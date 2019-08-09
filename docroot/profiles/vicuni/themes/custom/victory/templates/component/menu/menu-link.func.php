<?php

/**
 * @file
 * Theme implementations for menu_link hook.
 */

/**
 * Overrides theme_menu_link().
 */
function victory_menu_link__menu_block($variables) {
  // By default, Bootstrap theme converts all menu items that have children
  // into drop-downs. This implementation overrides this behaviour for all menus
  // rendered within menu blocks. Such menus could have their links rendered as
  // drop-downs by copying some of  the functionality from 'bootstrap_menu_link'
  // function. Note, that adding 'bootstrap_menu_link' to the '#theme' array of
  // the menu item will not work for menus starting at depth greater then 1 as
  // 'bootstrap_menu_link' has hardcoded filtering by depth.
  // @see bootstrap_menu_link()
  // @codingStandardsIgnoreStart DrupalPractice.FunctionCalls.Theme.ThemeFunctionDirect
  return theme_menu_link($variables);
  // @codingStandardsIgnoreEnd
}
