<?php

/**
 * @file
 * Courses - Postgrad course more text block.
 */

/**
 * Class VuCoreCoursePostgradMoreTextCourseBlock.
 */
class VuCoreCoursePostgradMoreTextCourseBlock extends vuCoreCourseBlockBase {

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
  public $condAQF = VU_CBS_AQF_MASTERS_DEGREE | VU_CBS_AQF_GRAD_DIPLOMA | VU_CBS_AQF_GRAD_CERT;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Postgrad Course More Text';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_postgrad_more_text';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return [
      'hta_content' => vu_core_extract_single_field_value($this->course, 'node', 'field_how_to_apply'),
    ];
  }

}
