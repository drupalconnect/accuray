<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function accuray_marketing_toolkit_taxonomy_default_vocabularies() {
  return array(
    'marketing_toolkit' => array(
      'name' => 'Marketing toolkit',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '1',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_marketing_toolkit',
      'weight' => '0',
      'language' => '',
      'nodes' => array(
        'asset' => 'asset',
      ),
    ),
  );
}
