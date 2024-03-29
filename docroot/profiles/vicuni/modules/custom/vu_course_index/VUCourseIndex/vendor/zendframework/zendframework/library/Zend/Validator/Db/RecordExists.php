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

namespace Zend\Validator\Db;

use Zend\Validator\Exception;

/**
 * Confirms a record exists in a table.
 */
class RecordExists extends AbstractDb {
  public function isValid($value) {
    /*
     * Check for an adapter being defined. If not, throw an exception.
     */
    if (NULL === $this->adapter) {
      throw new Exception\RuntimeException('No database adapter present');
    }

    $valid = TRUE;
    $this->setValue($value);

    $result = $this->query($value);
    if (!$result) {
      $valid = FALSE;
      $this->error(self::ERROR_NO_RECORD_FOUND);
    }

    return $valid;
  }
}
