<?php

/**
 * @file
 * Courses - How to Apply - Applications due date.
 */

define('VU_CORE_HTA_CTA_TEXT_CLOSED', 'Applications are not being taken at this time.');
define('VU_CORE_HTA_CTA_TAFE_TEXT_CLOSED', 'For information on the next course start date, request a call back.');
define('VU_CORE_HTA_CTA_TAFE_TEXT_OPEN', 'Applications for this course are currently being accepted.');
define('VU_CORE_HTA_CTA_DIRECT_TEXT_OPEN', 'Direct applications are due on <strong>@date</strong>');
define('VU_CORE_HTA_CTA_VTAC_TEXT_OPEN', 'VTAC applications are due on <strong>@date</strong>');
define('VU_CORE_HTA_DUAL_TEXT_OPEN', "View <a href='#goto-how-to-apply' data-smoothscroll> How to apply</a>");

/**
 * Class VuCoreHtaAppDueDateCourseBlock.
 */
class VuCoreHtaAppDueDateCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'HTA Applications due date';

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_CUSTOM;

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_application_due';

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

    if (vu_courses_is_international_course_url()) {
      $text = t('We are currently accepting applications for this course.');
    }
    else {
      $sup_text = vu_core_extract_single_field_value($this->course, 'node', 'field_sup_application_info');
      // Define course scenario switches.
      $direct_future = $this->courseIntake->isClosed('direct') && $this->courseIntake->nextDate('direct');
      $direct_closed = $this->courseIntake->isClosed('direct') && !$direct_future;
      $direct_open = $this->courseIntake->isOpen('direct');
      $vtac_future = $this->courseIntake->isClosed('vtac') && $this->courseIntake->nextDate('vtac');
      $vtac_closed = $this->courseIntake->isClosed('vtac') && !$vtac_future;
      $vtac_open = $this->courseIntake->isOpen('vtac');

      // Checking if the course is Tafe.
      $tafeOnly = $this->isTafeOnly();

      $date = '';
      switch (TRUE) {
        // Direct = Closed && VTAC = Closed.
        case $direct_closed && $vtac_closed:
          $text = VU_CORE_HTA_CTA_TEXT_CLOSED;
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_CLOSED;
          }
          break;

        // Direct = Closed && VTAC = Future: Show Close Text.
        case $direct_closed && $vtac_future:
          $text = VU_CORE_HTA_CTA_TEXT_CLOSED;
          $date = date('j F Y', $this->courseIntake->openDate('vtac'));
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_CLOSED;
          }
          break;

        // Direct = Closed && VTAC = Open.
        case $direct_closed && $vtac_open:
          $text = VU_CORE_HTA_CTA_VTAC_TEXT_OPEN;
          $date = date('j F Y', $this->courseIntake->nextDate('vtac'));
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_OPEN;
          }
          break;

        // Direct = Future && VTAC = Closed.
        case $direct_future && $vtac_closed:
          $text = VU_CORE_HTA_CTA_TEXT_CLOSED;
          $date = date('j F Y', $this->courseIntake->openDate('direct'));
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_CLOSED;
          }
          break;

        // Direct = Future && VTAC = Future: Show Closed Text.
        case $direct_future && $vtac_future:
          $text = VU_CORE_HTA_CTA_TEXT_CLOSED;
          $firstOpenDate = min(array_filter([
            $this->courseIntake->openDate('vtac'),
            $this->courseIntake->openDate('direct'),
          ]));
          $date = date('j F Y', $firstOpenDate);
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_CLOSED;
          }
          break;

        // Direct = Future && VTAC = Open.
        case $direct_future && $vtac_open:
          $text = VU_CORE_HTA_DUAL_TEXT_OPEN;
          $date = date('j F Y', $this->courseIntake->nextDate('vtac'));
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_OPEN;
          }
          break;

        // Direct = Open && VTAC = Closed.
        case $direct_open && $vtac_closed:
          $text = VU_CORE_HTA_CTA_DIRECT_TEXT_OPEN;
          $date = date('j F Y', $this->courseIntake->nextDate('direct'));
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_OPEN;
          }
          break;

        // Direct = Open && VTAC = Future.
        case $direct_open && $vtac_future:
          $text = VU_CORE_HTA_DUAL_TEXT_OPEN;
          $date = date('j F Y', $this->courseIntake->nextDate('direct'));
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_OPEN;
          }
          break;

        // Direct = Open && VTAC = Open.
        case $direct_open && $vtac_open:
          $text = VU_CORE_HTA_DUAL_TEXT_OPEN;
          $firstDueDate = min(array_filter([
            $this->courseIntake->nextDate('vtac'),
            $this->courseIntake->nextDate('direct'),
          ]));
          $date = date('j F Y', $firstDueDate);
          // For Tafe courses only.
          if ($tafeOnly) {
            $text = VU_CORE_HTA_CTA_TAFE_TEXT_OPEN;
          }
          break;
      }
    }

    // Victoria University online.
    if ($this->isVuOnline() && !vu_courses_is_international_course_url()) {

      // Logic to make sure direct option works even when closed.
      if ($direct_closed) {
        $text = t('Applications to study online <strong>always open</strong>');
      }
      elseif ($direct_future) {
        $text = VU_CORE_HTA_DUAL_TEXT_OPEN;
      }
      else {
        $text = VU_CORE_HTA_DUAL_TEXT_OPEN;
      }
    }

    // Check if course index start dates are overriden.
    if ($text == VU_CORE_HTA_CTA_DIRECT_TEXT_OPEN || $text == VU_CORE_HTA_CTA_VTAC_TEXT_OPEN) {
      // Should we be looking for next commencement date here
      // or current commencement date?.
      // Updated logic in commencementDateNext(). Check if it is needed.
      $intake_date = $this->courseIntake->commencementDateNext();
      if (!is_null($intake_date)) {
        $intake_date = new DateTime($intake_date);
        $intake_date = $intake_date->format('j F Y');
      }

      $customDateOverride = $this->customCourseStartDateNext();
      if (!empty($customDateOverride)) {
        $intake_date = $customDateOverride;
      }
    }

    // @codingStandardsIgnoreStart
    return [
      'text' => t($text, ['@date' => $date]),
      'sup_text' => $sup_text,
      'intake_date' => $intake_date,
    ];
    // @codingStandardsIgnoreEnd
  }

}
