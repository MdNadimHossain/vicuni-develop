<?php

class Issue498Test extends PHPUnit_Framework_TestCase {

  /**
   * @test
   * @dataProvider shouldBeTrueDataProvider
   * @group falseOnly
   */
  public function shouldBeTrue($testData) {
    $this->assertTrue(TRUE);
  }


  /**
   * @test
   * @dataProvider shouldBeFalseDataProvider
   * @group trueOnly
   */
  public function shouldBeFalse($testData) {
    $this->assertFalse(FALSE);
  }

  public function shouldBeTrueDataProvider() {

    //throw new Exception("Can't create the data");
    return array(
      array(TRUE),
      array(FALSE)
    );
  }

  public function shouldBeFalseDataProvider() {

    throw new Exception("Can't create the data");
    return array(
      array(TRUE),
      array(FALSE)
    );
  }
}
