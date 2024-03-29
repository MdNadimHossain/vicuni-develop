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

namespace Zend\Filter;

use Traversable;

class StringToUpper extends AbstractUnicode {
  /**
   * @var array
   */
  protected $options = array(
    'encoding' => NULL,
  );

  /**
   * Constructor
   *
   * @param string|array|Traversable $encodingOrOptions OPTIONAL
   */
  public function __construct($encodingOrOptions = NULL) {
    if ($encodingOrOptions !== NULL) {
      if (!static::isOptions($encodingOrOptions)) {
        $this->setEncoding($encodingOrOptions);
      }
      else {
        $this->setOptions($encodingOrOptions);
      }
    }
  }

  /**
   * Defined by Zend\Filter\FilterInterface
   *
   * Returns the string $value, converting characters to uppercase as necessary
   *
   * If the value provided is non-scalar, the value will remain unfiltered
   *
   * @param  string $value
   *
   * @return string|mixed
   */
  public function filter($value) {
    if (!is_scalar($value)) {
      return $value;
    }
    $value = (string) $value;

    if ($this->options['encoding'] !== NULL) {
      return mb_strtoupper($value, $this->options['encoding']);
    }

    return strtoupper($value);
  }
}
