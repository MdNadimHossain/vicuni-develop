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

namespace Zend\Di;

interface LocatorInterface {
  /**
   * Retrieve a class instance
   *
   * @param  string $name Class name or service name
   * @param  null|array $params Parameters to be used when instantiating a new
   *   instance of $name
   *
   * @return object|null
   */
  public function get($name, array $params = array());
}
