<?php

/**
 * @file
 * Overrides for vumain functions to avoid changes to deprecated module.
 */

/**
 * Implements hook_block_view_alter().
 */
function vumain_vu_core_block_view_alter(&$data, $block) {
  // Update the link to /mid-year to open in a _blank target.
  // This is a throwaway hack for [PW-2076].
  if ($block->module === 'vumain' && $block->delta === 'featured_content') {
    // The link to search for.
    $midyear_link_tag = '<a href="/mid-year">';
    $midyear_link_tag_length = strlen($midyear_link_tag);
    // The parameter to inject.
    $parameter = ' target="_blank"';
    $parameter_length = strlen($parameter);

    // There's more than one link, and the block doesn't ever start with it.
    $offset_position = 0;
    while ($midyear_link_start = strpos($data['content'], $midyear_link_tag, $offset_position)) {
      // Insert the parameter between '"' and '>'.
      $parameter_insert_position = $midyear_link_start + $midyear_link_tag_length - 1;
      $data['content'] = substr_replace($data['content'], $parameter, $parameter_insert_position, 0);
      $offset_position = $parameter_insert_position + $parameter_length;
    }
  }
}
