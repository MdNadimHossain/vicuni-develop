@researcher_profile @rp_workbench @p0
Feature: Researcher Profile workbench

  @api
  Scenario: Researcher Profile Admin user has access to workbench table
    Given I am logged in as a user with the "Researcher Profile Admin" role
    And I go to "admin/workbench"

    Then I see the text "Administration of Researcher Profiles"
    And I see the text "Manage list of Researchers"

    And I see the text "People Summary"
    And I see the text "List of researchers"
    And I see the text "Researchers - never logged in/no account"
    And I see the text "Researchers - opted out"

    And I see the text "Researcher profiles summary"
    And I see the text "Drafts"
    And I see the text "Needs Review"
    And I see the text "Published"
    And I see the text "Amended & Awaiting"
