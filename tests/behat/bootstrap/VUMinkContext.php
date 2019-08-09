<?php

/**
 * @file
 * VU Mink context for Behat testing.
 */

use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Behat\Hook\Scope\AfterScenarioScope;
use Behat\Gherkin\Node\TableNode;
use Behat\Mink\Driver\GoutteDriver;
use Behat\Mink\Driver\Selenium2Driver;
use Behat\Mink\Exception\UnsupportedDriverActionException;
use Drupal\DrupalExtension\Context\MinkContext;
use IntegratedExperts\BehatSteps\PathTrait;

/**
 * Defines application features from the specific context.
 */
class VUMinkContext extends MinkContext implements SnippetAcceptingContext {

  use PathTrait;

  use VUDropdownNavTrait;
  use ContentReportTrait;

  /**
   * After scenario, go back to the 'about:blank' so that scenarios start fresh.
   *
   * @AfterScenario
   */
  public function afterScenarioBackToBlank(AfterScenarioScope $event) {
    if ($this->getSession()->getDriver() instanceof Selenium2Driver) {
      $this->getSession()->visit('about:blank');
    }
  }

  /**
   * Checks whether a file wildcard at provided path exists.
   *
   * @param string $wildcard
   *   File name with a wildcard.
   *
   * @Given /^file wildcard "([^"]*)" should exist$/
   */
  public function assertFileShouldExist($wildcard) {
    $wildcard = $this->screenshotDir . DIRECTORY_SEPARATOR . $wildcard;
    $matches = glob($wildcard);

    if (empty($matches)) {
      throw new \Exception(sprintf("Unable to find files matching wildcard '%s'", $wildcard));
    }
  }

  /**
   * Iterate over a list of links and ensure they are visible.
   *
   * @Then I should see the following links in :region region:
   */
  public function assertMultipleLinksVisible(TableNode $table, $region = NULL) {
    if ($region) {
      // Find region.
      $region = strtolower(str_replace(' ', '-', $region));
      $element = $this->getDrupalRegion('.region-' . $region);
    }
    else {
      $element = $this->getSession()->getPage();
    }

    $driver = $this->getSession()->getDriver();

    foreach ($table->getHash() as $row) {
      // Extract current link.
      $link = reset($row);

      $result = $element->findLink($link);

      // Check element presence for Goutte driver and visibility for Selenium
      // driver.
      if ($result &&
        (
          ($driver instanceof GoutteDriver && !$result)
          ||
          ($driver instanceof Selenium2Driver && !$result->isVisible())
        )
      ) {
        throw new \Exception(sprintf("No link to '%s' on the page %s", $link, $this->getSession()
          ->getCurrentUrl()));
      }

      if (empty($result)) {
        throw new \Exception(sprintf("No link to '%s' on the page %s", $link, $this->getSession()
          ->getCurrentUrl()));
      }
    }
  }

  /**
   * Asserts the page title is as provided.
   *
   * @Then the page title should be :title
   */
  public function assertPageTitle($title) {
    $element = $this->getSession()->getPage();
    $result = $element->find('css', 'title');
    if (!$result) {
      throw new \Exception(sprintf("Page title '%s' is not found", $title));
    }
    if ($result && $title != $result->getText()) {
      throw new \Exception(sprintf("Page title is not '%s' but '%s'", $title, $result->getText()));
    }
  }

  /**
   * Iterate over a list of links and ensure they go to the correct destination.
   *
   * @param string $regionName
   *   Region name.
   * @param \Behat\Gherkin\Node\TableNode $linksData
   *   Links data.
   *
   * @Then the links in region :region take me to the following pages:
   */
  public function assertMultipleLinkDestinations($regionName, TableNode $linksData) {
    foreach ($linksData->getHash() as $data) {
      // Extract the link and page title.
      list($link_title, $page_title) = array_values($data);

      // Store current path for later.
      $source_path = $this->getSession()->getCurrentUrl();

      // Find region.
      $regionName = strtolower(str_replace(' ', '-', $regionName));
      $region = $this->getDrupalRegion('.region-' . $regionName);

      // Find the link by title and follow it.
      $link_title = $this->fixStepArgument($link_title);
      $region->clickLink($link_title);

      // Allow for page titles of specific external paths.
      $destination_path = $this->getSession()->getCurrentUrl();
      if (strpos($destination_path, 'https://login.') === 0) {
        if (strpos($destination_path, 'https://login.microsoftonline.com') === 0) {
          $page_title = 'Please wait...';
        }
      }
      elseif (strpos($destination_path, 'https://myvuportal.vu.edu.au') === 0) {
        // Leave $page_title as it is.
      }
      else {
        $page_title = "{$page_title} | Victoria University | Melbourne Australia";
      }

      // Assert the page title.
      $this->assertPageTitle($page_title);

      // Return to original path.
      $this->assertAtPath($source_path);
    }
  }

