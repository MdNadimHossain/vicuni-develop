<?php

namespace Drupal\vu_rp_api\Logger;

/**
 * Class Logger.
 *
 * @package Drupal\vu_rp_api\Logger
 */
class Logger implements LoggerInterface {

  /**
   * Log messages.
   */
  public function log($event, $message, $severity = self::SEVERITY_INFO) {
    $hook = 'vu_rp_api_logger_log';

    module_invoke_all($hook, $event, $message, $severity);
  }

  /**
   * Severity map.
   */
  public static function severityMap($key = NULL) {
    $map = [
      self::SEVERITY_EMERGENCY => 'Emergency',
      self::SEVERITY_ALERT => 'Alert',
      self::SEVERITY_CRITICAL => 'Critical',
      self::SEVERITY_ERROR => 'Error',
      self::SEVERITY_WARNING => 'Warning',
      self::SEVERITY_NOTICE => 'Notice',
      self::SEVERITY_INFO => 'Info',
    ];

    return isset($map[$key]) ? $map[$key] : $map;
  }

}
