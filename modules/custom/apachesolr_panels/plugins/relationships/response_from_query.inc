<?php
if (module_exists('apachesolr_search')) {
  $plugin = array(
    'title' => t('Apache Solr response'),
    'keyword' => 'response_from_query',
    'description' => t('Execute an Apache Solr query'),
    'required context' => new ctools_context_required(t('Apache Solr query'), 'solrquery'),
    'context' => 'ctools_response_from_solrquery_context',
    'settings form' => 'ctools_response_from_solrquery_settings_form',
    'settings form validate' => 'ctools_response_from_solrquery_settings_form_validate',
    
  );
}

function ctools_response_from_solrquery_context($context, $conf) {
  
  if (empty($context->data)) {
    return ctools_context_create_empty('solrresponse', NULL);
  }

  return ctools_context_create('solrresponse', $context->data);
}

function ctools_response_from_solrquery_settings_form() {
}

function ctools_response_from_solrquery_settings_form_validate() {
}

