<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function accuray_locations_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function accuray_locations_imagecache_default_presets() {
  $items = array(
    'Thumbnail' => array(
      'presetname' => 'Thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_definecanvas',
          'data' => array(
            'RGB' => array(
              'HEX' => 'CCCCCC',
            ),
            'under' => 1,
            'exact' => array(
              'width' => '185',
              'height' => '105',
              'xpos' => 'center',
              'ypos' => 'center',
            ),
            'relative' => array(
              'leftdiff' => '',
              'rightdiff' => '',
              'topdiff' => '',
              'bottomdiff' => '',
            ),
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '184',
            'height' => '104',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function accuray_locations_node_info() {
  $items = array(
    'location' => array(
      'name' => t('Location'),
      'module' => 'features',
      'description' => '',
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
 * Implementation of hook_rules_defaults().
 */
function accuray_locations_rules_defaults() {
  return array(
    'rules' => array(
      'rules_geocode_location_addresses' => array(
        '#type' => 'rule',
        '#set' => 'event_node_presave',
        '#label' => 'Geocode location addresses',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'Geocoding',
          'accuray_locations' => 'accuray_locations',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Saved content is Location',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'location' => 'location',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'sources' => array(
                'field_address_1' => 'field_address_1',
                'field_address_3' => 'field_address_3',
                'field_address_2' => 'field_address_2',
                'field_city' => 'field_city',
                'field_province' => 'field_province',
                'field_postcode' => 'field_postcode',
                'field_country' => 'field_country',
              ),
              'destination' => 'field_wkt',
              'prefix' => '',
              'suffix' => '',
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_geocoder_action_geocode_fields',
            '#info' => array(
              'label' => 'Geocode a field or a combination of fields',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Rules Geocoder',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function accuray_locations_views_api() {
  return array(
    'api' => '3.0-alpha1',
  );
}
