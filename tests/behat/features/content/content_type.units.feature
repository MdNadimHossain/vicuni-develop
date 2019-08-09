@p0
Feature: Content type: Units

  As a prospective student
  I want the ability to view Unit pages
  So that I can get more information about VU units

  @PW-817
  Scenario Outline: Study single unit block appears in undergraduate and postgraduate units
    Given I am an anonymous user
    When I am viewing a page of unit content type where:
      | condition type    | field          | value        |
      | propertyCondition | status         | 1            |
      | fieldCondition    | field_unit_lev | <unit_level> |
    Then I should see 1 "div.study-single-unit" element
    And  I should see the link "Apply for single units of study"

    When  I click "Apply for single units of study"
    Then I should see the text "Single units of study"

    Examples:
      | unit_level |
      | undergrad  |
      | postgrad   |

  @PW-817
  Scenario: Study single unit block does not appear in units that are not undergraduate and postgraduate level
    Given I am an anonymous user
    When I am viewing a page of unit content type where:
      | condition type    | field          | value |
      | propertyCondition | status         | 1     |
      | fieldCondition    | field_unit_lev | tafe  |
    Then I should see 0 "div.study-single-unit" elements
