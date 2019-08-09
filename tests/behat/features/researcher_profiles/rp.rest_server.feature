@researcher_profile @rp_rest_server @p0
Feature: Researcher Profile API REST Server

  @api
  Scenario: Test that REST functionality works as expected

    Given I am logged in as a user with the "administer test rest server, view the administration theme" permission
    When I visit "admin/config/researcher-profile/rest-server"
    Then the response status code should be 200

    And I should see the link "+ Add new record"

    # Create.
    When I click "+ Add new record"
    Then I see the text "Add record"
    And I fill in "Request path" with "my-test-path"
    And I select the radio button "GET" with the id "edit-request-method-get"
    And I fill in "Response content" with "MY TEST RESPONSE CONTENT"
    And I fill in "Comment" with "MY TEST RESPONSE COMMENT"
    And I press "Save"

    Then I see the text "Successfully created record"
    And I should see the text "GET" in the "MY TEST RESPONSE COMMENT" row
    And I should see the text "my-test-path" in the "MY TEST RESPONSE COMMENT" row
    And I should see the text "MY TEST RESPONSE CONTENT" in the "MY TEST RESPONSE COMMENT" row
    And I should see the text "Edit" in the "MY TEST RESPONSE COMMENT" row
    And I should see the text "Delete" in the "MY TEST RESPONSE COMMENT" row

    # Edit.
    When I click "Edit" in the "MY TEST RESPONSE COMMENT" row
    Then I see the text "Edit record"
    And I fill in "Request path" with "my-updated-test-path"
    And I select the radio button "GET" with the id "edit-request-method-get"
    And I fill in "Response content" with "MY UPDATED TEST RESPONSE CONTENT"
    And I fill in "Comment" with "MY UPDATED TEST RESPONSE COMMENT"
    And I press "Save"

    Then I see the text "Successfully updated record"
    And I should see the text "GET" in the "MY UPDATED TEST RESPONSE COMMENT" row
    And I should see the text "my-updated-test-path" in the "MY UPDATED TEST RESPONSE COMMENT" row
    And I should see the text "MY UPDATED TEST RESPONSE CONTENT" in the "MY UPDATED TEST RESPONSE COMMENT" row
    And I should see the text "Edit" in the "MY UPDATED TEST RESPONSE COMMENT" row
    And I should see the text "Delete" in the "MY UPDATED TEST RESPONSE COMMENT" row

    And I should not see the text "my-test-path"
    And I should not see the text "MY TEST RESPONSE CONTENT"
    And I should not see the text "MY TEST RESPONSE COMMENT"

    # Delete.
    When I click "Delete" in the "MY UPDATED TEST RESPONSE COMMENT" row
    Then I see the text "Are you sure you want to delete this record?"
    And I press "Delete record"
    Then I see the text "Successfully delete record"

    And I should not see the text "my-test-path"
    And I should not see the text "my-updated-test-path"
    And I should not see the text "MY TEST RESPONSE CONTENT"
    And I should not see the text "MY UPDATED TEST RESPONSE CONTENT"
    And I should not see the text "MY TEST RESPONSE COMMENT"
    And I should not see the text "MY UPDATED TEST RESPONSE COMMENT"
