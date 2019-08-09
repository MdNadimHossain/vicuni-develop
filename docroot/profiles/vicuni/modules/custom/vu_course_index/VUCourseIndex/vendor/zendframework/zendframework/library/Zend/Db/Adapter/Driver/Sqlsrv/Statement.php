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

namespace Zend\Db\Adapter\Driver\Sqlsrv;

use Zend\Db\Adapter\Driver\StatementInterface;
use Zend\Db\Adapter\Exception;
use Zend\Db\Adapter\ParameterContainer;
use Zend\Db\Adapter\Profiler;

class Statement implements StatementInterface, Profiler\ProfilerAwareInterface {

  /**
   * @var resource
   */
  protected $sqlsrv = NULL;

  /**
   * @var Sqlsrv
   */
  protected $driver = NULL;

  /**
   * @var Profiler\ProfilerInterface
   */
  protected $profiler = NULL;

  /**
   * @var string
   */
  protected $sql = NULL;

  /**
   * @var bool
   */
  protected $isQuery = NULL;

  /**
   * @var array
   */
  protected $parameterReferences = array();

  /**
   * @var ParameterContainer
   */
  protected $parameterContainer = NULL;

  /**
   * @var resource
   */
  protected $resource = NULL;

  /**
   *
   * @var bool
   */
  protected $isPrepared = FALSE;

  /**
   * @var array
   */
  protected $prepareParams = array();

  /**
   * @var array
   */
  protected $prepareOptions = array();

  /**
   * Set driver
   *
   * @param  Sqlsrv $driver
   *
   * @return Statement
   */
  public function setDriver(Sqlsrv $driver) {
    $this->driver = $driver;
    return $this;
  }

  /**
   * @param Profiler\ProfilerInterface $profiler
   *
   * @return Statement
   */
  public function setProfiler(Profiler\ProfilerInterface $profiler) {
    $this->profiler = $profiler;
    return $this;
  }

  /**
   * @return null|Profiler\ProfilerInterface
   */
  public function getProfiler() {
    return $this->profiler;
  }

  /**
   *
   * One of two resource types will be provided here:
   * a) "SQL Server Connection" when a prepared statement needs to still be
   * produced b) "SQL Server Statement" when a prepared statement has been
   * already produced
   * (there will need to already be a bound param set if it applies to this
   * query)
   *
   * @param resource $resource
   *
   * @throws Exception\InvalidArgumentException
   * @return Statement
   */
  public function initialize($resource) {
    $resourceType = get_resource_type($resource);

    if ($resourceType == 'SQL Server Connection') {
      $this->sqlsrv = $resource;
    }
    elseif ($resourceType == 'SQL Server Statement') {
      $this->resource = $resource;
      $this->isPrepared = TRUE;
    }
    else {
      throw new Exception\InvalidArgumentException('Invalid resource provided to ' . __CLASS__);
    }

    return $this;
  }

  /**
   * Set parameter container
   *
   * @param ParameterContainer $parameterContainer
   *
   * @return Statement
   */
  public function setParameterContainer(ParameterContainer $parameterContainer) {
    $this->parameterContainer = $parameterContainer;
    return $this;
  }

  /**
   * @return ParameterContainer
   */
  public function getParameterContainer() {
    return $this->parameterContainer;
  }

  /**
   * @param $resource
   *
   * @return Statement
   */
  public function setResource($resource) {
    $this->resource = $resource;
    return $this;
  }

  /**
   * Get resource
   *
   * @return resource
   */
  public function getResource() {
    return $this->resource;
  }

  /**
   * @param string $sql
   *
   * @return Statement
   */
  public function setSql($sql) {
    $this->sql = $sql;
    return $this;
  }

  /**
   * Get sql
   *
   * @return string
   */
  public function getSql() {
    return $this->sql;
  }

  /**
   * @param string $sql
   * @param array $options
   *
   * @throws Exception\RuntimeException
   * @return Statement
   */
  public function prepare($sql = NULL, array $options = array()) {
    if ($this->isPrepared) {
      throw new Exception\RuntimeException('Already prepared');
    }
    $sql = ($sql) ?: $this->sql;
    $options = ($options) ?: $this->prepareOptions;

    $pRef = &$this->parameterReferences;
    for ($position = 0, $count = substr_count($sql, '?'); $position < $count; $position++) {
      if (!isset($this->prepareParams[$position])) {
        $pRef[$position] = array('', SQLSRV_PARAM_IN, NULL, NULL);
      }
      else {
        $pRef[$position] = &$this->prepareParams[$position];
      }
    }

    $this->resource = sqlsrv_prepare($this->sqlsrv, $sql, $pRef, $options);

    $this->isPrepared = TRUE;

    return $this;
  }

  /**
   * @return bool
   */
  public function isPrepared() {
    return $this->isPrepared;
  }

  /**
   * Execute
   *
   * @param  array|ParameterContainer $parameters
   *
   * @throws Exception\RuntimeException
   * @return Result
   */
  public function execute($parameters = NULL) {
    /** END Standard ParameterContainer Merging Block */
    if (!$this->isPrepared) {
      $this->prepare();
    }

    /** START Standard ParameterContainer Merging Block */
    if (!$this->parameterContainer instanceof ParameterContainer) {
      if ($parameters instanceof ParameterContainer) {
        $this->parameterContainer = $parameters;
        $parameters = NULL;
      }
      else {
        $this->parameterContainer = new ParameterContainer();
      }
    }

    if (is_array($parameters)) {
      $this->parameterContainer->setFromArray($parameters);
    }

    if ($this->parameterContainer->count() > 0) {
      $this->bindParametersFromContainer();
    }

    if ($this->profiler) {
      $this->profiler->profilerStart($this);
    }

    $resultValue = sqlsrv_execute($this->resource);

    if ($this->profiler) {
      $this->profiler->profilerFinish();
    }

    if ($resultValue === FALSE) {
      $errors = sqlsrv_errors();
      // ignore general warnings
      if ($errors[0]['SQLSTATE'] != '01000') {
        throw new Exception\RuntimeException($errors[0]['message']);
      }
    }

    $result = $this->driver->createResult($this->resource);
    return $result;
  }

  /**
   * Bind parameters from container
   *
   */
  protected function bindParametersFromContainer() {
    $values = $this->parameterContainer->getPositionalArray();
    $position = 0;
    foreach ($values as $value) {
      $this->parameterReferences[$position++][0] = $value;
    }
  }

  /**
   * @param array $prepareParams
   */
  public function setPrepareParams(array $prepareParams) {
    $this->prepareParams = $prepareParams;
  }

  /**
   * @param array $prepareOptions
   */
  public function setPrepareOptions(array $prepareOptions) {
    $this->prepareOptions = $prepareOptions;
  }
}
