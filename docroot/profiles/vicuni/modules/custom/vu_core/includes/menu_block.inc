<?php

/**
 * @file
 * Menu block module integration.
 */

use Drupal\drupal_helpers\Menu;

/**
 * Implements hook_menu_block_blocks().
 */
function vu_core_menu_block_blocks() {
  // These menu block configuration cannot be exported with features as their
  // 'parent_mlid' values are created dynamically.
  return [
    // Using 'col1' suffix to explicitly specify that this is an index-based
    // rather then mlid-based menu block.
    'footer-useful-links-col1' => [
      'menu_name' => 'menu-footer-useful-links',
      'parent_mlid' => _vu_core_get_menu_mlid_by_index('menu-footer-useful-links', 0),
      'title_link' => FALSE,
      'admin_title' => 'Footer Useful Links menu Future Students',
      'level' => 1,
      'follow' => 0,
      'depth' => 0,
      'expanded' => TRUE,
      'sort' => FALSE,
    ],
    // Using 'col2' suffix to explicitly specify that this is an index-based
    // rather then mlid-based menu block.
    'footer-useful-links-col2' => [
      'menu_name' => 'menu-footer-useful-links',
      'parent_mlid' => _vu_core_get_menu_mlid_by_index('menu-footer-useful-links', 1),
      'title_link' => FALSE,
      'admin_title' => 'Footer Useful Links menu Students and Staff',
      'level' => 1,
      'follow' => 0,
      'depth' => 0,
      'expanded' => TRUE,
      'sort' => FALSE,
    ],
    'footer-main-menu-tools' => [
      'menu_name' => 'main-menu',
      'parent_mlid' => Menu::findItem('main-menu', ['link_title' => 'Login']),
      'title_link' => FALSE,
      'admin_title' => 'Footer Main Menu Tools',
      'level' => 1,
      'follow' => 0,
      'depth' => 0,
      'expanded' => TRUE,
      'sort' => FALSE,
    ],
    'main-menu-level1' => [
      'menu_name' => 'main-menu',
      'parent_mlid' => 0,
      'title_link' => FALSE,
      'admin_title' => 'Main Menu Level 1',
      'level' => 1,
      'follow' => 0,
      'depth' => 1,
      'expanded' => TRUE,
      'sort' => FALSE,
    ],
    'main-menu-level2' => [
      'menu_name' => 'main-menu',
      'parent_mlid' => 0,
      'title_link' => FALSE,
      'admin_title' => 'Main Menu Level 2',
      'level' => 2,
      'follow' => 0,
      'depth' => 4,
      'expanded' => FALSE,
      'sort' => FALSE,
    ],
    'main-menu-tools' => [
      'menu_name' => 'main-menu',
      'parent_mlid' => Menu::findItem('main-menu', ['link_title' => 'Login']),
      'title_link' => FALSE,
      'admin_title' => 'Main menu::Tools',
      'level' => 1,
      'follow' => 0,
      'depth' => 0,
      'expanded' => TRUE,
      'sort' => FALSE,
    ],
    'main-menu-left-nav' => [
      'menu_name' => 'main-menu',
      'parent_mlid' => 0,
      'title_link' => FALSE,
      'admin_title' => 'Main Menu: Left Navigation',
      'level' => 2,
      'follow' => 0,
      'depth' => 0,
      'expanded' => TRUE,
      'sort' => FALSE,
    ],
    'main-menu-our-campuses' => [
      'menu_name' => 'main-menu',
      'parent_mlid' => 0,
      'title_link' => 'Our Campuses',
      'admin_title' => 'Main Menu: Our Campuses',
      'level' => 2,
      'follow' => 0,
      'depth' => 1,
      'expanded' => TRUE,
      'sort' => FALSE,
    ],
    'menu-subsites-left-nav' => [
      'menu_name' => 'menu-subsites',
      'parent_mlid' => 0,
      'title_link' => FALSE,
      'admin_title' => 'Menu subsites: Left Navigation',
      'level' => 2,
      'follow' => 0,
      'depth' => 0,
      'expanded' => TRUE,
      'sort' => FALSE,
    ],
    'main-menu-child-page-nav' => [
      'menu_name' => 'main-menu',
      'parent_mlid' => 0,
      'title_link' => TRUE,
      'admin_title' => 'Main Menu: Child Page Navigation',
      'level' => 1,
      'follow' => 'child',
      'depth' => 1,
      'depth_relative' => 1,
      'expanded' => FALSE,
      'sort' => FALSE,
    ],
    'menu-subsites-level2' => [
      'menu_name' => 'menu-subsites',
      'parent_mlid' => 0,
      'title_link' => FALSE,
      'admin_title' => 'Menu subsites: Level 2',
      'level' => 2,
      'follow' => 0,
      'depth' => 4,
      'expanded' => FALSE,
      'sort' => FALSE,
    ],
    'menu-subsites-child-page-nav' => [
      'menu_name' => 'menu-subsites',
      'parent_mlid' => 0,
      'title_link' => TRUE,
      'admin_title' => 'Menu subsites: Child Page Navigation',
      'level' => 1,
      'follow' => 'child',
      'depth' => 1,
      'depth_relative' => 1,
      'expanded' => FALSE,
      'sort' => FALSE,
    ],
  ];
}

