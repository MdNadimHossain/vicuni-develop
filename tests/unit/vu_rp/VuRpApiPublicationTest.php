<?php

/**
 * Class VuRpApiPublicationTest.
 */
class VuRpApiPublicationTest extends VuRpApiTestCase {

  /**
   * @dataProvider providePublicationsConvert
   */
  public function testPublicationsConvert($data, $expected) {
    $actual = vu_rp_api_convert_publications($data);
    $this->assertEquals($expected, $actual);
  }

  public function providePublicationsConvert() {
    return [
      [NULL, []],

      [
        [
          $this->getPublication('Book'),
        ],
        [
          'Book' => [
            'items' => [
              $this->getPublication('Book'),
            ],
            'total' => 1,
          ],
        ],
      ],

      // Filtering.
      [
        [
          $this->getPublication('Other type'),
        ],
        [],
      ],

      // Ordering within the same type.
      [
        [
          $this->getPublication('Book', ['publicationDate' => '20150901']),
          $this->getPublication('Book', ['publicationDate' => '20150902']),
        ],

        [
          'Book' => [
            'items' => [
              $this->getPublication('Book', ['publicationDate' => '20150902']),
              $this->getPublication('Book', ['publicationDate' => '20150901']),
            ],
            'total' => 2,
          ],
        ],
      ],

      // Multiple types + filtering.
      [
        [
          $this->getPublication('Book chapter', ['publicationDate' => '20150905']),
          $this->getPublication('Book', ['publicationDate' => '20150901']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150903']),
          $this->getPublication('Book', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150906']),
        ],

        [
          'Book' => [
            'items' => [
              $this->getPublication('Book', ['publicationDate' => '20150902']),
              $this->getPublication('Book', ['publicationDate' => '20150901']),
            ],
            'total' => 2,
          ],
          'Book chapter' => [
            'items' => [
              $this->getPublication('Book chapter', ['publicationDate' => '20150906']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150905']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150903']),
            ],
            'total' => 3,
          ],
        ],
      ],

      // Multiple types + filtering + more then 10.
      [
        [
          $this->getPublication('Book chapter', ['publicationDate' => '20150901']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150902']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150903']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150904']),
          $this->getPublication('Book', ['publicationDate' => '20150901']),
          $this->getPublication('Book', ['publicationDate' => '20150902']),
          $this->getPublication('Book', ['publicationDate' => '20150903']),
          $this->getPublication('Book', ['publicationDate' => '20150904']),
          $this->getPublication('Book', ['publicationDate' => '20150905']),
          $this->getPublication('Book', ['publicationDate' => '20150906']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150905']),
          $this->getPublication('Book', ['publicationDate' => '20150907']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150906']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150907']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150908']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150909']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150910']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150911']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150912']),
        ],

        [
          'Book' => [
            'items' => [
              $this->getPublication('Book', ['publicationDate' => '20150907']),
              $this->getPublication('Book', ['publicationDate' => '20150906']),
            ],
            'total' => 7,
          ],
          'Book chapter' => [
            'items' => [
              $this->getPublication('Book chapter', ['publicationDate' => '20150912']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150911']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150910']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150909']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150908']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150907']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150906']),
              $this->getPublication('Book chapter', ['publicationDate' => '20150905']),
            ],
            'total' => 12,
          ],
        ],
      ],

      // Multiple types + filtering + more then 10 + favourites (12).
      [
        [
          $this->getPublication('Book chapter', ['publicationDate' => '20150901']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150902', 'favouritePublication' => TRUE]),
          $this->getPublication('Book chapter', ['publicationDate' => '20150903']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150904', 'favouritePublication' => TRUE]),
          $this->getPublication('Book', ['publicationDate' => '20150901', 'favouritePublication' => TRUE]),
          $this->getPublication('Book', ['publicationDate' => '20150902']),
          $this->getPublication('Book', ['publicationDate' => '20150903', 'favouritePublication' => TRUE]),
          $this->getPublication('Book', ['publicationDate' => '20150904', 'favouritePublication' => TRUE]),
          $this->getPublication('Book', ['publicationDate' => '20150905', 'favouritePublication' => TRUE]),
          $this->getPublication('Book', ['publicationDate' => '20150906']),
          $this->getPublication('Book', ['publicationDate' => '20150907', 'favouritePublication' => TRUE]),
          $this->getPublication('Book', ['publicationDate' => '20150908']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902', 'favouritePublication' => TRUE]),
          $this->getPublication('Book chapter', ['publicationDate' => '20150905']),
          $this->getPublication('Book', ['publicationDate' => '20150909']),
          $this->getPublication('Custom type', ['publicationDate' => '20150902', 'favouritePublication' => TRUE]),
          $this->getPublication('Book chapter', ['publicationDate' => '20150906']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150907', 'favouritePublication' => TRUE]),
          $this->getPublication('Book chapter', ['publicationDate' => '20150908']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150909', 'favouritePublication' => TRUE]),
          $this->getPublication('Book chapter', ['publicationDate' => '20150910']),
          $this->getPublication('Book chapter', ['publicationDate' => '20150911', 'favouritePublication' => TRUE]),
          $this->getPublication('Book chapter', ['publicationDate' => '20150912', 'favouritePublication' => TRUE]),
        ],

        [
          'Book' => [
            'items' => [
              $this->getPublication('Book', ['publicationDate' => '20150907', 'favouritePublication' => TRUE]),
              $this->getPublication('Book', ['publicationDate' => '20150905', 'favouritePublication' => TRUE]),
              $this->getPublication('Book', ['publicationDate' => '20150904', 'favouritePublication' => TRUE]),
              $this->getPublication('Book', ['publicationDate' => '20150903', 'favouritePublication' => TRUE]),
            ],
            'total' => 9,
          ],
          'Book chapter' => [
            'items' => [
              $this->getPublication('Book chapter', ['publicationDate' => '20150912', 'favouritePublication' => TRUE]),
              $this->getPublication('Book chapter', ['publicationDate' => '20150911', 'favouritePublication' => TRUE]),
              $this->getPublication('Book chapter', ['publicationDate' => '20150909', 'favouritePublication' => TRUE]),
              $this->getPublication('Book chapter', ['publicationDate' => '20150907', 'favouritePublication' => TRUE]),
              $this->getPublication('Book chapter', ['publicationDate' => '20150904', 'favouritePublication' => TRUE]),
              $this->getPublication('Book chapter', ['publicationDate' => '20150902', 'favouritePublication' => TRUE]),
            ],
            'total' => 12,
          ],
        ],
      ],
    ];
  }

}
