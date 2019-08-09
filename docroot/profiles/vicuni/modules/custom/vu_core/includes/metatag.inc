<?php

/**
 * @file
 * Metatag integration for the metatag_opengraph module.
 */

/**
 * Implements hook_html_head_alter().
 */
function vu_core_html_head_alter(&$head_elements) {
  $node = menu_get_object();
  $image = drupal_get_path('theme', 'victory') . '/images/vu_logo_stacked.png';
  $image_url = url($image, ['absolute' => TRUE]);

  // Adding default image if researcher do not want to use his photo.
  if (isset($node->type) && $node->type == 'researcher_profile') {
    $val = vu_rp_extract_single_field_value('node', $node, 'field_rp_use_photo');
    if (!$val && isset($head_elements['metatag_og:image_0'])) {
      $head_elements['metatag_twitter:image_0']['#value'] = $head_elements['metatag_og:image_0']['#value'] = $image_url;
    }
  }
  if (!isset($head_elements['metatag_og:image_0']) && isset($head_elements['metatag_og:site_name_0'])) {
    $head_elements['metatag_og:image_0'] = [
      '#theme' => 'metatag_property',
      '#tag' => 'meta',
      '#id' => 'metatag_og:image_0',
      '#name' => 'og:image',
      '#value' => $image_url,
      '#weight' => 34,
      '#type' => 'html_tag',
    ];
  }
  if (!isset($head_elements['metatag_twitter:image_0'])  && isset($head_elements['metatag_twitter:url_0'])) {
    $head_elements['metatag_twitter:image_0'] = [
      '#theme' => 'metatag_twitter_cards',
      '#tag' => 'meta',
      '#id' => 'metatag_twitter:image_0',
      '#name' => 'twitter:image',
      '#value' => $image_url,
      '#weight' => 50.1,
      '#type' => 'html_tag',
    ];
  }
}
