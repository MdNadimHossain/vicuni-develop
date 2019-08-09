<?php

/**
 * @file
 * Courses - How to Apply - VTAC open.
 */

/**
 * Class VuCoreHtaVtacOpenCourseBlock.
 */
class VuCoreHtaVtacOpenCourseBlock extends vuCoreCourseBlockBase {

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
  public static $info = 'How to Apply - VTAC open';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_hta_vtac_open';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    // Ensure the course is either open or will be in the future.
    $this->courseIntake = $this->getCourseIntake();
    if (!$this->courseIntake->isOpen('vtac') && !$this->courseIntake->openDate('vtac')) {
      return FALSE;
    }
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function variables() {
    $start_date = $this->courseIntake->openDate('vtac');
    $end_date = $dueDateMethod = NULL;

    if ($start_date) {
      $start_date = date('j F Y', $start_date);
    }

    $end_date = $this->courseIntake->closingDate('vtac');
    if ($end_date) {
      $end_date = date('j F Y', $end_date);
      $dueDateMethod = $this->courseIntake->getVtacDueDateMethod();
    }

    $vtac_codes = '';
    // If not open but we still get here, look at valid rows for course code.
    $openRows = $this->courseIntake->isOpen('vtac');
    $info = $this->courseIntake->courseEssentialsInfo($openRows);

    foreach ($info['rows'] as $key => $row) {
      if (!isset($row['vtac_course_code']) || empty($row['vtac_course_code'])) {
        unset($info['rows'][$key]);
      }
    }

    $presenter = vu_course_index_get_course_essentials_presenter($info);

    // If it's a single VTAC code for all intakes, use that.
    $vtac_codes = !empty($info['common']['vtac_course_code']) ? $presenter->singleValue($info['common']['vtac_course_code'], 'vtac_course_code') : '';

    // If it's multiple VTAC codes, use the presenter's method.
    if (empty($vtac_codes)) {
      $rows = $presenter->intakeRows();
      // Get unique vtac course codes.
      $vtac_rows = array_unique(array_column($rows, 'VTAC course code'));
      if (count($vtac_rows) > 1) {
        $vtac_codes = $presenter->singleValue(trim(implode(', ', $vtac_rows), ', '), 'vtac_course_code');
      }

      // If vtac codes are still empty.
      if (empty($vtac_codes)) {
        $vtac_codes = $presenter->singleValue(reset($info['rows'])['vtac_course_code'], 'vtac_course_code');
      }
    }

    $direct_open = $this->courseIntake->isOpen('direct');
    $direct_future = $this->courseIntake->isClosed('direct') && $this->courseIntake->nextDate('direct');
    $is_online = $this->isVuOnline();

    $vtac_class = (!$direct_open && !$direct_future && !$is_online) ? 'col-md-12' : 'col-md-6';

    return [
      'application_start_date' => $start_date,
      'application_end_date' => $end_date,
      'vtac_codes' => $vtac_codes,
      'vtac_class' => $vtac_class,
      'due_date_method' => $dueDateMethod,
    ];
  }

}
