<?php

/**
 * @file
 * Courses - Pathways and Credits.
 */

/**
 * Class VuCorePAthwaysCreditsCourseBlock.
 */
class VuCorePAthwaysCreditsCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Pathways and Credits';

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_BACHE_DEGREE | VU_CBS_AQF_BACHE_HON_DEGREE_EMB | VU_CBS_AQF_BACHE_HON_DEGREE_SA | VU_CBS_AQF_ASSOC_DEGREE | VU_CBS_AQF_DIPLOMA | VU_CBS_AQF_BACHE_DEGREE_MASTERS_DEGREE;

  /**
   * {@inheritdoc}
   */
  public $courseType = !VU_CBS_TYPE_NA;

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Do not display for undergrad courses if switch is on.
    if (vu_feature_switches_switch_state('courses-admission-transparency')) {
      // Ensure that this works for only HE diploma courses.
      if ($this->getCourseAqf() == VU_CBS_AQF_DIPLOMA) {
        if ($this->getCourseType() != VU_CBS_TYPE_HE) {
          return FALSE;
        }
      }

      return TRUE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function view() {

    $level = $this->getCourseType();

    // Prepare array of arguments for theme function.
    $course_code = vu_core_extract_single_field_value($this->course, 'node', 'field_unit_code');
    $international = vu_core_extract_single_field_value($this->course, 'node', 'field_international');
    $international = ($international && vu_courses_is_international_course_url());
    $variables = [];
    module_load_include('inc', 'vu_core', 'theme/vu_core.theme');
    $pathways = vu_core_pathways_in($this->course, $international);

    $variables['course_code'] = $course_code;
    $variables['course_name'] = $this->course->title;
    $variables['college'] = vu_core_extract_single_field_value($this->course, 'node', 'field_college', 'title');
    $variables['is_ve'] = $level == VU_CBS_TYPE_VE ? TRUE : FALSE;
    $variables['international'] = $international;

    // Allows for optionally excluding accordion items.
    $content = [];

    $variables['type'] = 'Internal to VU';
    $variables['introText'] = FALSE;
    $variables['pathways'] = $pathways['Internal to VU'];
    $content[] = [
      '#theme' => 'vu_accordion',
      '#name' => 'accordion-pathways-from-vu',
      '#title' => t('Pathways from VU courses'),
      '#content' => theme('pathways_to_this_course', $variables),
    ];

    if (count($pathways['External to VU'])) {
      $variables['type'] = 'External to VU';
      $variables['pathways'] = $pathways['External to VU'];
      $content[] = [
        '#theme' => 'vu_accordion',
        '#name' => 'accordion-pathways-from-external',
        '#title' => t('Pathways from other institutions'),
        '#content' => theme('pathways_to_this_course', $variables),
      ];
    }

    if (count($pathways['Offshore'])) {
      $variables['type'] = 'Offshore';
      $variables['pathways'] = $pathways['Offshore'];
      $content[] = [
        '#theme' => 'vu_accordion',
        '#name' => 'accordion-pathways-from-international',
        '#title' => t('Pathways from overseas institutions'),
        '#content' => theme('pathways_to_this_course', $variables),
      ];
    }

    $content[] = [
      '#theme' => 'vu_accordion',
      '#name' => 'accordion-pathways-credit',
      '#title' => $variables['is_ve'] ? t('Recognition of Prior Learning (RPL)') : t('Credit for skills and past study'),
      '#content' => theme('pathways_credit', $variables),
    ];

    return [
      'subject' => NULL,
      'content' => $content,
    ];
  }

}
