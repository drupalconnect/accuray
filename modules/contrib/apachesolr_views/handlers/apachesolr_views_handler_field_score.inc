<?php

/**
 * @file
 * Views handler to handle the score field. Will not add anything to the query
 */
class apachesolr_views_handler_field_score extends views_handler_field_numeric {
  function construct() {
    parent::construct();
    $this->definition['float'] = TRUE;
  }
  function query() {
    $this->field_alias = $this->query->add_solr_field('score');
  }
}