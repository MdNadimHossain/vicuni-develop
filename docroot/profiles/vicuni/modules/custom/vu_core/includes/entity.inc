<?php

/**
 * @file
 * Entity module integration.
 */

/**
 * Implements hook_entity_property_info_alter().
 */
function vu_core_entity_property_info_alter(&$info) {
  if (isset($info['node']['bundles']['courses']['properties'])) {
    $properties = &$info['node']['bundles']['courses']['properties'];
    $properties['commencement_date'] = [
      'label' => t("Course Commencement Date"),
      'description' => t("Course Commencement Date"),
      'type' => 'text',
      'getter callback' => '_vu_core_get_property_commencement_date',
    ];
    $properties['course_duration_hours'] = [
      'label' => t("Course Duration Hours"),
      'description' => t("Course Duration Hours"),
      'type' => 'integer',
      'getter callback' => '_vu_core_get_course_duration_hours',
    ];
  }
  // Sticky and promote are defined twice: first by Entity API and again by
  // Custom Publishing Options. This results in the definitions containing
  // arrays as values instead of strings. Here we just go with the last one
  // defined, which is the Custom Publishing Options one.
  foreach (['sticky', 'promote'] as $property_name) {
    if (isset($info['node']['properties'][$property_name])) {
      // Setter permission defaults to 'administer content', but we want to use
      // the granular Custom Publishing Options permissions.
      unset($info['node']['properties'][$property_name]['setter permission']);
      foreach ($info['node']['properties'][$property_name] as $key => $value) {
        if (is_array($value)) {
          $info['node']['properties'][$property_name][$key] = array_pop($value);
        }
      }
    }
  }
}

/**
 * Implements hook_entity_view_mode_alter().
 */
function vu_core_entity_view_mode_alter(&$view_mode, $context) {
  if (isset($context['entity_type'])) {
    if ($context['entity_type'] == 'node' && $context['entity']->type == 'staff_profile') {
      $view_mode = 'victory';
    }
  }
}
