<?php
/*
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This software consists of voluntary contributions made by many individuals
 * and is licensed under the MIT license. For more information, see
 * <http://www.doctrine-project.org>.
 */

namespace Doctrine\Tests\DBAL\Schema;

require_once __DIR__ . '/../../TestInit.php';

use Doctrine\DBAL\Schema\Column;
use Doctrine\DBAL\Schema\ColumnDiff;
use Doctrine\DBAL\Schema\Comparator;
use Doctrine\DBAL\Schema\ForeignKeyConstraint;
use Doctrine\DBAL\Schema\Index;
use Doctrine\DBAL\Schema\Schema;
use Doctrine\DBAL\Schema\SchemaConfig;
use Doctrine\DBAL\Schema\SchemaDiff;
use Doctrine\DBAL\Schema\Sequence;
use Doctrine\DBAL\Schema\Table;
use Doctrine\DBAL\Schema\TableDiff;
use Doctrine\DBAL\Types\Type;

/**
 * @license http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link    www.doctrine-project.org
 * @copyright Copyright (C) 2005-2009 eZ Systems AS. All rights reserved.
 * @license http://ez.no/licenses/new_bsd New BSD License
 * @since   2.0
 * @version $Revision$
 * @author  Benjamin Eberlei <kontakt@beberlei.de>
 */
