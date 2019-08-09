@researcher_profile @rp_api @p1
Feature: Researcher Profile API

  @api
  Scenario: Users with specified permission have access to the specific pages.
    Given I am logged in as a user with the "administer researcher profile configuration" permission
    When I visit "admin/config/researcher-profile"
    Then the response status code should be 200

    Given I am logged in as a user with the "administer researcher profile configuration" permission
    When I visit "admin/config/researcher-profile/general"
    Then the response status code should be 200

    Given I am logged in as a user with the "administer researcher profile api configuration" permission
    When I visit "admin/config/researcher-profile/api"
    Then the response status code should be 200

    Given I am logged in as a user with the "administer researcher profile api configuration" permission
    When I visit "admin/config/researcher-profile/api-force-run"
    Then the response status code should be 200

    Given I am logged in as a user with the "access researcher profile api log" permission
    When I visit "admin/config/researcher-profile/log"
    Then the response status code should be 200

    Given I am logged in as a user with the "provision researcher profile demo content" permission
    When I visit "admin/config/development/demo-content"
    Then the response status code should be 200

    Given I am logged in as a user with the "administer test rest server" permission
    When I visit "admin/config/development/rest-server"
    Then the response status code should be 200

  @api
  Scenario Outline: Users have correct access to create Researcher Profile configuration
    Given I am logged in as a user with the "<role>" role

    When I go to "admin/config/researcher-profile"
    Then I should get a "<code_default>" HTTP response

    When I go to "admin/config/researcher-profile/general"
    Then I should get a "<code_general>" HTTP response

    When I go to "admin/config/researcher-profile/general/api"
    Then I should get a "<code_api>" HTTP response

    When I go to "admin/config/researcher-profile/api-force-run"
    Then I should get a "<code_api_force_run>" HTTP response

    When I go to "admin/config/researcher-profile/logs"
    Then I should get a "<code_logs>" HTTP response

    When I go to "admin/config/development/demo-content"
    Then I should get a "<code_demo>" HTTP response

    When I go to "admin/config/researcher-profile/rest-server"
    Then I should get a "<code_rest>" HTTP response

    When I go to "admin/config/system/queue-ui"
    Then I should get a "<code_queue>" HTTP response

    When I go to "admin/config/researcher-profile/list"
    Then I should get a "<code_researcher_list>" HTTP response

    When I go to "admin/config/researcher-profile/list/add"
    Then I should get a "<code_researcher_list_add>" HTTP response

    When I go to "admin/content"
    Then I should get a "<code_content_overview>" HTTP response

    When I go to "admin/reports"
    Then I should get a "<code_reports>" HTTP response

    When I go to "admin/reports/integration-status-report"
    Then I should get a "<code_status>" HTTP response

    Examples:
      | role                        | code_default | code_general | code_api | code_api_force_run | code_logs | code_demo | code_rest | code_queue | code_researcher_list | code_researcher_list_add | code_content_overview | code_reports | code_status |
      | Administrator               | 200          | 200          | 200      | 200                | 200       | 200       | 200       | 200        | 200                  | 200                      | 200                   | 200          | 200         |
      | Researcher                  | 403          | 403          | 403      | 403                | 403       | 403       | 403       | 403        | 403                  | 403                      | 403                   | 403          | 403         |
      | Researcher Profile Approver | 403          | 403          | 403      | 403                | 403       | 403       | 403       | 403        | 403                  | 403                      | 403                   | 403          | 403         |
      # @todo: Fix code_api access for Researcher Profile Admin to be 403.
      | Researcher Profile Admin    | 403          | 403          | 403      | 403                | 403       | 403       | 403       | 403        | 200                  | 200                      | 403                   | 403          | 403         |
      | Researcher Profile Tester   | 200          | 200          | 200      | 200                | 200       | 200       | 200       | 200        | 200                  | 200                      | 200                   | 200          | 200         |
      | Author                      | 403          | 403          | 403      | 403                | 403       | 403       | 403       | 403        | 403                  | 403                      | 200                   | 403          | 403         |
      | Advanced author             | 403          | 403          | 403      | 403                | 403       | 403       | 403       | 403        | 403                  | 403                      | 200                   | 403          | 403         |
      | Approver                    | 403          | 403          | 403      | 403                | 403       | 403       | 403       | 403        | 403                  | 403                      | 200                   | 200          | 403         |
      | Emergency publisher         | 403          | 403          | 403      | 403                | 403       | 403       | 403       | 403        | 403                  | 403                      | 200                   | 403          | 403         |
