<?php

namespace Doctrine\Tests\DBAL\Schema;

use Doctrine\DBAL\Schema\ForeignKeyConstraint;

class ForeignKeyConstraintTest extends \PHPUnit_Framework_TestCase {
  /**
   * @group DBAL-1062
   *
   * @dataProvider getIntersectsIndexColumnsData
   */
  public function testIntersectsIndexColumns(array $indexColumns, $expectedResult) {
    $foreignKey = new ForeignKeyConstraint(array(
      'foo',
      'bar'
    ), 'foreign_table', array('fk_foo', 'fk_bar'));

    $index = $this->getMockBuilder('Doctrine\DBAL\Schema\Index')
      ->disableOriginalConstructor()
      ->getMock();
    $index->expects($this->once())
      ->method('getColumns')
      ->will($this->returnValue($indexColumns));

    $this->assertSame($expectedResult, $foreignKey->intersectsIndexColumns($index));
  }

  /**
   * @return array
   */
  public function getIntersectsIndexColumnsData() {
    return array(
      array(array('baz'), FALSE),
      array(array('baz', 'bloo'), FALSE),

      array(array('foo'), TRUE),
      array(array('bar'), TRUE),

      array(array('foo', 'bar'), TRUE),
      array(array('bar', 'foo'), TRUE),

      array(array('foo', 'baz'), TRUE),
      array(array('baz', 'foo'), TRUE),

      array(array('bar', 'baz'), TRUE),
      array(array('baz', 'bar'), TRUE),

      array(array('foo', 'bloo', 'baz'), TRUE),
      array(array('bloo', 'foo', 'baz'), TRUE),
      array(array('bloo', 'baz', 'foo'), TRUE),

      array(array('FOO'), TRUE),
    );
  }
}
