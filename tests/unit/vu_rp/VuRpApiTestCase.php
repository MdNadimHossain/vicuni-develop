<?php

/**
 * Class VuRpApiTestCase.
 */
abstract class VuRpApiTestCase extends VicUniTestCase {

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    $module_path = sprintf('%s/%s', getcwd(), 'docroot/profiles/vicuni/modules/custom/vu_rp');
    require_once $module_path . '/includes/node.inc';
    require_once $module_path . '/modules/vu_rp_api/vu_rp_api.render.inc';
    require_once $module_path . '/modules/vu_rp_api/vu_rp_api.convert.inc';
  }

  public function getPublication($type, $overrides = []) {
    $data = [
      'type' => $type,
      'title' => 'Test publication title',
      'references' => [
        '18612',
      ],
      'publicationDate' => date('Ymd', strtotime('September 1, 2015')),
      'authors' => [
        'Author1 FM',
        'Author2 FnM',
        'Author3',
      ],
      'url' => NULL,
      'recordID' => '71623',
      'favouritePublication' => FALSE,
      'journalTitle' => 'Journal title',
      'volume' => 'vol 1',
      'issue' => 'issue 5',
      'paginationBegin' => 20,
      'paginationEnd' => 105,
      'location' => 'Location 1',
      'publisher' => 'Some publisher 1',
      'bookTitle' => 'Book title 1',
      'DOI' => '10.1055/s-0032-1316315',
      'titleOfPaper' => 'Title of paper 1',
      'titleOfConf' => 'Title of conference 1',
      'editor' => 'Editor F',
      'edition' => 'Edition 1',
    ];

    return $overrides + $data;
  }

  public function getGrant($id, $type, $overrides = []) {
    $data = [
      'projectId' => $id,
      'projectTitle' => 'Quantifying and overcoming fatigue during intermittent high-intensity exercise performed at altitude',
      'projectType' => $type,
      'startDate' => date('Y', strtotime('-1 year')) . '-01-01 00:00:00.0',
      'endDate' => date('Y', strtotime('-1 year')) . '-4-1 00:00:00.0',
      'year' => date('Y', strtotime('-1 year')),
      'grantFundSource' => 'Western Bulldogs',
      'grantAmount' => 20000.0,
      'confidential' => FALSE,
      'researchersRole' => '1st Chief Investigator',
      'otherInvestigators' => [],
    ];

    if (isset($overrides['startDate'])) {
      $overrides['startDate'] = date('Y-m-d', strtotime($overrides['startDate'] . '-1-1')) . ' 00:00:00.0';
    }
    $data = $overrides + $data;

    $year_end = isset($overrides['endDate']) ? $overrides['endDate'] : intval(date('Y', strtotime($data['startDate'])));
    $overrides['endDate'] = date('Y-m-d', strtotime($year_end . '-4-1')) . ' 00:00:00.0';

    if (!isset($overrides['year'])) {
      $overrides['year'] = date('Y', strtotime($overrides['startDate']));
    }

    $data = $overrides + $data;

    return $data;
  }

  public function getInvestigator($overrides = []) {
    $data = [
      'staffID' => 'E5027900',
      'role' => 'Chief Investigator',
      'firstName' => 'DAVID',
      'lastName' => 'BISHOP',
      'honorific' => 'PROF',
    ];

    return $overrides + $data;
  }

}
