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

namespace Zend\Console\Prompt;

class Number extends Line {
  /**
   * @var string
   */
  protected $promptText = 'Please enter a number: ';

  /**
   * @var bool
   */
  protected $allowFloat = FALSE;

  /**
   * @var int
   */
  protected $min;

  /**
   * @var int
   */
  protected $max;

  /**
   * Ask the user for a number.
   *
   * @param string $promptText The prompt text to display in console
   * @param bool $allowEmpty Is empty response allowed?
   * @param bool $allowFloat Are floating (non-decimal) numbers allowed?
   * @param int $min Minimum value (inclusive)
   * @param int $max Maximum value (inclusive)
   */
  public function __construct(
    $promptText = 'Please enter a number: ',
    $allowEmpty = FALSE,
    $allowFloat = FALSE,
    $min = NULL,
    $max = NULL
  ) {
    if ($promptText !== NULL) {
      $this->setPromptText($promptText);
    }

    if ($allowEmpty !== NULL) {
      $this->setAllowEmpty($allowEmpty);
    }

    if ($min !== NULL) {
      $this->setMin($min);
    }

    if ($max !== NULL) {
      $this->setMax($max);
    }

    if ($allowFloat !== NULL) {
      $this->setAllowFloat($allowFloat);
    }
  }

  /**
   * Show the prompt to user and return the answer.
   *
   * @return mixed
   */
  public function show() {
    /**
     * Ask for a number and validate it.
     */
    do {
      $valid = TRUE;
      $number = parent::show();
      if ($number === "" && !$this->allowEmpty) {
        $valid = FALSE;
      }
      elseif ($number === "") {
        $number = NULL;
      }
      elseif (!is_numeric($number)) {
        $this->getConsole()->writeLine("$number is not a number\n");
        $valid = FALSE;
      }
      elseif (!$this->allowFloat && (round($number) != $number)) {
        $this->getConsole()
          ->writeLine("Please enter a non-floating number, i.e. " . round($number) . "\n");
        $valid = FALSE;
      }
      elseif ($this->max !== NULL && $number > $this->max) {
        $this->getConsole()
          ->writeLine("Please enter a number not greater than " . $this->max . "\n");
        $valid = FALSE;
      }
      elseif ($this->min !== NULL && $number < $this->min) {
        $this->getConsole()
          ->writeLine("Please enter a number not smaller than " . $this->min . "\n");
        $valid = FALSE;
      }
    } while (!$valid);

    /**
     * Cast proper type
     */
    if ($number !== NULL) {
      $number = $this->allowFloat ? (double) $number : (int) $number;
    }

    return $this->lastResponse = $number;
  }

  /**
   * @param  bool $allowEmpty
   */
  public function setAllowEmpty($allowEmpty) {
    $this->allowEmpty = $allowEmpty;
  }

  /**
   * @return bool
   */
  public function getAllowEmpty() {
    return $this->allowEmpty;
  }

  /**
   * @param int $maxLength
   */
  public function setMaxLength($maxLength) {
    $this->maxLength = $maxLength;
  }

  /**
   * @return int
   */
  public function getMaxLength() {
    return $this->maxLength;
  }

  /**
   * @param string $promptText
   */
  public function setPromptText($promptText) {
    $this->promptText = $promptText;
  }

  /**
   * @return string
   */
  public function getPromptText() {
    return $this->promptText;
  }

  /**
   * @param int $max
   */
  public function setMax($max) {
    $this->max = $max;
  }

  /**
   * @return int
   */
  public function getMax() {
    return $this->max;
  }

  /**
   * @param int $min
   */
  public function setMin($min) {
    $this->min = $min;
  }

  /**
   * @return int
   */
  public function getMin() {
    return $this->min;
  }

  /**
   * @param  bool $allowFloat
   */
  public function setAllowFloat($allowFloat) {
    $this->allowFloat = $allowFloat;
  }

  /**
   * @return bool
   */
  public function getAllowFloat() {
    return $this->allowFloat;
  }
}
