<?php 

class openlayers_proximity_handler_filter extends views_handler_filter_float {

  // exposed filter options
  var $no_single = FALSE;

  function op_between($field) {
    $this->op_process('between', $field);
  }

  function op_simple($field) {
    $this->op_process('simple', $field);
  }
  
  function op_process($op = 'simple', $field) {

    $this->secure_input();
    if ($this->options['location_as'] == 'node') {
      $this->process_node_proximity();
    }
    if ($this->options['location_as'] == 'location') {
      $this->process_location_proximity();
    }
  }
    
  /**
   * Display the filter on the administrative summary
   */
  function admin_summary() {
    if (!empty($this->options['exposed'])) {
      return t('exposed');
    }
    $options = $this->operator_options('short');
    $output = check_plain($options[$this->operator]);
    if (in_array($this->operator, $this->operator_values(2))) {
      $output .= ' ' . t('@min and @max @unit from @location', array('@min' => $this->value['min'], '@max' => $this->value['max'], '@unit' => $this->value['unit'], '@location' => $this->value['location']));
    }
    elseif (in_array($this->operator, $this->operator_values(1))) {
      $output .= ' ' . t('@value @unit from @location', array('@value' => $this->value['value'], '@unit' => $this->value['unit'], '@location' => $this->value['location']));
    }
    return $output;
  }  

  /**
   * Information about options for all kinds of purposes will be held here.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['operator'] = array('default' => '<');
    $options['location_as'] = array('default' => 'location');

    $options['value']['contains']['unit'] = array('default' => variable_get('openlayers_proximity_unit', OPENLAYERS_PROXIMITY_DEFAULT_UNIT));
    $options['value']['contains']['location'] = array('default' => '');
    $options['value']['contains']['node'] = array('default' => '');

    $options['expose']['contains']['use_unit'] = array('default' => FALSE);
    $options['expose']['contains']['unit'] = array('default' => 'unit');
    $options['expose']['contains']['use_location'] = array('default' => FALSE);
    $options['expose']['contains']['location'] = array('default' => 'location');
    $options['expose']['contains']['use_node'] = array('default' => FALSE);
    $options['expose']['contains']['node'] = array('default' => 'node');

    return $options;
  }

  /**
   * Provide default options for exposed filters.
   */
  function expose_options() {
    parent::expose_options();
    $this->options['expose']['use_unit'] = FALSE;
    $this->options['expose']['unit'] = 'unit';
    $this->options['expose']['use_location'] = FALSE;
    $this->options['expose']['location'] = 'location';
    $this->options['expose']['use_node'] = FALSE;
    $this->options['expose']['node'] = 'node';
  }

  /**
   * Handle the 'left' side fo the exposed options form.
   */
  function expose_form_left(&$form, &$form_state) {
    $this->expose_option_form($form, 'unit', 'unit of measurement');
    $this->expose_option_form($form, 'location', 'location');
    $this->expose_option_form($form, 'node', 'node');
    parent::expose_form_left($form, $form_state);
  }

  /**
   * Validate the options form.
   */
  function expose_validate($form, &$form_state) {
    parent::expose_validate($form, &$form_state);
    // @todo: validation.
  }
  
