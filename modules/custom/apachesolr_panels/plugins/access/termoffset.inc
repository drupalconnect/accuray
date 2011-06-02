<?php
if (module_exists('taxonomy')) {
  $plugin = array(
    'title' => t("Taxonomy: depth offset"),
    'description' => t('Control access by the depth of a term.'),
    'callback' => 'ctools_termoffset_ctools_access_check',
    'default' => array('vids' => array()),
    'settings form' => 'ctools_termoffset_ctools_access_settings',
    'settings form validation' => 'ctools_termoffset_ctools_access_settings_validate',
    'settings form submit' => 'ctools_termoffset_ctools_access_settings_submit',
    'summary' => 'ctools_termoffset_ctools_access_summary',
    'required context' => new ctools_context_required(t('Term'), array('term', 'terms')),
  );
}

function ctools_termoffset_ctools_access_check($conf, $context) {
  
  if (empty($context) || empty($context->data) || empty($context->data->vid) || empty($context->data->tid)) {
    //return FALSE;
  }

  $direction = (0 === strpos($conf['offset'], '-', 0) ? 'top' : 'bottom');  
  
  $offset = abs((int) $conf['offset']);
  
  switch ($direction) {
    case 'top':
      $depth = 0;
      $intermediaries = _get_term_max_depth($context->data, $depth);
      break;
    case 'bottom':
      $intermediaries = taxonomy_get_parents_all($context->data->tid);
      $depth = count($intermediaries);
      break;
  }
  return $depth == $offset ? TRUE : FALSE;
}

function _get_term_max_depth($term, &$counter = 0) {
  $children = taxonomy_get_children($term->tid);
  if (count($children)) {
    $counter ++;
    foreach ($children as $child) {
      _get_term_max_depth($child, $counter);
    }
  }
}

function ctools_termoffset_ctools_access_settings(&$form, &$form_state, $conf) {
  
  $form['settings']['offset'] = array(
    '#type' => 'textfield',
    '#title' => 'Offset',
    '#description' => 'This condition will return TRUE if the term is the nth one into the hierarchy, either from the top or from the bottom of the tree. 
      Enter a positive value to count from the bottom of the hierarchy (least deeply nested). 
      Enter a negative value to count from the top of the hierarchy (most deeply nested). -0 indicates the most deeply nested term.',
    '#default_value' => $conf['offset'],
    );
  
}

function ctools_termoffset_ctools_access_settings_validate() {
}

function ctools_termoffset_ctools_access_settings_submit() {
}

function ctools_termoffset_ctools_access_summary() {
}