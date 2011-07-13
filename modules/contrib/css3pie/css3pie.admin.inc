<?php

/**
 *  CSS3PIE Administrative settings form
 */
function css3pie_admin() {
 $form = array();

  $form['css3pie_css_selectors'] = array(
    '#type' => 'textarea',
    '#title' => t('CSS Selectors'),
    '#cols' => 40,
    '#rows' => 3,
    '#prefix' => '<div class="css3pie-selector">',
    '#suffix' => '</div>',
    '#default_value' => variable_get('css3pie_css_selectors', ''),
    '#description' => t('Use normal CSS Selectors here .class or #id use new line per selector'),
  );

  $form['css3pie_css_comment'] = array(
    '#type' => 'select',
    '#title' => t('Display namespace as comment in css file'),
    '#description' => t('renders the used namespace names in to css as comment'),
    '#default_value' => variable_get('css3pie_css_comment', TRUE),
    '#options' => array(
      FALSE => t('No'),
      TRUE => t('Yes'),
    ),
  );

  $form['css3pie_css_use_php_wrapper'] = array(
    '#type' => 'select',
    '#title' => t('Use PHP wrapper'),
    '#description' => t("old server doesn't have the right mime type for .htc files so you can use the php wrapper to simulate it (uses the PIE.php from css3pie package)."),
    '#default_value' => variable_get('css3pie_css_use_php_wrapper', FALSE),
    '#options' => array(
      FALSE => t('No'),
      TRUE => t('Yes'),
    ),
  );

 return system_settings_form($form);
}

/**
 * Rebuild the CSS file only on Save submit
 *
 * @param <type> $form
 * @param <type> $form_state
 */
function css3pie_admin_submit($form, &$form_state) {

  // check if submit button was pressed and rebuild the css file
  // we must use "clicked_button" becaus values['op'] was unset by
  // system_settings_form_submit.
  $op = isset($form_state['clicked_button']['#value']) ? $form_state['clicked_button']['#value'] : '';
  if ($op == t('Save configuration')) {
    _css3pie_build_css3pie_css();
  }
}

/**
 * Implements hook_form_alter()
 * we need to run our css file building after the system_settings_form_submit handler
 * has runned because we have new values and we read the variable with variable_get...
 * 
 * @param array $form
 * @param <type> $form_state
 */
function css3pie_form_css3pie_admin_alter(&$form, &$form_state) {
  // rebuild the css file after save of the new variables
  // system_settings_form_submit must be run before we want to rebuild.
  $form['#submit'][] = 'css3pie_admin_submit';
}
