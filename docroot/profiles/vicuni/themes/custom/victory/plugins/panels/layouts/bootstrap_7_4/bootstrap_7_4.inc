<?php

/**
 * @file
 * Bootstrap 7/4 panels layout plugin definition.
 */

/**
 * Implements hook_panels_layouts().
 */
$plugin = [
  'title' => t('Bootstrap 7/4'),
  'category' => t('Victory'),
  'icon' => 'bootstrap_7_4.png',
  'theme' => 'panels_victory_bootstrap_7_4',
  'regions' => [
    'left' => t('Left'),
    'right' => t('Right'),
  ],
];
