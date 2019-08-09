<?php

/**
 * @file
 * Courses - Materials fee.
 */

/**
 * Class VuCoreMaterialsFeeCourseBlock.
 */
class VuCoreMaterialsFeeCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_INTERNATIONAL;

  /**
   * {@inheritdoc}
   */
  public static $info = 'VU Materials Fee';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_materials_fee';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $materials_fee = vu_core_extract_single_field_value($this->course, 'node', 'field_materials_fee');

    return [
      'materials_fee' => $materials_fee,
    ];
  }

}
