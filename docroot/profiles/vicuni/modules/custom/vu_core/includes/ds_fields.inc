<?php

/**
 * @file
 * Create Display suite fields.
 */

/**
 * Render Supplimentary description.
 */
function vu_core_ds_field_supplimentary_description($field) {
  return _vu_core_display_field(['field_paragraphs_right', 'field_sidebar_content'], $field);
}

/**
 * Render Supplimentary carreers.
 */
function vu_core_ds_field_supplimentary_carreers($field) {
  return _vu_core_display_field(['field_para_supp_career_info', 'field_supplementary_career_info'], $field);
}

/**
 * Work through a list of fields to find the populated field and render.
 */
function _vu_core_display_field($fields, $info) {
  $entity = clone $info['entity'];
  unset($entity->_field_view_prepared);
  $language = entity_language($info['entity_type'], $entity);

  foreach ($fields as $field) {
    $instance = field_info_instance($info['entity_type'], $field, $info['bundle']);
    $field_info = field_info_field($instance['field_name']);

    if (!empty($entity->{$field_info['field_name']}[$language])) {
      $is_empty = $field_info['module'] . '_field_is_empty';
      if (function_exists($is_empty)) {
        foreach ($entity->{$field_info['field_name']}[$language] as $item) {
          if (!$is_empty($item, $field_info)) {
            $output = field_view_field($info['entity_type'], $entity, $field, $info['formatter_settings']['display'], $language);
            return drupal_render($output);
          }
        }
      }
    }
  }
}
