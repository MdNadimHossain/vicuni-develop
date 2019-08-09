<?php

/**
 * @file
 * Preprocess functions for course index functionality.
 */

/**
 * Implements hook_preprocess_page().
 *
 * Remove sidebar classes from body tag and adds specific VUIT classes if the
 * search request has vuit query parameter.
 */
function vu_course_index_preprocess_page(&$vars) {
  if (isset($vars['node']) && $vars['node']->type == 'course' && vu_courses_is_provided_by_tafe($vars['node']->field_school_imported[0])) {
    vu_courses_set_vuit_branding_classes($vars);
  }
}

/**
 * Change node title to "TAFE Courses" when the course is TAFE.
 */
function vu_course_index_neon_node_title_alter(&$vars) {
  if (isset($vars['node']) && $vars['node']->type == 'course' && vu_courses_is_provided_by_tafe($vars['node']->field_school_imported[0])) {
    vu_courses_set_vuit_page_title($vars, 'TAFE courses', 'courses/search');
  }
}

/**
 * Implements hook_preprocess_node().
 */
function vu_course_index_preprocess_node(&$variables) {
  module_load_include('php', 'vu_course_index', 'vu_course_index.functions');

  if ($variables['type'] == 'courses') {
    // Add JavaScript to override the online application link on mobile
    // because eAdmssions doesn't support mobile.
    // Note: this may be redundant now?
    $code = $variables['field_unit_code'][$variables['language']][0]['safe_value'];
    $apply_online_url = vu_courses_apply_url($code);
    $mobile_apply_online_url = sprintf('/%s/%s',
      VU_COURSE_INDEX_MOBILE_APPLY_ONLINE_URL, $code);
    drupal_add_js(array(
      'applyOnlineURL' => $apply_online_url,
      'mobileApplyOnlineURL' => $mobile_apply_online_url,
    ), 'setting');
    drupal_add_js(
      VU_COURSE_INDEX_MODULE_PATH . '/js/mobile-online-application.js',
      'footer');

    $variables['delivery'] = vu_course_index_get_course_intake_list($variables['field_unit_code'][$variables['language']][0]['safe_value']);
    $variables['midyear'] = vu_course_index_is_midyear($variables['node']);
  }
}

/**
 * Prepare vars to render mobile apply online block.
 */
function preprocess_mobile_apply_online(&$vars) {
  module_load_include('module', 'vumain');
  $node = vumain_get_course_node_by_unit_code($vars['course_code']);
  if ($node) {
    $vars['course_link'] = l($node->title, $node->path);
  }
}

/**
 * Prepare vars to render how to apply summary.
 */
function preprocess_how_to_apply_summary(&$vars) {
  $course = $vars['course'];

  $field = _course_field_lookup_func($course);

  $variables = array(
    'course' => $course,
    'short_course' => $field('unit_lev', 'value') == 'Short course',
    'international' => $field('international', 'value') == TRUE,
    'how_to_apply' => $field('how_to_apply'),
    'faculty' => $field('college', 'title'),
  );

  // Re-use the "how to apply" logic with our array.
  preprocess_how_to_apply($variables);

  $variables['is_international'] = vu_courses_is_international_course_url();

  // Combine both arrays!
  $vars = array_merge($vars, $variables);

  // Is this a midyear course?
  $vars['midyear'] = vu_feature_switches_switch_state('courses-midyear-info') &&
    $vars['delivery']->isOpen();
}

/**
 * Populate index data based on course code for theme.
 */
function preprocess_how_to_apply(&$vars) {

  $course = $vars['course'];
  $vars['course_code'] = $course->field_unit_code[$course->language][0]['safe_value'];

  $field = _course_field_lookup_func($course);

  $aqf_type = $field('course_aqf', 'value');
  $vars['is_pgr'] = preg_match('/Doctoral|Research/', $aqf_type);

  $is_specialisation = preg_match('/-/i', $field('unit_code'));
  $vars['specialisation_text'] = theme('specialisation-text', array('is_specialisation' => $is_specialisation));

  if (isset($course->_intakes)) {
    $vars['delivery'] = new CourseIntakeList($course->_intakes);
  }
  else {
    $vars['delivery'] = vu_course_index_get_course_intake_list($vars['course_code']);
  }

  // Always returns FALSE?
  $vars['midyear'] = vu_feature_switches_switch_state('courses-midyear-info') && $vars['delivery']->isOpen();

  // Checks July intake against current year.
  if (!empty($course->field_int_sem_int[$course->language][0]['value'])) {
    $field_int_sem_int_value = $course->field_int_sem_int[$course->language][0]['value'];
    $vars['july_intake'] = vu_courses_has_july_intake_from_xml($field_int_sem_int_value) && $vars['delivery']->isOpen() ? date('Y') : FALSE;
  }

  // Contact message.
  $vars['contact_message'] = t('Call us on <strong>1300 VIC UNI (1300 842 864)</strong>');
  if ($vars['delivery']->isTafe()) {
    $vars['contact_message'] = t('Ring us on <strong>1300 TAFE VP (1300 823 387)</strong>');
  }

  // Is this a new course?
  $next_year = date('Y') + 1;
  $vars['new_course'] = vu_courses_is_new_course($field('first_off_date'), $next_year);
  $vars['new_course'] = FALSE;

  $vars['application_methods'] = trim(theme('application-methods', array(
    'course_code' => $vars['course_code'],
    'short_course' => $vars['short_course'],
    'international' => $vars['international'],
    'is_pgr' => $vars['is_pgr'],
    'delivery' => $vars['delivery'],
    'new_course' => $vars['new_course'],
    'course' => $vars['course'],
  )));
}

/**
 * Prepare vars to render associated courses section.
 */
function preprocess_associated_courses(&$vars) {
  $course = $vars['course'];
  preprocess_how_to_apply_summary($vars);

  $vars['course_preceded_by'] = FALSE;
  $vars['course_followed_by'] = FALSE;

  $course_preceded_by = !empty($course->field_course_preceded_by) ? $course->field_course_preceded_by[$course->language][0]['entity'] : FALSE;
  $course_followed_by = !empty($course->field_course_followed_by) ? $course->field_course_followed_by[$course->language][0]['entity'] : FALSE;
  $is_intl = $vars['is_international'];

  if ($course_preceded_by && $course_preceded_by->status) {
    $cpby_code = $course_preceded_by->field_unit_code[$course_preceded_by->language][0]['safe_value'];

    if (!$is_intl) {
      $course_preceded_by->url = '/courses/' . $cpby_code;
    }
    elseif ($course_preceded_by->field_international[$course_preceded_by->language][0]['value'] == TRUE) {
      $course_preceded_by->url = '/courses/international/' . $cpby_code;
    }

    $vars['course_preceded_by'] = $course_preceded_by;
  }

  if ($course_followed_by && $course_followed_by->status) {
    $cfby_code = $course_followed_by->field_unit_code[$course_followed_by->language][0]['safe_value'];

    if (!$is_intl) {
      $course_followed_by->url = '/courses/' . $cfby_code;
    }
    elseif ($course_followed_by->field_international[$course_followed_by->language][0]['value'] == TRUE) {
      $course_followed_by->url = '/courses/international/' . $cfby_code;
    }

    $vars['course_followed_by'] = $course_followed_by;
  }
}
