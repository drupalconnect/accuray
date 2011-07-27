<?php
//$Id: contact_field_admin.inc,v 1.1.2.5.2.6 2010/08/27 08:57:40 beautifulmind Exp $

/**
 * @file
 *
 * Create administer interface to add fields to contact form
 *
 * @author Bhavin H. Joshi <bhavinjosi@joshics.in>
 */


/**
 * 
 * @param $ss__type
 * @return unknown_type
 * @author Bhavin H. Joshi <bhavinjosi@joshics.in>
 */
function contact_field_add_field($op, $om__field_details = NULL) {
  if ($om__field_details) {
    $om__field_details = unserialize($om__field_details);
  }
  $ss__field_type = _get_field_type($op);

  if ($op != 'add') {
    switch($ss__field_type) {
      case 'textfield':
        if (module_exists('contact_textfield')) {
          return drupal_get_form('contact_field_add_field_text_form', $form_state, $op);
        }
        break;
      case 'textarea':
        if (module_exists('contact_textfield')) {
          return drupal_get_form('contact_field_add_field_textarea_form', $form_state, $op);
        }
        break;
      case 'radios':
      case 'checkboxes':
        if (module_exists('contact_option')) {
          return drupal_get_form('contact_field_add_field_option_form', $form_state, $op);
        }
        break;
      case 'select':
        if (module_exists('contact_listfield')) {
          return drupal_get_form('contact_field_add_field_listfield_form', $form_state, $op);
        }
        break;
//      case 'fieldset':
//        if (module_exists('contact_listfield')) {
//          return drupal_get_form(contact_group_submit($form_state, $op));
//        }
//        break;  
    }
  }
  else{
    switch($om__field_details->type) {
      case 'text':
        if (module_exists('contact_textfield')) {
          return drupal_get_form('contact_field_add_field_text_form', $form_state, $om__field_details);
        }
        break;
      case 'area':
        if (module_exists('contact_textfield')) {
          return drupal_get_form('contact_field_add_field_textarea_form', $form_state, $om__field_details);
        }
        break;
      case 'option':
        if (module_exists('contact_option')) {
          return drupal_get_form('contact_field_add_field_option_form', $form_state, $om__field_details);
        }
        break;
      case 'list':
        if (module_exists('contact_listfield')) {
          return drupal_get_form('contact_field_add_field_listfield_form', $form_state, $om__field_details);
        }
        
      case 'fieldset':
        if (module_exists('contact_listfield')) {
          contact_group_submit($form_state, $om__field_details);
        }
        break;
    }
  }
}


/**
 * 
 * @return unknown_type
 * @author Bhavin H. Joshi <bhavinjosi@joshics.in>
 */
function contact_field_list_field() {
  $form = array();
  drupal_set_title(t("Manage fields"));
  $form['contact_field_list'] = array(
    '#type' => 'item',
    '#value' => _get_fields(),
    '#description' => t("Only fields from Contact form field module can be edited/deleted here."),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('contact_field_list_update'),
    '#value' => t("Save configuration"),
    '#weight' => 50,
  );
  
  $form['#validate'] = array('contact_field_validate');
  $form['#submit'] = array('contact_field_list_update');
  return $form;
}


/**
 * contact_field_list_update
 * 
 * @param $form
 * @param $form_values
 * @author Bhavin H. Joshi <bhavinjosi@joshics.in>
 */
function contact_field_list_update($form, $form_values) {
  $ss__field_label = $form_values['clicked_button']['#post']['field_label'];
  $ss__field_name = $form_values['clicked_button']['#post']['field_name'];
  $ss__field_type = $form_values['clicked_button']['#post']['field_type'];
  $ss__group_label = $form_values['clicked_button']['#post']['field_group_label'];
  $ss__group_name = $form_values['clicked_button']['#post']['field_group_name'];
  
  if ($ss__field_name && $ss__field_label && $ss__field_type) {
    $om__field_details = (object) array('name' => "field_". $ss__field_name, 'title' => $ss__field_label, 'type' => $ss__field_type);
    drupal_goto("admin/build/contact/add/". serialize($om__field_details)); 
  }
  
  elseif ($ss__group_label && $ss__group_name) {
    $om__field_details = (object) array('name' => "group_". $ss__group_name, 'title' => $ss__group_label, 'type' => 'fieldset');
    drupal_goto("admin/build/contact/add/". serialize($om__field_details)); 
  }
  
  else {
    $am__weight = preg_grep("/^(contact_weight_)/", array_keys($form_values['clicked_button']['#post']));
    $am__group = preg_grep("/^(contact_group_)/", array_keys($form_values['clicked_button']['#post']));
    
    if (!empty($am__weight)) {
      foreach ($am__weight as $key => $value) {
        $am__field = preg_split("/^(contact_weight_)/", $value, -1, PREG_SPLIT_NO_EMPTY);
        if (!empty($am__field)) {
          db_query("UPDATE {contact_fields} SET weight = %d WHERE field_name = '%s'",
          $form_values['clicked_button']['#post'][$value], $am__field[0]);
        }
      }
    }
    
    if (!empty($am__group)) {
      foreach ($am__group as $key => $value) {
        $am__field = preg_split("/^(contact_group_)/", $value, -1, PREG_SPLIT_NO_EMPTY);
        if (!empty($am__field)) {
          db_query("UPDATE {contact_fields} SET field_group = '%s' WHERE field_name = '%s'",
            $form_values['clicked_button']['#post'][$value], $am__field[0]);
        }
      }
    }
  }
}



