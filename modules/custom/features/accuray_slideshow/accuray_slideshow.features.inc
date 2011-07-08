<?php

/**
 * Implementation of hook_node_info().
 */
function accuray_slideshow_node_info() {
  $items = array(
    'slide' => array(
      'name' => t('Slide'),
      'module' => 'features',
      'description' => t('Slideshow slide'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function accuray_slideshow_views_api() {
  return array(
    'api' => '3.0-alpha1',
  );
}
