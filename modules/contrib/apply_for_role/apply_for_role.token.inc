<?php
// $Id: apply_for_role.token.inc,v 1.3 2008/10/17 08:20:56 sorenjones Exp $

/**
 * Implementation of hook_token_values().
 */
function apply_for_role_token_values($type, $object = NULL, $options = array()) {
  $values = array();
  switch ($type) {
    case 'apply_for_role':
      // Cast to an object just in case fussy Drupal gave us an array
      $apply = (object)$object;

      $roles = user_roles();
      $user = isset($apply->user) ? $apply->user : user_load(array('uid' => $apply->uid));

      $values['apply_for_role-uid']         = $apply->uid;
      $values['apply_for_role-name']        = check_plain($user->name);
      $values['apply_for_role-name-raw']    = $user->name;
      $values['apply_for_role-mail']        = check_plain($user->mail);
      $values['apply_for_role-mail-raw']    = $user->mail;

      $values['apply_for_role-rid']         = $apply->rid;
      $values['apply_for_role-role']        = check_plain($roles[$apply->rid]);
      $values['apply_for_role-status']      = check_plain(theme('apply_for_role_status', $apply->approved));

      $values['apply_for_role-apply_date-yyyy']   = date('Y', $apply->apply_date);
      $values['apply_for_role-apply_date-yy']     = date('y', $apply->apply_date);
      $values['apply_for_role-apply_date-month']  = date('F', $apply->apply_date);
      $values['apply_for_role-apply_date-mon']    = date('M', $apply->apply_date);
      $values['apply_for_role-apply_date-mm']     = date('m', $apply->apply_date);
      $values['apply_for_role-apply_date-m']      = date('n', $apply->apply_date);
      $values['apply_for_role-apply_date-ww']     = date('W', $apply->apply_date);
      $values['apply_for_role-apply_date-date']   = date('N', $apply->apply_date);
      $values['apply_for_role-apply_date-day']    = date('l', $apply->apply_date);
      $values['apply_for_role-apply_date-ddd']    = date('D', $apply->apply_date);
      $values['apply_for_role-apply_date-dd']     = date('d', $apply->apply_date);
      $values['apply_for_role-apply_date-d']      = date('j', $apply->apply_date);
      break;
  }

  return $values;
}

/**
 * Implementation of hook_token_list().
 */
function apply_for_role_token_list($type = 'all') {
  if ($type == 'apply_for_role' || $type == 'all') {
    $tokens['apply_for_role']['apply_for_role-uid']       = t("Applicant's user ID");
    $tokens['apply_for_role']['apply_for_role-name']      = t("Applicant's user name");
    $tokens['apply_for_role']['apply_for_role-name-raw']  = t("Applicant's user name. WARNING - raw user input.");
    $tokens['apply_for_role']['apply_for_role-mail']      = t("Applicant's e-mail.");
    $tokens['apply_for_role']['apply_for_role-mail-raw']  = t("Applicant's e-mail. WARNING - raw user input.");

    $tokens['apply_for_role']['apply_for_role-rid']       = t('Application role ID');
    $tokens['apply_for_role']['apply_for_role-role']      = t('Application role name');
    $tokens['apply_for_role']['apply_for_role-status']    = t('Application status');

    $tokens['apply_for_role']['apply_for_role-apply_date-yyyy']  = t("Application creation year (four digit)");
    $tokens['apply_for_role']['apply_for_role-apply_date-yy']    = t("Application creation year (two digit)");
    $tokens['apply_for_role']['apply_for_role-apply_date-month'] = t("Application creation month (full word)");
    $tokens['apply_for_role']['apply_for_role-apply_date-mon']   = t("Application creation month (abbreviated)");
    $tokens['apply_for_role']['apply_for_role-apply_date-mm']    = t("Application creation month (two digit, zero padded)");
    $tokens['apply_for_role']['apply_for_role-apply_date-m']     = t("Application creation month (one or two digit)");
    $tokens['apply_for_role']['apply_for_role-apply_date-ww']    = t("Application creation week (two digit)");
    $tokens['apply_for_role']['apply_for_role-apply_date-date']  = t("Application creation date (day of month)");
    $tokens['apply_for_role']['apply_for_role-apply_date-day']   = t("Application creation day (full word)");
    $tokens['apply_for_role']['apply_for_role-apply_date-ddd']   = t("Application creation day (abbreviation)");
    $tokens['apply_for_role']['apply_for_role-apply_date-dd']    = t("Application creation day (two digit, zero-padded)");
    $tokens['apply_for_role']['apply_for_role-apply_date-d']     = t("Application creation day (one or two digit)");
    return $tokens;
  }
}
