<?php

namespace Doctrine\Tests\DBAL\Driver;

use Doctrine\DBAL\Connection;
use Doctrine\DBAL\Platforms\MySqlPlatform;
use Doctrine\DBAL\Schema\MySqlSchemaManager;

class AbstractMySQLDriverTest extends AbstractDriverTest {
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
    return $this->getMockForAbstractClass('Doctrine\DBAL\Driver\AbstractMySQLDriver');
  }

  protected function createPlatform() {
    return new MySqlPlatform();
  }

  protected function createSchemaManager(Connection $connection) {
    return new MySqlSchemaManager($connection);
  }

  protected function getDatabasePlatformsForVersions() {
    return array(
      array('5.6.9', 'Doctrine\DBAL\Platforms\MySqlPlatform'),
      array('5.7', 'Doctrine\DBAL\Platforms\MySQL57Platform'),
      array('5.7.0', 'Doctrine\DBAL\Platforms\MySQL57Platform'),
      array('5.7.1', 'Doctrine\DBAL\Platforms\MySQL57Platform'),
      array('6', 'Doctrine\DBAL\Platforms\MySQL57Platform'),
      array(
        '10.0.15-MariaDB-1~wheezy',
        'Doctrine\DBAL\Platforms\MySqlPlatform'
      ),
      array(
        '10.1.2a-MariaDB-a1~lenny-log',
        'Doctrine\DBAL\Platforms\MySqlPlatform'
      ),
      array('5.5.40-MariaDB-1~wheezy', 'Doctrine\DBAL\Platforms\MySqlPlatform'),
    );
  }

  protected function getExceptionConversionData() {
    return array(
      self::EXCEPTION_CONNECTION => array(
        array('1044', NULL, NULL),
        array('1045', NULL, NULL),
        array('1046', NULL, NULL),
        array('1049', NULL, NULL),
        array('1095', NULL, NULL),
        array('1142', NULL, NULL),
        array('1143', NULL, NULL),
        array('1227', NULL, NULL),
        array('1370', NULL, NULL),
        array('2002', NULL, NULL),
        array('2005', NULL, NULL),
      ),
      self::EXCEPTION_FOREIGN_KEY_CONSTRAINT_VIOLATION => array(
        array('1216', NULL, NULL),
        array('1217', NULL, NULL),
        array('1451', NULL, NULL),
        array('1452', NULL, NULL),
      ),
      self::EXCEPTION_INVALID_FIELD_NAME => array(
        array('1054', NULL, NULL),
        array('1166', NULL, NULL),
        array('1611', NULL, NULL),
      ),
      self::EXCEPTION_NON_UNIQUE_FIELD_NAME => array(
        array('1052', NULL, NULL),
        array('1060', NULL, NULL),
        array('1110', NULL, NULL),
      ),
      self::EXCEPTION_NOT_NULL_CONSTRAINT_VIOLATION => array(
        array('1048', NULL, NULL),
        array('1121', NULL, NULL),
        array('1138', NULL, NULL),
        array('1171', NULL, NULL),
        array('1252', NULL, NULL),
        array('1263', NULL, NULL),
        array('1566', NULL, NULL),
      ),
      self::EXCEPTION_SYNTAX_ERROR => array(
        array('1064', NULL, NULL),
        array('1149', NULL, NULL),
        array('1287', NULL, NULL),
        array('1341', NULL, NULL),
        array('1342', NULL, NULL),
        array('1343', NULL, NULL),
        array('1344', NULL, NULL),
        array('1382', NULL, NULL),
        array('1479', NULL, NULL),
        array('1541', NULL, NULL),
        array('1554', NULL, NULL),
        array('1626', NULL, NULL),
      ),
      self::EXCEPTION_TABLE_EXISTS => array(
        array('1050', NULL, NULL),
      ),
      self::EXCEPTION_TABLE_NOT_FOUND => array(
        array('1051', NULL, NULL),
        array('1146', NULL, NULL),
      ),
      self::EXCEPTION_UNIQUE_CONSTRAINT_VIOLATION => array(
        array('1062', NULL, NULL),
        array('1557', NULL, NULL),
        array('1569', NULL, NULL),
        array('1586', NULL, NULL),
      ),
    );
  }
}
