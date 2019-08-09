<?php

/**
 * @file
 * Unit tests related to functions in vu_courses.theme.inc.
 */

require 'docroot/profiles/vicuni/modules/custom/vu_courses/theme/templates/vu_courses.theme.inc';

/**
 * @class VuCoursesThemeTest
 */
class VuCoursesThemeTest extends VicUniTestCase {

  public function setUp() {
    $this->updateSnapshot();
    $this->loadSnapshot();
  }

  /**
   * @var string
   * Path to example XML used to generate snapshots for testing.
   */
  static private $exampleXmlFilePath = __DIR__ . '/fixtures/international-courses.xml';

  /**
   * @var string
   * Path to generated snapshots used for testing.
   */
  static private $snapshotFilePath = __DIR__ . '/fixtures/fees.csv';

  /**
   * Generate updated snapshot from inernational course XML.
   *
   * Place the international XML in the fixtures directory to generate updated
   * examples. This will only update the examples if the XML is present.
   * Once examples have been updated remove the XML file.
   *
   * Do commit the generated snapshot file, but do not commit the XML.
   */
  private function updateSnapshot() {
    if (!file_exists(self::$exampleXmlFilePath)) {
      return;
    }
    $xml = simplexml_load_file(self::$exampleXmlFilePath);
    $examples = [];
    foreach ($xml->course as $course) {
      $fees = $course->fees->asXML();
      if (!isset($examples[$fees])) {
        $out1 = vu_courses_international_fees_from_node($this->makeNode($fees));
        $out2 = serialize(vu_courses_international_fees_formatter($fees));
        $examples[$fees] = [$fees, $out1, $out2];
      }
    }
    $csv = fopen(self::$snapshotFilePath, 'w');
    foreach ($examples as $example) {
      fputcsv($csv, $example);
    }
    fclose($csv);
  }

  /**
   * Load exmaples from generated snapshot CSV.
   */
  private function loadSnapshot() {
    $csv = fopen(self::$snapshotFilePath, 'r');
    $this->examples = [];
    while ($example = fgetcsv($csv)) {
      $this->examples[] = $example;
    }
  }

  /**
   * Create a fake node to supply to the function to test.
   */
  private function makeNode($xml) {
    $lang = 'EN';
    $node = new StdClass();
    $node->language = $lang;
    $node->field_international_fees = [$lang => [0 => ['value' => $xml]]];
    return $node;
  }

  /**
   * Test passing fake node object.
   */
  public function testInternationalFeesNodeVars() {
    foreach ($this->examples as $example) {
      list($xml, $expected_result) = $example;
      $node = $this->makeNode($xml);
      $actual_result = vu_courses_international_fees_from_node($node);
      $this->assertEquals($expected_result, $actual_result);
    }
  }

  /**
   * Test accessing formatter directly (Study area pages do this.)
   */
  public function testInternationalFeesFormatter() {
    foreach ($this->examples as $example) {
      list($xml,, $expected_result) = $example;
      $actual_result = serialize(vu_courses_international_fees_formatter($xml));
      $this->assertEquals($expected_result, $actual_result);
    }
  }

}
