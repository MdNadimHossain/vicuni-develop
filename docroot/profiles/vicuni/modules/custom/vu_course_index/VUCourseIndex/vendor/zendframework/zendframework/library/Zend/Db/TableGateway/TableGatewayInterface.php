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

namespace Zend\Db\TableGateway;

interface TableGatewayInterface {
  public function getTable();

  public function select($where = NULL);

  public function insert($set);

  public function update($set, $where = NULL);

  public function delete($where);
}
