<?php
/**
 * @file
 * vu_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function vu_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer',
    'description' => '',
  );
  // Exported menu: menu-footer-useful-links.
  $menus['menu-footer-useful-links'] = array(
    'menu_name' => 'menu-footer-useful-links',
    'title' => 'Footer Useful Links',
    'description' => 'Useful links placed in the footer',
  );
  // Exported menu: menu-header-area.
  $menus['menu-header-area'] = array(
    'menu_name' => 'menu-header-area',
    'title' => 'Header area',
    'description' => '',
  );
  // Exported menu: menu-subsites.
  $menus['menu-subsites'] = array(
    'menu_name' => 'menu-subsites',
    'title' => 'Subsites',
    'description' => 'VU subsites including "VU in your country" sites.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer');
  t('Footer Useful Links');
  t('Header area');
  t('Main menu');
  t('Subsites');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('Useful links placed in the footer');
  t('VU subsites including "VU in your country" sites.');

  return $menus;
}
