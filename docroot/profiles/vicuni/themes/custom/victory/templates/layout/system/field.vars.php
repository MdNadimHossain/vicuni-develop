<?php

/**
 * @file
 * Stub file for "field" theme hook [pre]process functions.
 */

/**
 * Implements hook_preprocess_HOOK().
 *
 * See template for list of available variables.
 *
 * @see field.tpl.php
 *
 * @ingroup theme_preprocess
 */
function victory_preprocess_field(&$variables) {

  $entity_type = $variables['element']['#entity_type'];
  $bundle = $variables['element']['#bundle'];
  $field_name = $variables['element']['#field_name'];

  if ('fieldable_panels_pane' == $entity_type && 'pane_featured_content' == $bundle && count($variables['items']) == 2) {
    $variables['ds-config']['fi-cl'] .= ' items-2';
  }

  if ('field_paragraphs_left' == $field_name) {
    $items = $variables['items'];

    // The preferred way to set classes is to use drupal_attributes and
    // $variables['item_attributes_array'] but it does not work from
    // theme_preprocess_field() hence we're using a custom theme variable.
    $item_classes = [];
    foreach ($items as $delta => $item) {
      if (!empty($item['entity']['paragraphs_item'])) {
        $entity = reset($item['entity']['paragraphs_item']);
        $item_classes[$delta] = 'field-item-' . $entity['#bundle'];
      }
    }
    $variables['item_classes'] = $item_classes;
  }

  // Add classes to Component Row based on layout selection.
  if ($bundle == 'component_row') {
    // TODO Need to calculate items actually present.
    $layout = isset($variables['element']['#object']->field_row_layout[LANGUAGE_NONE]['0']) ? $variables['element']['#object']->field_row_layout[LANGUAGE_NONE]['0'] : FALSE;
    $item_count = count($variables['element']['#object']->field_row_components[LANGUAGE_NONE]);

    if ($item_count === 1) {
      array_push($variables['classes_array'], 'row-full-width');
    }
    elseif ($item_count === 2) {
      if (!empty($layout)) {
        switch ($layout['value']) {
          case '6_6':
            array_push($variables['classes_array'], 'row-6-6');
            break;

          case '4_8':
            array_push($variables['classes_array'], 'row-4-8');
            break;

          case '8_4':
            array_push($variables['classes_array'], 'row-8-4');
            break;

          default:
            break;
        }
      }
      else {
        array_push($variables['classes_array'], 'row-6-6');
      }
    }
    elseif ($item_count === 3) {
      array_push($variables['classes_array'], 'row-4-4-4');
    }
  }

  if ($field_name == 'field_contact_info') {
    $node = isset($variables['element']['#object']) ? $variables['element']['#object'] : NULL;
    if ($node && $node->type == 'news') {
      $media = vu_core_extract_single_field_value($node, 'node', 'field_media_release');
      if ($media == TRUE) {
        $variables['label'] = 'Media contact';
      }
    }
  }
}
