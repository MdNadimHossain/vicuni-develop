<?php

/**
 * @file
 * VU Researcher Profile Demo random API data.
 *
 * This is used to feed Drupal with API data directly, bypassing the client.
 */

use Drupal\drupal_helpers\Random;

/**
 * Return API researcher data with random values.
 */
function _vu_rp_demo_random_api_researcher() {
  return [
    'staffID' => _vu_rp_demo_get_random_staff_id(),
    'title' => vu_rp_demo_random_array_item([
      'Dr',
      'Professor',
      'Associate Professor',
      'Eur Ing',
      'Dean Laureate',
      'The Hon.',
      'The Hon. Justice',
      'Magistrate',
      'Judge',
    ]),
    'firstName' => 'FN_' . Random::name(),
    'secondName' => 'MN_' . Random::name(),
    'lastName' => 'LN_' . Random::name(),
    'preferredName' => rand(0, 10) % 3 ? '' : 'PrN_' . Random::name(),
    'orcID' => _vu_rp_demo_random_api_orcid(),
    'email' => Random::email(),
    'scorpusID' => NULL,
    'researcherID' => NULL,
    'classification' => 'ACADE',
    'managerId' => rand(pow(10, 6), pow(10, 7) - 1),
    'jobTitle' => 'JT_' . Random::name(),
    'supervisionAccreditationLevel' => 'Level ' . rand(1, 5),
    'fieldsOfResearch' => [],
    'publications' => _vu_rp_demo_random_api_publications(rand(1, 15)),
    'grantDetails' => _vu_rp_demo_random_api_grants(rand(1, 15)),
    'HDRDetails' => _vu_rp_demo_random_api_supervisions(rand(0, 25)),
  ];
}

/**
 * Publications data from API.
 */
function _vu_rp_demo_random_api_publications($count) {
  $publications = [];

  for ($i = 0; $i < $count; $i++) {
    $is_favourite = (bool) rand(1, 0);
    $publications[] = [
      'type' => vu_rp_demo_random_array_item([
        'Journal article',
        'Book Chapter',
        'Book',
        'Conference Paper',
        'Commissioned Research Report',
        'Internet publication',
        'Poster',
      ]),
      'title' => sprintf('PUB#%s of %s %s %s', ($i + 1), $count, ($is_favourite ? 'Fav' : ''), Random::lipsum(rand(5, 15))),
      // Between 10 years and 1 month ago.
      'publicationDate' => date('Ymd', time() - 24 * 60 * 60 - rand(10 * 365 * 24 * 60 * 60, 30 * 24 * 60 * 60)),
      'authors' => _vu_rp_demo_random_api_publications_authors(rand(1, 10)),
      'url' => NULL,
      'recordID' => rand(pow(10, 4), pow(10, 5) - 1),
      'favouritePublication' => $is_favourite,
      'journalTitle' => 'JT#' . ($i + 1) . '_' . Random::lipsum(rand(3, 8)),
      'volume' => rand(30, 200),
      'issue' => rand(1, 20),
      'paginationBegin' => 1,
      'paginationEnd' => rand(10, 250),
      'location' => NULL,
      'publisher' => NULL,
      'bookTitle' => NULL,
      'DOI' => rand(1, 10) % 3 ? _vu_rp_demo_random_api_doi() : NULL,
      'titleOfPaper' => 'ToP_' . Random::lipsum(rand(3, 15)),
      'titleOfConf' => 'ToC_' . Random::lipsum(rand(3, 15)),
      'editor' => NULL,
      'edition' => NULL,
    ];
  }

  return $publications;
}

/**
 * Generate authors of publications.
 */
function _vu_rp_demo_random_api_publications_authors($count) {
  $authors = [];
  for ($i = 0; $i < $count; $i++) {
    $authors[] = 'PA#' . ($i + 1) . ' ' . Random::name();
  }

  return $authors;
}

/**
 * Grants data from API.
 */
