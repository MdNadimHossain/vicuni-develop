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

namespace Zend\Form\Element;

use Zend\Form\Element;
use Zend\InputFilter\InputProviderInterface;
use Zend\Validator\Uri as UriValidator;

class Url extends Element implements InputProviderInterface {
  /**
   * Seed attributes
   *
   * @var array
   */
  protected $attributes = array(
    'type' => 'url',
  );

  /**
   * @var \Zend\Validator\ValidatorInterface
   */
  protected $validator;

  /**
   * Get validator
   *
   * @return \Zend\Validator\ValidatorInterface
   */
  public function getValidator() {
    if (NULL === $this->validator) {
      $this->validator = new UriValidator(array(
        'allowAbsolute' => TRUE,
        'allowRelative' => FALSE,
      ));
    }
    return $this->validator;
  }

  /**
   * Provide default input rules for this element
   *
   * Attaches an email validator.
   *
   * @return array
   */
  public function getInputSpecification() {
    return array(
      'name' => $this->getName(),
      'required' => TRUE,
      'filters' => array(
        array('name' => 'Zend\Filter\StringTrim'),
      ),
      'validators' => array(
        $this->getValidator(),
      ),
    );
  }
}
