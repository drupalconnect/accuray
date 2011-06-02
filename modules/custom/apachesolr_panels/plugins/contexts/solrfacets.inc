<?php
if (module_exists('apachesolr_search')) {
  

  /**
   * Define the plugin 
   */
  $plugin = array(
    'title' => t('Apache Solr Facet List'),
    'description' => t('An Apache Solr facet context'),
    'settings form' => 'ctools_context_solrfacets_settings_form',
    'settings form validate' => 'ctools_context_solrfacets_settings_form_validate',
    'settings form submit' => 'ctools_context_solrfacets_settings_form_submit',
    'context' => 'ctools_context_create_solrfacets',
    'keyword' => 'solrfacets',
    'no ui' => FALSE,
    'context name' => 'solrfacets',
    'convert' => 'ctools_context_solrfacets_convert',
    'convert list' => $converts,
  );

}

function ctools_context_solrfacets_settings_form() {
}

function ctools_context_solrfacets_settings_form_validate() {
}

function ctools_context_solrfacets_settings_form_submit() {
}

/**
 * Create a facets context. This primarily is just a hook on which to hang
 * facet conversions. Since some facet operations will need access to the 
 * full query and response objects, we just pass them along as is.
 */
function ctools_context_create_solrfacets($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('solrfacets');
  $context->plugin = 'solrfacets';

  if ($empty) {
    return $context;
  }
  
  if (count($data->response->facet_counts->facet_fields) || count($data->response->facet_counts->facet_dates)) {
    
  }
  
  if ($data !== FALSE ) {
    $context->data = $data;
    $context->title = check_plain('Apache Solr facets');
    return $context;
  }
}

