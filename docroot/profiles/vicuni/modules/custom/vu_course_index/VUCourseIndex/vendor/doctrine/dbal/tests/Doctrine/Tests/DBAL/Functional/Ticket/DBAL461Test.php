<?php

namespace Doctrine\Tests\DBAL\Functional\Ticket;

use Doctrine\DBAL\Schema\SQLServerSchemaManager;

/**
 * @group DBAL-461
 */
class DBAL461Test extends \PHPUnit_Framework_TestCase {
  public function testIssue() {
    $conn = $this->getMock('Doctrine\DBAL\Connection', array(), array(), '', FALSE);
    $platform = $this->getMockForAbstractClass('Doctrine\DBAL\Platforms\AbstractPlatform');
    $platform->registerDoctrineTypeMapping('numeric', 'decimal');

    $schemaManager = new SQLServerSchemaManager($conn, $platform);

    $reflectionMethod = new \ReflectionMethod($schemaManager, '_getPortableTableColumnDefinition');
    $reflectionMethod->setAccessible(TRUE);
    $column = $reflectionMethod->invoke($schemaManager, array(
      'type' => 'numeric(18,0)',
      'length' => NULL,
      'default' => NULL,
      'notnull' => FALSE,
      'scale' => 18,
      'precision' => 0,
      'autoincrement' => FALSE,
      'collation' => 'foo',
      'comment' => NULL,
    ));

    $this->assertEquals('Decimal', (string) $column->getType());
  }
}
