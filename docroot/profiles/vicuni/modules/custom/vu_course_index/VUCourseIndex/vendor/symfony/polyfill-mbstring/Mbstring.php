<?php

/*
 * This file is part of the Symfony package.
 *
 * (c) Fabien Potencier <fabien@symfony.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Symfony\Polyfill\Mbstring;

/**
 * Partial mbstring implementation in PHP, iconv based, UTF-8 centric.
 *
 * Implemented:
 * - mb_convert_encoding     - Convert character encoding
 * - mb_convert_variables    - Convert character code in variable(s)
 * - mb_decode_mimeheader    - Decode string in MIME header field
 * - mb_encode_mimeheader    - Encode string for MIME header XXX NATIVE
 * IMPLEMENTATION IS REALLY BUGGED
 * - mb_convert_case         - Perform case folding on a string
 * - mb_get_info             - Get internal settings of mbstring
 * - mb_http_input           - Detect HTTP input character encoding
 * - mb_http_output          - Set/Get HTTP output character encoding
 * - mb_internal_encoding    - Set/Get internal character encoding
 * - mb_list_encodings       - Returns an array of all supported encodings
 * - mb_output_handler       - Callback function converts character encoding in
 * output buffer
 * - mb_strlen               - Get string length
 * - mb_strpos               - Find position of first occurrence of string in a
 * string
 * - mb_strrpos              - Find position of last occurrence of a string in
 * a string
 * - mb_strtolower           - Make a string lowercase
 * - mb_strtoupper           - Make a string uppercase
 * - mb_substitute_character - Set/Get substitution character
 * - mb_substr               - Get part of string
 * - mb_stripos              - Finds position of first occurrence of a string
 * within another, case insensitive
 * - mb_stristr              - Finds first occurrence of a string within
 * another, case insensitive
 * - mb_strrchr              - Finds the last occurrence of a character in a
 * string within another
 * - mb_strrichr             - Finds the last occurrence of a character in a
 * string within another, case insensitive
 * - mb_strripos             - Finds position of last occurrence of a string
 * within another, case insensitive
 * - mb_strstr               - Finds first occurrence of a string within
 * anothers
 * - mb_strwidth             - Return width of string
 * - mb_substr_count         - Count the number of substring occurrences
 *
 * Not implemented:
 * - mb_convert_kana         - Convert "kana" one from another ("zen-kaku",
 * "han-kaku" and more)
 * - mb_decode_numericentity - Decode HTML numeric string reference to
 * character
 * - mb_encode_numericentity - Encode character to HTML numeric string
 * reference
 * - mb_ereg_*               - Regular expression with multibyte support
 * - mb_parse_str            - Parse GET/POST/COOKIE data and set global
 * variable
 * - mb_preferred_mime_name  - Get MIME charset string
 * - mb_regex_encoding       - Returns current encoding for multibyte regex as
 * string
 * - mb_regex_set_options    - Set/Get the default options for mbregex
 * functions
 * - mb_send_mail            - Send encoded mail
 * - mb_split                - Split multibyte string using regular expression
 * - mb_strcut               - Get part of string
 * - mb_strimwidth           - Get truncated string with specified width
 *
 * @author Nicolas Grekas <p@tchwork.com>
 *
 * @internal
 */
final class Mbstring {
  const MB_CASE_FOLD = PHP_INT_MAX;

  private static $encodingList = array('ASCII', 'UTF-8');
  private static $language = 'neutral';
  private static $internalEncoding = 'UTF-8';
  private static $caseFold = array(
    array(
      'µ',
      'ſ',
      "\xCD\x85",
      'ς',
      "\xCF\x90",
      "\xCF\x91",
      "\xCF\x95",
      "\xCF\x96",
      "\xCF\xB0",
      "\xCF\xB1",
      "\xCF\xB5",
      "\xE1\xBA\x9B",
      "\xE1\xBE\xBE"
    ),
    array(
      'μ',
      's',
      'ι',
      'σ',
      'β',
      'θ',
      'φ',
      'π',
      'κ',
      'ρ',
      'ε',
      "\xE1\xB9\xA1",
      'ι'
    ),
  );

