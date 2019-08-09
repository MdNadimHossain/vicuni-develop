<?php

/**
 * @file
 * Fee Calculator Link Domestic block.
 */

/**
 * Class VuCoreCourseFeeCalcLinkDomCourseBlock.
 */
class VuCoreCourseFeeCalcLinkDomCourseBlock extends vuCoreCourseBlockBase {
  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Course Fee Calculator Link - Domestic';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_fee_calculator_link';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return [
      'link' => '/study-at-vu/fees-scholarships/fee-calculator',
    ];
  }

}
