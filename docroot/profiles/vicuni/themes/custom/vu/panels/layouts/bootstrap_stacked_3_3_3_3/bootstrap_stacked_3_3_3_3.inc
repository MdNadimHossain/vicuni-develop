<?php

/**
 * @file
 * Bootstrap - Stacked - 3 3 3 3 panels layout plugin definition.
 */

/**
 * Implements hook_panels_layouts().
 */
$plugin = [
  'title' => t('Bootstrap - Stacked - 3 3 3 3'),
  'category' => t('VicUni'),
  'icon' => 'bootstrap_stacked_3_3_3_3.png',
  'theme' => 'panels_bootstrap_stacked_3_3_3_3',
  'admin css' => 'bootstrap_stacked_3_3_3_3-admin.css',
  'regions' => [
    'top' => t('Top'),
    'middle_1' => t('Middle - 1'),
    'middle_2' => t('Middle - 2'),
    'middle_3' => t('Middle - 3'),
    'middle_4' => t('Middle - 4'),
    'bottom' => t('Bottom'),
  ],
];
