<?php

/**
 * @file
 * Courses - How to Apply - Research Course Summary block.
 */

/**
 * Class VuCoreHtaRsrchCourseSummaryBlock.
 */
class VuCoreHtaRsrchCourseSummaryCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_HE;

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_MASTERS_DEGREE_RESEARCH | VU_CBS_AQF_DOC_DEGREE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Research Course Summary';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_research_course_summary';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return [
      'hta_content' => vu_core_extract_single_field_value($this->course, 'node', 'field_how_to_apply'),
    ];
  }

}
