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

namespace Zend\Db\Adapter\Driver\Mysqli;

use Zend\Db\Adapter\Driver\StatementInterface;
use Zend\Db\Adapter\Exception;
use Zend\Db\Adapter\ParameterContainer;
use Zend\Db\Adapter\Profiler;

class Statement implements StatementInterface, Profiler\ProfilerAwareInterface {

  /**
   * @var \mysqli
   */
  protected $mysqli = NULL;

  /**
   * @var Mysqli
   */
  protected $driver = NULL;

  /**
   * @var Profiler\ProfilerInterface
   */
  protected $profiler = NULL;

  /**
   * @var string
   */
  protected $sql = '';

  /**
   * Parameter container
   *
   * @var ParameterContainer
   */
  protected $parameterContainer = NULL;

  /**
   * @var \mysqli_stmt
   */
  protected $resource = NULL;

  /**
   * Is prepared
   *
   * @var bool
   */
  protected $isPrepared = FALSE;

  /**
   * @var bool
   */
  protected $bufferResults = FALSE;

  /**
   * @param  bool $bufferResults
   */
  public function __construct($bufferResults = FALSE) {
    $this->bufferResults = (bool) $bufferResults;
  }

  /**
   * Set driver
   *
   * @param  Mysqli $driver
   *
   * @return Statement
   */
  public function setDriver(Mysqli $driver) {
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
   * Initialize
   *
   * @param  \mysqli $mysqli
   *
   * @return Statement
   */
  public function initialize(\mysqli $mysqli) {
    $this->mysqli = $mysqli;
    return $this;
  }

  /**
   * Set sql
   *
   * @param  string $sql
   *
   * @return Statement
   */
  public function setSql($sql) {
    $this->sql = $sql;
    return $this;
  }

  /**
   * Set Parameter container
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
   * Get resource
   *
   * @return mixed
   */
  public function getResource() {
    return $this->resource;
  }

  /**
   * Set resource
   *
   * @param  \mysqli_stmt $mysqliStatement
   *
   * @return Statement
   */
  public function setResource(\mysqli_stmt $mysqliStatement) {
    $this->resource = $mysqliStatement;
    $this->isPrepared = TRUE;
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
   * Get parameter count
   *
   * @return ParameterContainer
   */
  public function getParameterContainer() {
    return $this->parameterContainer;
  }

  /**
   * Is prepared
   *
   * @return bool
   */
  public function isPrepared() {
    return $this->isPrepared;
  }

  /**
   * Prepare
   *
   * @param string $sql
   *
   * @throws Exception\InvalidQueryException
   * @throws Exception\RuntimeException
   * @return Statement
   */
  public function prepare($sql = NULL) {
    if ($this->isPrepared) {
      throw new Exception\RuntimeException('This statement has already been prepared');
    }

    $sql = ($sql) ?: $this->sql;

    $this->resource = $this->mysqli->prepare($sql);
    if (!$this->resource instanceof \mysqli_stmt) {
      throw new Exception\InvalidQueryException(
        'Statement couldn\'t be produced with sql: ' . $sql,
        NULL,
        new Exception\ErrorException($this->mysqli->error, $this->mysqli->errno)
      );
    }

    $this->isPrepared = TRUE;
    return $this;
  }

  /**
   * Execute
   *
   * @param  ParameterContainer|array $parameters
   *
   * @throws Exception\RuntimeException
   * @return mixed
   */
  public function execute($parameters = NULL) {
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
    /** END Standard ParameterContainer Merging Block */

    if ($this->profiler) {
      $this->profiler->profilerStart($this);
    }

    $return = $this->resource->execute();

    if ($this->profiler) {
      $this->profiler->profilerFinish();
    }

    if ($return === FALSE) {
      throw new Exception\RuntimeException($this->resource->error);
    }

    if ($this->bufferResults === TRUE) {
      $this->resource->store_result();
      $this->isPrepared = FALSE;
      $buffered = TRUE;
    }
    else {
      $buffered = FALSE;
    }

    $result = $this->driver->createResult($this->resource, $buffered);
    return $result;
  }

  /**
   * Bind parameters from container
   *
   * @return void
   */
  protected function bindParametersFromContainer() {
    $parameters = $this->parameterContainer->getNamedArray();
    $type = '';
    $args = array();

    foreach ($parameters as $name => &$value) {
      if ($this->parameterContainer->offsetHasErrata($name)) {
        switch ($this->parameterContainer->offsetGetErrata($name)) {
          case ParameterContainer::TYPE_DOUBLE:
            $type .= 'd';
            break;
          case ParameterContainer::TYPE_NULL:
            $value = NULL; // as per @see http://www.php.net/manual/en/mysqli-stmt.bind-param.php#96148
          case ParameterContainer::TYPE_INTEGER:
            $type .= 'i';
            break;
          case ParameterContainer::TYPE_STRING:
          default:
            $type .= 's';
            break;
        }
      }
      else {
        $type .= 's';
      }
      $args[] = &$value;
    }

    if ($args) {
      array_unshift($args, $type);
      call_user_func_array(array($this->resource, 'bind_param'), $args);
    }
  }
}
