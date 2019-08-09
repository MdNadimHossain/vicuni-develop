<?php

/**
 * Class VuRpApiCitationTest.
 */
class VuRpApiCitationTest extends VuRpApiTestCase {

  /**
   * @dataProvider providerParseAuthors
   */
  public function testParseAuthors($authors, $expected) {
    $actual = _vu_rp_api_render_publications_authors($authors);
    $this->assertSame($expected, $actual);
  }

  public function providerParseAuthors() {
    return [
      [NULL, []],
      ['', []],
      [FALSE, []],
      [[], []],

      [
        [
          'Author1',
        ],
        [
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author1',
          ],
        ],
      ],

      [
        [
          'Author1',
          'Author2',
        ],
        [
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author1',
          ],
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author2',
          ],
        ],
      ],

      [
        [
          'Author1 F',
          'Author2 FM',
          'Author3 FnM',
          'Author4 FMn',
          'Author5 FnaMn',
          'Author6 FnaMna',
        ],
        [
          [
            'first_name' => 'F',
            'middle_name' => '',
            'last_name' => 'Author1',
          ],
          [
            'first_name' => 'F',
            'middle_name' => 'M',
            'last_name' => 'Author2',
          ],
          [
            'first_name' => 'Fn',
            'middle_name' => 'M',
            'last_name' => 'Author3',
          ],
          [
            'first_name' => 'F',
            'middle_name' => 'Mn',
            'last_name' => 'Author4',
          ],
          [
            'first_name' => 'Fna',
            'middle_name' => 'Mn',
            'last_name' => 'Author5',
          ],
          [
            'first_name' => 'Fna',
            'middle_name' => 'Mna',
            'last_name' => 'Author6',
          ],
        ],
      ],

    ];
  }

  /**
   * @dataProvider providerRenderAuthors
   */
  public function testRenderAuthors($authors, $expected) {
    $actual = _vu_rp_api_render_publications_authors_list($authors);
    $this->assertSame($expected, $actual);
  }

  public function providerRenderAuthors() {
    return [
      [NULL, ''],
      ['', ''],
      [FALSE, ''],
      [[], ''],

      [
        [
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author1',
          ],
        ],
        'Author1',
      ],

      [
        [
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author1',
          ],
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author2',
          ],
        ],
        'Author1, & Author2',
      ],

      [
        [
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author1',
          ],
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author2',
          ],
          [
            'first_name' => '',
            'middle_name' => '',
            'last_name' => 'Author3',
          ],
        ],
        'Author1, Author2, & Author3',
      ],

      [
        [
          [
            'first_name' => 'F',
            'middle_name' => '',
            'last_name' => 'Author1',
          ],
        ],
        'Author1, F.',
      ],

      [
        [
          [
            'first_name' => 'F',
            'middle_name' => 'M',
            'last_name' => 'Author1',
          ],
          [
            'first_name' => 'Fn',
            'middle_name' => 'Mn',
            'last_name' => 'Author2',
          ],
        ],
        'Author1, F. M., & Author2, Fn. Mn.',
      ],

      [
        [
          [
            'first_name' => 'F',
            'middle_name' => 'M',
            'last_name' => 'Author1',
          ],
          [
            'first_name' => 'Fn',
            'middle_name' => 'Mn',
            'last_name' => 'Author2',
          ],
          [
            'first_name' => 'Fna',
            'middle_name' => 'Mna',
            'last_name' => 'Author3',
          ],
        ],
        'Author1, F. M., Author2, Fn. Mn., & Author3, Fna. Mna.',
      ],
    ];
  }

  /**
   * @dataProvider providerCitation
   */
  public function testCitation($publication, $expected) {
    $actual = _vu_rp_api_render_publication_citation($publication);
    $this->assertEquals($expected, $actual);
  }

  public function providerCitation() {
    return [
      [NULL, ''],
      ['', ''],
      [FALSE, ''],
      [[], ''],

      // Book.
      [
        $this->getPublication('Book'),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). <em>Test publication title</em> (Edition 1). Editor, F. (Ed.). Location 1: Some publisher 1.',
      ],
      // No optional data.
      [
        $this->getPublication('Book', [
          'editor' => NULL,
          'edition' => NULL,
          'location' => NULL,
          'publisher' => NULL,
        ]),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). <em>Test publication title</em>.',
      ],
      // Editor is one of the authors.
      [
        $this->getPublication('Book', [
          'editor' => 'Author2 FnM',
        ]),
        'Author1, F. M., Author2, Fn. M., & Author3. (Eds.). (150901). <em>Test publication title</em> (Edition 1). Location 1: Some publisher 1.',
      ],
      // No editors.
      [
        $this->getPublication('Book', [
          'editor' => NULL,
        ]),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). <em>Test publication title</em> (Edition 1). Location 1: Some publisher 1.',
      ],

      // Book Chapter.
      [
        $this->getPublication('Book Chapter'),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). <em>Test publication title</em> In Editor, F. (Ed.) (Edition 1) (pp. 20-105). Location 1: Some publisher 1.',
      ],
      // Editor is one of the authors.
      [
        $this->getPublication('Book Chapter', [
          'editor' => 'Author2 FnM',
        ]),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). <em>Test publication title</em> In Author2, Fn. M. (Ed.) (Edition 1) (pp. 20-105). Location 1: Some publisher 1.',
      ],
      // No editors.
      [
        $this->getPublication('Book Chapter', [
          'editor' => NULL,
        ]),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). <em>Test publication title</em> (Edition 1) (pp. 20-105). Location 1: Some publisher 1.',
      ],

      // Journal article.
      [
        $this->getPublication('Journal article'),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). Test publication title. <em>Journal title</em>, vol 1(issue 5), (20-105).',
      ],
      // No issue and vol.
      [
        $this->getPublication('Journal article', [
          'volume' => NULL,
          'issue' => NULL,
        ]),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). Test publication title. <em>Journal title</em>, (20-105).',
      ],

      // Research Report.
      [
        $this->getPublication('Research Report'),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). <em>Test publication title</em>. Location 1: Some publisher 1.',
      ],
      // No optional data.
      [
        $this->getPublication('Research Report', [
          'location' => NULL,
          'publisher' => NULL,
        ]),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). <em>Test publication title</em>.',
      ],

      // Conference Paper.
      [
        $this->getPublication('Conference Paper'),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). Title of paper 1 In Editor, F. (Ed.), Paper presented at Title of conference 1 (pp. 20-105). Location 1: Some publisher 1.',
      ],
      // No optional data.
      [
        $this->getPublication('Conference Paper', [
          'location' => NULL,
          'publisher' => NULL,
          'paginationBegin' => NULL,
          'paginationEnd' => NULL,
        ]),
        'Author1, F. M., Author2, Fn. M., & Author3. (150901). Title of paper 1 In Editor, F. (Ed.), Paper presented at Title of conference 1.',
      ],
    ];
  }

}
