<?php

/**
 * @file
 * Pathauto module integration.
 */

/**
 * Implements hook_pathauto().
 */
function vu_core_pathauto($op) {
  switch ($op) {
    case 'settings':
      $settings = [];
      $settings['module'] = 'vu_core';
      $settings['token_type'] = 'node';
      $settings['groupheader'] = t('VU IA Structure: Menu Paths');
      $settings['patterndescr'] = t('Default path pattern for VU IA in the main-menu (applies to all menu types with blank patterns below)');
      $settings['patterndefault'] = '';

      $menus = menu_get_menus();
      // System menus we want to ignore.
      $admin_module_menus = ['devel', 'features', 'user-menu', 'management'];

      foreach ($admin_module_menus as $admin_module_menu) {
        if ($menus[$admin_module_menu]) {
          unset($menus[$admin_module_menu]);
        }
      }

      foreach ($menus as $menu_name => $menu) {
        $settings['patternitems'][$menu_name] = t('Pattern for all @menu_name paths', ['@menu_name' => $menu_name]);
      }

      return (object) $settings;
  }
}

/**
 * Implements hook_pathauto_pattern_alter().
 */
function vu_core_pathauto_pattern_alter(&$pattern, array &$context) {
  // If the entity has a menu item assigned update the pattern based on the
  // menu.
  $data = $context['data'];
  if (isset($data['node'])) {
    // When processed by node_pathauto the $data doesn't contain a menu
    // property. We need to look up the menu so that we can check it's menu
    // state.
    $menu_item = menu_node_get_links($data['node']->nid);

    if ($menu_item) {
      $menu_key = array_keys($menu_item);
      // If the pattern is set for this menu use it, otherwise use the default
      // content pattern.
      $default_pattern = $pattern;
      $pattern = variable_get('pathauto_vu_core_' . $menu_item[$menu_key[0]]->menu_name . '_pattern', $pattern);

      if (empty($pattern)) {
        $pattern = $default_pattern;
      }
    }
    // If there's no menu item found and it's the menu alias pattern
    // or if it's empty, use node:title.
    if (!$menu_item && $pattern == variable_get('pathauto_vu_core_main-menu_pattern', '')) {
      $pattern = "[node:title]";
    }
  }
}
