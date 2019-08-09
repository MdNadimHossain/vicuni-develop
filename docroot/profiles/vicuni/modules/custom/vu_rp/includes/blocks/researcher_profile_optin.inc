<?php

/**
 * @file
 * Researcher profile opt-in/opt-out block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_rp_block_researcher_profile_optin_info() {
  return [
    'info' => t('Researcher Profile Opt-in/Opt-out'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_rp_block_researcher_profile_optin_view() {
  $form = drupal_get_form('vu_rp_optin_form');
  $variables['content'] = drupal_render($form);
  $content = theme('vu_rp_block_optin', $variables);

  return [
    'subject' => NULL,
    'content' => [
      '#markup' => $content,
    ],
  ];
}
