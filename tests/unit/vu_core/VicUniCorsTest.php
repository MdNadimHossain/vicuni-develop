<?php

use PHPUnit\Framework\TestCase;

/**
 * Class VicUniCorsTestCase.
 */
class VicUniCorsTestCase extends TestCase {

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    require_once sprintf('%s/%s', getcwd(), 'docroot/profiles/vicuni/modules/custom/vu_core/includes/_cors.inc');
  }

  /**
   * Ensure headers contain expected CORS value.
   *
   * @dataProvider providerCors
   */
  public function testCors($path, $request_origin, $cors_config, $expected) {
    $actual = _vu_core_cors_header_prepare_for_path($path, $request_origin, $cors_config);
    $this->assertEquals($expected, $actual);
  }

  /**
   * Cors data provider.
   */
  public function providerCors() {
    $cors_config = [
      'node/123' => [
        'campaign.vu.edu.au',
        'cors.vu.edu.au',
      ],
      'node/234' => [
        'a.vu.edu.au',
      ],
    ];
    $header_name = 'Access-Control-Allow-Origin';
    return [
      // Path and domain match (first array item).
      [
        'node/123',
        'https://campaign.vu.edu.au',
        $cors_config,
        [
          'name' => $header_name,
          'value' => 'https://campaign.vu.edu.au',
        ],
      ],
      // Path and domain match (second array item).
      [
        'node/123',
        'https://cors.vu.edu.au',
        $cors_config,
        [
          'name' => $header_name,
          'value' => 'https://cors.vu.edu.au',
        ],
      ],
      // Path matches partially, domain matches.
      [
        'node/1234',
        'https://campaign.vu.edu.au',
        $cors_config,
        [],
      ],
      // Domain matches partially, path matches.
      [
        'node/123',
        'https://cors.vu.edu.au.net',
        $cors_config,
        [],
      ],
      // Domain matches partially, path matches.
      [
        'node/234',
        'https://bla.vu.edu.au',
        $cors_config,
        [],
      ],
      // Path and domain match (second path item).
      [
        'node/234',
        'https://a.vu.edu.au',
        $cors_config,
        [
          'name' => $header_name,
          'value' => 'https://a.vu.edu.au',
        ],
      ],
      // Path partial match, but with sub path.
      [
        'node/234/done',
        'https://a.vu.edu.au',
        $cors_config,
        [
          'name' => $header_name,
          'value' => 'https://a.vu.edu.au',
        ],
      ],
    ];
  }

}
