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

class FormInput extends AbstractHelper {
  /**
   * Attributes valid for the input tag
   *
   * @var array
   */
  protected $validTagAttributes = array(
    'name' => TRUE,
    'accept' => TRUE,
    'alt' => TRUE,
    'autocomplete' => TRUE,
    'autofocus' => TRUE,
    'checked' => TRUE,
    'dirname' => TRUE,
    'disabled' => TRUE,
    'form' => TRUE,
    'formaction' => TRUE,
    'formenctype' => TRUE,
    'formmethod' => TRUE,
    'formnovalidate' => TRUE,
    'formtarget' => TRUE,
    'height' => TRUE,
    'list' => TRUE,
    'max' => TRUE,
    'maxlength' => TRUE,
    'min' => TRUE,
    'multiple' => TRUE,
    'pattern' => TRUE,
    'placeholder' => TRUE,
    'readonly' => TRUE,
    'required' => TRUE,
    'size' => TRUE,
    'src' => TRUE,
    'step' => TRUE,
    'type' => TRUE,
    'value' => TRUE,
    'width' => TRUE,
  );

  /**
   * Valid values for the input type
   *
   * @var array
   */
  protected $validTypes = array(
    'text' => TRUE,
    'button' => TRUE,
    'checkbox' => TRUE,
    'file' => TRUE,
    'hidden' => TRUE,
    'image' => TRUE,
    'password' => TRUE,
    'radio' => TRUE,
    'reset' => TRUE,
    'select' => TRUE,
    'submit' => TRUE,
    'color' => TRUE,
    'date' => TRUE,
    'datetime' => TRUE,
    'datetime-local' => TRUE,
    'email' => TRUE,
    'month' => TRUE,
    'number' => TRUE,
    'range' => TRUE,
    'search' => TRUE,
    'tel' => TRUE,
    'time' => TRUE,
    'url' => TRUE,
    'week' => TRUE,
  );

  /**
   * Invoke helper as functor
   *
   * Proxies to {@link render()}.
   *
   * @param  ElementInterface|null $element
   *
   * @return string|FormInput
   */
  public function __invoke(ElementInterface $element = NULL) {
    if (!$element) {
      return $this;
    }

    return $this->render($element);
  }

  /**
   * Render a form <input> element from the provided $element
   *
   * @param  ElementInterface $element
   *
   * @throws Exception\DomainException
   * @return string
   */
  public function render(ElementInterface $element) {
    $name = $element->getName();
    if ($name === NULL || $name === '') {
      throw new Exception\DomainException(sprintf(
        '%s requires that the element has an assigned name; none discovered',
        __METHOD__
      ));
    }

    $attributes = $element->getAttributes();
    $attributes['name'] = $name;
    $attributes['type'] = $this->getType($element);
    $attributes['value'] = $element->getValue();

    return sprintf(
      '<input %s%s',
      $this->createAttributesString($attributes),
      $this->getInlineClosingBracket()
    );
  }

  /**
   * Determine input type to use
   *
   * @param  ElementInterface $element
   *
   * @return string
   */
  protected function getType(ElementInterface $element) {
    $type = $element->getAttribute('type');
    if (empty($type)) {
      return 'text';
    }

    $type = strtolower($type);
    if (!isset($this->validTypes[$type])) {
      return 'text';
    }

    return $type;
  }
}
