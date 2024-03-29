<?php

namespace Doctrine\Tests\ORM\Functional\Ticket;

use Doctrine\Common\Collections\ArrayCollection;

/**
 * @group DDC-1050
 */
class DDC1050Test extends \Doctrine\Tests\OrmFunctionalTestCase {
  public function setUp() {
    $this->markTestSkipped('performance skipped');
    $this->useModelSet('cms');
    parent::setUp();
  }

  public function testPerformance() {
    for ($i = 2; $i < 10000; ++$i) {
      $user = new \Doctrine\Tests\Models\CMS\CmsUser();
      $user->status = 'developer';
      $user->username = 'jwage' + $i;
      $user->name = 'Jonathan';
      $this->_em->persist($user);
    }
    $this->_em->flush();
    $this->_em->clear();

    $s = microtime(TRUE);
    $users = $this->_em->getRepository('Doctrine\Tests\Models\CMS\CmsUser')
      ->findAll();
    $e = microtime(TRUE);
    echo __FUNCTION__ . " - " . ($e - $s) . " seconds" . PHP_EOL;
  }
}
