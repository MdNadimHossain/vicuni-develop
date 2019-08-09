@p1 @skipped
Feature: TAFE information session block

  As a user I want to see a link to information sessions in the RHS of TAFE courses.

  @api
  Scenario: A TAFE course referenced in a tafe information session link entity should have a RHS block with the link.
    Given I am on a TAFE course that has a scheduled information session
    Then I can see a link "Course information sessions" within the element "div.aside-cta-box--tafe"
