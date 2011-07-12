<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function accuray_locations_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'locations_2';
  $feeds_importer->config = array(
    'name' => 'Locations 2',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'SiteName',
          'xpathparser:1' => '',
          'xpathparser:2' => 'isActive',
          'xpathparser:3' => 'WebSiteURL',
          'xpathparser:4' => 'CyberKnifeSiteGUID',
          'xpathparser:5' => 'Phone_Main',
          'xpathparser:6' => 'Phone_Fax',
          'xpathparser:7' => 'Email',
          'xpathparser:8' => 'PhotoURL_Facility',
          'xpathparser:9' => 'WebSiteURL',
          'xpathparser:10' => 'SiteName',
          'xpathparser:11' => 'AddressLine1',
          'xpathparser:12' => 'AddressLine2',
          'xpathparser:13' => 'AddressLine3',
          'xpathparser:14' => 'City',
          'xpathparser:15' => 'State',
          'xpathparser:16' => 'ZipCode',
          'xpathparser:17' => 'Country',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
        ),
        'context' => '//rows/sites/CKSite',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'location',
        'input_format' => '0',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'status',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'url',
            'unique' => 0,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_phone',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_fax',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_thumbnail',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_link:url',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_link:title',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_address_1',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_address_2',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_address_3',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_city',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_province',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_postcode',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_country',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
  );

  $export['locations_2'] = $feeds_importer;
  return $export;
}
