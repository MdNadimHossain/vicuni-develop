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

use Zend\I18n\Exception;

/**
 * View helper for translating messages.
 */
class Translate extends AbstractTranslatorHelper {
  /**
   * Translate a message
   *
   * @param  string $message
   * @param  string $textDomain
   * @param  string $locale
   *
   * @throws Exception\RuntimeException
   * @return string
   */
  public function __invoke($message, $textDomain = NULL, $locale = NULL) {
    $translator = $this->getTranslator();
    if (NULL === $translator) {
      throw new Exception\RuntimeException('Translator has not been set');
    }
    if (NULL === $textDomain) {
      $textDomain = $this->getTranslatorTextDomain();
    }

    return $translator->translate($message, $textDomain, $locale);
  }
}
