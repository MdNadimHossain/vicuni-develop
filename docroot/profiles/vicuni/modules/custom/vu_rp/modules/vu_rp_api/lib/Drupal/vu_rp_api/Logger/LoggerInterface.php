<?php

namespace Drupal\vu_rp_api\Logger;

/**
 * Interface LoggerInterface.
 *
 * @package Drupal\vu_rp_api\Logger
 */
interface LoggerInterface {

  const SEVERITY_EMERGENCY = 0;

  const SEVERITY_ALERT = 1;

  const SEVERITY_CRITICAL = 2;

  const SEVERITY_ERROR = 3;

  const SEVERITY_WARNING = 4;

  const SEVERITY_NOTICE = 5;

  const SEVERITY_INFO = 6;

  /**
   * Log an event.
   *
   * @param string $event
   *   Event that triggered this log. Could be an action prefixed with a
   *   module name.
   * @param mixed $message
   *   Message.
   * @param int $severity
   *   Message severity.
   */
  public function log($event, $message, $severity = self::SEVERITY_INFO);

}
