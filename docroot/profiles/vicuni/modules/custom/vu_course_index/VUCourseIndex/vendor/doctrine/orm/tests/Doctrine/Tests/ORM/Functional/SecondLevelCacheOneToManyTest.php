<?php

namespace Doctrine\Tests\ORM\Functional;

use Doctrine\Tests\Models\Cache\City;
use Doctrine\Tests\Models\Cache\Login;
use Doctrine\Tests\Models\Cache\State;
use Doctrine\Tests\Models\Cache\Token;
use Doctrine\Tests\Models\Cache\Travel;
use Doctrine\Tests\Models\Cache\Traveler;

/**
 * @group DDC-2183
 */
class SecondLevelCacheOneToManyTest extends SecondLevelCacheAbstractTest {
  public function testShouldNotPutCollectionInverseSideOnPersist() {
    $this->loadFixturesCountries();
    $this->loadFixturesStates();
    $this->loadFixturesCities();
    $this->_em->clear();

    $this->assertTrue($this->cache->containsEntity(State::CLASSNAME, $this->states[0]->getId()));
    $this->assertTrue($this->cache->containsEntity(State::CLASSNAME, $this->states[1]->getId()));

    $this->assertFalse($this->cache->containsCollection(State::CLASSNAME, 'cities', $this->states[0]->getId()));
    $this->assertFalse($this->cache->containsCollection(State::CLASSNAME, 'cities', $this->states[1]->getId()));
  }

