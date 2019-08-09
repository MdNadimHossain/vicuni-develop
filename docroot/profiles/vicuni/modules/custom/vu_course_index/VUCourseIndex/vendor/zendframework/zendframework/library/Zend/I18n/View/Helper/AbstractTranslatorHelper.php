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

namespace Zend\I18n\View\Helper;

use Zend\I18n\Translator\TranslatorInterface as Translator;
use Zend\I18n\Translator\TranslatorAwareInterface;
use Zend\View\Helper\AbstractHelper;

abstract class AbstractTranslatorHelper extends AbstractHelper implements
  TranslatorAwareInterface {
  /**
   * Translator (optional)
   *
   * @var Translator
   */
  protected $translator;

  /**
   * Translator text domain (optional)
   *
   * @var string
   */
  protected $translatorTextDomain = 'default';

  /**
   * Whether translator should be used
   *
   * @var bool
   */
  protected $translatorEnabled = TRUE;

  /**
   * Sets translator to use in helper
   *
   * @param  Translator $translator [optional] translator.
   *                                 Default is null, which sets no translator.
   * @param  string $textDomain [optional] text domain
   *                                 Default is null, which skips
   *   setTranslatorTextDomain
   *
   * @return AbstractTranslatorHelper
   */
  public function setTranslator(Translator $translator = NULL, $textDomain = NULL) {
    $this->translator = $translator;
    if (NULL !== $textDomain) {
      $this->setTranslatorTextDomain($textDomain);
    }

    return $this;
  }

  /**
   * Returns translator used in helper
   *
   * @return Translator|null
   */
  public function getTranslator() {
    if (!$this->isTranslatorEnabled()) {
      return NULL;
    }

    return $this->translator;
  }

  /**
   * Checks if the helper has a translator
   *
   * @return bool
   */
  public function hasTranslator() {
    return (bool) $this->getTranslator();
  }

  /**
   * Sets whether translator is enabled and should be used
   *
   * @param  bool $enabled
   *
   * @return AbstractTranslatorHelper
   */
  public function setTranslatorEnabled($enabled = TRUE) {
    $this->translatorEnabled = (bool) $enabled;
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
   * @param  string $textDomain
   *
   * @return AbstractTranslatorHelper
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
