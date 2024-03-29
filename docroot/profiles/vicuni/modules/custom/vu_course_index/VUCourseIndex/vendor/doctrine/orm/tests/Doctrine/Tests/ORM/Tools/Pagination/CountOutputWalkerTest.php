<?php

namespace Doctrine\Tests\ORM\Tools\Pagination;

use Doctrine\ORM\Query;

class CountOutputWalkerTest extends PaginationTestCase {
  public function testCountQuery() {
    $query = $this->entityManager->createQuery(
      'SELECT p, c, a FROM Doctrine\Tests\ORM\Tools\Pagination\BlogPost p JOIN p.category c JOIN p.author a');
    $query->setHint(Query::HINT_CUSTOM_OUTPUT_WALKER, 'Doctrine\ORM\Tools\Pagination\CountOutputWalker');
    $query->setFirstResult(NULL)->setMaxResults(NULL);

    $this->assertEquals(
      "SELECT COUNT(*) AS dctrn_count FROM (SELECT DISTINCT id_0 FROM (SELECT b0_.id AS id_0, c1_.id AS id_1, a2_.id AS id_2, a2_.name AS name_3, b0_.author_id AS author_id_4, b0_.category_id AS category_id_5 FROM BlogPost b0_ INNER JOIN Category c1_ ON b0_.category_id = c1_.id INNER JOIN Author a2_ ON b0_.author_id = a2_.id) dctrn_result) dctrn_table", $query->getSql()
    );
  }

  public function testCountQuery_MixedResultsWithName() {
    $query = $this->entityManager->createQuery(
      'SELECT a, sum(a.name) as foo FROM Doctrine\Tests\ORM\Tools\Pagination\Author a');
    $query->setHint(Query::HINT_CUSTOM_OUTPUT_WALKER, 'Doctrine\ORM\Tools\Pagination\CountOutputWalker');
    $query->setFirstResult(NULL)->setMaxResults(NULL);

    $this->assertEquals(
      "SELECT COUNT(*) AS dctrn_count FROM (SELECT DISTINCT id_0 FROM (SELECT a0_.id AS id_0, a0_.name AS name_1, sum(a0_.name) AS sclr_2 FROM Author a0_) dctrn_result) dctrn_table", $query->getSql()
    );
  }

  public function testCountQuery_Having() {
    $query = $this->entityManager->createQuery(
      'SELECT g, u, count(u.id) AS userCount FROM Doctrine\Tests\ORM\Tools\Pagination\Group g LEFT JOIN g.users u GROUP BY g.id HAVING userCount > 0');
    $query->setHint(Query::HINT_CUSTOM_OUTPUT_WALKER, 'Doctrine\ORM\Tools\Pagination\CountOutputWalker');
    $query->setFirstResult(NULL)->setMaxResults(NULL);

    $this->assertEquals(
      "SELECT COUNT(*) AS dctrn_count FROM (SELECT DISTINCT id_1 FROM (SELECT count(u0_.id) AS sclr_0, g1_.id AS id_1, u0_.id AS id_2 FROM groups g1_ LEFT JOIN user_group u2_ ON g1_.id = u2_.group_id LEFT JOIN User u0_ ON u0_.id = u2_.user_id GROUP BY g1_.id HAVING sclr_0 > 0) dctrn_result) dctrn_table", $query->getSql()
    );
  }

  public function testCountQueryOrderBySqlServer() {
    if ($this->entityManager->getConnection()
        ->getDatabasePlatform()
        ->getName() !== "mssql"
    ) {
      $this->markTestSkipped('SQLServer only test.');
    }

    $query = $this->entityManager->createQuery(
      'SELECT p FROM Doctrine\Tests\ORM\Tools\Pagination\BlogPost p ORDER BY p.id');
    $query->setHint(Query::HINT_CUSTOM_OUTPUT_WALKER, 'Doctrine\ORM\Tools\Pagination\CountOutputWalker');
    $query->setFirstResult(NULL)->setMaxResults(NULL);

    $this->assertEquals(
      "SELECT COUNT(*) AS dctrn_count FROM (SELECT DISTINCT id_0 FROM (SELECT b0_.id AS id_0, b0_.author_id AS author_id_1, b0_.category_id AS category_id_2 FROM BlogPost b0_) dctrn_result) dctrn_table",
      $query->getSql()
    );
  }
}

