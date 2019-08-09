@researcher_profile @rp_log @p0
Feature: Researcher logs exists

  @api
  Scenario: Logs are accessible
    Given I am logged in as a user with the "access researcher profile api log" permission
    And I visit "admin/config/researcher-profile/log"
    Then I should get a "200" HTTP response
    And I should not see the link "Clear log messages"
    And I should see the text "Filter log messages"
    And I should see the button "Filter"
    Then I should see the text "Event"
    And I should see the text "Severity"
    And I should see the text "Message"
    And I should see the text "Date"
    And I should see the text "View"

  @api
  Scenario: Logs are accessible
    Given I am logged in as a user with the "access researcher profile api log, clear researcher profile api log" permissions
    And I visit "admin/config/researcher-profile/log"
    Then I should get a "200" HTTP response
    And I should see the link "Clear log messages"
    And I should see the text "Filter log messages"
    And I should see the button "Filter"
    Then I should see the text "Event"
    And I should see the text "Severity"
    And I should see the text "Message"
    And I should see the text "Date"
    And I should see the text "View"
