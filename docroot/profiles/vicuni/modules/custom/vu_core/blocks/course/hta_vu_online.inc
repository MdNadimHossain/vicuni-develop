<?php

/**
 * @file
 * Courses - How to apply - VU Online.
 */

/**
 * Class VuCoreHtaVuOnlineCourseBlock.
 */
class VuCoreHtaVuOnlineCourseBlock extends VuCoreCourseBlockBase {
  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - VU Online';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_vu_online';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    return $this->isVuOnline();
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $this->courseIntake = $this->getCourseIntake();

    $vtac_closed = !($this->courseIntake->isOpen('vtac') && !$this->courseIntake->openDate('vtac'));
    $class = $vtac_closed ? 'col-md-6 vu-online-container' : 'col-md-6';

    return [
      'online_link' => 'https://online.vu.edu.au/online-courses/mba?VendorLocationName=VU',
      'vu_online_class' => $class,
    ];
  }

}
