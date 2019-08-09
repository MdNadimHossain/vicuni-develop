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

interface MetadataInterface {
  public function getSchemas();

  public function getTableNames($schema = NULL, $includeViews = FALSE);

  public function getTables($schema = NULL, $includeViews = FALSE);

  public function getTable($tableName, $schema = NULL);

  public function getViewNames($schema = NULL);

  public function getViews($schema = NULL);

  public function getView($viewName, $schema = NULL);

  public function getColumnNames($table, $schema = NULL);

  public function getColumns($table, $schema = NULL);

  public function getColumn($columnName, $table, $schema = NULL);

  public function getConstraints($table, $schema = NULL);

  public function getConstraint($constraintName, $table, $schema = NULL);

  public function getConstraintKeys($constraint, $table, $schema = NULL);

  public function getTriggerNames($schema = NULL);

  public function getTriggers($schema = NULL);

  public function getTrigger($triggerName, $schema = NULL);

}
