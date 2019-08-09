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

class FormImage extends FormInput {
  /**
   * Attributes valid for the input tag type="image"
   *
   * @var array
   */
  protected $validTagAttributes = array(
    'name' => TRUE,
    'alt' => TRUE,
    'autofocus' => TRUE,
    'disabled' => TRUE,
    'form' => TRUE,
    'formaction' => TRUE,
    'formenctype' => TRUE,
    'formmethod' => TRUE,
    'formnovalidate' => TRUE,
    'formtarget' => TRUE,
    'height' => TRUE,
    'src' => TRUE,
    'type' => TRUE,
    'width' => TRUE,
  );

  /**
   * Render a form <input> element from the provided $element
   *
   * @param  ElementInterface $element
   *
   * @throws Exception\DomainException
   * @return string
   */
  public function render(ElementInterface $element) {
    $src = $element->getAttribute('src');
    if (empty($src)) {
      throw new Exception\DomainException(sprintf(
        '%s requires that the element has an assigned src; none discovered',
        __METHOD__
      ));
    }

    return parent::render($element);
  }

  /**
   * Determine input type to use
   *
   * @param  ElementInterface $element
   *
   * @return string
   */
  protected function getType(ElementInterface $element) {
    return 'image';
  }
}
