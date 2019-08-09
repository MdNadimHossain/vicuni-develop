@p1
Feature: Workbench moderation

  As an Approver, I want to know that a new draft revision is created
  when published course is moderated.

  @api @user
  Scenario: Workflow moderation creates drafts on moderation.
    Given I am logged in as a user with the Approver role
    And I am viewing a draft revision of a published course:
      | title | [TEST] Draft Course |
    And I click "Moderate"

    # Initial draft.
    And I should see "View" in the "From Draft --> Draft" row
    And I should see "Revert" in the "From Draft --> Draft" row
    And I should not see "Edit draft" in the "From Draft --> Draft" row

    # Active published.
    And I should see "View" in the "Published --> Published" row
    And I should not see "Edit draft" in the "Published --> Published" row
    And I should not see "Revert" in the "Published --> Published" row

    # Active draft.
    And I should see "View" in the "Published --> Draft" row
    And I should see "Edit draft" in the "Published --> Draft" row
    And I should not see "Revert" in the "Published --> Draft" row
