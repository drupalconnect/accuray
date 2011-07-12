<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function accuray_events_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_location
  $groups['event-group_location'] = array(
    'group_type' => 'standard',
    'type_name' => 'event',
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
    'weight' => '9',
    'fields' => array(
      '0' => 'field_address_1',
      '1' => 'field_address_2',
      '2' => 'field_address_3',
      '3' => 'field_province',
      '4' => 'field_city',
      '5' => 'field_postcode',
      '6' => 'field_country',
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
