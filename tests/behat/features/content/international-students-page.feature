@p0
Feature: International Students Topic Page

  As a stakeholder, I want to search for international courses by default when I use
  the course search form on the international students topic page.

  @PW-1273 @skipped
  Scenario: Anonymous user viewing international students page.
    Given I am at "study-at-vu/international-students"
    When I press "Find"
    Then I should be in the "courses/search" path
    And I should see "non-residents" in the ".vu-course-search-tabs li.active .search-navigation strong" element
