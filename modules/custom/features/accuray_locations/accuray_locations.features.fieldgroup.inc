<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function accuray_locations_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_location
  $groups['location-group_location'] = array(
    'group_type' => 'standard',
    'type_name' => 'location',
    'group_name' => 'group_location',
    'parent' => '',
    'label' => 'Location',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'bubble' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '33',
    'fields' => array(
      '0' => 'field_address_1',
      '1' => 'field_address_3',
      '2' => 'field_address_2',
      '3' => 'field_city',
      '4' => 'field_province',
      '5' => 'field_postcode',
      '6' => 'field_country',
      '7' => 'field_lat',
      '8' => 'field_lon',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Location');

  return $groups;
}
