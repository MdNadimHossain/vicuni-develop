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

namespace Zend\Console;

use Zend\Stdlib\Message;
use Zend\Stdlib\Parameters;
use Zend\Stdlib\RequestInterface;

class Request extends Message implements RequestInterface {
  /**
   * @var \Zend\Stdlib\Parameters
   */
  protected $params = NULL;

  /**
   * @var \Zend\Stdlib\Parameters
   */
  protected $envParams = NULL;

  /**
   * @var string
   */
  protected $scriptName = NULL;

  /**
   * Create a new CLI request
   *
   * @param array|null $args Console arguments. If not supplied,
   *   $_SERVER['argv'] will be used
   * @param array|null $env Environment data. If not supplied, $_ENV will be
   *   used
   *
   * @throws Exception\RuntimeException
   */
  public function __construct(array $args = NULL, array $env = NULL) {
    if ($args === NULL) {
      if (!isset($_SERVER['argv'])) {
        $errorDescription = (ini_get('register_argc_argv') == FALSE)
          ? "Cannot create Console\\Request because PHP ini option 'register_argc_argv' is set Off"
          : 'Cannot create Console\\Request because $_SERVER["argv"] is not set for unknown reason.';
        throw new Exception\RuntimeException($errorDescription);
      }
      $args = $_SERVER['argv'];
    }

    if ($env === NULL) {
      $env = $_ENV;
    }

    /**
     * Extract first param assuming it is the script name
     */
    if (count($args) > 0) {
      $this->setScriptName(array_shift($args));
    }

    /**
     * Store runtime params
     */
    $this->params()->fromArray($args);
    $this->setContent($args);

    /**
     * Store environment data
     */
    $this->env()->fromArray($env);
  }

  /**
   * Exchange parameters object
   *
   * @param \Zend\Stdlib\Parameters $params
   *
   * @return Request
   */
  public function setParams(Parameters $params) {
    $this->params = $params;
    $this->setContent($params);
    return $this;
  }

  /**
   * Return the container responsible for parameters
   *
   * @return \Zend\Stdlib\Parameters
   */
  public function getParams() {
    if ($this->params === NULL) {
      $this->params = new Parameters();
    }

    return $this->params;
  }

  /**
   * Return a single parameter.
   * Shortcut for $request->params()->get()
   *
   * @param string $name Parameter name
   * @param string $default (optional) default value in case the parameter does
   *   not exist
   *
   * @return mixed
   */
  public function getParam($name, $default = NULL) {
    return $this->params()->get($name, $default);
  }

  /**
   * Return the container responsible for parameters
   *
   * @return \Zend\Stdlib\Parameters
   */
  public function params() {
    return $this->getParams();
  }

  /**
   * Provide an alternate Parameter Container implementation for env parameters
   * in this object, (this is NOT the primary API for value setting, for that
   * see env())
   *
   * @param \Zend\Stdlib\Parameters $env
   *
   * @return \Zend\Console\Request
   */
  public function setEnv(Parameters $env) {
    $this->envParams = $env;
    return $this;
  }

  /**
   * Return a single parameter container responsible for env parameters
   *
   * @param string $name Parameter name
   * @param string $default (optional) default value in case the parameter does
   *   not exist
   *
   * @return \Zend\Stdlib\Parameters
   */
  public function getEnv($name, $default = NULL) {
    return $this->env()->get($name, $default);
  }

  /**
   * Return the parameter container responsible for env parameters
   *
   * @return \Zend\Stdlib\Parameters
   */
  public function env() {
    if ($this->envParams === NULL) {
      $this->envParams = new Parameters();
    }

    return $this->envParams;
  }

  /**
   * @return string
   */
  public function toString() {
    return trim(implode(' ', $this->params()->toArray()));
  }

  /**
   * Allow PHP casting of this object
   *
   * @return string
   */
  public function __toString() {
    return $this->toString();
  }

  /**
   * @param string $scriptName
   */
  public function setScriptName($scriptName) {
    $this->scriptName = $scriptName;
  }

  /**
   * @return string
   */
  public function getScriptName() {
    return $this->scriptName;
  }
}
