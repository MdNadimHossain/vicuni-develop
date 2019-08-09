<?php

/**
 * @file
 * Get sensible information from the Course Index.
 */

require_once 'CourseIntakeList.interface.php';
require_once 'AbstractCourseIntakeList.class.php';
require_once 'vu_course_index.functions.php';

/**
 * Object encapsulating a set of course index rows.
 */
class CourseIntakeList extends AbstractCourseIntakeList implements CourseIntakeListInterface {
  // 23:59:59.
  const END_OF_DAY = 86399;

  /**
   * Does the course have a VTAC entry method?
   *
   * @return bool
   *         Does the course have a VTAC entry method?
   */
  public function isVtac() {
    return $this->hasEntryMethod('VTAC');
  }
  /**
   * Does the course have a direct entry method?
   *
   * @return bool
   *         Does the course have a direct entry method?
   */
  public function isDirect() {
    // VU connect bug means that no "DIRECT" rows come through
    // while it's VTAC season.
    return $this->hasEntryMethod('DIRECT') || $this->hasEntryMethod('VTAC');
  }

  /**
   * Does the course have an apprenticeship entry method?
   *
   * @return bool
   *         Does the course have an apprenticeship entry method?
   */
  public function isApprenticeship() {
    return $this->hasEntryMethod('APP-TRAIN');
  }

  /**
   * Is this a VE/TAFE course?
   *
   * @return bool
   *         Is this a VE/TAFE course?
   */
  public function isTafe() {
    return $this->hasSector('VET');
  }

  /**
   * Is this an undergraduate course?
   *
   * @return bool
   *         Is this an undergraduate course?
   */
  public function isUndergraduate() {
    return $this->hasLevel('HE-UNDGRD');
  }

  /**
   * Is this a postgraduate course?
   *
   * @return bool
   *         Is this a postgraduate course?
   */
  public function isPostgraduate() {
    return $this->hasLevel('HE-PGRAD');
  }

  /**
   * Course level.
   *
   * @return string
   *         Undergraduate, Postgraduate, TAFE or empty string.
   */
  public function level() {
    return $this->isPostgraduate() ? 'Postgraduate' : ($this->isUndergraduate() ? 'Undergraduate' : ($this->isTafe() ? 'TAFE' : ''));
  }

  /**
   * Is this a Higher Ed (undergraduate or postgraduate) course?
   *
   * @return bool
   *         Is this a Higher Ed (undergraduate or postgraduate) course?
   */
  public function isHigherEd() {
    return $this->isUndergraduate() || $this->isPostgraduate();
  }

  /**
   * Find the next closing date.
   *
   * @return string
   *         UNIX timestamp of next closing date.
   */
  public function nextDate($entry_method = NULL) {
    $dates = array_flip($this->dates($entry_method));
    return array_shift($dates);
  }

  /**
   * Find the next closing date tyoe.
   *
   * @return string
   *         string.
   */
  public function getVtacDueDateMethod() {
    $dates = array_flip($this->dates('vtac'));

    $key = key($dates);
    $map = ['vtac_timely_date' => 'timely', 'vtac_late_date' => 'late', 'vtac_very_late_date' =>  'very late'];

    return isset($map[$key]) ? $map[$key] : '';
  }

  /**
   * Find the next opening date.
   *
   * @return string
   *         UNIX timestamp of next open date.
   */
  public function openDate($entry_method = NULL) {
    $dates = array_flip($this->applicationOpenDates($entry_method));
    return array_shift($dates);
  }

  /**
   * Find the next commencement date.
   *
   * @return string
   *         UNIX timestamp of next commencement date.
   */
  public function commencementDateNext() {
    $dates = $this->commencementDates();
    return array_shift($dates);
  }

  /**
   * Find the next 3 commencement dates.
   *
   * @return string
   *         UNIX timestamp of next commencement date.
   */
  public function commencementDatesNext() {
    $dates = $this->commencementDates();
    return array_slice(array_unique($dates), 0, 3);
  }

