@researcher_profile @rp_optin @p0
Feature: Opt-in/opt-out to use Researcher Profile
  As a Researcher, I want to be able to opt-in/opt-out from using research
  profiles.

  Background:
    Given no users:
      | name            |
      | Test Researcher |
    And users:
      | name            | mail                        | roles      |
      | Test Researcher | test.researcher@example.com | Researcher |
    And "researcher_profile" content:
      | title           | field_rpa_staff_id |
      | Test Researcher | E1234567           |

  @api
  Scenario: User opts-in and opts-out for researcher profile.
    Given user "Test Researcher" has CAS account "1234567" added
    # Because of fast login, there is no easy way to actually login through UI
    # using standard step, so we have to login and go to the path.
    And I am logged in as "Test Researcher"
    And I go to "admin/workbench"
    Then I should see the text "My Researcher Profile"
    And I should see the text "Opt in or out"
    And I see field "edit-optin-1"
    And I see field "edit-optin-0"
    And element "#edit-optin-1[checked]" does not exist
    And element "#edit-optin-0[checked]" does not exist

    When I select the radio button "Opt-in to have a VU researcher profile" with the id "edit-optin-1"
    And I press the "submit_optin_link" button
    Then I see the text "Your selection has been saved"
    # Redirected to the profile node form.
    And element "#researcher-profile-node-form" exists

    # Go back to workbench and assert that correct option is selected.
    When I go to "admin/workbench"
    Then element "#edit-optin-1" exists
    And element "#edit-optin-0" exists
    And element "#edit-optin-1[checked]" exists
    And element "#edit-optin-0[checked]" does not exist

    Given I am logged in as a user with the "Administrator" role
    When I visit user "Test Researcher" profile
    And I click "Edit"

    Then element "#edit-field-rp-optin-und-1" exists
    And element "#edit-field-rp-optin-und-0" exists
    And element "#edit-field-rp-optin-und-1[checked]" exists

    And I should see an "#edit-field-rp-optout-timestamp-und-0-value-date" element
    And the "edit-field-rp-optout-timestamp-und-0-value-date" field should contain ""

    And the "Researcher Profile" field should not contain ""

    # Test opt-out.

    Given I am logged in as "Test Researcher"
    And I go to "admin/workbench"
    Then I should see the text "My Researcher Profile"
    And I should see the text "Opt in or out"
    And element "#edit-optin-1" exists
    And element "#edit-optin-0" exists
    And element "#edit-optin-1[checked]" exists
    And element "#edit-optin-0[checked]" does not exist

    When I select the radio button "Opt-out: I do NOT want a VU researcher profile at this time" with the id "edit-optin-0"
    And I press the "submit_optout" button
    Then I see the text "Your selection has been saved"

    And element "#edit-optin-1" exists
    And element "#edit-optin-0" exists
    And element "#edit-optin-1[checked]" does not exist
    And element "#edit-optin-0[checked]" exists

    Given I am logged in as a user with the "Administrator" role
    When I visit user "Test Researcher" profile
    And I click "Edit"

    Then element "#edit-field-rp-optin-und-1" exists
    And element "#edit-field-rp-optin-und-0" exists
    And element "#edit-field-rp-optin-und-0[checked]" exists

    And I should see an "#edit-field-rp-optout-timestamp-und-0-value-date" element
    And the "edit-field-rp-optout-timestamp-und-0-value-date" field should not contain ""

    And the "Researcher Profile" field should contain ""

  @api
  Scenario: User without CAS number tries to opt-in for researcher profile.
    # Because of fast login, there is no easy way to actually login through UI
    # using standard step, so we have to login and go to the path.
    Given I am logged in as "Test Researcher"
    And I go to "admin/workbench"
    Then I should see the text "My Researcher Profile"
    And I should see the text "Opt in or out"
    And I don't see field "edit-optin-1"
    And I don't see field "edit-optin-0"
    And I see the text "Looks like your account does not have a staff ID associated."

