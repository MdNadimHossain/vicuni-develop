<?php

namespace Drupal\vu_rp_api;

/**
 * Class Utilities.
 *
 * @package Drupal\vu_rp_api
 */
class Utilities {

  /**
   * Convert string to camelcase.
   */
  public static function toCamelCase($string, $ucfirst = FALSE) {
    $parts = explode('_', $string);
    $parts = $parts ? array_map('ucfirst', $parts) : [$string];
    $parts[0] = $ucfirst ? ucfirst($parts[0]) : lcfirst($parts[0]);

    return implode('', $parts);
  }

}
