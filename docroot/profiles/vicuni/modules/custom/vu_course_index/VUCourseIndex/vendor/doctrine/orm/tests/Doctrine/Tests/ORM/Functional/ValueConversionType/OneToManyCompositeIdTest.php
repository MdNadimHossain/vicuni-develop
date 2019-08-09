<?php

namespace Doctrine\Tests\ORM\Functional\ValueConversionType;

use Doctrine\DBAL\Types\Type as DBALType;
use Doctrine\Tests\Models\ValueConversionType as Entity;
use Doctrine\Tests\OrmFunctionalTestCase;

/**
 * The entities all use a custom type that converst the value as identifier(s).
 * {@see \Doctrine\Tests\DbalTypes\Rot13Type}
 *
 * Test that OneToMany associations with composite id work correctly.
 *
 * @group DDC-3380
 */
class OneToManyCompositeIdTest extends OrmFunctionalTestCase {
  public function setUp() {
    $this->useModelSet('vct_onetomany_compositeid');

    parent::setUp();

    $inversed = new Entity\InversedOneToManyCompositeIdEntity();
    $inversed->id1 = 'abc';
    $inversed->id2 = 'def';
    $inversed->someProperty = 'some value to be loaded';

    $owning = new Entity\OwningManyToOneCompositeIdEntity();
    $owning->id3 = 'ghi';

    $inversed->associatedEntities->add($owning);
    $owning->associatedEntity = $inversed;

    $this->_em->persist($inversed);
    $this->_em->persist($owning);

    $this->_em->flush();
    $this->_em->clear();
  }

  public static function tearDownAfterClass() {
    $conn = static::$_sharedConn;

    $conn->executeUpdate('DROP TABLE vct_owning_manytoone_compositeid');
    $conn->executeUpdate('DROP TABLE vct_inversed_onetomany_compositeid');
  }

  public function testThatTheValueOfIdentifiersAreConvertedInTheDatabase() {
    $conn = $this->_em->getConnection();

    $this->assertEquals('nop', $conn->fetchColumn('SELECT id1 FROM vct_inversed_onetomany_compositeid LIMIT 1'));
    $this->assertEquals('qrs', $conn->fetchColumn('SELECT id2 FROM vct_inversed_onetomany_compositeid LIMIT 1'));

    $this->assertEquals('tuv', $conn->fetchColumn('SELECT id3 FROM vct_owning_manytoone_compositeid LIMIT 1'));
    $this->assertEquals('nop', $conn->fetchColumn('SELECT associated_id1 FROM vct_owning_manytoone_compositeid LIMIT 1'));
    $this->assertEquals('qrs', $conn->fetchColumn('SELECT associated_id2 FROM vct_owning_manytoone_compositeid LIMIT 1'));
  }

  /**
   * @depends testThatTheValueOfIdentifiersAreConvertedInTheDatabase
   */
  public function testThatEntitiesAreFetchedFromTheDatabase() {
    $inversed = $this->_em->find(
      'Doctrine\Tests\Models\ValueConversionType\InversedOneToManyCompositeIdEntity',
      array('id1' => 'abc', 'id2' => 'def')
    );

    $owning = $this->_em->find(
      'Doctrine\Tests\Models\ValueConversionType\OwningManyToOneCompositeIdEntity',
      'ghi'
    );

    $this->assertInstanceOf('Doctrine\Tests\Models\ValueConversionType\InversedOneToManyCompositeIdEntity', $inversed);
    $this->assertInstanceOf('Doctrine\Tests\Models\ValueConversionType\OwningManyToOneCompositeIdEntity', $owning);
  }

  /**
   * @depends testThatEntitiesAreFetchedFromTheDatabase
   */
  public function testThatTheValueOfIdentifiersAreConvertedBackAfterBeingFetchedFromTheDatabase() {
    $inversed = $this->_em->find(
      'Doctrine\Tests\Models\ValueConversionType\InversedOneToManyCompositeIdEntity',
      array('id1' => 'abc', 'id2' => 'def')
    );

    $owning = $this->_em->find(
      'Doctrine\Tests\Models\ValueConversionType\OwningManyToOneCompositeIdEntity',
      'ghi'
    );

    $this->assertEquals('abc', $inversed->id1);
    $this->assertEquals('def', $inversed->id2);
    $this->assertEquals('ghi', $owning->id3);
  }

  /**
   * @depends testThatEntitiesAreFetchedFromTheDatabase
   */
  public function testThatTheProxyFromOwningToInversedIsLoaded() {
    $owning = $this->_em->find(
      'Doctrine\Tests\Models\ValueConversionType\OwningManyToOneCompositeIdEntity',
      'ghi'
    );

    $inversedProxy = $owning->associatedEntity;

    $this->assertEquals('some value to be loaded', $inversedProxy->someProperty);
  }

  /**
   * @depends testThatEntitiesAreFetchedFromTheDatabase
   */
  public function testThatTheCollectionFromInversedToOwningIsLoaded() {
    $inversed = $this->_em->find(
      'Doctrine\Tests\Models\ValueConversionType\InversedOneToManyCompositeIdEntity',
      array('id1' => 'abc', 'id2' => 'def')
    );

    $this->assertCount(1, $inversed->associatedEntities);
  }
}