  /**
   * Return Drupal region from the current page.
   *
   * @param string $regionCssPath
   *   Region CSS path.
   *
   * @return \Behat\Mink\Element\NodeElement
   *   Node element.
   *
   * @throws \Exception
   *   If Drupal region cannot be found.
   */
  public function getDrupalRegion($regionCssPath) {
    $session = $this->getSession();
    $regionElement = $session->getPage()->find('css', $regionCssPath);
    if (!$regionElement) {
      throw new \Exception(sprintf('No Drupal region defined by CSS path "%s" found on the page %s.', $regionCssPath, $session->getCurrentUrl()));
    }

    return $regionElement;
  }

  /**
   * Click on the element specified by CSS.
   *
   * @When /^(?:|I )click (an?|on) "(?P<element>[^"]*)" element$/
   *
   * @javascript
   */
  public function assertElementClick($element) {
    $session = $this->getSession();
    $xpath = $session->getSelectorsHandler()->selectorToXpath('css', $element);

    $this->getSession()->getDriver()->click($xpath);
  }

  /**
   * Click on a visible link and assert the title of the landing page.
   *
   * @param string $link
   *   Link to be clicked.
   * @param string $title
   *   Title of the landing page.
   *
   * @When I click :Link I see page title :Title
   *
   * @throws Exception
   */
  public function assertClickLinkCheckTitle($link, $title) {
    $session = $this->getSession();
    $element = $session->getPage();
    if (!$element) {
      throw new \Exception(sprintf("element '%s' not found", $element));
    }
    $element->clickLink($link);
    $title = "{$title} | Victoria University | Melbourne Australia";
    $this->assertPageTitle($title);
  }

