<?php
// $Id: sharethis.views.inc,v 1.1.2.3 2009/08/14 03:52:42 robloach Exp $
/**
 * @file
 * Views integration for sharethis.
 */

/**
 * Implementation of hook_views_data().
 */
function sharethis_views_data() {
  // sharethis link
  $data['node']['sharethislink'] = array(
    'title' => t('ShareThis link'), // The item it appears as on the UI,
    'help' => t('Link provided by the ShareThis service.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'sharethis_handler_link',
      'click sortable' => FALSE,
    )
  );
  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function sharethis_views_handlers() {
  return array(
    'handlers' => array(
      'sharethis_handler_link' => array(
        'parent' => 'views_handler_field_node_link',
      ),
    ),
  );
}
