<?php

/**
 * @file
 * Bootstrap 12 panels layout plugin definition.
 */

/**
 * Implements hook_panels_layouts().
 */
$plugin = [
  'title'    => t('Bootstrap - 12'),
  'category' => t('VicUni'),
  'icon'     => 'bootstrap_12.png',
  'theme'    => 'panels_bootstrap_12',
  'regions'  => ['middle' => t('Content')],
];
