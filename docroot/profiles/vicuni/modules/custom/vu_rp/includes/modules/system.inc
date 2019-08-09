<?php

/**
 * @file
 * System module integration.
 */

/**
 * Implements hook_preprocess().
 */
function vu_rp_preprocess(&$vars, $hook) {
  drupal_alter('vu_rp_preprocess', $vars, $hook);
  drupal_alter("vu_rp_preprocess_{$hook}", $vars);
}
