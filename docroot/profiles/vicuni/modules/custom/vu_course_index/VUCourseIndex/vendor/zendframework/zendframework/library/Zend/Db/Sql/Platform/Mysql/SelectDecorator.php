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

namespace Zend\Db\Sql\Platform\Mysql;

use Zend\Db\Adapter\AdapterInterface;
use Zend\Db\Adapter\Driver\DriverInterface;
use Zend\Db\Adapter\ParameterContainer;
use Zend\Db\Adapter\Platform\PlatformInterface;
use Zend\Db\Adapter\StatementContainerInterface;
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
   * @param AdapterInterface $adapter
   * @param StatementContainerInterface $statementContainer
   */
  public function prepareStatement(AdapterInterface $adapter, StatementContainerInterface $statementContainer) {
    // localize variables
    foreach (get_object_vars($this->select) as $name => $value) {
      $this->{$name} = $value;
    }
    if ($this->limit === NULL && $this->offset !== NULL) {
      $this->specifications[self::LIMIT] = 'LIMIT 18446744073709551615';
    }
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
    if ($this->limit === NULL && $this->offset !== NULL) {
      $this->specifications[self::LIMIT] = 'LIMIT 18446744073709551615';
    }
    return parent::getSqlString($platform);
  }

  protected function processLimit(PlatformInterface $platform, DriverInterface $driver = NULL, ParameterContainer $parameterContainer = NULL) {
    if ($this->limit === NULL && $this->offset !== NULL) {
      return array('');
    }
    if ($this->limit === NULL) {
      return NULL;
    }
    if ($driver) {
      $sql = $driver->formatParameterName('limit');
      $parameterContainer->offsetSet('limit', $this->limit, ParameterContainer::TYPE_INTEGER);
    }
    else {
      $sql = $this->limit;
    }

    return array($sql);
  }

  protected function processOffset(PlatformInterface $platform, DriverInterface $driver = NULL, ParameterContainer $parameterContainer = NULL) {
    if ($this->offset === NULL) {
      return NULL;
    }
    if ($driver) {
      $parameterContainer->offsetSet('offset', $this->offset, ParameterContainer::TYPE_INTEGER);
      return array($driver->formatParameterName('offset'));
    }

    return array($this->offset);
  }
}
