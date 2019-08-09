<?php

/**
 * @file
 * Paragraphs module integration.
 */

/**
 * Implements hook_preprocess_entity_ENTITY_TYPE_BUNDLE_alter().
 */
function vu_rp_preprocess_entity_paragraphs_item_find_researcher_alter(&$vars) {
  $paragraph = $vars['elements']['#entity'];
  // Get link.
  $link = '';
  $link_enabled = field_get_items('paragraphs_item', $paragraph, 'field_researcher_link');
  if (!empty($link_enabled[0]['value'])) {
    if ($link_enabled[0]['value']) {
      $link = VU_RP_SEARCH_LINK;
    }
  }

  $vars['content']['researcher_link'] = $link;
}

/**
 * Implements hook_field_widget_form_alter().
 */
function vu_rp_field_widget_paragraphs_embed_form_alter(&$element, &$form_state, $context) {
  // Unset description.
  if ($context['field']['field_name'] == 'field_rp_ota') {
    foreach ($element as $key => $field) {
      if (is_numeric($key)) {
        if (isset($field['paragraph_bundle_title']['info']['#markup'])) {
          unset($element[$key]['paragraph_bundle_title']['info']['#markup']);
        }
      }
    }
  }
}
