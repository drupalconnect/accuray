<?php
if (module_exists('apachesolr_search')) {
  $plugin = array(
    'single' => TRUE,
    'no title override' => TRUE,
    'title' => t('Apache Solr response facets'),
    'icon' => 'icon_search.png',
    'description' => t('The facet counts from an Apache Solr response.'),
    'required context' => new ctools_context_optional(t('Context to fetch search query from'), 'solrquery'),
    'category' => t('Apache Solr Search'),
    'defaults' => array(
      'keys_action' => 'none',
      'keys' => '',
      'keys_required' => TRUE,
      'filters_action' => 'none',
      'filters' => '',
      'sort_action' => 'none',
      'sort' => '',
      'breadcrumb' => TRUE,
      'title_override' => FALSE,
      'title_override_text' => '',
      'empty_override' => FALSE,
      'empty_override_title' => '',
      'empty_override_text' => '',
      'empty_override_format' => FILTER_FORMAT_DEFAULT,
      'log' => FALSE,
      'substitute' => FALSE,
    ),
    'render first' => TRUE,
  );
}