  /**
   * Return the date applications open for this intake.
   *
   * @param string|NULL $entry_method
   *        If supplied only matching row will be referenced.
   *
   * @return array
   *         Application opening dates.
   */
  public function applicationOpenDates($entry_method = NULL) {
    // For now, please don't kill me, it's just that it should check
    // that ANY open date has passed if there's no specific entry method
    // actually think there's a problem in the "dates" method for this too.
    if ($entry_method === NULL) {
      return array();
    }

    if ($this->isVtac() && $entry_method == 'vtac') {
      $start_field = 'vtac_open_date';
    }
    else {
      $start_field = 'admissions_start_date';
    }

    $priority_start_field = $entry_method === 'vtac' ? 'vtac_start_date' : 'application_start_date';

    $date_check = function ($intake) use ($start_field, $priority_start_field) {
      $date = array();
      if (!empty($intake[$priority_start_field])) {
        $t = strtotime($intake[$priority_start_field]);
        if ($t) {
          if ($t > time()) {
            $date[$t] = $priority_start_field;
          }
          return $date;
        }
      }

      if (!empty($intake[$start_field])) {
        $t = strtotime($intake[$start_field]);
        if ($t && $t > time()) {
          $date[$t] = $start_field;
        }
      }

      return $date;
    };

    $dates = $this->validIntakeIterate($entry_method, $date_check);
    ksort($dates);

    return $dates;
  }

  /**
   * Future closing dates for the course.
   *
   * @return array
   *         Key is numeric timestamp, value is the name of the column.
   *         Sorted ascending by key.
   */
  public function dates($entry_method = NULL) {
    if (!is_null($entry_method)) {
      $entry_method = strtolower($entry_method);
    }

    $fields = array();
    if (($this->isDirect() || $this->isApprenticeship()) && $entry_method !== 'vtac') {
      $fields = array_merge($fields, array(
        'early_admissions_end_date',
        'admissions_end_date',
      ));
    }
    if ($this->isVtac() && $entry_method !== 'direct' && $entry_method !== 'app-train') {
      $fields = array_merge($fields, array(
        'vtac_timely_date',
        'vtac_late_date',
        'vtac_very_late_date',
      ));
    }

    // If it's a VTAC course, we need to check the vtac_end_date override field,
    // otherwise (direct/app-train) use the application_end_date overrides.
    // The boolean value specifies if it's the "final" override.
    // If it's the 'early' override the next date in the normal date field
    // should continue.
    $priority_fields = $entry_method === 'vtac' ? array('vtac_end_date' => TRUE) : array(
      'early_application_end_date' => FALSE,
      'application_end_date' => TRUE,
    );

    $date_check = function ($intake) use ($fields, $priority_fields) {
      $override_set = FALSE;
      $dates = array();
      foreach ($priority_fields as $field_name => $final) {
        // If it's the final value, we need to know that it's been set,
        // even if the date is in the past.
        if ($final && !empty($intake[$field_name])) {
          $override_set = TRUE;
        }
        $time = strtotime($intake[$field_name]);

        if ($time + CourseIntakeList::END_OF_DAY > time()) {
          $dates[$time] = $field_name;
        }
      }
      // Override takes precedence so no need to worry about other dates.
      if ($override_set) {
        return $dates;
      }

      foreach ($fields as $field_name) {
        $time = strtotime($intake[$field_name]);
        if ($time + CourseIntakeList::END_OF_DAY > time()) {
          $dates[$time] = $field_name;
        }
      }
      return $dates;
    };

    $dates = $this->validIntakeIterate($entry_method, $date_check);
    ksort($dates);
    return $dates;
  }

