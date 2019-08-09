@p1
Feature:
  I want the ability to view logo, the primary and secondary navigation links.

  Background:
    Given I define components:
      | primary navigation           | header .menu-block-main-menu-level1             |
      | secondary navigation         | #page-header .menu-block-main-menu-level2       |
      | header search trigger        | .menu-block-main-menu-level1 .search .fa-search |
      | mobile header search trigger | .logo-wrapper .search .fa-search                |
      | mobile header menu trigger   | .logo-wrapper button .title                     |

  @api @javascript @PW-1044
  Scenario Outline: Anonymous user cannot see primary and secondary navigation links on the homepage at the extra_small breakpoint
    Given I am viewing the site on a "<breakpoint>" screen
    And I go to the homepage
    Then I see header over content
    And I see logo, mobile header search trigger and mobile header menu trigger inside of header
    And I see logo to the left of mobile header search trigger and mobile header menu trigger
    And I see mobile header search trigger to the left of mobile header menu trigger
    And I don't see primary navigation
    And I don't see secondary navigation
    Examples:
      | breakpoint  |
      | extra_small |
      | small       |

  @api @javascript @PW-1044
  Scenario Outline: Anonymous user can see primary and secondary navigation links on the homepage at the medium breakpoint
    Given I am viewing the site on a "<breakpoint>" screen
    And I go to the homepage
    Then I see header above content
    And I see logo, primary navigation and secondary navigation inside of header
    And I see primary navigation above secondary navigation
    And I see logo below primary navigation
    And I see header search trigger inside of primary navigation
    And I don't see mobile header search trigger and mobile header menu trigger
    Examples:
      | breakpoint  |
      | medium      |
      | large       |
      | extra_large |

  @api @javascript @PW-1044
  Scenario: Anonymous user cannot see primary and secondary navigation links on the page other than homepage at the extra_small breakpoint
    Given I am viewing the site on a extra_small screen
    When I visit "/courses"
    Then I see header above content
    And I see logo inside of header
    And I don't see primary navigation
    And I don't see secondary navigation

  @api @javascript @PW-1044
  Scenario: Anonymous user cannot see primary and secondary navigation links on the page other than homepage at the small breakpoint
    Given I am viewing the site on a small screen
    When I visit "/courses"
    Then I see header above content
    And I see logo inside of header
    And I don't see primary navigation
    And I don't see secondary navigation

  @api @javascript @PW-1044
  Scenario: Anonymous user can see primary and secondary navigation links on the page other than homepage at the medium breakpoint
    Given I am viewing the site on a medium screen
    When I visit "/courses"
    Then I see header above content
    And I see logo, primary navigation and secondary navigation inside of header
    And I see primary navigation inside of header
    And I see primary navigation above secondary navigation
    And I see logo below primary navigation

  @api @javascript @PW-1044
  Scenario: Anonymous user can see primary and secondary navigation links on the page other than homepage at the large breakpoint
    Given I am viewing the site on a large screen
    When I visit "/courses"
    Then I see header above content
    And I see logo, primary navigation and secondary navigation inside of header
    And I see primary navigation inside of header
    And I see primary navigation above secondary navigation
    And I see logo below primary navigation

  @api @javascript @PW-1044d
  Scenario: Anonymous user cannot see secondary navigation on Campuses pages at the medium breakpoint
    Given I am viewing the site on a medium screen
    When I visit "/campuses"
    Then I see header above content
    And I see logo and primary navigation inside of header
    And I see logo below primary navigation
    And I don't see secondary navigation

  @api @javascript @PW-1044
  Scenario: Anonymous user cannot see secondary navigation on Campuses pages at the large breakpoint
    Given I am viewing the site on a large screen
    When I visit "/campuses"
    Then I see header above content
    And I see logo and primary navigation inside of header
    And I see logo below primary navigation
    And I don't see secondary navigation

  @api @javascript @PW-1044
  Scenario: Anonymous user cannot see secondary navigation on Contact Us pages at the medium breakpoint
    Given I am viewing the site on a medium screen
    When I visit "/contact-us"
    Then I see header above content
    And I see logo and primary navigation inside of header
    And I see logo below primary navigation
    And I don't see secondary navigation

  @api @javascript @PW-1044
  Scenario: Anonymous user cannot see secondary navigation on Contact Us pages at the large breakpoint
    Given I am viewing the site on a large screen
    When I visit "/contact-us"
    Then I see header above content
    And I see logo and primary navigation inside of header
    And I see logo below primary navigation
    And I don't see secondary navigation