  /**
   * Asserts whether an element has a link.
   *
   * @param string $assert
   *   Assert verb: can or can not.
   * @param string $link
   *   Link name/title/id.
   * @param string $selector
   *   CSS selector of the element.
   *
   * @throws \Exception
   *    When the element is not found or
   *    the assertion fails.
   *
   * @Then /^(?:|I )(?P<assert>can|can\s?not) see a link "(?P<link>[^"]*)" within the element "(?P<selector>[^"]*)"$/
   */
  public function assertElementHasLink($assert, $link, $selector) {
    $assert = $assert == 'can';
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $selector);
    if (!$element) {
      throw new \Exception(sprintf('No element defined by the selector "%s" found on the page %s.', $selector, $session->getCurrentUrl()));
    }
    $found = $element->hasLink($link);
    if ($found !== $assert) {
      $verb = $assert ? 'can not be' : 'can be';
      throw new \Exception(sprintf('A link with the title/name "%s" %s found within the element "%s".', $link, $verb, $selector));
    }
  }

  /**
   * Click on link with text and href and assert the title of the landing page.
   *
   * @param string $text
   *   Link text to be clicked.
   * @param string $href
   *   Link href to be clicked.
   * @param string $title
   *   Title of the landing page.
   *
   * @When I click :text link with href :href I see page title :Title
   *
   * @throws Exception
   */
  public function assertClickLinkWithTextCheckTitle($text, $href, $title) {
    $session = $this->getSession();
    $page = $session->getPage();
    if (!$page) {
      throw new \Exception(sprintf("Page element '%s' not found", $page));
    }

    $linkByText = $page->findLink($text);
    if (!$linkByText) {
      throw new \Exception(sprintf("Link with text '%s' not found", $text));
    }

    $foundLink = $linkByText->getAttribute('href');
    $foundLink = ltrim($foundLink, '/');

    if ($href != $foundLink) {
      throw new \Exception(sprintf("Link with text '%s' has href '%s', but expected href is '%s'", $text, $foundLink, $href));
    }

    return $this->assertClickLinkCheckTitle($text, $title);
  }

  /**
   * Checks, that element with specified CSS is visible on page.
   *
   * @inheritdoc
   *
   * @javascript
   */
  public function assertElementOnPage($element) {
    if (!$this->getSession()->getDriver() instanceof Selenium2Driver) {
      parent::assertElementOnPage($element);
    }
    else {
      $xpath = $this->getSession()
        ->getSelectorsHandler()
        ->selectorToXpath('css', $element);

      if (!$this->getSession()->getDriver()->isVisible($xpath)) {
        throw new \Exception('Element is not visible');
      }
    }
  }

  /**
   * Checks, that element with specified CSS is not visible on page.
   *
   * @inheritdoc
   *
   * @javascript
   */
  public function assertElementNotOnPage($element) {
    $session = $this->getSession();
    $xpath = $session->getSelectorsHandler()->selectorToXpath('css', $element);

    if ($this->getSession()->getDriver()->isVisible($xpath)) {
      throw new \Exception('Element is not visible');
    }
  }

  /**
   * @Then /^element "(?P<element>[^"]*)" exists$/
   */
  public function assertElementExists($element) {
    $this->assertSession()->elementExists('css', $element);
  }

  /**
   * @Then /^element "(?P<element>[^"]*)" does not exist$/
   */
  public function assertElementNotExists($element) {
    $this->assertSession()->elementNotExists('css', $element);
  }

  /**
   * Wait for specified number of seconds.
   *
   * @When /^wait (\d+) seconds?$/
   *
   * @javascript
   */
  public function waitSeconds($seconds) {
    $this->getSession()->wait(1000 * $seconds, '1 === 2');
  }

  /**
   * Press keyboard key, optionally on element.
   *
   * @param string $char
   *   Character or one of the pre-defined special keyboard keys.
   * @param string $selector
   *   Optional CSS selector for an element to trigger the key on. If omitted,
   *   the key will be triggered on the 'html' element of the page.
   *
   * @throws UnsupportedDriverActionException
   *   If method is used for invalid driver.
   *
   * @Given I press the :char key
   * @Given I press the :char key on :selector
   */
  public function pressKeyOnElement($char, $selector = NULL) {
    $driver = $this->getSession()->getDriver();
    if (!$driver instanceof Selenium2Driver) {
      throw new UnsupportedDriverActionException('Method can be used only with Selenium driver', $driver);
    }

    $keys = [
      'backspace' => "\b",
      'tab' => "\t",
      'enter' => "\r",
      'shift' => 'shift',
      'ctrl' => 'ctrl',
      'alt' => 'alt',
      'pause' => 'pause',
      'break' => 'break',
      'escape' => 'escape',
      'esc' => 'escape',
      'end' => 'end',
      'home' => 'home',
      'left' => 'left',
      'up' => 'up',
      'right' => 'right',
      'down' => 'down',
      'insert' => 'insert',
      'delete' => 'delete',
      'pageup' => 'page-up',
      'page-up' => 'page-up',
      'pagedown' => 'page-down',
      'page-down' => 'page-down',
      'capslock' => 'caps',
      'caps' => 'caps',
    ];

    // Convert provided character sequence to special keys.
    if (is_string($char)) {
      if (strlen($char) < 1) {
        throw new \Exception('keyPress($char) was invoked but the $char parameter was empty.');
      }
      // Consider provided characters string longer then 1 to be a keyboard key.
      elseif (strlen($char) > 1) {
        if (!array_key_exists(strtolower($char), $keys)) {
          throw new \Exception('Unsupported key name provided');
        }

        // Special case for tab key triggered in window without target element
        // focused: Syn (JS library that provides synthetic events) can tab only
        // from another element that can receive focus, so we inject such
        // element as a very first element after opening <body> tag. This
        // element is visually hidden, but compatible with screen readers. Then
        // we trigger key on this element to make sure that an element that
        // supposed to get the very first focus from tab index actually gets it.
        // Note that injecting element and triggering key press on it does not
        // make it focused itself.
        if (is_null($selector) && $char == 'tab') {
          $hiddenFocusableElement = '<a id="injected-focusable" style="position: absolute;width: 1px;height: 1px;margin: -1px;padding: 0;overflow: hidden;clip: rect(0,0,0,0);border: 0;"></a>';
          $this->injectHtml($hiddenFocusableElement, 'body', 'prepend');
          $selector = '#injected-focusable';
        }

        $char = $keys[strtolower($char)];
      }
    }

    $selector = $selector ? $selector : 'html';

    // Element to trigger key press on.
    $element = $this->getSession()->getPage()->find('css', $selector);

    $this->triggerKey($element->getXpath(), $char);
  }

  /**
   * Inject HTML into page.
   *
   * @param string $html
   *   HTML string to inject.
   * @param string $selector
   *   CSS selector to use as a reference for injection position.
   * @param string $position
   *   Injection position: before, after, prepend, append.
   *
   * @throws UnsupportedDriverActionException
   *   If method is used for invalid driver.
   * @throws RuntimeException
   *   If invalid position specified.
   */
  protected function injectHtml($html, $selector, $position) {
    $allowedPositions = [
      'before',
      'after',
      'prepend',
      'append',
    ];

    $driver = $this->getSession()->getDriver();
    if (!$driver instanceof Selenium2Driver) {
      throw new UnsupportedDriverActionException('Method can be used only with Selenium driver', $driver);
    }

    if (!in_array($position, $allowedPositions)) {
      throw new \RuntimeException('Invalid position specified');
    }

    // Ensure jQuery has loaded.
    $this->getSession()->wait(5000, 'typeof window.jQuery === "function"');
    $driver->evaluateScript("jQuery('$selector').$position('$html');");
  }

  /**
   * Trigger key on the element.
   *
   * Uses Syn library injected by original Selenium2 class to trigger browser
   * events.
   *
   * @param string $xpath
   *   XPath string for an element to trigger the key on.
   * @param string $key
   *   Key to trigger. Special key values must be provided as strings (i.e.
   *   'tab' key as "\t", 'enter' key as "\r" etc.).
   *
   * @throws UnsupportedDriverActionException
   *   If method is used for invalid driver.
   */
  protected function triggerKey($xpath, $key) {
    $driver = $this->getSession()->getDriver();
    if (!$driver instanceof Selenium2Driver) {
      throw new UnsupportedDriverActionException('Method can be used only with Selenium driver', $driver);
    }

    // Use reflection to re-use Syn library injection and execution of JS on
    // element.
    $reflector = new ReflectionClass($driver);
    $withSynReflection = $reflector->getMethod('withSyn');
    $withSynReflection->setAccessible(TRUE);
    $executeJsOnXpathReflection = $reflector->getMethod('executeJsOnXpath');
    $executeJsOnXpathReflection->setAccessible(TRUE);
    $withSynResult = $withSynReflection->invoke($driver);

    $executeJsOnXpathReflection->invokeArgs($withSynResult, [
      $xpath,
      "Syn.key({{ELEMENT}}, '$key');",
    ]);
  }

  /**
   * Check that the given link is visible and points to the specified href.
   *
   * @param string $link
   *   The link text.
   * @param string $href
   *   The expected href value.
   *
   * @throws Exception
   *   If the link or the href do not match expected values.
   *
   * @Then I should see the link :link linking to :href
   */
  public function assertLinkVisibleLinksToHref($link, $href) {
    $element = $this->getSession()->getPage();
    $result = $element->findLink($link);

    try {
      if ($result && !$result->isVisible()) {
        throw new \Exception(sprintf("No link to '%s' on the page %s", $link, $this->getSession()
          ->getCurrentUrl()));
      }
    }
    catch (UnsupportedDriverActionException $e) {
      // We catch the UnsupportedDriverActionException exception in case
      // this step is not being performed by a driver that supports javascript.
      // All other exceptions are valid.
    }

    if (empty($result)) {
      throw new \Exception(sprintf("No link to '%s' on the page %s", $link, $this->getSession()
        ->getCurrentUrl()));
    }

    if (!$result->hasAttribute('href')) {
      throw new \Exception("The link does not contain a href attribute");
    }

    if ($result->getAttribute('href') != $href) {
      throw new \Exception(sprintf("The link href '%s' does not match the specified href '%s'", $result->getAttribute('href'), $href));
    }
  }

  /**
   * Checks, that (?P<num>\d+) CSS elements are visible on the page.
   *
   * Example: Then I should see 5 "div" visible elements.
   * Example: And I should see 5 "div" visible elements.
   *
   * @Then /^(?:|I )should see (?P<num>\d+) "(?P<element>[^"]*)" visible elements?$/
   */
  public function assertNumElementsVisible($num, $element) {
    $container = $this->getSession()->getPage();
    $nodes = $container->findAll('css', $element);

    // Determine how many elements are visible.
    $visible = count($nodes);
    foreach ($nodes as $node) {
      if (!$node->isVisible()) {
        $visible--;
      }
    }
    if ($visible !== intval($num)) {
      throw new \Exception(sprintf('%d visible elements found on the page, but should be %d.', $visible, $num));
    }
  }

  /**
   * Hover the mouse over an element.
   *
   * @When /^I hover over the element "([^"]*)"$/
   */
  public function iHoverOverTheElement($selector) {
    $session = $this->getSession();
    $element = $session->getPage()
      ->find('css', $selector);

    if (NULL === $element) {
      throw new \Exception(sprintf('Could not find an element with the selector: "%s"', $selector));
    }
    $element->mouseOver();
  }

  /**
   * Ensure lists are displayed in the correct order.
   *
   * @Then /^the selector "([^"]*)" should contain (only|all of) the following items in order:$/
   */
  public function shouldPrecedeForTheQuery($cssQuery, $only, TableNode $textItems) {
    $exact_match = $only == "only";
    $items = array_map(
      function ($element) {
        return $element->getText();
      },
      $this->getSession()->getPage()->findAll('css', $cssQuery)
    );

    if ($exact_match && count($items) !== count($textItems->getRows())) {
      throw new Exception(sprintf('Found %s items in "%s" expected: %s.', count($items), $cssQuery, count($textItems->getRows())));
    }

    $last_item_position = -1;
    foreach ($textItems->getRows() as $index => $row) {
      if ($exact_match) {
        if (!isset($items[$index])) {
          throw new Exception(sprintf('The provided value "%s" could not be found in "%s"', $row[0], $cssQuery));
        }
        if ($items[$index] !== $row[0]) {
          throw new Exception(sprintf('The provided value "%s" does not match the "%s"', $row[0], $items[$index]));
        }
      }
      else {
        $current_item_position = array_search($row[0], $items);
        if ($current_item_position === FALSE) {
          throw new Exception(sprintf('The provided value "%s" is not found in "%s".', $row[0], $cssQuery));
        }
        if ($current_item_position <= $last_item_position) {
          throw new Exception(sprintf('The provided value "%s" was found in position %s, excpected position: %s.', $row[0], $current_item_position, $index));
        }
        $last_item_position = $current_item_position;
      }
    }
  }

  /**
   * Assert that a user has navigated away from the homepage.
   *
   * All tests should use this step definition to assert that current path is
   * not the homepage.
   *
   * @Given /^(?:|I )am not on (?:|the )homepage$/
   */
  public function assertIamNotOnHomepage() {
    if ($this->locatePath('homepage') == $this->getSession()->getCurrentUrl()) {
      throw new \Exception('Currently on homepage but should not be');
    }
  }

  /**
   * {@inheritdoc}
   *
   * Fixes a bug where Drupal.ajax.instances is undefined.
   */
  public function iWaitForAjaxToFinish() {
    $condition = <<<JS
    (function() {
      function isAjaxing(instance) {
        return instance && instance.ajaxing === true;
      }
      return (
        // Assert no AJAX request is running (via jQuery or Drupal) and no
        // animation is running.
        (typeof jQuery === 'undefined' || (jQuery.active === 0 && jQuery(':animated').length === 0)) &&
        ((typeof Drupal === 'undefined' || typeof Drupal.ajax === 'undefined' || typeof Drupal.ajax.instances === 'undefined') || !Drupal.ajax.instances.some(isAjaxing))
      );
    }());
JS;
    // This returned false on admin page based tests on:
    // AfterStep // VUMinkContext::afterJavascriptStep().
    // Because of that issue, the return value is no longer checked.
    // It shouldn't impact too much because we don't use "wait for ajax" as
    // the key step anyway. If this fails then the next step should fail.
    $this->getSession()->wait(5000, $condition);
  }

  /**
   * @Then the element :arg1 is not empty
   */
  public function theElementIsNotEmpty($arg1) {
    $this->assertSession()->elementExists('css', $arg1);

    if (empty($this->getSession()->getPage()->find('css', $arg1)->getText())) {
      throw new \Exception("Element $arg1 is empty");
    }
  }

  /**
   * {@inheritdoc}
   */
  public function assertLinkRegion($link, $region) {
    // Allow to use href as a link's locator.
    try {
      parent::assertLinkRegion($link, $region);
    }
    catch (\Exception $exception) {
      if (!parse_url($link)) {
        throw $exception;
      }
      $regionObj = $this->getRegion($region);
      $link = $regionObj->find('css', 'a[href="' . $link . '"]');
      if (!$link) {
        throw $exception;
      }
    }
  }

}
