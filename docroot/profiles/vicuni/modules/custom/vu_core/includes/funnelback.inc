<?php

/**
 * @file
 * Funnelback module integration.
 */

/**
 * Alter funnelback query.
 */
function vu_core_funnelback_query_alter(&$query) {
  // See PW-5471.
  unset($query['profile']);
}

/**
 * Alter funnelback result.
 */
function vu_core_funnelback_result_alter(&$result) {
  // See PW-5471
  // Replace display url with click tracking url.
  if (!empty($result['results'])) {
    foreach ($result['results'] as &$item) {
      if (!empty($item['clickTrackingUrl'])) {
        $item['display_url'] = FUNNELBACK_BASE_URL . ltrim($item['clickTrackingUrl'], '/');
      }
    }
  }
}
