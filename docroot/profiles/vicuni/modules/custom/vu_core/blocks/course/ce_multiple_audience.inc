<?php

/**
 * @file
 * Course essential multiple audience group.
 */

define('START_TEXT', 'Available for ');

/**
 * Class VuCoreStudentProfileCourseBlock.
 */
class VuCoreCeMultipleAudienceCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_ALL;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_VE;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Multiple Audience Group';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_ce_multiple_audience';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return vu_core_get_multiple_audience_data($this->course);
  }

}

/**
 * Get multiple audience group info.
 */
function vu_core_get_multiple_audience_data($course) {
  $output = '';

  if (!vu_courses_is_international_course_url()) {
    $multiple_aud = field_get_items('node', $course, 'field_multiple_audience_group');

    $val = [];
    if ($multiple_aud) {
      foreach ($multiple_aud as $item) {
        $val[] = $item['value'];
      }
    }

    $target = [
      'International Off-Shore',
      'Apprenticeship',
      'Traineeship',
      'Industry Group',
      'VETiS',
    ];

    $check_multi = array_intersect($val, $target);

    if (count($check_multi) > 0) {
      // Implode with comma & add "or" before the last element.
      $last = array_pop($check_multi);
      $string = count($check_multi) ? implode(", ", $check_multi) . " or " . $last : $last;
      $temp_text = START_TEXT . $string;

      // Changing words in full form.
      $word_change_from = ['VETiS', 'Industry Group'];
      $word_change_to = ['VET Delivered to Secondary Schools', 'Industry'];
      $output = str_replace($word_change_from, $word_change_to, $temp_text);
    }
  }

  return [
    'off_campus_text' => $output,
  ];
}
