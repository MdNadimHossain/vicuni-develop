<?php

namespace Doctrine\Tests\ORM\Mapping;

use Doctrine\ORM\Mapping\UnderscoreNamingStrategy;
use Doctrine\ORM\Mapping\DefaultNamingStrategy;
use Doctrine\ORM\Mapping\NamingStrategy;
use Doctrine\Tests\ORM\Mapping\NamingStrategy\JoinColumnClassNamingStrategy;

/**
 * @group DDC-559
 */
class NamingStrategyTest extends \Doctrine\Tests\OrmTestCase {
  /**
   * @return DefaultNamingStrategy
   */
  static private function defaultNaming() {
    return new DefaultNamingStrategy();
  }

  /**
   * @return UnderscoreNamingStrategy
   */
  static private function underscoreNamingLower() {
    return new UnderscoreNamingStrategy(CASE_LOWER);
  }

  /**
   * @return UnderscoreNamingStrategy
   */
  static private function underscoreNamingUpper() {
    return new UnderscoreNamingStrategy(CASE_UPPER);
  }

  /**
   * Data Provider for NamingStrategy#classToTableName
   *
   * @return array
   */
  static public function dataClassToTableName() {
    return array(
      // DefaultNamingStrategy
      array(
        self::defaultNaming(),
        'SomeClassName',
        'SomeClassName'
      ),
      array(
        self::defaultNaming(),
        'SomeClassName',
        '\SomeClassName'
      ),
      array(
        self::defaultNaming(),
        'Name',
        '\Some\Class\Name'
      ),

      // UnderscoreNamingStrategy
      array(
        self::underscoreNamingLower(),
        'some_class_name',
        '\Name\Space\SomeClassName'
      ),
      array(
        self::underscoreNamingLower(),
        'name',
        '\Some\Class\Name'
      ),
      array(
        self::underscoreNamingUpper(),
        'SOME_CLASS_NAME',
        '\Name\Space\SomeClassName'
      ),
      array(
        self::underscoreNamingUpper(),
        'NAME',
        '\Some\Class\Name'
      ),
    );
  }

  /**
   * @dataProvider dataClassToTableName
   */
  public function testClassToTableName(NamingStrategy $strategy, $expected, $className) {
    $this->assertEquals($expected, $strategy->classToTableName($className));
  }

  /**
   * Data Provider for NamingStrategy#propertyToColumnName
   *
   * @return array
   */
  static public function dataPropertyToColumnName() {
    return array(
      // DefaultNamingStrategy
      array(
        self::defaultNaming(),
        'someProperty',
        'someProperty'
      ),
      array(
        self::defaultNaming(),
        'SOME_PROPERTY',
        'SOME_PROPERTY'
      ),
      array(
        self::defaultNaming(),
        'some_property',
        'some_property'
      ),

      // UnderscoreNamingStrategy
      array(
        self::underscoreNamingLower(),
        'some_property',
        'someProperty'
      ),
      array(
        self::underscoreNamingUpper(),
        'SOME_PROPERTY',
        'someProperty'
      ),
      array(
        self::underscoreNamingUpper(),
        'SOME_PROPERTY',
        'some_property'
      ),
      array(
        self::underscoreNamingUpper(),
        'SOME_PROPERTY',
        'SOME_PROPERTY'
      ),
    );
  }

  /**
   * @dataProvider dataPropertyToColumnName
   *
   * @param NamingStrategy $strategy
   * @param string $expected
   * @param string $propertyName
   */
  public function testPropertyToColumnName(NamingStrategy $strategy, $expected, $propertyName) {
    $this->assertEquals($expected, $strategy->propertyToColumnName($propertyName));
  }

  /**
   * Data Provider for NamingStrategy#referenceColumnName
   *
   * @return array
   */
  static public function dataReferenceColumnName() {
    return array(
      // DefaultNamingStrategy
      array(self::defaultNaming(), 'id'),

      // UnderscoreNamingStrategy
      array(self::underscoreNamingLower(), 'id'),
      array(self::underscoreNamingUpper(), 'ID'),
    );
  }

  /**
   * @dataProvider dataReferenceColumnName
   *
   * @param NamingStrategy $strategy
   * @param string $expected
   */
  public function testReferenceColumnName(NamingStrategy $strategy, $expected) {
    $this->assertEquals($expected, $strategy->referenceColumnName());
  }

