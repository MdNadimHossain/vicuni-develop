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

namespace Zend\Db\Adapter\Driver\Oci8;

use Zend\Db\Adapter\Driver\DriverInterface;
use Zend\Db\Adapter\Exception;
use Zend\Db\Adapter\Profiler;

class Oci8 implements DriverInterface, Profiler\ProfilerAwareInterface {

  /**
   * @var Connection
   */
  protected $connection = NULL;

  /**
   * @var Statement
   */
  protected $statementPrototype = NULL;

  /**
   * @var Result
   */
  protected $resultPrototype = NULL;

  /**
   * @var Profiler\ProfilerInterface
   */
  protected $profiler = NULL;

  /**
   * @var array
   */
  protected $options = array();

  /**
   * @param array|Connection|\oci8 $connection
   * @param null|Statement $statementPrototype
   * @param null|Result $resultPrototype
   * @param array $options
   */
  public function __construct($connection, Statement $statementPrototype = NULL, Result $resultPrototype = NULL, array $options = array()) {
    if (!$connection instanceof Connection) {
      $connection = new Connection($connection);
    }

    $options = array_intersect_key(array_merge($this->options, $options), $this->options);

    $this->registerConnection($connection);
    $this->registerStatementPrototype(($statementPrototype) ?: new Statement());
    $this->registerResultPrototype(($resultPrototype) ?: new Result());
  }

  /**
   * @param Profiler\ProfilerInterface $profiler
   *
   * @return Oci8
   */
  public function setProfiler(Profiler\ProfilerInterface $profiler) {
    $this->profiler = $profiler;
    if ($this->connection instanceof Profiler\ProfilerAwareInterface) {
      $this->connection->setProfiler($profiler);
    }
    if ($this->statementPrototype instanceof Profiler\ProfilerAwareInterface) {
      $this->statementPrototype->setProfiler($profiler);
    }
    return $this;
  }

  /**
   * @return null|Profiler\ProfilerInterface
   */
  public function getProfiler() {
    return $this->profiler;
  }

  /**
   * Register connection
   *
   * @param  Connection $connection
   *
   * @return Oci8
   */
  public function registerConnection(Connection $connection) {
    $this->connection = $connection;
    $this->connection->setDriver($this); // needs access to driver to createStatement()
    return $this;
  }

  /**
   * Register statement prototype
   *
   * @param Statement $statementPrototype
   *
   * @return Oci8
   */
  public function registerStatementPrototype(Statement $statementPrototype) {
    $this->statementPrototype = $statementPrototype;
    $this->statementPrototype->setDriver($this); // needs access to driver to createResult()
    return $this;
  }

  /**
   * @return null|Statement
   */
  public function getStatementPrototype() {
    return $this->statementPrototype;
  }

  /**
   * Register result prototype
   *
   * @param Result $resultPrototype
   *
   * @return Oci8
   */
  public function registerResultPrototype(Result $resultPrototype) {
    $this->resultPrototype = $resultPrototype;
    return $this;
  }

  /**
   * @return null|Result
   */
  public function getResultPrototype() {
    return $this->resultPrototype;
  }

  /**
   * Get database platform name
   *
   * @param  string $nameFormat
   *
   * @return string
   */
  public function getDatabasePlatformName($nameFormat = self::NAME_FORMAT_CAMELCASE) {
    return 'Oracle';
  }

  /**
   * Check environment
   */
  public function checkEnvironment() {
    if (!extension_loaded('oci8')) {
      throw new Exception\RuntimeException('The Oci8 extension is required for this adapter but the extension is not loaded');
    }
  }

  /**
   * @return Connection
   */
  public function getConnection() {
    return $this->connection;
  }

  /**
   * @param string $sqlOrResource
   *
   * @return Statement
   */
  public function createStatement($sqlOrResource = NULL) {
    $statement = clone $this->statementPrototype;
    if (is_resource($sqlOrResource) && get_resource_type($sqlOrResource) == 'oci8 statement') {
      $statement->setResource($sqlOrResource);
    }
    else {
      if (is_string($sqlOrResource)) {
        $statement->setSql($sqlOrResource);
      }
      elseif ($sqlOrResource !== NULL) {
        throw new Exception\InvalidArgumentException(
          'Oci8 only accepts an SQL string or an oci8 resource in ' . __FUNCTION__
        );
      }
      if (!$this->connection->isConnected()) {
        $this->connection->connect();
      }
      $statement->initialize($this->connection->getResource());
    }
    return $statement;
  }

  /**
   * @param  resource $resource
   * @param  null $isBuffered
   *
   * @return Result
   */
  public function createResult($resource, $isBuffered = NULL) {
    $result = clone $this->resultPrototype;
    $result->initialize($resource, $this->connection->getLastGeneratedValue(), $isBuffered);
    return $result;
  }

  /**
   * @return array
   */
  public function getPrepareType() {
    return self::PARAMETERIZATION_NAMED;
  }

  /**
   * @param string $name
   * @param mixed $type
   *
   * @return string
   */
  public function formatParameterName($name, $type = NULL) {
    return ':' . $name;
  }

  /**
   * @return mixed
   */
  public function getLastGeneratedValue() {
    return $this->getConnection()->getLastGeneratedValue();
  }

}
