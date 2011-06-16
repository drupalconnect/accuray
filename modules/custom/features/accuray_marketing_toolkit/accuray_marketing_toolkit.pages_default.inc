<?php

/**
 * Implementation of hook_default_page_manager_pages().
 */
function accuray_marketing_toolkit_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'marketing_toolkit';
  $page->task = 'page';
  $page->admin_title = '';
  $page->admin_description = '';
  $page->path = 'marketing-toolkit/!toolkit/!section';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'toolkit' => array(
      'id' => 3,
      'identifier' => 'Taxonomy term: ID Toolkit',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'term',
        'vids' => array(
          1 => 1,
          2 => 0,
        ),
        'breadcrumb' => 1,
      ),
    ),
    'section' => array(
      'id' => 2,
      'identifier' => 'Taxonomy term: ID Section',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          2 => 2,
          1 => 0,
        ),
        'breadcrumb' => 1,
      ),
    ),
  );
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_marketing_toolkit_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'marketing_toolkit';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Media kit section',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'name' => 'solrquery',
        'id' => 1,
        'identifier' => 'Apache Solr Base Query',
        'keyword' => 'solrquery',
        'context_settings' => array(
          'queryvalues' => 'append',
          'base_path' => '',
        ),
      ),
    ),
    'relationships' => array(
      0 => array(
        'context' => array(
          0 => 'context_solrquery_1',
          1 => 'argument_term_3',
        ),
        'name' => 'query_from_context',
        'id' => 1,
        'identifier' => 'Apache Solr query filter toolkit',
        'keyword' => 'queryfilter_toolkit',
      ),
      1 => array(
        'context' => array(
          0 => 'context_solrquery_1',
          1 => 'argument_term_2',
        ),
        'name' => 'query_from_context',
        'id' => 2,
        'identifier' => 'Apache Solr query filter section',
        'keyword' => 'queryfilter_section',
      ),
      2 => array(
        'context' => 'context_solrquery_1',
        'name' => 'response_from_query',
        'id' => 1,
        'identifier' => 'Apache Solr response',
        'keyword' => 'response_from_query',
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_term_2',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_term_2',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'termoffset',
          'settings' => array(
            'offset' => '-1',
          ),
          'context' => 'argument_term_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible:marketing_toolkit';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'first' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%section:name';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '%section:name',
      'body' => '',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'MarketingToolkitSection-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'first';
    $pane->type = 'block';
    $pane->subtype = 'apachesolr_search-im_vid_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['first'][0] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_marketing_toolkit_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'marketing_toolkit';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Media kit overview',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'name' => 'solrquery',
        'id' => 1,
        'identifier' => 'Apache Solr Base Query',
        'keyword' => 'solrquery',
        'context_settings' => array(
          'queryvalues' => 'append',
          'base_path' => '',
        ),
      ),
    ),
    'relationships' => array(
      0 => array(
        'context' => array(
          0 => 'context_solrquery_1',
          1 => 'argument_term_3',
        ),
        'name' => 'query_from_context',
        'id' => 1,
        'identifier' => 'Apache Solr query filter toolkit',
        'keyword' => 'queryfilter_toolkit',
      ),
      1 => array(
        'context' => array(
          0 => 'context_solrquery_1',
          1 => 'argument_term_2',
        ),
        'name' => 'query_from_context',
        'id' => 2,
        'identifier' => 'Apache Solr query filter section',
        'keyword' => 'queryfilter_section',
      ),
      2 => array(
        'context' => 'context_solrquery_1',
        'name' => 'response_from_query',
        'id' => 1,
        'identifier' => 'Apache Solr response',
        'keyword' => 'response_from_query',
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_term_3',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible:marketing_toolkit';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'first' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '%toolkit:name marketing toolkit',
      'body' => 'Accuray is delighted to share with you the newly developed CyberKnife&reg; Communications Toolkit. Developed specifically for CyberKnife hospitals and centers, the CyberKnife Communications Toolkit is a comprehensive resource of marketing and communications materials designed to generate awareness for your facility and CyberKnife System. Included in this kit are images and animations, videos, ad templates, press materials, peer to peer health care outreach materials and much more.',
      'format' => '2',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'MarketingToolkitOverview-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_3',
        1 => 'relationship_response_from_query_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'first';
    $pane->type = 'block';
    $pane->subtype = 'apachesolr_search-im_vid_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['first'][0] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_marketing_toolkit_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'marketing_toolkit';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Media kit section catchall',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'name' => 'solrquery',
        'id' => 1,
        'identifier' => 'Apache Solr Base Query',
        'keyword' => 'solrquery',
        'context_settings' => array(
          'queryvalues' => 'append',
          'base_path' => '',
        ),
      ),
    ),
    'relationships' => array(
      0 => array(
        'context' => array(
          0 => 'context_solrquery_1',
          1 => 'argument_term_3',
        ),
        'name' => 'query_from_context',
        'id' => 1,
        'identifier' => 'Apache Solr query filter toolkit',
        'keyword' => 'queryfilter_toolkit',
      ),
      1 => array(
        'context' => array(
          0 => 'context_solrquery_1',
          1 => 'argument_term_2',
        ),
        'name' => 'query_from_context',
        'id' => 2,
        'identifier' => 'Apache Solr query filter section',
        'keyword' => 'queryfilter_section',
      ),
      2 => array(
        'context' => 'context_solrquery_1',
        'name' => 'response_from_query',
        'id' => 1,
        'identifier' => 'Apache Solr response',
        'keyword' => 'response_from_query',
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_term_2',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_term_2',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'termoffset',
          'settings' => array(
            'offset' => '-0',
          ),
          'context' => 'argument_term_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'flexible:marketing_toolkit';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'first' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%section:name';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '%section:name',
      'body' => '',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'MediaKitSectionCatchall-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_2',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'first';
    $pane->type = 'block';
    $pane->subtype = 'apachesolr_search-im_vid_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['first'][0] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['marketing_toolkit'] = $page;

 return $pages;

}