  /**
   * Provide a simple textfield for equality
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    
    $form['value']['wrapper_open']['#value'] = '<div class="dependent-options">';
    $form['value']['wrapper_location_open']['#value'] = '<div class="views-right-70">';
    $form['value']['location'] = array(
      '#title' => t('Location'),
      '#type' => 'textfield',
      '#size' => 20,
      '#default_value' => $this->options['value']['location'],
      '#description' => t('Location where to start to search from.'),
      '#process' => array('views_process_dependency'),
      '#dependency' => array(
        'radio:options[location_as]' => array('location'),
      ),
    );
    $form['value']['node'] = array(
      '#title' => t('Node'),
      '#type' => 'select',
      '#default_value' => $this->options['value']['node'],
      '#options' => $this->get_node_options(),
      '#description' => t('Node where to start to search from.'),
      '#process' => array('views_process_dependency'),
      '#dependency' => array(
        'radio:options[location_as]' => array('node'),
      ),
    );
    $form['value']['wrapper_location_close']['#value'] = '</div>';
    $form['value']['unit'] = array(
      '#title' => t('Unit of measurement'),
      '#type' => 'select',
      '#options' => openlayers_proximity_get_available_units_for_select(),
      '#default_value' => $this->options['value']['unit'],
      '#description' => t('Select unit of measurement.'),
      '#prefix' => '<div class="views-left-30">',
      '#suffix' => '</div>',
    );
    $form['value']['wrapper_close']['#value'] = '</div>';
    $form['location_as'] = array(
      '#type' => 'radios',
      '#title' => t('Location'),
      '#default_value' => $this->options['location_as'],
      '#options' => array(
        'location' => t('Get location from a string'),
        'node' => t('Get location from a node'),
      ),
    );
  }
  
  /**
   * Provide a form for setting the operator.
   */
  function operator_form(&$form, &$form_state) {
    parent::operator_form($form, $form_state);
    // At the end of the day proximity search is a rough estimation.  
    $this->unset_attributes($form['operator']['#options'], array('<=', '=', '!=', '>='));
  }
  
  /**
   * Render our chunk of the exposed filter form when selecting
   */
  function exposed_form(&$form, &$form_state) {
    
    if (empty($this->options['exposed'])) {
      return;
    }
    
    $force_operator = FALSE;
    $operators = $this->operator_options();
    if (empty($this->options['expose']['use_operator'])) {
      $this->options['expose']['use_operator'] = TRUE;
      $force_operator = TRUE;
    }
    
    parent::exposed_form($form, $form_state);
    
    if ($force_operator) {
      $operator = $this->options['expose']['operator'];
      $form[$operator]['#type'] = 'hidden';
      $form[$operator]['#value'] = $form[$operator]['#default_value']; 
      $this->unset_attributes($form[$operator], array('#options'));
    }
    
    // When exposed pull location and unit out of value form item.
    if (!empty($this->options['expose']['identifier'])) {
      
      // Unset useless form elements.
      $filter = &$form[$this->options['expose']['identifier']];
      $this->unset_attributes($filter, array('wrapper_open', 'wrapper_close', 'wrapper_location_open', 'wrapper_location_close'));
      $this->unset_attributes($form, array('location_as'));
      
      // Turn exposed form into a fieldset to have better control over its rendering.
      $filter['#type'] = 'fieldset';
      $filter['#attributes'] = array('class' => "openlayers-proximity-filter-exposed");
      
      // Expose unit of measurement form, if necessary.
      if ($this->filter_item_is_exposed('unit')) {
        $name = $this->rename_exposed_filter_item($form, 'unit');
        $this->clean_exposed_filter_item($filter[$name]);
      }
      else {
        $this->unset_attributes($filter, array('unit'));
      }
      
      // Expose location form, if necessary.
      $name = $this->options['location_as']; 
      if ($this->filter_item_is_exposed($name)) {

        $name = $this->rename_exposed_filter_item($form, $name);
        $this->clean_exposed_filter_item($filter[$name]);

        $filter[$name]['#weight'] = 100;
        $filter[$name]['#field_prefix'] =  t('from');
      }
      else {
        $this->unset_attributes($filter, array($name));
        $filter[$name]['#value'] = $this->filter_item_is_exposed('unit') ? '<div class=" form-item">'. $this->get_suffix() .'</div>' : '';
      }        
      
      if ($this->options['location_as'] == 'location') {
        $this->unset_attributes($filter, array('node'));
      }
      if ($this->options['location_as'] == 'node') {
        $this->unset_attributes($filter, array('location'));
      }

      // Add meaningful suffix to value.
      if (isset($filter['value'])) {
        
        $filter['value']['#size'] = 3;
        $filter['value']['#field_prefix'] = $force_operator ? $operators[$this->options['operator']] : '';
        $filter['value']['#field_suffix'] = $this->get_suffix();;

        $this->unset_attributes($filter['value'], array('#default_value'));
      }
      
      // Add meaningful prefix/suffix to min max.
      if (isset($filter['min']) && isset($filter['max'])) {
        
        $filter['min']['#size'] = 3;
        $filter['min']['#field_prefix'] = $force_operator ? $operators[$this->options['operator']] : '';

        $filter['max']['#size'] = 3;
        $filter['max']['#field_prefix'] = t('and');
        $filter['max']['#field_suffix'] = $this->get_suffix();
        
        $this->unset_attributes($filter['max'], array('#title', '#default_value'));
        $this->unset_attributes($filter['min'], array('#default_value'));
      }
    }
  }


