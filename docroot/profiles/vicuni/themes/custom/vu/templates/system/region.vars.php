<?php

/**
 * @file
 * Region-related theme hook [pre]process functions.
 */

/**
 * Implements theme_preprocess_region().
 */
function vu_preprocess_region(&$variables) {
  // Overlay region.
  if ($variables['region'] === 'shutter') {
    $alt_logo = [
      '#theme' => 'image',
      '#path' => drupal_get_path('theme', 'vu') . '/images/logo_full_white.svg',
      '#alt' => '',
      '#title' => 'VU Home',
    ];

    $variables['alt_logo'] = [
      '#type' => 'container',
      '#attributes' => ['class' => ['logo']],
      'child' => [
        '#theme' => 'link',
        '#text' => drupal_render($alt_logo),
        '#path' => '<front>',
        '#options' => [
          'html' => TRUE,
          'attributes' => [
            'class' => ['js-shutter-close'],
          ],
        ],
      ],
    ];
  }
}
