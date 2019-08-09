<?php

/**
 * @file
 * Tests for CourseIntakeList.
 */

require 'CourseIntakeList.interface.php';
require 'AbstractCourseIntakeList.class.php';
require 'CourseIntakeList.class.php';

/**
 * Tests for CourseIntakeList.
 */
class CourseIntakeListTest extends PHPUnit_Framework_TestCase {

  /**
   * Construct a fake intake row for testing.
   *
   * @param array $fields
   *        Overrides for the default values.
   *
   * @return array
   *         Fake intake row.
   */
  private function dummyIntake($fields = array()) {
    return array_merge(array(
      'application_entry_method' => 'DIRECT',
      'course_intake_status' => 'OFFERED',
      'location' => 'F',
      'specialisation_name' => '',
      'early_application_end_date' => '',
      'application_end_date' => '',
      'vtac_end_date' => '',
    ), $fields);
  }

  /**
   * Construct a fake open VTAC intake row for testing.
   *
   * @param array $fields
   *        Overrides for the default values.
   *
   * @return array
   *         Fake open VTAC intake row.
   */
  private function openVtacIntake($fields = array()) {
    return $this->dummyIntake(array_merge(array(
      'is_vtac_course' => 'Y',
      'vtac_end_date' => NULL,
      'vtac_timely_date' => 'yesterday',
      'vtac_late_date' => 'yesterday',
      'vtac_very_late_date' => 'tomorrow',
      'early_admissions_end_date' => 'yesterday',
      'admissions_end_date' => 'yesterday',
    ), $fields));
  }

  /**
   * Construct a fake closed VTAC intake row for testing.
   *
   * @param array $fields
   *        Overrides for the default values.
   *
   * @return array
   *         Fake closed VTAC intake row.
   */
  private function closedVtacIntake($fields = array()) {
    return $this->openVtacIntake(array_merge(array(
      'vtac_very_late_date' => 'yesterday',
    ), $fields));
  }

  /**
   * Construct a fake open direct intake row for testing.
   *
   * @param array $fields
   *        Overrides for the default values.
   *
   * @return array
   *         Fake open direct intake row.
   */
  private function openDirectIntake($fields = array()) {
    return $this->dummyIntake(array_merge(array(
      'is_vtac_course' => 'N',
      'vtac_end_date' => NULL,
      'vtac_timely_date' => 'yesterday',
      'vtac_late_date' => 'yesterday',
      'vtac_very_late_date' => 'yesterday',
      'early_admissions_end_date' => 'yesterday',
      'admissions_end_date' => 'tomorrow',
    ), $fields));
  }

  /**
   * Load a CSV file into an array.
   *
   * @param string $name
   *        Only the basename part of the filename.
   *
   * @return array
   *         The CSV data as an array.
   */
  private function loadCsv($name) {
    $dir = dirname(__FILE__);
    $csv = array_map('str_getcsv', file("${dir}/fixtures/${name}.csv", FILE_SKIP_EMPTY_LINES));
    $keys = array_shift($csv);
    return array_map(function ($row) use ($keys) {
      return array_combine($keys, $row);
    }, $csv);
  }

  /**
   * A generic test of course essentials.
   */
  private function courseEssentialsTest($fixture, $row_fields = array(), $common_fields = array(), $exclude_fields = array()) {
    $course = new CourseIntakeList($this->loadCsv($fixture));
    $info = $course->courseEssentialsInfo(FALSE, $exclude_fields);
    $common = $info['common'];
    $row = current($info['rows']);
    foreach ((array) $row_fields as $field) {
      $this->assertArrayHasKey($field, $row);
      $this->assertArrayNotHasKey($field, $common);
    }
    foreach ((array) $common_fields as $field) {
      $this->assertArrayHasKey($field, $common);
      $this->assertArrayNotHasKey($field, $row);
    }
    foreach ((array) $exclude_fields as $field) {
      $this->assertArrayNotHasKey($field, $row);
      $this->assertArrayNotHasKey($field, $common);
    }
  }

  /**
   * Test a VTAC course is handled correctly.
   */
  public function testIsVtac() {
    $intake = new CourseIntakeList(array($this->openVtacIntake()));
    $this->assertTrue($intake->isVtac(), 'Is a VTAC course.');
  }

  /**
   * Test for intakes with open VTAC.
   */
  public function testVtacIsOpen() {
    $intake = new CourseIntakeList(array($this->openVtacIntake()));
    $this->assertTrue($intake->isOpen('VTAC'), 'Is open for VTAC.');
  }

  /**
   * Test for course with separate VTAC codes for different campuses.
   */
  public function testCourseEssentialsVtacCodePerCampus() {
    $row_fields = array('location', 'vtac_course_code');
    $this->courseEssentialsTest('vtac-code-per-campus', $row_fields);
  }

  /**
   * Test for course with separate VTAC codes for different study modes.
   */
  public function testCourseEssentialsVtacCodePerStudyMode() {
    $row_fields = array('attendance_type', 'vtac_course_code');
    $this->courseEssentialsTest('vtac-code-per-study-mode', $row_fields);
  }

