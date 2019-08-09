<?php

/**
 * @file
 * Functions for vumain course blocks.
 */

// Include the relevant file to be able to return the block types.
module_load_include('php', 'vumain', 'includes/vumain_courses/vumain.courses.functions');

/**
 * Pseudo implements hook_block_info().
 */
function vumain_courses_block_info() {
  $blocks = array();

  $blocks['course-list'] = array(
    'info' => 'VU courses: course a-z list',
    'cache' => DRUPAL_CACHE_GLOBAL,
    'weight' => 0,
    'status' => 1,
    'region' => 'content',
    'theme' => 'VU',
    'pages' => 'courses/browse-for-courses/all-courses-a-to-z',
    'visibility' => BLOCK_VISIBILITY_LISTED,
  );
  $blocks['courses_disclaimer'] = array(
    'info' => t('Courses disclaimer'),
    'status' => 0,
  );
  $blocks['homepage_course_finder_box'] = array(
    'info' => t('Homepage course finder box'),
    'status' => 0,
  );
  $blocks['landingpages_course_finder_box'] = array(
    'info' => t('VU: Landing pages course finder box'),
    'status' => 0,
  );
  $blocks['vu_study_topics_form'] = array(
    'info' => t('VU_Courses: Study Topics form'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );

  // Return all 'Course search form' blocks.
  $types = _vumain_courses_search_get_form_type();
  // Loop through the types.
  foreach ($types as $type => $name) {
    $args = array(
      '@name' => $name,
    );
    $blocks['vu_course_search_' . $type] = array(
      'info' => t('VU Course Finder: @name', $args),
    );
  }

  return $blocks;
}

/**
 * Pseudo implements hook_block_config().
 */
function vumain_courses_disclaimer_block_configure() {
  $form = array();
  $form['courses_disclaimer'] = array(
    '#type' => 'text_format',
    '#title' => t('Disclaimer text'),
    '#default_value' => variable_get('courses_disclaimer', ''),
  );
  $form['courses_disclaimer_international'] = array(
    '#type' => 'text_format',
    '#title' => t('International Disclaimer text'),
    '#default_value' => variable_get('courses_disclaimer_international', VUMAIN_DEFAULT_INTERNATIONAL_DISCLAIMER),
  );
  return $form;
}

/**
 * Pseudo implements hook_block_save().
 */
function vumain_courses_disclaimer_block_save($edit) {
  variable_set('courses_disclaimer', $edit['courses_disclaimer']['value']);
  variable_set('courses_disclaimer_international', $edit['courses_disclaimer_international']['value']);
}

/**
 * Pseudo implements hook_block_view().
 *
 * @deprecated @PW-236
 */
function vumain_courses_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'course-list':
      $block = array(
        'subject' => t('All courses A to Z'),
        'content' => theme('vumain_courses_list'),
      );
      break;

    case 'courses_disclaimer':
      // If tafe course, add additional disclaimer.
      $node = menu_get_object();
      $disclaimer = '';
      if (!empty($node->field_unit_lev) && $node->field_unit_lev[$node->language][0]['value'] == VUMAIN_COURSELEVEL_TAFE) {
       $disclaimer = t('<p class="tafe-disclaimer">Please note that if changes to this course occur, VU will notify students as soon as possible.</p>');
      }
      if (vu_courses_is_international_course_url()){
        $block['content'] = $disclaimer . '<div class="course-disclaimer">' . variable_get('courses_disclaimer_international', '') . '</div>';
      }
      else {
        $block['content'] = $disclaimer . '<div class="course-disclaimer">' . variable_get('courses_disclaimer', '') . '</div>';
      }
      break;

    case 'homepage_course_finder_box':
      $block['content'] = theme('vumain_courses_course_finder_box');
      break;

    case 'landingpages_course_finder_box':
      $block['content'] = theme('vumain_landing_course_finder_box');
      break;

    case 'vu_study_topics_form':
      // Check if any study topics attached to at least one course, to control
      // block visibility.
      $study_topics = vumain_cources_get_all_study_topics();
      $block['subject'] = FALSE;
      $block['content'] = !empty($study_topics) ? drupal_get_form('vumain_courses_courses_by_study_topic_form') : '';
      break;
  }

  // Work out the type.
  // The 17 in this case is the length of the string
  // before the actual ID i.e. vu_course_search_.
  $type = substr($delta, 17);
  if (!empty($type) && substr($delta, 0, 17) == 'vu_course_search_') {
    $block['content'] = drupal_get_form('vumain_courses_course_finder_form', $type);
  }

  return $block;
}
