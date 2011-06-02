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
    'title' => t("Apache Solr: Filter exists"),
    'description' => t('Control access by query filter values.'),
    'callback' => 'ctools_solrfilter_ctools_access_check',
    'default' => array('vids' => array()),
    'settings form' => 'ctools_solrfilter_ctools_access_settings',
    'settings form validation' => 'ctools_solrfilter_ctools_access_settings_validate',
    'settings form submit' => 'ctools_solrfilter_ctools_access_settings_submit',
    'summary' => 'ctools_solrfilter_ctools_access_summary',
    'required context' => new ctools_context_required(t('Apache Solr query'), array('solrquery')),
  );
}

function ctools_solrfilter_ctools_access_check($conf, $context) {
  
  $query = $context->data->query;
  //dpm($query->get_filters());

  return TRUE;

  if (!is_object($query)) {
    return FALSE;
  }  
  
  if ($query->has_filter($conf['key'], $conf['value'])) {
    return TRUE;
  }
  
  return FALSE;
}

function ctools_solrfilter_ctools_access_settings(&$form, &$form_state, $conf) {
  
  $form['settings']['key'] = array(
    '#type' => 'textfield',
    '#title' => 'Index key',
    '#default_value' => $conf['key'],
    );
    
  $form['settings']['value'] = array(
    '#type' => 'textfield',
    '#title' => 'Value',
    '#default_value' => $conf['value'],
    );
}

function ctools_solrfilter_ctools_access_settings_validate() {
}

function ctools_solrfilter_ctools_access_settings_submit() {
}

function ctools_solrfilter_ctools_access_summary() {
}