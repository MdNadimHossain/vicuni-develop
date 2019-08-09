<?php

/**
 * @file
 * VU Drupal context for Behat testing.
 */

use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
use Drupal\drupal_helpers\Menu;
use Drupal\drupal_helpers\Module;
use Drupal\DrupalExtension\Context\DrupalContext;
use IntegratedExperts\BehatSteps\D7\ContentTrait;
use IntegratedExperts\BehatSteps\D7\EmailTrait;
use IntegratedExperts\BehatSteps\D7\OverrideTrait;
use IntegratedExperts\BehatSteps\D7\ParagraphsTrait;
use IntegratedExperts\BehatSteps\D7\TaxonomyTrait;
use IntegratedExperts\BehatSteps\D7\UserTrait;
use IntegratedExperts\BehatSteps\D7\VariableTrait;
use IntegratedExperts\BehatSteps\D7\WatchdogTrait;
use IntegratedExperts\BehatSteps\FieldTrait;

/**
 * Defines application features from the specific context.
 *
 * READ ME!
 *
 * If you need to extend this class for a specific use case (Feeds, etc) make
 * a Trait and 'use' it below. This class should contain generic/re-usable
 * methods only.
 */
class VUDrupalContext extends DrupalContext implements SnippetAcceptingContext {

  use ContentTrait;
  use FieldTrait;
  use OverrideTrait;
  use ParagraphsTrait;
  use TaxonomyTrait;
  use UserTrait;
  use VariableTrait;
  use WatchdogTrait;
  use EmailTrait;

  // Bean trait.
  use VUBeanTrait;

  // Courses import trait.
  use VUCoursesImportTrait;

  // Rapid login trait.
  use VicUni\FastLoginTrait;

  use VURpApiTrait {
    VURpApiTrait::__construct as private __vuRpApiConstruct;
  }

  /**
   * VUDrupalContext constructor.
   */
  public function __construct() {
    $this->__vuRpApiConstruct(vu_rp_test_variable_name_is_test_mode(), vu_rp_test_variable_name_test_rest_responses_list());
  }

  /**
   * Keep track of saved entities so they can be cleaned up.
   *
   * @var array
   */
  protected $savedEntities = [];

  /**
   * Keep track of saved intakes so they can be cleaned up.
   *
   * @var array
   */
  protected $savedIntakes = [];

  /**
   * Keep track of overridden feature switch values.
   *
   * @var array
   */
  protected $switchStates = [];

  /**
   * Current theme.
   *
   * @var string
   */
  private $theme = '';

  /**
   * Navigate to the most recent published content of specified type.
   *
   * Caveat: If it's an course with field_international = 1, it will
   * return the URL for the international version. To avoid this behaviour
   * (but still selecting an international course) include both
   * field_international = 1 and field_domestic = 1.
   *
   * @param string $name
   *   Human-readable content type name.
   * @param string|array $fields
   *   Step definition list of fields (or array of field names).
   *
   * @throws \Exception
   *
   * @When /^I visit a page of ([a-zA-Z].*) content type(?:|\swith filled fields ([a-zA-Z0-9\s,\_]+))$/
   */
  public function iVisitPageOfContentTypeWithFilledFields($name, $fields = NULL) {
    $url = getenv('BEHAT_CONTENT_URL');

    if (!empty($url)) {
      $url = $this->getMinkParameter('base_url') . $url;
    }
    else {
      $field_names = $this->parseSubjects($fields);
      $content_type = $this->getContentType($name);

      // Only include published nodes.
      $published = [
        'condition_type' => 'propertyCondition',
        'field_name' => 'status',
        'value' => 1,
      ];
      $field_names[] = $published;
      $nodes = self::getNodesWithFilledFields($content_type->type, $field_names);

      if (empty($nodes)) {
        throw new \Exception(sprintf("No published content of type '%s'.", $content_type->type));
      }

      $node = reset($nodes);

      $url = $this->getMinkParameter('base_url') . '/node/' . $node->nid;
    }

    print $url;

    $this->getSession()->visit($url);
  }

  /**
   * Parse step definition subjects into array.
   */
  protected function parseSubjects($subjects) {
    return is_string($subjects) ? preg_split("/\s*(,|and)\s*/", $subjects) : [];
  }

  /**
   * Get content type by name.
   *
   * @param string $name
   *   Human-readable content type name.
   *
   * @return object
   *   Content type object.
   *
   * @throws Exception
   *   When content type does not exist.
   */
  protected function getContentType($name) {
    $content_type = NULL;

    $node_types = node_type_get_types();
    $node_type_names = [];
    foreach ($node_types as $node_type) {
      $node_type_names[] = $node_type->name;
      if (strtolower($name) == strtolower($node_type->name)) {
        $content_type = $node_type;
        break;
      }
    }

    if (!$content_type) {
      throw new \Exception(sprintf("Unknown content type '%s'. Available content types are: %s", $content_type, implode(', ', $node_type_names)));
    }

    return $content_type;
  }

  /**
   * Get nodes with non-empty fields.
   *
   * @param string $node_type
   *   Human-readable content type name.
   * @param array $fields
   *   Optional array of field names.
   * @param int $limit
   *   Optional quantity of nodes to return. Defaults to 1.
   *
   * @return array
   *   Array of found nodes, keyed by nid or empty array if no nodes found.
   */
  protected static function getNodesWithFilledFields($node_type, $fields = [], $limit = 1) {
    $query = new EntityFieldQuery();
    $query = $query->entityCondition('entity_type', 'node');
    $query = $query->entityCondition('bundle', $node_type);
    foreach ($fields as $field) {
      if (is_array($field)) {
        $condition_type = isset($field['condition_type']) ? $field['condition_type'] : 'fieldCondition';
        switch ($condition_type) {
          case 'propertyCondition':
            $query = $query->{$condition_type}($field['field_name'], $field['value']);
            break;

          case 'fieldCondition':
          default:
            $query = $query->{$condition_type}($field['field_name'], 'value', $field['value']);
        }
      }
      else {
        $query = $query->fieldCondition($field);
      }
    }

    $query = $query->propertyOrderBy('changed');
    $query = $query->range(0, $limit);
    $query = $query->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

    $result = $query->execute();

    return isset($result['node']) ? $result['node'] : [];
  }

