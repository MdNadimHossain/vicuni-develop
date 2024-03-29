<?php

namespace Doctrine\Tests\DBAL\Schema;

require_once __DIR__ . '/../../TestInit.php';

use Doctrine\DBAL\Schema\Column;
use Doctrine\DBAL\Types\Type;

class ColumnTest extends \PHPUnit_Framework_TestCase {
  public function testGet() {
    $column = $this->createColumn();

    $this->assertEquals("foo", $column->getName());
    $this->assertSame(Type::getType('string'), $column->getType());

    $this->assertEquals(200, $column->getLength());
    $this->assertEquals(5, $column->getPrecision());
    $this->assertEquals(2, $column->getScale());
    $this->assertTrue($column->getUnsigned());
    $this->assertFalse($column->getNotNull());
    $this->assertTrue($column->getFixed());
    $this->assertEquals("baz", $column->getDefault());

    $this->assertEquals(array('foo' => 'bar'), $column->getPlatformOptions());
    $this->assertTrue($column->hasPlatformOption('foo'));
    $this->assertEquals('bar', $column->getPlatformOption('foo'));
    $this->assertFalse($column->hasPlatformOption('bar'));

    $this->assertEquals(array('bar' => 'baz'), $column->getCustomSchemaOptions());
    $this->assertTrue($column->hasCustomSchemaOption('bar'));
    $this->assertEquals('baz', $column->getCustomSchemaOption('bar'));
    $this->assertFalse($column->hasCustomSchemaOption('foo'));
  }

  public function testToArray() {
    $expected = array(
      'name' => 'foo',
      'type' => Type::getType('string'),
      'default' => 'baz',
      'notnull' => FALSE,
      'length' => 200,
      'precision' => 5,
      'scale' => 2,
      'fixed' => TRUE,
      'unsigned' => TRUE,
      'autoincrement' => FALSE,
      'columnDefinition' => NULL,
      'comment' => NULL,
      'foo' => 'bar',
      'bar' => 'baz'
    );

    $this->assertEquals($expected, $this->createColumn()->toArray());
  }

  /**
   * @return Column
   */
  public function createColumn() {
    $options = array(
      'length' => 200,
      'precision' => 5,
      'scale' => 2,
      'unsigned' => TRUE,
      'notnull' => FALSE,
      'fixed' => TRUE,
      'default' => 'baz',
      'platformOptions' => array('foo' => 'bar'),
      'customSchemaOptions' => array('bar' => 'baz'),
    );

    $string = Type::getType('string');
    return new Column("foo", $string, $options);
  }

  /**
   * @group DBAL-64
   * @group DBAL-830
   */
  public function testQuotedColumnName() {
    $string = Type::getType('string');
    $column = new Column("`bar`", $string, array());

    $mysqlPlatform = new \Doctrine\DBAL\Platforms\MySqlPlatform();
    $sqlitePlatform = new \Doctrine\DBAL\Platforms\SqlitePlatform();

    $this->assertEquals('bar', $column->getName());
    $this->assertEquals('`bar`', $column->getQuotedName($mysqlPlatform));
    $this->assertEquals('"bar"', $column->getQuotedName($sqlitePlatform));

    $column = new Column("[bar]", $string);

    $sqlServerPlatform = new \Doctrine\DBAL\Platforms\SQLServerPlatform();

    $this->assertEquals('bar', $column->getName());
    $this->assertEquals('[bar]', $column->getQuotedName($sqlServerPlatform));
  }

  /**
   * @dataProvider getIsQuoted
   * @group DBAL-830
   */
  public function testIsQuoted($columnName, $isQuoted) {
    $type = Type::getType('string');
    $column = new Column($columnName, $type);

    $this->assertSame($isQuoted, $column->isQuoted());
  }

  public function getIsQuoted() {
    return array(
      array('bar', FALSE),
      array('`bar`', TRUE),
      array('"bar"', TRUE),
      array('[bar]', TRUE),
    );
  }

  /**
   * @group DBAL-42
   */
  public function testColumnComment() {
    $column = new Column("bar", Type::getType('string'));
    $this->assertNull($column->getComment());

    $column->setComment("foo");
    $this->assertEquals("foo", $column->getComment());

    $columnArray = $column->toArray();
    $this->assertArrayHasKey('comment', $columnArray);
    $this->assertEquals('foo', $columnArray['comment']);
  }
}
