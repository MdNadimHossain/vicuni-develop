<?php

namespace Doctrine\Tests\DBAL\Types;

use Doctrine\DBAL\Types\Type;
use Doctrine\Tests\DBAL\Mocks\MockPlatform;

require_once __DIR__ . '/../../TestInit.php';

class BooleanTest extends \Doctrine\Tests\DbalTestCase {
  protected
    $_platform,
    $_type;

  protected function setUp() {
    $this->_platform = new MockPlatform();
    $this->_type = Type::getType('boolean');
  }

  public function testBooleanConvertsToDatabaseValue() {
    $this->assertInternalType('integer', $this->_type->convertToDatabaseValue(1, $this->_platform));
  }

  public function testBooleanConvertsToPHPValue() {
    $this->assertInternalType('bool', $this->_type->convertToPHPValue(0, $this->_platform));
  }

  public function testBooleanNullConvertsToPHPValue() {
    $this->assertNull($this->_type->convertToPHPValue(NULL, $this->_platform));
  }
}
