@researcher_profile @rp_login @p1
Feature: Login as Researcher Profile users with relevant roles

  @api @javascript
  Scenario Outline: User logs in
    Given I am logged in as a user with the "<role>" role
    And I am viewing the site on a large screen
    When I visit "admin/workbench"

    Examples:
      | role                        |
      | Researcher                  |
      | Researcher Profile Admin    |
      | Researcher Profile Approver |
      | Researcher Profile Tester   |
