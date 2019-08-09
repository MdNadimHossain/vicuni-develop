<?php

/**
 * @file
 * Courses - How to Apply - Mid-year block.
 */

/**
 * Class VuCoreHtaMidYearCourseBlock.
 */
class VuCoreHtaMidYearCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_HE | VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_YES;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Mid Year';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    return vu_feature_switches_switch_state('courses-midyear-info');
  }

  /**
   * {@inheritdoc}
   */
  public function view() {
    $element = [
      '#type' => 'html_tag',
      '#tag' => 'h3',
      '#value' => t('Mid-year applications'),
    ];

    return [
      'subject' => NULL,
      'content' => render($element),
    ];
  }

}
