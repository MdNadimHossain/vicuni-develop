<?php

/**
 * @file
 * Media related hooks.
 */

/**
 * Implements hook_entity_view_alter().
 */
function media_vu_core_entity_view_alter(&$build, $type) {
  if ($type === 'file' && !empty($build['#file']) && $build['#file']->type === 'document') {
    // This removes the "admin links" which force a div wrapper.
    unset($build['links']);
  }
}
