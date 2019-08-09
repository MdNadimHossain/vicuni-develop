<?php

/**
 * @file
 * Theme implementations for menu_tree hook.
 */

/**
 * Theme wrapper function for footer Useful Links menu.
 */
function victory_menu_tree__menu_block__menu_footer_useful_links(&$variables) {
  return '<strong><p>Information for:</p></strong><ul class="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Theme wrapper function for footer Main Menu Tools menu.
 */
function victory_menu_tree__menu_block__footer_main_menu_tools(&$variables) {
  return '<strong><p>Tools:</p></strong><ul class="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Theme wrapper function for footer menu.
 */
function victory_menu_tree__menu_footer(&$variables) {
  return '<ul class="menu menu-footer">' . $variables['tree'] . '</ul>';
}

/**
 * Theme wrapper function for Main Menu menu rendered in menu block at depth 2.
 */
function victory_menu_tree__menu_block__main_menu_level2(&$variables) {
  return '<div class="menu-wrapper"><ul class="menu main-menu">' . $variables['tree'] . '</ul></div>';
}

/**
 * Theme wrapper function for Main Menu menu rendered in menu block at depth 2.
 */
function victory_menu_tree__menu_block__menu_subsites_level2(&$variables) {
  return '<div class="menu-wrapper"><ul class="menu main-menu">' . $variables['tree'] . '</ul></div>';
}

/**
 * Theme wrapper function for Tools Menu menu rendered in menu block.
 */
function victory_menu_tree__menu_block__main_menu_tools(&$variables) {
  return '<ul class="menu main-tools">' . $variables['tree'] . '</ul>';
}
