<?php

namespace Doctrine\Tests\ORM\Functional\Locking;

use Doctrine\ORM\Mapping\ClassMetadata;
use Doctrine\ORM\OptimisticLockException;
use Doctrine\Common\EventManager;
use Doctrine\ORM\Mapping\ClassMetadataFactory;
use Doctrine\Tests\TestUtil;
use Doctrine\DBAL\LockMode;
use DateTime;

class OptimisticTest extends \Doctrine\Tests\OrmFunctionalTestCase {
  protected function setUp() {
    parent::setUp();

    try {
      $this->_schemaTool->createSchema(array(
        $this->_em->getClassMetadata('Doctrine\Tests\ORM\Functional\Locking\OptimisticJoinedParent'),
        $this->_em->getClassMetadata('Doctrine\Tests\ORM\Functional\Locking\OptimisticJoinedChild'),
        $this->_em->getClassMetadata('Doctrine\Tests\ORM\Functional\Locking\OptimisticStandard'),
        $this->_em->getClassMetadata('Doctrine\Tests\ORM\Functional\Locking\OptimisticTimestamp')
      ));
    }
    catch (\Exception $e) {
      // Swallow all exceptions. We do not test the schema tool here.
    }
    $this->_conn = $this->_em->getConnection();
  }

  public function testJoinedChildInsertSetsInitialVersionValue() {
    $test = new OptimisticJoinedChild();
    $test->name = 'child';
    $test->whatever = 'whatever';
    $this->_em->persist($test);
    $this->_em->flush();

    $this->assertEquals(1, $test->version);

    return $test;
  }

  /**
   * @depends testJoinedChildInsertSetsInitialVersionValue
   */
  public function testJoinedChildFailureThrowsException(OptimisticJoinedChild $child) {
    $q = $this->_em->createQuery('SELECT t FROM Doctrine\Tests\ORM\Functional\Locking\OptimisticJoinedChild t WHERE t.id = :id');
    $q->setParameter('id', $child->id);
    $test = $q->getSingleResult();

    // Manually update/increment the version so we can try and save the same
    // $test and make sure the exception is thrown saying the record was
    // changed or updated since you read it
    $this->_conn->executeQuery('UPDATE optimistic_joined_parent SET version = ? WHERE id = ?', array(
      2,
      $test->id
    ));

    // Now lets change a property and try and save it again
    $test->whatever = 'ok';
    try {
      $this->_em->flush();
    }
    catch (OptimisticLockException $e) {
      $this->assertSame($test, $e->getEntity());
    }
  }

  public function testJoinedParentInsertSetsInitialVersionValue() {
    $test = new OptimisticJoinedParent();
    $test->name = 'parent';
    $this->_em->persist($test);
    $this->_em->flush();

    $this->assertEquals(1, $test->version);

    return $test;
  }

  /**
   * @depends testJoinedParentInsertSetsInitialVersionValue
   */
  public function testJoinedParentFailureThrowsException(OptimisticJoinedParent $parent) {
    $q = $this->_em->createQuery('SELECT t FROM Doctrine\Tests\ORM\Functional\Locking\OptimisticJoinedParent t WHERE t.id = :id');
    $q->setParameter('id', $parent->id);
    $test = $q->getSingleResult();

    // Manually update/increment the version so we can try and save the same
    // $test and make sure the exception is thrown saying the record was
    // changed or updated since you read it
    $this->_conn->executeQuery('UPDATE optimistic_joined_parent SET version = ? WHERE id = ?', array(
      2,
      $test->id
    ));

    // Now lets change a property and try and save it again
    $test->name = 'WHATT???';
    try {
      $this->_em->flush();
    }
    catch (OptimisticLockException $e) {
      $this->assertSame($test, $e->getEntity());
    }
  }

  public function testMultipleFlushesDoIncrementalUpdates() {
    $test = new OptimisticStandard();

    for ($i = 0; $i < 5; $i++) {
      $test->name = 'test' . $i;
      $this->_em->persist($test);
      $this->_em->flush();

      $this->assertInternalType('int', $test->getVersion());
      $this->assertEquals($i + 1, $test->getVersion());
    }
  }

  public function testStandardInsertSetsInitialVersionValue() {
    $test = new OptimisticStandard();
    $test->name = 'test';
    $this->_em->persist($test);
    $this->_em->flush();

    $this->assertInternalType('int', $test->getVersion());
    $this->assertEquals(1, $test->getVersion());

    return $test;
  }

  /**
   * @depends testStandardInsertSetsInitialVersionValue
   */
  public function testStandardFailureThrowsException(OptimisticStandard $entity) {
    $q = $this->_em->createQuery('SELECT t FROM Doctrine\Tests\ORM\Functional\Locking\OptimisticStandard t WHERE t.id = :id');
    $q->setParameter('id', $entity->id);
    $test = $q->getSingleResult();

    // Manually update/increment the version so we can try and save the same
    // $test and make sure the exception is thrown saying the record was
    // changed or updated since you read it
    $this->_conn->executeQuery('UPDATE optimistic_standard SET version = ? WHERE id = ?', array(
      2,
      $test->id
    ));

    // Now lets change a property and try and save it again
    $test->name = 'WHATT???';
    try {
      $this->_em->flush();
    }
    catch (OptimisticLockException $e) {
      $this->assertSame($test, $e->getEntity());
    }
  }