  /**
   * Test for course with separate VTAC codes for different specialisations.
   */
  public function testCourseEssentialsVtacCodePerSpecialisation() {
    $row_fields = array('specialisation_name', 'vtac_course_code');
    $this->courseEssentialsTest('vtac-code-per-specialisation', $row_fields);
  }

  /**
   * Test that study modes are grouped in course essentials.
   */
  public function testCourseEssentialsNotSplitOnStudyMode() {
    $row_fields = array();
    $common_fields = array('attendance_type');
    $this->courseEssentialsTest('study-modes', $row_fields, $common_fields);
  }

  /**
   * Test involving attendace types and fee types.
   */
  public function testCourseEssentialsAttendanceTypeAndFeeType() {
    $row_fields = array('place_type', 'attendance_type');
    $this->courseEssentialsTest('attendance-type-fee-type', $row_fields);
  }

  /**
   * Test involving attendace types and fee types.
   */
  public function testCourseEssentialsExcludingFeeType() {
    $exclude_fields = array('place_type');
    $this->courseEssentialsTest('attendance-type-fee-type', array(), array(), $exclude_fields);
  }

  /**
   * Test for course with expression of interest.
   */
  public function testHasExpressionOfInterest() {
    $course = new CourseIntakeList(array(
      $this->dummyIntake(array('expression_of_interest' => 'N')),
      $this->dummyIntake(array('expression_of_interest' => 'N')),
      $this->dummyIntake(array('expression_of_interest' => 'Y')),
      $this->dummyIntake(array('expression_of_interest' => 'N')),
    ));

    $this->assertTrue($course->expressionOfInterest());
  }

  /**
   * Test for course without expression of interest.
   */
  public function testNoExpressionOfInterest() {
    $course = new CourseIntakeList(array(
      $this->dummyIntake(array('expression_of_interest' => 'N')),
      $this->dummyIntake(array('expression_of_interest' => 'N')),
    ));

    $this->assertFalse($course->expressionOfInterest());
  }

  /**
   * Test for direct intake.
   */
  public function testIsDirect() {
    $intake = new CourseIntakeList(array($this->openDirectIntake()));
    $this->assertTrue($intake->isDirect(), 'Is a direct course.');
  }

  /**
   * Test for direct open intake.
   */
  public function testDirectIsOpen() {
    $intake = new CourseIntakeList(array($this->openDirectIntake()));
    $this->assertTrue($intake->isOpen('direct'), 'Is open for direct.');
  }

  /**
   * Test for apprenticeship.
   */
  public function testIsApprenticeship() {
    $intake = new CourseIntakeList(array(
      $this->openDirectIntake(array(
        'application_entry_method' => 'APP-TRAIN',
      )),
    ));
    $this->assertTrue($intake->isApprenticeship(), 'Is an apprenticeship course.');
  }

  /**
   * Test for open apprenticeship.
   */
  public function testApprenticeshipIsOpen() {
    $intake = new CourseIntakeList(array(
      $this->openDirectIntake(array(
        'application_entry_method' => 'APP-TRAIN',
      )),
    ));
    $this->assertTrue($intake->isOpen('app-train'), 'Is an apprenticeship course.');
  }

  /**
   * Test for part-time course.
   */
  public function testStudyModesPartTimeOnly() {
    $intake = new CourseIntakeList(array(
      $this->openDirectIntake(array(
        'attendance_type' => 'PT',
      )),
    ));
    $this->assertEquals($intake->studyModes(), array('part time'));
  }

  /**
   * Test for full-time course.
   */
  public function testStudyModesFullTimeOnly() {
    $intake = new CourseIntakeList(array(
      $this->openDirectIntake(array(
        'attendance_type' => 'FT',
      )),
    ));
    $this->assertEquals($intake->studyModes(), array('full time'));
  }

  /**
   * Test for course with part-time and full-time intakes.
   */
  public function testStudyModesPartTimeAndFullTime() {
    $intake = new CourseIntakeList(array(
      $this->openDirectIntake(array('attendance_type' => 'FT')),
      $this->openDirectIntake(array('attendance_type' => 'PT')),
    ));
    $modes = $intake->studyModes();
    $this->assertCount(2, $modes);
    $this->assertContains('part time', $modes);
    $this->assertContains('full time', $modes);
  }

  /**
   * Test for course with multiple intakes in the same location.
   */
  public function testSingleLocation() {
    $intake = new CourseIntakeList(array(
      $this->openDirectIntake(array('location' => 'A')),
      $this->openVtacIntake(array('location' => 'A')),
    ));
    $locations = $intake->locations();
    $this->assertEquals($locations, array('A'));
  }

  /**
   * Test for course with multiple locations.
   */
  public function testMultipleLocation() {
    $intake = new CourseIntakeList(array(
      $this->openDirectIntake(array('location' => 'A')),
      $this->openDirectIntake(array('location' => 'B')),
    ));
    $locations = $intake->locations();
    $this->assertEquals($locations, array('A', 'B'));
  }

}
