<?php

/**
 * @file
 * VU Bean trait for Behat testing.
 */

use Behat\Behat\Hook\Scope\ScenarioScope;
use Behat\Gherkin\Node\TableNode;

/**
 * Class VUCoursesImportTrait.
 */
trait VUBeanTrait {

  /**
   * Static cache of Bean pages.
   *
   * @var array
   */
  private $beanPages = [];

  /**
   * Create a Bean entity and attach to and view a Page manager page.
   *
   * Fields and values provided in the form:
   * | title                | My entity      |
   * | field][und][0][value | My field value |
   * | ...                  | ...            |
   *
   * @Given I am on a page with a bean with the content:
   */
  public function createBeanAttachPageView(TableNode $content) {
    // Create Bean entity.
    $values = [];
    foreach ($content->getRowsHash() as $field => $value) {
      $parents = explode('][', $field);
      drupal_array_set_nested_value($values, $parents, $value);
    }
    $bean = bean_create($values);
    $bean->save();
    $this->savedEntities['bean'][] = $bean->delta;

    // Create a Page manager page.
    module_load_include('inc', 'ctools', 'page_manager/plugins/tasks/page');
    $page = new stdClass();
    $page->name = str_replace('-', '_', "bean_test_{$bean->delta}");
    $page->task = 'page';
    $page->path = $page->name;
    $page->access = [];
    $page->menu = [];
    $page->arguments = [];
    $page->conf = [];
    $page->default_handlers = [];
    $handler = new stdClass();
    $handler->name = 'panel';
    $handler->task = 'page';
    $handler->subtask = 'panel';
    $handler->handler = 'panel_context';
    $handler->conf = [
      'pipeline' => 'default',
      'css_id' => '',
    ];
    $page->default_handlers[$handler->name] = $handler;
    $display = new panels_display();
    $display->layout = 'raw';
    $display->storage_type = 'page_manager';
    $display->storage_id = "{$page->name}-panel";
    $handler->conf['display'] = $display;
    $pane = new stdClass();
    $pane->pid = "{$display->storage_id}-pane";
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = "bean-{$bean->delta}";
    $pane->shown = TRUE;
    $pane->configuration = [
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    ];
    $display->content[$pane->pid] = $pane;
    $display->panels['middle'][] = $pane->pid;
    page_manager_page_save($page);

    // Rebuild menu.
    menu_rebuild();

    // Store ID for cleanup.
    $this->beanPages[] = $page->name;

    // Visit page.
    $this->getSession()->visit($this->locatePath($page->path));
  }

  /**
   * Cleanup Bean testing page.
   *
   * @param Behat\Behat\Hook\Scope\ScenarioScope $event
   *   The behat event object.
   *
   * @AfterScenario @bean
   */
  public function afterFeatureBean(ScenarioScope $event) {
    module_load_include('inc', 'ctools', 'page_manager/plugins/tasks/page');
    foreach ($this->beanPages as $page) {
      $page = page_manager_page_load($page);
      page_manager_page_delete($page);
    }
  }

}