  public function testLockWorksWithProxy() {
    $test = new OptimisticStandard();
    $test->name = 'test';
    $this->_em->persist($test);
    $this->_em->flush();
    $this->_em->clear();

    $proxy = $this->_em->getReference('Doctrine\Tests\ORM\Functional\Locking\OptimisticStandard', $test->id);

    $this->_em->lock($proxy, LockMode::OPTIMISTIC, 1);
  }

  public function testOptimisticTimestampSetsDefaultValue() {
    $test = new OptimisticTimestamp();
    $test->name = 'Testing';

    $this->assertNull($test->version, "Pre-Condition");

    $this->_em->persist($test);
    $this->_em->flush();

    $this->assertInstanceOf('DateTime', $test->version);

    return $test;
  }

  /**
   * @depends testOptimisticTimestampSetsDefaultValue
   */
  public function testOptimisticTimestampFailureThrowsException(OptimisticTimestamp $entity) {
    $q = $this->_em->createQuery('SELECT t FROM Doctrine\Tests\ORM\Functional\Locking\OptimisticTimestamp t WHERE t.id = :id');
    $q->setParameter('id', $entity->id);
    $test = $q->getSingleResult();

    $this->assertInstanceOf('DateTime', $test->version);

    // Manually increment the version datetime column
    $format = $this->_em->getConnection()
      ->getDatabasePlatform()
      ->getDateTimeFormatString();
    $this->_conn->executeQuery('UPDATE optimistic_timestamp SET version = ? WHERE id = ?', array(
      date($format, strtotime($test->version->format($format)) + 3600),
      $test->id
    ));

    // Try and update the record and it should throw an exception
    $caughtException = NULL;
    $test->name = 'Testing again';
    try {
      $this->_em->flush();
    }
    catch (OptimisticLockException $e) {
      $caughtException = $e;
    }

    $this->assertNotNull($caughtException, "No OptimisticLockingException was thrown");
    $this->assertSame($test, $caughtException->getEntity());
  }

  /**
   * @depends testOptimisticTimestampSetsDefaultValue
   */
  public function testOptimisticTimestampLockFailureThrowsException(OptimisticTimestamp $entity) {
    $q = $this->_em->createQuery('SELECT t FROM Doctrine\Tests\ORM\Functional\Locking\OptimisticTimestamp t WHERE t.id = :id');
    $q->setParameter('id', $entity->id);
    $test = $q->getSingleResult();

    $this->assertInstanceOf('DateTime', $test->version);

    // Try to lock the record with an older timestamp and it should throw an exception
    $caughtException = NULL;
    try {
      $expectedVersionExpired = DateTime::createFromFormat('U', $test->version->getTimestamp() - 3600);
      $this->_em->lock($test, LockMode::OPTIMISTIC, $expectedVersionExpired);
    }
    catch (OptimisticLockException $e) {
      $caughtException = $e;
    }

    $this->assertNotNull($caughtException, "No OptimisticLockingException was thrown");
    $this->assertSame($test, $caughtException->getEntity());
  }

}

/**
 * @Entity
 * @Table(name="optimistic_joined_parent")
 * @InheritanceType("JOINED")
 * @DiscriminatorColumn(name="discr", type="string")
 * @DiscriminatorMap({"parent" = "OptimisticJoinedParent", "child" =
 *   "OptimisticJoinedChild"})
 */
class OptimisticJoinedParent {
  /**
   * @Id @Column(type="integer")
   * @GeneratedValue(strategy="AUTO")
   */
  public $id;

  /**
   * @Column(type="string", length=255)
   */
  public $name;

  /**
   * @Version @Column(type="integer")
   */
  public $version;
}

/**
 * @Entity
 * @Table(name="optimistic_joined_child")
 */
class OptimisticJoinedChild extends OptimisticJoinedParent {
  /**
   * @Column(type="string", length=255)
   */
  public $whatever;
}

/**
 * @Entity
 * @Table(name="optimistic_standard")
 */
class OptimisticStandard {
  /**
   * @Id @Column(type="integer")
   * @GeneratedValue(strategy="AUTO")
   */
  public $id;

  /**
   * @Column(type="string", length=255)
   */
  public $name;

  /**
   * @Version @Column(type="integer")
   */
  private $version;

  function getVersion() {
    return $this->version;
  }
}

/**
 * @Entity
 * @Table(name="optimistic_timestamp")
 */
class OptimisticTimestamp {
  /**
   * @Id @Column(type="integer")
   * @GeneratedValue(strategy="AUTO")
   */
  public $id;

  /**
   * @Column(type="string", length=255)
   */
  public $name;

  /**
   * @Version @Column(type="datetime")
   */
  public $version;
}
