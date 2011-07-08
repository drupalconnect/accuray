<?php 

class openlayers_proximity_handler_filter_circle extends openlayers_proximity_handler_filter {
 
  /**
   * Process operator.
   */
  function op_process($op = 'simple', $field) {
    parent::op_process($op, $field);
    
    if (!is_null($this->value['lat']) && !is_null($this->value['lon'])) {
      
      $join = new views_join();
      $table = $this->table_formula_alias();
      $join->definition['table formula'] = $this->table_formula($this->value['lat'], $this->value['lon']);
      $join->construct($table, 'node', 'nid', 'nid', array(), 'RIGHT');
      $this->query->queue_table($table, 'node', $join);           
      $this->query->add_field($table, 'distance');
      
      if ($op == 'simple') {
        $radius = $this->value['value'];
        $where = ($this->operator == '<') ? $this->build_where('<', $table, $radius) : $this->build_where('>', $table, $radius);
      }
      else {
        $inner = $this->build_where('>', $table, $this->value['min']);
        $outer = $this->build_where('<', $table, $this->value['max']);
        $where = ($this->operator == 'between') ? "($inner AND $outer)" : "NOT($inner AND $outer)";
      }
      $this->query->add_where($this->options['group'], $where);
    }
    $this->query->add_groupby("nid");
  }

  /**
   * Build WHERE clause.
   */
  function build_where($operator, $alias, $radius) {
    return sprintf("($alias.distance $operator= %f)", $radius);
  }

  function table_formula($lat, $lon) {
    $args = array('!lat1' => 'lat', '!lon1' => 'lon', '!lat2' => $lat, '!lon2' => $lon);
    $great_circle = strtr(OPENLAYERS_PROXIMITY_SQL_GREAT_CIRCLE, $args);
    return "(SELECT nid, lat, lon, $great_circle AS distance FROM {openlayers_proximity})";
  }
  
  function table_formula_alias() {
    return $this->table_alias .'_filter_'. $this->options['id'];
  }
}
