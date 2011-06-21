<?php
// $Id: domain.inc,v 1.2 2009/10/24 16:16:54 agentken Exp $

/**
 * @file
 * Plugin to provide access control based upon active domain.
 */

/**
 * Implement hook_ctools_access().
 */
function domain_ctools_domain_ctools_access() {
  return array(
    'title' => t('Domain Access'),
    'description' => t('Control access by active domain.'),
    'callback' => 'domain_ctools_domain_access_check',
    'default' => array('domains' => array(), 'domain_site' => TRUE),
    'settings form' => 'domain_ctools_domain_access_settings',
    'summary' => 'domain_ctools_domain_acesss_summary',
  );
}

/**
 * Settings form domain access plugin.
 */
function domain_ctools_domain_access_settings(&$form, &$form_state, $conf) {
  $domains = domain_domains();
  $options = array();
  $format = domain_select_format();
  foreach ($domains as $domain) {
    // Checkboxes cannot handles zeros.
    if ($domain['domain_id'] == 0) {
      $domain['domain_id'] = -1;
    }
    // The domain must be valid.
    if ($domain['valid'] || user_access('access inactive domains')) {
      // Filter checkboxes but not select lists.
      $options[$domain['domain_id']] = empty($format) ? check_plain($domain['sitename']) : $domain['sitename'];
    }
  }
  $form['settings']['domain_site'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show on all affiliates'),
    '#default_value' => isset($conf['domain_site']) ? $conf['domain_site'] : TRUE,
    '#description' => t('Show content on all domains. This setting will override the domain-specific options below.'),
  );
  $form['settings']['domains'] = array(
    '#type' => empty($format) ? 'checkboxes' : 'select',
    '#title' => t('Domains'),
    '#default_value' => isset($conf['domains']) ? $conf['domains'] : array(),
    '#options' => $options,
    '#description' => t('This content will only be visible on the selected domains.'),
  );
  if ($format) {
    $form['settings']['domains']['#multiple'] = TRUE;
    $form['settings']['domains']['#size'] = count($options) > 10 ? 10 : count($options);
  }
}

/**
 * Check for access based on the currently active domain.
 */
function domain_ctools_domain_access_check($conf, $context) {
  global $_domain;
  if ($conf['domain_site']) {
    return TRUE;
  }
  // Check each domain, converting -1 to 0.
  foreach ($conf['domains'] as $key => $value) {
    $id = ($key == -1) ? 0 : $key;
    if (abs($value) > 0 && $id == $_domain['domain_id']) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Provide a summary description based upon the checked domains.
 */
function domain_ctools_domain_acesss_summary($conf, $context) {
  // Visible on all domains?
  if ($conf['domain_site'] || !isset($conf['domains'])) {
    $conf['domains'] = array();
    $output = t('Content is visible on all domains.');
  }
  // Determine visibility.
  else {
    $domains = domain_domains();
    $names = array();
    foreach (array_filter($conf['domains']) as $key) {
      $id = ($key == -1) ? 0 : $key;
      $names[] = check_plain($domains[$id]['sitename']);
    }
    // Print the proper message.
    if (empty($names) && empty($output)) {
      $output = t('Content is visible on no domains.');
    }
    else {
      $output = t('Visible on !domains.', array('!domains' => implode(', ', $names)));
    }
  }
  return $output;
}
