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

namespace Zend\I18n\Translator;

trait TranslatorAwareTrait {
  /**
   * @var TranslatorInterface
   */
  protected $translator = NULL;

  /**
   * @var bool
   */
  protected $translatorEnabled = TRUE;

  /**
   * @var string
   */
  protected $translatorTextDomain = 'default';

  /**
   * Sets translator to use in helper
   *
   * @param TranslatorInterface $translator
   * @param string $textDomain
   *
   * @return mixed
   */
  public function setTranslator(TranslatorInterface $translator = NULL, $textDomain = NULL) {
    $this->translator = $translator;

    if (NULL !== $textDomain) {
      $this->setTranslatorTextDomain($textDomain);
    }

    return $this;
  }

  /**
   * Returns translator used in object
   *
   * @return TranslatorInterface
   */
  public function getTranslator() {
    return $this->translator;
  }

  /**
   * Checks if the object has a translator
   *
   * @return bool
   */
  public function hasTranslator() {
    return (NULL !== $this->translator);
  }

  /**
   * Sets whether translator is enabled and should be used
   *
   * @param bool $enabled
   *
   * @return mixed
   */
  public function setTranslatorEnabled($enabled = TRUE) {
    $this->translatorEnabled = $enabled;

    return $this;
  }

  /**
   * Returns whether translator is enabled and should be used
   *
   * @return bool
   */
  public function isTranslatorEnabled() {
    return $this->translatorEnabled;
  }

  /**
   * Set translation text domain
   *
   * @param string $textDomain
   *
   * @return mixed
   */
  public function setTranslatorTextDomain($textDomain = 'default') {
    $this->translatorTextDomain = $textDomain;

    return $this;
  }

  /**
   * Return the translation text domain
   *
   * @return string
   */
  public function getTranslatorTextDomain() {
    return $this->translatorTextDomain;
  }
}
