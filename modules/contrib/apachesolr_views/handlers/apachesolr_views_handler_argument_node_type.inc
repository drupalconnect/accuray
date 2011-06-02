<?php

/**
 * @file
 * defines a class to handle node type arguments
 */
class apachesolr_views_handler_argument_node_type extends apachesolr_views_handler_argument {
  function title() {
    return $this->node_type($this->argument);
  }

  function node_type($type) {
    $output = node_get_types('name', $type);
    if (empty($output)) {
      return t('Unknown node type');
    }
    else {
      $output .= 's';
      return check_plain(t($output));
    }
  }
}