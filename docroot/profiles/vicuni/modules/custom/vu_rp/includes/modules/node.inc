<?php

/**
 * @file
 * Node related functions.
 */

/**
 * Implements hook_preprocess_page_alter().
 */
function node_vu_rp_preprocess_page_alter(&$variables) {
  $node = isset($variables['node']) && is_object($variables['node']) ? $variables['node'] : FALSE;

  if ($node === FALSE) {
    return;
  }

  switch ($node->type) {
    case 'researcher_profile':
      $crumbs = [
        'home' => l(t('VU Home'), '<front>'),
        'research' => l(t('Research'), '/research'),
        'find' => l(t('Find a researcher'), VU_RP_SEARCH_LINK),
      ];
      // Set breadcrumbs.
      drupal_set_breadcrumb($crumbs);
      break;
  }
}
