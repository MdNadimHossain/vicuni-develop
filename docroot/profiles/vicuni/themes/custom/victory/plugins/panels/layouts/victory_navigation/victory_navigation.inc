<?php

/**
 * @file
 * Raw panels layout plugin definition.
 */

/**
 * Implements hook_panels_layouts().
 */
$plugin = [
  'title' => t('Navigation'),
  'category' => t('Victory'),
  'icon' => 'victory_navigation.png',
  'theme' => 'panels_victory_navigation',
  'regions' => [
    'primary' => t('Primary'),
    'secondary' => t('Secondary'),
    'shutter' => t('Shutter'),
  ],
];
