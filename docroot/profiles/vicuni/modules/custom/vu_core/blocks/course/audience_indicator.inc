<?php

/**
 * @file
 * Courses - Audience Indicator.
 */

/**
 * Class VuCoreAudienceIndicatorCourseBlock.
 */
class VuCoreAudienceIndicatorCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Audience Indicator';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_audience_indicator';

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_BACHE_DEGREE | VU_CBS_AQF_BACHE_HON_DEGREE_EMB | VU_CBS_AQF_BACHE_HON_DEGREE_SA | VU_CBS_AQF_ASSOC_DEGREE | VU_CBS_AQF_DIPLOMA | VU_CBS_AQF_BACHE_DEGREE_MASTERS_DEGREE;

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Display only if Courses Admission Transparency feature switch is on.
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
    return [
      'subject' => NULL,
      'content' => [
        '#attached' => [
          'css' => [libraries_get_path('bootstrap-select') . '/dist/css/bootstrap-select.css'],
          'js' => [
            libraries_get_path('bootstrap-select') . '/dist/js/bootstrap-select.js',
            drupal_get_path('module', 'vu_core') . '/js/vu_core.audience-indicator.js',
          ],
        ],
        '#markup' => theme($this->theme, $this->variables()),
      ],
    ];
  }

}
