@p1
Feature: Workflow State Permissions
  Access for users based on the workflow published/draft/needs-review state

  @skipped @api @user @120928913
  Scenario: An authenticated user can view a draft revision
    Given I am logged in as a user with the administrator role
    And I am viewing a draft revision of a published course:
      | title | Test Draft Course |
    And I am logged in as an 'authenticated user'
    When I go to "/courses/test-draft-course-a12345"
    Then I should see the heading "Test Draft Course"
    Then I should see the text "View draft"
    When I click "View draft"
    Then I should see the text "Revision state: Draft"
    And I should see the text "Most recent revision: Yes"
    And I should not see the text "Edit draft"

  @skipped @api @user @120928913
  Scenario: An authenticated user can view an unpublished node
    Given I am logged in as a user with the administrator role
    And I am viewing a course page with the title "Test Unpublished Course"
    And I am logged in as an 'authenticated user'
    When I go to "/courses/test-unpublished-course-a12345"
    Then I should see the heading "Test Unpublished Course"
    And I should see the text "Revision state: Draft"
    And I should see the text "Most recent revision: Yes"
    And I should not see the text "Edit draft"

  @api @user @120928913
  Scenario: An anonymous user cannot view an unpublished node
    Given I am logged in as a user with the administrator role
    And I am viewing a course page with the title "Test Unpublished Course"
    And I am an anonymous user
    When I go to "/courses/test-unpublished-course-a12345"
    Then I should not see the heading "Test Unpublished Course"
    And I should see the heading "Access denied"

  @api @user @workbench_moderation_messages
  Scenario: An Approver user can view workbench moderation messages
    Given I am logged in as an Approver
    And I create a published page_builder with content:
      | title | Test Page 123 |
    Then I should see the heading "Test Page 123"
    And I should see the text "Revised by"
    And I should see the text "Date of revision"
    And I should see the text "Log message"
    And I should see the text "Revision state"
    And I should see the text "Most recent revision"
    When I click "View draft"
    Then I should see the text "Set moderation state"

    When I am logged in as an "Advanced Author"
    And I go to "/test-page-123"
    Then I should see the heading "Test Page 123"
    And I should see the text "Revised by"
    And I should see the text "Date of revision"
    And I should see the text "Log message"
    And I should see the text "Revision state"
    And I should see the text "Most recent revision"

    And I am logged in as an "Author"
    And I go to "/test-page-123"
    Then I should see the heading "Test Page 123"
    And I should see the text "Revised by"
    And I should see the text "Date of revision"
    And I should see the text "Log message"
    And I should see the text "Revision state"
    And I should see the text "Most recent revision"

    And I am an anonymous user
    And I go to "/test-page-123"
    Then I should see the heading "Test Page 123"
    And I should not see the text "Revised by"
    And I should not see the text "Date of revision"
    And I should not see the text "Log message"
    And I should not see the text "Revision state"
    And I should not see the text "Most recent revision"

  @api @PW-2508
  Scenario: Previously published nodes are 410'd
    Given I am logged in as an Approver
    And I enable the test email system
    And I create a published page_builder with content:
      | title | Test Page 410 |
    And I click "Unpublish this revision"
    And I press the "Unpublish" button
    And I am an anonymous user
    When I go to "/test-page-410"
    Then the response status code should be 410
