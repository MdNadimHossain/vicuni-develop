<?php

/**
 * @file
 * Menu module integration.
 */

/**
 * Implements hook_block_view_alter().
 */
function menu_vu_core_block_menu_footer_view_alter(&$data, $block) {
  if (empty($data['content'])) {
    menu_tree_set_path('menu-footer', 'homepage');
    drupal_static_reset('menu_tree');
    drupal_static_reset('menu_get_item');
    $data['content'] = menu_tree('menu-footer');
  }
}

/**
 * Implements hook_permission_alter().
 */
function menu_vu_core_permission_alter(&$permissions) {
  $permissions['delete menu item'] = [
    'title' => t('Allow user to delete menu items.'),
  ];
}

/**
 * Implements hook_vu_core_form_alter().
 */
function menu_vu_core_form_alter(&$form, &$form_state, $form_id) {
  // Remove delete link and button for users without permission.
  // see @PW-5175.
  if ($form_id == 'menu_overview_form') {
    $user_access = user_access('delete menu item');

    if ($user_access === FALSE) {
      foreach ($form as &$item) {
        if (isset($item['operations']['delete'])) {
          unset($item['operations']['delete']);
        }
      }
    }
  }

  if ($form_id == 'menu_edit_item') {
    $user_access = user_access('delete menu item');
    if ($user_access === FALSE) {
      if (isset($form['actions']['delete'])) {
        unset($form['actions']['delete']);
      }
    }
  }
}
