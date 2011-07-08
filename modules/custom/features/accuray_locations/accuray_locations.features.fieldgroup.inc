<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function accuray_locations_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_contact
  $groups['location-group_contact'] = array(
    'group_type' => 'standard',
    'type_name' => 'location',
    'group_name' => 'group_contact',
    'parent' => '',
    'label' => 'Contact',
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
        'sticky' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '7',
    'fields' => array(
      '0' => 'field_email',
      '1' => 'field_phone',
      '2' => 'field_fax',
      '3' => 'field_link',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');

  return $groups;
}
