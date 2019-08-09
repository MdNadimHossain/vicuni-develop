@researcher_profile @rp_list @p1
Feature: Researcher Profile Researchers list

  @api
  Scenario: User manages Researchers list
    Given I am logged in as a user with the "manage researcher list" permission
    And I go to "admin/config/researcher-profile/list"
    Then I should get a "200" HTTP response

    # Clear the whole list before running tests.
    When I go to "admin/config/researcher-profile/list/delete-all"
    Then I should get a "200" HTTP response
    And I see the text "Are you sure you want to delete all records?"
    When I press "Delete all records"
    Then I see the text "Deleted all researchers from the list"
    And I see the text "No results found."

    When I go to "admin/config/researcher-profile/list"
    And I click "Add new researcher"
    Then I should get a "200" HTTP response
    And I see the text "Add new researcher"

    When I fill in "What is the staff ID of the new researcher?" with "E1111111"
    And I press the "Save" button

    Then I see the text "Successfully saved Staff ID"
    And I should see the text "Inactive" in the "E1111111" row

    # Try to add the same id again.
    When I go to "admin/config/researcher-profile/list/add"
    And I fill in "What is the staff ID of the new researcher?" with "E1111111"
    And I press the "Save" button
    Then I see the text "Staff ID already exists"
    And I see the text "Add new researcher"

    # Try to add incorrectly formatted id.
    When I go to "admin/config/researcher-profile/list/add"
    And I fill in "What is the staff ID of the new researcher?" with "E111"
    And I press the "Save" button
    Then I see the text "Staff ID should have 7 digits"
    And I see the text "Add new researcher"

        # Try to add incorrectly formatted id.
    When I go to "admin/config/researcher-profile/list/add"
    And I fill in "What is the staff ID of the new researcher?" with "1111111"
    And I press the "Save" button
    Then I see the text "Staff ID should start with"
    And I see the text "Add new researcher"
