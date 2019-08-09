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

namespace Zend\Db\Sql\Platform\Oracle;

use Zend\Db\Adapter\AdapterInterface;
use Zend\Db\Adapter\Driver\DriverInterface;
use Zend\Db\Adapter\ParameterContainer;
use Zend\Db\Adapter\Platform\PlatformInterface;
use Zend\Db\Adapter\StatementContainerInterface;
use Zend\Db\Sql\ExpressionInterface;
use Zend\Db\Sql\Platform\PlatformDecoratorInterface;
use Zend\Db\Sql\Select;

class SelectDecorator extends Select implements PlatformDecoratorInterface {

  /**
   * @var Select
   */
  protected $select = NULL;

  /**
   * @param Select $select
   */
  public function setSubject($select) {
    $this->select = $select;
  }

  /**
   * @see \Zend\Db\Sql\Select::renderTable
   */
  protected function renderTable($table, $alias = NULL) {
    return $table . ' ' . $alias;
  }

  /**
   * @param AdapterInterface $adapter
   * @param StatementContainerInterface $statementContainer
   */
  public function prepareStatement(AdapterInterface $adapter, StatementContainerInterface $statementContainer) {
    // localize variables
    foreach (get_object_vars($this->select) as $name => $value) {
      $this->{$name} = $value;
    }
    // set specifications
    unset($this->specifications[self::LIMIT]);
    unset($this->specifications[self::OFFSET]);

    $this->specifications['LIMITOFFSET'] = NULL;
    parent::prepareStatement($adapter, $statementContainer);
  }

  /**
   * @param PlatformInterface $platform
   *
   * @return string
   */
  public function getSqlString(PlatformInterface $platform = NULL) {
    // localize variables
    foreach (get_object_vars($this->select) as $name => $value) {
      $this->{$name} = $value;
    }

    // set specifications
    unset($this->specifications[self::LIMIT]);
    unset($this->specifications[self::OFFSET]);

    $this->specifications['LIMITOFFSET'] = NULL;
    return parent::getSqlString($platform);
  }

  /**
   * @param PlatformInterface $platform
   * @param DriverInterface $driver
   * @param ParameterContainer $parameterContainer
   * @param $sqls
   * @param $parameters
   *
   * @return null
   */
  protected function processLimitOffset(PlatformInterface $platform, DriverInterface $driver = NULL, ParameterContainer $parameterContainer = NULL, &$sqls, &$parameters) {
    if ($this->limit === NULL && $this->offset === NULL) {
      return NULL;
    }

    $selectParameters = $parameters[self::SELECT];

    $starSuffix = $platform->getIdentifierSeparator() . self::SQL_STAR;
    foreach ($selectParameters[0] as $i => $columnParameters) {
      if ($columnParameters[0] == self::SQL_STAR || (isset($columnParameters[1]) && $columnParameters[1] == self::SQL_STAR) || strpos($columnParameters[0], $starSuffix)) {
        $selectParameters[0] = array(array(self::SQL_STAR));
        break;
      }
      if (isset($columnParameters[1])) {
        array_shift($columnParameters);
        $selectParameters[0][$i] = $columnParameters;
      }
    }

    if ($this->offset === NULL) {
      $this->offset = 0;
    }

    // first, produce column list without compound names (using the AS portion only)
    array_unshift($sqls, $this->createSqlFromSpecificationAndParameters(
      array('SELECT %1$s FROM (SELECT b.%1$s, rownum b_rownum FROM (' => current($this->specifications[self::SELECT])), $selectParameters
    ));

    if ($parameterContainer) {
      if ($this->limit === NULL) {
        array_push($sqls, ') b ) WHERE b_rownum > (:offset)');
        $parameterContainer->offsetSet('offset', $this->offset, $parameterContainer::TYPE_INTEGER);
      }
      else {
        // create bottom part of query, with offset and limit using row_number
        array_push($sqls, ') b WHERE rownum <= (:offset+:limit)) WHERE b_rownum >= (:offset + 1)');
        $parameterContainer->offsetSet('offset', $this->offset, $parameterContainer::TYPE_INTEGER);
        $parameterContainer->offsetSet('limit', $this->limit, $parameterContainer::TYPE_INTEGER);
      }
    }
    else {
      if ($this->limit === NULL) {
        array_push($sqls, ') b ) WHERE b_rownum > (' . (int) $this->offset . ')'
        );
      }
      else {
        array_push($sqls, ') b WHERE rownum <= ('
          . (int) $this->offset
          . '+'
          . (int) $this->limit
          . ')) WHERE b_rownum >= ('
          . (int) $this->offset
          . ' + 1)'
        );
      }
    }

    $sqls[self::SELECT] = $this->createSqlFromSpecificationAndParameters(
      $this->specifications[self::SELECT], $parameters[self::SELECT]
    );
  }


  protected function processJoins(PlatformInterface $platform, DriverInterface $driver = NULL, ParameterContainer $parameterContainer = NULL) {
    if (!$this->joins) {
      return NULL;
    }

    // process joins
    $joinSpecArgArray = array();
    foreach ($this->joins as $j => $join) {
      $joinSpecArgArray[$j] = array();
      // type
      $joinSpecArgArray[$j][] = strtoupper($join['type']);
      // table name
      $joinSpecArgArray[$j][] = (is_array($join['name']))
        ? $platform->quoteIdentifier(current($join['name'])) . ' ' . $platform->quoteIdentifier(key($join['name']))
        : $platform->quoteIdentifier($join['name']);
      // on expression
      $joinSpecArgArray[$j][] = ($join['on'] instanceof ExpressionInterface)
        ? $this->processExpression($join['on'], $platform, $driver, $this->processInfo['paramPrefix'] . 'join')
        : $platform->quoteIdentifierInFragment($join['on'], array(
          '=',
          'AND',
          'OR',
          '(',
          ')',
          'BETWEEN'
        )); // on
      if ($joinSpecArgArray[$j][2] instanceof StatementContainerInterface) {
        if ($parameterContainer) {
          $parameterContainer->merge($joinSpecArgArray[$j][2]->getParameterContainer());
        }
        $joinSpecArgArray[$j][2] = $joinSpecArgArray[$j][2]->getSql();
      }
    }

    return array($joinSpecArgArray);
  }

}
