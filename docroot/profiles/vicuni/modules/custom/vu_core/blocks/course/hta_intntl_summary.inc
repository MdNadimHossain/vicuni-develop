<?php

/**
 * @file
 * Courses - How to Apply - International Summary block.
 */

/**
 * Class VuCoreHtaInternationalSummaryBlock.
 */
class VuCoreHtaIntntlSummaryCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_INTERNATIONAL;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_HE | VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - International Summary';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_international_summary';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $supplementary_information = '';
    $int_text = vu_core_extract_single_field_value($this->course, 'node', 'field_supplementary_inf_int');
    if (!empty($int_text)) {
      $supplementary_information = $int_text;
    }

    return [
      'supplementary_information' => $supplementary_information,
    ];
  }

}
