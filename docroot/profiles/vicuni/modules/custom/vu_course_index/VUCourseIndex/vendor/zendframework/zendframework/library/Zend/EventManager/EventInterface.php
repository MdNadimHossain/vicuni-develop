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

namespace Zend\EventManager;

use ArrayAccess;

/**
 * Representation of an event
 */
interface EventInterface {
  /**
   * Get event name
   *
   * @return string
   */
  public function getName();

  /**
   * Get target/context from which event was triggered
   *
   * @return null|string|object
   */
  public function getTarget();

  /**
   * Get parameters passed to the event
   *
   * @return array|ArrayAccess
   */
  public function getParams();

  /**
   * Get a single parameter by name
   *
   * @param  string $name
   * @param  mixed $default Default value to return if parameter does not exist
   *
   * @return mixed
   */
  public function getParam($name, $default = NULL);

  /**
   * Set the event name
   *
   * @param  string $name
   *
   * @return void
   */
  public function setName($name);

  /**
   * Set the event target/context
   *
   * @param  null|string|object $target
   *
   * @return void
   */
  public function setTarget($target);

  /**
   * Set event parameters
   *
   * @param  string $params
   *
   * @return void
   */
  public function setParams($params);

  /**
   * Set a single parameter by key
   *
   * @param  string $name
   * @param  mixed $value
   *
   * @return void
   */
  public function setParam($name, $value);

  /**
   * Indicate whether or not the parent EventManagerInterface should stop
   * propagating events
   *
   * @param  bool $flag
   *
   * @return void
   */
  public function stopPropagation($flag = TRUE);

  /**
   * Has this event indicated event propagation should stop?
   *
   * @return bool
   */
  public function propagationIsStopped();
}
