<?php
// $Id: example_role.inc,v 1.1.2.2 2010/07/14 01:30:19 merlinofchaos Exp $

/**
 * @file
 * Plugin to provide access control based upon role membership.
 * This is directly from the ctools module, but serves as a good
 * example of an access plugin
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Accuray TOU accepted"),
  'description' => t('Determine whether the user has accepted a TOU.'),
  'callback' => 'accuray_tou_accepted_access_check',
  'default' => array('vid' => array()),
  'settings form' => 'accuray_tou_accepted_access_settings',
  'summary' => 'accuray_tou_accepted_access_summary',
  'required context' => new ctools_context_required(t('Vocabulary'), 'vocabulary'),
);

/**
 * Settings form for the 'by role' access plugin.
 */
function accuray_tou_accepted_access_settings(&$form, &$form_state, $conf) {
}

/**
 * Compress the roles allowed to the minimum.
 */
function accuray_tou_accepted_access_settings_submit(&$form, &$form_state) {
  return $form;
}

/**
 * Check for access.
 */
function accuray_tou_accepted_access_check($conf, $context) {
  if (empty($context) || empty($context->data) || !isset($context->data->vid)) {
    return FALSE;
  }
  
  $nid = variable_get('accuray_tou_' . $context->data->vid, FALSE);
  
  // No nid is set on this vid, so there's no tou to accept. Which is equivalent to its being accepted.
  if (!$nid) {
    return TRUE;
  }  
  
  if ($_SESSION['accuray_tou_' . $context->data->vid]) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Provide a summary description based upon the checked roles.
 */
function accuray_tou_accepted_access_summary($conf, $context) {
  return t('Check whether users have accepted the terms of use.');
}

