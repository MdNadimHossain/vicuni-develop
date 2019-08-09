<?php

/**
 * @file
 * News media img caption.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_news_media_img_caption_info() {
  return [
    'info' => t('News media img caption'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_news_media_img_caption_view() {
  $node = menu_get_object();
  if ($node->type !== 'news') {
    return FALSE;
  }

  $img_caption = $node->field_image[LANGUAGE_NONE][0]['field_file_image_title_text'][LANGUAGE_NONE][0]['safe_value'];
  $variables = [];
  $variables['img_caption'] = $img_caption;
  $block = theme('vu_news_media_img_caption', $variables);
  return [
    'subject' => NULL,
    'content' => [
      '#markup' => $block,
    ],
  ];

}
