<?php

/**
 * @file
 * Courses - How to Apply - International Contacts block.
 */

/**
 * Class VuCoreHtaIntntlContactsBlock.
 */
class VuCoreHtaIntntlContactsCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_INTERNATIONAL;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - International Contacts';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_international_contacts';

}