/**
 * Get menu item mlid by index.
 *
 * @param string $menu_name
 *   Menu machine name.
 * @param int $index
 *   Number of menu item in the items list.
 *
 * @return int|bool
 *   Menu item mlid or FALSE if invalid $index specified.
 */
function _vu_core_get_menu_mlid_by_index($menu_name, $index) {
  $links = menu_tree_all_data($menu_name, NULL, 1);
  if ($index >= count($links)) {
    return FALSE;
  }
  $item = array_slice(array_values($links), $index, 1);
  $item = reset($item);

  return $item['link']['mlid'];
}

/**
 * Implements hook_core_menu_block_tree_alter().
 */
function vu_core_menu_block_tree_alter(&$tree, &$config) {

  if ($config['delta'] == "main-menu-level1" && vu_core_is_subsite()) {
    _vu_core_menu_block_process_subsite_main_menu($tree);
  }

  // Secondary navigation.
  if ($config['delta'] == 'main-menu-level2' || $config['delta'] == 'menu-subsites-level2') {
    _vu_core_menu_block_process_expanded($tree);
  }

  // Main menu left navigation.
  if ($config['delta'] == 'main-menu-left-nav') {
    // Alter starting level for menu shown on pages that are children of VUHome.
    if (_vu_core_active_trail_has_root_parent('main-menu', ['link_title' => 'VU Home'])) {
      $config['level'] = 3;
    }

    _vu_core_menu_block_process_expanded($tree);
    _vu_core_menu_block_remove_non_active_trail($tree, $config['level']);
  }

  // Subsites left navigation.
  if ($config['delta'] == 'menu-subsites-left-nav') {
    _vu_core_menu_block_remove_non_active_trail($tree, $config['level']);
  }
}

/**
 * Alter subsite's main menu.
 */
function _vu_core_menu_block_process_subsite_main_menu(&$tree) {
  // Items to preserve. @TODO need to find a better way to maintain this.
  $preserve = [
    'VU Home' => 'VU Home',
    'Contact us' => 'Contact us',
    '<separator>' => '<separator>',
    'Search' => 'Search',
    'Login' => 'Login',
  ];

  // Values to hide.
  $hide = [
    'Contact us' => 'hide_contact',
    'Search' => 'hide_search',
    'Login' => 'hide_login',
  ];

  // Unset items.
  $subsite_node = vu_core_subsite_node_get();
  $subsite_metadata = vu_core_subsite_meta_get($subsite_node);

  // Add updated contact us title if any.
  if (!empty($subsite_metadata->contact_us_title)) {
    $preserve[$subsite_metadata->contact_us_title] = $subsite_metadata->contact_us_title;
  }

  if ($subsite_metadata) {
    foreach ($subsite_metadata as $item => $value) {
      if (in_array($item, $hide)) {
        if ($subsite_metadata->{$item} == TRUE) {
          unset($preserve[array_search($item, $hide)]);
        }
      }
    }
  }

  // Only alter on new theme.
  global $theme;
  if ($theme != 'victory') {
    return;
  }

  foreach ($tree as $key => &$item) {
    if ($item['link']['menu_name'] != 'main-menu' && $item['link']['depth'] != '1') {
      return;
    }

    if (!in_array($item['link']['link_title'], $preserve)) {
      unset($tree[$key]);
    }
  }

  // Add subsite to main menu.
  $mlid = vu_core_get_mlid();
  if ($mlid) {
    $menu_item = menu_link_load($mlid);
    if (!empty($menu_item)) {
      $menu_item['localized_options']['attributes']['class'][] = 'active';
      $menu_item['localized_options']['item_attributes']['class'] = 'active-trail';
      $menu_item['in_active_trail'] = FALSE;
      $subsite_root = [
        $menu_item['link_title'] . ' ' . $menu_item['mlid'] => [
          'link' => $menu_item,
          'below' => FALSE,
        ],
      ];

      array_splice($tree, 1, 0, $subsite_root);
    }
  }
}

