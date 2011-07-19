<?php
// $Id: simple_access.theme.inc,v 1.1.2.2 2009/01/08 13:02:50 gordon Exp $
/**
 * @file
 * Provide themes for simple access administration
 */

function theme_simple_access_form($form) {
  drupal_add_css(drupal_get_path('module', 'simple_access') .'/simple_access.css');

  $output = '';
  if (isset($form['#admin'])) {
    $variable = array('view' => 1, 'update' => 1, 'delete' => 1);
  }
  else {
    $variable = variable_get('sa_display', array('view' => 1));
  }
  $head = array(t('Access Group'));
  if ((isset($variable['view']) && $variable['view']) || isset($form['#admin'])) {
    $head[] = t('View');
  }
  if ((isset($variable['update']) && $variable['update']) || isset($form['#admin'])) {
    $head[] = t('Update');
  }
  if ((isset($variable['delete']) && $variable['delete']) || isset($form['#admin'])) {
    $head[] = t('Delete');
  }

  foreach (element_children($form) as $gid) {
    if (!isset($form['#access']) || $form['#access']) {
      $row = array(
        array('data' => drupal_render($form[$gid]['name'])),
      );
      if ((isset($variable['view']) && $variable['view']) || isset($form['#admin'])) {
        $row[] = array(
          'data' => drupal_render($form[$gid]['sa_view']),
        );
      }
      if ((isset($variable['update']) && $variable['update']) || isset($form['#admin'])) {
        $row[] = array(
          'data' => drupal_render($form[$gid]['sa_update']),
        );
      }
      if ((isset($variable['delete']) && $variable['delete']) || isset($form['#admin'])) {
        $row[] = array(
          'data' => drupal_render($form[$gid]['sa_delete']),
        );
      }

      $rows[] = $row;
    }
  }

  if (!empty($rows)) {
    $output .= theme('table', $head, $rows);
    $output .= drupal_render($form);
    return $output;
  }
}

function theme_simple_access_page_overview($form) {
  drupal_add_tabledrag('sa-group-list', 'order', 'sibling', 'sa-group-weight');
  $header = array(t('Group'), t('Roles'), t('Weight'), t('Operations'));
  foreach (element_children($form['groups']) as $gid) {
    $rows[] = array(
      'data' => array(
        drupal_render($form['groups'][$gid]['name']),
        array('data' => drupal_render($form['groups'][$gid]['roles']), 'class' => 'sa-group-roles'),
        drupal_render($form['groups'][$gid]['weight']),
        drupal_render($form['groups'][$gid]['ops']),
      ),
      'class' => 'draggable',
    );
  }
  $output .= theme('table', $header, $rows, array('id' => 'sa-group-list'));
  $output .= drupal_render($form); 

  return $output;
}

function theme_simple_access_profile_list($form) {
  drupal_add_tabledrag('sa-profile-list', 'order', 'sibling', 'sa-profile-weight');
  $head = array(t('Name'), t('Weight'), t('Operations'));
  $rows = array();

  foreach (element_children($form['profiles']) as $id) {
    $rows[] = array(
      'data' => array(
        array('data' => drupal_render($form['profiles'][$id]['name'])),
        array('data' => drupal_render($form['profiles'][$id]['weight'])),
        array('data' => drupal_render($form['profiles'][$id]['operations'])),
      ),
      'class' => 'draggable',
    );
  }

  if (empty($rows)) {
    $rows[] = array(
      array(
        'data' => t('No profiles defined'),
        'colspan' => 3,
        'align' => 'center',
      ),
    );
  }
  $output .= theme('table', $head, $rows, array('id' => 'sa-profile-list'));
  $output .= drupal_render($form);

  return $output;
}


