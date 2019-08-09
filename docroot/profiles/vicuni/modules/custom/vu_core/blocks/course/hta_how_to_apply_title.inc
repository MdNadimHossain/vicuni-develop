<?php

/**
 * @file
 * Courses - How to Apply - title block.
 */

/**
 * Class VuCoreHtaHowToApplyTitleBlock.
 */
class VuCoreHtaHowToApplyTitleCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Title';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_how_to_apply_title';

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $this->courseIntake = $this->getCourseIntake();
    $is_open_direct = $this->courseIntake->isOpen('direct');
    $is_non_award = $this->getCourseType() === VU_CBS_TYPE_NA;
    $is_international = vu_courses_is_international_course_url();

    // Default title and short title.
    $title = $short_title = t('How to apply');

    // Get editable title.
    $editable_title = vu_core_extract_single_field_value($this->course, 'node', 'field_how_to_apply_title');

    if (!empty($editable_title)) {
      $title = $short_title = $editable_title;
    }
    elseif ($is_non_award && !$is_international && !$is_open_direct) {
      $title = $short_title = t('How to register');
    }

    return [
      'short_title' => $short_title,
      'how_to_apply_title' => $title,
    ];
  }

}
