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

namespace Zend\Mvc\I18n;

use Zend\I18n\Translator\TranslatorInterface as I18nTranslatorInterface;

class DummyTranslator implements I18nTranslatorInterface {
  public function translate($message, $textDomain = 'default', $locale = NULL) {
    return $message;
  }

  public function translatePlural($singular, $plural, $number, $textDomain = 'default', $locale = NULL) {
    return ($number == 1 ? $singular : $plural);
  }
}
