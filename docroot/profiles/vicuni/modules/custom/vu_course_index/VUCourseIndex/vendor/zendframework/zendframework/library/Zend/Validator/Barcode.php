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

namespace Zend\Validator;

use Traversable;

class Barcode extends AbstractValidator {
  const INVALID = 'barcodeInvalid';
  const FAILED = 'barcodeFailed';
  const INVALID_CHARS = 'barcodeInvalidChars';
  const INVALID_LENGTH = 'barcodeInvalidLength';

  protected $messageTemplates = array(
    self::FAILED => "The input failed checksum validation",
    self::INVALID_CHARS => "The input contains invalid characters",
    self::INVALID_LENGTH => "The input should have a length of %length% characters",
    self::INVALID => "Invalid type given. String expected",
  );

  /**
   * Additional variables available for validation failure messages
   *
   * @var array
   */
  protected $messageVariables = array(
    'length' => array('options' => 'length'),
  );

  protected $options = array(
    'adapter' => NULL,
    // Barcode adapter Zend\Validator\Barcode\AbstractAdapter
    'options' => NULL,
    // Options for this adapter
    'length' => NULL,
    'useChecksum' => NULL,
  );

  /**
   * Constructor for barcodes
   *
   * @param array|string $options Options to use
   */
  public function __construct($options = NULL) {
    if (!is_array($options) && !($options instanceof Traversable)) {
      $options = array('adapter' => $options);
    }

    if (array_key_exists('options', $options)) {
      $options['options'] = array('options' => $options['options']);
    }

    parent::__construct($options);
  }

  /**
   * Returns the set adapter
   *
   * @return Barcode\AbstractAdapter
   */
  public function getAdapter() {
    if (!($this->options['adapter'] instanceof Barcode\AdapterInterface)) {
      $this->setAdapter('Ean13');
    }

    return $this->options['adapter'];
  }

  /**
   * Sets a new barcode adapter
   *
   * @param  string|Barcode\AbstractAdapter $adapter Barcode adapter to use
   * @param  array $options Options for this adapter
   *
   * @return Barcode
   * @throws Exception\InvalidArgumentException
   */
  public function setAdapter($adapter, $options = NULL) {
    if (is_string($adapter)) {
      $adapter = ucfirst(strtolower($adapter));
      $adapter = 'Zend\\Validator\\Barcode\\' . $adapter;

      if (!class_exists($adapter)) {
        throw new Exception\InvalidArgumentException('Barcode adapter matching "' . $adapter . '" not found');
      }

      $this->options['adapter'] = new $adapter($options);
    }

    if (!$this->options['adapter'] instanceof Barcode\AdapterInterface) {
      throw new Exception\InvalidArgumentException(
        "Adapter $adapter does not implement Zend\\Validate\\Barcode\\AdapterInterface"
      );
    }

    return $this;
  }

  /**
   * Returns the checksum option
   *
   * @return string
   */
  public function getChecksum() {
    return $this->getAdapter()->getChecksum();
  }

  /**
   * Sets if checksum should be validated, if no value is given the actual
   * setting is returned
   *
   * @param  bool $checksum
   *
   * @return bool
   */
  public function useChecksum($checksum = NULL) {
    return $this->getAdapter()->useChecksum($checksum);
  }

  /**
   * Defined by Zend\Validator\ValidatorInterface
   *
   * Returns true if and only if $value contains a valid barcode
   *
   * @param  string $value
   *
   * @return bool
   */
  public function isValid($value) {
    if (!is_string($value)) {
      $this->error(self::INVALID);
      return FALSE;
    }

    $this->setValue($value);
    $adapter = $this->getAdapter();
    $this->options['length'] = $adapter->getLength();
    $result = $adapter->hasValidLength($value);
    if (!$result) {
      if (is_array($this->options['length'])) {
        $temp = $this->options['length'];
        $this->options['length'] = "";
        foreach ($temp as $length) {
          $this->options['length'] .= "/";
          $this->options['length'] .= $length;
        }

        $this->options['length'] = substr($this->options['length'], 1);
      }

      $this->error(self::INVALID_LENGTH);
      return FALSE;
    }

    $result = $adapter->hasValidCharacters($value);
    if (!$result) {
      $this->error(self::INVALID_CHARS);
      return FALSE;
    }

    if ($this->useChecksum(NULL)) {
      $result = $adapter->hasValidChecksum($value);
      if (!$result) {
        $this->error(self::FAILED);
        return FALSE;
      }
    }

    return TRUE;
  }
}