  /**
   * Data Provider for NamingStrategy#joinColumnName
   *
   * @return array
   */
  static public function dataJoinColumnName() {
    return array(
      // DefaultNamingStrategy
      array(self::defaultNaming(), 'someColumn_id', 'someColumn', NULL),
      array(self::defaultNaming(), 'some_column_id', 'some_column', NULL),

      // UnderscoreNamingStrategy
      array(
        self::underscoreNamingLower(),
        'some_column_id',
        'someColumn',
        NULL
      ),
      array(
        self::underscoreNamingUpper(),
        'SOME_COLUMN_ID',
        'someColumn',
        NULL
      ),
      // JoinColumnClassNamingStrategy
      array(
        new JoinColumnClassNamingStrategy(),
        'classname_someColumn_id',
        'someColumn',
        'Some\ClassName'
      ),
      array(
        new JoinColumnClassNamingStrategy(),
        'classname_some_column_id',
        'some_column',
        'ClassName'
      ),
    );
  }

  /**
   * @dataProvider dataJoinColumnName
   *
   * @param NamingStrategy $strategy
   * @param string $expected
   * @param string $propertyName
   */
  public function testJoinColumnName(NamingStrategy $strategy, $expected, $propertyName, $className = NULL) {
    $this->assertEquals($expected, $strategy->joinColumnName($propertyName, $className));
  }

  /**
   * Data Provider for NamingStrategy#joinTableName
   *
   * @return array
   */
  static public function dataJoinTableName() {
    return array(
      // DefaultNamingStrategy
      array(
        self::defaultNaming(),
        'someclassname_classname',
        'SomeClassName',
        'Some\ClassName',
        NULL,
      ),
      array(
        self::defaultNaming(),
        'someclassname_classname',
        '\SomeClassName',
        'ClassName',
        NULL,
      ),
      array(
        self::defaultNaming(),
        'name_classname',
        '\Some\Class\Name',
        'ClassName',
        NULL,
      ),

      // UnderscoreNamingStrategy
      array(
        self::underscoreNamingLower(),
        'some_class_name_class_name',
        'SomeClassName',
        'Some\ClassName',
        NULL,
      ),
      array(
        self::underscoreNamingLower(),
        'some_class_name_class_name',
        '\SomeClassName',
        'ClassName',
        NULL,
      ),
      array(
        self::underscoreNamingLower(),
        'name_class_name',
        '\Some\Class\Name',
        'ClassName',
        NULL,
      ),

      array(
        self::underscoreNamingUpper(),
        'SOME_CLASS_NAME_CLASS_NAME',
        'SomeClassName',
        'Some\ClassName',
        NULL,
      ),
      array(
        self::underscoreNamingUpper(),
        'SOME_CLASS_NAME_CLASS_NAME',
        '\SomeClassName',
        'ClassName',
        NULL,
      ),
      array(
        self::underscoreNamingUpper(),
        'NAME_CLASS_NAME',
        '\Some\Class\Name',
        'ClassName',
        NULL,
      ),
    );
  }

  /**
   * @dataProvider dataJoinTableName
   *
   * @param NamingStrategy $strategy
   * @param string $expected
   * @param string $ownerEntity
   * @param string $associatedEntity
   * @param string $propertyName
   */
  public function testJoinTableName(NamingStrategy $strategy, $expected, $ownerEntity, $associatedEntity, $propertyName = NULL) {
    $this->assertEquals($expected, $strategy->joinTableName($ownerEntity, $associatedEntity, $propertyName));
  }

  /**
   * Data Provider for NamingStrategy#joinKeyColumnName
   *
   * @return array
   */
  static public function dataJoinKeyColumnName() {
    return array(
      // DefaultNamingStrategy
      array(
        self::defaultNaming(),
        'someclassname_id',
        'SomeClassName',
        NULL,
        NULL,
      ),
      array(
        self::defaultNaming(),
        'name_identifier',
        '\Some\Class\Name',
        'identifier',
        NULL,
      ),

      // UnderscoreNamingStrategy
      array(
        self::underscoreNamingLower(),
        'some_class_name_id',
        'SomeClassName',
        NULL,
        NULL,
      ),
      array(
        self::underscoreNamingLower(),
        'class_name_identifier',
        '\Some\Class\ClassName',
        'identifier',
        NULL,
      ),

      array(
        self::underscoreNamingUpper(),
        'SOME_CLASS_NAME_ID',
        'SomeClassName',
        NULL,
        NULL,
      ),
      array(
        self::underscoreNamingUpper(),
        'CLASS_NAME_IDENTIFIER',
        '\Some\Class\ClassName',
        'IDENTIFIER',
        NULL,
      ),
    );
  }

  /**
   * @dataProvider dataJoinKeyColumnName
   *
   * @param NamingStrategy $strategy
   * @param string $expected
   * @param string $propertyEntityName
   * @param string $referencedColumnName
   * @param string $propertyName
   */
  public function testJoinKeyColumnName(NamingStrategy $strategy, $expected, $propertyEntityName, $referencedColumnName = NULL, $propertyName = NULL) {
    $this->assertEquals($expected, $strategy->joinKeyColumnName($propertyEntityName, $referencedColumnName, $propertyName));
  }
}
