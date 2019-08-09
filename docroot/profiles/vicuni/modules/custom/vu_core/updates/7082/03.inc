<?php

/**
 * @file
 * Provisions Research Profile nodes for UAT accounts (but Drupal not accounts).
 */

use Drupal\drupal_helpers\General;

module_load_install('vu_rp');

$staff_ids = [
  'E5100418',
  'E5102013',
  'E5004368',
  'E5105173',
];

foreach ($staff_ids as $staff_id) {
  vu_rp_install_provision_profile($staff_id);
}

General::messageSet('Finishing provisioning of Researcher Profiles for UAT accounts');
