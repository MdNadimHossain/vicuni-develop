<?php

/**
 * Class VuStaffIdTest.
 */
class VuStaffIdTest extends VicUniDrupalTestCase {

  /**
   * @dataProvider providerStaffIdNormalise
   */
  public function testStaffIdNormalise($value, $expected) {
    $actual = vu_core_normalise_staff_id($value);
    $this->assertEquals($expected, $actual);
  }

  public function providerStaffIdNormalise() {
    return [
      ['1234567', 'E1234567'],
      ['e1234567', 'E1234567'],
      ['E1234567', 'E1234567'],
    ];
  }

  /**
   * @dataProvider providerStaffIdValidate
   */
  public function testStaffIdValidate($value, $exceptionMessage) {
    if ($exceptionMessage) {
      $this->expectExceptionMessage($exceptionMessage);
    }
    vu_core_staff_id_validate($value);
  }

  public function providerStaffIdValidate() {
    return [
      // Valid.
      ['E1234567', FALSE],
      ['e1234567', FALSE],
      ['E1234567', FALSE],

      // Invalid.
      ['E12345678', 'Staff ID should have 7 digits'],
      ['1234567', 'Staff ID should start with "E"'],
      ['my id', 'Staff ID should be numeric'],
      ['emy id', 'Staff ID should be numeric'],
      ['Emy id', 'Staff ID should be numeric'],
      ['E123id', 'Staff ID should be numeric'],
    ];
  }

}
