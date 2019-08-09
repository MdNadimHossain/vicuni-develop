<?php

/**
 * Class VuRpApiFundingTest.
 */
class VuRpApiFundingTest extends VuRpApiTestCase {

  /**
   * @dataProvider provideFundingsConvert
   * @group wip
   */
  public function testFundingsConvert($data, $expected) {
    $actual = vu_rp_api_convert_fundings($data);
    $this->assertEquals($expected, $actual);
  }

  public function provideFundingsConvert() {
    $year = date('Y');
    $old_year = date('Y', strtotime('-10 years'));

    $year1 = $year - 1;
    $year2 = $year - 2;
    $year3 = $year - 3;
    $year4 = $year - 4;
    $year7 = $year - 7;

    $year_future2 = $year + 2;

    $prohibited_type = 'Tender';
    $allowed_type = 'other';

    return [
      [NULL, []],

      // This year.
      [
        [
          $this->getGrant('p1', $allowed_type, ['startDate' => $year]),
        ],
        [
          $year => [
            $this->getGrant('p1', $allowed_type, ['startDate' => $year]),
          ],
        ],
      ],

      // Altering by type.
      [
        [
          $this->getGrant('p1', $prohibited_type, ['startDate' => $year]),
        ],
        [
          $year => [
            $this->getGrant('p1', $prohibited_type, ['startDate' => $year, 'grantAmount' => 'Not disclosed']),
          ],
        ],
      ],

      // Filtering by year - old start, old finish.
      [
        [
          $this->getGrant('p1', $allowed_type, ['startDate' => $old_year]),
          $this->getGrant('p1', $prohibited_type, ['startDate' => $old_year]),
        ],
        [],
      ],
      // Filtering by year - old start, finished recently.
      [
        [
          $this->getGrant('p1', $allowed_type, ['startDate' => $old_year, 'endDate' => $year4]),
          $this->getGrant('p2', $prohibited_type, ['startDate' => $old_year]),
        ],
        [
          $old_year => [
            $this->getGrant('p1', $allowed_type, ['startDate' => $old_year, 'endDate' => $year4]),
          ],
        ],
      ],
      // Filtering by year - old start, finish in the future.
      [
        [
          $this->getGrant('p1', $allowed_type, ['startDate' => $old_year, 'endDate' => $year_future2]),
          $this->getGrant('p2', $prohibited_type, ['startDate' => $old_year]),
        ],
        [
          $old_year => [
            $this->getGrant('p1', $allowed_type, ['startDate' => $old_year, 'endDate' => $year_future2]),
          ],
        ],
      ],
      // Filtering by year - recent start, recent finish.
      [
        [
          $this->getGrant('p1', $allowed_type, ['startDate' => $year4, 'endDate' => $year3]),
          $this->getGrant('p2', $prohibited_type, ['startDate' => $old_year]),
        ],
        [
          $year4 => [
            $this->getGrant('p1', $allowed_type, ['startDate' => $year4, 'endDate' => $year3]),
          ],
        ],
      ],
      // Filtering by year - recent start, finish in the future.
      [
        [
          $this->getGrant('p1', $allowed_type, ['startDate' => $year4, 'endDate' => $year_future2]),
          $this->getGrant('p2', $prohibited_type, ['startDate' => $old_year]),
        ],
        [
          $year4 => [
            $this->getGrant('p1', $allowed_type, ['startDate' => $year4, 'endDate' => $year_future2]),
          ],
        ],
      ],

      // Filtering by year + type.
      [
        [
          $this->getGrant('p1', $prohibited_type, ['startDate' => $year7]),
          $this->getGrant('p2', $allowed_type, ['startDate' => $year7]),
        ],
        [],
      ],

      // Filtering by type + amount.
      [
        [
          $this->getGrant('p1', $prohibited_type, ['startDate' => $year, 'grantAmount' => 3]),
          $this->getGrant('p2', $allowed_type, ['startDate' => $year, 'grantAmount' => 3]),
        ],
        [
          $year => [
            $this->getGrant('p1', $prohibited_type, ['startDate' => $year, 'grantAmount' => 'Not disclosed']),
          ],
        ],
      ],

      // Sorting.
      [
        [
          $this->getGrant('p1', $allowed_type, ['projectTitle' => 't31', 'startDate' => $year3]),
          $this->getGrant('p2', $allowed_type, ['projectTitle' => 't11', 'startDate' => $year1]),
          $this->getGrant('p3', $allowed_type, ['projectTitle' => 't21', 'startDate' => $year2]),
          $this->getGrant('p4', $allowed_type, ['projectTitle' => 't12', 'startDate' => $year1]),
          $this->getGrant('p5', $allowed_type, ['projectTitle' => 't32', 'startDate' => $year3]),
          $this->getGrant('p6', $allowed_type, ['projectTitle' => 't41', 'startDate' => $year4]),
          $this->getGrant('p7', $allowed_type, ['projectTitle' => 't13', 'startDate' => $year1]),
          $this->getGrant('p8', $allowed_type, ['projectTitle' => 't42', 'startDate' => $year4]),
        ],
        [
          $year1 => [
            $this->getGrant('p2', $allowed_type, ['projectTitle' => 't11', 'startDate' => $year1]),
            $this->getGrant('p4', $allowed_type, ['projectTitle' => 't12', 'startDate' => $year1]),
            $this->getGrant('p7', $allowed_type, ['projectTitle' => 't13', 'startDate' => $year1]),
          ],
          $year2 => [
            $this->getGrant('p3', $allowed_type, ['projectTitle' => 't21', 'startDate' => $year2]),
          ],
          $year3 => [
            $this->getGrant('p1', $allowed_type, ['projectTitle' => 't31', 'startDate' => $year3]),
            $this->getGrant('p5', $allowed_type, ['projectTitle' => 't32', 'startDate' => $year3]),
          ],
          $year4 => [
            $this->getGrant('p6', $allowed_type, ['projectTitle' => 't41', 'startDate' => $year4]),
            $this->getGrant('p8', $allowed_type, ['projectTitle' => 't42', 'startDate' => $year4]),
          ],
        ],
      ],

      // Investigators.
      [
        [
          $this->getGrant('p1', $allowed_type, ['startDate' => $year, 'otherInvestigators' => [$this->getInvestigator(['firstName' => 'JaNe', 'lastName' => 'doE', 'honorific' => 'PROF'])]]),
        ],
        [
          $year => [
            $this->getGrant('p1', $allowed_type, ['startDate' => $year, 'otherInvestigators' => [$this->getInvestigator(['firstName' => 'Jane', 'lastName' => 'Doe', 'honorific' => 'Prof'])]]),
          ],
        ],
      ],

      // Composite projects, no investigators.
      [
        [
          // This should end up under $year2 group. Also, note that fund
          // source is the same in the third line - this is to test that fund
          // sources are not duplicated.
          $this->getGrant('p1', $allowed_type, ['projectTitle' => 't1', 'startDate' => $year7, 'grantFundSource' => 'fs11', 'grantAmount' => 10101]),
          $this->getGrant('p1', $allowed_type, ['projectTitle' => 't1', 'startDate' => $year4, 'grantFundSource' => 'fs12', 'grantAmount' => 10102]),
          $this->getGrant('p1', $allowed_type, ['projectTitle' => 't1', 'startDate' => $year2, 'grantFundSource' => 'fs11', 'grantAmount' => 10103]),
          // This should be finished under $year4 group.
          $this->getGrant('p2', $allowed_type, ['projectTitle' => 't2', 'startDate' => $year7, 'grantFundSource' => 'fs21', 'grantAmount' => 10201]),
          $this->getGrant('p2', $allowed_type, ['projectTitle' => 't2', 'startDate' => $year4, 'grantFundSource' => 'fs22', 'grantAmount' => 10202]),
          // This should be finished under $year2 group.
          $this->getGrant('p3', $allowed_type, ['projectTitle' => 't3', 'startDate' => $year2, 'grantFundSource' => 'fs31', 'grantAmount' => 10301]),
          // This should be excluded as it was finished before 5 years ago.
          $this->getGrant('p4', $allowed_type, ['projectTitle' => 't4', 'startDate' => $year7, 'grantFundSource' => 'fs41', 'grantAmount' => 10401]),
        ],
        [
          $year2 => [
            $this->getGrant('p3', $allowed_type, ['projectTitle' => 't3', 'startDate' => $year2, 'endDate' => $year2, 'year' => $year2, 'grantFundSource' => 'fs31', 'grantAmount' => 10301]),
          ],
          $year7 => [
            $this->getGrant('p1', $allowed_type, ['projectTitle' => 't1', 'startDate' => $year7, 'endDate' => $year2, 'year' => $year7, 'grantFundSource' => 'fs11, fs12', 'grantAmount' => 10101 + 10102 + 10103]),
            $this->getGrant('p2', $allowed_type, ['projectTitle' => 't2', 'startDate' => $year7, 'endDate' => $year4, 'year' => $year7, 'grantFundSource' => 'fs21, fs22', 'grantAmount' => 10201 + 10202]),
          ],
        ],
      ],

      // Composite projects, no investigators, checking composite sum is > 5000.
      [
        [
          // This should not be included.
          $this->getGrant('p1', $allowed_type, ['projectTitle' => 't1', 'startDate' => $year2, 'grantAmount' => 100]),
          $this->getGrant('p1', $allowed_type, ['projectTitle' => 't1', 'startDate' => $year2, 'grantAmount' => 100]),
          $this->getGrant('p1', $allowed_type, ['projectTitle' => 't1', 'startDate' => $year2, 'grantAmount' => 5000 - 100 - 100 - 1]),
          // This should be included, amount = 5001.
          $this->getGrant('p2', $allowed_type, ['projectTitle' => 't2', 'startDate' => $year2, 'grantAmount' => 100]),
          $this->getGrant('p2', $allowed_type, ['projectTitle' => 't2', 'startDate' => $year2, 'grantAmount' => 100]),
          $this->getGrant('p2', $allowed_type, ['projectTitle' => 't2', 'startDate' => $year2, 'grantAmount' => 5000 - 100 - 100 + 1]),
          // This should be included, amount = 5000.
          $this->getGrant('p3', $allowed_type, ['projectTitle' => 't3', 'startDate' => $year2, 'grantAmount' => 100]),
          $this->getGrant('p3', $allowed_type, ['projectTitle' => 't3', 'startDate' => $year2, 'grantAmount' => 100]),
          $this->getGrant('p3', $allowed_type, ['projectTitle' => 't3', 'startDate' => $year2, 'grantAmount' => 5000 - 100 - 100 + 0]),
        ],
        [
          $year2 => [
            $this->getGrant('p2', $allowed_type, ['projectTitle' => 't2', 'startDate' => $year2, 'endDate' => $year2, 'year' => $year2, 'grantAmount' => 5001]),
            $this->getGrant('p3', $allowed_type, ['projectTitle' => 't3', 'startDate' => $year2, 'endDate' => $year2, 'year' => $year2, 'grantAmount' => 5000]),
          ],
        ],
      ],

      // Composite projects + investigators.
      [
        [
          $this->getGrant('p1', $allowed_type, [
            'projectTitle' => 't1',
            'startDate' => $year7,
            'grantFundSource' => 'fs11',
            'grantAmount' => 10101,
            'otherInvestigators' => [
              $this->getInvestigator(['firstName' => 'JaNe1', 'lastName' => 'doE1', 'honorific' => 'PROF1']),
              $this->getInvestigator(['firstName' => 'JaNe2', 'lastName' => 'doE2', 'honorific' => 'PROF2']),
            ],
          ]),

          // Note that second investigator has the same last name as for grant
          // above, but different first name, so it is a different person.
          $this->getGrant('p1', $allowed_type, [
            'projectTitle' => 't1',
            'startDate' => $year2,
            'grantFundSource' => 'fs12',
            'grantAmount' => 10102,
            'otherInvestigators' => [
              $this->getInvestigator(['firstName' => 'JaNe3', 'lastName' => 'doE3', 'honorific' => 'PROF3']),
              $this->getInvestigator(['firstName' => 'JaNe2', 'lastName' => 'doE1', 'honorific' => 'PROF21']),
              $this->getInvestigator(['firstName' => 'JaNe1', 'lastName' => 'doE1', 'honorific' => 'PROF1']),
            ],
          ]),
          // Same investigator as another project - should still appear.
          $this->getGrant('p2', $allowed_type, [
            'projectTitle' => 't2',
            'startDate' => $year4,
            'grantFundSource' => 'fs21',
            'grantAmount' => 10201,
            'otherInvestigators' => [
              $this->getInvestigator(['firstName' => 'JaNe4', 'lastName' => 'doE4', 'honorific' => 'PROF4']),
              $this->getInvestigator(['firstName' => 'JaNe1', 'lastName' => 'doE1', 'honorific' => 'PROF1']),
            ],
          ]),
          // Old year - should not be included in result.
          $this->getGrant('p3', $allowed_type, [
            'projectTitle' => 't3',
            'startDate' => $year7,
            'grantFundSource' => 'fs31',
            'grantAmount' => 10301,
            'otherInvestigators' => [
              $this->getInvestigator(['firstName' => 'JaNe4', 'lastName' => 'doE4', 'honorific' => 'PROF4']),
              $this->getInvestigator(['firstName' => 'JaNe1', 'lastName' => 'doE1', 'honorific' => 'PROF1']),
            ],
          ]),
        ],
        [
          $year4 => [
            $this->getGrant('p2', $allowed_type, [
              'projectTitle' => 't2',
              'startDate' => $year4,
              'endDate' => $year4,
              'grantFundSource' => 'fs21',
              'grantAmount' => 10201,
              'otherInvestigators' => [
                $this->getInvestigator(['firstName' => 'Jane4', 'lastName' => 'Doe4', 'honorific' => 'Prof4']),
                $this->getInvestigator(['firstName' => 'Jane1', 'lastName' => 'Doe1', 'honorific' => 'Prof1']),
              ],
            ]),
          ],
          $year7 => [
            $this->getGrant('p1', $allowed_type, [
              'projectTitle' => 't1',
              'startDate' => $year7,
              'endDate' => $year2,
              'year' => $year7,
              'grantFundSource' => 'fs11, fs12',
              'grantAmount' => 10101 + 10102,
              'otherInvestigators' => [
                $this->getInvestigator(['firstName' => 'Jane1', 'lastName' => 'Doe1', 'honorific' => 'Prof1']),
                $this->getInvestigator(['firstName' => 'Jane2', 'lastName' => 'Doe2', 'honorific' => 'Prof2']),
                $this->getInvestigator(['firstName' => 'Jane3', 'lastName' => 'Doe3', 'honorific' => 'Prof3']),
                $this->getInvestigator(['firstName' => 'Jane2', 'lastName' => 'Doe1', 'honorific' => 'Prof21']),
              ],
            ]),
          ],
        ],
      ],
    ];
  }

}
