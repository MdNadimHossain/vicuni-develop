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

namespace Zend\Mvc;

use Zend\EventManager\EventManagerInterface;
use Zend\EventManager\ListenerAggregateInterface;

class ModuleRouteListener implements ListenerAggregateInterface {
  const MODULE_NAMESPACE = '__NAMESPACE__';
  const ORIGINAL_CONTROLLER = '__CONTROLLER__';

  /**
   * @var \Zend\Stdlib\CallbackHandler[]
   */
  protected $listeners = array();

  /**
   * Attach to an event manager
   *
   * @param  EventManagerInterface $events
   * @param  int $priority
   */
  public function attach(EventManagerInterface $events, $priority = 1) {
    $this->listeners[] = $events->attach(MvcEvent::EVENT_ROUTE, array(
      $this,
      'onRoute'
    ), $priority);
  }

  /**
   * Detach all our listeners from the event manager
   *
   * @param  EventManagerInterface $events
   *
   * @return void
   */
  public function detach(EventManagerInterface $events) {
    foreach ($this->listeners as $index => $listener) {
      if ($events->detach($listener)) {
        unset($this->listeners[$index]);
      }
    }
  }

  /**
   * Listen to the "route" event and determine if the module namespace should
   * be prepended to the controller name.
   *
   * If the route match contains a parameter key matching the MODULE_NAMESPACE
   * constant, that value will be prepended, with a namespace separator, to
   * the matched controller parameter.
   *
   * @param  MvcEvent $e
   *
   * @return null
   */
  public function onRoute(MvcEvent $e) {
    $matches = $e->getRouteMatch();
    if (!$matches instanceof Router\RouteMatch) {
      // Can't do anything without a route match
      return;
    }

    $module = $matches->getParam(self::MODULE_NAMESPACE, FALSE);
    if (!$module) {
      // No module namespace found; nothing to do
      return;
    }

    $controller = $matches->getParam('controller', FALSE);
    if (!$controller) {
      // no controller matched, nothing to do
      return;
    }

    // Ensure the module namespace has not already been applied
    if (0 === strpos($controller, $module)) {
      return;
    }

    // Keep the originally matched controller name around
    $matches->setParam(self::ORIGINAL_CONTROLLER, $controller);

    // Prepend the controllername with the module, and replace it in the
    // matches
    $controller = $module . '\\' . str_replace(' ', '', ucwords(str_replace('-', ' ', $controller)));
    $matches->setParam('controller', $controller);
  }
}
