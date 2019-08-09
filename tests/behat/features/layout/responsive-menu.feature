@p1
Feature: Responsive menu

  As anonymous visitor, I want to have access to responsive menu on mobile
  and tablet devices, so that I could have access to other pages of the website.

  Background:
    Given I define components:
      | mobile menu trigger          | .logo-wrapper .js-offcanvas-trigger               |
      | mobile menu                  | #responsive-nav                                   |
      | mobile menu dropdown trigger | #responsive-nav .js-menu-item-login               |
      | mobile menu dropdown         | #responsive-nav .menu-nav-dropdown-items li:first |
      | overlay                      | #responsiveMenuOverlay                            |

  @api @javascript @PW-1048 @PW-1491
  Scenario Outline: Button should and menu should not be visible at extra_small and small breakpoints
    Given I am viewing the site on a "<breakpoint>" screen
    And I am on the homepage
    And I see mobile menu trigger inside of header
    And I don't see mobile menu
    # Open mobile menu.
    When I click a mobile menu trigger
    And wait 2 seconds
    And save screenshot
    Then I see mobile menu to right of header, content, footer, mobile menu trigger and overlay
    And I see mobile menu dropdown trigger inside of mobile menu
    And I don't see mobile menu dropdown
    # Open dropdown within mobile menu.
    When I click a mobile menu dropdown trigger
    And wait 2 second
    And save screenshot
    Then I see mobile menu dropdown below mobile menu dropdown trigger
    And I see mobile menu dropdown to right of header, content, footer, mobile menu trigger and overlay
    # Close dropdown within mobile menu.
    When I click a mobile menu dropdown trigger
    And wait 2 seconds
    And save screenshot
    Then I don't see mobile menu dropdown
    And I see mobile menu dropdown trigger inside of mobile menu
    And I see mobile menu to right of header, content, footer, mobile menu trigger and overlay
    # Close  mobile menu.
    When I press the "esc" key
    And wait 4 seconds
    And I don't see mobile menu, mobile menu dropdown, mobile menu dropdown trigger and overlay

    Examples:
      | breakpoint  |
      | extra_small |
      | small       |

  @api @javascript @PW-1048 @PW-1491
  Scenario Outline: Both button and menu should not be visible at medium and up breakpoints
    Given I am viewing the site on a "<breakpoint>" screen
    When I am on the homepage
    Then I don't see mobile menu, mobile menu trigger, mobile menu dropdown, mobile menu dropdown trigger and overlay
    Examples:
      | breakpoint  |
      | medium      |
      | large       |
      | extra_large |
