@p0
Feature: Course search

  As a prospective VU student
  I want to search for courses on the VU website
  To find a course to apply for

  Background:
    Given I define components:
      | search filters | .main-container-wrapper .sidebar-first-wrapper |
      | search results | .main-container-wrapper .main-content-wrapper  |

  @PW-663
  Scenario: Unit search
    Given I visit "/courses/search"
    When I press the "Select search type" button
    Then I see the text "Search for courses"
    And I should not see the text "Search for mid-year courses"
    And I see the text "Search for units"

  @javascript @PW-1962
  Scenario: Facets on Mobile device
    Given I am viewing the site on a extra_small device
    When I visit "/courses/search"
    Then I should see the text "Refine your search"
    And I see the text "Filter by study level"
    And I see search filters not over search results

  @javascript @PW-1962
  Scenario: Facets on Desktop
    Given I am viewing the site on a desktop device
    When I visit "/courses/search"
    Then I should see the text "Refine your search"
    And I see the text "Filter by study level"