  /**
   * Future commencement dates.
   *
   * @return array
   *         Array of commencement dates.
   */
  public function commencementDates() {
    $dates = [];
    foreach ($this->intakes as $intake) {
      if (!is_null($intake['course_srt_dt']) && new DateTime($intake['course_srt_dt']) > new DateTime() ) {
        // Added condition in to filter passed intakes.
        $field = !empty($intake['application_end_date']) ? 'application_end_date' : 'admissions_end_date';
        if (new DateTime($intake[$field]) > new DateTime()) {
          // Added condition in to filter vu online courses.
          if ($intake['location'] != 'ZV') {
            $dates[$intake['id']] = $intake['course_srt_dt'];
          }
        }
      }
    }

    asort($dates);
    return $dates;
  }

  /**
   * Iterate over the valid/matching intakes and perform function $callback.
   *
   * @param string|NULL $entry_method
   *        If string supplied only matching rows are referenced.
   * @param callable $callback
   *        A function that transforms and returns an intake row.
   *
   * @return array
   *         The transformed intake rows.
   */
  protected function validIntakeIterate($entry_method, callable $callback) {
    $return = [];
    $intakes = [];

    $commencements = $this->commencementDates();
    if ($commencements) {
      foreach (array_keys($commencements) as $id) {
        if (isset($this->intakes[$id])) {
          $intakes[$id] = $this->intakes[$id];
        }
      }
    }
    else {
      $intakes = $this->intakes;
    }

    foreach ($intakes as $intake) {
      // Ensure intake is offered.
      if ($intake['course_intake_status'] !== 'OFFERED') {
        continue;
      }
      // Make sure we match entry method, if specified.
      $aem = strtolower($intake['application_entry_method']);

      // Don't need to do this 38 times.
      if (!is_null($entry_method) && (($entry_method === 'direct' && $aem !== 'vtac' && $aem !== 'direct') ||

          // VU connect bug means no "DIRECT" rows come through
          // while it's VTAC season.
          ($entry_method !== 'vtac' && $entry_method !== 'direct' && $aem !== $entry_method) ||

          // This really now only applies to app-train.
          ($entry_method === 'vtac' && $intake['is_vtac_course'] !== 'Y'))
      ) {
        continue;
      }

      // Merge the return array with the previous values.
      $result = $callback($intake);
      if ($commencements) {
        return $result;
      }
      $return += $result;
    }

    return $return;
  }

  /**
   * Is the course currently open?
   *
   * Optionally filtered by application method.
   *
   * @param string|NULL $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course currently open?
   */
  public function isOpen($entry_method = NULL) {
    return !$this->openDate($entry_method) && !!$this->nextDate($entry_method);
  }

  /**
   * Is the course currently closed?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course currently closed?
   */
  public function isClosed($entry_method = NULL) {
    return !$this->isOpen($entry_method);
  }

  /**
   * Does the course have an ongoing intake?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Does the course have an ongoing intake?
   */
  public function isOngoing($entry_method = NULL) {
    return FALSE;
  }

  /**
   * The furthest course closing date as a string.
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return string
   *         The furthest course closing date.
   */
  public function closingDate($entry_method = NULL) {
    return $this->nextDate($entry_method);
  }

  /**
   * Does the course have online application?
   *
   * Note that until Increment 2 of the TAFE Automation project
   * (July 2016) apprenticeship courses should not be regarded
   * as available for online admission regardless of the course
   * index data.
   *
   * Once increment 2 has been delivered the `!$this->isApprenticeship()`
   * check should be removed.
   *
   * @return bool
   *         Does the course have online application?
   */
  public function hasOnlineApplication() {
    return $this->test(function($intake) {
      return strtoupper($intake['is_admissions_centre_available']) === 'Y';
    });
  }

  /**
   * Is the course offered part time?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course offered part time?
   */
  public function isPartTime($entry_method = NULL) {
    return $entry_method ? $this->filterByEntryMethod($entry_method)
      ->isPartTime() : $this->hasMode('PT');
  }

  /**
   * Is the course offered full time?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course offered full time?
   */
  public function isFullTime($entry_method = NULL) {
    return $entry_method ? $this->filterByEntryMethod($entry_method)
      ->isFullTime() : $this->hasMode('FT');
  }

