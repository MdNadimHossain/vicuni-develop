<?php

/**
 * @file
 * PW-4834 - Add custom menu item.
 */

use Drupal\drupal_helpers\Menu;

$plid = Menu::findItem('main-menu', ['link_path' => 'research']);
if (!$plid) {
  throw new UpdaterException('Unable to find required parent menu item.');
}

Menu::addItem('main-menu', [
  'link_path' => 'research/find-researcher',
  'link_title' => 'Find a researcher',
  'plid' => $plid,
  'module' => 'menu',
]);
