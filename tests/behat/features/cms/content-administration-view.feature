@p0 @testnew
Feature: Content administration view

  As a Author, I wan to see bulk operations and other content information
  on Content page.

  @api @user @PW-656
  Scenario: Content administration view has the bulk operation block
    Given I am logged in as a user with the "Author" role
    And I am at "admin/content"
    Then I should see an "#edit-type" element
    And I should see an "#edit-uid" element
    And I should see an "#edit-status" element
    And I should see an "#edit-submit-content-revisions" element
    And I should see an "#edit-reset" element
    And element ".form-item-operation" does not exist
    And I should see "Title" in the "table.views-table > thead" element
    And I should see "Type" in the "table.views-table > thead" element
    And I should see "Revised by" in the "table.views-table > thead" element
    And I should see "Revision date" in the "table.views-table > thead" element
    And I should see "Log message" in the "table.views-table > thead" element
    And I should see "Pending" in the "table.views-table > thead" element
    And I should see "Published" in the "table.views-table > thead" element
    And I should see "Operation" in the "table.views-table > thead" element

  @api @user @PW-5161
  Scenario: Administrator should see bulk operations
    Given I am logged in as a user with the "Administrator" role
    And I am at "admin/content"
    And I should see an ".form-item-operation" element
    And I am at "admin/content/file"
    And I should see an ".form-item-operation" element

  @api @user @PW-5161
  Scenario: Advanced Authors should not see bulk operations
    Given I am logged in as a user with the "Advanced Author" role
    And I am at "admin/content"
    And element ".form-item-operation" does not exist
    And I am at "admin/content/file"
    And element ".form-item-operation" does not exist

  @api @user @PW-5161
  Scenario: Approvers should see bulk operations on files
    Given I am logged in as a user with the "Approver" role
    And I am at "admin/content"
    And element ".form-item-operation" does not exist
    And I am at "admin/content/file"
    And I should see an ".form-item-operation" element
