<?php

/**
 * @file
 * Admin functions for ip2locale module.
 */

/**
 * Menu callback and form builder for admin/settings/ip2locale.
 */
function ip2locale_admin_settings() {
  $options = array(
    IP2LOCALE_FIRST_REQUEST_ONLY => t('First request only'),
    IP2LOCALE_ALL_REQUESTS => t('All requests'),
  );
  $form['ip2locale_redirect_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Redirection mode'),
    '#description' => t("Select the mechanism used to determine when redirection should be applied."),
    '#options' => $options,
    '#default_value' => variable_get('ip2locale_redirect_mode', IP2LOCALE_FIRST_REQUEST_ONLY),
  );
  $form['ip2locale_preserve_user_language'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use prefered language in user account.'),
    '#description' => t("If user is logged in, use language preferences of it's account."),
    '#default_value' => variable_get('ip2locale_preserve_user_language', FALSE),
  );
  $form['ip2locale_save_locale'] = array(
    '#type' => 'checkbox',
    '#title' => t("Save user's locale upon exit."),
    '#description' => t("This option saves the users current language in their session, ensuring that the next time they visit the site they will start on the same language as the previous time. This only works for users that have cookies enabled in their browser."),
    '#default_value' => variable_get('ip2locale_save_locale', TRUE),
  );
  $form['ip2locale_custom_mapping'] = array(
    '#type' => 'textarea',
    '#title' => t('Country Code to Language Code mappings'),
    '#description' => t('A list of custom mappings from ISO 3166 2-character <em>Country Code</em> to Drupal <em>Language Code</em>, one on each line. eg.<br/>gb,en<br/>ie,en<br/>us,en'),
    '#default_value' => variable_get('ip2locale_custom_mapping', ''),
    '#element_validate' => array('_ip2locale_validate_custom_mapping'),
  );
  $form['ip2locale_pages'] = array(
     '#type' => 'textarea',
     '#title' => t('Pages for which redirection should be performed'),
     '#default_value' => variable_get('ip2locale_pages', "*"),
     '#cols' => 40,
     '#rows' => 5,
     '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are '<em>blog</em>' for the blog page and '<em>blog/*</em>' for every personal blog. '<em>&lt;front&gt;</em>' is the front page."),
  );
  $form['ip2locale_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('ip2locale debug mode'),
    '#description' => t('With this setting enabled, an IP may be passed in through the query string using the ip2locale_debug parameter. This should not be used on production sites.'),
    '#default_value' => variable_get('ip2locale_debug', FALSE),
  );
  return system_settings_form($form);
}

/**
 * Menu callback and form builder for admin/settings/ip2locale.
 */
function ip2locale_admin_backend_settings() {
  $supported_backends = ip2locale_backend_list('supported');
  $available_backends = ip2locale_backend_list('available');
  $enabled_backends = ip2locale_backend_list('enabled');

  // drupal_add_js(drupal_get_path('module', 'ip2locale') .'/ip2locale.js');

  // Weights range from -delta to +delta, so delta should be at least half
  // of the amount of backends present. This makes sure all backends get
  // a unique weight.
  $weight_delta = round(count($supported_backends) / 2);

  // Build form tree
  $form = array(
    '#action' => url('admin/settings/ip2locale/backends'),
    '#tree' => TRUE,
  );

  foreach ($available_backends as $module => $function) {
    $available = $available_backends[$module]? t('yes') : t('no');
    $enabled = isset($enabled_backends[$module])? t('yes') : t('no');

    $enable_link = l(t('Enable'), 'ip2locale/backend/enable/'. $module);
    $disable_link = l(t('Disable'), 'ip2locale/backend/disable/'. $module);

    $ops = isset($enabled_backends[$module])? $disable_link : $enable_link;

    $form['backends'][$module]['name'] = array(
      '#value' => $module,
    );
    $form['backends'][$module]['weight'] = array(
      '#type' => 'weight',
      '#delta' => $weight_delta,
      '#default_value' => variable_get('ip2locale_'. $module .'_weight', 0),
      '#attributes' => array('class' => 'ip2locale-table-weight')
    );
    $form['backends'][$module]['enabled'] = array(
      '#value' => $enabled,
    );
    $form['backends'][$module]['ops'] = array(
      '#value' => $ops,
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

function ip2locale_admin_backend_settings_submit($form, &$form_state) {
  foreach ($form_state['values']['backends'] as $module => $details) {
    variable_set('ip2locale_'. $module .'_weight', $details['weight']);
  }
  drupal_set_message(t('The changes have been saved.'));
}

// Displays a paged list and overview of existing product fees.
function theme_ip2locale_admin_backend_settings($form) {
  $header = array(t('Module'), t('Weight'), t('Enabled'), t('Actions'));

  if (count(element_children($form['backends'])) > 0) {
    foreach (element_children($form['backends']) as $module) {
      $row = array(
        drupal_render($form['backends'][$module]['name']),
        drupal_render($form['backends'][$module]['weight']),
        drupal_render($form['backends'][$module]['enabled']),
        drupal_render($form['backends'][$module]['ops']),
      );

      $rows[] = array(
        'data' => $row,
        'class' => 'draggable',
      );
    }
  }
  else {
    $rows[] = array(
      array('data' => t('No backends are available.'), 'colspan' => 4),
    );
  }

  drupal_add_tabledrag('ip2locale-table', 'order', 'sibling', 'ip2locale-table-weight');
  $output = theme('table', $header, $rows, array('id' => 'ip2locale-table'));
  $output .= drupal_render($form);

  return $output;
}


/**
 * Validation callback. Ensure keys are not duplicated.
 */
function _ip2locale_validate_custom_mapping($element, $form_state) {
  // Check for duplicate key values to prevent unexpected data loss.
  if (!empty($element['#value'])) {
    $lines = explode("\n", $element['#value']);
    $existing_keys = array();
    $invalid_maps = array();
    $duplicate_keys = array();
    $group = '';
    foreach ($lines as $line) {
      $matches = array();
      $line = trim($line);
      if (preg_match('/^([^,]+)\,(.*)$/', $line, $matches)) {
        $key = $matches[1];
      }
      else {
        $invalid_maps[$line] = $line;
      }

      if (isset($key)) {
        if (isset($existing_keys[$group][$key])) {
          $duplicate_keys[$key] = $key;
        }
        else {
          $existing_keys[$group][$key] = $key;
        }
      }
    }

    if (!empty($invalid_maps)) {
      form_error($element, t('Each custom IP 2 Locale map must be in the format \'cc,lc\' (ISO 3166 2-character <em>Country Code</em> to Drupal <em>Language Code</em>) eg.') .'<br/>'. t('\'ie,en\' (<em>Ireland</em> to <em>English</em>)') .'<br/>'. t('\'us,en\' (<em>United States</em> to <em>English</em>)') .'<br/>'. t('The following mappings are invalid:') . theme('item_list', $invalid_maps));
    }

    if (!empty($duplicate_keys)) {
      form_error($element, t('Country Codes within the Custom IP 2 Locale mappings list must be unique. The following Country Codes have been used multiple times:') . theme('item_list', $duplicate_keys));
    }

  }

  return TRUE;
}