class ComparatorTest extends \PHPUnit_Framework_TestCase {
  public function testCompareSame1() {
    $schema1 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
        )
      ),
    ));
    $schema2 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
        )
      ),
    ));

    $expected = new SchemaDiff();
    $expected->fromSchema = $schema1;
    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareSame2() {
    $schema1 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        )
      ),
    ));
    $schema2 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
        )
      ),
    ));

    $expected = new SchemaDiff();
    $expected->fromSchema = $schema1;
    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareMissingTable() {
    $schemaConfig = new \Doctrine\DBAL\Schema\SchemaConfig;
    $table = new Table('bugdb', array('integerfield1' => new Column('integerfield1', Type::getType('integer'))));
    $table->setSchemaConfig($schemaConfig);

    $schema1 = new Schema(array($table), array(), $schemaConfig);
    $schema2 = new Schema(array(), array(), $schemaConfig);

    $expected = new SchemaDiff(array(), array(), array('bugdb' => $table), $schema1);

    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareNewTable() {
    $schemaConfig = new \Doctrine\DBAL\Schema\SchemaConfig;
    $table = new Table('bugdb', array('integerfield1' => new Column('integerfield1', Type::getType('integer'))));
    $table->setSchemaConfig($schemaConfig);

    $schema1 = new Schema(array(), array(), $schemaConfig);
    $schema2 = new Schema(array($table), array(), $schemaConfig);

    $expected = new SchemaDiff(array('bugdb' => $table), array(), array(), $schema1);

    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareOnlyAutoincrementChanged() {
    $column1 = new Column('foo', Type::getType('integer'), array('autoincrement' => TRUE));
    $column2 = new Column('foo', Type::getType('integer'), array('autoincrement' => FALSE));

    $comparator = new Comparator();
    $changedProperties = $comparator->diffColumn($column1, $column2);

    $this->assertEquals(array('autoincrement'), $changedProperties);
  }

  public function testCompareMissingField() {
    $missingColumn = new Column('integerfield1', Type::getType('integer'));
    $schema1 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => $missingColumn,
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        )
      ),
    ));
    $schema2 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        )
      ),
    ));

    $expected = new SchemaDiff (array(),
      array(
        'bugdb' => new TableDiff('bugdb', array(), array(),
          array(
            'integerfield1' => $missingColumn,
          )
        )
      )
    );
    $expected->fromSchema = $schema1;
    $expected->changedTables['bugdb']->fromTable = $schema1->getTable('bugdb');

    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareNewField() {
    $schema1 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
        )
      ),
    ));
    $schema2 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        )
      ),
    ));

    $expected = new SchemaDiff (array(),
      array(
        'bugdb' => new TableDiff ('bugdb',
          array(
            'integerfield2' => new Column('integerfield2', Type::getType('integer')),
          )
        ),
      )
    );
    $expected->fromSchema = $schema1;
    $expected->changedTables['bugdb']->fromTable = $schema1->getTable('bugdb');

    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareChangedColumns_ChangeType() {
    $column1 = new Column('charfield1', Type::getType('string'));
    $column2 = new Column('charfield1', Type::getType('integer'));

    $c = new Comparator();
    $this->assertEquals(array('type'), $c->diffColumn($column1, $column2));
    $this->assertEquals(array(), $c->diffColumn($column1, $column1));
  }

  public function testCompareChangedColumns_ChangeCustomSchemaOption() {
    $column1 = new Column('charfield1', Type::getType('string'));
    $column2 = new Column('charfield1', Type::getType('string'));

    $column1->setCustomSchemaOption('foo', 'bar');
    $column2->setCustomSchemaOption('foo', 'bar');

    $column1->setCustomSchemaOption('foo1', 'bar1');
    $column2->setCustomSchemaOption('foo2', 'bar2');

    $c = new Comparator();
    $this->assertEquals(array(
      'foo1',
      'foo2'
    ), $c->diffColumn($column1, $column2));
    $this->assertEquals(array(), $c->diffColumn($column1, $column1));
  }

  public function testCompareChangeColumns_MultipleNewColumnsRename() {
    $tableA = new Table("foo");
    $tableA->addColumn('datefield1', 'datetime');

    $tableB = new Table("foo");
    $tableB->addColumn('new_datefield1', 'datetime');
    $tableB->addColumn('new_datefield2', 'datetime');

    $c = new Comparator();
    $tableDiff = $c->diffTable($tableA, $tableB);

    $this->assertCount(1, $tableDiff->renamedColumns, "we should have one rename datefield1 => new_datefield1.");
    $this->assertArrayHasKey('datefield1', $tableDiff->renamedColumns, "'datefield1' should be set to be renamed to new_datefield1");
    $this->assertCount(1, $tableDiff->addedColumns, "'new_datefield2' should be added");
    $this->assertArrayHasKey('new_datefield2', $tableDiff->addedColumns, "'new_datefield2' should be added, not created through renaming!");
    $this->assertCount(0, $tableDiff->removedColumns, "Nothing should be removed.");
    $this->assertCount(0, $tableDiff->changedColumns, "Nothing should be changed as all fields old & new have diff names.");
  }

  public function testCompareRemovedIndex() {
    $schema1 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        ),
        array(
          'primary' => new Index('primary',
            array(
              'integerfield1'
            ),
            TRUE
          )
        )
      ),
    ));
    $schema2 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        )
      ),
    ));

    $expected = new SchemaDiff (array(),
      array(
        'bugdb' => new TableDiff('bugdb', array(), array(), array(), array(), array(),
          array(
            'primary' => new Index('primary',
              array(
                'integerfield1'
              ),
              TRUE
            )
          )
        ),
      )
    );
    $expected->fromSchema = $schema1;
    $expected->changedTables['bugdb']->fromTable = $schema1->getTable('bugdb');

    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareNewIndex() {
    $schema1 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        )
      ),
    ));
    $schema2 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        ),
        array(
          'primary' => new Index('primary',
            array(
              'integerfield1'
            ),
            TRUE
          )
        )
      ),
    ));

    $expected = new SchemaDiff (array(),
      array(
        'bugdb' => new TableDiff('bugdb', array(), array(), array(),
          array(
            'primary' => new Index('primary',
              array(
                'integerfield1'
              ),
              TRUE
            )
          )
        ),
      )
    );
    $expected->fromSchema = $schema1;
    $expected->changedTables['bugdb']->fromTable = $schema1->getTable('bugdb');

    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareChangedIndex() {
    $schema1 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        ),
        array(
          'primary' => new Index('primary',
            array(
              'integerfield1'
            ),
            TRUE
          )
        )
      ),
    ));
    $schema2 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        ),
        array(
          'primary' => new Index('primary',
            array('integerfield1', 'integerfield2'),
            TRUE
          )
        )
      ),
    ));

    $expected = new SchemaDiff (array(),
      array(
        'bugdb' => new TableDiff('bugdb', array(), array(), array(), array(),
          array(
            'primary' => new Index('primary',
              array(
                'integerfield1',
                'integerfield2'
              ),
              TRUE
            )
          )
        ),
      )
    );
    $expected->fromSchema = $schema1;
    $expected->changedTables['bugdb']->fromTable = $schema1->getTable('bugdb');

    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareChangedIndexFieldPositions() {
    $schema1 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        ),
        array(
          'primary' => new Index('primary', array(
            'integerfield1',
            'integerfield2'
          ), TRUE)
        )
      ),
    ));
    $schema2 = new Schema(array(
      'bugdb' => new Table('bugdb',
        array(
          'integerfield1' => new Column('integerfield1', Type::getType('integer')),
          'integerfield2' => new Column('integerfield2', Type::getType('integer')),
        ),
        array(
          'primary' => new Index('primary', array(
            'integerfield2',
            'integerfield1'
          ), TRUE)
        )
      ),
    ));

    $expected = new SchemaDiff (array(),
      array(
        'bugdb' => new TableDiff('bugdb', array(), array(), array(), array(),
          array(
            'primary' => new Index('primary', array(
              'integerfield2',
              'integerfield1'
            ), TRUE)
          )
        ),
      )
    );
    $expected->fromSchema = $schema1;
    $expected->changedTables['bugdb']->fromTable = $schema1->getTable('bugdb');

    $this->assertEquals($expected, Comparator::compareSchemas($schema1, $schema2));
  }

  public function testCompareSequences() {
    $seq1 = new Sequence('foo', 1, 1);
    $seq2 = new Sequence('foo', 1, 2);
    $seq3 = new Sequence('foo', 2, 1);

    $c = new Comparator();

    $this->assertTrue($c->diffSequence($seq1, $seq2));
    $this->assertTrue($c->diffSequence($seq1, $seq3));
  }

  public function testRemovedSequence() {
    $schema1 = new Schema();
    $seq = $schema1->createSequence('foo');

    $schema2 = new Schema();

    $c = new Comparator();
    $diffSchema = $c->compare($schema1, $schema2);

    $this->assertEquals(1, count($diffSchema->removedSequences));
    $this->assertSame($seq, $diffSchema->removedSequences[0]);
  }

  public function testAddedSequence() {
    $schema1 = new Schema();

    $schema2 = new Schema();
    $seq = $schema2->createSequence('foo');

    $c = new Comparator();
    $diffSchema = $c->compare($schema1, $schema2);

    $this->assertEquals(1, count($diffSchema->newSequences));
    $this->assertSame($seq, $diffSchema->newSequences[0]);
  }

  public function testTableAddForeignKey() {
    $tableForeign = new Table("bar");
    $tableForeign->addColumn('id', 'integer');

    $table1 = new Table("foo");
    $table1->addColumn('fk', 'integer');

    $table2 = new Table("foo");
    $table2->addColumn('fk', 'integer');
    $table2->addForeignKeyConstraint($tableForeign, array('fk'), array('id'));

    $c = new Comparator();
    $tableDiff = $c->diffTable($table1, $table2);

    $this->assertInstanceOf('Doctrine\DBAL\Schema\TableDiff', $tableDiff);
    $this->assertEquals(1, count($tableDiff->addedForeignKeys));
  }

  public function testTableRemoveForeignKey() {
    $tableForeign = new Table("bar");
    $tableForeign->addColumn('id', 'integer');

    $table1 = new Table("foo");
    $table1->addColumn('fk', 'integer');

    $table2 = new Table("foo");
    $table2->addColumn('fk', 'integer');
    $table2->addForeignKeyConstraint($tableForeign, array('fk'), array('id'));

    $c = new Comparator();
    $tableDiff = $c->diffTable($table2, $table1);

    $this->assertInstanceOf('Doctrine\DBAL\Schema\TableDiff', $tableDiff);
    $this->assertEquals(1, count($tableDiff->removedForeignKeys));
  }

  public function testTableUpdateForeignKey() {
    $tableForeign = new Table("bar");
    $tableForeign->addColumn('id', 'integer');

    $table1 = new Table("foo");
    $table1->addColumn('fk', 'integer');
    $table1->addForeignKeyConstraint($tableForeign, array('fk'), array('id'));

    $table2 = new Table("foo");
    $table2->addColumn('fk', 'integer');
    $table2->addForeignKeyConstraint($tableForeign, array('fk'), array('id'), array('onUpdate' => 'CASCADE'));

    $c = new Comparator();
    $tableDiff = $c->diffTable($table1, $table2);

    $this->assertInstanceOf('Doctrine\DBAL\Schema\TableDiff', $tableDiff);
    $this->assertEquals(1, count($tableDiff->changedForeignKeys));
  }

  public function testMovedForeignKeyForeignTable() {
    $tableForeign = new Table("bar");
    $tableForeign->addColumn('id', 'integer');

    $tableForeign2 = new Table("bar2");
    $tableForeign2->addColumn('id', 'integer');

    $table1 = new Table("foo");
    $table1->addColumn('fk', 'integer');
    $table1->addForeignKeyConstraint($tableForeign, array('fk'), array('id'));

    $table2 = new Table("foo");
    $table2->addColumn('fk', 'integer');
    $table2->addForeignKeyConstraint($tableForeign2, array('fk'), array('id'));

    $c = new Comparator();
    $tableDiff = $c->diffTable($table1, $table2);

    $this->assertInstanceOf('Doctrine\DBAL\Schema\TableDiff', $tableDiff);
    $this->assertEquals(1, count($tableDiff->changedForeignKeys));
  }

  public function testTablesCaseInsensitive() {
    $schemaA = new Schema();
    $schemaA->createTable('foo');
    $schemaA->createTable('bAr');
    $schemaA->createTable('BAZ');
    $schemaA->createTable('new');

    $schemaB = new Schema();
    $schemaB->createTable('FOO');
    $schemaB->createTable('bar');
    $schemaB->createTable('Baz');
    $schemaB->createTable('old');

    $c = new Comparator();
    $diff = $c->compare($schemaA, $schemaB);

    $this->assertSchemaTableChangeCount($diff, 1, 0, 1);
  }

  public function testSequencesCaseInsenstive() {
    $schemaA = new Schema();
    $schemaA->createSequence('foo');
    $schemaA->createSequence('BAR');
    $schemaA->createSequence('Baz');
    $schemaA->createSequence('new');

    $schemaB = new Schema();
    $schemaB->createSequence('FOO');
    $schemaB->createSequence('Bar');
    $schemaB->createSequence('baz');
    $schemaB->createSequence('old');

    $c = new Comparator();
    $diff = $c->compare($schemaA, $schemaB);

    $this->assertSchemaSequenceChangeCount($diff, 1, 0, 1);
  }

  public function testCompareColumnCompareCaseInsensitive() {
    $tableA = new Table("foo");
    $tableA->addColumn('id', 'integer');

    $tableB = new Table("foo");
    $tableB->addColumn('ID', 'integer');

    $c = new Comparator();
    $tableDiff = $c->diffTable($tableA, $tableB);

    $this->assertFalse($tableDiff);
  }

  public function testCompareIndexBasedOnPropertiesNotName() {
    $tableA = new Table("foo");
    $tableA->addColumn('id', 'integer');
    $tableA->addIndex(array("id"), "foo_bar_idx");

    $tableB = new Table("foo");
    $tableB->addColumn('ID', 'integer');
    $tableB->addIndex(array("id"), "bar_foo_idx");

    $c = new Comparator();
    $tableDiff = new TableDiff('foo');
    $tableDiff->fromTable = $tableA;
    $tableDiff->renamedIndexes['foo_bar_idx'] = new Index('bar_foo_idx', array('id'));

    $this->assertEquals(
      $tableDiff,
      $c->diffTable($tableA, $tableB)
    );
  }

  public function testCompareForeignKeyBasedOnPropertiesNotName() {
    $tableA = new Table("foo");
    $tableA->addColumn('id', 'integer');
    $tableA->addNamedForeignKeyConstraint('foo_constraint', 'bar', array('id'), array('id'));

    $tableB = new Table("foo");
    $tableB->addColumn('ID', 'integer');
    $tableB->addNamedForeignKeyConstraint('bar_constraint', 'bar', array('id'), array('id'));

    $c = new Comparator();
    $tableDiff = $c->diffTable($tableA, $tableB);

    $this->assertFalse($tableDiff);
  }

  public function testCompareForeignKey_RestrictNoAction_AreTheSame() {
    $fk1 = new ForeignKeyConstraint(array("foo"), "bar", array("baz"), "fk1", array('onDelete' => 'NO ACTION'));
    $fk2 = new ForeignKeyConstraint(array("foo"), "bar", array("baz"), "fk1", array('onDelete' => 'RESTRICT'));

    $c = new Comparator();
    $this->assertFalse($c->diffForeignKey($fk1, $fk2));
  }

  /**
   * @group DBAL-492
   */
  public function testCompareForeignKeyNamesUnqualified_AsNoSchemaInformationIsAvailable() {
    $fk1 = new ForeignKeyConstraint(array("foo"), "foo.bar", array("baz"), "fk1");
    $fk2 = new ForeignKeyConstraint(array("foo"), "baz.bar", array("baz"), "fk1");

    $c = new Comparator();
    $this->assertFalse($c->diffForeignKey($fk1, $fk2));
  }

  public function testDetectRenameColumn() {
    $tableA = new Table("foo");
    $tableA->addColumn('foo', 'integer');

    $tableB = new Table("foo");
    $tableB->addColumn('bar', 'integer');

    $c = new Comparator();
    $tableDiff = $c->diffTable($tableA, $tableB);

    $this->assertEquals(0, count($tableDiff->addedColumns));
    $this->assertEquals(0, count($tableDiff->removedColumns));
    $this->assertArrayHasKey('foo', $tableDiff->renamedColumns);
    $this->assertEquals('bar', $tableDiff->renamedColumns['foo']->getName());
  }

  /**
   * You can easily have ambiguouties in the column renaming. If these
   * are detected no renaming should take place, instead adding and dropping
   * should be used exclusively.
   *
   * @group DBAL-24
   */
  public function testDetectRenameColumnAmbiguous() {
    $tableA = new Table("foo");
    $tableA->addColumn('foo', 'integer');
    $tableA->addColumn('bar', 'integer');

    $tableB = new Table("foo");
    $tableB->addColumn('baz', 'integer');

    $c = new Comparator();
    $tableDiff = $c->diffTable($tableA, $tableB);

    $this->assertEquals(1, count($tableDiff->addedColumns), "'baz' should be added, not created through renaming!");
    $this->assertArrayHasKey('baz', $tableDiff->addedColumns, "'baz' should be added, not created through renaming!");
    $this->assertEquals(2, count($tableDiff->removedColumns), "'foo' and 'bar' should both be dropped, an ambigouty exists which one could be renamed to 'baz'.");
    $this->assertArrayHasKey('foo', $tableDiff->removedColumns, "'foo' should be removed.");
    $this->assertArrayHasKey('bar', $tableDiff->removedColumns, "'bar' should be removed.");
    $this->assertEquals(0, count($tableDiff->renamedColumns), "no renamings should take place.");
  }

  /**
   * @group DBAL-1063
   */
  public function testDetectRenameIndex() {
    $table1 = new Table('foo');
    $table1->addColumn('foo', 'integer');

    $table2 = clone $table1;

    $table1->addIndex(array('foo'), 'idx_foo');

    $table2->addIndex(array('foo'), 'idx_bar');

    $comparator = new Comparator();
    $tableDiff = $comparator->diffTable($table1, $table2);

    $this->assertCount(0, $tableDiff->addedIndexes);
    $this->assertCount(0, $tableDiff->removedIndexes);
    $this->assertArrayHasKey('idx_foo', $tableDiff->renamedIndexes);
    $this->assertEquals('idx_bar', $tableDiff->renamedIndexes['idx_foo']->getName());
  }

  /**
   * You can easily have ambiguities in the index renaming. If these
   * are detected no renaming should take place, instead adding and dropping
   * should be used exclusively.
   *
   * @group DBAL-1063
   */
  public function testDetectRenameIndexAmbiguous() {
    $table1 = new Table('foo');
    $table1->addColumn('foo', 'integer');

    $table2 = clone $table1;

    $table1->addIndex(array('foo'), 'idx_foo');
    $table1->addIndex(array('foo'), 'idx_bar');

    $table2->addIndex(array('foo'), 'idx_baz');

    $comparator = new Comparator();
    $tableDiff = $comparator->diffTable($table1, $table2);

    $this->assertCount(1, $tableDiff->addedIndexes);
    $this->assertArrayHasKey('idx_baz', $tableDiff->addedIndexes);
    $this->assertCount(2, $tableDiff->removedIndexes);
    $this->assertArrayHasKey('idx_foo', $tableDiff->removedIndexes);
    $this->assertArrayHasKey('idx_bar', $tableDiff->removedIndexes);
    $this->assertCount(0, $tableDiff->renamedIndexes);
  }

  public function testDetectChangeIdentifierType() {
    $this->markTestSkipped('DBAL-2 was reopened, this test cannot work anymore.');

    $tableA = new Table("foo");
    $tableA->addColumn('id', 'integer', array('autoincrement' => FALSE));

    $tableB = new Table("foo");
    $tableB->addColumn('id', 'integer', array('autoincrement' => TRUE));

    $c = new Comparator();
    $tableDiff = $c->diffTable($tableA, $tableB);

    $this->assertInstanceOf('Doctrine\DBAL\Schema\TableDiff', $tableDiff);
    $this->assertArrayHasKey('id', $tableDiff->changedColumns);
  }


  /**
   * @group DBAL-105
   */
  public function testDiff() {
    $table = new \Doctrine\DBAL\Schema\Table('twitter_users');
    $table->addColumn('id', 'integer', array('autoincrement' => TRUE));
    $table->addColumn('twitterId', 'integer', array('nullable' => FALSE));
    $table->addColumn('displayName', 'string', array('nullable' => FALSE));
    $table->setPrimaryKey(array('id'));

    $newtable = new \Doctrine\DBAL\Schema\Table('twitter_users');
    $newtable->addColumn('id', 'integer', array('autoincrement' => TRUE));
    $newtable->addColumn('twitter_id', 'integer', array('nullable' => FALSE));
    $newtable->addColumn('display_name', 'string', array('nullable' => FALSE));
    $newtable->addColumn('logged_in_at', 'datetime', array('nullable' => TRUE));
    $newtable->setPrimaryKey(array('id'));

    $c = new Comparator();
    $tableDiff = $c->diffTable($table, $newtable);

    $this->assertInstanceOf('Doctrine\DBAL\Schema\TableDiff', $tableDiff);
    $this->assertEquals(array(
      'twitterid',
      'displayname'
    ), array_keys($tableDiff->renamedColumns));
    $this->assertEquals(array('logged_in_at'), array_keys($tableDiff->addedColumns));
    $this->assertEquals(0, count($tableDiff->removedColumns));
  }


  /**
   * @group DBAL-112
   */
  public function testChangedSequence() {
    $schema = new Schema();
    $sequence = $schema->createSequence('baz');

    $schemaNew = clone $schema;
    /* @var $schemaNew Schema */
    $schemaNew->getSequence('baz')->setAllocationSize(20);

    $c = new \Doctrine\DBAL\Schema\Comparator;
    $diff = $c->compare($schema, $schemaNew);

    $this->assertSame($diff->changedSequences[0], $schemaNew->getSequence('baz'));
  }

  /**
   * @group DBAL-106
   */
  public function testDiffDecimalWithNullPrecision() {
    $column = new Column('foo', Type::getType('decimal'));
    $column->setPrecision(NULL);

    $column2 = new Column('foo', Type::getType('decimal'));

    $c = new Comparator();
    $this->assertEquals(array(), $c->diffColumn($column, $column2));
  }

  /**
   * @group DBAL-204
   */
  public function testFqnSchemaComparision() {
    $config = new SchemaConfig();
    $config->setName("foo");

    $oldSchema = new Schema(array(), array(), $config);
    $oldSchema->createTable('bar');

    $newSchema = new Schema(array(), array(), $config);
    $newSchema->createTable('foo.bar');

    $expected = new SchemaDiff();
    $expected->fromSchema = $oldSchema;

    $this->assertEquals($expected, Comparator::compareSchemas($oldSchema, $newSchema));
  }

  /**
   * @group DBAL-669
   */
  public function testNamespacesComparison() {
    $config = new SchemaConfig();
    $config->setName("schemaName");

    $oldSchema = new Schema(array(), array(), $config);
    $oldSchema->createTable('taz');
    $oldSchema->createTable('war.tab');

    $newSchema = new Schema(array(), array(), $config);
    $newSchema->createTable('bar.tab');
    $newSchema->createTable('baz.tab');
    $newSchema->createTable('war.tab');

    $expected = new SchemaDiff();
    $expected->fromSchema = $oldSchema;
    $expected->newNamespaces = array('bar' => 'bar', 'baz' => 'baz');

    $diff = Comparator::compareSchemas($oldSchema, $newSchema);

    $this->assertEquals(array(
      'bar' => 'bar',
      'baz' => 'baz'
    ), $diff->newNamespaces);
    $this->assertCount(2, $diff->newTables);
  }

  /**
   * @group DBAL-204
   */
  public function testFqnSchemaComparisionDifferentSchemaNameButSameTableNoDiff() {
    $config = new SchemaConfig();
    $config->setName("foo");

    $oldSchema = new Schema(array(), array(), $config);
    $oldSchema->createTable('foo.bar');

    $newSchema = new Schema();
    $newSchema->createTable('bar');

    $expected = new SchemaDiff();
    $expected->fromSchema = $oldSchema;

    $this->assertEquals($expected, Comparator::compareSchemas($oldSchema, $newSchema));
  }

  /**
   * @group DBAL-204
   */
  public function testFqnSchemaComparisionNoSchemaSame() {
    $config = new SchemaConfig();
    $config->setName("foo");
    $oldSchema = new Schema(array(), array(), $config);
    $oldSchema->createTable('bar');

    $newSchema = new Schema();
    $newSchema->createTable('bar');

    $expected = new SchemaDiff();
    $expected->fromSchema = $oldSchema;

    $this->assertEquals($expected, Comparator::compareSchemas($oldSchema, $newSchema));
  }

  /**
   * @group DDC-1657
   */
  public function testAutoIncremenetSequences() {
    $oldSchema = new Schema();
    $table = $oldSchema->createTable("foo");
    $table->addColumn("id", "integer", array("autoincrement" => TRUE));
    $table->setPrimaryKey(array("id"));
    $oldSchema->createSequence("foo_id_seq");

    $newSchema = new Schema();
    $table = $newSchema->createTable("foo");
    $table->addColumn("id", "integer", array("autoincrement" => TRUE));
    $table->setPrimaryKey(array("id"));

    $c = new Comparator();
    $diff = $c->compare($oldSchema, $newSchema);

    $this->assertCount(0, $diff->removedSequences);
  }


  /**
   * Check that added autoincrement sequence is not populated in newSequences
   *
   * @group DBAL-562
   */
  public function testAutoIncremenetNoSequences() {
    $oldSchema = new Schema();
    $table = $oldSchema->createTable("foo");
    $table->addColumn("id", "integer", array("autoincrement" => TRUE));
    $table->setPrimaryKey(array("id"));

    $newSchema = new Schema();
    $table = $newSchema->createTable("foo");
    $table->addColumn("id", "integer", array("autoincrement" => TRUE));
    $table->setPrimaryKey(array("id"));
    $newSchema->createSequence("foo_id_seq");

    $c = new Comparator();
    $diff = $c->compare($oldSchema, $newSchema);

    $this->assertCount(0, $diff->newSequences);
  }

  /**
   * You can get multiple drops for a FK when a table referenced by a foreign
   * key is deleted, as this FK is referenced twice, once on the
   * orphanedForeignKeys array because of the dropped table, and once on
   * changedTables array. We now check that the key is present once.
   */
  public function testAvoidMultipleDropForeignKey() {
    $oldSchema = new Schema();

    $tableA = $oldSchema->createTable('table_a');
    $tableA->addColumn('id', 'integer');

    $tableB = $oldSchema->createTable('table_b');
    $tableB->addColumn('id', 'integer');

    $tableC = $oldSchema->createTable('table_c');
    $tableC->addColumn('id', 'integer');
    $tableC->addColumn('table_a_id', 'integer');
    $tableC->addColumn('table_b_id', 'integer');

    $tableC->addForeignKeyConstraint($tableA, array('table_a_id'), array('id'));
    $tableC->addForeignKeyConstraint($tableB, array('table_b_id'), array('id'));

    $newSchema = new Schema();

    $tableB = $newSchema->createTable('table_b');
    $tableB->addColumn('id', 'integer');

    $tableC = $newSchema->createTable('table_c');
    $tableC->addColumn('id', 'integer');

    $comparator = new Comparator();
    $schemaDiff = $comparator->compare($oldSchema, $newSchema);

    $this->assertCount(1, $schemaDiff->changedTables['table_c']->removedForeignKeys);
    $this->assertCount(1, $schemaDiff->orphanedForeignKeys);
  }

  public function testCompareChangedColumn() {
    $oldSchema = new Schema();

    $tableFoo = $oldSchema->createTable('foo');
    $tableFoo->addColumn('id', 'integer');

    $newSchema = new Schema();
    $table = $newSchema->createTable('foo');
    $table->addColumn('id', 'string');

    $expected = new SchemaDiff();
    $expected->fromSchema = $oldSchema;
    $tableDiff = $expected->changedTables['foo'] = new TableDiff('foo');
    $tableDiff->fromTable = $tableFoo;
    $columnDiff = $tableDiff->changedColumns['id'] = new ColumnDiff('id', $table->getColumn('id'));
    $columnDiff->fromColumn = $tableFoo->getColumn('id');
    $columnDiff->changedProperties = array('type');

    $this->assertEquals($expected, Comparator::compareSchemas($oldSchema, $newSchema));
  }

  public function testCompareChangedBinaryColumn() {
    $oldSchema = new Schema();

    $tableFoo = $oldSchema->createTable('foo');
    $tableFoo->addColumn('id', 'binary');

    $newSchema = new Schema();
    $table = $newSchema->createTable('foo');
    $table->addColumn('id', 'binary', array('length' => 42, 'fixed' => TRUE));

    $expected = new SchemaDiff();
    $expected->fromSchema = $oldSchema;
    $tableDiff = $expected->changedTables['foo'] = new TableDiff('foo');
    $tableDiff->fromTable = $tableFoo;
    $columnDiff = $tableDiff->changedColumns['id'] = new ColumnDiff('id', $table->getColumn('id'));
    $columnDiff->fromColumn = $tableFoo->getColumn('id');
    $columnDiff->changedProperties = array('length', 'fixed');

    $this->assertEquals($expected, Comparator::compareSchemas($oldSchema, $newSchema));
  }

  /**
   * @group DBAL-617
   */
  public function testCompareQuotedAndUnquotedForeignKeyColumns() {
    $fk1 = new ForeignKeyConstraint(array("foo"), "bar", array("baz"), "fk1", array('onDelete' => 'NO ACTION'));
    $fk2 = new ForeignKeyConstraint(array("`foo`"), "bar", array("`baz`"), "fk1", array('onDelete' => 'NO ACTION'));

    $comparator = new Comparator();
    $diff = $comparator->diffForeignKey($fk1, $fk2);

    $this->assertFalse($diff);
  }

  /**
   * @param SchemaDiff $diff
   * @param int $newTableCount
   * @param int $changeTableCount
   * @param int $removeTableCount
   */
  public function assertSchemaTableChangeCount($diff, $newTableCount = 0, $changeTableCount = 0, $removeTableCount = 0) {
    $this->assertEquals($newTableCount, count($diff->newTables));
    $this->assertEquals($changeTableCount, count($diff->changedTables));
    $this->assertEquals($removeTableCount, count($diff->removedTables));
  }

  /**
   * @param SchemaDiff $diff
   * @param int $newSequenceCount
   * @param int $changeSequenceCount
   * @param int $changeSequenceCount
   */
  public function assertSchemaSequenceChangeCount($diff, $newSequenceCount = 0, $changeSequenceCount = 0, $removeSequenceCount = 0) {
    $this->assertEquals($newSequenceCount, count($diff->newSequences), "Expected number of new sequences is wrong.");
    $this->assertEquals($changeSequenceCount, count($diff->changedSequences), "Expected number of changed sequences is wrong.");
    $this->assertEquals($removeSequenceCount, count($diff->removedSequences), "Expected number of removed sequences is wrong.");
  }

  public function testDiffColumnPlatformOptions() {
    $column1 = new Column('foo', Type::getType('string'), array(
      'platformOptions' => array(
        'foo' => 'foo',
        'bar' => 'bar'
      )
    ));
    $column2 = new Column('foo', Type::getType('string'), array(
      'platformOptions' => array(
        'foo' => 'foo',
        'foobar' => 'foobar'
      )
    ));
    $column3 = new Column('foo', Type::getType('string'), array(
      'platformOptions' => array(
        'foo' => 'foo',
        'bar' => 'rab'
      )
    ));
    $column4 = new Column('foo', Type::getType('string'));

    $comparator = new Comparator();

    $this->assertEquals(array(), $comparator->diffColumn($column1, $column2));
    $this->assertEquals(array(), $comparator->diffColumn($column2, $column1));
    $this->assertEquals(array('bar'), $comparator->diffColumn($column1, $column3));
    $this->assertEquals(array('bar'), $comparator->diffColumn($column3, $column1));
    $this->assertEquals(array(), $comparator->diffColumn($column1, $column4));
    $this->assertEquals(array(), $comparator->diffColumn($column4, $column1));
  }

  public function testComplexDiffColumn() {
    $column1 = new Column('foo', Type::getType('string'), array(
      'platformOptions' => array('foo' => 'foo'),
      'customSchemaOptions' => array('foo' => 'bar'),
    ));

    $column2 = new Column('foo', Type::getType('string'), array(
      'platformOptions' => array('foo' => 'bar'),
    ));

    $comparator = new Comparator();

    $this->assertEquals(array(), $comparator->diffColumn($column1, $column2));
    $this->assertEquals(array(), $comparator->diffColumn($column2, $column1));
  }

  /**
   * @group DBAL-669
   */
  public function testComparesNamespaces() {
    $comparator = new Comparator();
    $fromSchema = $this->getMock('Doctrine\DBAL\Schema\Schema', array(
      'getNamespaces',
      'hasNamespace'
    ));
    $toSchema = $this->getMock('Doctrine\DBAL\Schema\Schema', array(
      'getNamespaces',
      'hasNamespace'
    ));

    $fromSchema->expects($this->once())
      ->method('getNamespaces')
      ->will($this->returnValue(array('foo', 'bar')));

    $fromSchema->expects($this->at(0))
      ->method('hasNamespace')
      ->with('bar')
      ->will($this->returnValue(TRUE));

    $fromSchema->expects($this->at(1))
      ->method('hasNamespace')
      ->with('baz')
      ->will($this->returnValue(FALSE));

    $toSchema->expects($this->once())
      ->method('getNamespaces')
      ->will($this->returnValue(array('bar', 'baz')));

    $toSchema->expects($this->at(1))
      ->method('hasNamespace')
      ->with('foo')
      ->will($this->returnValue(FALSE));

    $toSchema->expects($this->at(2))
      ->method('hasNamespace')
      ->with('bar')
      ->will($this->returnValue(TRUE));

    $expected = new SchemaDiff();
    $expected->fromSchema = $fromSchema;
    $expected->newNamespaces = array('baz' => 'baz');
    $expected->removedNamespaces = array('foo' => 'foo');

    $this->assertEquals($expected, $comparator->compare($fromSchema, $toSchema));
  }

  public function testCompareGuidColumns() {
    $comparator = new Comparator();

    $column1 = new Column('foo', Type::getType('guid'), array('comment' => 'GUID 1'));
    $column2 = new Column(
      'foo',
      Type::getType('guid'),
      array(
        'notnull' => FALSE,
        'length' => '36',
        'fixed' => TRUE,
        'default' => 'NEWID()',
        'comment' => 'GUID 2.'
      )
    );

    $this->assertEquals(array(
      'notnull',
      'default',
      'comment'
    ), $comparator->diffColumn($column1, $column2));
    $this->assertEquals(array(
      'notnull',
      'default',
      'comment'
    ), $comparator->diffColumn($column2, $column1));
  }

  /**
   * @group DBAL-1009
   *
   * @dataProvider getCompareColumnComments
   */
  public function testCompareColumnComments($comment1, $comment2, $equals) {
    $column1 = new Column('foo', Type::getType('integer'), array('comment' => $comment1));
    $column2 = new Column('foo', Type::getType('integer'), array('comment' => $comment2));

    $comparator = new Comparator();

    $expectedDiff = $equals ? array() : array('comment');

    $actualDiff = $comparator->diffColumn($column1, $column2);

    $this->assertSame($expectedDiff, $actualDiff);

    $actualDiff = $comparator->diffColumn($column2, $column1);

    $this->assertSame($expectedDiff, $actualDiff);
  }

  public function getCompareColumnComments() {
    return array(
      array(NULL, NULL, TRUE),
      array('', '', TRUE),
      array(' ', ' ', TRUE),
      array('0', '0', TRUE),
      array('foo', 'foo', TRUE),

      array(NULL, '', TRUE),
      array(NULL, ' ', FALSE),
      array(NULL, '0', FALSE),
      array(NULL, 'foo', FALSE),

      array('', ' ', FALSE),
      array('', '0', FALSE),
      array('', 'foo', FALSE),

      array(' ', '0', FALSE),
      array(' ', 'foo', FALSE),

      array('0', 'foo', FALSE),
    );
  }
}
