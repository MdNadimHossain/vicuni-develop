<?php
/**
 * @file
 * vu_rp.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function vu_rp_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-researcher-profile-admin.
  $menus['menu-researcher-profile-admin'] = array(
    'menu_name' => 'menu-researcher-profile-admin',
    'title' => 'Researcher Profile Admin',
    'description' => 'Menu for Researcher Profile Admin role',
  );
  // Exported menu: menu-researcher-role.
  $menus['menu-researcher-role'] = array(
    'menu_name' => 'menu-researcher-role',
    'title' => 'Researcher',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu for Researcher Profile Admin role');
  t('Researcher');
  t('Researcher Profile Admin');

  return $menus;
}
