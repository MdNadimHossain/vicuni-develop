<?php

/**
 * @file
 * Process variables for menu-block-wrapper.tpl.php.
 *
 * @see menu-block-wrapper.tpl.php
 */

/**
 * Implements template_preprocess_menu_block_wrapper().
 */
function victory_preprocess_menu_block_wrapper(&$variables) {

  if ($variables['delta'] === 'main-menu-child-page-nav' || $variables['delta'] === 'menu-subsites-child-page-nav') {
    // Remove level 0 pages.
    foreach ($variables['content'] as $index => &$item) {
      if (isset($item['#original_link']['plid']) && $item['#original_link']['plid'] == 0) {
        unset($variables['content'][$index]);
      }
    }

    // Don't show the menu if the current page has only one child page.
    // We are counting integer keys (i.e. node ids) since $variables['content']
    // may contain other values (e.g. #theme_wrappers, #sorted, #child...etc).
    $child_nodes = count(array_filter(array_keys($variables['content']), 'is_int'));
    if ($child_nodes <= 1) {
      unset($variables['content']);
    }

    // Get node.
    $menu = menu_get_object();
    // Hide child page navigation.
    if ($variables['delta'] == 'menu-subsites-child-page-nav' && !empty($menu)) {
      $subsite_metadata = vu_core_subsite_meta_get($menu);
      if (isset($subsite_metadata->hide_child_navigation) && $subsite_metadata->hide_child_navigation == TRUE) {
        unset($variables['content']);
      }
    }

    // Adding a shorter class mainly for styling and Behat tests.
    $variables['classes_array'][] = 'child-page-nav';

    // Get depth of this node in the menu so we can
    // Add a class to the top level child navigation sections.
    $nav_block_style = vu_core_extract_single_field_value($menu, 'node', 'field_nav_block_style');
    $depth = 1;
    $links = [
      'main-menu',
      'menu-subsites',
    ];

    foreach ($menu->menu_node_links as $key => $node_link) {
      if (in_array($node_link->menu_name, $links)) {
        $depth = $menu->menu_node_links[$key]->depth;
        break;
      }
    }

    // Level 1 is a top level page.
    if (1 == $depth && $nav_block_style == '') {
      $variables['classes_array'][] = 'first-four-block';
    }

    // Level 2 is 2nd level page.
    elseif (2 == $depth && $nav_block_style == '') {
      $variables['classes_array'][] = 'full-length';
    }

    // If style is selected make it four block.
    elseif ($nav_block_style == 'Four Block') {
      $variables['classes_array'][] = 'first-four-block';
    }

    // If style is selected make it All blocks.
    elseif ($nav_block_style == 'All Blocks') {
      $variables['classes_array'][] = 'first-twelve-block';
    }

    // If style is selected make it full length.
    elseif ($nav_block_style == 'Full Length') {
      $variables['classes_array'][] = 'full-length';
    }

    // Campuses menu : level is 1.
    // or drupal_get_path_alias() == 'campuses'
    // Just for campuses page attached a 12 block style.
    elseif (drupal_get_path_alias() == 'campuses' && $nav_block_style == '') {
      $variables['classes_array'][] = 'first-twelve-block';
    }

  }

}
