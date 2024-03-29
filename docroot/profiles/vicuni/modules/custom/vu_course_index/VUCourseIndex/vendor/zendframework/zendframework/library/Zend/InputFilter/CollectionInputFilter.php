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

use Traversable;

class CollectionInputFilter extends InputFilter {
  /*
   * @var bool
   */
  protected $isRequired = FALSE;

  /*
   * @var int
   */
  protected $count = NULL;

  /*
   * @var array
   */
  protected $collectionValues = array();

  /*
   * @var array
   */
  protected $collectionRawValues = array();

  /*
   * @var array
   */
  protected $collectionMessages = array();

  /**
   * @var BaseInputFilter
   */
  protected $inputFilter;

  /**
   * Set the input filter to use when looping the data
   *
   * @param BaseInputFilter|array|Traversable $inputFilter
   *
   * @throws Exception\RuntimeException
   * @return CollectionInputFilter
   */
  public function setInputFilter($inputFilter) {
    if (is_array($inputFilter) || $inputFilter instanceof Traversable) {
      $inputFilter = $this->getFactory()->createInputFilter($inputFilter);
    }

    if (!$inputFilter instanceof BaseInputFilter) {
      throw new Exception\RuntimeException(sprintf(
        '%s expects an instance of %s; received "%s"',
        __METHOD__,
        'Zend\InputFilter\BaseInputFilter',
        (is_object($inputFilter) ? get_class($inputFilter) : gettype($inputFilter))
      ));
    }

    $this->inputFilter = $inputFilter;

    return $this;
  }

  /**
   * Get the input filter used when looping the data
   *
   * @return BaseInputFilter
   */
  public function getInputFilter() {
    if (NULL === $this->inputFilter) {
      $this->setInputFilter(new InputFilter());
    }

    return $this->inputFilter;
  }

  /**
   * Set if the collection can be empty
   *
   * @param bool $isRequired
   *
   * @return CollectionInputFilter
   */
  public function setIsRequired($isRequired) {
    $this->isRequired = $isRequired;

    return $this;
  }

  /**
   * Get if collection can be empty
   *
   * @return bool
   */
  public function getIsRequired() {
    return $this->isRequired;
  }

  /**
   * Set the count of data to validate
   *
   * @param int $count
   *
   * @return CollectionInputFilter
   */
  public function setCount($count) {
    $this->count = $count > 0 ? $count : 0;

    return $this;
  }

  /**
   * Get the count of data to validate, use the count of data by default
   *
   * @return int
   */
  public function getCount() {
    if (NULL === $this->count) {
      return count($this->data);
    }

    return $this->count;
  }

  /**
   * {@inheritdoc}
   */
  public function setData($data) {
    $this->data = $data;
  }

  /**
   * {@inheritdoc}
   */
  public function isValid() {
    $inputFilter = $this->getInputFilter();
    $valid = TRUE;

    if ($this->getCount() < 1) {
      if ($this->isRequired) {
        $valid = FALSE;
      }
    }

    if (is_scalar($this->data)
      || count($this->data) < $this->getCount()
    ) {
      $valid = FALSE;
    }

    if (empty($this->data) || is_scalar($this->data)) {
      $this->clearValues();
      $this->clearRawValues();

      return $valid;
    }

    foreach ($this->data as $key => $data) {
      if (!is_array($data)) {
        $data = array();
      }
      $inputFilter->setData($data);

      if (NULL !== $this->validationGroup) {
        $inputFilter->setValidationGroup($this->validationGroup[$key]);
      }

      if ($inputFilter->isValid()) {
        $this->validInputs[$key] = $inputFilter->getValidInput();
      }
      else {
        $valid = FALSE;
        $this->collectionMessages[$key] = $inputFilter->getMessages();
        $this->invalidInputs[$key] = $inputFilter->getInvalidInput();
      }

      $this->collectionValues[$key] = $inputFilter->getValues();
      $this->collectionRawValues[$key] = $inputFilter->getRawValues();
    }

    return $valid;
  }

  /**
   * {@inheritdoc}
   */
  public function setValidationGroup($name) {
    if ($name === self::VALIDATE_ALL) {
      $this->validationGroup = NULL;

      return $this;
    }

    $this->validationGroup = $name;

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getValues() {
    return $this->collectionValues;
  }

  /**
   * {@inheritdoc}
   */
  public function getRawValues() {
    return $this->collectionRawValues;
  }

  /**
   * Clear collectionValues
   *
   * @access public
   */
  public function clearValues() {
    return $this->collectionValues = array();
  }

  /**
   * Clear collectionRawValues
   *
   * @access public
   */
  public function clearRawValues() {
    return $this->collectionRawValues = array();
  }

  /**
   * {@inheritdoc}
   */
  public function getMessages() {
    return $this->collectionMessages;
  }
}
