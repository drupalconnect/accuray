<?php
/**
 * @file
 *
 * Plugin to provide an apachesolr context
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
if (module_exists('apachesolr_search')) {
  $plugin = array(
    'title' => t('Apache Solr Base Query'),
    'description' => t('An Apache Solr base query context'),
    'settings form' => 'ctools_context_solrquery_settings_form',
    'settings form validate' => 'ctools_context_solrquery_settings_form_validate',
    'settings form submit' => 'ctools_context_solrquery_settings_form_submit',
    'context' => 'ctools_context_create_solrquery',
    'keyword' => 'solrquery',
    'no ui' => FALSE,
  );
}

function ctools_context_solrquery_settings_form($conf) {
  $form = array();
  
  $form['queryvalues'] = array(
    '#type' => 'select',
    '#title' => 'URL filterstring handling',
    '#description' => 'Leave this box unchecked to ignore filters passed on the URL',
    '#default_value' => $conf['queryvalues'] ? TRUE : FALSE,
    '#options' => array(
      'append' => 'Append',
      'replace' => 'Replace',
      'ignore' => 'Ignore',
      ),
    );
  $form['base_path'] = array(
    '#type' => 'textfield',
    '#title' => 'Base path',
    '#description' => 'Manually set the base path. Leaving this field empty will set it to the panel path.',
    '#default_value' => $conf['base_path'] ? $conf['base_path'] : '',
    );
    
  return $form;
}

function ctools_context_solrquery_settings_form_validate($form, &$form_values, &$form_state) {
}

function ctools_context_solrquery_settings_form_submit($form, &$form_values, &$form_state) {
}

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function ctools_context_create_solrquery($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('solrquery');
  $context->plugin = 'solrquery';

  if ($empty) {
    return $context;
  }
  
  $keys = '';  
  
  if (!empty($data['keys'])) {
    $keys = $data['keys'];
  }  
  
  $filters = '';
  
  if ($data['queryvalues'] && !empty($_REQUEST['filters'])) {
    $filters = $_REQUEST['filters'];
  }

  $solrsort = '';

  if ($data['queryvalues'] && !empty($_REQUEST['solrsort'])) {
    $solrsort = $_REQUEST['solrsort'];
  }
  
  $base_path = $_GET['q'];
  
  if (!empty($data['base_path'])) {
    $base_path = $data['base_path'];
  }

  $page = 0;

  if ($_GET['page']) {
    $page = $_GET['page'];
  }

  $params = array();

  $params += apachesolr_search_basic_params($current_query);

  if ($keys) {
    $params += apachesolr_search_highlighting_params($current_query);
    $params += apachesolr_search_spellcheck_params($current_query);
  }
  else {
    // No highlighting, use the teaser as a snippet.
    $params['fl'] .= ',teaser';
  }

  if (module_exists('upload')) {
    $params['fl'] .= ',is_upload_count';
  }
  
  $current_query = apachesolr_drupal_query($keys, $filters, $solrsort, $base_path);

  apachesolr_search_add_facet_params($params, $current_query);
  apachesolr_search_add_boost_params($params, $current_query, apachesolr_get_solr());  
  
  if ($data !== FALSE ) {
    $context->data = (object) array('query' => $current_query, 'params' => $params);
    $context->title = check_plain('Apache Solr query');
    return $context;
  }
  
}

function ctools_context_solrquery_convert() {
}