<?php

/**
 * @file
 * Code for the VU Researcher Profile API data convert functions.
 *
 * Convert functions responsible for manipulation of raw API data before it is
 * stored in Drupal DB. Each function is covered by unit tests. It is critical
 * to always maintain unit tests for these functions as they may result in
 * some data to be missed.
 */

/**
 * Convert first name.
 */
function vu_rp_api_convert_first_name($value) {
  return ucfirst(strtolower($value));
}

/**
 * Convert last name.
 */
function vu_rp_api_convert_last_name($value) {
  return ucfirst(strtolower($value));
}

/**
 * Convert honorific.
 */
function vu_rp_api_convert_honorific($value) {
  return ucfirst(strtolower($value));
}

/**
 * Convert email.
 */
function vu_rp_api_convert_email($value) {
  return strtolower($value);
}

/**
 * Convert publication data into filtered and grouped data.
 */
function vu_rp_api_convert_publications($data) {
  $data = (array) $data;

  if (empty($data)) {
    return [];
  }

  // Types will be filtered and ordered using this list.
  $allowed_types = [
    'Book',
    'Book chapter',
    'Journal article',
    'Commissioned Research Report',
    'Conference paper',
  ];

  // Filter by allowed types.
  $data = array_filter($data, function ($value) use ($allowed_types) {
    return !empty($value['type']) && in_array(strtolower($value['type']), array_map('strtolower', $allowed_types));
  });

  // Count items per group.
  $groups = [];
  foreach ($data as $record) {
    $groups[$record['type']]['total'] = isset($groups[$record['type']]['total']) ? $groups[$record['type']]['total'] + 1 : 1;
  }

  // Check if there are any favourites.
  $favourites = array_filter($data, function ($value) {
    return !empty($value['favouritePublication']);
  });

  if (!empty($favourites)) {
    $data = $favourites;
  }

  // Sort reverse-chronological.
  uasort($data, function ($a, $b) {
    return strtotime($b['publicationDate']) - strtotime($a['publicationDate']);
  });

  // Limit to 10.
  $data = array_slice($data, 0, 10);

  // Fill-in items per type.
  foreach ($data as $record) {
    $groups[$record['type']]['items'][] = $record;
  }

  // Sort reverse-chronological within each group.
  $group_types = [];
  foreach ($groups as $type => $group) {
    if (empty($groups[$type]['items'])) {
      unset($groups[$type]);
      continue;
    }
    uasort($groups[$type]['items'], function ($a, $b) {
      return strtotime($b['publicationDate']) - strtotime($a['publicationDate']);
    });
    $group_types[] = $type;
  }

  array_unique($group_types);

  // Sort groups according to allowed list.
  $groups = array_intersect_key(array_replace(array_flip($allowed_types), $groups), array_flip($group_types));

  return $groups;
}

/**
 * Convert fundings data into filtered and grouped data.
 *
 * Important notes:
 *   - Grouping is done by start date.
 *   - Only projects that ended within last 5 years are shown.
 *   - Multi-entries projects dates have they start date as the start of the
 *     earliest project and the end as the end of the latest.
 *   - 'year' is always normalised to be the same as start date year.
 *   - Merging of investigators for multi-entry projects is done with full
 *     distinct on normalised first name, last name and honorific. This means
 *     that if one letter is different in any of the fields, this investigator
 *     is considered a separate distinct entry.
 *   - Merging of fund sources for multi-entry projects is done with name
 *     distinction: duplicated entries are removed.
 */