  /**
   * Is the course fee type CSP?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course fee type CSP?
   */
  public function isFeeTypeCsp($entry_method = NULL) {
    if ($this->isTafe()) {
      return FALSE;
    }
    return $entry_method ? $this->filterByEntryMethod($entry_method)
      ->isFeeTypeCsp() : $this->hasFeeType(self::FEE_TYPE_CSP);
  }

  /**
   * Is the course fee type full fee?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course fee type full fee?
   */
  public function isFeeTypeFullFee($entry_method = NULL) {
    if ($this->isTafe()) {
      return FALSE;
    }
    return $entry_method ? $this->filterByEntryMethod($entry_method)
      ->isFeeTypeFullFee() : $this->hasFeeType(self::FEE_TYPE_FULL);
  }

  /**
   * Get the fee type for this course.
   *
   * @return string
   *         Fee type.
   */
  public function getFeeType() {
    if ($this->isTafe()) {
      return FALSE;
    }

    $fee_types = array();

    if ($this->hasFeeType(self::FEE_TYPE_CSP)) {
      $fee_types[] = self::FEE_TYPE_CSP;
    }
    if ($this->hasFeeType(self::FEE_TYPE_FULL)) {
      $fee_types[] = self::FEE_TYPE_FULL;
    }

    return implode(', ', $fee_types);
  }

  /**
   * Is the course fee type both CSP and full fee?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course fee type both CSP and full fee?
   */
  public function isFeeTypeBothCspAndFullFee($entry_method = NULL) {
    return $this->isFeeTypeFullFee($entry_method) && $this->isFeeTypeCsp($entry_method);
  }

  /**
   * Is the course only offered full time?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course only offered full time?
   */
  public function isOnlyFullTime($entry_method = NULL) {
    return $entry_method ? $this->filterByEntryMethod($entry_method)
      ->isOnlyFullTime() : $this->isFullTime() && !($this->isPartTime() || $this->is_flex_ed());
  }

  /**
   * Array of supplementary form codes for this set of intakes.
   *
   * @return array
   *         Unique supplementary form codes.
   */
  public function supplementaryForms() {
    return $this->getForms('supplementary_forms');
  }

  /**
   * Array of referee report form codes for this set of intakes.
   *
   * @return array
   *         Unique referee report form codes.
   */
  public function refereeReports() {
    return $this->getForms('referee_reports');
  }

  /**
   * Information for the 'Course essentials' section of a course page.
   *
   * @param bool $open
   *        If true, only use info from open rows.
   * @param array $exclude_fields
   *        Names of fields you don't want to get in the result.
   *
   * @return array
   *         Information for the 'Course essentials' section of a course page.
   *         This is an array with two keys:
   *         - common: contains a hash of all values that are the same for rows.
   *         - rows: contains an array of hashes of distinct values.
   */
  public function courseEssentialsInfo($open = TRUE, $exclude_fields = array()) {
    if ($open) {
      return $this->getOpen()->courseEssentialsInfo(FALSE, $exclude_fields);
    }

    // These are the fields we need - the default set
    // excluding any the user doesn't want.
    $field_names = array_diff(array(
      'specialisation_name',
      'vtac_course_code',
      'location',
      'application_entry_method',
      'is_vtac_course',
      'attendance_type',
      'place_type',
    ), $exclude_fields);
    $field_names = array_combine($field_names, $field_names);

    // This is what we're building:
    // - common: a hash of common values
    // - rows:   an array of hashes of distinct values.
    $common = array();
    $rows = array();

    // Any fields with only one unique value we pull out into $info['common'].
    // We remove this from our field_names so it doesn't show up again in rows.
    foreach ($field_names as $field_name) {
      $field_values = $this->getUniqueValues($field_name, $open);
      if (count($field_values) === 1) {
        $common[$field_name] = current($field_values);
        unset($field_names[$field_name]);
      }
    }

    // Now we want to make rows for each of the fields that aren't common,
    // grouped on the key generated for this row by
    // `course_essentials_info_row_key`.
    $rows = $this->reduce(function ($rows, $row) use ($field_names) {
      $row = array_intersect_key($row, $field_names);
      $key = $this->courseEssentialsInfoRowKey($row, count($rows));
      if (isset($rows[$key])) {
        // Combine with an existing row.
        foreach ($row as $field_name => $new_value) {
          $existing_value = $rows[$key][$field_name];
          if ($existing_value !== $new_value) {
            if (!is_array($existing_value)) {
              $rows[$key][$field_name] = array(
                $existing_value => $existing_value,
              );
            }
            $rows[$key][$field_name][$new_value] = $new_value;
          }
        }
      }
      else {
        // No existing row, just add one.
        $rows[$key] = $row;
      }
      return $rows;
    }, NULL, array());

    // Grouping may have produced new common values (e.g. place_type FT, PT)
    // so now we clean those up.
    if (count($rows)) {
      $row = current($rows);
      $grouped_fields = array_reduce(array_keys($row), function ($acc, $key) use ($row) {
        if (is_array($row[$key])) {
          $acc[] = $key;
        }
        return $acc;
      }, array());
      foreach ($grouped_fields as $field_name) {
        $values = array_values(array_unique(array_map(function ($row) use ($field_name) {
          return $row[$field_name];
        }, $rows), SORT_REGULAR));
        if (count($values) === 1) {
          $common[$field_name] = current($values);
          $rows = array_map(function ($row) use ($field_name) {
            unset($row[$field_name]);
            return $row;
          }, $rows);
        }
      }
    }

    return array('common' => $common, 'rows' => $rows);
  }