  public function testPutAndLoadOneToManyRelation() {
    $this->loadFixturesCountries();
    $this->loadFixturesStates();
    $this->loadFixturesCities();
    $this->_em->clear();
    $this->secondLevelCacheLogger->clearStats();

    $this->cache->evictEntityRegion(State::CLASSNAME);
    $this->cache->evictEntityRegion(City::CLASSNAME);
    $this->cache->evictCollectionRegion(State::CLASSNAME, 'cities');

    $this->assertFalse($this->cache->containsEntity(State::CLASSNAME, $this->states[0]->getId()));
    $this->assertFalse($this->cache->containsEntity(State::CLASSNAME, $this->states[1]->getId()));

    $this->assertFalse($this->cache->containsCollection(State::CLASSNAME, 'cities', $this->states[0]->getId()));
    $this->assertFalse($this->cache->containsCollection(State::CLASSNAME, 'cities', $this->states[1]->getId()));

    $this->assertFalse($this->cache->containsEntity(City::CLASSNAME, $this->states[0]->getCities()
      ->get(0)
      ->getId()));
    $this->assertFalse($this->cache->containsEntity(City::CLASSNAME, $this->states[0]->getCities()
      ->get(1)
      ->getId()));
    $this->assertFalse($this->cache->containsEntity(City::CLASSNAME, $this->states[1]->getCities()
      ->get(0)
      ->getId()));
    $this->assertFalse($this->cache->containsEntity(City::CLASSNAME, $this->states[1]->getCities()
      ->get(1)
      ->getId()));

    $s1 = $this->_em->find(State::CLASSNAME, $this->states[0]->getId());
    $s2 = $this->_em->find(State::CLASSNAME, $this->states[1]->getId());

    $this->assertEquals(2, $this->secondLevelCacheLogger->getPutCount());
    $this->assertEquals(2, $this->secondLevelCacheLogger->getMissCount());
    $this->assertEquals(2, $this->secondLevelCacheLogger->getRegionPutCount($this->getEntityRegion(State::CLASSNAME)));
    $this->assertEquals(2, $this->secondLevelCacheLogger->getRegionMissCount($this->getEntityRegion(State::CLASSNAME)));

    //trigger lazy load
    $this->assertCount(2, $s1->getCities());
    $this->assertCount(2, $s2->getCities());

    $this->assertEquals(4, $this->secondLevelCacheLogger->getPutCount());
    $this->assertEquals(4, $this->secondLevelCacheLogger->getMissCount());
    $this->assertEquals(2, $this->secondLevelCacheLogger->getRegionPutCount($this->getCollectionRegion(State::CLASSNAME, 'cities')));
    $this->assertEquals(2, $this->secondLevelCacheLogger->getRegionMissCount($this->getCollectionRegion(State::CLASSNAME, 'cities')));

    $this->assertInstanceOf(City::CLASSNAME, $s1->getCities()->get(0));
    $this->assertInstanceOf(City::CLASSNAME, $s1->getCities()->get(1));

    $this->assertInstanceOf(City::CLASSNAME, $s2->getCities()->get(0));
    $this->assertInstanceOf(City::CLASSNAME, $s2->getCities()->get(1));

    $this->assertTrue($this->cache->containsEntity(State::CLASSNAME, $this->states[0]->getId()));
    $this->assertTrue($this->cache->containsEntity(State::CLASSNAME, $this->states[1]->getId()));

    $this->assertTrue($this->cache->containsCollection(State::CLASSNAME, 'cities', $this->states[0]->getId()));
    $this->assertTrue($this->cache->containsCollection(State::CLASSNAME, 'cities', $this->states[1]->getId()));

    $this->assertTrue($this->cache->containsEntity(City::CLASSNAME, $this->states[0]->getCities()
      ->get(0)
      ->getId()));
    $this->assertTrue($this->cache->containsEntity(City::CLASSNAME, $this->states[0]->getCities()
      ->get(1)
      ->getId()));
    $this->assertTrue($this->cache->containsEntity(City::CLASSNAME, $this->states[1]->getCities()
      ->get(0)
      ->getId()));
    $this->assertTrue($this->cache->containsEntity(City::CLASSNAME, $this->states[1]->getCities()
      ->get(1)
      ->getId()));

    $this->_em->clear();
    $this->secondLevelCacheLogger->clearStats();

    $queryCount = $this->getCurrentQueryCount();

    $s3 = $this->_em->find(State::CLASSNAME, $this->states[0]->getId());
    $s4 = $this->_em->find(State::CLASSNAME, $this->states[1]->getId());

    //trigger lazy load from cache
    $this->assertCount(2, $s3->getCities());
    $this->assertCount(2, $s4->getCities());

    $this->assertEquals(4, $this->secondLevelCacheLogger->getHitCount());
    $this->assertEquals(2, $this->secondLevelCacheLogger->getRegionHitCount($this->getEntityRegion(State::CLASSNAME)));
    $this->assertEquals(2, $this->secondLevelCacheLogger->getRegionHitCount($this->getCollectionRegion(State::CLASSNAME, 'cities')));

    $this->assertInstanceOf(City::CLASSNAME, $s3->getCities()->get(0));
    $this->assertInstanceOf(City::CLASSNAME, $s3->getCities()->get(1));
    $this->assertInstanceOf(City::CLASSNAME, $s4->getCities()->get(0));
    $this->assertInstanceOf(City::CLASSNAME, $s4->getCities()->get(1));

    $this->assertNotSame($s1->getCities()->get(0), $s3->getCities()->get(0));
    $this->assertEquals($s1->getCities()->get(0)->getId(), $s3->getCities()
      ->get(0)
      ->getId());
    $this->assertEquals($s1->getCities()->get(0)->getName(), $s3->getCities()
      ->get(0)
      ->getName());

    $this->assertNotSame($s1->getCities()->get(1), $s3->getCities()->get(1));
    $this->assertEquals($s1->getCities()->get(1)->getId(), $s3->getCities()
      ->get(1)
      ->getId());
    $this->assertEquals($s1->getCities()->get(1)->getName(), $s3->getCities()
      ->get(1)
      ->getName());

    $this->assertNotSame($s2->getCities()->get(0), $s4->getCities()->get(0));
    $this->assertEquals($s2->getCities()->get(0)->getId(), $s4->getCities()
      ->get(0)
      ->getId());
    $this->assertEquals($s2->getCities()->get(0)->getName(), $s4->getCities()
      ->get(0)
      ->getName());

    $this->assertNotSame($s2->getCities()->get(1), $s4->getCities()->get(1));
    $this->assertEquals($s2->getCities()->get(1)->getId(), $s4->getCities()
      ->get(1)
      ->getId());
    $this->assertEquals($s2->getCities()->get(1)->getName(), $s4->getCities()
      ->get(1)
      ->getName());

    $this->assertEquals(4, $this->secondLevelCacheLogger->getHitCount());
    $this->assertEquals($queryCount, $this->getCurrentQueryCount());
  }

