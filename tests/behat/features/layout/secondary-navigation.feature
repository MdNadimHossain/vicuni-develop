@p1 @PW-1487
Feature: Secondary navigation on homepage

  Ensure that secondary navigation dropdown and overlay work correctly together.

  Background:
    Given I define components:
      | second menu item     | .secondary .menu-block-main-menu-level2 > .menu-wrapper > ul.menu > li.level-2:nth-child(2)                   |
      | third menu item      | .secondary .menu-block-main-menu-level2 > .menu-wrapper > ul.menu > li.level-2:nth-child(3)                   |
      | second menu dropdown | .secondary .menu-block-main-menu-level2 >.menu-wrapper > ul.menu > li.level-2:nth-child(2) > div.menu-wrapper |
      | third menu dropdown  | .secondary .menu-block-main-menu-level2 >.menu-wrapper > ul.menu > li.level-2:nth-child(3) > div.menu-wrapper |
      | overlay              | #mainMenuOverlay                                                                                              |

  @api @javascript
  Scenario Outline: Clicking on the second menu item shows and hides dropdown with overlay
    Given I am viewing the site on a "<breakpoint>" screen
    And I am on the homepage
    And I don't see overlay, second menu dropdown and third menu dropdown
    When I click on second menu item
    And wait 2 seconds
    Then I see visible second menu dropdown and overlay
    And I don't see third menu dropdown
    When I click on second menu item
    And wait 2 seconds
    Then I don't see overlay, second menu dropdown and third menu dropdown

    Examples:
      | breakpoint  |
      | medium      |
      | large       |
      | extra_large |

  @api @javascript
  Scenario Outline: Clicking on the second menu item shows and clicking on the third menu item hides/shows dropdown, bur preserve overlay
    Given I am viewing the site on a "<breakpoint>" screen
    And I am on the homepage
    And I don't see overlay, second menu dropdown and third menu dropdown
    When I click on second menu item
    And wait 2 seconds
    Then I see visible second menu dropdown and overlay
    And I don't see third menu dropdown
    When I click on third menu item
    And wait 2 seconds
    Then I see visible third menu dropdown and overlay
    And I don't see second menu dropdown
    When I click on third menu item
    And wait 2 seconds
    Then I don't see overlay, second menu dropdown and third menu dropdown

    Examples:
      | breakpoint  |
      | medium      |
      | large       |
      | extra_large |
