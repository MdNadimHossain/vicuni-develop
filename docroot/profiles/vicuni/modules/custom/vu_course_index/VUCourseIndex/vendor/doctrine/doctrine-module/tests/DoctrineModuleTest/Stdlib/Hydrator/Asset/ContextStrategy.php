<?php

namespace DoctrineModuleTest\Stdlib\Hydrator\Asset;

use Zend\Stdlib\Hydrator\Strategy\StrategyInterface;

class ContextStrategy implements StrategyInterface {
  public function extract($value, $object = NULL) {
    return (string) $value . $object->getField();
  }

  public function hydrate($value, $data = NULL) {
    return $value . $data['field'];
  }
}
