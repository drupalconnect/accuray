<?php
// $Id: instance_operations.inc,v 1.1.2.2 2010/01/20 04:42:49 jbrown Exp $

// Copyright 2008-2009 Jonathan Brown


function _storage_api_create_object_instance(&$container, $file) {

  $success = _storage_api_service_invoke($container['service_id'], 'object_instance_create', 
    $container, $file);
  
  if(!$success)
    return FALSE;
    
  if($success !== TRUE)
    $container['reference'] = $success;
  
  $instance = array(
    'object_id' => $file['object_id'],
    'container_id' => $container['container_id'],
    'reference' => $container['reference'],
  );

  drupal_write_record('storage_object_instance', $instance);
  
  _storage_api_flush_serving_container($file['file_id']);
  
  $message = 'Object instance created. <br />';
  $message .= _storage_api_container_log_info($container);
  $message .= _storage_api_object_log_info($file);
  
  watchdog('storage_api', $message, NULL);

  return TRUE;
}


function _storage_api_create_file_instance(&$container, $file) {

  $success = _storage_api_service_invoke($container['service_id'], 'file_instance_create', 
    $container, $file);
  
  if(!$success)
    return FALSE;
    
  if($success !== TRUE)
    $container['reference'] = $success;
  
  $instance = array(
    'file_id' => $file['file_id'],
    'container_id' => $container['container_id'],
    'reference' => $container['reference'],
  );

  drupal_write_record('storage_file_instance', $instance);
  
  _storage_api_flush_serving_container($file['file_id']);
  
  $message = 'File instance created' . ($file['filename'] ? (': ' . $file['filename'] . ' ') : '') . '. <br />';
  $message .= _storage_api_container_log_info($container);
  $message .= _storage_api_file_log_info($file);

  watchdog('storage_api', $message, NULL);

  return TRUE;
}


function _storage_api_create_instance(&$container, $file) {

  // we need write access to the directory for it to be deleted

  if(!$file['keep_me']) {
  
    if(!is_writable(dirname($file['filepath'])))
      $file['keep_me'] = TRUE;
  }
  
  $service_info = _storage_api_service_invoke($container['service_id'], 'service_info');

  if(!(!$service_info['dynamic'] && $container['serving'] && $file['force_download'])) {
    $container['type'] = 'object';

    // if the file's object is already in the system, then the instance might already exist

    if(!$file['new_object']) {
      $instance = _storage_api_object_instance_exists($file['object_id'], $container['container_id']);
      
      if($instance)
        $container['reference'] = $instance['reference'];
    }
    
    if(!$instance) {
      $failure = !_storage_api_create_object_instance($container, $file);
    }
  }
  else {
    $container['type'] = 'file';
    $failure = !_storage_api_create_file_instance($container, $file);
  }
  
  if(!$file['keep_me'])
    @unlink($file['filepath']);
    
  return !$failure;
}


function _storage_api_object_instance_copy(&$container, $file, $source_container) {

  $success = _storage_api_service_invoke($container['service_id'], 'object_instance_copy', 
    $container, $file, $source_container);
  
  if(!$success)
    return FALSE;
  
  if($success !== TRUE)
    $container['reference'] = $success;
  
  $instance = array(
    'object_id' => $file['object_id'],
    'container_id' => $container['container_id'],
    'reference' => $container['reference'],
  );

  drupal_write_record('storage_object_instance', $instance);
  
  _storage_api_flush_serving_container($file['file_id']);
  
  $message = 'Object instance copied. <br />';
  $message .= _storage_api_container_log_info($container);
  $message .= _storage_api_object_log_info($file);
  
  watchdog('storage_api', $message, NULL);

  return TRUE;
}


function _storage_api_file_instance_copy(&$container, $file, $source_container) {

  $success = _storage_api_service_invoke($container['service_id'], 'file_instance_copy', 
    $container, $file, $source_container);
  
  if(!$success)
    return FALSE;
    
  if($success !== TRUE)
    $container['reference'] = $success;
  
  $instance = array(
    'file_id' => $file['file_id'],
    'container_id' => $container['container_id'],
    'reference' => $container['reference'],
  );

  drupal_write_record('storage_file_instance', $instance);
  
  _storage_api_flush_serving_container($file['file_id']);
  
  $message = 'File instance copied' . ($file['filename'] ? (': ' . $file['filename'] . ' ') : '') . '. <br />';
  $message .= _storage_api_container_log_info($container);
  $message .= _storage_api_file_log_info($file);

  watchdog('storage_api', $message, NULL);

  return TRUE;
}


function _storage_api_object_instance_destroy($container, $file) {

  if($container['suspended'] != 0 ||
    $container['service_suspended'] != 0)
  {
    return FALSE;
  }

  $success = _storage_api_service_invoke($container['service_id'], 'object_instance_destroy', 
    $container, $file);
  
  if(!$success)
    return FALSE;

  db_query("
    DELETE FROM {storage_object_instance}
    WHERE object_id = %d
      AND container_id = %d
  ",
    $file['object_id'],
    $container['container_id']
  );
  
  $message = 'Object instance destroyed. <br />';
  $message .= _storage_api_container_log_info($container);
  $message .= _storage_api_object_log_info($file);
  
  watchdog('storage_api', $message, NULL);

  return TRUE;
}


function _storage_api_file_instance_destroy($container, $file) {

  if($container['suspended'] != 0 ||
    $container['service_suspended'] != 0)
  {
    return FALSE;
  }

  $success = _storage_api_service_invoke($container['service_id'], 'file_instance_destroy', 
    $container, $file);
    
  if(!$success)
    return FALSE;

  db_query("
    DELETE FROM {storage_file_instance}
    WHERE file_id = %d
      AND container_id = %d
  ",
    $file['file_id'],
    $container['container_id']
  );
  
  $message = 'File instance destroyed' . ($file['filename'] ? (': ' . $file['filename'] . ' ') : '') . '. <br />';
  $message .= _storage_api_container_log_info($container);
  $message .= _storage_api_file_log_info($file);

  watchdog('storage_api', $message, NULL);

  return TRUE;
}

