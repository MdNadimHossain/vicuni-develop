<?php

namespace Doctrine\Tests\ORM\Performance;

use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\ORM\Event\LifecycleEventArgs;
use Doctrine\ORM\Events;

/**
 * @group performance
 * @group DDC-2602
 */
class DDC2602Test extends \Doctrine\Tests\OrmPerformanceTestCase {
  protected function setUp() {
    parent::setUp();

    $this->_schemaTool->createSchema(array(
      $this->_em->getClassMetadata(__NAMESPACE__ . '\DDC2602User'),
      $this->_em->getClassMetadata(__NAMESPACE__ . '\DDC2602Biography'),
      $this->_em->getClassMetadata(__NAMESPACE__ . '\DDC2602BiographyField'),
      $this->_em->getClassMetadata(__NAMESPACE__ . '\DDC2602BiographyFieldChoice'),
    ));

    $this->loadFixture();
  }

  protected function tearDown() {
    parent::tearDown();

    $this->_schemaTool->dropSchema(array(
      $this->_em->getClassMetadata(__NAMESPACE__ . '\DDC2602User'),
      $this->_em->getClassMetadata(__NAMESPACE__ . '\DDC2602Biography'),
      $this->_em->getClassMetadata(__NAMESPACE__ . '\DDC2602BiographyField'),
      $this->_em->getClassMetadata(__NAMESPACE__ . '\DDC2602BiographyFieldChoice'),
    ));
  }

  public function testIssue() {
    $eventManager = $this->_em->getEventManager();
    $eventManager->addEventListener(array(Events::postLoad), new DDC2602PostLoadListener());

    // Set maximum seconds this can run
    $this->setMaxRunningTime(1);

    $s = microtime(TRUE);

    $query = $this->_em->createQuery('SELECT u, b FROM Doctrine\Tests\ORM\Performance\DDC2602User u JOIN u.biography b');
    $query->getResult();

    $e = microtime(TRUE);

    echo __FUNCTION__ . " - " . ($e - $s) . " seconds" . PHP_EOL;
  }

  private function loadFixture() {
    $user1 = new DDC2602User();
    $user2 = new DDC2602User();
    $biography1 = new DDC2602Biography();
    $biography2 = new DDC2602Biography();
    $biographyField1 = new DDC2602BiographyField();
    $biographyField2 = new DDC2602BiographyField();
    $biographyFieldChoice1 = new DDC2602BiographyFieldChoice();
    $biographyFieldChoice2 = new DDC2602BiographyFieldChoice();
    $biographyFieldChoice3 = new DDC2602BiographyFieldChoice();
    $biographyFieldChoice4 = new DDC2602BiographyFieldChoice();
    $biographyFieldChoice5 = new DDC2602BiographyFieldChoice();
    $biographyFieldChoice6 = new DDC2602BiographyFieldChoice();

    $user1->name = 'Gblanco';
    $user1->biography = $biography1;

    $user2->name = 'Beberlei';
    $user2->biography = $biography2;

    $biography1->user = $user1;
    $biography1->content = '[{"field": 1, "choiceList": [1,3]}, {"field": 2, "choiceList": [5]}]';

    $biography2->user = $user2;
    $biography2->content = '[{"field": 1, "choiceList": [1,2,3,4]}]';

    $biographyField1->alias = 'question_1';
    $biographyField1->label = 'Question 1';
    $biographyField1->choiceList->add($biographyFieldChoice1);
    $biographyField1->choiceList->add($biographyFieldChoice2);
    $biographyField1->choiceList->add($biographyFieldChoice3);
    $biographyField1->choiceList->add($biographyFieldChoice4);

    $biographyField2->alias = 'question_2';
    $biographyField2->label = 'Question 2';
    $biographyField2->choiceList->add($biographyFieldChoice5);
    $biographyField2->choiceList->add($biographyFieldChoice6);

    $biographyFieldChoice1->field = $biographyField1;
    $biographyFieldChoice1->label = 'Answer 1.1';

    $biographyFieldChoice2->field = $biographyField1;
    $biographyFieldChoice2->label = 'Answer 1.2';

    $biographyFieldChoice3->field = $biographyField1;
    $biographyFieldChoice3->label = 'Answer 1.3';

    $biographyFieldChoice4->field = $biographyField1;
    $biographyFieldChoice4->label = 'Answer 1.4';

    $biographyFieldChoice5->field = $biographyField2;
    $biographyFieldChoice5->label = 'Answer 2.1';

    $biographyFieldChoice6->field = $biographyField2;
    $biographyFieldChoice6->label = 'Answer 2.2';

    $this->_em->persist($user1);
    $this->_em->persist($user2);

    $this->_em->persist($biographyField1);
    $this->_em->persist($biographyField2);

    $this->_em->flush();
    $this->_em->clear();
  }
}


