<?php

/**
 * @file
 * Domestic intakes block.
 */

/**
 * Class VuCoreCourseFeesBlock.
 */
class VuCoreDomesticIntakesCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Domestic intakes';

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_CUSTOM;

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_intakes_block';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $index_dates = $this->courseIntake->commencementDatesNext();
    $custom_dates = $this->customCourseStartDate();
    $dates = $custom_dates ? $custom_dates : $index_dates;
    // Set label for field.
    $label = 'Start date:';
    if (count($dates) > 1) {
      $label = 'Start dates:';
    }

    $content = [];

    foreach ($dates as $date) {
      $date = new DateTime($date);
      $content[] = $date->format('j F Y');
    }

    // Set content.
    if (!empty($content)) {
      $content = implode("<br>", $content);
    }

    return [
      'label' => $label,
      'dates' => $content,
    ];
  }

}