  public function testLoadOneToManyCollectionFromDatabaseWhenEntityMissing() {
    $this->loadFixturesCountries();
    $this->loadFixturesStates();
    $this->loadFixturesCities();
    $this->_em->clear();

    //trigger lazy load from database
    $this->assertCount(2, $this->_em->find(State::CLASSNAME, $this->states[0]->getId())
      ->getCities());

    $this->assertTrue($this->cache->containsEntity(State::CLASSNAME, $this->states[0]->getId()));
    $this->assertTrue($this->cache->containsCollection(State::CLASSNAME, 'cities', $this->states[0]->getId()));
    $this->assertTrue($this->cache->containsEntity(City::CLASSNAME, $this->states[0]->getCities()
      ->get(0)
      ->getId()));
    $this->assertTrue($this->cache->containsEntity(City::CLASSNAME, $this->states[0]->getCities()
      ->get(1)
      ->getId()));

    $queryCount = $this->getCurrentQueryCount();
    $stateId = $this->states[0]->getId();
    $state = $this->_em->find(State::CLASSNAME, $stateId);
    $cityId = $this->states[0]->getCities()->get(1)->getId();

    //trigger lazy load from cache
    $this->assertCount(2, $state->getCities());
    $this->assertEquals($queryCount, $this->getCurrentQueryCount());
    $this->assertTrue($this->cache->containsEntity(City::CLASSNAME, $cityId));

    $this->cache->evictEntity(City::CLASSNAME, $cityId);

    $this->assertFalse($this->cache->containsEntity(City::CLASSNAME, $cityId));
    $this->assertTrue($this->cache->containsEntity(State::CLASSNAME, $stateId));
    $this->assertTrue($this->cache->containsCollection(State::CLASSNAME, 'cities', $stateId));

    $this->_em->clear();

    $state = $this->_em->find(State::CLASSNAME, $stateId);

    //trigger lazy load from database
    $this->assertCount(2, $state->getCities());
    $this->assertEquals($queryCount + 1, $this->getCurrentQueryCount());
  }


  public function testShoudNotPutOneToManyRelationOnPersist() {
    $this->loadFixturesCountries();
    $this->evictRegions();

    $state = new State("State Foo", $this->countries[0]);

    $this->_em->persist($state);
    $this->_em->flush();
    $this->_em->clear();

    $this->assertTrue($this->cache->containsEntity(State::CLASSNAME, $state->getId()));
    $this->assertFalse($this->cache->containsCollection(State::CLASSNAME, 'cities', $state->getId()));
  }

