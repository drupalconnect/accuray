<?php

/**
 * Implementation of hook_views_default_views().
 */
function accuray_slideshow_views_default_views() {
  $views = array();

  // Exported view: Slideshow
  $view = new view;
  $view->name = 'Slideshow';
  $view->description = 'Provides the slide show on the home page';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Slideshow';
  $view->core = 6;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['start_paused'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['fixed_height'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['random'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['pause'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['pause_on_click'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['controls'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['pager'] = '2';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['pager_type'] = 'Numbered';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['pager_hover'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['image_count'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['nowrap'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_singleframe']['sync'] = '1';
  $handler->display->display_options['style_options']['mode'] = 'views_slideshow_singleframe';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue (qid) */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['qids'] = array(
    1 => 1,
  );
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
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'slide' => 'slide',
  );
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['Slideshow'] = array(
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
    t('queue'),
    t('Content pane'),
    t('View panes'),
  );

  $views[$view->name] = $view;

  return $views;
}
