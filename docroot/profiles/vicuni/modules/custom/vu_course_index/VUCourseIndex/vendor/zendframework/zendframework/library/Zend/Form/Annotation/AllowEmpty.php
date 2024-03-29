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

namespace Zend\Form\Annotation;

use Zend\Filter\Boolean as BooleanFilter;

/**
 * AllowEmpty annotation
 *
 * Presence of this annotation is a hint that the associated
 * \Zend\InputFilter\Input should enable the allowEmpty flag.
 *
 * @Annotation
 */
class AllowEmpty {
  /**
   * @var bool
   */
  protected $allowEmpty = TRUE;

  /**
   * Receive and process the contents of an annotation
   *
   * @param array $data
   */
  public function __construct(array $data) {
    if (!isset($data['value'])) {
      $data['value'] = FALSE;
    }

    $allowEmpty = $data['value'];

    if (!is_bool($allowEmpty)) {
      $filter = new BooleanFilter();
      $allowEmpty = $filter->filter($allowEmpty);
    }

    $this->allowEmpty = $allowEmpty;
  }

  /**
   * Get value of required flag
   *
   * @return bool
   */
  public function getAllowEmpty() {
    return $this->allowEmpty;
  }
}
