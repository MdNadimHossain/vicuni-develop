<?php

/**
 * @file
 * Courses - Entry Requirement International.
 */

/**
 * Class VuCoreEntryReqInternationalCourseBlock.
 */
class VuCoreEntryReqInternationalCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Entry Requirements International';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_entry_req_international';

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_INTERNATIONAL;

  /**
   * {@inheritdoc}
   */
  public function variables() {

    $international_lang_requirements = vu_core_extract_single_field_value($this->course, 'node', 'field_inter_lang_requirements', 'safe_value');
    $essential_requirements = vu_core_extract_single_field_value($this->course, 'node', 'field_additional_requirements', 'safe_value');
    $entry_req = vu_core_extract_single_field_value($this->course, 'node', 'field_entry_requirements_in');
    $college = vu_core_extract_single_field_value($this->course, 'node', 'field_college', 'title');

    $is_vicpoly = in_array($college, ['VU Polytechnic', 'Victoria Polytechnic']);
    $essential_requirements = $is_vicpoly ? '' : $essential_requirements;

    // Display important admission req for NA courses.
    $course_type = $this->getCourseType();
    if ($course_type == VU_CBS_TYPE_NA) {
      $entry_req = vu_core_extract_single_field_value($this->course, 'node', 'field_imp_admission_requirements', 'safe_value');
    }

    if (!empty($international_lang_requirements)) {
      $international_lang_requirements = filter_xss_admin($international_lang_requirements);
    }

    return [
      'entry_requirements' => $entry_req,
      'international_lang_requirements' => $international_lang_requirements,
      'essential_requirements' => $essential_requirements,
    ];
  }

}
