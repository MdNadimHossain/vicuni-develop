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

namespace Zend\Form\View\Helper;

use Zend\Form\ElementInterface;

class FormHidden extends FormInput {
  /**
   * Attributes valid for the input tag type="hidden"
   *
   * @var array
   */
  protected $validTagAttributes = array(
    'name' => TRUE,
    'disabled' => TRUE,
    'form' => TRUE,
    'type' => TRUE,
    'value' => TRUE,
  );

  /**
   * Determine input type to use
   *
   * @param  ElementInterface $element
   *
   * @return string
   */
  protected function getType(ElementInterface $element) {
    return 'hidden';
  }
}
