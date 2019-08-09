<?php

/**
 * @file
 * PW-4269 - Update subsite links.
 */

use Drupal\drupal_helpers\Menu;

$links = [
  'Convention Centres',
  'Menus',
  'Room hire & layout',
  'Sir Zelman Cowen Centre',
  'About SZCC',
  'Community & school legal programs',
  'Aspire: Young Muslim Womens\' Governance & Leadership program',
  'School holiday sports programs',
  'Junior Programs',
  'High performance youth training',
  'About our programs',
  'Footscray University Town',
  'Facts',
  'Australian Health Policy Collaboration',
];

foreach ($links as $link) {
  Menu::updateItem('menu-subsites', ['link_title' => $link], ['expanded' => 1]);
}
