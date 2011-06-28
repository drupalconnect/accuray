<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function accuray_locations_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'locations';
  $openlayers_presets->title = 'Locations';
  $openlayers_presets->description = 'This is the default map preset that comes with the OpenLayers module.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'http://js.mapbox.com/theme/dark/',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'Locations_openlayers_1' => 'Locations_openlayers_1',
        ),
      ),
      'openlayers_behavior_tooltip' => array(
        'layers' => array(
          'Locations_openlayers_1' => 'Locations_openlayers_1',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'Locations_openlayers_1',
        'point_zoom_level' => '5',
      ),
      'openlayers_behavior_cluster' => array(
        'clusterlayer' => array(
          'Locations_openlayers_1' => 'Locations_openlayers_1',
        ),
        'distance' => '20',
        'threshold' => '',
      ),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'Locations_openlayers_1' => 'Locations_openlayers_1',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'Locations_openlayers_1' => 'Locations_openlayers_1',
    ),
    'layer_switcher' => array(
      'Locations_openlayers_1' => 'Locations_openlayers_1',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );

  $export['locations'] = $openlayers_presets;
  return $export;
}