  public static function mb_convert_encoding($s, $toEncoding, $fromEncoding = NULL) {
    if (is_array($fromEncoding) || FALSE !== strpos($fromEncoding, ',')) {
      $fromEncoding = self::mb_detect_encoding($s, $fromEncoding);
    }
    else {
      $fromEncoding = self::getEncoding($fromEncoding);
    }

    $toEncoding = self::getEncoding($toEncoding);

    if ('BASE64' === $fromEncoding) {
      $s = base64_decode($s);
      $fromEncoding = $toEncoding;
    }

    if ('BASE64' === $toEncoding) {
      return base64_encode($s);
    }

    if ('HTML-ENTITIES' === $toEncoding || 'HTML' === $toEncoding) {
      if ('HTML-ENTITIES' === $fromEncoding || 'HTML' === $fromEncoding) {
        $fromEncoding = 'Windows-1252';
      }
      if ('UTF-8' !== $fromEncoding) {
        $s = iconv($fromEncoding, 'UTF-8', $s);
      }

      return preg_replace_callback('/[\x80-\xFF]+/', array(
        __CLASS__,
        'html_encoding_callback'
      ), $s);
    }

    if ('HTML-ENTITIES' === $fromEncoding) {
      $s = html_entity_decode($s, ENT_COMPAT, 'UTF-8');
      $fromEncoding = 'UTF-8';
    }

    return iconv($fromEncoding, $toEncoding, $s);
  }

  public static function mb_convert_variables($toEncoding, $fromEncoding, &$a = NULL, &$b = NULL, &$c = NULL, &$d = NULL, &$e = NULL, &$f = NULL) {
    $vars = array(&$a, &$b, &$c, &$d, &$e, &$f);

    $ok = TRUE;
    array_walk_recursive($vars, function (&$v) use (&$ok, $toEncoding, $fromEncoding) {
      if (FALSE === $v = Mbstring::mb_convert_encoding($v, $toEncoding, $fromEncoding)) {
        $ok = FALSE;
      }
    });

    return $ok ? $fromEncoding : FALSE;
  }

  public static function mb_decode_mimeheader($s) {
    return iconv_mime_decode($s, 2, self::$internalEncoding);
  }

  public static function mb_encode_mimeheader($s, $charset = NULL, $transferEncoding = NULL, $linefeed = NULL, $indent = NULL) {
    trigger_error('mb_encode_mimeheader() is bugged. Please use iconv_mime_encode() instead', E_USER_WARNING);
  }

  public static function mb_convert_case($s, $mode, $encoding = NULL) {
    if ('' === $s .= '') {
      return '';
    }

    $encoding = self::getEncoding($encoding);

    if ('UTF-8' === $encoding) {
      $encoding = NULL;
    }
    else {
      $s = iconv($encoding, 'UTF-8', $s);
    }

    if (MB_CASE_TITLE == $mode) {
      $s = preg_replace_callback('/\b\p{Ll}/u', array(
        __CLASS__,
        'title_case_upper'
      ), $s);
      $s = preg_replace_callback('/\B[\p{Lu}\p{Lt}]+/u', array(
        __CLASS__,
        'title_case_lower'
      ), $s);
    }
    else {
      if (MB_CASE_UPPER == $mode) {
        static $upper = NULL;
        if (NULL === $upper) {
          $upper = self::getData('upperCase');
        }
        $map = $upper;
      }
      else {
        if (self::MB_CASE_FOLD === $mode) {
          $s = str_replace(self::$caseFold[0], self::$caseFold[1], $s);
        }

        static $lower = NULL;
        if (NULL === $lower) {
          $lower = self::getData('lowerCase');
        }
        $map = $lower;
      }

      static $ulenMask = array(
        "\xC0" => 2,
        "\xD0" => 2,
        "\xE0" => 3,
        "\xF0" => 4
      );

      $i = 0;
      $len = strlen($s);

      while ($i < $len) {
        $ulen = $s[$i] < "\x80" ? 1 : $ulenMask[$s[$i] & "\xF0"];
        $uchr = substr($s, $i, $ulen);
        $i += $ulen;

        if (isset($map[$uchr])) {
          $uchr = $map[$uchr];
          $nlen = strlen($uchr);

          if ($nlen == $ulen) {
            $nlen = $i;
            do {
              $s[--$nlen] = $uchr[--$ulen];
            } while ($ulen);
          }
          else {
            $s = substr_replace($s, $uchr, $i - $ulen, $ulen);
            $len += $nlen - $ulen;
            $i += $nlen - $ulen;
          }
        }
      }
    }

    if (NULL === $encoding) {
      return $s;
    }

    return iconv('UTF-8', $encoding, $s);
  }

