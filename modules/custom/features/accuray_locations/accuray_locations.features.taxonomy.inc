<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function accuray_locations_taxonomy_default_vocabularies() {
  return array(
    'region' => array(
      'name' => 'Region',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_region',
      'weight' => '0',
      'language' => '',
      'type' => NULL,
      'nodes' => array(),
    ),
  );
}
