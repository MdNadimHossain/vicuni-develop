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
use Zend\Form\Exception;

class FormReset extends FormInput {
  /**
   * Attributes valid for the input tag type="reset"
   *
   * @var array
   */
  protected $validTagAttributes = array(
    'name' => TRUE,
    'autofocus' => TRUE,
    'disabled' => TRUE,
    'form' => TRUE,
    'type' => TRUE,
    'value' => TRUE,
  );

  /**
   * Translatable attributes
   *
   * @var array
   */
  protected $translatableAttributes = array(
    'value' => TRUE
  );

  /**
   * Determine input type to use
   *
   * @param  ElementInterface $element
   *
   * @throws Exception\DomainException
   * @return string
   */
  protected function getType(ElementInterface $element) {
    return 'reset';
  }
}