  public static function mb_internal_encoding($encoding = NULL) {
    if (NULL === $encoding) {
      return self::$internalEncoding;
    }

    $encoding = self::getEncoding($encoding);

    if ('UTF-8' === $encoding || FALSE !== @iconv($encoding, $encoding, ' ')) {
      self::$internalEncoding = $encoding;

      return TRUE;
    }

    return FALSE;
  }

  public static function mb_language($lang = NULL) {
    if (NULL === $lang) {
      return self::$language;
    }

    switch ($lang = strtolower($lang)) {
      case 'uni':
      case 'neutral':
        self::$language = $lang;

        return TRUE;
    }

    return FALSE;
  }

  public static function mb_list_encodings() {
    return array('UTF-8');
  }

  public static function mb_encoding_aliases($encoding) {
    switch (strtoupper($encoding)) {
      case 'UTF8':
      case 'UTF-8':
        return array('utf8');
    }

    return FALSE;
  }

  public static function mb_check_encoding($var = NULL, $encoding = NULL) {
    if (NULL === $encoding) {
      if (NULL === $var) {
        return FALSE;
      }
      $encoding = self::$internalEncoding;
    }

    return self::mb_detect_encoding($var, array($encoding)) || FALSE !== @iconv($encoding, $encoding, $var);
  }

  public static function mb_detect_encoding($str, $encodingList = NULL, $strict = FALSE) {
    if (NULL === $encodingList) {
      $encodingList = self::$encodingList;
    }
    else {
      if (!is_array($encodingList)) {
        $encodingList = array_map('trim', explode(',', $encodingList));
      }
      $encodingList = array_map('strtoupper', $encodingList);
    }

    foreach ($encodingList as $enc) {
      switch ($enc) {
        case 'ASCII':
          if (!preg_match('/[\x80-\xFF]/', $str)) {
            return $enc;
          }
          break;

        case 'UTF8':
        case 'UTF-8':
          if (preg_match('//u', $str)) {
            return 'UTF-8';
          }
          break;

        default:
          if (0 === strncmp($enc, 'ISO-8859-', 9)) {
            return $enc;
          }
      }
    }

    return FALSE;
  }

  public static function mb_detect_order($encodingList = NULL) {
    if (NULL === $encodingList) {
      return self::$encodingList;
    }

    if (!is_array($encodingList)) {
      $encodingList = array_map('trim', explode(',', $encodingList));
    }
    $encodingList = array_map('strtoupper', $encodingList);

    foreach ($encodingList as $enc) {
      switch ($enc) {
        default:
          if (strncmp($enc, 'ISO-8859-', 9)) {
            return FALSE;
          }
        case 'ASCII':
        case 'UTF8':
        case 'UTF-8':
      }
    }

    self::$encodingList = $encodingList;

    return TRUE;
  }

  public static function mb_strlen($s, $encoding = NULL) {
    $encoding = self::getEncoding($encoding);

    return iconv_strlen($s, $encoding);
  }

  public static function mb_strpos($haystack, $needle, $offset = 0, $encoding = NULL) {
    $encoding = self::getEncoding($encoding);

    if ('' === $needle .= '') {
      trigger_error(__METHOD__ . ': Empty delimiter', E_USER_WARNING);

      return FALSE;
    }

    return iconv_strpos($haystack, $needle, $offset, $encoding);
  }

