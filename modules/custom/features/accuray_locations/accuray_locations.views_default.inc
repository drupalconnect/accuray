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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = 'name';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province_1']['id'] = 'province_1';
  $handler->display->display_options['fields']['province_1']['table'] = 'location';
  $handler->display->display_options['fields']['province_1']['field'] = 'province';
  $handler->display->display_options['fields']['province_1']['label'] = '';
  $handler->display->display_options['fields']['province_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['province_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['province_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['province_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['province_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['province_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['province_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['province_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['province_1']['style'] = 'code';
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['label'] = '';
  $handler->display->display_options['fields']['province']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['province']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['province']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['province']['alter']['external'] = 0;
  $handler->display->display_options['fields']['province']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['province']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['province']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['province']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['province']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['province']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['province']['alter']['html'] = 0;
  $handler->display->display_options['fields']['province']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['province']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['province']['hide_empty'] = 0;
  $handler->display->display_options['fields']['province']['empty_zero'] = 0;
  /* Filter: Taxonomy: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    4 => '4',
  );
  /* Filter: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if ($static->province[$row->province]) {
  return TRUE;
}
$static->province[$row->province] = $row->province;
return FALSE;
';

  /* Display: Regions */
  $handler = $view->new_display('page', 'Regions', 'page_locations');
  $handler->display->display_options['display_description'] = 'Locations grouped by region';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province_1']['id'] = 'province_1';
  $handler->display->display_options['fields']['province_1']['table'] = 'location';
  $handler->display->display_options['fields']['province_1']['field'] = 'province';
  $handler->display->display_options['fields']['province_1']['label'] = '';
  $handler->display->display_options['fields']['province_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['province_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['province_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['province_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['province_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['province_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['province_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['province_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['province_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['province_1']['style'] = 'code';
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['label'] = '';
  $handler->display->display_options['fields']['province']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['province']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['province']['alter']['path'] = 'locations/[province_1]';
  $handler->display->display_options['fields']['province']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['province']['alter']['external'] = 0;
  $handler->display->display_options['fields']['province']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['province']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['province']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['province']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['province']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['province']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['province']['alter']['html'] = 0;
  $handler->display->display_options['fields']['province']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['province']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['province']['hide_empty'] = 0;
  $handler->display->display_options['fields']['province']['empty_zero'] = 0;
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
  /* Argument: Location: Province */
  $handler->display->display_options['arguments']['province']['id'] = 'province';
  $handler->display->display_options['arguments']['province']['table'] = 'location';
  $handler->display->display_options['arguments']['province']['field'] = 'province';
  $handler->display->display_options['arguments']['province']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['province']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['province']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['province']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['province']['validate_fail'] = 'empty';
  $handler->display->display_options['argument_input'] = array(
    'province' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Location: Province',
    ),
  );

  /* Display: OpenLayers Data */
  $handler = $view->new_display('openlayers', 'OpenLayers Data', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'latitude',
    'other_lon' => 'longitude',
    'openlayers_wkt' => 'latitude',
    'other_top' => 'latitude',
    'other_right' => 'latitude',
    'other_bottom' => 'latitude',
    'other_left' => 'latitude',
    'name_field' => 'title',
    'keep_orig_name_field' => 1,
    'description_field' => 'body',
    'keep_orig_desc_field' => 1,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Location: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'location';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['latitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['latitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['latitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['latitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['latitude']['style'] = 'dd';
  /* Field: Location: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'location';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['longitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['longitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['longitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['longitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['longitude']['style'] = 'dd';
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Location: Province */
  $handler->display->display_options['arguments']['province']['id'] = 'province';
  $handler->display->display_options['arguments']['province']['table'] = 'location';
  $handler->display->display_options['arguments']['province']['field'] = 'province';
  $handler->display->display_options['arguments']['province']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['province']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['province']['default_argument_skip_url'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Taxonomy: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    4 => '4',
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
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Text area'),
    t('Regions'),
    t('Locations grouped by region'),
    t('locations/[province_1]'),
    t('Locations (pane)'),
    t('Provide locations in a content pane'),
    t('All'),
    t('View panes'),
    t('OpenLayers Data'),
    t('Latitude'),
    t('Longitude'),
    t('Locations map (pane)'),
    t('Locations by region (pane)'),
  );

  $views[$view->name] = $view;

  return $views;
}
