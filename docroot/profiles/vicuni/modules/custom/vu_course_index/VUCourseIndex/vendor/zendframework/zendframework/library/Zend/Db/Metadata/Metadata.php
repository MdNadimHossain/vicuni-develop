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

namespace Zend\Db\Metadata;

use Zend\Db\Adapter\Adapter;

class Metadata implements MetadataInterface {
  /**
   * Adapter
   *
   * @var Adapter
   */
  protected $adapter = NULL;

  /**
   * @var MetadataInterface
   */
  protected $source = NULL;

  /**
   * Constructor
   *
   * @param Adapter $adapter
   */
  public function __construct(Adapter $adapter) {
    $this->adapter = $adapter;
    $this->source = $this->createSourceFromAdapter($adapter);
  }

  /**
   * Create source from adapter
   *
   * @param  Adapter $adapter
   *
   * @return Source\AbstractSource
   */
  protected function createSourceFromAdapter(Adapter $adapter) {
    switch ($adapter->getPlatform()->getName()) {
      case 'MySQL':
        return new Source\MysqlMetadata($adapter);
      case 'SQLServer':
        return new Source\SqlServerMetadata($adapter);
      case 'SQLite':
        return new Source\SqliteMetadata($adapter);
      case 'PostgreSQL':
        return new Source\PostgresqlMetadata($adapter);
      case 'Oracle':
        return new Source\OracleMetadata($adapter);
    }

    throw new \Exception('cannot create source from adapter');
  }

  // @todo methods

  /**
   * Get base tables and views
   *
   * @param string $schema
   * @param bool $includeViews
   *
   * @return Object\TableObject[]
   */
  public function getTables($schema = NULL, $includeViews = FALSE) {
    return $this->source->getTables($schema, $includeViews);
  }

  /**
   * Get base tables and views
   *
   * @param string $schema
   *
   * @return Object\TableObject[]
   */
  public function getViews($schema = NULL) {
    return $this->source->getViews($schema);
  }

  /**
   * Get triggers
   *
   * @param  string $schema
   *
   * @return array
   */
  public function getTriggers($schema = NULL) {
    return $this->source->getTriggers($schema);
  }

  /**
   * Get constraints
   *
   * @param  string $table
   * @param  string $schema
   *
   * @return array
   */
  public function getConstraints($table, $schema = NULL) {
    return $this->source->getConstraints($table, $schema);
  }

  /**
   * Get columns
   *
   * @param  string $table
   * @param  string $schema
   *
   * @return array
   */
  public function getColumns($table, $schema = NULL) {
    return $this->source->getColumns($table, $schema);
  }

  /**
   * Get constraint keys
   *
   * @param  string $constraint
   * @param  string $table
   * @param  string $schema
   *
   * @return array
   */
  public function getConstraintKeys($constraint, $table, $schema = NULL) {
    return $this->source->getConstraintKeys($constraint, $table, $schema);
  }

  /**
   * Get constraints
   *
   * @param  string $constraintName
   * @param  string $table
   * @param  string $schema
   *
   * @return Object\ConstraintObject
   */
  public function getConstraint($constraintName, $table, $schema = NULL) {
    return $this->source->getConstraint($constraintName, $table, $schema);
  }

  /**
   * Get schemas
   */
  public function getSchemas() {
    return $this->source->getSchemas();
  }

  /**
   * Get table names
   *
   * @param  string $schema
   * @param  bool $includeViews
   *
   * @return array
   */
  public function getTableNames($schema = NULL, $includeViews = FALSE) {
    return $this->source->getTableNames($schema, $includeViews);
  }

  /**
   * Get table
   *
   * @param  string $tableName
   * @param  string $schema
   *
   * @return Object\TableObject
   */
  public function getTable($tableName, $schema = NULL) {
    return $this->source->getTable($tableName, $schema);
  }

  /**
   * Get views names
   *
   * @param string $schema
   *
   * @return \Zend\Db\Metadata\Object\TableObject
   */
  public function getViewNames($schema = NULL) {
    return $this->source->getViewNames($schema);
  }

  /**
   * Get view
   *
   * @param string $viewName
   * @param string $schema
   *
   * @return \Zend\Db\Metadata\Object\TableObject
   */
  public function getView($viewName, $schema = NULL) {
    return $this->source->getView($viewName, $schema);
  }

  /**
   * Get trigger names
   *
   * @param string $schema
   *
   * @return array
   */
  public function getTriggerNames($schema = NULL) {
    return $this->source->getTriggerNames($schema);
  }

  /**
   * Get trigger
   *
   * @param string $triggerName
   * @param string $schema
   *
   * @return \Zend\Db\Metadata\Object\TriggerObject
   */
  public function getTrigger($triggerName, $schema = NULL) {
    return $this->source->getTrigger($triggerName, $schema);
  }

  /**
   * Get column names
   *
   * @param string $table
   * @param string $schema
   *
   * @return array
   */
  public function getColumnNames($table, $schema = NULL) {
    return $this->source->getColumnNames($table, $schema);
  }

  /**
   * Get column
   *
   * @param string $columnName
   * @param string $table
   * @param string $schema
   *
   * @return \Zend\Db\Metadata\Object\ColumnObject
   */
  public function getColumn($columnName, $table, $schema = NULL) {
    return $this->source->getColumn($columnName, $table, $schema);
  }
}