function vu_rp_api_convert_fundings($data) {
  $data = (array) $data;

  if (empty($data)) {
    return [];
  }

  $prohibited_types = [
    'Tender',
    'Research Contract',
  ];

  // Filter by confidential.
  $data = array_filter($data, function ($value) {
    return isset($value['confidential']) && $value['confidential'] === FALSE;
  });

  // Merge projects with the same id.
  $project_groups = [];
  foreach ($data as $k => $item) {
    $project_groups[$item['projectId']][] = $item;
  }
  // Merge projects.
  $merged_projects = [];
  foreach ($project_groups as $project_id => $project_group) {
    // Default merged project data to the first entry. Other will be overridden
    // below.
    $merged_projects[$project_id] = reset($project_group);

    // Reset calculated fields.
    $merged_projects[$project_id]['grantAmount'] = 0;
    $merged_projects[$project_id]['otherInvestigators'] = [];

    $start_date = date('Y-m-d H:i:s', strtotime('January 19, 2038'));
    $end_date = date('Y-m-d H:i:s', 0);

    $fund_sources = [];
    foreach ($project_group as $project) {
      $start_date = strtotime($project['startDate']) < strtotime($start_date) ? $project['startDate'] : $start_date;
      $merged_projects[$project_id]['startDate'] = $start_date;
      $end_date = strtotime($end_date) > strtotime($project['endDate']) ? $end_date : $project['endDate'];
      $merged_projects[$project_id]['endDate'] = $end_date;
      $merged_projects[$project_id]['grantAmount'] += $project['grantAmount'];
      $merged_projects[$project_id]['otherInvestigators'] = array_merge($merged_projects[$project_id]['otherInvestigators'], $project['otherInvestigators']);
      $fund_sources[] = $project['grantFundSource'];
    }
    $merged_projects[$project_id]['grantFundSource'] = implode(', ', array_unique($fund_sources));
  }
  $data = $merged_projects;

  // Sort reverse-chronological.
  uasort($data, function ($a, $b) {
    return strtotime($b['endDate']) - strtotime($a['endDate']);
  });

  // Decide if we can disclose.
  foreach ($data as $k => $item) {
    if (in_array($item['projectType'], $prohibited_types)) {
      $data[$k]['grantAmount'] = 'Not disclosed';
    }
    elseif ($item['grantAmount'] < 5000) {
      unset($data[$k]);
    }
  }

  // Remove all entries that finished before 5 years.
  $data = array_filter($data, function ($value) {
    return strtotime($value['endDate']) > strtotime('-5 years');
  });

  // Group by start year.
  // Since we are filtering out projects that finished before 5 years, there
  // may still be projects that started more then 5 years ago and still going.
  // For such projects, the year will appear as quite away in the past.
  $groups = [];
  foreach ($data as $k => $item) {
    // Process additional fields.
    if (!empty($item['otherInvestigators'])) {
      foreach (array_keys($item['otherInvestigators']) as $j) {
        $item['otherInvestigators'][$j]['firstName'] = isset($item['otherInvestigators'][$j]['firstName']) ? vu_rp_api_convert_first_name($item['otherInvestigators'][$j]['firstName']) : $item['otherInvestigators'][$j]['firstName'];
        $item['otherInvestigators'][$j]['lastName'] = isset($item['otherInvestigators'][$j]['lastName']) ? vu_rp_api_convert_last_name($item['otherInvestigators'][$j]['lastName']) : $item['otherInvestigators'][$j]['lastName'];
        $item['otherInvestigators'][$j]['honorific'] = isset($item['otherInvestigators'][$j]['honorific']) ? ucfirst(strtolower($item['otherInvestigators'][$j]['honorific'])) : $item['otherInvestigators'][$j]['honorific'];
      }
      // Remove duplicates.
      $hashes = [];
      foreach (array_keys($item['otherInvestigators']) as $j) {
        $hash = md5($item['otherInvestigators'][$j]['firstName'] . '_' . $item['otherInvestigators'][$j]['lastName'] . '_' . $item['otherInvestigators'][$j]['honorific']);
        $hashes[$hash] = $item['otherInvestigators'][$j];
      }
      $item['otherInvestigators'] = array_values($hashes);
    }

    $year = date('Y', strtotime($item['startDate']));
    // Year is not used anywhere, but we still want it to be the same as a
    // grouping year for consistency.
    $item['year'] = $year;

    $groups[$year][] = $item;
  }

  // Sort reverse chronologically each group.
  krsort($groups);

  // Sort reverse chronologically within each group.
  foreach (array_keys($groups) as $type) {
    uasort($groups[$type], function ($a, $b) {
      return strtotime($b['startDate']) - strtotime($a['startDate']);
    });
  }

  return $groups;
}

/**
 * Remove any character that is not supported.
 */
function vu_rp_api_convert_strings($text = '') {
  $cleanText = '';
  if (empty($text)) {
    return $cleanText;
  }

  $utf8 = [
    '/[áàâãªä]/u' => 'a',
    '/[ÁÀÂÃÄ]/u' => 'A',
    '/[ÍÌÎÏ]/u' => 'I',
    '/[íìîï]/u' => 'i',
    '/[éèêë]/u' => 'e',
    '/[ÉÈÊË]/u' => 'E',
    '/[óòôõºö]/u' => 'o',
    '/[ÓÒÔÕÖ]/u' => 'O',
    '/[úùûü]/u' => 'u',
    '/[ÚÙÛÜ]/u' => 'U',
    '/[çć]/u' => 'c',
    '/Ç/' => 'C',
    '/ñ/' => 'n',
    '/Ñ/' => 'N',
    '/š/' => 's',
    '/Ž/' => 'Z',
    '/–/' => '-',
    '/[’‘‹›‚]/u' => ' ',
    '/[“”«»„]/u' => ' ',
    '/ /' => ' ',
  ];

  $cleanText = preg_replace(array_keys($utf8), array_values($utf8), $text);

  // Reset clean text if error occurred.
  if (is_null($cleanText)) {
    $cleanText = $text;
  }

  return preg_replace('/[\x00-\x1F\x7F-\xFF]/', '', $cleanText);
}
