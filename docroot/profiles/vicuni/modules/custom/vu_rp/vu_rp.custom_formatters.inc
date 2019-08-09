<?php
/**
 * @file
 * vu_rp.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function vu_rp_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'research_profile_flags';
  $formatter->label = 'Research Profile Supervisor Flag';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'list_boolean';
  $formatter->code = '$supervisor = [];
if (!empty($items)) {
  $supervisor = isset($items[0][\'value\']) && $items[0][\'value\'] ? "<i class=\'fa fa-check\'></i> Available to supervise research students" : "<i class=\'fa fa-times\'></i> Unavailable to supervise research students";
}

return [[\'#markup\' => $supervisor]];';
  $formatter->fapi = '';
  $export['research_profile_flags'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'staff_profiles_media_flag';
  $formatter->label = 'Researcher profiles media flag';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'list_boolean';
  $formatter->code = '$media_ready = [];
if (!empty($items)) {
  $media_ready = isset($items[0][\'value\']) && $items[0][\'value\'] ? "<i class=\'fa fa-microphone\'></i> Available for media queries" : "";
}

return [[\'#markup\' => $media_ready]];';
  $formatter->fapi = '';
  $export['staff_profiles_media_flag'] = $formatter;

  return $export;
}
