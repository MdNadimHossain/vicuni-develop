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

namespace Zend\Feed\PubSubHubbub\Model;

use Zend\Db\TableGateway\TableGateway;
use Zend\Db\TableGateway\TableGatewayInterface;

class AbstractModel {
  /**
   * Zend\Db\TableGateway\TableGatewayInterface instance to host database
   * methods
   *
   * @var TableGatewayInterface
   */
  protected $db = NULL;

  /**
   * Constructor
   *
   * @param null|TableGatewayInterface $tableGateway
   */
  public function __construct(TableGatewayInterface $tableGateway = NULL) {
    if ($tableGateway === NULL) {
      $parts = explode('\\', get_class($this));
      $table = strtolower(array_pop($parts));
      $this->db = new TableGateway($table, NULL);
    }
    else {
      $this->db = $tableGateway;
    }
  }
}
