<?php
/**
 * @file
 * VU Midyear Intake views hooks.
 */

/**
 * Implements hook_preprocess_views_view_list().
 */
function vu_midyear_intake_preprocess_views_view_list(&$variables) {
  if (!vu_midyear_intake_is_enabled() || vu_core_is_non_resident_search()) {
    return;
  }
  $view = $variables['view'];
  if ($view->name == 'course_search') {
    foreach ($variables['rows'] as $id => $row) {
      $course = $view->result[$id]->entity;
      if (!is_object($course)) {
        $course = node_load($course);
      }
      // Add Midyear class to wrapper if the course is available.
      if ($course->type == 'courses' && vu_course_index_is_midyear($course)) {
        $variables['classes_array'][$id] .= 'midyear';
      }
    }
  }
}
