@p0 @smoke @researcher_profile
Feature: Homepage

  Ensure that homepage is displayed as expected

  @api @p0 @smoke0
  Scenario: Anonymous user visits homepage
    Given I go to the homepage
    And I should be in the "<front>" path
    Then I save screenshot

  @api @javascript @p1 @smoke1
  Scenario: Anonymous user visits homepage
    Given I go to the homepage
    And I should be in the "<front>" path
    Then I save screenshot
