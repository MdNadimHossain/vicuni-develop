<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source
 *   repository
 * @copyright  Copyright (c) 2005-2010 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license    http://framework.zend.com/license/new-bsd     New BSD License
 */

/**
 * @namespace
 */
namespace Zend\Mvc\Router\Console;

use Traversable;
use Zend\Console\RouteMatcher\DefaultRouteMatcher;
use Zend\Console\Request as ConsoleRequest;
use Zend\Console\RouteMatcher\RouteMatcherInterface;
use Zend\Filter\FilterChain;
use Zend\Mvc\Exception\InvalidArgumentException;
use Zend\Mvc\Router\Exception;
use Zend\Stdlib\ArrayUtils;
use Zend\Stdlib\RequestInterface as Request;
use Zend\Validator\ValidatorChain;

/**
 * Segment route.
 *
 * @copyright  Copyright (c) 2005-2010 Zend Technologies USA Inc.
 *   (http://www.zend.com)
 * @license    http://framework.zend.com/license/new-bsd     New BSD License
 * @see        http://guides.rubyonrails.org/routing.html
 */
class Simple implements RouteInterface {

  /**
   * List of assembled parameters.
   *
   * @var array
   */
  protected $assembledParams = array();

  /**
   * @var RouteMatcherInterface
   */
  protected $matcher;

  /**
   * Create a new simple console route.
   *
   * @param  string|RouteMatcherInterface $routeOrRouteMatcher
   * @param  array $constraints
   * @param  array $defaults
   * @param  array $aliases
   * @param  null|array|Traversable|FilterChain $filters
   * @param  null|array|Traversable|ValidatorChain $validators
   *
   * @throws InvalidArgumentException
   */
  public function __construct(
    $routeOrRouteMatcher,
    array $constraints = array(),
    array $defaults = array(),
    array $aliases = array(),
    $filters = NULL,
    $validators = NULL
  ) {
    if (is_string($routeOrRouteMatcher)) {
      $this->matcher = new DefaultRouteMatcher($routeOrRouteMatcher, $constraints, $defaults, $aliases);
    }
    elseif ($routeOrRouteMatcher instanceof RouteMatcherInterface) {
      $this->matcher = $routeOrRouteMatcher;
    }
    else {
      throw new InvalidArgumentException(
        "routeOrRouteMatcher should either be string, or class implementing RouteMatcherInterface. "
        . gettype($routeOrRouteMatcher) . " was given."
      );
    }
  }

  /**
   * factory(): defined by Route interface.
   *
   * @see    \Zend\Mvc\Router\RouteInterface::factory()
   *
   * @param  array|Traversable $options
   *
   * @throws InvalidArgumentException
   * @return self
   */
  public static function factory($options = array()) {
    if ($options instanceof Traversable) {
      $options = ArrayUtils::iteratorToArray($options);
    }
    elseif (!is_array($options)) {
      throw new InvalidArgumentException(__METHOD__ . ' expects an array or Traversable set of options');
    }

    if (!isset($options['route'])) {
      throw new InvalidArgumentException('Missing "route" in options array');
    }

    foreach (array(
               'constraints',
               'defaults',
               'aliases',
             ) as $opt) {
      if (!isset($options[$opt])) {
        $options[$opt] = array();
      }
    }

    if (!isset($options['validators'])) {
      $options['validators'] = NULL;
    }

    if (!isset($options['filters'])) {
      $options['filters'] = NULL;
    }

    return new static(
      $options['route'],
      $options['constraints'],
      $options['defaults'],
      $options['aliases'],
      $options['filters'],
      $options['validators']
    );
  }

  /**
   * match(): defined by Route interface.
   *
   * @see     Route::match()
   *
   * @param   Request $request
   * @param   null|int $pathOffset
   *
   * @return  RouteMatch
   */
  public function match(Request $request, $pathOffset = NULL) {
    if (!$request instanceof ConsoleRequest) {
      return NULL;
    }

    $params = $request->getParams()->toArray();
    $matches = $this->matcher->match($params);

    if (NULL !== $matches) {
      return new RouteMatch($matches);
    }
    return NULL;
  }

  /**
   * assemble(): Defined by Route interface.
   *
   * @see    \Zend\Mvc\Router\RouteInterface::assemble()
   *
   * @param  array $params
   * @param  array $options
   *
   * @return mixed
   */
  public function assemble(array $params = array(), array $options = array()) {
    $this->assembledParams = array();
  }

  /**
   * getAssembledParams(): defined by Route interface.
   *
   * @see    RouteInterface::getAssembledParams
   * @return array
   */
  public function getAssembledParams() {
    return $this->assembledParams;
  }
}
