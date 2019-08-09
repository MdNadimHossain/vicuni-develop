<?php

/**
 * @file
 * Courses - How to Apply - International eBrochure block.
 */

/**
 * Class VuCoreHtaIntntlEbrochureBlock.
 */
class VuCoreHtaIntntlEbrochureCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_INTERNATIONAL;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - International eBrochure';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_international_ebrochure';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return [
      'ebrochure_url' => 'http://eaams.vu.edu.au/LAVA/MyBrochure/CreateBrochure.aspx?courseid=' . vu_core_extract_single_field_value($this->course, 'node', 'field_unit_code'),
    ];
  }

}
