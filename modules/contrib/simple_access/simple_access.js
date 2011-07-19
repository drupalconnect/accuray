Drupal.verticalTabs = Drupal.verticalTabs || {};

Drupal.verticalTabs.sa = function() {
  if (!$('.vertical-tabs-sa .form-checkbox:checked').size()) {
    return Drupal.t('No access set');
  }
  else {
    return Drupal.t('Restricted access');
  }
}

Drupal.verticalTabs.simple_access = function() {
  if (!$('.vertical-tabs-simple_access .form-checkbox:checked').size()) {
    return Drupal.t('No access set');
  }
  else {
    return Drupal.t('Restricted access');
  }
}