  /**
   * Execute an EntityFieldQuery.
   */
  protected function doEntityFieldQuery($entity_type, $bundle, $field_name, $field_value) {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', $entity_type)
      ->entityCondition('bundle', $bundle)
      ->fieldCondition($field_name, 'value', $field_value)
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT')
      ->execute();

    return $result;
  }

  /**
   * Asserts an entities published status.
   *
   * @Then the :bundle :entity_type where :field_name is :field_value should have :count result.
   * @Then the :bundle :entity_type where :field_name is :field_value should have :count results.
   */
  public function assertEfqResultCount($entity_type, $bundle, $field_name, $field_value, $count) {
    $result = $this->doEntityFieldQuery($entity_type, $bundle, $field_name, $field_value);
    $results = !isset($result[$entity_type]) || empty($result[$entity_type]) ? 0 : count($result[$entity_type]);
    if ($results != $count) {
      throw new \Exception(sprintf('Query returned %d results.', $results));
    }
  }

  /**
   * Asserts an entities published status.
   *
   * @Then the :bundle :entity_type where :field_name is :field_value should be :status.
   */
  public function assertEfqResultStatus($entity_type, $bundle, $field_name, $field_value, $status) {
    if (!is_numeric($status)) {
      $status = $status == 'unpublished' ? 0 : 1;
    }

    $result = $this->doEntityFieldQuery($entity_type, $bundle, $field_name, $field_value);
    if (isset($result[$entity_type]) && is_array($result[$entity_type])) {
      $entity_id = key($result[$entity_type]);
      $entities = entity_load($entity_type, [$entity_id], [], TRUE);
      $entity = reset($entities);
      if (!isset($entity->status) || $entity->status != $status) {
        throw new \Exception(sprintf('Published status is incorrect: %s / %s', $entity->status, $status));
      }
    }
    else {
      throw new \Exception(sprintf('No results found matching your criteria.'));
    }
  }

  /**
   * Assert that the specified field on the EFQ returned entity has a value.
   *
   * @Then the :bundle :entity_type where :field_name is :field_value should have the following value in :field:
   *
   * @TODO: Merge share functionality with assertEntityFieldValue().
   */
  public function assertEntityFieldValue($entity_type, $bundle, $field_name, $field_value, $field, PyStringNode $data) {
    // Execute our EntityFieldQuery.
    $result = $this->doEntityFieldQuery($entity_type, $bundle, $field_name, $field_value);
    if (!isset($result[$entity_type]) || !is_array($result[$entity_type])) {
      throw new \Exception(sprintf('No results found matching your criteria.'));
    }

    // Load our entity.
    $entity_id = key($result[$entity_type]);
    $entities = entity_load($entity_type, [$entity_id], [], TRUE);
    $entity = reset($entities);

    // Use EntityMetadataWrapper.
    /** @var EntityDrupalWrapper $entity_wrapper */
    $entity_wrapper = entity_metadata_wrapper($entity_type, $entity);

    // Support for specific columns.
    $delta = 0;
    $column = NULL;
    if (strstr($field, ':')) {
      list($field, $delta, $column) = explode(':', $field, 3);
    }

    // Get the value via the Entity API.
    $value = $entity_wrapper->{$field}->value();
    if (!is_null($column) && isset($value[$column])) {
      $value = $value[$column];
    }

    // Ensure we're not dealing with an array.
    // @TODO - Add support for targetting a delta on a multivalue field.
    if (is_array($value)) {
      if (is_array($value)) {
        if (isset($value[$delta])) {
          $value = $value[$delta];
        }
        else {
          $value = reset($value);
        }
      }
    }

    // Deal with referenced entities.
    if (is_object($value)) {
      $value = $entity_wrapper->{$field}[$delta]->{$column}->value();
    }

    // Assert our values match.
    if ($value != $data->getRaw()) {
      throw new \Exception(sprintf("Entity's field '%s' value is '%s' not '%s'.", $field, $value, $data->getRaw()));
    }
  }

  /**
   * Assert that the EFQ returned entity has supplied field values.
   *
   * @Then the :bundle :entity_type where :field_name is :field_value should have the following data:
   */
  public function assertEntityFieldValues($entity_type, $bundle, $field_name, $field_value, TableNode $data) {
    // Execute our EntityFieldQuery.
    $result = $this->doEntityFieldQuery($entity_type, $bundle, $field_name, $field_value);
    if (!isset($result[$entity_type]) || !is_array($result[$entity_type])) {
      throw new \Exception(sprintf('No results found matching your criteria.'));
    }

    // Load our entity.
    $entity_id = key($result[$entity_type]);
    $entities = entity_load($entity_type, [$entity_id], [], TRUE);
    $entity = reset($entities);

    // Use EntityMetadataWrapper.
    /** @var EntityDrupalWrapper $entity_wrapper */
    $entity_wrapper = entity_metadata_wrapper($entity_type, $entity);

    foreach ($data->getHash() as $item) {
      // Support for specific columns.
      $field = $item['field'];
      $delta = 0;
      $column = NULL;
      if (strstr($field, ':')) {
        list($field, $delta, $column) = explode(':', $field, 3);
      }

      // Get the value via the Entity API.
      $value = $entity_wrapper->{$field}->value();
      if (!is_null($column) && isset($value[$column])) {
        $value = $value[$column];
      }

      // Ensure we're not dealing with an array.
      // @TODO - Add support for targetting a delta on a multivalue field.
      if (is_array($value)) {
        if (isset($value[$delta])) {
          $value = $value[$delta];
        }
        else {
          $value = reset($value);
        }
      }

      // Deal with referenced entities.
      if (is_object($value)) {
        $value = $entity_wrapper->{$field}[$delta]->{$column}->value();
      }

      // Assert our values match.
      if ($value != $item['value']) {
        throw new \Exception(sprintf("Entity's field '%s' value is '%s' not '%s'.", $item['field'], $value, $item['value']));
      }
    }
  }

