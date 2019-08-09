<?php

/**
 * @file
 * VU course related hooks.
 */

/**
 * Implements hook_preprocess_node().
 */
function vu_courses_vu_core_preprocess_node_alter(&$variables) {
  switch ($variables['node']->type) {
    case 'courses':
      _vu_core_course_node_preprocess($variables);
      break;

    case 'unit':
      _vu_core_unit_node_preprocess($variables);
      break;

    case 'unit_set':
      _vu_core_unit_node_preprocess($variables);
      break;

  }
}

/**
 * Implements hook_node_view().
 */
function vu_courses_vu_core_node_view_alter($node, $view_mode, $langcode) {
  if ($node->type != 'courses') {
    return;
  }
  if (!vu_courses_is_international_course_url()) {
    if (!vu_courses_offered_to_audience($node, 'domestic')) {
      if (vu_courses_offered_to_audience($node, 'international')) {
        $path = 'courses/international/' . vu_core_extract_single_field_value($node, 'node', 'field_unit_code');
        drupal_goto($path, [], 303);
      }

      // Still here?
      drupal_not_found();
      drupal_exit();
    }
  }
  vu_core_prevent_automatic_tel_links();
}

/**
 * Course related node preprocess functionality.
 */
function _vu_core_course_node_preprocess(&$variables) {
  $node = $variables['node'];
  $variables['international'] = vu_courses_is_international_course_url();
  $audience = $variables['international'] ? 'international' : 'domestic';
  $variables['description'] = theme('vu_courses_description', $variables);

  $themeables = [
    'course_objectives',
    'units_and_electives',
    'how_to_apply',
  ];

  $variables['associated_courses'] = theme('associated-courses', ['course' => $variables['node']]);

  // Has a huge query that needs upgrading.
  $variables['info_sessions'] = theme("vu_courses_{$audience}_info_sessions", [
    'nid' => $variables['node']->nid,
    'audience' => $audience,
  ]);

  $variables['course_partials'] = [];
  foreach ($themeables as $themeable) {
    $theme_name = "vu_courses_{$audience}_{$themeable}";
    $variables['course_partials'][$themeable] = theme($theme_name, [
      'node' => $variables['node'],
      'title' => '',
    ]);
  }

  // College link.
  $field_college_link = field_view_field('node', $variables['node'], 'field_college', ['label' => 'hidden']);
  $variables['college_link'] = drupal_render($field_college_link);

  $field_supplementary_description = field_view_field('node', $variables['node'], 'field_sidebar_content', [
    'label' => 'hidden',
    'type' => 'entityreference_entity_view',
    'settings' => ['view_mode' => 'full'],
  ]);
  $variables['supplementary_description'] = drupal_render($field_supplementary_description);

  $variables['course_level'] = $node->field_unit_lev[$node->language][0]['value'];
  $variables['tafe_course'] = $variables['course_level'] == 'tafe';
  $variables['short_course'] = $variables['course_level'] == 'short';

  // This is based on the fact that at time of writing all TAFE courses that do
  // not have 'Victorian' in their title are Nationally Registered.
  $victorian = (FALSE !== strpos(strtolower($node->title), 'victorian'));
  $variables['nrt'] = $variables['tafe_course'] && !$victorian;

  // Get course code.
  $code = $node->field_unit_code[$node->language][0]['safe_value'];
  $variables['course_code'] = $code;

  // Add introduction field.
  $introduction = field_view_field('node', $variables['node'], 'field_introduction', ['label' => 'hidden']);
  $variables['course_introduction'] = empty($introduction['#items'][0]['safe_value']) ? '' : $introduction['#items'][0]['safe_value'];

  // Load field_completion_rules.
  $variables['completion_rules'] = field_view_field('node', $node, 'field_completion_rules', ['label' => 'hidden']);

  // Course AQF.
  $course = new VuCoreCourseBlockBase($node);
  $variables['aqf'] = $course->getCourseAqf();

  // Add meta tag with course code.
  $course_code_meta_tag = [
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => [
      'name' => 'course_code',
      'content' => $code,
    ],
  ];
  drupal_add_html_head($course_code_meta_tag, 'course_code');
  drupal_add_js('var $c_code=document.querySelector(\'meta[name="course_code"]\');if($c_code){var c_code=$c_code.getAttribute(\'content\');}',
    [
      'type' => 'inline',
      'scope' => 'footer',
    ]
  );
}

/**
 * Unit related node preprocess functionality.
 */
function _vu_core_unit_node_preprocess(&$variables) {
  $unit_level = '';
  // Unit level comes through in a different format depending on the content
  // type.
  if (isset($variables['field_unit_lev'][LANGUAGE_NONE]) && !empty($variables['field_unit_lev'][LANGUAGE_NONE][0]['value'])) {
    $unit_level = $variables['field_unit_lev'][LANGUAGE_NONE][0]['value'];
  }
  elseif (!empty($variables['field_unit_lev'][0]['value'])) {
    $unit_level = $variables['field_unit_lev'][0]['value'];
  }

  $undergrad_postgrad_unit_levels = [VUMAIN_COURSELEVEL_UNDERGRADUATE, VUMAIN_COURSELEVEL_POSTGRADUATE];
  $variables['unit_level'] = vumain_get_study_level($unit_level);

  $variables['courses_this_unit_belongs_to'] = views_embed_view('courses_by_unit_unitset', 'block', $variables['nid']);

  $variables['specialisations_this_unit_belongs_to'] = views_embed_view('courses_by_unit_unitset', 'block_1', $variables['nid']);
  if ('unit' == $variables['type'] && in_array($unit_level, $undergrad_postgrad_unit_levels)) {
    $bean = module_invoke('bean', 'block_view', 'vu-study_single_unit_bean');
    $variables['study_single_unit']['heading'] = check_plain($bean['subject']);
    $variables['study_single_unit']['content'] = $bean['content'];
  }

  // Handle imported locations that cannot be stored as
  // entity references.
  $special_locations = [];
  if (!empty($variables['field_locations_special'])) {
    foreach ($variables['field_locations_special'] as $value) {
      if ($value['safe_value'] == 'VU Sydney') {
        $sydney_link = vu_unit_special_location_link('VU Sydney');
        $special_locations[] = ['#markup' => $sydney_link];
      }
      else {
        $special_locations[] = ['#markup' => $value['safe_value']];
      }
    }
  }
  $variables['special_locations'] = $special_locations;
  // Provide minimum required render array for #theme => field
  // for nodes where only special locations are imported.
  $variables['field_locations_base_render_array'] = [
    '#items' => [],
    '#theme' => 'field',
    '#label_display' => 'hidden',
    '#formatter' => 'entityreference_label',
    '#field_name' => 'field_locations',
  ];

  // Prerequisites and corequisites - Render and ensure actual content present.
  foreach (['field_prerequisites', 'field_co_requisites'] as $field_name) {
    if (isset($variables['content'][$field_name])) {
      $tmp_content = trim(strip_tags(render($variables['content'][$field_name])));
      $variables[$field_name] = !empty($tmp_content);
    }
  }
}
