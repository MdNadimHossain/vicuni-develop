@p1
Feature: Shutter

  Ensure that search and tools dropdown behaves as expected. Note that
  behaviours in off-canvas dropdowns are tested separately in responsive menu
  feature.

  Background:
    Given I define components:
      | header                       | #page-header                                                   |
      | shutter                      | .js-shutter                                                    |
      | shutter close                | .js-shutter .js-shutter-footer .close                          |
      | shutter logo                 | .js-shutter .logo img                                          |
      | header search trigger        | .menu-block-main-menu-level1 .search .fa-search                |
      | mobile header search trigger | .logo-wrapper .search .fa-search                               |
      | shutter search block         | #block-vu-core-vu-funnelback-search                            |
      | shutter tools trigger        | [data-shutter-item-target="#block-menu-block-main-menu-tools"] |
      | shutter tools mobile trigger | [data-target="#menu-nav-tools-collapse"]                       |
      | shutter tools block          | #block-menu-block-main-menu-tools                              |

  @api @javascript
  Scenario Outline: Search shutter on homepage at the extra_small and small breakpoints
    Given I am viewing the site on a "<breakpoint>" screen
    And I go to the homepage
    And I see visible mobile header search trigger
    And I don't see header search trigger and shutter tools trigger
    # @todo: Uncomment below when shutter is fixed.
    # And I don't see shutter, shutter logo and overlay
    And I don't see shutter and overlay
    And I don't see shutter search block
    # Open shutter with search block.
    When I click on mobile header search trigger
    And wait 1 second
    # @todo: Uncomment below when shutter is fixed.
    # And I don't see shutter, shutter logo and overlay
    Then I see visible shutter and overlay
    And I see visible shutter search block
    And I see shutter over mobile header search trigger
    # Close shutter with search block.
    When I click on shutter close
    And wait 1 second
    Then I don't see shutter logo
    And I don't see shutter search block
    And I see visible mobile header search trigger

    Examples:
      | breakpoint  |
      | extra_small |
      | small       |

  @api @javascript
  Scenario Outline: Search shutter on homepage at the breakpoints medium and above
    Given I am viewing the site on a "<breakpoint>" screen
    And I go to the homepage
    And I see visible header search trigger and shutter tools trigger
    # @todo: Uncomment below when shutter is fixed.
    # And I don't see shutter, shutter logo and overlay
    And I don't see shutter and overlay
    And I don't see shutter search block
    # Open shutter with search block.
    When I click on header search trigger
    And wait 1 second
    # @todo: Uncomment below when shutter is fixed.
    # Then I see visible shutter, shutter logo and overlay
    Then I see visible shutter and overlay
    And I see visible shutter search block
    And I see shutter over header search trigger and shutter tools trigger
    # Close shutter with search block.
    When I click on shutter close
    And wait 1 second
    # @todo: Uncomment below when shutter is fixed.
    Then I don't see shutter logo
    And I don't see shutter search block
    And I see visible header search trigger and shutter tools trigger
    Examples:
      | breakpoint  |
      | medium      |
      | large       |
      | extra_large |
