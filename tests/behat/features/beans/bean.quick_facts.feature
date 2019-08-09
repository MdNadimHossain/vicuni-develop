@p0
Feature: Bean: Quick Facts

  As Approver, I want to be able to add new "Quick Facts" block.

  @api @bean
  Scenario: Approver can author a Quick Facts Bean.
    Given I am logged in as a user with the Approver role
    When I am at "/block/add/quick-facts"
    Then I see the text "Label"
    And I see the text "Icon"
    And I see the text "Title"
    And I see the text "Fact description"
