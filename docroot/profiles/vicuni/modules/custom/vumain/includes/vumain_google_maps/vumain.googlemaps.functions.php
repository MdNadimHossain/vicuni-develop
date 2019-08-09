<?php
/**
 * @file
 * Functions related to the google maps block in campus pages.
 */

/**
 * Get campus id.
 *
 * @param string $campus_alias
 *   A URL alias for a campus page.
 *
 * @return string
 *   Slug based on a campus name.
 */
function vumain_googlemaps_get_campus_id($campus_alias) {
  if (empty($campus_alias)) {
    return '';
  }

  if ($campus_alias == VU_CAMPUSES_METROWEST_ALIAS) {
    return VU_CAMPUSES_METROWEST_ALIAS;
  }

  // ID is the last component of the alias with trailing '-campus' removed.
  $alias_parts = explode('/', $campus_alias);
  $campus_name = preg_replace('/-campus$/', '', end($alias_parts));

  return $campus_name;
}

/**
 * Determines if a campus has full campus status or not.
 *
 * E.g. MetroWest is technically not.
 *
 * @param string $campus_alias
 *   A URL alias for a campus page.
 *
 * @return bool
 *   Is campus?
 */
function vumain_googlemaps_is_full_campus($campus_alias) {
  return $campus_alias != VU_CAMPUSES_METROWEST_ALIAS;
}

/**
 * Gmaps zoom level per campus.
 *
 * @param string $campus_alias
 *   Alias for the campus node.
 *
 * @return int|array
 *   Zoom level for the campus, or for all campuses if the
 *   campus wasn't matched.
 */
function vumain_campuses_zoom($campus_alias) {
  $campus_id = vumain_googlemaps_get_campus_id($campus_alias);
  $campuses = array(
    'albert-place' => 15,
    'victoria-place' => 14,
    'student-village' => 15,
    'city-flinders' => 16,
    'city-flinders-lane' => 19,
    'city-king' => 17,
    'city-queen' => 17,
    'footscray-nicholson' => 16,
    'footscray-park' => 16,
    'melton' => 15,
    VU_CAMPUSES_METROWEST_ALIAS => 17,
    'sunshine' => 15,
    'werribee' => 16,
    'st-albans' => 17,
    'vu-sydney' => 16,
  );
  return $campus_id ? $campuses[$campus_id] : $campuses;
}

/**
 * Latitude and longitude for each campus.
 *
 * @param string $campus_alias
 *   Alias for the campus node.
 *
 * @return int|array
 *   Lat and long for the campus, or for all campuses if the
 *   campus didn't match or is not set.
 */
function vumain_campuses_get_lat_long($campus_alias = '') {
  $campus_id = '';
  if (!empty($campus_alias)) {
    $campus_id = vumain_googlemaps_get_campus_id($campus_alias);
  }
  $campuses = array(
    'albert-place' => array(
      'lat' => -37.806038,
      'long' => 144.8970,
    ),
    'victoria-place' => array(
      'lat' => -37.791320,
      'long' => 144.89546,
    ),
    'student-village' => array(
      'lat' => -37.775518,
      'long' => 144.87746,
    ),
    'city-flinders' => array(
      'lat' => -37.818022,
      'long' => 144.96382,
    ),
    'city-flinders-lane' => array(
      'lat' => -37.81740,
      'long' => 144.96398,
    ),
    'city-king' => array(
      'lat' => -37.81475,
      'long' => 144.95473,
    ),
    'city-queen' => array(
      'lat' => -37.811861,
      'long' => 144.958993,
    ),
    'city-queen-295' => array(
      'address' => '295 Queen Street',
      'lat' => -37.811861,
      'long' => 144.958993,
    ),
    'city-queen-256' => array(
      'address' => '256 Queen Street',
      'lat' => -37.812447,
      'long' => 144.959841,
    ),
    'city-queen-283' => array(
      'address' => '283 Queen Street',
      'lat' => -37.812561,
      'long' => 144.959283,
    ),
    'city-queen-300' => array(
      'address' => '300 Queen Street',
      'lat' => -37.811587,
      'long' => 144.959459,
    ),
    'footscray-nicholson' => array(
      'lat' => -37.805060,
      'long' => 144.898236,
    ),
    'footscray-park' => array(
      'lat' => -37.79395,
      'long' => 144.8993,
    ),
    'melton' => array(
      'lat' => -37.70535,
      'long' => 144.5658,
    ),
    VU_CAMPUSES_METROWEST_ALIAS => array(
      'lat' => -37.8013994,
      'long' => 144.8993,
    ),
    'sunshine' => array(
      'lat' => -37.776626,
      'long' => 144.83357,
    ),
    'werribee' => array(
      'lat' => -37.889428,
      'long' => 144.6990,
    ),
    'st-albans' => array(
      'lat' => -37.751138,
      'long' => 144.797046,
    ),
    'vu-sydney' => array(
      'lat' => -33.869788,
      'long' => 151.204019,
    ),
  );
  
  return !empty($campus_id) && !empty($campuses[$campus_id]) ? $campuses[$campus_id] : $campuses;
}

/**
 * Get Location Address from campus.
 *
 * @param object $campus
 *   Campus node.
 *
 * @return string
 *   Campus Address
 */
function vumain_campus_get_location($campus, $process_address = TRUE) {
  $address = '';
  if (!isset($campus->type)) {
    return $address;
  }

  $nid = vu_core_extract_single_field_value($campus, 'node', 'field_location', 'target_id');

  if (!$nid) {
    return $address;
  }

  $location = entity_load('inline_entities', [$nid]);
  $location = reset($location);

  $field_address = field_get_items('inline_entities', $location, 'field_address');

  if (empty($field_address)) {
    return $address;
  }

  if (!$process_address) {
    return $field_address;
  }

  $address = str_replace(', Australia', '', addressfield_staticmap_clean_address($field_address[0]));

  return $address;

}

/**
 * Get city queen Location Address from campus.
 *
 * @param object $campus
 *   Campus node.
 *
 * @return string
 *   Campus Address
 */
function vumain_campus_get_city_queen_locations() {

  $all_campuses = vumain_campuses_get_lat_long();
  $filtered = array_filter(array_keys($all_campuses), function ($k) {
    return strpos($k, 'queen-') !== FALSE;
  });
  $city_queen_lat_long = array_values(array_intersect_key($all_campuses, array_flip($filtered)));

  return $city_queen_lat_long;
}