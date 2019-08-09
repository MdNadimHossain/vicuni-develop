<?php

/**
 * @file
 * Course essential other locations block.
 */

/**
 * Class VuCoreHeOtherLocationsCourseBlock.
 */
class VuCoreHeOtherLocationsCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_ALL;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_HE | VU_CBS_TYPE_NA;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Other Locations Group';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_he_other_locations';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $text = vu_core_extract_single_field_value($this->course, 'node', 'field_location_other_editable');

    return [
      'other_locations_text' => $text,
    ];
  }

}
