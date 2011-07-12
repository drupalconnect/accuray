<?php

/**
 * Implementation of hook_content_default_fields().
 */
function accuray_events_content_default_fields() {
  $fields = array();

  // Exported field: field_address_1
  $fields['event-field_address_1'] = array(
    'field_name' => 'field_address_1',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-94',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_address_1',
        'label_value' => '',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'bubble' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'css-class' => '',
        'exclude' => 0,
        'weight' => '-94',
        'format' => 'default',
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_address_1][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'rows' => 5,
      'size' => '60',
      'label' => 'Address line 1',
      'weight' => '10',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_address_2
  $fields['event-field_address_2'] = array(
    'field_name' => 'field_address_2',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-93',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_address_2',
        'label_value' => '',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'bubble' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'css-class' => '',
        'exclude' => 0,
        'weight' => '-93',
        'format' => 'default',
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_address_2][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Address line 2',
      'weight' => '11',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_address_3
  $fields['event-field_address_3'] = array(
    'field_name' => 'field_address_3',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-92',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_address_3',
        'label_value' => '',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'bubble' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'css-class' => '',
        'exclude' => 0,
        'weight' => '-92',
        'format' => 'default',
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_address_3][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Address line 3',
      'weight' => '12',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_city
  $fields['event-field_city'] = array(
    'field_name' => 'field_city',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-91',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_city',
        'label_value' => '',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'bubble' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'css-class' => '',
        'exclude' => 0,
        'weight' => '-91',
        'format' => 'default',
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => 'All',
          '_error_element' => 'default_value_widget][field_city][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'City',
      'weight' => '14',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_country
  $fields['event-field_country'] = array(
    'field_name' => 'field_country',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-66',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'disabled',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_country',
        'label_value' => '',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'bubble' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'css-class' => '',
        'exclude' => 0,
        'weight' => '-66',
        'format' => 'default',
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => 'USA',
          '_error_element' => 'default_value_widget][field_country][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Country',
      'weight' => '16',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date
  $fields['event-field_date'] = array(
    'field_name' => 'field_date',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-100',
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'datestamp',
        'parent_id' => '',
        'field_id' => 'field_date',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-100',
      ),
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'short',
        'css-class' => '',
        'region' => 'right',
        'type' => 'datestamp',
        'parent_id' => '',
        'field_id' => 'field_date',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-96',
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datestamp',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => 'optional',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - H:i',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Event date',
      'weight' => '3',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_link
  $fields['event-field_link'] = array(
    'field_name' => 'field_link',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-98',
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'link',
        'parent_id' => '',
        'field_id' => 'field_link',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-98',
      ),
      'teaser' => array(
        'label' => array(
          'format' => 'inline',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'link',
        'parent_id' => '',
        'field_id' => 'field_link',
        'label_value' => 'More information',
        'exclude' => 0,
        'weight' => '-97',
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'format' => 'default',
        'exclude' => 0,
        'css-class' => '',
        'weight' => '-95',
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => '_blank',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'optional',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'title' => '',
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Link',
      'weight' => '-4',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_postcode
  $fields['event-field_postcode'] = array(
    'field_name' => 'field_postcode',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-89',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_postcode',
        'label_value' => '',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'bubble' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'css-class' => '',
        'exclude' => 0,
        'weight' => '-89',
        'format' => 'default',
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_postcode][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Post code',
      'weight' => '15',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_province
  $fields['event-field_province'] = array(
    'field_name' => 'field_province',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-90',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_province',
        'label_value' => '',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'bubble' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'css-class' => '',
        'exclude' => 0,
        'weight' => '-90',
        'format' => 'default',
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => 'All',
          '_error_element' => 'default_value_widget][field_province][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Province',
      'weight' => '13',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_thumbnail
  $fields['event-field_thumbnail'] = array(
    'field_name' => 'field_thumbnail',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-95',
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'Thumbnail_default',
        'css-class' => '',
        'region' => 'right',
        'type' => 'filefield',
        'parent_id' => '',
        'field_id' => 'field_thumbnail',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-95',
      ),
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'Thumbnail_default',
        'css-class' => '',
        'region' => 'left',
        'type' => 'filefield',
        'parent_id' => '',
        'field_id' => 'field_thumbnail',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-100',
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'sticky' => array(
        'format' => 'Thumbnail_default',
        'exclude' => 0,
        'weight' => '-100',
        'css-class' => '',
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Thumbnail',
      'weight' => '-3',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_wkt
  $fields['event-field_wkt'] = array(
    'field_name' => 'field_wkt',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-69',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'disabled',
        'type' => 'openlayers_wkt',
        'parent_id' => '',
        'field_id' => 'field_wkt',
        'label_value' => '',
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'bubble' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'css-class' => '',
        'exclude' => 0,
        'weight' => '-69',
        'format' => 'default',
      ),
    ),
    'widget_active' => '1',
    'type' => 'openlayers_wkt',
    'required' => '0',
    'multiple' => '0',
    'module' => 'openlayers_cck',
    'active' => '1',
    'openlayers_cck_feature_types' => array(
      'point' => 'point',
      'path' => 'path',
      'polygon' => 'polygon',
    ),
    'widget' => array(
      'openlayers_cck_preset_map' => 'default',
      'openlayers_behaviors' => array(
        'openlayers_behavior_zoomtolayer' => array(
          'enabled' => 0,
          'options' => array(
            'zoomtolayer' => 'openlayers_cck_vector_layer',
            'point_zoom_level' => '5',
          ),
        ),
      ),
      'default_value' => array(
        '0' => array(
          'openlayers_wkt' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'WKT',
      'weight' => '16',
      'description' => '',
      'type' => 'rules_geocoder_widget',
      'module' => 'rules_geocoder',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address line 1');
  t('Address line 2');
  t('Address line 3');
  t('City');
  t('Country');
  t('Event date');
  t('Link');
  t('Post code');
  t('Province');
  t('Thumbnail');
  t('WKT');

  return $fields;
}