class DDC2602PostLoadListener {
  public function postLoad(LifecycleEventArgs $event) {
    $entity = $event->getEntity();

    if (!($entity instanceof DDC2602Biography)) {
      return;
    }

    $entityManager = $event->getEntityManager();
    $query = $entityManager->createQuery('
            SELECT f, fc
              FROM Doctrine\Tests\ORM\Performance\DDC2602BiographyField f INDEX BY f.id
              JOIN f.choiceList fc INDEX BY fc.id
        ');

    $result = $query->getResult();
    $content = json_decode($entity->content);
    $fieldList = new ArrayCollection();

    foreach ($content as $selection) {
      $field = $result[$selection->field];
      $choiceList = $selection->choiceList;
      $fieldSelection = new DDC2602FieldSelection();

      $fieldSelection->field = $field;
      $fieldSelection->choiceList = $field->choiceList->filter(function ($choice) use ($choiceList) {
        return in_array($choice->id, $choiceList);
      });

      $fieldList->add($fieldSelection);
    }

    $entity->fieldList = $fieldList;
  }
}


/**
 * @Entity
 */
class DDC2602User {
  /**
   * @Id @GeneratedValue
   * @Column(type="integer")
   *
   * @var integer
   */
  public $id;

  /**
   * @Column(type="string", length=15)
   *
   * @var string
   */
  public $name;

  /**
   * @OneToOne(
   *     targetEntity="DDC2602Biography",
   *     inversedBy="user",
   *     cascade={"persist", "merge", "refresh", "remove"}
   * )
   * @JoinColumn(nullable=false)
   *
   * @var DDC2602Biography
   */
  public $biography;
}

/**
 * @Entity
 */
class DDC2602Biography {
  /**
   * @Id @GeneratedValue
   * @Column(type="integer")
   *
   * @var integer
   */
  public $id;

  /**
   * @OneToOne(
   *     targetEntity="DDC2602User",
   *     mappedBy="biography",
   *     cascade={"persist", "merge", "refresh"}
   * )
   *
   * @var DDC2602User
   */
  public $user;

  /**
   * @Column(type="text", nullable=true)
   *
   * @var string
   */
  public $content;

  /**
   * @var array
   */
  public $fieldList = array();
}

/**
 * @Entity
 */
class DDC2602BiographyField {
  /**
   * @Id @GeneratedValue
   * @Column(type="integer")
   *
   * @var integer
   */
  public $id;

  /**
   * @Column(type="string", unique=true, length=100)
   */
  public $alias;

  /**
   * @Column(type="string", length=100)
   */
  public $label;

  /**
   * @OneToMany(
   *     targetEntity="DDC2602BiographyFieldChoice",
   *     mappedBy="field",
   *     cascade={"persist", "merge", "refresh"}
   * )
   *
   * @var \Doctrine\Common\Collections\ArrayCollection
   */
  public $choiceList;

  /**
   * Constructor.
   *
   */
  public function __construct() {
    $this->choiceList = new ArrayCollection();
  }
}

/**
 * @Entity
 */
class DDC2602BiographyFieldChoice {
  /**
   * @Id @GeneratedValue
   * @Column(type="integer")
   *
   * @var integer
   */
  public $id;

  /**
   * @Column(type="string", unique=true, length=100)
   */
  public $label;

  /**
   * @ManyToOne(
   *     targetEntity="DDC2602BiographyField",
   *     inversedBy="choiceList"
   * )
   * @JoinColumn(onDelete="CASCADE")
   *
   * @var DDC2602BiographyField
   */
  public $field;
}

class DDC2602FieldSelection {
  /**
   * @var DDC2602BiographyField
   */
  public $field;

  /**
   * @var \Doctrine\Common\Collections\ArrayCollection
   */
  public $choiceList;

  /**
   * Constructor.
   *
   */
  public function __construct() {
    $this->choiceList = new ArrayCollection();
  }
}
