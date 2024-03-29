<?php

namespace Doctrine\Tests\ORM\Functional\Ticket;

use Doctrine\Tests\Models\Company\CompanyPerson,
  Doctrine\Tests\Models\Company\CompanyEmployee,
  Doctrine\Tests\Models\Company\CompanyManager,
  Doctrine\Tests\Models\Company\CompanyOrganization,
  Doctrine\Tests\Models\Company\CompanyEvent,
  Doctrine\Tests\Models\Company\CompanyAuction,
  Doctrine\Tests\Models\Company\CompanyRaffle,
  Doctrine\Tests\Models\Company\CompanyCar;

/**
 * Functional tests for the Class Table Inheritance mapping strategy.
 *
 * @author Benjamin Eberlei <kontakt@beberlei.de>
 */
class DDC331Test extends \Doctrine\Tests\OrmFunctionalTestCase {
  protected function setUp() {
    $this->useModelSet('company');
    parent::setUp();
  }

  /**
   * @group DDC-331
   */
  public function testSelectFieldOnRootEntity() {
    $q = $this->_em->createQuery('SELECT e.name FROM Doctrine\Tests\Models\Company\CompanyEmployee e');
    $this->assertEquals(
      strtolower('SELECT c0_.name AS name_0 FROM company_employees c1_ INNER JOIN company_persons c0_ ON c1_.id = c0_.id LEFT JOIN company_managers c2_ ON c1_.id = c2_.id'),
      strtolower($q->getSql())
    );
  }
}