  /**
   * Validate the exposed filter form
   */
  function exposed_validate(&$form, &$form_state) { 
    parent::exposed_validate(&$form, &$form_state);
    
    // Satitize "value", "min" and "max"
    $operators = $this->operators();
    $identifier = $this->options['expose']['identifier'];
    $location = $this->options['expose']['location'];
    foreach (array('value', 'min', 'max') as $field) {
    	$form_state['input'][$identifier][$field] = str_replace(',', '.', $form_state['input'][$identifier][$field]);
    }
    $values = $form_state['input'];
    $op = $values[$this->options['expose']['operator']];
        
    // Validate "value", "min" and "max"     
    $fields = ($operators[$op]['method'] == 'op_between') ? array('min', 'max') : array('value');  
    foreach ($fields as $key => $field) {
      if ($values[$identifier][$field]) {
        if (!is_numeric($values[$identifier][$field])) {
          form_set_error($identifier .']['. $field, t('Please, provide a valid numeric value.'));
        }
        elseif ($values[$identifier][$field] <= 0) {
          form_set_error($identifier .']['. $field, t('Please, provide a value greater then zero.'));
        }
        elseif ($key && $values[$identifier]['min'] >= $values[$identifier]['max']) {
          form_set_error($identifier .'][min', t('Please, make sure that the first value is greater then the second one.'));
        }
      }
    }
    
    // Validate location 
    if ($this->options['location_as'] == 'location' && !empty($values[$identifier][$location])) {
      if ($response = openlayers_proximity_geocode($values[$identifier][$location])) {
        $this->response = $response;
      }
      else {
        form_set_error($identifier .']['. $location, t('Location not found'));
      }
    }
    
  }

  /**
   * Distance from a node: rough calculation of a centroid for the node in
   * argument: centroid is calculate directly on values stored in the
   * proximity_index table.
   */
  function process_node_proximity() {
    $nid = $this->value['node'];
    
    // Get square boundaries.
    $x1 = db_result(db_query("SELECT lon FROM {openlayers_proximity} WHERE nid = %d ORDER BY lon ASC LIMIT 0, 1", $nid));
    $y1 = db_result(db_query("SELECT lat FROM {openlayers_proximity} WHERE nid = %d ORDER BY lat ASC LIMIT 0, 1", $nid));
    $x2 = db_result(db_query("SELECT lon FROM {openlayers_proximity} WHERE nid = %d ORDER BY lon DESC LIMIT 0, 1", $nid));
    $y2 = db_result(db_query("SELECT lat FROM {openlayers_proximity} WHERE nid = %d ORDER BY lat DESC LIMIT 0, 1", $nid));
    
    $delta = (sqrt(pow($x1 - $x2, 2) + pow($y1 - $y2, 2)) / 2) * OPENLAYERS_PROXIMITY_KM_PER_LAT; 
    $this->value['value'] += $delta;
    $this->value['min'] += $delta;
    $this->value['max'] += $delta;
    $this->value['lon'] = ($x1 + $x2) / 2;
    $this->value['lat'] = ($y1 + $y2) / 2;
    drupal_alter('process_node_proximity', $this->value);
  }

  /**
   * Distance from a location: query is a string and it will be geolocated.
   */
  function process_location_proximity() {
    $this->value['lat'] = $this->value['lon'] = NULL;
    if ($this->response = openlayers_proximity_geocode($this->value['location'])) {
      $this->value['lat']  = $this->response[0]['location']['lat'];
      $this->value['lon']  = $this->response[0]['location']['lng'];
    }
    drupal_alter('process_location_proximity', $this->value);
  }
  
