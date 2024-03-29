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

namespace Zend\Validator\Barcode;

class Upca extends AbstractAdapter {
  /**
   * Constructor for this barcode adapter
   */
  public function __construct() {
    $this->setLength(12);
    $this->setCharacters('0123456789');
    $this->setChecksum('gtin');
  }
}