  public function testOneToManyRemove() {
    $this->loadFixturesCountries();
    $this->loadFixturesStates();
    $this->loadFixturesCities();
    $this->_em->clear();
    $this->secondLevelCacheLogger->clearStats();

    $this->cache->evictEntityRegion(State::CLASSNAME);
    $this->cache->evictEntityRegion(City::CLASSNAME);
    $this->cache->evictCollectionRegion(State::CLASSNAME, 'cities');

    $this->assertFalse($this->cache->containsEntity(State::CLASSNAME, $this->states[0]->getId()));
    $this->assertFalse($this->cache->containsCollection(State::CLASSNAME, 'cities', $this->states[0]->getId()));
    $this->assertFalse($this->cache->containsEntity(City::CLASSNAME, $this->states[0]->getCities()
      ->get(0)
      ->getId()));
    $this->assertFalse($this->cache->containsEntity(City::CLASSNAME, $this->states[0]->getCities()
      ->get(1)
      ->getId()));

    $entity = $this->_em->find(State::CLASSNAME, $this->states[0]->getId());

    $this->assertEquals(1, $this->secondLevelCacheLogger->getPutCount());
    $this->assertEquals(1, $this->secondLevelCacheLogger->getMissCount());
    $this->assertEquals(1, $this->secondLevelCacheLogger->getRegionPutCount($this->getEntityRegion(State::CLASSNAME)));
    $this->assertEquals(1, $this->secondLevelCacheLogger->getRegionMissCount($this->getEntityRegion(State::CLASSNAME)));

    //trigger lazy load
    $this->assertCount(2, $entity->getCities());

    $this->assertEquals(2, $this->secondLevelCacheLogger->getPutCount());
    $this->assertEquals(2, $this->secondLevelCacheLogger->getMissCount());
    $this->assertEquals(1, $this->secondLevelCacheLogger->getRegionPutCount($this->getCollectionRegion(State::CLASSNAME, 'cities')));
    $this->assertEquals(1, $this->secondLevelCacheLogger->getRegionMissCount($this->getCollectionRegion(State::CLASSNAME, 'cities')));

    $this->assertInstanceOf(City::CLASSNAME, $entity->getCities()->get(0));
    $this->assertInstanceOf(City::CLASSNAME, $entity->getCities()->get(1));

    $this->_em->clear();
    $this->secondLevelCacheLogger->clearStats();

    $queryCount = $this->getCurrentQueryCount();
    $state = $this->_em->find(State::CLASSNAME, $this->states[0]->getId());

    //trigger lazy load from cache
    $this->assertCount(2, $state->getCities());

    $this->assertEquals(2, $this->secondLevelCacheLogger->getHitCount());
    $this->assertEquals(1, $this->secondLevelCacheLogger->getRegionHitCount($this->getEntityRegion(State::CLASSNAME)));
    $this->assertEquals(1, $this->secondLevelCacheLogger->getRegionHitCount($this->getCollectionRegion(State::CLASSNAME, 'cities')));

    $city0 = $state->getCities()->get(0);
    $city1 = $state->getCities()->get(1);

    $this->assertInstanceOf(City::CLASSNAME, $city0);
    $this->assertInstanceOf(City::CLASSNAME, $city1);

    $this->assertEquals($entity->getCities()
      ->get(0)
      ->getName(), $city0->getName());
    $this->assertEquals($entity->getCities()
      ->get(1)
      ->getName(), $city1->getName());

    $this->assertEquals(2, $this->secondLevelCacheLogger->getHitCount());
    $this->assertEquals($queryCount, $this->getCurrentQueryCount());

    $state->getCities()->removeElement($city0);

    $this->_em->remove($city0);
    $this->_em->persist($state);
    $this->_em->flush();

    $this->_em->clear();
    $this->secondLevelCacheLogger->clearStats();

    $queryCount = $this->getCurrentQueryCount();
    $state = $this->_em->find(State::CLASSNAME, $this->states[0]->getId());

    //trigger lazy load from cache
    $this->assertCount(1, $state->getCities());

    $city1 = $state->getCities()->get(0);
    $this->assertInstanceOf(City::CLASSNAME, $city1);
    $this->assertEquals($entity->getCities()
      ->get(1)
      ->getName(), $city1->getName());

    $this->assertEquals(1, $this->secondLevelCacheLogger->getHitCount());
    $this->assertEquals(1, $this->secondLevelCacheLogger->getRegionHitCount($this->getEntityRegion(State::CLASSNAME)));
    $this->assertEquals(0, $this->secondLevelCacheLogger->getRegionHitCount($this->getCollectionRegion(State::CLASSNAME, 'cities')));

    $this->assertEquals($queryCount + 1, $this->getCurrentQueryCount());

    $state->getCities()->remove(0);

    $this->_em->remove($city1);
    $this->_em->persist($state);
    $this->_em->flush();

    $this->_em->clear();
    $this->secondLevelCacheLogger->clearStats();

    $queryCount = $this->getCurrentQueryCount();
    $state = $this->_em->find(State::CLASSNAME, $this->states[0]->getId());

    $this->assertCount(0, $state->getCities());

    $this->assertEquals(1, $this->secondLevelCacheLogger->getHitCount());
    $this->assertEquals(1, $this->secondLevelCacheLogger->getRegionHitCount($this->getEntityRegion(State::CLASSNAME)));
    $this->assertEquals(0, $this->secondLevelCacheLogger->getRegionHitCount($this->getCollectionRegion(State::CLASSNAME, 'cities')));
  }

