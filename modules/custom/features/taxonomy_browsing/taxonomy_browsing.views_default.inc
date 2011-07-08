<?php

/**
 * Implementation of hook_views_default_views().
 */
function taxonomy_browsing_views_default_views() {
  $views = array();

  // Exported view: LineageNestedList
  $view = new view;
  $view->name = 'LineageNestedList';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'term_data';
  $view->human_name = 'Lineage nested list';
  $view->core = 6;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = 'name';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy: Node */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'term_node';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  $handler->display->display_options['relationships']['vid']['required'] = 0;
  /* Relationship: Taxonomy: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['required'] = 1;
  /* Field: title_count */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['title_1']['ui_name'] = 'title_count';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Taxonomy: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['format_plural'] = 0;
  /* Field: Taxonomy: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid_1']['label'] = '';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['tid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid_1']['format_plural'] = 0;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Taxonomy: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 1;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
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
  $handler->display->display_options['fields']['php']['element_type'] = '0';
  $handler->display->display_options['fields']['php']['element_label_type'] = '0';
  $handler->display->display_options['fields']['php']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 1;
  $handler->display->display_options['fields']['php']['empty_zero'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print ($row->description ? \' - \' . $row->description : \'\') . (!$row->title_1 ? \' \' . l(\'More&nbsp;>\', \'taxonomy/term/\'.$row->tid, array(\'html\' => TRUE)) : \'\'); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_type'] = '0';
  $handler->display->display_options['fields']['view']['element_label_type'] = '0';
  $handler->display->display_options['fields']['view']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['view']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view']['hide_empty'] = 1;
  $handler->display->display_options['fields']['view']['empty_zero'] = 1;
  $handler->display->display_options['fields']['view']['view'] = 'NodeTeasers';
  $handler->display->display_options['fields']['view']['arguments'] = '[nid]';
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'parent';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['not'] = 0;

  /* Display: By term */
  $handler = $view->new_display('panel_pane', 'By term', 'panel_pane_by_term');
  $handler->display->display_options['display_description'] = 'Take term as an argument';
  $handler->display->display_options['pane_title'] = 'Lineage nested list (by term)';
  $handler->display->display_options['argument_input'] = array(
    'vid' => array(
      'type' => 'user',
      'context' => 'term.vid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy: Vocabulary ID',
    ),
    'tid' => array(
      'type' => 'context',
      'context' => 'term.tid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy: Term ID',
    ),
  );

  /* Display: By vocabulary */
  $handler = $view->new_display('panel_pane', 'By vocabulary', 'panel_pane_by_vocabulary');
  $handler->display->display_options['display_description'] = 'Take vocabulary as an argument';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy: Node */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'term_node';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  $handler->display->display_options['relationships']['vid']['required'] = 0;
  /* Relationship: Taxonomy: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['required'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Taxonomy: Vocabulary ID */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'vocabulary';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'return is_null($data->term_data_term_hierarchy_tid) ? FALSE : TRUE;';
  $handler->display->display_options['pane_title'] = 'Lineage nested list (by vocabulary)';
  $handler->display->display_options['argument_input'] = array(
    'vid' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy: Vocabulary ID',
    ),
    'tid' => array(
      'type' => 'none',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy: Term ID',
    ),
  );
  $translatables['LineageNestedList'] = array(
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
    t('node'),
    t('Parent'),
    t('Term ID'),
    t('.'),
    t(','),
    t('All'),
    t('By term'),
    t('Take term as an argument'),
    t('Lineage nested list (by term)'),
    t('View panes'),
    t('By vocabulary'),
    t('Take vocabulary as an argument'),
    t('Lineage nested list (by vocabulary)'),
  );

  $views[$view->name] = $view;

  // Exported view: LineageNestedListFallback
  $view = new view;
  $view->name = 'LineageNestedListFallback';
  $view->description = 'If there\'s no lineage to work with, then simply display teasers or empty text';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Lineage nested list fallback';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['changing'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'We created this category because we are about to add content. But you seem to have beaten us to the punch. It\'s also possible the content was misfiled. So please try a search or contact us to let us know about the problem.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_node';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['tid']['use_synonym_for_summary_links'] = 0;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'context',
      'context' => 'term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy: Term ID',
    ),
  );
  $translatables['LineageNestedListFallback'] = array(
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
    t('We created this category because we are about to add content. But you seem to have beaten us to the punch. It\'s also possible the content was misfiled. So please try a search or contact us to let us know about the problem.'),
    t('All'),
    t('Content pane'),
    t('View panes'),
  );

  $views[$view->name] = $view;

  // Exported view: NodeTeasers
  $view = new view;
  $view->name = 'NodeTeasers';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Node teasers';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['changing'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'asset' => 'asset',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $translatables['NodeTeasers'] = array(
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
    t('All'),
  );

  $views[$view->name] = $view;

  return $views;
}
