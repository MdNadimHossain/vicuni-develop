@p1
Feature: Mid-year courses

  As a prospective VU student
  I want to search and view courses open for mid-year intake on the VU website.

  Background:
    Given I define components:
      | course finder dropdown toggle | .coursefinder__form .dropdown-toggle |

  @javascript @api @PW-1217 @PW-1435 @PW-3010
  Scenario: Test Mid-year flag
    Given I am viewing the site on a large device
    And I am logged in as a user with the administrator role

    # Mid-year flag is OFF.
    When the feature switch courses-midyear-info is off

    When I am on the homepage
    Then I should not see "Find courses open for mid-year entry" in the "#vu-core-course-search-form" element

    When I go to "courses/search?type=Midyear"
    Then I should not see the text "Search for mid-year courses"

    When I go to "courses/1337CERTIII"
    Then I should not see the text "Mid-year applications"
