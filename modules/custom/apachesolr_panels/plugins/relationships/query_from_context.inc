<?php
if (module_exists('apachesolr_search')) {
  $plugin = array(
    'title' => t('Apache Solr query filter'),
    'keyword' => 'queryfilter',
    'description' => t('Adds a query from filter parameters derived from arguments'),
    'required context' => array(
      new ctools_context_required(t('Apache Solr query'), 'solrquery'),
      new ctools_context_optional(t('Term'), 'term'),
      ),
    'context' => 'ctools_query_from_context_context',
    'settings form' => 'ctools_query_from_context_settings_form',
    'settings form validate' => 'ctools_query_from_context_settings_form_validate',
  );
}

function ctools_query_from_context_context($contexts, $conf) {
  foreach ($contexts as $i => $context) {
    if (!strcmp('solrquery', $context->type)) {
      $querycontext = &$contexts[$i];
    }
    else {
      $filters[] = $context;
    }
  }
  
  foreach ($filters as $filter) {
    switch ($filter->type) {
      case 'term':
        if ($filter->data->tid) {
          $querycontext->data->query->add_filter('tid', $filter->data->tid);
          $querycontext->data->filter_contexts[] = $filter;
        }
        break;
    }
  }
  
  //dpm($querycontext->data);  
  
}

function ctools_query_from_context_settings_form() {
}

function ctools_query_from_context_settings_form_validate() {
}