  /**
   * Creates a "Courses" node with pre-populated fields.
   *
   * Fields to be provided in the form:
   * | title     | My node        |
   * | Field One | My field value |
   * | author    | Joe Editor     |
   * | status    | 1              |
   * | ...       | ...            |
   * .
   *
   * @Given I am viewing a published short course:
   */
  public function iAmViewingPublishedShortCourse(TableNode $fields) {
    // This step requires a logged-in user, as per iLogInAs().
    if (!isset($this->getUserManager()->getCurrentUser()->uid)) {
      throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
    }

    $node = new stdClass();
    $node->type = 'courses';
    $node->field_unit_lev = 'short';
    $node->uid = $this->getUserManager()->getCurrentUser()->uid;

    node_object_prepare($node);

    foreach ($fields->getRowsHash() as $field => $value) {
      $node->{$field} = $value;
    }

    $node->workbench_moderation_state_current = workbench_moderation_state_none();

    $saved = $this->nodeCreate($node);

    // Add required fields so the course wil display correctly.
    $saved = $this->populateCourseRequiredFieldsStubs($saved);

    // Publish the node using workbench_moderation.
    $saved->workbench_moderation_state_new = workbench_moderation_state_published();
    $saved->revision = 1;
    $saved->revision_timestamp = REQUEST_TIME;
    $saved->log = 'State Changed to published';
    node_save($saved);

    // Set internal browser on the node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }

  /**
   * Creates a "Courses" node with pre-populated fields.
   *
   * Fields to be provided in the form:
   * | title     | My node        |
   * | Field One | My field value |
   * | author    | Joe Editor     |
   * | status    | 1              |
   * | ...       | ...            |
   * .
   *
   * @Given I am viewing a draft revision of a published course:
   */
  public function iAmViewingDraftRevisionOfPublishedCourse(TableNode $fields) {
    // This step requires a logged-in user, as per iLogInAs().
    if (!isset($this->getUserManager()->getCurrentUser()->uid)) {
      throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
    }
    $node = (object) [
      'type' => 'courses',
      'uid' => $this->getUserManager()->getCurrentUser()->uid,
      'path' => [
        'pathauto' => 1,
      ],
    ];

    $node->workbench_moderation_state_current = workbench_moderation_state_none();

    // Forcefully set the original node timestamp as 12 hours ago so that it
    // closely mimics real usage.
    $node->_timestamp = REQUEST_TIME - 43200;
    foreach ($fields->getRowsHash() as $field => $value) {
      if (strpos($field, ':') !== FALSE) {
        continue;
      }
      $node->{$field} = $value;
    }
    $node->log = 'Initially created with status Draft';
    $saved = $this->nodeCreate($node);

    // Add stub values for required courses fields so the course would display
    // correctly.
    $saved = $this->populateCourseRequiredFieldsStubs($saved);

    // Override stub values with provided fields, if any.
    foreach ($fields->getRowsHash() as $field => $value) {
      // Explode field components and set them properly.
      if (strpos($field, ':') !== FALSE) {
        $parts = explode(':', $field);
        $field = reset($parts);
        $value_field = end($parts);
        $saved->{$field}[$saved->language][0][$value_field] = $value;
      }
      elseif (is_array($saved->{$field})) {
        $saved->{$field}[$saved->language][0]['value'] = $value;
      }
    }

    // Publish the node using workbench_moderation.
    $saved->workbench_moderation_state_new = workbench_moderation_state_published();
    $saved->revision = 1;
    // Set the published revision as 6 hours ago so that it closely mimics real
    // usage.
    $saved->changed = $saved->revision_timestamp = REQUEST_TIME - 21600;
    $saved->log = 'State changed to Published';
    node_save($saved);

    // Create another revision as a draft.
    $new_revision = node_load($saved->nid, $saved->vid, TRUE);
    $new_revision->workbench_moderation_state_new = workbench_moderation_state_none();
    $new_revision->revision = 1;
    $new_revision->log = t('New revision created with status Draft');
    node_save($new_revision);

    // @hack: Explicitly remove duplicated published revision from previous save
    // as Drafty module would do in cron. This is a hack to replicate Drafty's
    // behaviour to save on running cron within the test.
    // @see https://www.drupal.org/node/2579205
    drafty_queue_delete_revision([
      'entity_type' => 'node',
      'entity_id' => $saved->nid,
      'revision_id' => $saved->vid,
    ]);

    // Set internal browser on the draft of this node.
    $path = $this->locatePath('/node/' . $saved->nid);
    print $path;
    $this->getSession()->visit($path);
  }

  /**
   * Creates content of the given type.
   *
   * @Given I am viewing a course page with the title :title
   */
  public function iAmViewingCoursePageWithTitle($title) {
    // This step requires a logged-in user, as per iLogInAs().
    if (!isset($this->getUserManager()->getCurrentUser()->uid)) {
      throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
    }

    $node = new stdClass();
    $node->title = $title;
    $node->type = 'courses';
    $node->body = $this->getRandom()->name(255);
    $node->log = 'Initially created with status Draft';
    node_object_prepare($node);
    // Function node_object_prepare() sets uid to 0 which produces an error
    // so set uid to the current user.
    $node->uid = $this->getUserManager()->getCurrentUser()->uid;
    $node->workbench_moderation_state_current = workbench_moderation_state_none();

    $saved = $this->nodeCreate($node);

    // Add stub values for required courses fields so the course would display
    // correctly.
    $saved = $this->populateCourseRequiredFieldsStubs($saved);

    node_save($saved);

    // Set internal page on the new node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }

  /**
   * Helper method that adds required fields to a course node.
   *
   * @param object $node
   *   The node that will have fields added to it.
   *
   * @return mixed
   *   The node object with added fields
   */
  protected function populateCourseRequiredFieldsStubs($node) {
    // Retrieve the latest 'course_date_time' item for adding to this node.
    $entities = (new EntityFieldQuery)
      ->entityCondition('entity_type', 'inline_entities')
      ->entityCondition('bundle', 'course_date_time')
      ->pager(1)
      ->execute();
    $test_dates = reset($entities);
    $test_dates_entity_id = key($test_dates);

    $node->language = LANGUAGE_NONE;
    $node->field_domestic[$node->language][0]['value'] = TRUE;
    $node->field_imp_desc[$node->language][0]['safe_value'] = 'Test description ' . $this->getRandom()->string(8);
    $node->field_course_aqf[$node->language][0]['value'] = 'Course aqf ' . $this->getRandom()->string(8);
    $node->field_unit_code[$node->language][0]['value'] = 'A12345';
    $node->field_unit_lev[$node->language][0]['value'] = 'short';
    $node->field_short_dates_times[$node->language][0]['target_id'] = $test_dates_entity_id;
    $node->field_handbook_include[LANGUAGE_NONE][0]['value'] = 1;
    $node->field_course_offered[LANGUAGE_NONE][0]['value'] = 1;
    $node->field_continuing_student[LANGUAGE_NONE][0]['value'] = 0;
    $node->field_introduction[LANGUAGE_NONE][0]['format'] = 'filtered_html';

    $node->body[$node->language][0]['value'] = 'Node body ' . $this->getRandom()->name(255);

    return $node;
  }

  /**
   * Creates an entity of the given type.
   *
   * Fields and values provided in the form:
   * | title     | My entity      |
   * | Field One | My field value |
   * | ...       | ...            |
   * To specify a bundle, add it to the fields table as follow:
   * | type | bundle_name |
   *
   * @Given an entity of type :type with fields:
   */
  public function createEntity($entity_type, TableNode $table) {
    $entity_type_exists = entity_get_info($entity_type);
    if (empty($entity_type_exists)) {
      throw new \Exception(sprintf('Entity type (%s) does not exist.', $entity_type));
    }
    $entity = entity_create($entity_type, ['type' => $entity_type]);
    // @TODO: investigate potentially incorrect structure.
    foreach ($table->getRowsHash() as $field => $value) {
      $entity->{$field} = $value;
    }

    entity_save($entity_type, $entity);

    // Store the entity id so it could be deleted after scenario.
    $this->savedEntities[$entity_type][] = $entity->id;

    return $entity;
  }

  /**
   * Asserts viewing an entity of the given type.
   *
   * Fields and values provided in the form:
   * | title     | My entity      |
   * | Field One | My field value |
   * | ...       | ...            |
   *
   * @Given I am viewing an entity of the type :type with the content content:
   */
  public function iAmViewingEntityOfTypeWithContent($type, TableNode $table) {
    $entity = $this->createEntity($type, $table);
    $entity_uri = entity_uri($type, $entity);
    $this->getSession()->visit($this->locatePath($entity_uri['path']));
  }

  /**
   * Removes test entities.
   *
   * @AfterScenario
   */
  public function cleanEntities() {
    if (!empty($this->savedEntities)) {
      foreach ($this->savedEntities as $entity_type => $entities) {
        entity_delete_multiple($entity_type, $entities);
      }
    }
  }

  /**
   * Get content type from human readable name.
   *
   * @param string $name
   *   Human readable content type.
   *
   * @return string
   *   Returns the machine name of the content type.
   *
   * @throws \Exception
   */
  protected function getContentTypeMachineName($name) {
    $types = node_type_get_types();
    $type_machine_name = str_replace(' ', '_', strtolower($name));

    if (!isset($types[$type_machine_name])) {
      throw new \Exception(sprintf('Content type (%s) does not exist.', $name));
    }

    return $type_machine_name;
  }

  /**
   * Validates user access for content types.
   *
   * @Then /^(?:|I )(?P<assert>can|can\s?not) (?P<op>view|update|edit|create|delete) an? "(?P<type>(?:[^"]|\\")*)"$/
   */
  public function assertOpWithContentOfType($assert, $op, $type) {
    $assert = $assert === 'can';
    $op = $op === 'edit' ? 'update' : $op;

    return node_access($op, $this->getContentTypeMachineName($type), $this->getUserManager()->getCurrentUser()) === $assert;
  }

  /**
   * Validates user role access for workbench moderation.
   *
   * @Given a role :role_name :assert have the permission: :permission
   */
  public function assertRoleHasPermission($role_name, $assert, $permission) {
    $assert = $assert === 'does';

    $role = user_role_load_by_name($role_name);
    if (!$role) {
      throw new \Exception(sprintf('A role by this name does not exist'));
    }
    $rid = $role->rid;
    $roles = [$rid => $role->name];
    $permissions = user_role_permissions($roles);

    if (!array_key_exists($permission, $permissions[$rid])) {
      if ($assert) {
        throw new \Exception(sprintf("This role does not have the permission: '%s'", $permission));
      }
    }
    else {
      if (!$assert) {
        throw new \Exception(sprintf("This role does have the permission: '%s'", $permission));
      }
    }
  }

  /**
   * Validates user role access for input formats.
   *
   * @Given a role :role_name :assert use the input format: :format
   */
  public function assertRoleCanUseFormat($role_name, $assert, $format) {
    $assert = $assert === 'can';

    $role = user_role_load_by_name($role_name);
    if (!$role) {
      throw new \Exception(sprintf('A role by this name does not exist'));
    }

    $rid = $role->rid;
    $format_object = filter_format_load($format);

    if (!$format_object) {
      throw new \Exception(sprintf('An invalid input format.'));
    }

    $filter_roles = filter_get_roles_by_format($format_object);

    if (!array_key_exists($rid, $filter_roles)) {
      if ($assert) {
        throw new \Exception(sprintf("This role can not use the input format: '%s'", $format));
      }
    }
    else {
      if (!$assert) {
        throw new \Exception(sprintf("This role can use the input format: '%s'", $format));
      }
    }
  }

  /**
   * Ensures a sitemap.xml file is generated.
   *
   * @Given the XML sitemap has been created
   */
  public function generateSiteMap() {
    module_load_include('generate.inc', 'xmlsitemap');
    xmlsitemap_run_unprogressive_batch('xmlsitemap_regenerate_batch');
  }

  /**
   * Evaluate javascript statements.
   *
   * @param string $script
   *   The javascript statement to be evaluated.
   * @param string $value
   *   The expected return value.
   *
   * @throws \Exception
   *    When the expected value is not allowed or
   *    the returned value is not the expected one.
   *
   * @Then the javascript statement :script should return :value
   */
  public function assertJavaScriptStatement($script, $value) {
    // Only true or false values expected for now.
    // This can be extended at later stages.
    $allowed_values = ['true', 'false'];

    if (!in_array($value, $allowed_values)) {
      throw new \RuntimeException('Invalid value specified');
    }

    $result = $this->getSession()->getDriver()->evaluateScript($script);
    if ($result !== filter_var($value, FILTER_VALIDATE_BOOLEAN)) {
      throw new \Exception(sprintf('The returned value of "%s" is not "%s".', $script, $value));
    }
  }

  /**
   * Creates a page builder node with page sections.
   *
   * @Given I am editing a page_builder node with sample page sections and the title :title
   */
  public function createPageBuilderNode($title) {
    // This step requires a logged-in user, as per iLogInAs().
    if (!isset($this->getUserManager()->getCurrentUser()->uid)) {
      throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
    }
    $node = (object) [
      'title' => $title,
      'type' => 'page_builder',
      'body' => $this->getRandom()->name(255),
      'uid' => $this->getUserManager()->getCurrentUser()->uid,
    ];
    $saved = $this->nodeCreate($node);

    // Add Inline Entities to Page sections field.
    $entity_bundles = [
      'accordion_section',
      'basic_body_text',
      'course_date_time',
      'featured_content',
      'location',
      'related_links',
      'topic_page_content',
      'topic_page_sidebar_content',
      'featured_success_story',
      'link_redirects',
      'topic_page_facts',
    ];

    $delta = 0;
    foreach ($entity_bundles as $bundle) {
      $entity_id = $this->retrieveLatestInlineEntityByBundle($bundle);
      $saved->field_page_sections[LANGUAGE_NONE][$delta]['target_id'] = $entity_id;
      $delta++;
    }

    // Save the node.
    node_save($saved);

    // Allow time for the node to save before loading the edit page.
    $this->getSession()->wait(5000);

    // Set internal page on the new node.
    $this->getSession()
      ->visit($this->locatePath('/node/' . $saved->nid . '/edit'));
  }

  /**
   * Helper method that finds the latest inline entity in a bundle.
   *
   * @param string $bundle
   *   The entity bundle to filter the search by.
   *
   * @return int
   *   The ID of the fetched entity.
   *
   * @throws exception
   *   If no entity can be found.
   */
  public function retrieveLatestInlineEntityByBundle($bundle) {
    // Retrieve the latest item in a bundle.
    $entities = (new EntityFieldQuery)
      ->entityCondition('entity_type', 'inline_entities')
      ->entityCondition('bundle', $bundle)
      ->pager(1)
      ->execute();
    $entities = reset($entities);

    if (!is_array($entities)) {
      throw new \Exception(sprintf('An entity could not be found in the bundle "%s".', $bundle));
    }
    else {
      $entity_id = key($entities);
    }

    return $entity_id;
  }

  /**
   * Creates a published node with pre-populated fields.
   *
   * Fields to be provided in the form:
   * | title     | My node        |
   * | Field One | My field value |
   * | author    | Joe Editor     |
   * | status    | 1              |
   * | ...       | ...            |
   * .
   *
   * @Given I create a published :type with content:
   */
  public function assertCreatingPublishedNode($type, TableNode $fields) {
    // This step requires a logged-in user, as per iLogInAs().
    if (!isset($this->getUserManager()->getCurrentUser()->uid)) {
      throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
    }

    // This step requires a logged-in user, as per iLogInAs().
    if (!isset($this->getUserManager()->getCurrentUser()->uid)) {
      throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
    }

    $node = new stdClass();
    $node->workbench_moderation_state_current = workbench_moderation_state_none();
    $node->type = $this->getContentTypeMachineName($type);
    $node->path['pathauto'] = 1;
    $node->language = LANGUAGE_NONE;
    $node->uid = $this->getUserManager()->getCurrentUser()->uid;

    foreach ($fields->getRowsHash() as $field => $value) {
      $node->{$field} = $value;
    }

    $saved = $this->nodeCreate($node);

    // Publish the node using workbench_moderation.
    $saved->workbench_moderation_state_new = workbench_moderation_state_published();
    $saved->revision = 1;
    $saved->revision_timestamp = REQUEST_TIME;
    $saved->log = 'State Changed to published';
    node_save($saved);

    // Create another revision as a draft.
    $new_revision = node_load($saved->nid);
    $new_revision->workbench_moderation_state_new = workbench_moderation_state_none();
    $new_revision->revision = 1;
    $new_revision->revision_timestamp = REQUEST_TIME;
    $new_revision->log = t('New Draft Revision Created');
    node_save($new_revision);

    // Set internal browser on the node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }

  /**
   * View a published content of specified type and field values.
   *
   * @param string $type
   *   Human-readable content type name.
   * @param \Behat\Gherkin\Node\TableNode $conditions
   *   List of field conditions provided in the test step.
   *
   * @When I am viewing a page of :arg1 content type where:
   *
   * @throws Exception
   *   When a node is not found.
   */
  public function assertViewingNodeWithFields($type, TableNode $conditions) {
    $url = getenv('BEHAT_CONTENT_URL');

    if (!empty($url)) {
      $url = $this->getMinkParameter('base_url') . $url;
    }
    else {
      $content_type = $this->getContentType($type);
      $fields = [];
      $international_course = FALSE;
      $domestic_course = FALSE;
      foreach ($conditions->getHash() as $condition) {
        $field = [
          'field_name' => $condition['field'],
          'value' => $condition['value'],
        ];
        if ($condition['field'] === 'field_international' && $condition['value'] == TRUE) {
          $international_course = TRUE;
        }
        if ($condition['field'] === 'field_domestic' && $condition['value'] == TRUE) {
          $domestic_course = TRUE;
        }
        // Condition type is optional, will default to fieldCondition.
        if (isset($condition['condition type'])) {
          $field['condition_type'] = $condition['condition type'];
        }
        $fields[] = $field;
      }
      $nodes = self::getNodesWithFilledFields($content_type->type, $fields);

      if (empty($nodes)) {
        throw new \Exception(sprintf("No published content of type '%s'.", $content_type->type));
      }

      $node = reset($nodes);
      if (!$international_course || $domestic_course) {
        $url = $this->getMinkParameter('base_url') . '/node/' . $node->nid;
      }
      else {
        // Get international URL. :( .
        $node = node_load($node->nid, $node->vid);
        $url = $this->getMinkParameter('base_url') . '/courses/international/' . $node->field_unit_code[$node->language][0]['value'];
      }
    }

    print $url;

    $this->getSession()->visit($url);
  }

  /**
   * Ensure a feature switch is set to a specific value (eval to TRUE/FALSE).
   *
   * @param string $switch_name
   *   The feature switch name to set.
   * @param string $value
   *   The value to set the switch to (true false)
   *
   * @Given /^the feature switch ([^\s]+) is ([^\s]+)/
   */
  public function setFeatureSwitchValue($switch_name, $value) {
    // Turn value into a boolean. On, off, yes, no, true, false, 1, 0 are valid.
    $value = filter_var($value, FILTER_VALIDATE_BOOLEAN);

    $switch_val = vu_feature_switches_switch_state($switch_name);
    if ($switch_val !== $value) {
      if (isset($this->switchStates[$switch_name])) {
        vu_feature_switches_switch_toggle($switch_name, $this->switchStates[$switch_name]);
        unset($this->switchStates[$switch_name]);
      }

      $this->switchStates[$switch_name] = vu_feature_switches_switch_state($switch_name);
      vu_feature_switches_switch_toggle($switch_name, $value);
    }
  }

  /**
   * Reset feature switch values to their original states.
   *
   * @AfterScenario
   */
  public function resetFeatureSwitches($event) {
    if (empty($this->switchStates)) {
      return;
    }
    foreach ($this->switchStates as $switch_name => $original_state) {
      vu_feature_switches_switch_toggle($switch_name, $original_state);
    }
    // Remove all previously saved states.
    $this->switchStates = [];
  }

  /**
   * Creates course intake with given values.
   *
   * Fields and values provided in the form:
   * | title     | My entity      |
   * | Field One | My field value |
   * | ...       | ...            |
   *
   * @Given there is a course intake where:
   */
  public function createIntake(TableNode $table) {
    $year = date('Y');
    $year_start = date('Y') . '-01-01 00:00:00';
    $year_end = date('Y') . '-12-31 00:00:00';

    $intake_values = [
      'course_index_id' => 666,
      'academic_year' => $year,
      'academic_calendar_type' => 'ACAD-YR',
      'academic_calendar_sequence_number' => 666,
      'academic_start_date' => $year_start,
      'academic_end_date' => $year_end,
      'is_mid_year_intake' => 'N',
      'admissions_calendar_type' => 'ADM-VE-YR',
      'admissions_calendar_sequence_number' => 666,
      'admissions_start_date' => $year_start,
      'early_admissions_end_date' => $year_end,
      'admissions_end_date' => $year_end,
      'vtac_open_date' => $year_start,
      'vtac_timely_date' => $year_end,
      'vtac_late_date' => $year_end,
      'vtac_very_late_date' => $year_end,
      'admissions_category' => 'VE-DOM',
      'course_offering_id' => 666,
      'sector_code' => 'VET',
      'course_code' => 'TESTINTAKE',
      'course_version' => 1,
      'course_name' => 'TEST INTAKE',
      'is_vtac_course' => 'Y',
      'location' => 'G',
      'attendance_type' => 'FT',
      'attendance_mode' => 'ON',
      'course_type' => '666',
      'place_type' => 'VET',
      'specialisation_code' => '',
      'specialisation_name' => '',
      'unit_set_version' => 0,
      'course_intake_status' => 'OFFERED',
      'college' => 'B9',
      'college_name' => 'VICTORIA POLYTECHNIC',
      'is_admissions_centre_available' => 'Y',
      'additional_requirements' => '',
      'published_date' => $year_start,
      'created_date_time' => $year_start,
      'intake_enabled' => 1,
      'vtac_course_code' => 666,
      'application_entry_method' => 'DIRECT',
      'supplementary_forms' => 'O:8:"stdClass":0:{}',
      'referee_reports' => 'O:8:"stdClass":0:{}',
      'expression_of_interest' => 'N',
      'updated_date_time' => $year_start,
    ];

    // Update relative dates in the table.
    $table = new TableNode($this->replaceTableRelativeDates($table->getTable()));

    foreach ($table->getRowsHash() as $field => $value) {
      $intake_values[$field] = $value;
    }

    $insert_id = db_insert('course_intake')->fields($intake_values)->execute();
    $this->savedIntakes[] = $insert_id;
  }

  /**
   * Remove any created intakes.
   *
   * @AfterScenario
   */
  public function cleanIntakes() {
    if (empty($this->savedIntakes)) {
      return;
    }

    foreach ($this->savedIntakes as $intake_id) {
      db_delete('course_intake')->condition('id', $intake_id)->execute();
    }
    $this->savedIntakes = [];
  }

  /**
   * Create content with a vertical table of | field | value |.
   *
   * This is similar to assertViewingNode / createNodes. The additional
   * functionality is that we can use relative dates for date fields.
   * The relative dates are anything supported by strtotime.
   * Using relative_dt returns ISO datetime.
   * | title      | My node                     |
   * | Field Date | [relative:tomorrow 5pm]     |
   * | Field Date | [relative_dt:tomorrow 5pm]  |
   *
   * @Given :type content with fields:
   */
  public function createNodesWithFields($type, TableNode $fields) {
    $fields = new TableNode($this->replaceTableRelativeDates($fields->getTable()));

    $node = (object) [
      'type' => $type,
    ];
    foreach ($fields->getRowsHash() as $field => $value) {
      $node->{$field} = $value;
    }

    $this->nodeCreate($node);
  }

  /**
   * Updates the TableNode field relative values with real dates.
   */
  protected function replaceTableRelativeDates(array $table) {
    // Allow relative dates as field values.
    foreach ($table as &$values) {
      // | field_name | field_value |.
      foreach ($values as &$value) {
        $value = preg_replace_callback('/\[relative_?(dt)?:([^\]\[]+)\]/', function ($matches) {
          $timestamp = strtotime($matches[2]);
          if ($timestamp === FALSE) {
            throw new \RuntimeException(sprintf("The supplied relative date is invalid: '%s'", $matches[1]));
          }

          // If we want ISO/datetime format not timestamp.
          if (!empty($matches[1]) && $matches[1] == 'dt') {
            return date('Y-m-d H:i:s', $timestamp);
          }

          return $timestamp;
        }, $value);
      }
    }

    return $table;
  }

  /**
   * Enable the vu_core_test module.
   *
   * @BeforeScenario @VUTestModule
   */
  public function enableTestModule() {
    Module::enable('vu_core_test');
  }

  /**
   * Disable the vu_core_test module.
   *
   * @AfterScenario @VUTestModule
   */
  public function disableTestModule() {
    Module::disable('vu_core_test');
  }

  /**
   * Clear a specific view's cache (this can't be done on a display level).
   *
   * @When I clear the :view_name view cache
   */
  public function clearViewCache($view_name) {
    $table_name = 'cache_views_data';
    cache_clear_all($view_name . ':', $table_name, TRUE);
  }

  /**
   * Clear a specific path cache. May be volatile.
   *
   * @When I clear the :path page cache
   */
  public function clearPageCache($path) {
    $path = in_array($path, ['home', 'homepage']) ? '<front>' : $path;
    $url = url($path, ['absolute' => TRUE]);
    cache_clear_all($url, 'cache_page');
  }

  /**
   * @When I clear the theme cache
   */
  public function clearThemeCache() {
    registry_rebuild();
    // Fall-through to clear cache tables, since registry information is
    // usually the base for other data that is cached (e.g. SimpleTests).
    // Don't clear cache_form - in-progress form submissions may break.
    // Ordered so clearing the page cache will always be the last action.
    // @see drupal_flush_all_caches()
    $core = ['cache', 'cache_bootstrap', 'cache_filter', 'cache_page'];
    $cache_tables = array_merge(module_invoke_all('flush_caches'), $core);
    foreach ($cache_tables as $table) {
      cache_clear_all('*', $table, TRUE);
    }
    system_rebuild_theme_data();
    drupal_theme_rebuild();
  }

  /**
   * Ensure the correct theme is present.
   *
   * @Given I should see :theme theme
   */
  public function assertTheme($theme) {
    $page = $this->getSession()->getPage();
    $html = $page->getHtml();
    // Note: This searches for the presence of the favicon in the theme's
    // directory as `global $theme` and `menu_get_custom_theme()` fail to report
    // the active theme correctly.
    if (strpos($html, "{$theme}/favicon.ico") === FALSE) {
      throw new \Exception(sprintf("'%s' theme not detected.", $theme));
    }
  }

  /**
   * Searches in saved test nodes.
   *
   * @param string $value
   *   The search value.
   * @param string $field
   *   The node field.
   *
   * @return Mixed
   *   Returns node object or null.
   */
  public function findInSavedNodes($value, $field = 'title') {
    $node = NULL;
    if (!empty($value) && !empty($this->nodes)) {
      foreach ($this->nodes as $saved_node) {
        if ($value == $saved_node->{$field}) {
          $node = $saved_node;
          break;
        }
      }
    }

    return $node;
  }

  /**
   * Creates a menu structure.
   *
   * The menu structure is specified as:
   *  | title                       | parent_menu_item            | menu      |
   *  | [TEST] Level 2 Child Page 1 | [TEST] Level 1 Child Page 1 | main-menu |
   *  |   ...                       | ...                         | ...       |
   *
   * @Given I create the following menu structure:
   */
  public function iCreateTheFollowingMenuStructure(TableNode $table) {
    foreach ($table->getHash() as $item) {
      $title = $item['title'];
      $parent_title = $item['parent_menu_item'];
      $menu = $item['menu'];

      $saved_node = $this->findInSavedNodes($title);

      if (empty($saved_node)) {
        throw new \Exception(sprintf("'%s' has not been created yet. Please create the node first.", $title));
      }

      if (!empty($parent_title)) {
        $parent_node = $this->findInSavedNodes($parent_title);
        if (empty($parent_node)) {
          throw new \Exception(sprintf("'%s' has not been created yet. Please create the node first.", $parent_title));
        }
        $plid = Menu::findItem($menu, ['link_title' => $parent_node->title]);
      }

      $path = drupal_lookup_path('alias', 'node/' . $saved_node->nid);
      $node = node_load($saved_node->nid);
      $node->menu['path'] = $path;
      $node->menu['enabled'] = TRUE;
      $node->menu['link_title'] = $item['title'];
      $node->menu['description'] = '';
      $node->menu['plid'] = !empty($plid) ? $plid : Menu::findItem($menu, ['link_path' => '<front>']);
      node_save($node);
    }
  }

  /**
   * Creates a TAFE course with RHS information session block.
   *
   * @Given I am on a TAFE course that has a scheduled information session
   *
   * @throws Exception
   *   When a node or entity cannot be created.
   */
  public function assertTafeCourseWithInformationSession() {
    $node = (object) [
      'title' => 'Test tafe course',
      'type' => 'courses',
      'field_unit_lev' => 'tafe',
      'uid' => 1,
      'field_course_aqf' => 'Diploma',
    ];

    $node->workbench_moderation_state_current = workbench_moderation_state_none();
    $saved = $this->nodeCreate($node);

    // Add required fields so the course wil display correctly.
    $saved = $this->populateCourseRequiredFieldsStubs($saved);

    // Publish the node using workbench_moderation.
    $saved->workbench_moderation_state_new = workbench_moderation_state_published();
    $saved->revision = 1;
    $saved->revision_timestamp = REQUEST_TIME;
    $saved->field_unit_lev[$saved->language][0]['value'] = "tafe";
    $saved->field_short_dates_times = NULL;
    $saved->field_course_aqf[$saved->language][0]['value'] = "Diploma";
    $saved->field_college[$saved->language][0]['title'] = "VU Polytechnic";
    $saved->field_college[$saved->language][0]['url'] = "https://www.vupolytechnic.edu.au/";
    node_save($saved);
    $nid = $saved->nid;

    // Create an information session link entity and attach it to the course.
    $entity_type = 'course_information_session_links';
    try {
      $entity = entity_create($entity_type, ['type' => 'tafe_info_session_link']);
      $wrapper = entity_metadata_wrapper($entity_type, $entity);
      $wrapper->title = 'Test information session link';
      $wrapper->field_info_session_link->set(['url' => 'http://www.example.com']);
      $wrapper->field_related_courses->set([$nid]);
      $wrapper->save();
    }
    catch (EntityMetadataWrapperException $e) {
      throw new \Exception(sprintf('(%s) entity could not be created.', $entity_type));
    }

    // Add to savedEntities to be cleared after scenario.
    $this->savedEntities[$entity_type][] = $entity->id;

    // Set internal browser on the node.
    $this->getSession()->visit($this->locatePath('/node/' . $nid));
  }

  /**
   * Asserts that a given vocabulary term can be edited.
   *
   * @When I edit vocabulary :vocabulary term
   */
  public function editVocabularyTerm($vocabulary) {
    $vocab = taxonomy_vocabulary_machine_name_load($vocabulary);
    if (!$vocab) {
      throw new RuntimeException(sprintf('"%s" vocabulary does not exist', $vocabulary));
    }

    $term = (object) [
      'vid' => $vocab->vid,
      'name' => "Test term $vocabulary",
    ];
    $saved = $this->termCreate($term);

    // Set internal browser on the taxonomy term edit page.
    $this->getSession()
      ->visit($this->locatePath('/taxonomy/term/' . $saved->tid . '/edit'));
  }

  /**
   * Asserts that a given vocabulary term can be deleted.
   *
   * @When I delete vocabulary :vocabulary term
   */
  public function deleteVocabularyTerm($vocabulary) {
    $vocab = taxonomy_vocabulary_machine_name_load($vocabulary);
    if (!$vocab) {
      throw new RuntimeException(sprintf('"%s" vocabulary does not exist', $vocabulary));
    }

    $term = (object) [
      'vid' => $vocab->vid,
      'name' => "Test term $vocabulary",
    ];
    $saved = $this->termCreate($term);

    // Set internal browser on the taxonomy term edit page.
    $this->getSession()
      ->visit($this->locatePath('/taxonomy/term/' . $saved->tid . '/delete'));
  }

  /**
   * @Then I fill in autocomplete :locator with :name from :vocab vocabulary
   */
  public function iFillInAutocompleteWithTermFromVocabulary($locator, $name, $vocab) {
    $terms = taxonomy_get_term_by_name($name, $vocab);
    if (empty($terms)) {
      throw new \Exception(sprintf('Term "%s" is not found in vocabulary "%s"', $name, $vocab));
    }

    $field = $this->getSession()->getPage()->findField($locator);
    if (!$field) {
      throw new \Exception('Unable to find autocomplete field ' . $locator);
    }

    $existing_value = $field->getValue();
    $existing_value_exploded = explode(',', $existing_value);
    array_walk($existing_value_exploded, 'trim');
    $existing_value_exploded = array_diff($existing_value_exploded, ['_none']);

    $value = sprintf('%s (%s)', $name, reset($terms)->tid);
    $existing_value_exploded[] = $value;
    $new_values = implode(', ', $existing_value_exploded);
    $field->setValue($new_values);
  }

  /**
   * @Then user :user has CAS account :casaccount added
   */
  public function userAddCasAccount($name, $cas_account) {
    $user = user_load_by_name($name);
    if (!$user) {
      throw new Exception('Unable to load user ' . $name);
    }

    // Only add if user does not already have CAS name(s).
    if (empty($user->cas_names)) {
      db_insert('cas_user')
        ->fields([
          'uid' => $user->uid,
          'cas_name' => $cas_account,
        ])
        ->execute();
    }
  }

}
