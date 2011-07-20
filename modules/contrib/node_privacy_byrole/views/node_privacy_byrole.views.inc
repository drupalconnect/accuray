<?php
// $Id: node_privacy_byrole.views.inc,v 1.1.2.1 2011/01/24 18:48:14 deekayen Exp $

/**
 * @file
 * Add views support to Node Privacy By Role
 *
 */

/**
 * Implementation of hook_views_data().
 */
function node_privacy_byrole_views_data() {
  $data['node_privacy_byrole']['table']['group'] = t('Node Privacy By Role');
  $data['node_privacy_byrole']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );
  $data['node_privacy_byrole']['gid'] = array(
    'title' => t('Grant ID'),
    'help' => t('Either a role ID or a user ID, the meaning depends on the realm'),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  $data['node_privacy_byrole']['uid'] = array(
    'title' => t('User'),
    'real field' => 'gid',
    'help' => t('The realm has to be filtered accordingly.'),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
  );
  $data['node_privacy_byrole']['rid'] = array(
    'title' => t('Role'),
    'real field' => 'gid',
    'help' => t('The realm has to be filtered accordingly.'),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_users_roles_rid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_roles',
    ),
  );
  $data['node_privacy_byrole']['realm'] = array(
    'title' => t('Realm'),
    'help' => t('Supply \'node_privacy_byrole_user\' or \'node_privacy_byrole_role\'.'),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  $data['node_privacy_byrole']['grant_view'] = array(
    'title' => t('View permission'),
    'help' => t('The given entitiy can view the node'),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
  );
  $data['node_privacy_byrole']['grant_update'] = array(
    'title' => t('Update permission'),
    'help' => t('The given entitiy can update the node'),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
  );
  $data['node_privacy_byrole']['grant_delete'] = array(
    'title' => t('Delete permission'),
    'help' => t('The given entitiy can delete the node'),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
  );
  return $data;
}

