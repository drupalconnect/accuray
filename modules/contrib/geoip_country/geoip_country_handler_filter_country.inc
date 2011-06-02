<?php
// $Id: geoip_country_handler_filter_country.inc

/**
 * Filter on country.
 */
class geoip_country_handler_filter_country extends views_handler_filter {

  function option_definition() {
    $options = parent::option_definition();
    $options['operator'] = array('default' => 'IS');

    return $options;
  }

  function operator_options() {
    if ($this->options['multiple']) {
      return array(
        'is' => t('Is one of'),
        'is not' => t('Is not one of'),
      );
    }
    else {
      return array(
        'is' => t('Is'),
        'is not' => t('Is not'),
      );
    }
  }

  function query() {
    if (empty($this->value)) {
      return;
    }

    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";

    // Normalize values.
    $value = $this->value;
    if (is_array($value)) {
      $value = array_keys($value);
      if (count($value) == 1) {
        // If multiple is allowed but only one was chosen, use a string instead.
        $value = reset($value);
      }
    }

    if (is_array($value)) {
      // Multiple values
      $placeholders = db_placeholders($value, 'varchar');
      $operator = ($this->operator == 'is') ? 'IN' : 'NOT IN';
      $this->query->add_where($this->options['group'], "$field $operator($placeholders)", $value);
    }
    else {
      // Single value
      $operator = ($this->operator == 'is') ? '=' : '!=';
      $this->query->add_where($this->options['group'], "$field $operator '%s'", $this->value);
    }
  }
}
