<?php

/**
 * @file
 * Region-related theme hook [pre]process functions.
 */

/**
 * Implements theme_preprocess_region().
 */
function victory_preprocess_region(&$variables) {
  switch ($variables['region']) {
    // Below header region.
    case 'below_header':
      if (isset($variables['elements']['vu_core_vu_cbs_hta_apply_cta'])) {
        $variables['classes_array'][] = 'has-cta';
      }
      break;

    // Overlay region.
    case 'shutter':
      $alt_logo = [
        '#theme' => 'image',
        '#path' => drupal_get_path('theme', 'victory') . '/images/logo-white.svg',
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
      break;
  }
}
