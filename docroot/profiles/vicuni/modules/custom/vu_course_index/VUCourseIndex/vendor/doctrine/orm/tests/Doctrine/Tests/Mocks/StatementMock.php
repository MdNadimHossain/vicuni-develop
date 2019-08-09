<?php

namespace Doctrine\Tests\Mocks;

/**
 * This class is a mock of the Statement interface.
 *
 * @author Alexander <iam.asm89@gmail.com>
 */
class StatementMock implements \IteratorAggregate, \Doctrine\DBAL\Driver\Statement {
  /**
   * {@inheritdoc}
   */
  public function bindValue($param, $value, $type = NULL) {
  }

  /**
   * {@inheritdoc}
   */
  public function bindParam($column, &$variable, $type = NULL, $length = NULL) {
  }

  /**
   * {@inheritdoc}
   */
  public function errorCode() {
  }

  /**
   * {@inheritdoc}
   */
  public function errorInfo() {
  }

  /**
   * {@inheritdoc}
   */
  public function execute($params = NULL) {
  }

  /**
   * {@inheritdoc}
   */
  public function rowCount() {
  }

  /**
   * {@inheritdoc}
   */
  public function closeCursor() {
  }

  /**
   * {@inheritdoc}
   */
  public function columnCount() {
  }

  /**
   * {@inheritdoc}
   */
  public function setFetchMode($fetchStyle, $arg2 = NULL, $arg3 = NULL) {
  }

  /**
   * {@inheritdoc}
   */
  public function fetch($fetchStyle = NULL) {
  }

  /**
   * {@inheritdoc}
   */
  public function fetchAll($fetchStyle = NULL) {
  }

  /**
   * {@inheritdoc}
   */
  public function fetchColumn($columnIndex = 0) {
  }

  /**
   * {@inheritdoc}
   */
  public function getIterator() {
  }
}