/**
 * _get_fields
 *
 * Return themed fields
 *
 * @return unknown_type
 * @author Bhavin H. Joshi <bhavinjosi@joshics.in>
 */
function _get_fields() {
  _set_core_fields();
  $header = array(t("Title"), t("Weight"), t("Name"), t("Type"), t("Required"),
    t("Enabled"), array('data' => t("Operation"), 'colspan' => 2));
  $r__result = db_query("SELECT * FROM {contact_fields} ORDER BY weight ASC");
  $class = "";
  
  while ($om__result = db_fetch_object($r__result)) {
    if ($om__result->core) {
      $ss__module = '';
      $class = "menu-disabled";
    }
    else {
      $ss__module = '(Module: Contact form field)';
    }
    
    $am__settings = unserialize($om__result->settings);

    $am__weight['contact_weight_'. $om__result->field_name] = array(
      '#type' => 'textfield',
      '#title' => t("Weight"),
      '#size' => 5,
      '#default_value' => $om__result->weight,
      '#attributes' => array('class' => 'contact-weight'),
    );
    
    if ($om__result->field_type == 'fieldset') {
      $row = array(
        $am__settings['title'],
        drupal_render(form_builder(NULL, $am__weight, $form_state)),
        $om__result->field_name,
        array('data' => t("Standard group")),
        NULL,
        NULL,
        ($om__result->core ? NULL : l(t("Configure"), 'admin/build/contact/'. $om__result->field_name ."/edit")),
        ($om__result->core ? NULL : l(t("Remove"), 'admin/build/contact/'. $om__result->field_name ."/delete")),
      );
      drupal_add_tabledrag('contact-field', 'depth', 'parent', 'contact-group', 'contact-group-'. $om__result->field_name);
      drupal_add_tabledrag('contact-field', 'order', 'sibling', 'contact-weight', 'contact-weight-'. $om__result->field_name);
    }
    else {
      if (module_exists('contact_group')) {
        $am__group['contact_group_'. $om__result->field_name ."_parent"] = array(
          '#type' => 'select',
          '#title' => t("Group"),
          '#multiple' => FALSE,
          '#parent' => array("parent"),
          '#options' => _get_contact_group(),
          '#default_value' => $om__result->field_group ? $om__result->field_group : "",
          '#attributes' => array('class' => 'contact-group'),
        );
        
        $am__group[$om__result->field_name] = array(
          '#type' => 'hidden',
          '#parent' => array($om__result->field_name),
          '#default_value' => $om__result->field_name,
        );
      }
      if (module_exists('contact_group') && $om__result->field_group != "") {
        $am__in_group =  array(
          '<div class="indentation">&nbsp;</div>',
          $am__settings['title'] ." $ss__module",
        );
      }
      else {
        $am__in_group =  array(
          $am__settings['title'] ." $ss__module",
        );
      }
      $ss__group_fields = count($am__in_group == 2) ? implode("", $am__in_group) : $am__in_group[0];
       
      $row = array(
        $ss__group_fields,
        drupal_render(form_builder(NULL, $am__weight, $form_state)) . 
          drupal_render(form_builder(NULL, $am__group, $form_state)),
        $om__result->field_name,
        $om__result->field_type,
        ($om__result->required ? t("Yes") : t("No")),
        ($om__result->core ? t("Yes") : ($om__result->enabled ? t("Yes") : t("No"))),
        ($om__result->core ? NULL : l(t("Configure"), 'admin/build/contact/'. $om__result->field_name ."/edit")),
        ($om__result->core ? NULL : l(t("Remove"), 'admin/build/contact/'. $om__result->field_name ."/delete")),
      );
      drupal_add_tabledrag('contact-field', 'order', 'sibling', 'contact-weight');
    }
    
    $rows[] = array(
      'id' => 'contact-field',
      'data' => $row,
      'class' => 'draggable '. $class,
    );
    
    unset($class, $am__weight, $am__group);
  }
  
  //Add fields
  $am__fields = module_invoke_all('info');
  $am__field_type[0] = "-- ". t("Field type") ." --";
  if (!empty($am__fields)) {
    foreach ($am__fields as $key => $value) {
      $am__field_type[$value['type']] = $value['title'];
    }
  }
  else {
    drupal_set_message(t("No contact form field module is enabled. Please enable from !module",
     array('!module' => l(t("module page"), 'admin/build/modules'))), 'error');
  }
  
  $form_label['field_label'] = array(
    '#type' => 'textfield',
    '#title' => t("New field"),
    '#size' => 30,
    '#description' => t("Label"),
  );
  
  $form_field_name['field_name'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#description' => t("Field name (a-z, 0-9, _)"),
    '#field_prefix' => 'field_'
  );
  
  $form_field_type['field_type'] = array(
    '#type' => 'select',
    '#description' => t("Set the field type"),
    '#options' => $am__field_type,
  );
  
  $rows[] = array(
    array('data' => t("Add"), 'colspan' => 8, 'class' => 'region'),
  );
  
  $rows[] = array(
    drupal_render(form_builder($form_id, $form_label, $form_values)),
    NULL,
    drupal_render(form_builder($form_id, $form_field_name, $form_values)),
    array('data' => drupal_render(form_builder($form_id, $form_field_type, $form_values)), 'colspan' => 8),
  );
  
  if (module_exists('contact_group')) {
    $form_group_label['field_group_label'] = array(
      '#type' => 'textfield',
      '#title' => t("New group"),
      '#size' => 30,
      '#description' => t("Label"),
    );
    
    $form_group_name['field_group_name'] = array(
      '#type' => 'textfield',
      '#size' => 30,
      '#description' => t("Group name (a-z, 0-9, _)"),
      '#field_prefix' => 'group_'
    );
    
    $rows[] = array(
      'data' => array(
        drupal_render(form_builder($form_id, $form_group_label, $form_values)),
        array('data' => drupal_render(form_builder($form_id, $form_group_name, $form_values)), 'colspan' => 7),
      ),
    );   
  }
  
  drupal_add_tabledrag('contact-field', 'depth', 'parent', 'contact-group', NULL, NULL, TRUE, 1);
  drupal_add_tabledrag('contact-field', 'order', 'sibling', 'contact-weight');
  return theme('table', $header, $rows, array('id' => 'contact-field'));
}




