<?php

/**
 * @file
 * Display Suite module integration.
 */

/**
 * Implements hook_ds_layout_info().
 */
function vu_rp_ds_layout_info() {
  $path = drupal_get_path('module', 'vu_rp') . '/includes/layouts';
  $layouts['vu_rp'] = [
    'label' => t('VU: Research profile'),
    'path' => $path . '/vu_rp',
    'regions' => [
      'overview_key_details' => t('Overview key details'),
      'overview_right' => t('Overview right'),
      'overview_about' => t('Overview about'),
      'overview_middle_right' => t('Overview middle right'),
      'overview_qualifications' => t('Overview qualifications'),
      'publications' => t('Publications'),
      'funding' => t('Funding'),
      'funding_right' => t('Funding right'),
      'funding_bottom' => t('Funding bottom'),
      'supervising_left' => t('Supervision left'),
      'supervising_right' => t('Supervision right'),
      'supervising_middle' => t('Supervision middle'),
      'supervising_bottom' => t('Supervision bottom'),
      'career' => t('Career'),
    ],
  ];

  return $layouts;
}