  public static function mb_strrpos($haystack, $needle, $offset = 0, $encoding = NULL) {
    $encoding = self::getEncoding($encoding);

    if ($offset != (int) $offset) {
      $offset = 0;
    }
    elseif ($offset = (int) $offset) {
      if ($offset < 0) {
        $haystack = self::mb_substr($haystack, 0, $offset, $encoding);
        $offset = 0;
      }
      else {
        $haystack = self::mb_substr($haystack, $offset, 2147483647, $encoding);
      }
    }

    $pos = iconv_strrpos($haystack, $needle, $encoding);

    return FALSE !== $pos ? $offset + $pos : FALSE;
  }

  public static function mb_strtolower($s, $encoding = NULL) {
    return self::mb_convert_case($s, MB_CASE_LOWER, $encoding);
  }

  public static function mb_strtoupper($s, $encoding = NULL) {
    return self::mb_convert_case($s, MB_CASE_UPPER, $encoding);
  }

  public static function mb_substitute_character($c = NULL) {
    if (0 === strcasecmp($c, 'none')) {
      return TRUE;
    }

    return NULL !== $c ? FALSE : 'none';
  }

  public static function mb_substr($s, $start, $length = NULL, $encoding = NULL) {
    $encoding = self::getEncoding($encoding);

    if ($start < 0) {
      $start = iconv_strlen($s, $encoding) + $start;
      if ($start < 0) {
        $start = 0;
      }
    }

    if (NULL === $length) {
      $length = 2147483647;
    }
    elseif ($length < 0) {
      $length = iconv_strlen($s, $encoding) + $length - $start;
      if ($length < 0) {
        return '';
      }
    }

    return iconv_substr($s, $start, $length, $encoding) . '';
  }

  public static function mb_stripos($haystack, $needle, $offset = 0, $encoding = NULL) {
    $haystack = self::mb_convert_case($haystack, self::MB_CASE_FOLD, $encoding);
    $needle = self::mb_convert_case($needle, self::MB_CASE_FOLD, $encoding);

    return self::mb_strpos($haystack, $needle, $offset, $encoding);
  }

  public static function mb_stristr($haystack, $needle, $part = FALSE, $encoding = NULL) {
    $pos = self::mb_stripos($haystack, $needle, 0, $encoding);

    return self::getSubpart($pos, $part, $haystack, $encoding);
  }

  public static function mb_strrchr($haystack, $needle, $part = FALSE, $encoding = NULL) {
    $encoding = self::getEncoding($encoding);
    $needle = self::mb_substr($needle, 0, 1, $encoding);
    $pos = iconv_strrpos($haystack, $needle, $encoding);

    return self::getSubpart($pos, $part, $haystack, $encoding);
  }

  public static function mb_strrichr($haystack, $needle, $part = FALSE, $encoding = NULL) {
    $needle = self::mb_substr($needle, 0, 1, $encoding);
    $pos = self::mb_strripos($haystack, $needle, $encoding);

    return self::getSubpart($pos, $part, $haystack, $encoding);
  }

  public static function mb_strripos($haystack, $needle, $offset = 0, $encoding = NULL) {
    $haystack = self::mb_convert_case($haystack, self::MB_CASE_FOLD, $encoding);
    $needle = self::mb_convert_case($needle, self::MB_CASE_FOLD, $encoding);

    return self::mb_strrpos($haystack, $needle, $offset, $encoding);
  }

  public static function mb_strstr($haystack, $needle, $part = FALSE, $encoding = NULL) {
    $pos = strpos($haystack, $needle);
    if (FALSE === $pos) {
      return FALSE;
    }
    if ($part) {
      return substr($haystack, 0, $pos);
    }

    return substr($haystack, $pos);
  }

