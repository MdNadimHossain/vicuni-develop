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

use Iterator;
use Zend\Db\Adapter\Driver\ResultInterface;
use Zend\Db\Adapter\Exception;

class Result implements Iterator, ResultInterface {

  /**
   * @var resource
   */
  protected $resource = NULL;

  /**
   * @var bool
   */
  protected $isBuffered = NULL;

  /**
   * Cursor position
   *
   * @var int
   */
  protected $position = 0;

  /**
   * Number of known rows
   *
   * @var int
   */
  protected $numberOfRows = -1;

  /**
   * Is the current() operation already complete for this pointer position?
   *
   * @var bool
   */
  protected $currentComplete = FALSE;

  /**
   * @var bool
   */
  protected $currentData = FALSE;

  /**
   *
   * @var array
   */
  protected $statementBindValues = array('keys' => NULL, 'values' => array());

  /**
   * @var mixed
   */
  protected $generatedValue = NULL;

  /**
   * Initialize
   *
   * @param resource $resource
   *
   * @return Result
   */
  public function initialize($resource /*, $generatedValue, $isBuffered = null*/) {
    if (!is_resource($resource) && get_resource_type($resource) !== 'oci8 statement') {
      throw new Exception\InvalidArgumentException('Invalid resource provided.');
    }
    $this->resource = $resource;
    return $this;
  }

  /**
   * Force buffering at driver level
   *
   * Oracle does not support this, to my knowledge (@ralphschindler)
   *
   * @throws Exception\RuntimeException
   */
  public function buffer() {
    return NULL;
  }

  /**
   * Is the result buffered?
   *
   * @return bool
   */
  public function isBuffered() {
    return FALSE;
  }

  /**
   * Return the resource
   *
   * @return mixed
   */
  public function getResource() {
    return $this->resource;
  }

  /**
   * Is query result?
   *
   * @return bool
   */
  public function isQueryResult() {
    return (oci_num_fields($this->resource) > 0);
  }

  /**
   * Get affected rows
   *
   * @return int
   */
  public function getAffectedRows() {
    return oci_num_rows($this->resource);
  }

  /**
   * Current
   *
   * @return mixed
   */
  public function current() {
    if ($this->currentComplete == FALSE) {
      if ($this->loadData() === FALSE) {
        return FALSE;
      }
    }

    return $this->currentData;
  }

  /**
   * Load from oci8 result
   *
   * @return bool
   */
  protected function loadData() {
    $this->currentComplete = TRUE;
    $this->currentData = oci_fetch_assoc($this->resource);

    if ($this->currentData !== FALSE) {
      $this->position++;
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Next
   */
  public function next() {
    return $this->loadData();
  }

  /**
   * Key
   *
   * @return mixed
   */
  public function key() {
    return $this->position;
  }

  /**
   * Rewind
   */
  public function rewind() {
    if ($this->position > 0) {
      throw new Exception\RuntimeException('Oci8 results cannot be rewound for multiple iterations');
    }
  }

  /**
   * Valid
   *
   * @return bool
   */
  public function valid() {
    if ($this->currentComplete) {
      return ($this->currentData !== FALSE);
    }

    return $this->loadData();
  }

  /**
   * Count
   *
   * @return int
   */
  public function count() {
    // @todo OCI8 row count in Driver Result
    return NULL;
  }

  /**
   * @return int
   */
  public function getFieldCount() {
    return oci_num_fields($this->resource);
  }

  /**
   * @return mixed|null
   */
  public function getGeneratedValue() {
    // @todo OCI8 generated value in Driver Result
    return NULL;
  }

}
