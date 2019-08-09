<?php

/**
 * @file
 * VU Funnelback Search block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_vu_funnelback_search_info() {
  return [
    'info' => t('VU Funnelback Search Block'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_vu_funnelback_search_view() {
  $form = drupal_get_form('vu_core_funnelback_search_form');

  // Custom overrides.
  $form['query']['#title'] = t('Search e.g. courses, units, information, people, facilities');
  $form['query']['#attributes']['placeholder'] = t('Type to search');
  $form['query']['#input_group'] = FALSE;
  $form['query']['#wrapper_attributes'] = '';
  $form['query']['#title_display'] = 'none';
  $form['query']['#input_suffix'] = t('Search e.g. courses, units, information, people, facilities');
  $form['query']['#field_suffix'] = '';
  $form['#prefix'] = '<div class="container-inline row">';
  $form['#suffix'] = '</div>';
  $form['submit']['#icon'] = '';
  $form['submit']['#icon_position'] = '';

  // Override prefix when empty.
  // VU theme has a custom prefix that needs to be changed for victory.
  // @see vu_form_vu_core_funnelback_search_form_alter().
  if (empty($form['submit']['#prefix'])) {
    $form['submit']['#prefix'] = '<div class="col-sm-3 col-lg-2 form-actions form-wrapper form-group">';
    $form['submit']['#suffix'] = '</div>';
  }

  return [
    'subject' => t('VU Funnelback Search Block'),
    'content' => [
      'form' => $form,
    ],
  ];

}
