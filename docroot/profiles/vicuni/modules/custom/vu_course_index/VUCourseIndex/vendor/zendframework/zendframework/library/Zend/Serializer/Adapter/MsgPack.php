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

namespace Zend\Serializer\Adapter;

use Zend\Serializer\Exception;
use Zend\Stdlib\ErrorHandler;

class MsgPack extends AbstractAdapter {
  /**
   * @var string Serialized 0 value
   */
  private static $serialized0 = NULL;

  /**
   * Constructor
   *
   * @throws Exception\ExtensionNotLoadedException If msgpack extension is not
   *   present
   */
  public function __construct($options = NULL) {
    if (!extension_loaded('msgpack')) {
      throw new Exception\ExtensionNotLoadedException(
        'PHP extension "msgpack" is required for this adapter'
      );
    }

    if (static::$serialized0 === NULL) {
      static::$serialized0 = msgpack_serialize(0);
    }

    parent::__construct($options);
  }

  /**
   * Serialize PHP value to msgpack
   *
   * @param  mixed $value
   *
   * @return string
   * @throws Exception\RuntimeException on msgpack error
   */
  public function serialize($value) {
    ErrorHandler::start();
    $ret = msgpack_serialize($value);
    $err = ErrorHandler::stop();

    if ($ret === FALSE) {
      throw new Exception\RuntimeException('Serialization failed', 0, $err);
    }

    return $ret;
  }

  /**
   * Deserialize msgpack string to PHP value
   *
   * @param  string $serialized
   *
   * @return mixed
   * @throws Exception\RuntimeException on msgpack error
   */
  public function unserialize($serialized) {
    if ($serialized === static::$serialized0) {
      return 0;
    }

    ErrorHandler::start();
    $ret = msgpack_unserialize($serialized);
    $err = ErrorHandler::stop();

    if ($ret === 0) {
      throw new Exception\RuntimeException('Unserialization failed', 0, $err);
    }

    return $ret;
  }
}
