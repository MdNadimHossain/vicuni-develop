<?php

/**
 * @file
 * Updates for [PW-1543].
 *
 * Removes blocks from Victory theme.
 */

use Drupal\drupal_helpers\Block;

Block::removeAll('victory');