function _vu_rp_demo_random_api_grants($count) {
  $grants = [];

  $organisations = [];
  for ($i = 0; $i < $count * 2; $i++) {
    $organisations[] = 'FOn#' . ($i + 1) . '_' . Random::name();
  }

  for ($i = 0; $i < $count; $i++) {
    $start = rand(1, 20) % 4 ? rand(strtotime('-10 years'), time()) : NULL;
    $end = $start ? rand($start, time()) : NULL;

    $grant = [
      'projectType' => vu_rp_demo_random_array_item([
        'Linkage',
        'Not Specified',
        'Agreement',
        'Application',
        'Grants',
        'Research Contract',
        'Internal',
        'Tender',
      ]),
      'startDate' => $start,
      'endDate' => $end,
      'grantAmount' => rand(1, 100) * 1000,
      'grantFundSource' => vu_rp_demo_random_array_item(array_merge($organisations, [NULL])),
      'otherInvestigators' => rand(1, 20) % 3 ? _vu_rp_demo_random_api_grants_investigators(rand(1, 5)) : NULL,
      'confidential' => (bool) (rand(1, 20) % 3 == 0),
    ];

    $grant['projectTitle'] = sprintf('FT#%s %s [%s]', $i + 1, Random::lipsum(1), substr(json_encode($grant, JSON_PRETTY_PRINT), 0, 200));

    $grants[] = $grant;
  }

  return $grants;
}

/**
 * Create grants investigators data.
 */
function _vu_rp_demo_random_api_grants_investigators($count) {
  $investigators = [];

  for ($i = 0; $i < $count; $i++) {
    $investigators[] = [
      'staffID' => _vu_rp_demo_get_random_staff_id(),
      'role' => vu_rp_demo_random_array_item([
        'Supervisor',
        'Student',
        'Partner Investigator',
        'Associate Investigator',
      ]),
      'firstName' => Random::name(),
      'lastName' => Random::name(),
      'honorific' => vu_rp_demo_random_array_item([
        'PROF',
        'DR',
        NULL,
      ]),
    ];
  }

  return $investigators;
}

/**
 * Supervisions data from API.
 */
function _vu_rp_demo_random_api_supervisions($count) {
  $records = [];

  for ($i = 0; $i < $count; $i++) {
    $date = rand(strtotime('-7 years'), time());
    $date = date('Y-m-d', $date) . ' 00:00:00.0';
    $record = [
      'yearOfCompletion' => rand(1, 20) % 3 ? $date : NULL,
      'HDRType' => vu_rp_demo_random_array_item([
        'PhD',
        'Masters',
      ]),
      'supervisionRole' => vu_rp_demo_random_array_item([
        'Principal',
        'Associate',
      ]),
    ];

    $record['titleOfResearch'] = sprintf('ToR#%s %s [IsCurr: %s, Type: %s, Role: %s]', $i + 1, Random::lipsum(1), is_null($record['yearOfCompletion']) ? 'Y' : 'N', $record['HDRType'], $record['supervisionRole']);
    $records[] = $record;
  }

  return $records;
}

/**
 * Generate random DOI.
 */
function _vu_rp_demo_random_api_doi() {
  return sprintf('10.%s/%s.%s.%s', rand(pow(10, 3), pow(10, 4) - 1), Random::name(), rand(pow(10, 4), pow(10, 5) - 1), rand(pow(10, 3), pow(10, 4) - 1));
}

/**
 * Generate random Staff ID.
 */
function _vu_rp_demo_get_random_staff_id() {
  return 'E' . rand(pow(10, 6), pow(10, 7) - 1);
}

/**
 * Generate random ORCID in the format '0000-0002-1825-0097'.
 *
 * @see https://orcid.org/trademark-and-id-display-guidelines
 */
function _vu_rp_demo_random_api_orcid() {
  $parts = [];
  for ($i = 0; $i < 4; $i++) {
    $parts[] = str_pad(rand(0, 9999), 4, '0', STR_PAD_LEFT);
  }

  return implode('-', $parts);
}
