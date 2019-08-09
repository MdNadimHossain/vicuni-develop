@p1
Feature: Shutter functionality

  Ensure that search and tools dropdown behaves as expected. Note that
  behaviours in off-canvas dropdowns are tested separately in responsive menu
  feature.

  Background:
    Given I define components:
      | shutter                       | .js-shutter                                                                            |
      | shutter close                 | .js-shutter .js-shutter-footer .close                                                  |
      | shutter logo                  | .js-shutter .logo img                                                                  |
      | shutter search trigger        | [data-shutter-item-target="#block-vu-core-vu-funnelback-search"]:nth-child(1)          |
      | shutter search mobile trigger | [data-shutter-item-target="#block-vu-core-vu-funnelback-search"]:nth-child(2)          |
      | shutter search block          | #block-vu-core-vu-funnelback-search                                                    |
      | shutter tools trigger         | [data-shutter-item-target="#block-menu-block-main-menu-tools"]                         |
      | shutter tools mobile trigger  | [data-target="#menu-nav-tools-collapse"]                                               |
      | shutter tools block           | #block-menu-block-main-menu-tools                                                      |

  #### Search shutter ####
  @javascript
  Scenario: Search shutter on any page on a mobile device
    Given I am viewing the site on a mobile device
    And I visit a page of News & Media content type
    And wait 1 seconds
    And I see visible shutter search mobile trigger
    And I don't see shutter search trigger and shutter tools trigger
    And I don't see shutter, shutter logo and overlay
    And I don't see shutter search block
    # Open shutter with search block.
    When I click on shutter search mobile trigger
    And wait 1 seconds
    Then I see visible shutter, shutter logo and overlay
    And I see visible shutter search block
    And I see shutter over shutter search mobile trigger
    # Close shutter with search block.
    When I click on shutter close
    And wait 1 second
    Then I don't see shutter logo
    And I don't see shutter search block
    And I see visible shutter search mobile trigger

  @javascript
  Scenario: Search shutter on any page on a tablet device
    Given I am viewing the site on a tablet device
    And I visit a page of News & Media content type
    And wait 1 seconds
    And I see visible shutter search mobile trigger
    And I don't see shutter search trigger and shutter tools trigger
    And I don't see shutter, shutter logo and overlay
    And I don't see shutter search block
    # Open shutter with search block.
    When I click on shutter search mobile trigger
    And wait 1 seconds
    And save screenshot
    Then I see visible shutter, shutter logo and overlay
    And I see visible shutter search block
    And I see shutter over shutter search mobile trigger
    # Close shutter with search block.
    When I click on shutter close
    And wait 1 seconds
    Then I don't see shutter logo
    And I don't see shutter search block
    And I see visible shutter search mobile trigger

  @javascript
  Scenario: Search shutter on any page on a desktop device
    Given I am viewing the site on a desktop device
    And wait 1 seconds
    And I visit a page of News & Media content type
    And I see visible shutter search trigger and shutter tools trigger
    And I don't see shutter, shutter logo and overlay
    And I don't see shutter search block
    # Open shutter with search block.
    When I click on shutter search trigger
    And wait 1 seconds
    Then I see visible shutter, shutter logo and overlay
    And I see visible shutter search block
    And I see shutter over shutter search trigger and shutter tools trigger
    # Close shutter with search block.
    When I click on shutter close
    And wait 1 seconds
    Then I don't see shutter logo
    And I don't see shutter search block
    And I see visible shutter search trigger and shutter tools trigger

  #### Tools shutter ####
  # Note that mobile tools dropdown is now tested as a part of responsive menu.
  @javascript
  Scenario: Tools shutter on any page on a desktop device
    Given I am viewing the site on a desktop device
    And wait 1 seconds
    And I visit a page of News & Media content type
    And I see visible shutter search trigger and shutter tools trigger
    And I don't see shutter, shutter logo and overlay
    And I don't see shutter tools block
    # Open shutter with search block.
    When I click on shutter tools trigger
    And wait 1 second
    Then I see visible shutter, shutter logo and overlay
    And I see visible shutter tools block
    And I see shutter over shutter search trigger and shutter tools trigger
    # Close shutter with search block.
    When I click on shutter close
    And wait 1 second
    Then I don't see shutter logo
    And I don't see shutter tools block
    And I see visible shutter search trigger and shutter tools trigger
