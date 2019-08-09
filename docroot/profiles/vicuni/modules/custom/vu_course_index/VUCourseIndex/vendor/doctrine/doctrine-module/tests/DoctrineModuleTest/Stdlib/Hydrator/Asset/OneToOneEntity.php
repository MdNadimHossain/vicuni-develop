<?php

namespace DoctrineModuleTest\Stdlib\Hydrator\Asset;

class OneToOneEntity {
  /**
   * @var int
   */
  protected $id;

  /**
   * @var SimpleEntity
   */
  protected $toOne;


  public function setId($id) {
    $this->id = $id;
  }

  public function getId() {
    return $this->id;
  }

  public function setToOne(SimpleEntity $entity = NULL, $modifyValue = TRUE) {
    // Modify the value to illustrate the difference between by value and by reference
    if ($modifyValue && $entity !== NULL) {
      $entity->setField('Modified from setToOne setter', FALSE);
    }

    $this->toOne = $entity;
  }

  public function getToOne($modifyValue = TRUE) {
    // Make some modifications to the association so that we can demonstrate difference between
    // by value and by reference
    if ($modifyValue) {
      $this->toOne->setField('Modified from getToOne getter', FALSE);
    }

    return $this->toOne;
  }
}
