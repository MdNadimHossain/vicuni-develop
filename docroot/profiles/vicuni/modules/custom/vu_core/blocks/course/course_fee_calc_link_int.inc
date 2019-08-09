<?php

/**
 * @file
 * Fee Calculator Link block International.
 */

/**
 * Class VuCoreCourseFeeCalcLinkIntCourseBlock.
 */
class VuCoreCourseFeeCalcLinkIntCourseBlock extends vuCoreCourseBlockBase {
  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_INTERNATIONAL;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Course Fee Calculator Link - International';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_fee_calculator_link';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return [
      'link' => '/study-at-vu/fees-scholarships/fee-calculator?international=1',
    ];
  }

}
