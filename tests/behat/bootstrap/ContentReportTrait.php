<?php

/**
 * @file
 * Content report trait.
 */

use Behat\Behat\Hook\Scope\AfterStepScope;

/**
 * Class ContentReportTrait.
 */
trait ContentReportTrait {

  /**
   * After scope event handler to save screenshot on page load for reports.
   *
   * @AfterStep
   */
  public function reportPageLoadScreenshot(AfterStepScope $event) {
    $content_url = getenv('BEHAT_CONTENT_URL');
    if (!empty($content_url)) {
      static $url;
      if ($url !== $this->getSession()->getCurrentUrl()) {
        $url = $this->getSession()->getCurrentUrl();
        if (!in_array($url, ['about:blank', 'data:,'])) {
          // @migration: Replace this with proper screenshot method.
          // @code
          // $this->saveDebugScreenshot();
          // @endcode
        }
      }
    }
  }

}
