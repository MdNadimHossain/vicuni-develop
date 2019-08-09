<?php

/**
 * @file
 * File for "panels-victory-navigation" template [pre]process functions.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function victory_preprocess_panels_victory_navigation(&$variables) {
  $variables['front_page'] = url();
  $variables['logo'] = theme_get_setting('logo');
  $variables['logo_svg'] = victory_embed_svg($variables['logo']);
  $variables['site_name'] = variable_get('site_name');
  // If the page is a subsite.
  $variables['is_subsite'] = vu_core_is_subsite() ? TRUE : FALSE;

  if ($variables['is_subsite']) {
    $subsite_node = vu_core_subsite_node_get();
    // Load settings from taxonomy.
    if (!empty($subsite_node)) {
      $subsite_metadata = vu_core_subsite_meta_get($subsite_node);
      if (!empty($subsite_metadata->logo)) {
        $variables['logo'] = $subsite_metadata->logo;
        $variables['logo_svg'] = victory_embed_svg($variables['logo']);
        // Change logo link.
        $mlid = vu_core_get_mlid();
        if ($mlid) {
          $menu_item = menu_link_load($mlid);
          if (!empty($menu_item['link_path'])) {
            $variables['front_page'] = url($menu_item['link_path']);
          }
        }
      }
    }
  }
}
