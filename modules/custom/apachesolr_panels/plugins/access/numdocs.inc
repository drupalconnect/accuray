<?php
/**
 * @file
 * Plugin to provide access control based upon presence of query filters.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
if (module_exists('apachesolr_search')) {
  $plugin = array(
    'title' => t("Apache Solr: Number of results"),
    'description' => t('Control access by number of documents in a response.'),
    'callback' => 'ctools_solrnumdocs_ctools_access_check',
    'settings form' => 'ctools_solrnumdocs_ctools_access_settings',
    'settings form validation' => 'ctools_solrnumdocs_ctools_access_settings_validate',
    'settings form submit' => 'ctools_solrnumdocs_ctools_access_settings_submit',
    'summary' => 'ctools_solrnumdocs_ctools_access_summary',
    'required context' => new ctools_context_required(t('Apache Solr response'), array('solrresponse')),
  );
}

function ctools_solrnumdocs_ctools_access_check($conf, $context) {
  $response = $context->data->response;
  $num_docs = $response->response->numFound;
  
  switch ($conf['operator']) {
    case 'eq':
      if (!strcmp($num_docs, $conf['value'])) { 
        return TRUE; 
      }
    case 'gt':
      if ($num_docs < $conf['value']) {
        return TRUE;
      }
    case 'lt':
      if ($num_docs > $conf['value']) {
        return TRUe;
      }
    default:
      return FALSE;
  }
  
}

function ctools_solrnumdocs_ctools_access_settings(&$form, &$form_state, $conf) {
  $form['settings']['operator'] = array(
    '#type' => 'select',
    '#title' => 'Operator',
    '#default_value' => ($conf['operator'] ? $conf['operator'] : 'eq'),
    '#options' => array(
      'eq' => 'Equal to',
      'gt' => 'Greater than',
      'lt' => 'Less than',
      ),
    );
  $form['settings']['value'] = array(
    '#type' => 'textfield',
    '#title' => 'Value',
    '#default_value' => ($conf['value'] ? $conf['value'] : ''),
    );
}