<?php

/**
 * Implementation of hook_views_default_views().
 */
function accuray_locations_views_default_views() {
  $views = array();

  // Exported view: Locations
  $view = new view;
  $view->name = 'Locations';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Locations';
  $view->core = 6;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = 'php';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Field: Content: Country (field_country) */
  $handler->display->display_options['fields']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['fields']['field_country_value']['table'] = 'apachesolr_node_node_data_field_country';
  $handler->display->display_options['fields']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['fields']['field_country_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_country_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_country_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_country_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_country_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_country_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_country_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_country_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_country_value']['label_type'] = 'none';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return rtrim($row->field_country_value);';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Province (field_province) */
  $handler->display->display_options['fields']['field_province_value']['id'] = 'field_province_value';
  $handler->display->display_options['fields']['field_province_value']['table'] = 'apachesolr_node_node_data_field_province';
  $handler->display->display_options['fields']['field_province_value']['field'] = 'field_province_value';
  $handler->display->display_options['fields']['field_province_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_province_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_province_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_province_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_province_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_province_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_province_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_province_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_province_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_province_value']['label_type'] = 'none';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'if (empty($row->field_province_value)) {
  return $row->field_province_value = t(\'All provinces\');
} else {
  return rtrim($row->field_province_value);
}';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print l(t($value), \'locations/\' . $row->php . \'/\' . $value);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Filter: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if ($static->province[$row->php_1]) {
  return TRUE;
}
$static->province[$row->php_1] = $row->php_1;
return FALSE;
';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );

  /* Display: Countries */
  $handler = $view->new_display('page', 'Countries', 'page_locations');
  $handler->display->display_options['display_description'] = 'Provinces grouped by country';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = 'php';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Country (field_country) */
  $handler->display->display_options['fields']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['fields']['field_country_value']['table'] = 'apachesolr_node_node_data_field_country';
  $handler->display->display_options['fields']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['fields']['field_country_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_country_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_country_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_country_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_country_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_country_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_country_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_country_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_country_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_country_value']['label_type'] = 'none';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return rtrim($row->field_country_value);';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Province (field_province) */
  $handler->display->display_options['fields']['field_province_value']['id'] = 'field_province_value';
  $handler->display->display_options['fields']['field_province_value']['table'] = 'apachesolr_node_node_data_field_province';
  $handler->display->display_options['fields']['field_province_value']['field'] = 'field_province_value';
  $handler->display->display_options['fields']['field_province_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_province_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_province_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_province_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_province_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_province_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_province_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_province_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_province_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_province_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_province_value']['label_type'] = 'none';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'if (empty($row->field_province_value)) {
  return $row->field_province_value = t(\'All provinces\');
} else {
  return rtrim($row->field_province_value);
}';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print l(t($value), \'locations/\' . $row->php . \'/\' . $value);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['path'] = 'locations';

  /* Display: Locations (pane) */
  $handler = $view->new_display('panel_pane', 'Locations (pane)', 'panel_pane_locations');
  $handler->display->display_options['display_description'] = 'Provide locations in a content pane';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['changing'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Content: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['table'] = 'node_data_field_country';
  $handler->display->display_options['arguments']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_country_value']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_country_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_country_value']['ignorecase'] = 0;
  $handler->display->display_options['arguments']['field_country_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_country_value']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['field_country_value']['break_phrase'] = 0;
  /* Argument: Content: Province (field_province) */
  $handler->display->display_options['arguments']['field_province_value']['id'] = 'field_province_value';
  $handler->display->display_options['arguments']['field_province_value']['table'] = 'node_data_field_province';
  $handler->display->display_options['arguments']['field_province_value']['field'] = 'field_province_value';
  $handler->display->display_options['arguments']['field_province_value']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_province_value']['wildcard'] = 'All provinces';
  $handler->display->display_options['arguments']['field_province_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_province_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_province_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_province_value']['ignorecase'] = 0;
  $handler->display->display_options['arguments']['field_province_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_province_value']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['field_province_value']['break_phrase'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_country_value' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Country (field_country)',
    ),
    'field_province_value' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Content: Province (field_province)',
    ),
  );

  /* Display: OpenLayers Data */
  $handler = $view->new_display('openlayers', 'OpenLayers Data', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'openlayers_wkt',
    'other_lat' => 'body',
    'other_lon' => 'body',
    'openlayers_wkt' => 'field_wkt_openlayers_wkt',
    'other_top' => 'body',
    'other_right' => 'body',
    'other_bottom' => 'body',
    'other_left' => 'body',
    'name_field' => 'title',
    'keep_orig_name_field' => 0,
    'description_field' => 'body',
    'keep_orig_desc_field' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: WKT (field_wkt) */
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['id'] = 'field_wkt_openlayers_wkt';
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['table'] = 'apachesolr_node_node_data_field_wkt';
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['field'] = 'field_wkt_openlayers_wkt';
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_wkt_openlayers_wkt']['format'] = 'openlayers_wkt';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Content: Country (field_country) */
  $handler->display->display_options['arguments']['field_country_value']['id'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['table'] = 'node_data_field_country';
  $handler->display->display_options['arguments']['field_country_value']['field'] = 'field_country_value';
  $handler->display->display_options['arguments']['field_country_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_country_value']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_options']['code'] = 'return arg(1);';
  $handler->display->display_options['arguments']['field_country_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_country_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_country_value']['ignorecase'] = 0;
  $handler->display->display_options['arguments']['field_country_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_country_value']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['field_country_value']['break_phrase'] = 0;
  /* Argument: Content: Province (field_province) */
  $handler->display->display_options['arguments']['field_province_value']['id'] = 'field_province_value';
  $handler->display->display_options['arguments']['field_province_value']['table'] = 'node_data_field_province';
  $handler->display->display_options['arguments']['field_province_value']['field'] = 'field_province_value';
  $handler->display->display_options['arguments']['field_province_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_province_value']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_province_value']['wildcard'] = 'All provinces';
  $handler->display->display_options['arguments']['field_province_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_province_value']['default_argument_options']['code'] = 'return arg(2) ? arg(2) : \'All provinces\';';
  $handler->display->display_options['arguments']['field_province_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_province_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_province_value']['ignorecase'] = 0;
  $handler->display->display_options['arguments']['field_province_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_province_value']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['field_province_value']['break_phrase'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );

  /* Display: Locations map (pane) */
  $handler = $view->new_display('panel_pane', 'Locations map (pane)', 'panel_pane_map');
  $handler->display->display_options['display_description'] = 'Locations by region (pane)';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'locations';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['Locations'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Text area'),
    t('Countries'),
    t('Provinces grouped by country'),
    t('Locations (pane)'),
    t('Provide locations in a content pane'),
    t('All'),
    t('View panes'),
    t('OpenLayers Data'),
    t('Locations map (pane)'),
    t('Locations by region (pane)'),
  );

  $views[$view->name] = $view;

  return $views;
}
