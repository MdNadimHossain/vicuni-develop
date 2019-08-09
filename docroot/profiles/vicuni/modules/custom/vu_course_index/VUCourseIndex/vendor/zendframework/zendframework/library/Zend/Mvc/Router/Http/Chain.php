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

namespace Zend\Mvc\Router\Http;

use ArrayObject;
use Traversable;
use Zend\Mvc\Router\Exception;
use Zend\Mvc\Router\PriorityList;
use Zend\Mvc\Router\RoutePluginManager;
use Zend\Stdlib\ArrayUtils;
use Zend\Stdlib\RequestInterface as Request;

/**
 * Chain route.
 */
class Chain extends TreeRouteStack implements RouteInterface {
  /**
   * Chain routes.
   *
   * @var array
   */
  protected $chainRoutes;

  /**
   * List of assembled parameters.
   *
   * @var array
   */
  protected $assembledParams = array();

  /**
   * Create a new part route.
   *
   * @param  array $routes
   * @param  RoutePluginManager $routePlugins
   * @param  ArrayObject|null $prototypes
   */
  public function __construct(array $routes, RoutePluginManager $routePlugins, ArrayObject $prototypes = NULL) {
    $this->chainRoutes = array_reverse($routes);
    $this->routePluginManager = $routePlugins;
    $this->routes = new PriorityList();
    $this->prototypes = $prototypes;
  }

  /**
   * factory(): defined by RouteInterface interface.
   *
   * @see    \Zend\Mvc\Router\RouteInterface::factory()
   *
   * @param  mixed $options
   *
   * @throws Exception\InvalidArgumentException
   * @return Part
   */
  public static function factory($options = array()) {
    if ($options instanceof Traversable) {
      $options = ArrayUtils::iteratorToArray($options);
    }
    elseif (!is_array($options)) {
      throw new Exception\InvalidArgumentException(__METHOD__ . ' expects an array or Traversable set of options');
    }

    if (!isset($options['routes'])) {
      throw new Exception\InvalidArgumentException('Missing "routes" in options array');
    }

    if (!isset($options['prototypes'])) {
      $options['prototypes'] = NULL;
    }

    if ($options['routes'] instanceof Traversable) {
      $options['routes'] = ArrayUtils::iteratorToArray($options['child_routes']);
    }

    if (!isset($options['route_plugins'])) {
      throw new Exception\InvalidArgumentException('Missing "route_plugins" in options array');
    }

    return new static(
      $options['routes'],
      $options['route_plugins'],
      $options['prototypes']
    );
  }

  /**
   * match(): defined by RouteInterface interface.
   *
   * @see    \Zend\Mvc\Router\RouteInterface::match()
   *
   * @param  Request $request
   * @param  int|null $pathOffset
   * @param  array $options
   *
   * @return RouteMatch|null
   */
  public function match(Request $request, $pathOffset = NULL, array $options = array()) {
    if (!method_exists($request, 'getUri')) {
      return NULL;
    }

    if ($pathOffset === NULL) {
      $mustTerminate = TRUE;
      $pathOffset = 0;
    }
    else {
      $mustTerminate = FALSE;
    }

    if ($this->chainRoutes !== NULL) {
      $this->addRoutes($this->chainRoutes);
      $this->chainRoutes = NULL;
    }

    $match = new RouteMatch(array());
    $uri = $request->getUri();
    $pathLength = strlen($uri->getPath());

    foreach ($this->routes as $route) {
      $subMatch = $route->match($request, $pathOffset, $options);

      if ($subMatch === NULL) {
        return NULL;
      }

      $match->merge($subMatch);
      $pathOffset += $subMatch->getLength();
    }

    if ($mustTerminate && $pathOffset !== $pathLength) {
      return NULL;
    }

    return $match;
  }

  /**
   * assemble(): Defined by RouteInterface interface.
   *
   * @see    \Zend\Mvc\Router\RouteInterface::assemble()
   *
   * @param  array $params
   * @param  array $options
   *
   * @return mixed
   */
  public function assemble(array $params = array(), array $options = array()) {
    if ($this->chainRoutes !== NULL) {
      $this->addRoutes($this->chainRoutes);
      $this->chainRoutes = NULL;
    }

    $this->assembledParams = array();

    end($this->routes);
    $lastRouteKey = key($this->routes);
    $path = '';

    foreach ($this->routes as $key => $route) {
      $chainOptions = $options;
      $hasChild = isset($options['has_child']) ? $options['has_child'] : FALSE;

      $chainOptions['has_child'] = ($hasChild || $key !== $lastRouteKey);

      $path .= $route->assemble($params, $chainOptions);
      $params = array_diff_key($params, array_flip($route->getAssembledParams()));

      $this->assembledParams += $route->getAssembledParams();
    }

    return $path;
  }

  /**
   * getAssembledParams(): defined by RouteInterface interface.
   *
   * @see    RouteInterface::getAssembledParams
   * @return array
   */
  public function getAssembledParams() {
    return $this->assembledParams;
  }
}
