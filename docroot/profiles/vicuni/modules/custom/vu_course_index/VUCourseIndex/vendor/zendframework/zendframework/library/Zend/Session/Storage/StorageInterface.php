<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Session\Storage;

use ArrayAccess;
use Countable;
use Serializable;
use Traversable;

/**
 * Session storage interface
 *
 * Defines the minimum requirements for handling userland, in-script session
 * storage (e.g., the $_SESSION superglobal array).
 */
interface StorageInterface extends Traversable, ArrayAccess, Serializable, Countable {
  public function getRequestAccessTime();

  public function lock($key = NULL);

  public function isLocked($key = NULL);

  public function unlock($key = NULL);

  public function markImmutable();

  public function isImmutable();

  public function setMetadata($key, $value, $overwriteArray = FALSE);

  public function getMetadata($key = NULL);

  public function clear($key = NULL);

  public function fromArray(array $array);

  public function toArray($metaData = FALSE);
}
