<?php

/**
 * @file
 * Courses - How to Apply - Short Course Summary block.
 */

/**
 * Class VuCoreHtaShortCourseSummaryBlock.
 */
class VuCoreHtaShortCourseSummaryCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_NA;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Short Course Summary';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_short_course_summary';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return [
      'hta_content' => vu_core_extract_single_field_value($this->course, 'node', 'field_how_to_apply'),
    ];
  }

}