  /**
   * List of unique locations from this intake list.
   *
   * @param bool $open
   *        If true only use info from open rows.
   *
   * @return array
   *         Unique locations.
   */
  public function locations($open = TRUE) {
    return $this->getUniqueValues('location', $open);
  }

  /**
   * Construct a key for a course essentials info row.
   *
   * This allows multiple rows to be 'collapsed' into one when
   * they share values in certain columns.
   *
   * @param array $row
   *        The course essentials row to use.
   * @param string $default
   *        A default key to use if one cannot be constructed.
   *
   * @return string
   *         Key for a course essentials info row.
   */
  private function courseEssentialsInfoRowKey($row, $default) {
    $key_names = array(
      'specialisation_name',
      'vtac_course_code',
      'place_type',
      'is_vtac_course',
      'location',
    );
    $key = '';
    foreach ($key_names as $key_name) {
      if (isset($row[$key_name])) {
        $key .= $row[$key_name];
      }
    }
    return empty($key) ? $default : $key;
  }

  /**
   * Build a new CourseIntakeList with only the open rows of this one.
   *
   * @return CourseIntakeList
   *         A new CourseIntakeList constructed from the open rows
   *         of the receiver.
   */
  private function getOpen() {
    return $this->filter(function ($intake) {
      $key = isset($intake['id']) ? $intake['id'] : 0;
      $_intake_list = new CourseIntakeList([$key => $intake]);
      return $_intake_list->isOpen();
    });
  }

  /**
   * Return the deduplicated list of unique values for a column.
   *
   * @param array $field_name
   *        The column to get values from.
   * @param bool $open
   *        If true, only reference open rows.
   *
   * @return array
   *         The deduplicated list of unique values for the column.
   */
  private function getUniqueValues($field_name, $open = TRUE) {
    $target = $open ? $this->getOpen() : $this;
    return array_unique($target->pluck($field_name));
  }

  /**
   * The list of unique study modes for this course.
   *
   * @param bool $open
   *        If true, only reference open rows.
   *
   * @return array
   *         The unique study modes for this course.
   */
  public function studyModes($open = TRUE) {
    $raw_modes = $this->getUniqueValues('attendance_type', $open);
    $map = ['FT' => 'full time', 'PT' => 'part time'];
    return array_map(function ($mode) use ($map) {
      return $map[$mode];
    }, $raw_modes);
  }

