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

return array(
  'code' => '46',
  'patterns' => array(
    'national' => array(
      'general' => '/^[1-9]\\d{6,9}$/',
      'fixed' => '/^1(?:0[1-8]\\d{6}|[136]\\d{5,7}|(?:2[0-35]|4[0-4]|5[0-25-9]|7[13-6]|[89]\\d)\\d{5,6})|2(?:[136]\\d{5,7}|(?:2[0-7]|4[0136-8]|5[0138]|7[018]|8[01]|9[0-57])\\d{5,6})|3(?:[356]\\d{5,7}|(?:0[0-4]|1\\d|2[0-25]|4[056]|7[0-2]|8[0-3]|9[023])\\d{5,6})|4(?:[0246]\\d{5,7}|(?:1[0-8]|3[0135]|5[14-79]|7[0-246-9]|8[0156]|9[0-689])\\d{5,6})|5(?:0[0-6]|[15][0-5]|2[0-68]|3[0-4]|4\\d|6[03-5]|7[013]|8[0-79]|9[01])\\d{5,6}|6(?:[03]\\d{5,7}|(?:1[1-3]|2[0-4]|4[02-57]|5[0-37]|6[0-3]|7[0-2]|8[0247]|9[0-356])\\d{5,6})|8\\d{6,8}|9(?:0\\d{5,7}|(?:1[0-68]|2\\d|3[02-59]|[45][0-4]|[68][01]|7[0135-8])\\d{5,6})$/',
      'mobile' => '/^7[0236]\\d{7}$/',
      'pager' => '/^74\\d{7}$/',
      'tollfree' => '/^20\\d{4,7}$/',
      'premium' => '/^9(?:00|39|44)\\d{7}$/',
      'shared' => '/^77\\d{7}$/',
      'personal' => '/^75\\d{7}$/',
      'emergency' => '/^112|90000$/',
    ),
    'possible' => array(
      'general' => '/^\\d{5,10}$/',
      'fixed' => '/^\\d{5,9}$/',
      'mobile' => '/^\\d{9}$/',
      'pager' => '/^\\d{9}$/',
      'tollfree' => '/^\\d{6,9}$/',
      'premium' => '/^\\d{10}$/',
      'shared' => '/^\\d{9}$/',
      'personal' => '/^\\d{9}$/',
      'emergency' => '/^\\d{3,5}$/',
    ),
  ),
);
