<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright  Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license    http://framework.zend.com/license/new-bsd     New BSD License
 */

/**
 * @namespace
 */
namespace Zend\Mvc\Router\Console;

use Zend\Mvc\Router\RouteInterface as BaseRoute;

/**
 * Tree specific route interface.
 *
 * @copyright  Copyright (c) 2005-2014 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license    http://framework.zend.com/license/new-bsd     New BSD License
 */
interface RouteInterface extends BaseRoute {
  /**
   * Get a list of parameters used while assembling.
   *
   * @return array
   */
  public function getAssembledParams();
}