  /**
   * Does this course accept expressions of interest as application method?
   *
   * @return bool
   *         Does this course accept expressions of interest?
   */
  public function expressionOfInterest() {
    return $this->test(function ($intake) {
      return $intake['expression_of_interest'] == 'Y';
    });
  }

  /**
   * Return an array of of referee report or supplementary form codes.
   *
   * If you want the list of supplementary forms call
   * $course_intake_list->supplementaryForms().
   * For the list of referee_report forms call
   * $course_intake_list->refereeReports().
   *
   * @param string $type
   *        Value can be 'referee_reports' or 'supplementary_forms'.
   *
   * @return array
   *         Unique form codes.
   */
  private function getForms($type) {
    return array_filter($this->reduce(function ($acc, $form) {
      $form = unserialize($form);
      if (property_exists($form, 'item')) {
        switch (gettype($form->item)) {
          case 'string':
            $acc[$form->item] = $form->item;
            break;

          case 'array':
            $acc = array_merge($acc, array_combine($form->item, $form->item));
            break;
        }
      }
      return $acc;
    }, $type, array()));
  }

  /**
   * Does this course have the given level?
   *
   * @param string $level
   *        VE-DOM|HE-UNDGRD|HE-PGRD.
   *
   * @return bool
   *         Does this course have the given level?
   */
  protected function hasLevel($level) {
    return $this->test(function ($intake) use ($level) {
      return $intake['admissions_category'] == $level;
    });
  }

  /**
   * Does this course have the given sector code?
   *
   * @param string $sector
   *        VE|HE.
   *
   * @return bool
   *         TRUE if course is given sector.
   */
  protected function hasSector($sector) {
    return $this->test(function ($intake) use ($sector) {
      return $intake['sector_code'] == $sector;
    });
  }

  /**
   * Does this course have the given entry method?
   *
   * @param string $entry_method
   *        VTAC|DIRECT|APP-TRAIN.
   *
   * @return bool
   *         Does this course have the given entry method?
   */
  protected function hasEntryMethod($entry_method) {
    return $this->test($this->methodTest($entry_method));
  }

  /**
   * Does this course have the given entry method?
   *
   * @param string $fee_type
   *        HEFULLFEE|GOVTFUND.
   *
   * @return bool
   *         Does this course have the given entry method?
   */
  protected function hasFeeType($fee_type) {
    if ($this->isTafe()) {
      return FALSE;
    }
    return $this->test(function ($intake) use ($fee_type) {
      return stripos($intake['place_type'], $fee_type) !== FALSE ? $intake['place_type'] : FALSE;
    });
  }

  /**
   * Construct a CourseIntakeList only from rows matching $entry_method.
   *
   * @param string $entry_method
   *         VTAC|DIRECT|APP-TRAIN.
   *
   * @return CourseIntakeList
   *         New CourseIntakeList with only rows matching $entry_method.
   */
  protected function filterByEntryMethod($entry_method) {
    $this->filterEntryMethod = $entry_method;
    return $this->filter($this->methodTest($entry_method));
  }

  /**
   * Construct a function to test whether an intake matches the supplied method.
   *
   * @param string $entry_method
   *        VTAC|DIRECT|APP-TRAIN.
   *
   * @return callable
   *         A function to test whether an intake matches the supplied method.
   */
  protected function methodTest($entry_method) {
    $entry_method = strtoupper($entry_method);
    return function ($intake) use ($entry_method) {
      switch ($entry_method) {
        case 'DIRECT':
        case 'APP-TRAIN':
          return strpos(strtoupper($intake['application_entry_method']), $entry_method) !== FALSE;

        case 'VTAC':
          return $intake['is_vtac_course'] == 'Y';
      }
    };
  }

  /**
   * Does this course have the given study mode?
   *
   * @param string $mode
   *        PT|FT.
   *
   * @return bool
   *         Does this course have the given study mode?
   */
  protected function hasMode($mode) {
    return $this->test(function ($intake) use ($mode) {
      return !empty($intake["attendance_type"]) && $intake["attendance_type"] == $mode;
    });
  }

}
