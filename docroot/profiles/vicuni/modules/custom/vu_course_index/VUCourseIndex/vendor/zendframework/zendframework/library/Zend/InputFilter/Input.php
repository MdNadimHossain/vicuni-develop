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

namespace Zend\InputFilter;

use Zend\Filter\FilterChain;
use Zend\Validator\NotEmpty;
use Zend\Validator\ValidatorChain;

class Input implements InputInterface, EmptyContextInterface {
  /**
   * @var bool
   */
  protected $allowEmpty = FALSE;

  /**
   * @var bool
   */
  protected $continueIfEmpty = FALSE;

  /**
   * @var bool
   */
  protected $breakOnFailure = FALSE;

  /**
   * @var string|null
   */
  protected $errorMessage;

  /**
   * @var FilterChain
   */
  protected $filterChain;

  /**
   * @var string
   */
  protected $name;

  /**
   * @var bool
   */
  protected $notEmptyValidator = FALSE;

  /**
   * @var bool
   */
  protected $required = TRUE;

  /**
   * @var ValidatorChain
   */
  protected $validatorChain;

  /**
   * @var mixed
   */
  protected $value;

  /**
   * @var mixed
   */
  protected $fallbackValue;

  /**
   * @var bool
   */
  protected $hasFallback = FALSE;

  public function __construct($name = NULL) {
    $this->name = $name;
  }

  /**
   * @param  bool $allowEmpty
   *
   * @return Input
   */
  public function setAllowEmpty($allowEmpty) {
    $this->allowEmpty = (bool) $allowEmpty;
    return $this;
  }

  /**
   * @param  bool $breakOnFailure
   *
   * @return Input
   */
  public function setBreakOnFailure($breakOnFailure) {
    $this->breakOnFailure = (bool) $breakOnFailure;
    return $this;
  }

  /**
   * @param bool $continueIfEmpty
   *
   * @return \Zend\InputFilter\Input
   */
  public function setContinueIfEmpty($continueIfEmpty) {
    $this->continueIfEmpty = (bool) $continueIfEmpty;
    return $this;
  }

  /**
   * @param  string|null $errorMessage
   *
   * @return Input
   */
  public function setErrorMessage($errorMessage) {
    $this->errorMessage = (NULL === $errorMessage) ? NULL : (string) $errorMessage;
    return $this;
  }

  /**
   * @param  FilterChain $filterChain
   *
   * @return Input
   */
  public function setFilterChain(FilterChain $filterChain) {
    $this->filterChain = $filterChain;
    return $this;
  }

  /**
   * @param  string $name
   *
   * @return Input
   */
  public function setName($name) {
    $this->name = (string) $name;
    return $this;
  }

  /**
   * @param  bool $required
   *
   * @return Input
   */
  public function setRequired($required) {
    $this->required = (bool) $required;
    $this->setAllowEmpty(!$required);
    return $this;
  }

  /**
   * @param  ValidatorChain $validatorChain
   *
   * @return Input
   */
  public function setValidatorChain(ValidatorChain $validatorChain) {
    $this->validatorChain = $validatorChain;
    return $this;
  }

  /**
   * @param  mixed $value
   *
   * @return Input
   */
  public function setValue($value) {
    $this->value = $value;
    return $this;
  }

  /**
   * @param  mixed $value
   *
   * @return Input
   */
  public function setFallbackValue($value) {
    $this->fallbackValue = $value;
    $this->hasFallback = TRUE;
    return $this;
  }

  /**
   * @return bool
   */
  public function allowEmpty() {
    return $this->allowEmpty;
  }

  /**
   * @return bool
   */
  public function breakOnFailure() {
    return $this->breakOnFailure;
  }

  /**
   * @return bool
   */
  public function continueIfEmpty() {
    return $this->continueIfEmpty;
  }

  /**
   * @return string|null
   */
  public function getErrorMessage() {
    return $this->errorMessage;
  }

  /**
   * @return FilterChain
   */
  public function getFilterChain() {
    if (!$this->filterChain) {
      $this->setFilterChain(new FilterChain());
    }
    return $this->filterChain;
  }

  /**
   * @return string
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @return mixed
   */
  public function getRawValue() {
    return $this->value;
  }

  /**
   * @return bool
   */
  public function isRequired() {
    return $this->required;
  }

  /**
   * @return ValidatorChain
   */
  public function getValidatorChain() {
    if (!$this->validatorChain) {
      $this->setValidatorChain(new ValidatorChain());
    }
    return $this->validatorChain;
  }

  /**
   * @return mixed
   */
  public function getValue() {
    $filter = $this->getFilterChain();
    return $filter->filter($this->value);
  }

  /**
   * @return mixed
   */
  public function getFallbackValue() {
    return $this->fallbackValue;
  }

  /**
   * @return bool
   */
  public function hasFallback() {
    return $this->hasFallback;
  }

  public function clearFallbackValue() {
    $this->hasFallback = FALSE;
    $this->fallbackValue = NULL;
  }

  /**
   * @param  InputInterface $input
   *
   * @return Input
   */
  public function merge(InputInterface $input) {
    $this->setBreakOnFailure($input->breakOnFailure());
    $this->setContinueIfEmpty($input->continueIfEmpty());
    $this->setErrorMessage($input->getErrorMessage());
    $this->setName($input->getName());
    $this->setRequired($input->isRequired());
    $this->setAllowEmpty($input->allowEmpty());
    $this->setValue($input->getRawValue());

    $filterChain = $input->getFilterChain();
    $this->getFilterChain()->merge($filterChain);

    $validatorChain = $input->getValidatorChain();
    $this->getValidatorChain()->merge($validatorChain);
    return $this;
  }

  /**
   * @param  mixed $context Extra "context" to provide the validator
   *
   * @return bool
   */
  public function isValid($context = NULL) {
    // Empty value needs further validation if continueIfEmpty is set
    // so don't inject NotEmpty validator which would always
    // mark that as false
    if (!$this->continueIfEmpty()) {
      $this->injectNotEmptyValidator();
    }
    $validator = $this->getValidatorChain();
    $value = $this->getValue();
    $result = $validator->isValid($value, $context);
    if (!$result && $this->hasFallback()) {
      $this->setValue($this->getFallbackValue());
      $result = TRUE;
    }

    return $result;
  }

  /**
   * @return array
   */
  public function getMessages() {
    if (NULL !== $this->errorMessage) {
      return (array) $this->errorMessage;
    }

    if ($this->hasFallback()) {
      return array();
    }

    $validator = $this->getValidatorChain();
    return $validator->getMessages();
  }

  /**
   * @return void
   */
  protected function injectNotEmptyValidator() {
    if ((!$this->isRequired() && $this->allowEmpty()) || $this->notEmptyValidator) {
      return;
    }
    $chain = $this->getValidatorChain();

    // Check if NotEmpty validator is already in chain
    $validators = $chain->getValidators();
    foreach ($validators as $validator) {
      if ($validator['instance'] instanceof NotEmpty) {
        $this->notEmptyValidator = TRUE;
        return;
      }
    }

    $chain->prependByName('NotEmpty', array(), TRUE);
    $this->notEmptyValidator = TRUE;
  }
}
