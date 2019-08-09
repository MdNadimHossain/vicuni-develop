<?php

class Issue765Test extends PHPUnit_Framework_TestCase {
  public function testDependee() {
    $this->assertTrue(TRUE);
  }

  /**
   * @depends      testDependee
   * @dataProvider dependentProvider
   */
  public function testDependent($a) {
    $this->assertTrue(TRUE);
  }

  public function dependentProvider() {
    throw new Exception;
  }
}
