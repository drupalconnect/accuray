<?php

/**
 * Provides a basic handler for boolean fields
 */
class apachesolr_views_handler_filter_boolean extends views_handler_filter_boolean_operator {
  /**
   * Override query to do our thing
   */
  function query() {
    $this->query->add_filter($this->real_field, $this->value);
  }
}