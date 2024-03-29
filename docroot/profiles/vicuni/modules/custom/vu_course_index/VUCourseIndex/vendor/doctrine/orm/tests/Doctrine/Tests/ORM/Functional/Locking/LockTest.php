<?php

namespace Doctrine\Tests\ORM\Functional\Locking;

use Doctrine\Tests\Models\CMS\CmsArticle,
  Doctrine\Tests\Models\CMS\CmsUser,
  Doctrine\DBAL\LockMode,
  Doctrine\ORM\EntityManager;

/**
 * @group locking
 */
class LockTest extends \Doctrine\Tests\OrmFunctionalTestCase {
  protected function setUp() {
    $this->useModelSet('cms');
    parent::setUp();
    $this->handles = array();
  }

  /**
   * @group DDC-178
   * @group locking
   */
  public function testLockVersionedEntity() {
    $article = new CmsArticle();
    $article->text = "my article";
    $article->topic = "Hello";

    $this->_em->persist($article);
    $this->_em->flush();

    $this->_em->lock($article, LockMode::OPTIMISTIC, $article->version);
  }

  /**
   * @group DDC-178
   * @group locking
   */
  public function testLockVersionedEntity_MismatchThrowsException() {
    $article = new CmsArticle();
    $article->text = "my article";
    $article->topic = "Hello";

    $this->_em->persist($article);
    $this->_em->flush();

    $this->setExpectedException('Doctrine\ORM\OptimisticLockException');
    $this->_em->lock($article, LockMode::OPTIMISTIC, $article->version + 1);
  }

  /**
   * @group DDC-178
   * @group locking
   */
  public function testLockUnversionedEntity_ThrowsException() {
    $user = new CmsUser();
    $user->name = "foo";
    $user->status = "active";
    $user->username = "foo";

    $this->_em->persist($user);
    $this->_em->flush();

    $this->setExpectedException('Doctrine\ORM\OptimisticLockException');
    $this->_em->lock($user, LockMode::OPTIMISTIC);
  }

  /**
   * @group DDC-178
   * @group locking
   */
  public function testLockUnmanagedEntity_ThrowsException() {
    $article = new CmsArticle();

    $this->setExpectedException('InvalidArgumentException', 'Entity Doctrine\Tests\Models\CMS\CmsArticle');
    $this->_em->lock($article, LockMode::OPTIMISTIC, $article->version + 1);
  }

  /**
   * @group DDC-178
   * @group locking
   */
  public function testLockPessimisticRead_NoTransaction_ThrowsException() {
    $article = new CmsArticle();
    $article->text = "my article";
    $article->topic = "Hello";

    $this->_em->persist($article);
    $this->_em->flush();

    $this->setExpectedException('Doctrine\ORM\TransactionRequiredException');
    $this->_em->lock($article, LockMode::PESSIMISTIC_READ);
  }

  /**
   * @group DDC-178
   * @group locking
   */
  public function testLockPessimisticWrite_NoTransaction_ThrowsException() {
    $article = new CmsArticle();
    $article->text = "my article";
    $article->topic = "Hello";

    $this->_em->persist($article);
    $this->_em->flush();

    $this->setExpectedException('Doctrine\ORM\TransactionRequiredException');
    $this->_em->lock($article, LockMode::PESSIMISTIC_WRITE);
  }

  /**
   * @group DDC-178
   * @group locking
   */
  public function testLockPessimisticWrite() {
    $writeLockSql = $this->_em->getConnection()
      ->getDatabasePlatform()
      ->getWriteLockSql();
    if (strlen($writeLockSql) == 0) {
      $this->markTestSkipped('Database Driver has no Write Lock support.');
    }

    $article = new CmsArticle();
    $article->text = "my article";
    $article->topic = "Hello";

    $this->_em->persist($article);
    $this->_em->flush();

    $this->_em->beginTransaction();
    try {
      $this->_em->lock($article, LockMode::PESSIMISTIC_WRITE);
      $this->_em->commit();
    }
    catch (\Exception $e) {
      $this->_em->rollback();
      throw $e;
    }

    $query = array_pop($this->_sqlLoggerStack->queries);
    $query = array_pop($this->_sqlLoggerStack->queries);
    $this->assertContains($writeLockSql, $query['sql']);
  }

  /**
   * @group DDC-178
   */
  public function testLockPessimisticRead() {
    $readLockSql = $this->_em->getConnection()
      ->getDatabasePlatform()
      ->getReadLockSql();
    if (strlen($readLockSql) == 0) {
      $this->markTestSkipped('Database Driver has no Write Lock support.');
    }

    $article = new CmsArticle();
    $article->text = "my article";
    $article->topic = "Hello";

    $this->_em->persist($article);
    $this->_em->flush();

    $this->_em->beginTransaction();
    try {
      $this->_em->lock($article, LockMode::PESSIMISTIC_READ);
      $this->_em->commit();
    }
    catch (\Exception $e) {
      $this->_em->rollback();
      throw $e;
    }

    $query = array_pop($this->_sqlLoggerStack->queries);
    $query = array_pop($this->_sqlLoggerStack->queries);
    $this->assertContains($readLockSql, $query['sql']);
  }

  /**
   * @group DDC-1693
   */
  public function testLockOptimisticNonVersionedThrowsExceptionInDQL() {
    $dql = "SELECT u FROM Doctrine\Tests\Models\CMS\CmsUser u WHERE u.username = 'gblanco'";

    $this->setExpectedException('Doctrine\ORM\OptimisticLockException', 'The optimistic lock on an entity failed.');
    $sql = $this->_em->createQuery($dql)->setHint(
      \Doctrine\ORM\Query::HINT_LOCK_MODE, \Doctrine\DBAL\LockMode::OPTIMISTIC
    )->getSQL();
  }
}
