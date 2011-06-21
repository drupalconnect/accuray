<?php
// $Id: domaincontext_context_condition_domain.inc,v 1.1.2.1 2010/08/28 19:29:38 xjm Exp $

/**
 * @file
 * Context plugin to supply the domain as a context condition.
 */

/**
 * Expose domains as a context condition.
 */
class domaincontext_context_condition_domain extends context_condition {
  function condition_values() {
    $values = array();
    $format = domain_select_format();
    foreach (domain_domains() as $data) {
      ($data['domain_id'] == 0) ? $key = -1 : $key = $data['domain_id'];
      if ($data['valid'] || user_access('access inactive domains')) {
        $values[$key] = empty($format) ? check_plain($data['sitename']) : $data['sitename'];
      }
    }
    return $values;
  }

  function execute() {
    global $_domain;
    $domain_id = $_domain['domain_id'];
    if ($domain_id == 0) {
      $domain_id = -1;
    }
    $this->values[$domain_id] = array();
    $contexts = $this->get_contexts($domain_id);
    foreach ($contexts as $context) {
      $this->values[$domain_id][] = $context->name;
      $this->condition_met($context, $domain_id);
    }
  }
}
