<?php

/**
 * Implementation of hook_ds_default_settings().
 */
function accuray_marketing_toolkit_ds_default_settings() {
  $data = array(
    'nd' => array(
      'asset' => array(
        'teaser' => array(
          'fields' => array(
            'field_thumbnail' => array(
              'region' => 'left',
              'weight' => '-100',
              'format' => 'Thumbnail_default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'field_file' => array(
              'region' => 'right',
              'weight' => '-97',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'title' => array(
              'region' => 'middle',
              'weight' => '-99',
              'format' => 'nd_title_p_link',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'disabled',
              'weight' => '-92',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'disabled',
              'weight' => '-91',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-90',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'disabled',
              'weight' => '-93',
              'format' => 'nd_post_date_small',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'middle',
              'weight' => '-98',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'terms_1' => array(
              'region' => 'disabled',
              'weight' => '-96',
              'format' => 'nd_terms_per_vocabulary_space',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'terms_2' => array(
              'region' => 'disabled',
              'weight' => '-95',
              'format' => 'nd_terms_per_vocabulary_space',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'terms' => array(
              'region' => 'disabled',
              'weight' => '-94',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'field_file_info' => array(
              'region' => 'middle',
              'weight' => '-19',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
          'region_styles' => array(
            'header' => '',
            'left' => '',
            'middle' => '',
            'right' => '',
            'footer' => '',
          ),
        ),
      ),
    ),
  );
  return $data;
}
