<?php

namespace Doctrine\Tests\Mocks;

/**
 * This class is a mock of the Statement interface that can be passed in to the
 * Hydrator to test the hydration standalone with faked result sets.
 *
 * @author  Roman Borschel <roman@code-factory.org>
 */
class HydratorMockStatement implements \Doctrine\DBAL\Driver\Statement {
  private $_resultSet;

  /**
   * Creates a new mock statement that will serve the provided fake result set
   * to clients.
   *
   * @param array $resultSet The faked SQL result set.
   */
  public function __construct(array $resultSet) {
    $this->_resultSet = $resultSet;
  }

  /**
   * Fetches all rows from the result set.
   *
   * @return array
   */
  public function fetchAll($fetchMode = NULL, $columnIndex = NULL, array $ctorArgs = NULL) {
    return $this->_resultSet;
  }

  public function fetchColumn($columnNumber = 0) {
    $row = current($this->_resultSet);
    if (!is_array($row)) {
      return FALSE;
    }
    $val = array_shift($row);
    return $val !== NULL ? $val : FALSE;
  }

  /**
   * Fetches the next row in the result set.
   *
   */
  public function fetch($fetchMode = NULL) {
    $current = current($this->_resultSet);
    next($this->_resultSet);
    return $current;
  }

  /**
   * Closes the cursor, enabling the statement to be executed again.
   *
   * @return boolean
   */
  public function closeCursor() {
    return TRUE;
  }

  public function setResultSet(array $resultSet) {
    reset($resultSet);
    $this->_resultSet = $resultSet;
  }

  public function bindColumn($column, &$param, $type = NULL) {
  }

  public function bindValue($param, $value, $type = NULL) {
  }

  public function bindParam($column, &$variable, $type = NULL, $length = NULL, $driverOptions = array()) {
  }

  public function columnCount() {
  }

  public function errorCode() {
  }

  public function errorInfo() {
  }

  public function execute($params = array()) {
  }

  public function rowCount() {
  }
}
