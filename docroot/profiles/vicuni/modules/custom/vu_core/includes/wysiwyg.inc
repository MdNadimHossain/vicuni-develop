<?php

/**
 * @file
 * Wysiwyg module integration.
 */

/**
 * Implements hook_element_info_alter().
 */
function vu_core_element_info_alter(&$type) {
  $type['text_format']['#pre_render'][] = 'vu_core_pre_render_text_format';
}

/**
 * Text format element #pre_render callback.
 *
 * @param array $element
 *   The element.
 *
 * @return array
 *   The element.
 */
function vu_core_pre_render_text_format(array $element = []) {
  // filter_process_format() copies properties to the expanded 'value' child
  // element. Skip this text format widget, if it contains no 'format' or when
  // the current user does not have access to edit the value.
  if (!isset($element['format']) || !empty($element['value']['#disabled'])) {
    return $element;
  }

  // Allow modules to programmatically enforce no client-side editor by setting
  // the #wysiwyg property to FALSE.
  if (isset($element['#wysiwyg']) && !$element['#wysiwyg']) {
    return $element;
  }

  // Attach the custom VU Wysiwyg behaviours.
  $element['#attached']['js'][] = drupal_get_path('module', 'vu_core') . '/js/vu_core.ckeditor.js';

  return $element;
}