/**
 * Recursively remove children for not expanded parents.
 *
 * @param array $tree
 *   Menu tree passed by reference.
 */
function _vu_core_menu_block_process_expanded(&$tree) {
  foreach ($tree as &$item) {
    // Only process items that have children.
    if (isset($item['below']) && count($item['below']) > 0) {
      // Drill down expanded sub-tree.
      if ($item['link']['expanded']) {
        // Do not show more than 4 elements in the secondary menu.
        // @TODO remove when child pages have been fixed.
        if ($item['link']['menu_name'] == "menu-subsites" && $item['link']['depth'] == 1) {
          $item['below'] = array_slice($item['below'], 0, 4, TRUE);
        }
        _vu_core_menu_block_process_expanded($item['below']);
      }
      else {
        // Remove children from not expanded parents.
        $item['below'] = FALSE;
        // Remove styling that shows there were children.
        if ($item['link']['has_children']) {
          $item['link']['has_children'] = FALSE;
          $item['link']['leaf_has_children'] = TRUE;
        }
      }
    }
  }
}

/**
 * Recursively remove non-active trail items.
 *
 * @param array $tree
 *   Menu tree to process.
 * @param int $non_active_trail_max_depth
 *   Maximum depth of non-active trail items to preserve. This allows to cut
 *   the tree "from the bottom", while standard menu_block behaviour will cut
 *   the tree "from the top" if starting level is set in config.
 * @param bool $on_active_trail
 *   Internal parameter to track whether current tree branch is a part of the
 *   active trail. This is used to expand all children of the item in the
 *   active trail.
 */
function _vu_core_menu_block_remove_non_active_trail(&$tree, $non_active_trail_max_depth = 0, $on_active_trail = FALSE) {
  if (!is_array($tree)) {
    return;
  }
  foreach ($tree as $key => &$item) {
    // Remove all item that are not in active trail, but only if they are
    // deeper then specified max depth and we are not currently on active trail.
    if (!$tree[$key]['link']['in_active_trail'] && $tree[$key]['link']['depth'] > $non_active_trail_max_depth && !$on_active_trail) {
      unset($tree[$key]);
      continue;
    }

    if (isset($item['below']) && count($item['below']) > 0) {
      _vu_core_menu_block_remove_non_active_trail($item['below'], $non_active_trail_max_depth, $tree[$key]['link']['in_active_trail']);

      // If all children were removed, remove styling that shows there were
      // children.
      if (count($item['below']) == 0 && $item['link']['has_children']) {
        $item['below'] = FALSE;
        $item['link']['has_children'] = FALSE;
        $item['link']['leaf_has_children'] = TRUE;
      }
    }
  }
}

/**
 * Check that active trail has a parent root item with specified criteria.
 *
 * @param string $menu_name
 *   Menu machine name.
 * @param array $menu_item
 *   Menu item fields to lookup.
 *
 * @return bool
 *   TRUE if item with specified criteria was found, FALSE otherwise.
 */
function _vu_core_active_trail_has_root_parent($menu_name, $menu_item) {
  // Alter starting level for menu shown on pages that are children of VUHome.
  $active_trail = menu_get_active_trail();
  if (isset($active_trail[1])) {
    $mlid = Menu::findItem($menu_name, $menu_item);
    if ($mlid) {
      if ($active_trail[1]['mlid'] == $mlid) {
        return TRUE;
      }
    }
    else {
      watchdog('vu_core', 'Unable to find menu item for active trail processing', WATCHDOG_WARNING);
    }
  }

  return FALSE;
}

/**
 * Get root mlid.
 */
function vu_core_get_mlid() {
  $mlid = FALSE;

  $active_trail = menu_get_active_trail();
  if (!empty($active_trail)) {
    if (isset($active_trail[1])) {
      $menu_item = $active_trail[1];
      $mlid = !empty($menu_item['plid']) ? $menu_item['plid'] : $menu_item['mlid'];
    }
  }

  return $mlid;
}
