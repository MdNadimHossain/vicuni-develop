<?php

/**
 * @file
 * Common form handling the VU Researcher Profile.
 */

/**
 * Process field widget for institute field.
 */
function _vu_rp_field_widget_form_process_institute_field(&$element, &$form_state, $context) {
  // Add ''<None of these>' option for primary institute field.
  $field_name = 'field_rp_institute_primary';
  if ($context['field']['type'] == 'entityreference'
    && $context['field']['field_name'] == $field_name) {
    // @note: The key must be numeric.
    $other_key = '0';
    $element["#options"][$other_key] = t('<None of these>');
    // Set the default value.
    if (empty($element['#default_value']) &&
      isset($element["#entity"]->field_rp_institute_primary[LANGUAGE_NONE][0]['target_id'])
      && $element["#entity"]->field_rp_institute_primary[LANGUAGE_NONE][0]['target_id'] === $other_key
    ) {
      $element['#default_value'] = 0;
    }
  }
}