  public function testOneToManyWithEmptyRelation() {
    $this->loadFixturesCountries();
    $this->loadFixturesStates();
    $this->loadFixturesCities();

    $this->secondLevelCacheLogger->clearStats();
    $this->cache->evictEntityRegion(City::CLASSNAME);
    $this->cache->evictEntityRegion(State::CLASSNAME);
    $this->cache->evictCollectionRegion(State::CLASSNAME, 'cities');
    $this->_em->clear();

    $entitiId = $this->states[2]->getId(); // bavaria (cities count = 0)
    $queryCount = $this->getCurrentQueryCount();
    $entity = $this->_em->find(State::CLASSNAME, $entitiId);

    $this->assertEquals(0, $entity->getCities()->count());
    $this->assertEquals($queryCount + 2, $this->getCurrentQueryCount());

    $this->_em->clear();

    $queryCount = $this->getCurrentQueryCount();
    $entity = $this->_em->find(State::CLASSNAME, $entitiId);

    $this->assertEquals(0, $entity->getCities()->count());
    $this->assertEquals($queryCount, $this->getCurrentQueryCount());
  }

  public function testOneToManyCount() {
    $this->loadFixturesCountries();
    $this->loadFixturesStates();
    $this->loadFixturesCities();

    $this->secondLevelCacheLogger->clearStats();
    $this->cache->evictEntityRegion(City::CLASSNAME);
    $this->cache->evictEntityRegion(State::CLASSNAME);
    $this->cache->evictCollectionRegion(State::CLASSNAME, 'cities');
    $this->_em->clear();

    $entityId = $this->states[0]->getId();
    $queryCount = $this->getCurrentQueryCount();
    $entity = $this->_em->find(State::CLASSNAME, $entityId);

    $this->assertEquals(2, $entity->getCities()->count());
    $this->assertEquals($queryCount + 2, $this->getCurrentQueryCount());

    $this->_em->clear();

    $queryCount = $this->getCurrentQueryCount();
    $entity = $this->_em->find(State::CLASSNAME, $entityId);

    $this->assertEquals(2, $entity->getCities()->count());
    $this->assertEquals($queryCount, $this->getCurrentQueryCount());
  }

  public function testCacheInitializeCollectionWithNewObjects() {
    $this->_em->clear();
    $this->evictRegions();

    $traveler = new Traveler("Doctrine Bot");

    for ($i = 0; $i < 3; ++$i) {
      $traveler->getTravels()->add(new Travel($traveler));
    }

    $this->_em->persist($traveler);
    $this->_em->flush();
    $this->_em->clear();

    $this->assertCount(3, $traveler->getTravels());

    $travelerId = $traveler->getId();
    $queryCount = $this->getCurrentQueryCount();
    $entity = $this->_em->find(Traveler::CLASSNAME, $travelerId);

    $this->assertEquals($queryCount, $this->getCurrentQueryCount());
    $this->assertFalse($entity->getTravels()->isInitialized());

    $newItem = new Travel($entity);
    $entity->getTravels()->add($newItem);

    $this->assertFalse($entity->getTravels()->isInitialized());
    $this->assertCount(4, $entity->getTravels());
    $this->assertTrue($entity->getTravels()->isInitialized());
    $this->assertEquals($queryCount + 1, $this->getCurrentQueryCount());

    $this->_em->flush();
    $this->_em->clear();

    $query = "SELECT t, tt FROM Doctrine\Tests\Models\Cache\Traveler t JOIN t.travels tt WHERE t.id = $travelerId";
    $result = $this->_em->createQuery($query)->getSingleResult();

    $this->assertEquals(4, $result->getTravels()->count());
  }

  public function testPutAndLoadNonCacheableOneToMany() {
    $this->assertNull($this->cache->getEntityCacheRegion(Login::CLASSNAME));
    $this->assertInstanceOf('Doctrine\ORM\Cache\Region', $this->cache->getEntityCacheRegion(Token::CLASSNAME));

    $l1 = new Login('session1');
    $l2 = new Login('session2');
    $token = new Token('token-hash');
    $token->addLogin($l1);
    $token->addLogin($l2);

    $this->_em->persist($token);
    $this->_em->flush();
    $this->_em->clear();

    $this->assertTrue($this->cache->containsEntity(Token::CLASSNAME, $token->token));

    $queryCount = $this->getCurrentQueryCount();

    $entity = $this->_em->find(Token::CLASSNAME, $token->token);

    $this->assertInstanceOf(Token::CLASSNAME, $entity);
    $this->assertEquals('token-hash', $entity->token);
    $this->assertEquals($queryCount, $this->getCurrentQueryCount());

    $this->assertCount(2, $entity->logins);
    $this->assertEquals($queryCount + 1, $this->getCurrentQueryCount());
  }
}
