@p0
Feature: Course search

  As a prospective VU student
  I want to search for units on the VU website

  Background:
    Given I define components:
      | unit search  | .field-name-unit-search |
      | overview rhs | #overview .col-md-4     |

  @javascript @PW-3049
  Scenario: Unit search
    # Find a published Unit page
    Given I am viewing a page of Unit content type where:
      | condition type    | field  | value |
      | propertyCondition | status | 1     |

    # Check the Unit Search block is in the correct area
    Then I see unit search inside of overview rhs

    # Make sure the search goes to the right place.
    Then I fill in the following:
      | edit-query | BEO2005 |
    And I press the "Search for a unit" button
    Then I am at "\/courses\/search\?.*?(type=.*|query=.*)[&](type=.*|query=.*)?"

  @javascript @PW-3049
  Scenario: Unit set search

    # Find a published Unit Set page
    Given I am viewing a page of "Unit Set" content type where:
      | condition type    | field  | value |
      | propertyCondition | status | 1     |

    # Check the Unit Search block is in the correct area
    Then I see unit search inside of overview rhs

    # Make sure the search goes to the right place.
    Then I fill in the following:
      | edit-query | BEO2005 |
    And I press the "Search for a unit" button
    Then I am at "\/courses\/search\?.*?(type=.*|query=.*)[&](type=.*|query=.*)?"
