<?php

/**
 * @file
 * Display Suite Responsive 5/7 (Bootstrap) configuration.
 */

/**
 * Provides a simple two-column responsive 5/7 layout.
 */
function ds_responsive_57_bootstrap() {
  return array(
    'label' => t('Responsive 5/7 (Bootstrap)'),
    'regions' => array(
      'left' => t('Left'),
      'right' => t('Right'),
    ),
  );
}
