@smoke @researcher_profile
Feature: Login

  Ensure that user can login.

  @api @p0 @smoke0
  Scenario: Administrator user logs in
    Given I am logged in as a user with the "administer site configuration" permission
    When I go to "admin"
    Then I save screenshot

  @api @javascript @p1 @smoke1
  Scenario: Administrator user logs in
    Given I am logged in as a user with the "administer site configuration" permission
    When I go to "admin"
    Then I save screenshot
