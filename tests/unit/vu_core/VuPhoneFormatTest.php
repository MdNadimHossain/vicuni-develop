<?php

/**
 * Class VuPhoneFormatTest.
 */
class VuPhoneFormatTest extends VicUniDrupalTestCase {

  /**
   * @dataProvider providerPhoneFormat
   */
  public function testPhoneFormat($value, $expected) {
    $actual = vu_core_format_phone($value);
    $this->assertEquals($expected, $actual);
  }

  public function providerPhoneFormat() {
    return [
      [NULL, NULL],
      ['', ''],

      ['12345678', '+61 3 1234 5678'],
      ['1234 5678', '+61 3 1234 5678'],
      ['12 34 56 78', '+61 3 1234 5678'],
      ['1 2 3 4 5 6 7 8', '+61 3 1234 5678'],
      ['+61312345678', '+61 3 1234 5678'],
      ['+61 3 12345678', '+61 3 1234 5678'],
      ['+6 1 3 1 2 3 4 5 6 7 8', '+61 3 1234 5678'],
      ['+61 (3) 12345678', '+61 3 1234 5678'],
      ['+61(3)12345678', '+61 3 1234 5678'],
      ['61312345678', '+61 3 1234 5678'],
      ['312345678', '+61 3 1234 5678'],
      ['+312345678', '+61 3 1234 5678'],

      ['412345678', '+61 412 345 678'],
      ['0412345678', '+61 412 345 678'],
      ['61412345678', '+61 412 345 678'],
      ['+61412345678', '+61 412 345 678'],
      ['+61 4 12345678', '+61 412 345 678'],
    ];
  }

}
