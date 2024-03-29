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

namespace Zend\Text\Figlet\Exception;

use Zend\Text\Exception;

/**
 * Exception class for Zend\Text
 */
class UnexpectedValueException
  extends Exception\UnexpectedValueException
  implements ExceptionInterface {
}
