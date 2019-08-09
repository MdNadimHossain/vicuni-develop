@researcher_profile @rp_api_queues @p1
Feature: Researcher Profile API queuing

  As a RP Admin, I want to know that PI items correctly processed in queues.

  @api @VURpAPIServer
  Scenario: Test re-queuing.
    Given no "researcher_profile" content:
      | title                            |
      | Testprefferedname1 Testlastname1 |
      | Testprefferedname2 Testlastname2 |
      | Testprefferedname3 Testlastname3 |

    And variable "vu_rp_api_provider" has value "local"
    And research profile api provider "list" endpoint "url" value is set to "vu-rest/test-researcher/profiles"
    And research profile api provider "list" endpoint "timeout" value is set to "10"
    And research profile api provider "account" endpoint "url" value is set to "vu-rest/test-researcher/profile/{account}"
    And research profile api provider "account" endpoint "timeout" value is set to "10"
    And researcher profile api response "test-researcher/profiles" exists
    And researcher profile api response "test-researcher/profile/E8888001" exists
    When I add staff id "E8888001" to researcher profile list
    And I add staff id "E8888002" to researcher profile list
    And I add staff id "E8888003" to researcher profile list

    And I set variable "vu_rp_api_queue_account_remove" to value "3"
    And I set variable "vu_rp_api_queue_account_batch_size" to value "3"
    And I set variable "vu_rp_api_queue_node_remove" to value "3"
    And I set variable "vu_rp_api_queue_node_batch_size" to value "3"

    And I reset research profile api queues
    And research profile api "account" queue has 0 items
    And research profile api "node" queue has 0 items

    Given I am logged in as a user with the "administrator" role

    When I visit "admin/config/system/cron/execute/vu_rp_api_fetch_list"
    Then research profile api "account" queue has 3 items
    And research profile api "node" queue has 0 items

    When I visit "admin/config/system/cron/execute/vu_rp_api_fetch_accounts"
    Then research profile api "account" queue has 2 items
    And research profile api "node" queue has 1 items

    # Retry the same queue - try 2 for failed items.
    When I visit "admin/config/system/cron/execute/vu_rp_api_fetch_accounts"
    Then research profile api "account" queue has 2 items
    And research profile api "node" queue has 1 items

    # Retry the same queue - try 3 for failed items.
    When I visit "admin/config/system/cron/execute/vu_rp_api_fetch_accounts"
    Then research profile api "account" queue has 0 items
    And research profile api "node" queue has 1 items

    # Now process the node.
    When I visit "admin/config/system/cron/execute/vu_rp_api_process_nodes"
    Then research profile api "account" queue has 0 items
    Then research profile api "node" queue has 0 items
