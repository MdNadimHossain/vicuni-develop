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

namespace Zend\Db\Adapter;

trait AdapterAwareTrait {
  /**
   * @var Adapter
   */
  protected $adapter = NULL;

  /**
   * Set db adapter
   *
   * @param Adapter $adapter
   *
   * @return mixed
   */
  public function setDbAdapter(Adapter $adapter) {
    $this->adapter = $adapter;

    return $this;
  }
}