  public static function mb_get_info($type = 'all') {
    $info = array(
      'internal_encoding' => self::$internalEncoding,
      'http_output' => 'pass',
      'http_output_conv_mimetypes' => '^(text/|application/xhtml\+xml)',
      'func_overload' => 0,
      'func_overload_list' => 'no overload',
      'mail_charset' => 'UTF-8',
      'mail_header_encoding' => 'BASE64',
      'mail_body_encoding' => 'BASE64',
      'illegal_chars' => 0,
      'encoding_translation' => 'Off',
      'language' => self::$language,
      'detect_order' => self::$encodingList,
      'substitute_character' => 'none',
      'strict_detection' => 'Off',
    );

    if ('all' === $type) {
      return $info;
    }
    if (isset($info[$type])) {
      return $info[$type];
    }

    return FALSE;
  }

  public static function mb_http_input($type = '') {
    return FALSE;
  }

  public static function mb_http_output($encoding = NULL) {
    return NULL !== $encoding ? 'pass' === $encoding : 'pass';
  }

  public static function mb_strwidth($s, $encoding = NULL) {
    $encoding = self::getEncoding($encoding);

    if ('UTF-8' !== $encoding) {
      $s = iconv($encoding, 'UTF-8', $s);
    }

    $s = preg_replace('/[\x{1100}-\x{115F}\x{2329}\x{232A}\x{2E80}-\x{303E}\x{3040}-\x{A4CF}\x{AC00}-\x{D7A3}\x{F900}-\x{FAFF}\x{FE10}-\x{FE19}\x{FE30}-\x{FE6F}\x{FF00}-\x{FF60}\x{FFE0}-\x{FFE6}\x{20000}-\x{2FFFD}\x{30000}-\x{3FFFD}]/u', '', $s, -1, $wide);

    return ($wide << 1) + iconv_strlen($s, 'UTF-8');
  }

  public static function mb_substr_count($haystack, $needle, $encoding = NULL) {
    return substr_count($haystack, $needle);
  }

  public static function mb_output_handler($contents, $status) {
    return $contents;
  }

  private static function getSubpart($pos, $part, $haystack, $encoding) {
    if (FALSE === $pos) {
      return FALSE;
    }
    if ($part) {
      return self::mb_substr($haystack, 0, $pos, $encoding);
    }

    return self::mb_substr($haystack, $pos, NULL, $encoding);
  }

  private static function html_encoding_callback($m) {
    $i = 1;
    $entities = '';
    $m = unpack('C*', htmlentities($m[0], ENT_COMPAT, 'UTF-8'));

    while (isset($m[$i])) {
      if (0x80 > $m[$i]) {
        $entities .= chr($m[$i++]);
        continue;
      }
      if (0xF0 <= $m[$i]) {
        $c = (($m[$i++] - 0xF0) << 18) + (($m[$i++] - 0x80) << 12) + (($m[$i++] - 0x80) << 6) + $m[$i++] - 0x80;
      }
      elseif (0xE0 <= $m[$i]) {
        $c = (($m[$i++] - 0xE0) << 12) + (($m[$i++] - 0x80) << 6) + $m[$i++] - 0x80;
      }
      else {
        $c = (($m[$i++] - 0xC0) << 6) + $m[$i++] - 0x80;
      }

      $entities .= '&#' . $c . ';';
    }

    return $entities;
  }

  private static function title_case_lower($s) {
    return self::mb_convert_case($s[0], MB_CASE_LOWER, 'UTF-8');
  }

  private static function title_case_upper($s) {
    return self::mb_convert_case($s[0], MB_CASE_UPPER, 'UTF-8');
  }

  private static function getData($file) {
    if (file_exists($file = __DIR__ . '/Resources/unidata/' . $file . '.php')) {
      return require $file;
    }

    return FALSE;
  }

  private static function getEncoding($encoding) {
    if (NULL === $encoding) {
      return self::$internalEncoding;
    }

    $encoding = strtoupper($encoding);

    if ('8BIT' === $encoding || 'BINARY' === $encoding) {
      return 'CP850';
    }
    if ('UTF8' === $encoding) {
      return 'UTF-8';
    }

    return $encoding;
  }
}
