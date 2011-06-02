<?php
// $Id: context_geoip_condition.inc,v 1.1 2010/11/17 23:57:28 introfini Exp $

/**
 * User's Geo IP as a Context condition.
 */
class context_geoip_condition extends context_condition {
  
  function condition_values() {
    $values = array();
    foreach (geoip_country_values() as $country_code => $country_name) {
        $values[$country_code] = $country_name;
    }
    return $values;
  }

  function execute() {  
    if ($this->condition_used()) {
      $user_country_code = geoip_country_code();
      foreach ($this->get_contexts() as $context) {
        $country_codes = $this->fetch_from_context($context, 'values');
        if (in_array($user_country_code, $country_codes)) {
          $this->condition_met($context);
        }
      }
    }
  }
 }