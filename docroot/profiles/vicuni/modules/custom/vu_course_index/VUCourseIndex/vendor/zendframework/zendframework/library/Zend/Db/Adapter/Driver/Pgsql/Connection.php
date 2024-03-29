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

namespace Zend\Db\Adapter\Driver\Pgsql;

use Zend\Db\Adapter\Driver\ConnectionInterface;
use Zend\Db\Adapter\Exception;
use Zend\Db\Adapter\Profiler;

class Connection implements ConnectionInterface, Profiler\ProfilerAwareInterface {
  /**
   * @var Pgsql
   */
  protected $driver = NULL;

  /**
   * @var Profiler\ProfilerInterface
   */
  protected $profiler = NULL;

  /**
   * Connection parameters
   *
   * @var array
   */
  protected $connectionParameters = array();

  /**
   * @var resource
   */
  protected $resource = NULL;

  /**
   * In transaction
   *
   * @var bool
   */
  protected $inTransaction = FALSE;

  /**
   * Constructor
   *
   * @param resource|array|null $connectionInfo
   */
  public function __construct($connectionInfo = NULL) {
    if (is_array($connectionInfo)) {
      $this->setConnectionParameters($connectionInfo);
    }
    elseif (is_resource($connectionInfo)) {
      $this->setResource($connectionInfo);
    }
  }

  /**
   * Set connection parameters
   *
   * @param  array $connectionParameters
   *
   * @return Connection
   */
  public function setConnectionParameters(array $connectionParameters) {
    $this->connectionParameters = $connectionParameters;
    return $this;
  }

  /**
   * Set driver
   *
   * @param  Pgsql $driver
   *
   * @return Connection
   */
  public function setDriver(Pgsql $driver) {
    $this->driver = $driver;
    return $this;
  }

  /**
   * @param Profiler\ProfilerInterface $profiler
   *
   * @return Connection
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
   * Set resource
   *
   * @param  resource $resource
   *
   * @return Connection
   */
  public function setResource($resource) {
    $this->resource = $resource;
    return;
  }

  /**
   * Get current schema
   *
   * @return null|string
   */
  public function getCurrentSchema() {
    if (!$this->isConnected()) {
      $this->connect();
    }

    $result = pg_query($this->resource, 'SELECT CURRENT_SCHEMA AS "currentschema"');
    if ($result == FALSE) {
      return NULL;
    }
    return pg_fetch_result($result, 0, 'currentschema');
  }

  /**
   * Get resource
   *
   * @return resource
   */
  public function getResource() {
    if (!$this->isConnected()) {
      $this->connect();
    }
    return $this->resource;
  }

  /**
   * Connect to the database
   *
   * @return Connection
   * @throws Exception\RuntimeException on failure
   */
  public function connect() {
    if (is_resource($this->resource)) {
      return $this;
    }

    // localize
    $p = $this->connectionParameters;

    // given a list of key names, test for existence in $p
    $findParameterValue = function (array $names) use ($p) {
      foreach ($names as $name) {
        if (isset($p[$name])) {
          return $p[$name];
        }
      }
      return NULL;
    };

    $connection = array();
    $connection['host'] = $findParameterValue(array('hostname', 'host'));
    $connection['user'] = $findParameterValue(array('username', 'user'));
    $connection['password'] = $findParameterValue(array(
      'password',
      'passwd',
      'pw'
    ));
    $connection['dbname'] = $findParameterValue(array(
      'database',
      'dbname',
      'db',
      'schema'
    ));
    $connection['port'] = (isset($p['port'])) ? (int) $p['port'] : NULL;
    $connection['socket'] = (isset($p['socket'])) ? $p['socket'] : NULL;

    $connection = array_filter($connection); // remove nulls
    $connection = http_build_query($connection, NULL, ' '); // @link http://php.net/pg_connect

    set_error_handler(function ($number, $string) {
      throw new Exception\RuntimeException(
        __METHOD__ . ': Unable to connect to database', NULL, new Exception\ErrorException($string, $number)
      );
    });
    $this->resource = pg_connect($connection);
    restore_error_handler();

    if ($this->resource === FALSE) {
      throw new Exception\RuntimeException(sprintf(
        '%s: Unable to connect to database',
        __METHOD__
      ));
    }

    return $this;
  }

  /**
   * @return bool
   */
  public function isConnected() {
    return (is_resource($this->resource));
  }

  /**
   * @return void
   */
  public function disconnect() {
    pg_close($this->resource);
  }

  /**
   * @return void
   */
  public function beginTransaction() {
    if ($this->inTransaction) {
      throw new Exception\RuntimeException('Nested transactions are not supported');
    }

    if (!$this->isConnected()) {
      $this->connect();
    }

    pg_query($this->resource, 'BEGIN');
    $this->inTransaction = TRUE;
  }

  /**
   * In transaction
   *
   * @return bool
   */
  public function inTransaction() {
    return $this->inTransaction;
  }

  /**
   * @return void
   */
  public function commit() {
    if (!$this->inTransaction) {
      return; // We ignore attempts to commit non-existing transaction
    }

    pg_query($this->resource, 'COMMIT');
    $this->inTransaction = FALSE;
  }

  /**
   * @return void
   */
  public function rollback() {
    if (!$this->inTransaction) {
      return;
    }

    pg_query($this->resource, 'ROLLBACK');
    $this->inTransaction = FALSE;
  }

  /**
   * @param  string $sql
   *
   * @throws Exception\InvalidQueryException
   * @return resource|\Zend\Db\ResultSet\ResultSetInterface
   */
  public function execute($sql) {
    if (!$this->isConnected()) {
      $this->connect();
    }

    if ($this->profiler) {
      $this->profiler->profilerStart($sql);
    }

    $resultResource = pg_query($this->resource, $sql);

    if ($this->profiler) {
      $this->profiler->profilerFinish($sql);
    }

    // if the returnValue is something other than a pg result resource, bypass wrapping it
    if ($resultResource === FALSE) {
      throw new Exception\InvalidQueryException(pg_errormessage());
    }

    $resultPrototype = $this->driver->createResult(($resultResource === TRUE) ? $this->resource : $resultResource);
    return $resultPrototype;
  }

  /**
   * @param  null $name Ignored
   *
   * @return string
   */
  public function getLastGeneratedValue($name = NULL) {
    if ($name == NULL) {
      return NULL;
    }
    $result = pg_query($this->resource, 'SELECT CURRVAL(\'' . str_replace('\'', '\\\'', $name) . '\') as "currval"');
    return pg_fetch_result($result, 0, 'currval');
  }
}
