<?php

/**
 * @file
 * Theme implementations for menu_tree hook.
 */

/**
 * Theme wrapper function for footer Useful Links menu.
 */
function vu_menu_tree__menu_block__menu_footer_useful_links(&$variables) {
  return '<strong><p>Information for:</p></strong><ul class="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Theme wrapper function for footer Main Menu Tools menu.
 */
function vu_menu_tree__menu_block__footer_main_menu_tools(&$variables) {
  return '<strong><p>Tools:</p></strong><ul class="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Theme wrapper function for footer menu.
 */
function vu_menu_tree__menu_footer(&$variables) {
  return '<ul class="menu menu-footer">' . $variables['tree'] . '</ul>';
}

/**
 * Theme wrapper function for Main Menu menu rendered in menu block at depth 2.
 */
function vu_menu_tree__menu_block__main_menu_level2(&$variables) {
  return '<div class="menu-wrapper"><ul class="menu main-menu">' . $variables['tree'] . '</ul></div>';
}

/**
 * Theme wrapper function for Left Nav menu.
 */
function vu_menu_tree__menu_block__main_menu_left_nav(&$variables) {
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}
