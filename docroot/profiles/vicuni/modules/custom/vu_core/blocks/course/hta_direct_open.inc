<?php

/**
 * @file
 * Courses - How to Apply - Direct open.
 */

/**
 * Class VuCoreHtaDirectOpenCourseBlock.
 */
class VuCoreHtaDirectOpenCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_ALL;

  /**
   * {@inheritdoc}
   */
  public static $info = 'How to Apply - Direct open';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_direct_open';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Ensure the course is either open or will be in the future.
    $this->courseIntake = $this->getCourseIntake();
    if (!$this->courseIntake->isOpen('direct') && !$this->courseIntake->openDate('direct')) {
      return FALSE;
    }
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $start_date = $this->courseIntake->openDate('direct');
    $end_date = NULL;
    $vtac_open = $this->courseIntake->isOpen('vtac');
    if ($start_date) {
      $start_date = date('j F Y', $start_date);
    }
    $end_date = $this->courseIntake->closingDate('direct');
    if ($end_date) {
      $end_date = date('j F Y', $end_date);
    }

    $college = vu_core_extract_single_field_value($this->course, 'node', 'field_college', 'title');
    $is_vicpoly = in_array($college, ['VU Polytechnic', 'Victoria Polytechnic']);

    // Should we be looking for next commencement date here
    // or current commencement date?.
    // Updated logic in commencementDateNext(). Check if it is needed.
    $intake_date = $this->courseIntake->commencementDateNext();
    if (!is_null($intake_date)) {
      $intake_date = new DateTime($intake_date);
      $intake_date = $intake_date->format('j F Y');

      // Check for overriden date.
      $customDateOverride = $this->customCourseStartDateNext();
      if (!empty($customDateOverride)) {
        $intake_date = $customDateOverride;
      }
    }

    $direct_open = $this->courseIntake->isOpen('direct');
    $is_vu_online = $this->isVuOnline();

    $button_text = t('Apply direct to VU');
    if ($is_vu_online && $direct_open) {
      $button_text = t('Apply for on-campus study');
    }

    $after_apply_block = new VuCoreHtaAfterYouApplyCourseBlock($this->course);
    $after_apply_content = $after_apply_block->view();
    $after_apply_text = '';
    if (isset($after_apply_content['content'])) {
      $after_apply_text = $after_apply_content['content'];
    }

    $vtac_open = $this->courseIntake->isOpen('vtac') || $this->courseIntake->openDate('vtac');
    $is_online = $this->isVuOnline();
    $direct_class = (!$vtac_open && !$is_online) ? 'col-md-12' : 'col-md-6';

    $direct_title = t('Apply direct to VU');
    if ($is_online) {
      $direct_title = t('Apply for on-campus study');
    }

    $vu_student = new VuCoreHtaAlreadyVuStudentCourseBlock($this->course);
    $vu_student_content = $vu_student->view();
    $vu_student_text = '';
    if (isset($vu_student_content['content'])) {
      $vu_student_text = $vu_student_content['content'];
    }

    $supplementary_date_info = vu_core_extract_single_field_value($this->course, 'node', 'field_supplementary_date_info');

    return [
      'application_start_date' => $start_date,
      'application_end_date' => $end_date,
      'intake_date' => $intake_date,
      'vtac_open' => $vtac_open,
      'direct_link' => vu_courses_apply_url(vu_core_extract_single_field_value($this->course, 'node', 'field_unit_code'), $this->courseIntake->isTafe()),
      'button_text' => $button_text,
      'is_vu_online' => $is_vu_online,
      'after_apply' => $after_apply_text,
      'direct_class' => $direct_class,
      'direct_title' => $direct_title,
      'is_vicpoly' => $is_vicpoly,
      'vu_student' => $vu_student_text,
      'supplementary_date_info' => $supplementary_date_info,
    ];
  }

}
