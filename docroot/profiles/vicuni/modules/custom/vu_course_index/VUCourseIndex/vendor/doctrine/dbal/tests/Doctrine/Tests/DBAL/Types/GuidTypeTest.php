<?php

namespace Doctrine\Tests\DBAL\Types;

use Doctrine\DBAL\Types\Type;
use Doctrine\Tests\DBAL\Mocks\MockPlatform;

class GuidTest extends \Doctrine\Tests\DbalTestCase {
  protected
    $_platform,
    $_type;

  protected function setUp() {
    $this->_platform = new MockPlatform();
    $this->_type = Type::getType('guid');
  }

  public function testConvertToPHPValue() {
    $this->assertInternalType("string", $this->_type->convertToPHPValue("foo", $this->_platform));
    $this->assertInternalType("string", $this->_type->convertToPHPValue("", $this->_platform));
  }

  public function testNullConversion() {
    $this->assertNull($this->_type->convertToPHPValue(NULL, $this->_platform));
  }

  public function testNativeGuidSupport() {
    $this->assertTrue($this->_type->requiresSQLCommentHint($this->_platform));

    $mock = $this->getMock(get_class($this->_platform));
    $mock->expects($this->any())
      ->method('hasNativeGuidType')
      ->will($this->returnValue(TRUE));

    $this->assertFalse($this->_type->requiresSQLCommentHint($mock));
  }
}
