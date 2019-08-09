<?php

/**
 * @file
 * VU Dropdown nav trait for Behat testing.
 */

/**
 * Class VUDropdownNavTrait.
 */
trait VUDropdownNavTrait {

  /**
   * CSS selector to activate the dropdown menu.
   *
   * @var string
   */
  private $dropdownTriggerSelector = '[data-toggle=dropdown].active-trail';

  /**
   * CSS selector for the open dropdown menu.
   *
   * @var string
   */
  private $dropdownSelector = '.level-2.open';

  /**
   * Step definition: click on the secondary nav ot open the dropdown.
   *
   * @When I open the dropdown nav
   */
  public function iOpenTheDropdownNav() {
    $session = $this->getSession();
    $driver = $session->getDriver();
    $xpath = $session->getSelectorsHandler()->selectorToXpath('css', $this->dropdownTriggerSelector);
    // Don't handle the exception if we can't click it,
    // just let the test fail.
    $driver->click($xpath);
    $session->wait(500);
  }

  /**
   * Step definition: assert text is in the dropdown nav.
   *
   * @Then I should see :text inside the dropdown nav
   */
  public function iShouldSeeInsideTheDropdownNav($text) {
    $this->assertSession()->elementTextContains('css', $this->dropdownSelector, $this->fixStepArgument($text));
  }

  /**
   * Step definition: assert text is not in the dropdown nav.
   *
   * @Then I should not see :text inside the dropdown nav
   */
  public function iShouldNotSeeInsideTheDropdownNav($text) {
    $this->assertSession()->elementTextNotContains('css', $this->dropdownSelector, $this->fixStepArgument($text));
  }

}
