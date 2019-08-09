<?php

/**
 * @file
 * Raw panels layout plugin definition.
 */

/**
 * Implements hook_panels_layouts().
 */
$plugin = [
  'title'    => t('Raw'),
  'category' => t('VicUni'),
  'icon'     => 'raw.png',
  'theme'    => 'panels_raw',
  'regions'  => ['middle' => t('Content')],
];
