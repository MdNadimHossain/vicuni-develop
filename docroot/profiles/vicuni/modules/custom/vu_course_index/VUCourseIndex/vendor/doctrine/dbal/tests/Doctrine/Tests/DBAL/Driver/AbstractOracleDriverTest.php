<?php

namespace Doctrine\Tests\DBAL\Driver;

use Doctrine\DBAL\Connection;
use Doctrine\DBAL\Platforms\OraclePlatform;
use Doctrine\DBAL\Schema\OracleSchemaManager;

class AbstractOracleDriverTest extends AbstractDriverTest {
  public function testReturnsDatabaseName() {
    $params = array(
      'user' => 'foo',
      'password' => 'bar',
      'dbname' => 'baz',
    );

    $connection = $this->getConnectionMock();

    $connection->expects($this->once())
      ->method('getParams')
      ->will($this->returnValue($params));

    $this->assertSame($params['user'], $this->driver->getDatabase($connection));
  }

  protected function createDriver() {
    return $this->getMockForAbstractClass('Doctrine\DBAL\Driver\AbstractOracleDriver');
  }

  protected function createPlatform() {
    return new OraclePlatform();
  }

  protected function createSchemaManager(Connection $connection) {
    return new OracleSchemaManager($connection);
  }

  protected function getExceptionConversionData() {
    return array(
      self::EXCEPTION_CONNECTION => array(
        array('1017', NULL, NULL),
        array('12545', NULL, NULL),
      ),
      self::EXCEPTION_FOREIGN_KEY_CONSTRAINT_VIOLATION => array(
        array('2292', NULL, NULL),
      ),
      self::EXCEPTION_INVALID_FIELD_NAME => array(
        array('904', NULL, NULL),
      ),
      self::EXCEPTION_NON_UNIQUE_FIELD_NAME => array(
        array('918', NULL, NULL),
        array('960', NULL, NULL),
      ),
      self::EXCEPTION_NOT_NULL_CONSTRAINT_VIOLATION => array(
        array('1400', NULL, NULL),
      ),
      self::EXCEPTION_SYNTAX_ERROR => array(
        array('923', NULL, NULL),
      ),
      self::EXCEPTION_TABLE_EXISTS => array(
        array('955', NULL, NULL),
      ),
      self::EXCEPTION_TABLE_NOT_FOUND => array(
        array('942', NULL, NULL),
      ),
      self::EXCEPTION_UNIQUE_CONSTRAINT_VIOLATION => array(
        array('1', NULL, NULL),
        array('2299', NULL, NULL),
        array('38911', NULL, NULL),
      ),
    );
  }
}