/**
 * _set_core_fields
 *
 * Set the core fields
 *
 * @author Bhavin H. Joshi <bhavinjosi@joshics.in>
 */
function _set_core_fields() {
  $form_state = array();
  $form_id  = 'contact_site_page';
  module_load_include('inc', 'contact', 'contact.pages');
  $form = contact_mail_page();
  
  $i = -10;
  $am__exclude = array('#token', 'submit', 'copy', 'contact_information');
  foreach ($form as $name => $attribute) {
    if (!in_array($name, $am__exclude) && !empty($attribute['#type'])) {
     $b__exist = db_result(db_query("SELECT field_name FROM {contact_fields} WHERE core = 1 AND field_name = '%s'", $name));
      if (!$b__exist) {
        $am__settings = array('title' => $form[$name]['#title']);
        db_query("INSERT INTO {contact_fields} VALUES('%s', '%s', '%s', %d, %d, %d, %d, '%s')", 
          $name, $attribute['#type'], serialize($am__settings), 
          $attribute['#required'], 1, $i, 1, '');
        $i++;
      }
    }
  }
}




/**
 * contact_field_list_field
 * 
 *  Return field display template
 *  
 *  @author Bhavin H. Joshi <bhavinjosi@joshics.in>
 */
function contact_field_display_field() {
  drupal_set_title(t("Message template"));
  $form = array();
  $form['contact_field_use_template'] = array(
    '#type' => 'checkbox',
    '#title' => t("Use message template"),
    '#default_value' => variable_get("contact_field_use_template", 0),
    '#weight' => -10,
  );
  
  $form['contact_field_message_template'] = array(
    '#type' => 'textarea',
    '#title' => t("Message template"),
    '#default_value' => variable_get("contact_field_message_template", ""),
    '#description' => t("The actual message content will be replaced by the content of message template with fields replaced by actual values."),
    '#weight' => -9,
  );
  
  $form['contact_field_token'] = array(
    '#type' => 'fieldset',
    '#title' => t("Available fields"),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['contact_field_token']['contact_field_lit'] = array(
    '#type' => 'item',
    '#description' => t("You can use above fields in the message template. Please note that some of the fields are of contact module."),
    '#value' => _get_contact_field(),
  );
  return system_settings_form($form); 
}