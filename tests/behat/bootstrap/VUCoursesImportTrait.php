<?php

/**
 * @file
 * VU Courses Import trait for Behat testing.
 */

use Behat\Behat\Hook\Scope\ScenarioScope;

/**
 * Class VUCoursesImportTrait.
 */
trait VUCoursesImportTrait {

  /**
   * Create nodes to be used for the Feeds testing.
   *
   * @param \Behat\Behat\Hook\Scope\ScenarioScope $event
   *   The behat event object.
   *
   * @BeforeScenario @feeds
   */
  public static function beforeFeatureFeeds(ScenarioScope $event) {
    // Create a campus.
    $node = new stdClass();
    $node->type = 'campus';
    node_object_prepare($node);
    $node->title = 'Test campus';
    $node->status = 1;
    node_save($node);

    // Create units, unitsets and courses.
    $nodes = [
      'TEST-MAPPING-UNIT' => [
        'type' => 'unit',
        'status' => 1,
        'guid_type' => 'unit',
        'importer' => 'units',
      ],
      'TEST-MAPPING-UNITSET' => [
        'type' => 'unit_set',
        'status' => 1,
        'guid_type' => 'unitset',
        'importer' => 'unitsets',
      ],
      'TEST-WORKFLOW-EXISTS-1' => [
        'type' => 'courses',
        'status' => 0,
        'guid_type' => 'course',
        'importer' => 'courses',
      ],
      'TEST-WORKFLOW-EXISTS-2' => [
        'type' => 'courses',
        'status' => 1,
        'guid_type' => 'course',
        'importer' => 'courses',
      ],
      'TEST-WORKFLOW-EXISTS-3' => [
        'type' => 'courses',
        'status' => 1,
        'guid_type' => 'course',
        'importer' => 'courses',
      ],
      'TEST-FLAGS-1' => [
        'type' => 'courses',
        'status' => 0,
        'guid_type' => 'course',
        'importer' => 'courses',
        'flags' => TRUE,
        'handbookinclude' => 0,
        'courseoffered' => 0,
        'continuingstudent' => 1,
      ],
      'TEST-FLAGS-2' => [
        'type' => 'courses',
        'status' => 1,
        'guid_type' => 'course',
        'importer' => 'courses',
        'flags' => TRUE,
        'handbookinclude' => 1,
        'courseoffered' => 1,
        'continuingstudent' => 0,
      ],
      'TEST-FLAGS-NA' => [
        'type' => 'courses',
        'status' => 1,
        'guid_type' => 'course',
        'importer' => 'courses',
        'flags' => TRUE,
        'handbookinclude' => 1,
        'courseoffered' => 1,
        'continuingstudent' => 0,
      ],
    ];

    foreach ($nodes as $code => $data) {
      // Create a dummy node.
      $node = new stdClass();
      $node->type = $data['type'];
      $node->revision = 1;
      $node->revision_timestamp = REQUEST_TIME;
      node_object_prepare($node);
      $node->title = $code;
      $node->field_unit_code[LANGUAGE_NONE][0]['value'] = $code;
      $node->field_domestic[LANGUAGE_NONE][0]['value'] = TRUE;
      $node->status = $data['status'];
      $node->workbench_moderation_state_current = workbench_moderation_state_none();

      if ($node->status) {
        $node->workbench_moderation_state_new = workbench_moderation_state_published();
      }
      if (isset($data['flags'])) {
        $node->field_handbook_include[LANGUAGE_NONE][0]['value'] = $data['handbookinclude'];
        $node->field_course_offered[LANGUAGE_NONE][0]['value'] = $data['courseoffered'];
        $node->field_continuing_student[LANGUAGE_NONE][0]['value'] = $data['continuingstudent'];
      }
      node_save($node);

      // Create an entry in the feeds item table.
      $feeds_item = [
        'entity_type' => 'node',
        'entity_id' => $node->nid,
        'id' => $data['importer'],
        'feed_nid' => 0,
        'imported' => REQUEST_TIME,
        'url' => '',
        'guid' => "{$data['guid_type']}-{$code}",
        'hash' => '',
      ];
      drupal_write_record('feeds_item', $feeds_item);
    }
  }

  /**
   * Cleanup nodes be used for the Feeds testing.
   *
   * @param \Behat\Behat\Hook\Scope\ScenarioScope $event
   *   The behat event object.
   *
   * @AfterScenario @feeds
   */
  public static function afterFeatureFeeds(ScenarioScope $event) {
    // Cleanup all nodes with a course code beginning with 'TEST-'.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->fieldCondition('field_unit_code', 'value', 'TEST-', 'STARTS_WITH')
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT')
      ->execute();
    if (isset($result['node']) && is_array($result['node'])) {
      node_delete_multiple(array_keys($result['node']));
    }

    // Delete test campus.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'campus')
      ->propertyCondition('title', 'Test campus')
      ->execute();
    if (isset($result['node']) && is_array($result['node'])) {
      node_delete_multiple(array_keys($result['node']));
    }
  }

}
