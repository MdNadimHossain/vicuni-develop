<?php

/**
 * @file
 * Page preview module integration.
 */

/**
 * Implements hook_pagepreview_node_alter().
 */
function vu_core_pagepreview_node_alter($node, &$view_mode) {
  $theme = vu_core_node_field_theme_get($node);
  if ('victory' == $theme) {
    $view_mode = $theme;
  }
}
