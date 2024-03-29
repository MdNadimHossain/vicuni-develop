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
use Zend\Form\LabelAwareInterface;

class FormButton extends FormInput {
  /**
   * Attributes valid for the button tag
   *
   * @var array
   */
  protected $validTagAttributes = array(
    'name' => TRUE,
    'autofocus' => TRUE,
    'disabled' => TRUE,
    'form' => TRUE,
    'formaction' => TRUE,
    'formenctype' => TRUE,
    'formmethod' => TRUE,
    'formnovalidate' => TRUE,
    'formtarget' => TRUE,
    'type' => TRUE,
    'value' => TRUE,
  );

  /**
   * Valid values for the button type
   *
   * @var array
   */
  protected $validTypes = array(
    'button' => TRUE,
    'reset' => TRUE,
    'submit' => TRUE,
  );

  /**
   * Invoke helper as functor
   *
   * Proxies to {@link render()}.
   *
   * @param  ElementInterface|null $element
   * @param  null|string $buttonContent
   *
   * @return string|FormButton
   */
  public function __invoke(ElementInterface $element = NULL, $buttonContent = NULL) {
    if (!$element) {
      return $this;
    }

    return $this->render($element, $buttonContent);
  }

  /**
   * Render a form <button> element from the provided $element,
   * using content from $buttonContent or the element's "label" attribute
   *
   * @param  ElementInterface $element
   * @param  null|string $buttonContent
   *
   * @throws Exception\DomainException
   * @return string
   */
  public function render(ElementInterface $element, $buttonContent = NULL) {
    $openTag = $this->openTag($element);

    if (NULL === $buttonContent) {
      $buttonContent = $element->getLabel();
      if (NULL === $buttonContent) {
        throw new Exception\DomainException(sprintf(
          '%s expects either button content as the second argument, ' .
          'or that the element provided has a label value; neither found',
          __METHOD__
        ));
      }

      if (NULL !== ($translator = $this->getTranslator())) {
        $buttonContent = $translator->translate(
          $buttonContent, $this->getTranslatorTextDomain()
        );
      }
    }

    if (!$element instanceof LabelAwareInterface || !$element->getLabelOption('disable_html_escape')) {
      $escapeHtmlHelper = $this->getEscapeHtmlHelper();
      $buttonContent = $escapeHtmlHelper($buttonContent);
    }

    return $openTag . $buttonContent . $this->closeTag();
  }

  /**
   * Generate an opening button tag
   *
   * @param  null|array|ElementInterface $attributesOrElement
   *
   * @throws Exception\InvalidArgumentException
   * @throws Exception\DomainException
   * @return string
   */
  public function openTag($attributesOrElement = NULL) {
    if (NULL === $attributesOrElement) {
      return '<button>';
    }

    if (is_array($attributesOrElement)) {
      $attributes = $this->createAttributesString($attributesOrElement);
      return sprintf('<button %s>', $attributes);
    }

    if (!$attributesOrElement instanceof ElementInterface) {
      throw new Exception\InvalidArgumentException(sprintf(
        '%s expects an array or Zend\Form\ElementInterface instance; received "%s"',
        __METHOD__,
        (is_object($attributesOrElement) ? get_class($attributesOrElement) : gettype($attributesOrElement))
      ));
    }

    $element = $attributesOrElement;
    $name = $element->getName();
    if (empty($name) && $name !== 0) {
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
      '<button %s>',
      $this->createAttributesString($attributes)
    );
  }

  /**
   * Return a closing button tag
   *
   * @return string
   */
  public function closeTag() {
    return '</button>';
  }

  /**
   * Determine button type to use
   *
   * @param  ElementInterface $element
   *
   * @return string
   */
  protected function getType(ElementInterface $element) {
    $type = $element->getAttribute('type');
    if (empty($type)) {
      return 'submit';
    }

    $type = strtolower($type);
    if (!isset($this->validTypes[$type])) {
      return 'submit';
    }

    return $type;
  }
}
