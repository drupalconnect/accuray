<?php
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
if (module_exists('apachesolr_search')) {
  /**
   * Compile a list of facets for which we will handle conversions
   */
  $facets = module_invoke_all('apachesolr_facets'); 
  $enabled = apachesolr_get_enabled_facets();

  $converts = array();

  foreach ($enabled as $module => $module_facets) {
    foreach ($module_facets as $module_facet => $module_facet) {
      $converts[$module_facet . '_raw'] = $facets[$module_facet]['info'] . ' (Raw comma separated values)';
      if ($display_callback = $facets[$module_facet]['info']['display_callback']) {
        $converts[$module_facet . '_formatted'] = $facets[$module_facet]['info'] . ' (Formatted comma separated values)';
      }
      $converts[$module_facet . '_arglist'] = $facets[$module_facet]['info'] . ' (Comma separated argument list for passing to views)';
    }
  }

  $plugin = array(
    'title' => t('Apache Solr response'),
    'description' => t('An Apache Solr query context'),
    'context' => 'ctools_context_create_solrresponse',
    'keyword' => 'solrresponse',
    'no ui' => TRUE,
    'convert' => 'ctools_context_solrresponse_convert',
    'convert list' => $converts,
  );
}

function ctools_context_create_solrresponse($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('solrresponse');
  $context->plugin = 'solrresponse';
  
  if ($empty) {
    return $context;
  }
  
  $page = ($_GET['page'] ? $_GET['page'] : 0);

  $params = $data->params;
  
  $current_query = $data->query;
  
  list($query, $response) = apachesolr_do_query('apachesolr_search', $current_query, $params, $page);

  // We need to remove filters originally passed as arguments in the path.
  
  
  apachesolr_current_query($query);
  apachesolr_static_response_cache($response);
  
  apachesolr_has_searched(TRUE);
  
  $data->response = $response;
  
  if ($data !== FALSE ) {
    $context->data = $data;
    $context->title = check_plain('Apache Solr response');
    return $context;
  }
}

/**
 * Convert a context into a string.
 */
function ctools_context_solrresponse_convert($context, $type) {
  $caller = 'apachesolr_search';
  
  $facet_info = module_invoke_all('apachesolr_facets'); 

  $response = $context->data->response;  
  
  // TODO: This allows refactoring such that other modules easily can provide new formatters
  $formats = array(
    'arglist',
    'raw',
    'formatted',
    );
  
  // Determine the format in which to return values
  foreach ($formats as $format) {
    $format_component = substr($type, strlen($type) - strlen($format), strlen($format));
    if (!strcmp($format, $format_component)) {
      $type_format = $format;
    }
  }
  
  // Determine the field to extract from the response
  $field = substr($type, 0, strlen($type) - strlen($type_format) -1 );  
  
  if (!count($response->facet_counts->facet_fields->$field)) {
    return;
  }  
  
  $values = array();

  foreach ($response->facet_counts->facet_fields->$field as $field_value => $count) {
    $values[] = $field_value;
  }
  
  $function = 'ctools_context_solrresponse_' . $field . '_convert';
  
  // Allow modules to tweak the facets list
  if (function_exists($function)) {
    $function($values, $context);
  }  
  
  switch ($type_format) {
    case 'arglist':
      return implode(',', $values);
    case 'raw':
      return implode(', ', $values);
    case 'formatted':
      return implode(', ', $values);  
  }
}


/**
 * Fiter the list of facet items to show only the next level in the taxonomy hierarchy
 */
function ctools_context_solrresponse_im_vid_2_convert(&$values, $context) {
  $query = $context->data->query;
  
  $depth = 0;
  
  // find the deepest active term
  foreach ($values as $value) {
    // check whether any of the values is active    
    if ($query->has_filter('tid', $value)) {      
      // calculate the depth of the term and increase max depth if needed
      $parents = taxonomy_get_parents_all($value);
      $depth = (count($parents) > $depth ? count($parents) : $depth);
    }      
  }
  
  $parents = array();
 
  $values_copy = $values;
 
  // remove values that are deeper than the maximum depth
  foreach ($values_copy as $i => $value) {
    $parents = taxonomy_get_parents_all($value);
    if (count($parents) != $depth + 1) {
      unset($values[$i]);
    }
    
  }
}