<?php

/**
 * @file
 * Contains functions related to journey planner block in campus pages.
 */

define('VU_CAMPUSES_METROWEST_ALIAS', 'vu-at-metrowest-footscray');
define('VU_CAMPUSES_METROWEST_TITLE', 'VU at MetroWest (Footscray)');

/**
 * Get the campus address.
 *
 * @param string $campus_alias
 *    Campus node alias.
 * @param bool $html
 *    Strip html tags if true.
 * @param bool $remove_country
 *    If true, exclude Country from the address.
 * @return string
 *    Return campus address.
 */
function vumain_journey_planner_get_address($campus_alias, $html = FALSE, $remove_country = FALSE) {
  $campus = vumain_journey_planner_get_campus_id($campus_alias);
  $campuses = array(
    'albert-place' => '88 Albert Street<br/>Footscray<br/>Australia',
    'victoria-place' => '117 - 119 Ballarat Road<br/>Footscray<br/>Australia',
    'student-village' => 'Corner Hampstead and Williamson Roads<br/>Maribyrnong<br/>Australia',
    'city-flinders' => '300 Flinders Street<br/>Melbourne<br/>Australia',
    'city-flinders-lane' => '301 Flinders Lane<br/>Melbourne<br/>Australia',
    'city-king' => '225 King Street<br/>Melbourne<br/>Australia',
    'city-queen' => '256, 283, 295 & 300 Queen Street<br/>Melbourne<br/>Australia',
    'city-queen-256' => '256 Queen Street<br/>Melbourne<br/>Australia',
    'city-queen-283' => '283 Queen Street<br/>Melbourne<br/>Australia',
    'city-queen-295' => '295 Queen Street<br/>Melbourne<br/>Australia',
    'city-queen-300' => '300 Queen Street<br/>Melbourne<br/>Australia',
    'footscray-nicholson' => 'Corner of Nicholson and Buckley Streets<br/>Footscray<br/>Australia',
    'footscray-park' => 'Ballarat Road<br/>Footscray<br/>Australia',
    'sunshine' => '460 Ballarat Road<br/>Sunshine<br/>Australia',
    'werribee' => 'Hoppers Lane<br/>Werribee<br/>Australia',
    'st-albans' => 'McKechnie St<br/>St Albans<br/>Australia',
    'vu-sydney' => 'Level 2-4, 545 Kent Street<br/>Australia',
  );

  $campuses[VU_CAMPUSES_METROWEST_ALIAS] = '138 Nicholson Street<br/>Footscray<br/>Australia';

  if ($remove_country) {
    foreach ($campuses as &$address) {
      $address = preg_replace('|<br/>Australia$|', '', $address);
    }
  }
  if (!$html) {
    foreach ($campuses as &$address) {
      $address = str_ireplace('<br/>', ', ', $address);
      $address = str_ireplace('<br>', ', ', $address);
    }
  }
  if ($campus) {
    $return = isset($campuses[$campus]) ? $campuses[$campus] : '';
  }
  else {
    $return = $campuses;
  }

  return $return;
}

/**
 * Prepare vars to render PTV journey planner.
 *
 * @param string $campus_alias
 *   Campus node alias.
 * @return mixed
 *    Return a campus address if specified otherwise return all addresses.
 */
function vumain_journey_planner_get_jp($campus_alias) {
  $prepend = 'Victoria University, ';
  $selected_address = vumain_journey_planner_get_address($campus_alias, FALSE);
  $campus_poi_id = vumain_journey_planner_get_poi_id($campus_alias);

  if (vumain_journey_planner_is_full_campus($campus_alias)) {
    $selected_address = $prepend . $selected_address;
  }

  $result['ptv'] = array(
    'type_destination' => 32,
    'poiID' => $campus_poi_id,
  );

  $all_addresses = vumain_journey_planner_get_address(NULL, FALSE);
  unset($all_addresses['albert-place']);
  unset($all_addresses['victoria-place']);
  unset($all_addresses['student-village']);
  unset($all_addresses['sunbury']);

  ksort($all_addresses);

  $result['selected_address'] = $selected_address;
  $result['campus_addresses'] = [];
  foreach ($all_addresses as $campusid => $address) {
    $campus_name = vumain_journey_planner_campus_name($campusid);
    $address_value = $address;
    if (vumain_journey_planner_is_full_campus($campusid) && $campusid !== 'footscray-nicholson') {
      $address_value = $prepend . $address_value;
    }
    $result['campus_addresses'][$campus_name] = $address_value;
  }
  return $result;
}

/**
 * Returns poi id which is a unique id used by PTV Journey Planner tool.
 */
/**
 * @param string $campus_alias
 *    Campus node alias.
 * @return string
 *   Campus poi id.
 */
function vumain_journey_planner_get_poi_id($campus_alias) {
  $campus = vumain_journey_planner_get_campus_id($campus_alias);
  $campuses = [
    'city-flinders' => '102356493:95101208',
    'city-flinders-lane' => '101725761:95101208',
    'city-king' => '101725730:95101208',
    'city-queen' => '101725265:95101208',
    'footscray-nicholson' => '102356491:95101134',
    'footscray-park' => '101010010:95101134',
    'sunshine' => '101009842:95101293',
    'werribee' => '101727173:95101325',
    'st-albans' => '101010764:95101286',
    VU_CAMPUSES_METROWEST_ALIAS => '104493157:95101134',
  ];

  return $campuses[$campus];
}

/**
 * Determines if a campus has full campus status or not i.e. MetroWest
 * technically is not.
 *
 * @param $campus
 *
 * @todo: Provide description and update type above.
 *
 * @return boolean
 *
 * @todo: Provide description.
 */
function vumain_journey_planner_is_full_campus($campus) {
  return $campus != VU_CAMPUSES_METROWEST_ALIAS;
}

/**
 * Get campus id.
 *
 * @param $campus .
 *
 * @todo: Provide description and update type above.
 *
 * @return string
 *
 * @todo: Provide description.
 */
function vumain_journey_planner_get_campus_id($campus) {
  if (empty($campus)) {
    return;
  }
  $campus_name = $campus;
  if (strpos($campus, 'campuses/') > -1) {
    $campus_name = preg_replace('/campuses\//i', '', $campus);
  }

  if ($campus == VU_CAMPUSES_METROWEST_ALIAS) {
    return VU_CAMPUSES_METROWEST_ALIAS;
  }

  return $campus_name;
}

/**
 * Normalise campus name.
 *
 * @param $campus
 *
 * @todo: Provide description and update type above.
 *
 * @return string
 *
 * @todo: Provide description.
 */
function vumain_journey_planner_campus_name($campus) {
  if (empty($campus)) {
    return '';
  }

  $campus_name = preg_replace('/[-]\d+/', '', $campus);
  $campus_name = ucwords(str_replace('-', ' ', $campus_name));
  $campus_name = str_replace('Vu ', 'VU ', $campus_name);
  if ($campus == VU_CAMPUSES_METROWEST_ALIAS) {
    return VU_CAMPUSES_METROWEST_TITLE;
  }

  return $campus_name . (vumain_journey_planner_is_full_campus($campus) ? ' Campus' : '');
}
