<?php

/**
 * Implementation of hook_content_default_fields().
 */
function accuray_locations_content_default_fields() {
  $fields = array();

  // Exported field: field_address_1
  $fields['location-field_address_1'] = array(
    'field_name' => 'field_address_1',
    'type_name' => 'location',
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
      'weight' => '40',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_address_2
  $fields['location-field_address_2'] = array(
    'field_name' => 'field_address_2',
    'type_name' => 'location',
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
      'weight' => '42',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_address_3
  $fields['location-field_address_3'] = array(
    'field_name' => 'field_address_3',
    'type_name' => 'location',
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
      'weight' => '41',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_city
  $fields['location-field_city'] = array(
    'field_name' => 'field_city',
    'type_name' => 'location',
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
      'weight' => '43',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_country
  $fields['location-field_country'] = array(
    'field_name' => 'field_country',
    'type_name' => 'location',
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
      'weight' => '46',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_email
  $fields['location-field_email'] = array(
    'field_name' => 'field_email',
    'type_name' => 'location',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-95',
      'teaser' => array(
        'label' => array(
          'format' => 'inline',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'email',
        'parent_id' => '',
        'field_id' => 'field_email',
        'label_value' => 'Email',
      ),
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'email',
        'parent_id' => '',
        'field_id' => 'field_email',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-98',
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
    'type' => 'email',
    'required' => '0',
    'multiple' => '0',
    'module' => 'email',
    'active' => '1',
    'widget' => array(
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'email' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Email',
      'weight' => '11',
      'description' => '',
      'type' => 'email_textfield',
      'module' => 'email',
    ),
  );

  // Exported field: field_fax
  $fields['location-field_fax'] = array(
    'field_name' => 'field_fax',
    'type_name' => 'location',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-97',
      'teaser' => array(
        'label' => array(
          'format' => 'inline',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_fax',
        'label_value' => 'Fax',
      ),
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_fax',
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
        'css-class' => '',
        'weight' => '-97',
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
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
          '_error_element' => 'default_value_widget][field_fax][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Fax',
      'weight' => '13',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_lat
  $fields['location-field_lat'] = array(
    'field_name' => 'field_lat',
    'type_name' => 'location',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-65',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'disabled',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_lat',
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
        'weight' => '-65',
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
          '_error_element' => 'default_value_widget][field_lat][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Latitude',
      'weight' => '47',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_link
  $fields['location-field_link'] = array(
    'field_name' => 'field_link',
    'type_name' => 'location',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-96',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'link',
        'parent_id' => '',
        'field_id' => 'field_link',
        'label_value' => '',
      ),
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
        'weight' => '-96',
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
      'weight' => '14',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_lon
  $fields['location-field_lon'] = array(
    'field_name' => 'field_lon',
    'type_name' => 'location',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-68',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'disabled',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_lon',
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
        'weight' => '-68',
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
          '_error_element' => 'default_value_widget][field_lon][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Longitude',
      'weight' => '48',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_phone
  $fields['location-field_phone'] = array(
    'field_name' => 'field_phone',
    'type_name' => 'location',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-98',
      'teaser' => array(
        'label' => array(
          'format' => 'inline',
        ),
        'format' => 'default',
        'css-class' => array(),
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_phone',
        'label_value' => 'Phone',
      ),
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_phone',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-99',
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
        'weight' => '-98',
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
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
          '_error_element' => 'default_value_widget][field_phone][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Phone',
      'weight' => '12',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_postcode
  $fields['location-field_postcode'] = array(
    'field_name' => 'field_postcode',
    'type_name' => 'location',
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
      'weight' => '45',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_province
  $fields['location-field_province'] = array(
    'field_name' => 'field_province',
    'type_name' => 'location',
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
      'weight' => '44',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_thumbnail
  $fields['location-field_thumbnail'] = array(
    'field_name' => 'field_thumbnail',
    'type_name' => 'location',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => array(),
      'region' => 'disabled',
      'ds_weight' => '-100',
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
      'weight' => '-4',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_wkt
  $fields['location-field_wkt'] = array(
    'field_name' => 'field_wkt',
    'type_name' => 'location',
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
      'weight' => '49',
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
  t('Email');
  t('Fax');
  t('Latitude');
  t('Link');
  t('Longitude');
  t('Phone');
  t('Post code');
  t('Province');
  t('Thumbnail');
  t('WKT');

  return $fields;
}
