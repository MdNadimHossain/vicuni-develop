<?php

namespace Doctrine\Tests\DBAL\Driver;

use Doctrine\DBAL\Connection;
use Doctrine\DBAL\Platforms\PostgreSqlPlatform;
use Doctrine\DBAL\Schema\PostgreSqlSchemaManager;

class AbstractPostgreSQLDriverTest extends AbstractDriverTest {
  public function testReturnsDatabaseName() {
    parent::testReturnsDatabaseName();

    $database = 'bloo';
    $params = array(
      'user' => 'foo',
      'password' => 'bar',
    );

    $statement = $this->getMock('Doctrine\Tests\Mocks\DriverResultStatementMock');

    $statement->expects($this->once())
      ->method('fetchColumn')
      ->will($this->returnValue($database));

    $connection = $this->getConnectionMock();

    $connection->expects($this->once())
      ->method('getParams')
      ->will($this->returnValue($params));

    $connection->expects($this->once())
      ->method('query')
      ->will($this->returnValue($statement));

    $this->assertSame($database, $this->driver->getDatabase($connection));
  }

  protected function createDriver() {
    return $this->getMockForAbstractClass('Doctrine\DBAL\Driver\AbstractPostgreSQLDriver');
  }

  protected function createPlatform() {
    return new PostgreSqlPlatform();
  }

  protected function createSchemaManager(Connection $connection) {
    return new PostgreSqlSchemaManager($connection);
  }

  protected function getDatabasePlatformsForVersions() {
    return array(
      array('9.0.9', 'Doctrine\DBAL\Platforms\PostgreSqlPlatform'),
      array('9.1', 'Doctrine\DBAL\Platforms\PostgreSQL91Platform'),
      array('9.1.0', 'Doctrine\DBAL\Platforms\PostgreSQL91Platform'),
      array('9.1.1', 'Doctrine\DBAL\Platforms\PostgreSQL91Platform'),
      array('9.1.9', 'Doctrine\DBAL\Platforms\PostgreSQL91Platform'),
      array('9.2', 'Doctrine\DBAL\Platforms\PostgreSQL92Platform'),
      array('9.2.0', 'Doctrine\DBAL\Platforms\PostgreSQL92Platform'),
      array('9.2.1', 'Doctrine\DBAL\Platforms\PostgreSQL92Platform'),
      array('10', 'Doctrine\DBAL\Platforms\PostgreSQL92Platform'),
    );
  }

  protected function getExceptionConversionData() {
    return array(
      self::EXCEPTION_CONNECTION => array(
        array(NULL, '7', 'SQLSTATE[08006]'),
      ),
      self::EXCEPTION_FOREIGN_KEY_CONSTRAINT_VIOLATION => array(
        array(NULL, '23503', NULL),
      ),
      self::EXCEPTION_INVALID_FIELD_NAME => array(
        array(NULL, '42703', NULL),
      ),
      self::EXCEPTION_NON_UNIQUE_FIELD_NAME => array(
        array(NULL, '42702', NULL),
      ),
      self::EXCEPTION_NOT_NULL_CONSTRAINT_VIOLATION => array(
        array(NULL, '23502', NULL),
      ),
      self::EXCEPTION_SYNTAX_ERROR => array(
        array(NULL, '42601', NULL),
      ),
      self::EXCEPTION_TABLE_EXISTS => array(
        array(NULL, '42P07', NULL),
      ),
      self::EXCEPTION_TABLE_NOT_FOUND => array(
        array(NULL, '42P01', NULL),
      ),
      self::EXCEPTION_UNIQUE_CONSTRAINT_VIOLATION => array(
        array(NULL, '23505', NULL),
      ),
    );
  }
}
