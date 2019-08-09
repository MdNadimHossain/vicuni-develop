<?php

/**
 * @file
 * Stub file for "entity" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "entity" theme hook.
 *
 * See template for list of available variables.
 *
 * @see entity.tpl.php
 *
 * @ingroup theme_preprocess
 */
function victory_preprocess_entity(&$variables) {
  // Abstract function into entity/bundle targeted functions.
  $entity = &$variables['elements']['#entity'];
  $entity_type = $variables['elements']['#entity_type'];
  $bundle = $variables['elements']['#bundle'];
  $functions = [
    "victory_preprocess_entity__{$entity_type}",
    "victory_preprocess_entity__{$entity_type}__{$bundle}",
  ];
  foreach ($functions as $function) {
    if (function_exists($function)) {
      $function($variables, $entity);
    }
  }

  // @TODO - Change to `field_brand`.
  if (isset($variables[$variables['entity_type']]->field_promo_brand)) {
    $items = field_get_items($variables['entity_type'], $variables[$variables['entity_type']], 'field_promo_brand');
    if (isset($items[0]['value'])) {
      $variables['classes_array'][] = "brand-set-{$items[0]['value']}";
    }
  }
  if (!empty($variables['elements']['#view_mode'])) {
    $view_mode = $variables['elements']['#view_mode'];
    $entity = !empty($variables['elements']['#entity']) ? $variables['elements']['#entity'] : '';
    switch ($view_mode) {
      case 'carousel':
        drupal_add_js(libraries_get_path('bootstrap-sass') . '/assets/javascripts/bootstrap/carousel.js');
        drupal_add_js(path_to_theme() . '/js/components/bootstrap.carousel.js');
        break;

      case 'collapsable_content':
        // This is set in vu_core_preprocess_entity().
        if (!empty($entity->referenced_entity_type) && $entity->referenced_entity_type == 'success_story') {
          $variables['classes_array'][] = 'success_story_collapsable';
          drupal_add_js(path_to_theme() . '/js/components/success_story.collapsable.js');
        }
        break;

    }
  }
}

/**
 * Implements hook_preprocess_entity__ENTITY_TYPE__BUNDLE().
 */
function victory_preprocess_entity__paragraphs_item__accordion(&$variables, $entity) {
  $variables['icon'] = victory_embed_svg(url('/profiles/vicuni/themes/custom/victory/images/cross.svg'));
}
