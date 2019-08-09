<?php

namespace Doctrine\Tests\Common\Proxy;

/**
 * Test asset class
 */
class MagicIssetClass {
  /**
   * @var string
   */
  public $id = 'id';

  /**
   * @var string
   */
  public $publicField = 'publicField';

  /**
   * @param string $name
   *
   * @return bool
   * @throws \BadMethodCallException
   */
  public function __isset($name) {
    if ('test' === $name) {
      return TRUE;
    }

    if ('publicField' === $name || 'id' === $name) {
      throw new \BadMethodCallException('Should never be called for "publicField" or "id"');
    }

    return FALSE;
  }
}
