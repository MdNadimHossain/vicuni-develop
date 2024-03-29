<?php

namespace Doctrine\Tests\DBAL\Schema;

require_once __DIR__ . '/../../TestInit.php';

use Doctrine\DBAL\Schema\Index;

class IndexTest extends \PHPUnit_Framework_TestCase {
  public function createIndex($unique = FALSE, $primary = FALSE, $options = array()) {
    return new Index("foo", array(
      "bar",
      "baz"
    ), $unique, $primary, array(), $options);
  }

  public function testCreateIndex() {
    $idx = $this->createIndex();
    $this->assertEquals("foo", $idx->getName());
    $columns = $idx->getColumns();
    $this->assertEquals(2, count($columns));
    $this->assertEquals(array("bar", "baz"), $columns);
    $this->assertFalse($idx->isUnique());
    $this->assertFalse($idx->isPrimary());
  }

  public function testCreatePrimary() {
    $idx = $this->createIndex(FALSE, TRUE);
    $this->assertTrue($idx->isUnique());
    $this->assertTrue($idx->isPrimary());
  }

  public function testCreateUnique() {
    $idx = $this->createIndex(TRUE, FALSE);
    $this->assertTrue($idx->isUnique());
    $this->assertFalse($idx->isPrimary());
  }

  /**
   * @group DBAL-50
   */
  public function testFullfilledByUnique() {
    $idx1 = $this->createIndex(TRUE, FALSE);
    $idx2 = $this->createIndex(TRUE, FALSE);
    $idx3 = $this->createIndex();

    $this->assertTrue($idx1->isFullfilledBy($idx2));
    $this->assertFalse($idx1->isFullfilledBy($idx3));
  }

  /**
   * @group DBAL-50
   */
  public function testFullfilledByPrimary() {
    $idx1 = $this->createIndex(TRUE, TRUE);
    $idx2 = $this->createIndex(TRUE, TRUE);
    $idx3 = $this->createIndex(TRUE, FALSE);

    $this->assertTrue($idx1->isFullfilledBy($idx2));
    $this->assertFalse($idx1->isFullfilledBy($idx3));
  }

  /**
   * @group DBAL-50
   */
  public function testFullfilledByIndex() {
    $idx1 = $this->createIndex();
    $idx2 = $this->createIndex();
    $pri = $this->createIndex(TRUE, TRUE);
    $uniq = $this->createIndex(TRUE);

    $this->assertTrue($idx1->isFullfilledBy($idx2));
    $this->assertTrue($idx1->isFullfilledBy($pri));
    $this->assertTrue($idx1->isFullfilledBy($uniq));
  }

  public function testFullfilledWithPartial() {
    $without = new Index('without', array(
      'col1',
      'col2'
    ), TRUE, FALSE, array(), array());
    $partial = new Index('partial', array(
      'col1',
      'col2'
    ), TRUE, FALSE, array(), array('where' => 'col1 IS NULL'));
    $another = new Index('another', array(
      'col1',
      'col2'
    ), TRUE, FALSE, array(), array('where' => 'col1 IS NULL'));

    $this->assertFalse($partial->isFullfilledBy($without));
    $this->assertFalse($without->isFullfilledBy($partial));

    $this->assertTrue($partial->isFullfilledBy($partial));

    $this->assertTrue($partial->isFullfilledBy($another));
    $this->assertTrue($another->isFullfilledBy($partial));
  }

  public function testOverrulesWithPartial() {
    $without = new Index('without', array(
      'col1',
      'col2'
    ), TRUE, FALSE, array(), array());
    $partial = new Index('partial', array(
      'col1',
      'col2'
    ), TRUE, FALSE, array(), array('where' => 'col1 IS NULL'));
    $another = new Index('another', array(
      'col1',
      'col2'
    ), TRUE, FALSE, array(), array('where' => 'col1 IS NULL'));

    $this->assertFalse($partial->overrules($without));
    $this->assertFalse($without->overrules($partial));

    $this->assertTrue($partial->overrules($partial));

    $this->assertTrue($partial->overrules($another));
    $this->assertTrue($another->overrules($partial));
  }

  /**
   * @group DBAL-220
   */
  public function testFlags() {
    $idx1 = $this->createIndex();
    $this->assertFalse($idx1->hasFlag('clustered'));
    $this->assertEmpty($idx1->getFlags());

    $idx1->addFlag('clustered');
    $this->assertTrue($idx1->hasFlag('clustered'));
    $this->assertTrue($idx1->hasFlag('CLUSTERED'));
    $this->assertSame(array('clustered'), $idx1->getFlags());

    $idx1->removeFlag('clustered');
    $this->assertFalse($idx1->hasFlag('clustered'));
    $this->assertEmpty($idx1->getFlags());
  }

  /**
   * @group DBAL-285
   */
  public function testIndexQuotes() {
    $index = new Index("foo", array("`bar`", "`baz`"));

    $this->assertTrue($index->spansColumns(array("bar", "baz")));
    $this->assertTrue($index->hasColumnAtPosition("bar", 0));
    $this->assertTrue($index->hasColumnAtPosition("baz", 1));

    $this->assertFalse($index->hasColumnAtPosition("bar", 1));
    $this->assertFalse($index->hasColumnAtPosition("baz", 0));
  }

  public function testOptions() {
    $idx1 = $this->createIndex();
    $this->assertFalse($idx1->hasOption('where'));
    $this->assertEmpty($idx1->getOptions());

    $idx2 = $this->createIndex(FALSE, FALSE, array('where' => 'name IS NULL'));
    $this->assertTrue($idx2->hasOption('where'));
    $this->assertTrue($idx2->hasOption('WHERE'));
    $this->assertSame('name IS NULL', $idx2->getOption('where'));
    $this->assertSame('name IS NULL', $idx2->getOption('WHERE'));
    $this->assertSame(array('where' => 'name IS NULL'), $idx2->getOptions());
  }
}
