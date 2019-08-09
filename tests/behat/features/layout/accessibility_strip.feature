@p1
Feature: Accessibility strip

  As a user employing a screen-reader
  I want the ability to skip to content and view accessibility information on
  any device so that I can navigate the site using a screen reader.

  @api @javascript @PW-814
  Scenario Outline: Anonymous user does not see accessibility strip at the extra_small breakpoint
    Given I am viewing the site on a "<breakpoint>" screen
    When I go to the homepage
    Then I don't see accessibility strip
    Examples:
      | breakpoint  |
      | extra_small |
      | small       |
      | medium      |
      | large       |
      | extra_large |

  @api @javascript @PW-814
  Scenario: Anonymous user sees accessibility strip at the extra_small breakpoint when pressing "tab" key
    Given I am viewing the site on a extra_small screen
    When I go to the homepage
    And I press the "tab" key
    Then I see visible accessibility strip
    And I see accessibility link, accessibility information and accessibility strip close button inside of accessibility strip
    And I see accessibility link above accessibility information
    And I see accessibility strip close button to right of accessibility link and accessibility information
    And I see header not over accessibility strip

  @api @javascript @PW-814
  Scenario Outline: Anonymous user sees accessibility strip at the breakpoints small and up when pressing "tab" key
    Given I am viewing the site on a "<breakpoint>" screen
    When I go to the homepage
    And I press the "tab" key
    Then I see visible accessibility strip
    And I see accessibility link, accessibility information and accessibility strip close button inside of accessibility strip
    And I see accessibility link to left of accessibility information
    And I see accessibility strip close button to right of accessibility link and accessibility information
    And I see header not over accessibility strip

    Examples:
      | breakpoint  |
      | small       |
      | medium      |
      | large       |
      | extra_large |
