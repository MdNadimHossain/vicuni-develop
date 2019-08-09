<?php

/**
 * @file
 * VU CORS functions.
 */

/**
 * Add CORS header if required.
 */
function _vu_core_cors_header_prepare_for_path($path, $request_origin, $cors_config) {
  // This adds cross-site access to the configured paths.
  $header = 'Access-Control-Allow-Origin';
  if (empty($path) || empty($cors_config || empty($request_origin))) {
    return [];
  }

  foreach ($cors_config as $cors_path => $remote_domains) {
    if (strpos($path, $cors_path) === 0) {
      $cors_path_length = strlen($cors_path);

      // This is just to make sure that node/1 doesn't match node/12343.
      if (strlen($path) > $cors_path_length && substr($path, $cors_path_length, 1) !== '/') {
        continue;
      }
      foreach ($remote_domains as $remote_domain) {
        // Strip http(s)://, port, credentials, etc.
        $request_scheme = parse_url($request_origin, PHP_URL_SCHEME);
        $request_origin_host = parse_url($request_origin, PHP_URL_HOST);
        $domain_in_origin = strpos($request_origin_host, $remote_domain);
        if ($domain_in_origin === FALSE || $domain_in_origin > 0 || strlen($request_origin_host) !== strlen($remote_domain)) {
          continue;
        }

        // CORS header only allows a single value or "*".
        return [
          'name' => $header,
          'value' => $request_scheme . "://" . $remote_domain,
        ];
      }
    }
  }
  return [];
}

if (!function_exists('getallheaders')) {

  /**
   * Getallheaders isn't on nginx or php-fpm so, re-implement it.
   */
  function getallheaders() {
    foreach ($_SERVER as $name => $value) {
      if (substr($name, 0, 5) == 'HTTP_') {
        $headers[str_replace(' ', '-', ucwords(strtolower(str_replace('_', ' ', substr($name, 5)))))] = $value;
      }
    }
    return $headers;
  }

}
