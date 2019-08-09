<?php

/**
 * @file
 * Generic helpers and formatters.
 */

/**
 * Format phone number.
 */
function vu_core_format_phone($value) {
  if (empty($value)) {
    return $value;
  }

  $value = preg_replace('/[^0-9]+/i', '', $value);
  $value = strpos($value, '61') === 0 ? substr($value, 2) : $value;
  $value = strpos($value, '04') === 0 ? substr($value, 1) : $value;
  $value = strlen($value) == 8 ? '+613' . $value : '+61' . $value;

  $value = format_phone_number('au', $value, []);

  $value = preg_replace('/[\(\)]+/i', '', $value);

  return $value;
}

/**
 * Helper to add possession to a noun.
 */
function vu_core_format_possession($string) {
  return $string . "'" . ($string[strlen($string) - 1] != 's' ? 's' : '');
}

/**
 * Helper to format currency.
 */
function vu_core_format_currency($number, $fractional = FALSE) {
  if ($fractional) {
    $number = sprintf('%.2f', $number);
  }

  while (TRUE) {
    $replaced = preg_replace('/(-?\d+)(\d\d\d)/', '$1,$2', $number);
    if ($replaced != $number) {
      $number = $replaced;
    }
    else {
      break;
    }
  }

  return $number;
}
