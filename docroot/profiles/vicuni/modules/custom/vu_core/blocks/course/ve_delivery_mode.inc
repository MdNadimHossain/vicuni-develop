<?php

/**
 * @file
 * Course essential VE delivery mode block.
 */

 /**
  * Class VuCoreVeDeliveryModeCourseBlock.
  */
class VuCoreVeDeliveryModeCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'VE Delivery Mode Block';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_ve_delivery_mode';

  /**
   * {@inheritdoc}
   */
  public function variables() {

    // Get VE course delivery mode info.
    if ($this->isMultipleAud()) {
      $ve_delivery_mode_text = '';
    }
    else {
      $ve_delivery_mode_text = $this->veDeliveryMode();
    }

    return [
      've_delivery_mode_text' => $ve_delivery_mode_text,
    ];
  }

}