  function secure_input() {
    $this->value['value'] = isset($this->value['value']) ? $this->value['value'] : $this->options['value']['value'];
    $this->value['min'] = isset($this->value['min']) ? $this->value['min'] : $this->options['value']['min'];
    $this->value['max'] = isset($this->value['max']) ? $this->value['max'] : $this->options['value']['max'];
    $this->value['node'] = isset($this->value[$this->options['expose']['node']]) ? $this->value[$this->options['expose']['node']] : $this->options['value']['node'];
    $this->value['location'] = isset($this->value[$this->options['expose']['location']]) ? $this->value[$this->options['expose']['location']] : $this->options['value']['location'];
    $this->value['unit'] = isset($this->value[$this->options['expose']['unit']]) ? $this->value[$this->options['expose']['unit']] : $this->options['value']['unit'];

    $this->value['value'] = openlayers_proximity_measurement_units_convert($this->value['unit'], $this->value['value']);
    $this->value['min'] = openlayers_proximity_measurement_units_convert($this->value['unit'], $this->value['min']);
    $this->value['max'] = openlayers_proximity_measurement_units_convert($this->value['unit'], $this->value['max']);
  }
  
  function unset_attributes(&$item, $attributes) {
    foreach ($attributes as $name) {
      unset($item[$name]);
    }
  } 
  
  function clean_exposed_filter_item(&$item) {
    $this->unset_attributes($item, array('#prefix', '#suffix', '#title', '#description'));
  }
  
  function expose_option_form(&$form, $name, $title) {
    
    $form['expose']['use_'. $name] = array(
      '#type' => 'checkbox',
      '#title' => t('Unlock @title', array('@title' => $title)),
      '#default_value' => $this->options['expose']['use_'. $name],
      '#description' => t('When checked, this filter will be exposed to the user'),
    );
    $form['expose'][$name] = array(
      '#type' => 'textfield',
      '#default_value' => $this->options['expose'][$name],
      '#title' => t('@title identifier', array('@title' => $title)),
      '#size' => 40,
      '#description' => t('This will appear in the URL after the ? to identify this filter.'),
      '#process' => array('views_process_dependency'),
      '#dependency' => array(
        'edit-options-expose-use-'. $name => array(1)
      ),
    );  
  }


  function rename_exposed_filter_item(&$form, $name) {
    $value = $this->options['expose'][$name];
    $identifier = $this->options['expose']['identifier'];
    if ($value != $name) {
      $form[$identifier][$value] = $form[$identifier][$name];
      $this->unset_attributes($form[$identifier], array($name));
    }
    return $value;
  }
  
  function filter_item_is_exposed($name) {
    return !empty($this->options['expose']['use_'. $name]) && !empty($this->options['expose'][$name]);
  }
  
  function get_node_options() {
    $options = array();
    // Avoid query if filter is not exposed. @TODO: get a better condition check.
    if ($this->filter_item_is_exposed('node') && $this->options['location_as'] == 'node' || arg(2) == 'views') {
      $results = db_query("SELECT n.title, n.nid FROM {openlayers_proximity} op LEFT JOIN {node} n ON n.nid = op.nid WHERE n.status = 1 ORDER BY n.title ASC");
      while ($row = db_fetch_object($results)) {
        $options[$row->nid] = check_plain(drupal_substr($row->title, 0, 40));
      }
    }
    return $options;
  }
  
  function location_name() {
    if ($this->options['location_as'] == 'location') {
      return $this->options['value']['location'];
    }
    if ($this->options['location_as'] == 'node') {
      return db_result(db_query("SELECT title FROM {node} WHERE nid = %d", $this->options['value']['node']));  
    }
  }

  function get_suffix() {
    $suffix = '';
    $units = openlayers_proximity_get_available_units();
    // If unit is not exposed add unit string to suffix.
    if (!$this->filter_item_is_exposed('unit')) {
      $suffix = '@unit '. $suffix;
    }

    // If location is not exposed add location string to suffix.
    if (!$this->filter_item_is_exposed($this->options['location_as'])) {
      $suffix = $suffix .' from @location';
    }
    return t($suffix, array('@unit' => $units[$this->options['value']['unit']]['long'], '@location' => $this->location_name()));
  }


}