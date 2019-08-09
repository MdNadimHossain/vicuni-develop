<?php

/**
 * @file
 * Courses - How to Apply - Apply CTA.
 */

/**
 * Class VuCoreHtaApplyCtaCourseBlock.
 */
class VuCoreHtaApplyCtaCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'HTA Apply CTA';

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_CUSTOM;

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_apply_cta';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    $isDocDegree = $this->courseAQF === VU_CBS_AQF_DOC_DEGREE;
    $isMastersResearch = $this->courseAQF === VU_CBS_AQF_MASTERS_DEGREE_RESEARCH;
    $isInternational = vu_courses_is_international_course_url();
    $isDomesticResearch = ($isMastersResearch || $isDocDegree) && !$isInternational;
    $isOpenDirect = $this->getCourseIntake()->isOpen('direct');
    $isDomesticShortCourseNoDirect = $this->courseAQF === FALSE && !($isOpenDirect || $isInternational);
    return !($isDomesticResearch || $isDomesticShortCourseNoDirect);
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    // Get course code.
    $code = vu_core_extract_single_field_value($this->course, 'node', 'field_unit_code');
    // Define button variants.
    $button_register = [
      'label' => 'Register your interest',
      'link' => '#goto-enquire-now',
      'attributes' => [
        'class' => ['btn', 'btn-tertiary', 'btn-register-interest'],
        'data-smoothscroll' => TRUE,
      ],
    ];
    $button_tafe_only = [
      'label' => 'Request a call back',
      'link' => "http://study.vu.edu.au/vu-polytechnic-request-callback?course=$code",
      'attributes' => [
        'class' => ['btn', 'btn-tertiary', 'btn-register-interest'],
        'data-smoothscroll' => TRUE,
      ],
    ];
    $button_vtac_only = [
      'label' => 'Apply',
      'link' => 'http://www.vtac.edu.au',
      'attributes' => [
        'class' => ['btn', 'btn-tertiary', 'btn-apply'],
      ],
    ];
    $button_direct_only = [
      'label' => 'Apply',
      'link' => vu_courses_apply_url($code, $this->courseIntake->isTafe()),
      'attributes' => [
        'class' => ['btn', 'btn-tertiary', 'btn-apply'],
      ],
    ];
    $button_open_modal = [
      'label' => 'Apply',
      'link' => '#OPEN-MODAL',
      'attributes' => [
        'class' => [
          'btn',
          'btn-tertiary',
          'btn-apply-modal-open',
          'js-apply-btn-modal',
        ],
      ],
    ];

    // Set course name for use in modal.
    $course_name = $this->course->title;
    $application_method_text = t('Choose your application method');

    // Checking if the course is Tafe.
    $tafeOnly = $this->isTafeOnly();

    if (vu_courses_is_international_course_url()) {
      $button = $button_open_modal;
    }
    else {
      // Define course scenario switches.
      $direct_future = $this->courseIntake->isClosed('direct') && $this->courseIntake->nextDate('direct');
      $direct_closed = $this->courseIntake->isClosed('direct') && !$direct_future;
      $direct_open = $this->courseIntake->isOpen('direct');
      $vtac_future = $this->courseIntake->isClosed('vtac') && $this->courseIntake->nextDate('vtac');
      $vtac_closed = $this->courseIntake->isClosed('vtac') && !$vtac_future;
      $vtac_open = $this->courseIntake->isOpen('vtac');

      // VTAC block variables.
      $vtac = [];
      if ($vtac_open || $vtac_future) {
        $vtac_block = new VuCoreHtaVtacOpenCourseBlock($this->course);
        $vtac_block->courseIntake = $this->getCourseIntake();
        $vtac = $vtac_block->variables();
        $vtac['modal'] = TRUE;
        $vtac['title_text'] = t('Option 1 - Apply via VTAC');
      }

      // Direct block variables.
      $direct = [];
      if ($direct_open || $direct_future) {
        $direct_block = new VuCoreHtaDirectOpenCourseBlock($this->course);
        $direct_block->courseIntake = $this->getCourseIntake();
        $direct = $direct_block->variables();
        $direct['modal'] = TRUE;
        $direct['title_text'] = t('Option 2 - Apply direct to VU');
      }

      switch (TRUE) {
        // Direct = Closed && VTAC = Closed.
        case $direct_closed && $vtac_closed:
          $button = $button_register;
          // For Tafe courses only.
          if ($tafeOnly) {
            $button = $button_tafe_only;
          }
          break;

        // Direct = Closed && VTAC = Future: Show Close Text.
        case $direct_closed && $vtac_future:
          $button = $button_register;
          // For Tafe courses only.
          if ($tafeOnly) {
            $button = $button_tafe_only;
          }
          break;

        // Direct = Closed && VTAC = Open.
        case $direct_closed && $vtac_open:
          $button = $button_vtac_only;
          break;

        // Direct = Future && VTAC = Closed.
        case $direct_future && $vtac_closed:
          $button = $button_register;
          // For Tafe courses only.
          if ($tafeOnly) {
            $button = $button_tafe_only;
          }
          break;

        // Direct = Future && VTAC = Future: Show Closed Text.
        case $direct_future && $vtac_future:
          $button = $button_register;
          // For Tafe courses only.
          if ($tafeOnly) {
            $button = $button_tafe_only;
          }
          break;

        // Direct = Future && VTAC = Open.
        case $direct_future && $vtac_open:
          $button = $button_open_modal;
          break;

        // Direct = Open && VTAC = Closed.
        case $direct_open && $vtac_closed:
          $button = $button_direct_only;
          break;

        // Direct = Open && VTAC = Future.
        case $direct_open && $vtac_future:
          $button = $button_open_modal;
          break;

        // Direct = Open && VTAC = Open.
        case $direct_open && $vtac_open:
          $button = $button_open_modal;
          break;
      }
    }

    // Victoria University online.
    $vu_online = [];

    if ($this->isVuOnline() && !vu_courses_is_international_course_url()) {

      // Logic to make sure direct option works even when closed.
      if ($direct_closed || $direct_future) {
        $direct_block = new VuCoreHtaDirectOpenCourseBlock($this->course);
        $direct_block->courseIntake = $this->getCourseIntake();
        $direct = $direct_block->variables();
        $direct['modal'] = TRUE;
        // Add register button and override values.
        $direct['register_button'] = $button_register;
        $direct['register_button']['attributes'] = [
          'class' => ['btn', 'btn-secondary', 'btn-register-interest'],
        ];
        $direct['register_button']['attributes']['role'] = 'button';
        $direct['register_button']['attributes']['data-smoothscroll'] = TRUE;
      }

      $direct['title_text'] = t('Apply for on-campus study');

      $button = $button_open_modal;

      // Add vu online block.
      $vu_online_block = new VuCoreHtaVuOnlineCourseBlock($this->course);
      $vu_online = $vu_online_block->variables();
      $vu_online['modal'] = TRUE;

      $application_method_text = t('Choose on-campus or online study');
    }

    // @codingStandardsIgnoreStart
    return [
      'button' => $button,
      'course_title' => $course_name,
      'vtac' => $vtac,
      'direct' => $direct,
      'vu_online' => $vu_online,
      'direct_closed' => $direct_closed,
      'application_method_text' => $application_method_text,
    ];
    // @codingStandardsIgnoreEnd
  }

}
