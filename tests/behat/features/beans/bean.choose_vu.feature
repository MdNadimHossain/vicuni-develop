@p0
Feature: Bean: Choose VU

  As Approver, I want to be able to add new "Choose VU" block.

  @api @bean
  Scenario: Approver can author a Choose VU Bean.
    Given I am logged in as a user with the Approver role
    When I am at "/block/add/choose-vu"
    Then I see the text "Label"
    And I see the text "Image"
    And I see the text "Title"
    And I see the text "Text"
    And I see the text "Link"
