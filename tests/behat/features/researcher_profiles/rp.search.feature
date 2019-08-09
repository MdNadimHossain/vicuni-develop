@researcher_profile @rp_search @p1
Feature: Researcher Profile Search
  Ensure that Researcher Profile page and content exists.

  Background:
      Given I define components:
        | third menu dropdown  | .secondary .menu-block-main-menu-level2 >.menu-wrapper > ul.menu > li.level-2:nth-child(3) > div.menu-wrapper |
        | overlay              | #mainMenuOverlay                                                                                              |

  @api
  Scenario: Researcher Profile Search page exists.
    Given I go to "research/find-researcher"
    Then I should get a "200" HTTP response
    And I should see the text "Find a researcher"

    # Check if search block exists and default options selected.
    Then the "query" field should not contain "test"
    And the "edit-rpc-all" checkbox should be checked
    And I should see the button "Search"

  @api
  Scenario: Check if search block works.
    Given I go to "research/find-researcher?query=test"
    Then I should get a "200" HTTP response
    And the "query" field should contain "test"
    And the "edit-rpc-all" checkbox should be checked
    And the "supervisors" checkbox should not be checked
    And the "media" checkbox should not be checked

    When I go to "research/find-researcher?query=test&rpc=supervisors"
    Then I should get a "200" HTTP response
    And the "query" field should contain "test"
    And the "edit-rpc-all" checkbox should not be checked
    And the "supervisors" checkbox should be checked
    And the "media" checkbox should not be checked

    When I go to "research/find-researcher?query=t&rpc=media"
    Then I should get a "200" HTTP response
    And the "query" field should not contain "test"
    And the "edit-rpc-all" checkbox should not be checked
    And the "supervisors" checkbox should not be checked
    And the "media" checkbox should be checked

  @javascript
  Scenario: Check if secondary link to search exists.
    Given I am viewing the site on a "large" screen
    And I am on the homepage
    When I click "Research"
    And wait 2 seconds
    Then I see visible third menu dropdown and overlay
    And I should see the link "Find a researcher"
    When I click "Find a researcher"
    Then I should see the text "Find a researcher"
