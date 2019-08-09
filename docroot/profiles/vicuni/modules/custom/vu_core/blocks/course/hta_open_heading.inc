<?php

/**
 * @file
 * Courses - How to apply - Open - Heading.
 */

/**
 * Class VuCoreOpenHeadingCourseBlock.
 */
class VuCoreHtaOpenHeadingCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_HE | VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_YES;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Open - Heading';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_open_heading';

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $is_online = $this->isVuOnline();
    $direct_future = $this->courseIntake->isClosed('direct') && $this->courseIntake->nextDate('direct');
    $direct_open = $this->courseIntake->isOpen('direct');

    // Set default title.
    $title = t("When you're ready:");
    if ($is_online && ($direct_open || $direct_future)) {
      $title = t('Apply for on-campus study');
    }
    elseif ($is_online && !$direct_open && !$direct_future) {
      $title = '';
    }

    return [
      'title' => $title,
      'is_vu_online' => $is_online,
    ];
  }

}
