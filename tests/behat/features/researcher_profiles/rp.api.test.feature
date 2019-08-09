@researcher_profile @rp_api_test @p0
Feature: Researcher Profile API test

  Tests to make sure that API server and provider work correctly when tested
  from Behat. This is a test for the test system itself.

  @api @VURpAPIServer
  Scenario: Assert that test API server works as expected with testing system.
    Given variable "vu_rp_test_is_test_mode" has value "1"
    And variable "vu_rp_test_rest_responses_list" does not have a value

    And researcher profile api response "test-researcher/profiles" exists
    And researcher profile api response "test-researcher/profile/E8888001" exists
    And researcher profile api response "test-researcher/profile/E8888002" exists
    And researcher profile api response "test-researcher/profile/E8888003" exists

    When I go to "vu-rest/test-researcher/profiles"
    Then the response status code should be 200
    And the response should contain "\"Researchers\": ["

    When I go to "vu-rest/test-researcher/profile/E8888001"
    Then the response status code should be 200
    And the response should contain "\"ResearcherProfile\": {"

    When I go to "vu-rest/test-researcher/profile/E8888002"
    Then the response status code should be 200
    And the response should contain "\"ResearcherProfile\": {"

    When I go to "vu-rest/test-researcher/profile/E8888003"
    Then the response status code should be 200
    And the response should contain "\"ResearcherProfile\": {"

    # Non-existing item.
    When I go to "vu-rest/test-researcher/profile/E8888004"
    Then the response status code should be 404
    And the response should not contain "\"ResearcherProfile\": {"

    When researcher profile api response "test-researcher/profile/E8888006" has content:
    """
    {
      "ResearcherProfile": {
        "staffID": "E8888003",
        "title": "Prof"
      }
    }
    """
    And I go to "vu-rest/test-researcher/profile/E8888006"
    Then the response status code should be 200
    And the response should contain "\"ResearcherProfile\": {"

    # Assert that provider was switched correctly by going directly to
    # integration report page url. The response code should always be 200
    # and the body would contain JS with success result.
    Then variable "vu_rp_api_provider" has value "local"

    Given research profile api provider "list" endpoint "url" value is set to "vu-rest/test-researcher/profiles"
    When I am logged in as a user with the "access integration status report" permission
    And I go to "admin/reports/status-report/VuRpApiStatusList"
    Then the response status code should be 200
    And the response should contain "{\"success\":true"

    Given research profile api provider "account" endpoint "url" value is set to "vu-rest/test-researcher/profile/{account}"
    And research profile api provider "account" endpoint "status.test_account" value is set to "E8888001"
    When I am logged in as a user with the "access integration status report" permission
    And I go to "admin/reports/status-report/VuRpApiStatusAccount"
    Then the response status code should be 200
    And the response should contain "{\"success\":true"

    Given researcher profile list does not have staff id "E8888001"
    When I add staff id "E8888001" to researcher profile list
    Then researcher profile list has staff id "E8888001"

  @api
  Scenario: Assert that there are no leftover variables after using test API run.
    Given variable "vu_rp_test_is_test_mode" does not have a value
    And variable "vu_rp_test_rest_responses_list" does not have a value

    And researcher profile list does not have staff id "E8888001"
