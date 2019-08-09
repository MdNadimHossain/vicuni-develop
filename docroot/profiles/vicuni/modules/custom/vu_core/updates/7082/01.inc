<?php

/**
 * @file
 * Adds Researcher Profile API configuration.
 */

use Drupal\drupal_helpers\General;

$provider_config = [
  'dev' =>
    [
      'list' =>
        [
          'url' => 'https://internal.api.vu.edu.au/era-dev/api/v1/researcher/profiles',
          'auth_username' => 'researchProfile',
          'auth_password' => ',,$rProfile-18',
          'timeout' => 180,
        ],
      'account' =>
        [
          'url' => 'https://internal.api.vu.edu.au/era-dev/api/v1/researcher/profile/{account}',
          'auth_username' => 'researchProfile',
          'auth_password' => ',,$rProfile-18',
          'timeout' => 180,
          'status' =>
            [
              'test_account' => 'E5105512',
            ],
        ],
    ],
  'prod' =>
    [
      'list' =>
        [
          'url' => 'https://api.vu.edu.au/era-prod/api/v1/researcher/profiles',
          'auth_username' => 'researchProfile',
          'auth_password' => ',,$rProfile-18',
          'timeout' => 180,
        ],
      'account' =>
        [
          'url' => 'https://api.vu.edu.au/era-prod/api/v1/researcher/profile/{account}',
          'auth_username' => 'researchProfile',
          'auth_password' => ',,$rProfile-18',
          'timeout' => 180,
          'status' =>
            [
              'test_account' => 'E5105512',
            ],
        ],
    ],
  'local' =>
    [
      'list' =>
        [
          'url' => 'vu-rest/researcher/profiles',
          'auth_username' => '',
          'auth_password' => '',
          'timeout' => 20,
        ],
      'account' =>
        [
          'url' => 'vu-rest/researcher/profile/{account}',
          'auth_username' => '',
          'auth_password' => '',
          'timeout' => 20,
          'status' =>
            [
              'test_account' => 'E9999001',
            ],
        ],
    ],
  'test2' =>
    [
      'list' =>
        [
          'url' => 'https://test2.vu.edu.au/vu-rest/researcher/profiles',
          'auth_username' => 'vu',
          'auth_password' => 'uv',
          'timeout' => 60,
        ],
      'account' =>
        [
          'url' => 'https://test2.vu.edu.au/vu-rest/researcher/profile/{account}',
          'auth_username' => 'vu',
          'auth_password' => 'uv',
          'timeout' => 60,
          'status' =>
            [
              'test_account' => 'E9999001',
            ],
        ],
    ],
];

variable_set('vu_rp_api_provider', 'dev');
variable_set('vu_rp_api_provider_config', $provider_config);
variable_set('vu_rp_api_logger_is_enabled', 1);
variable_set('vu_rp_api_debug_request', 0);
vu_rp_api_get_client(TRUE);
General::messageSet('Imported API providers configuration');
