@p1 @leftnav
Feature: Left navigation on different pages

  As a prospective student
  I want the ability to use left navigation
  So that I can access inner pages

  @javascript @PW-233 @skipped
  Scenario: Main menu navigation is present on pages that are listed in IA on mobile device
    Given I am viewing the site on a mobile device
    When I am on "/study-at-vu/courses"
    Then I see visible left nav main menu
    And I don't see left nav subsites
    And I don't see left nav collapse text and left nav list
    And I see left nav collapse trigger inside of left nav main menu
    When I click a left nav collapse trigger
    And wait 1 second
    Then I see left nav list and left nav collapse trigger inside of left nav main menu
    And I don't see left nav collapse text
    When I click a left nav collapse trigger
    And wait 1 second
    Then I don't see left nav collapse text and left nav list
    And I see left nav collapse trigger inside of left nav main menu

  @javascript @PW-233 @skipped
  Scenario: Main menu navigation is present on pages that are listed in IA on tablet device
    Given I am viewing the site on a tablet device
    When I am on "/study-at-vu/courses"
    Then I see visible left nav main menu
    And I don't see left nav subsites
    And I see left nav list and left nav collapse text inside of left nav main menu
    And I don't see left nav collapse trigger

  @javascript @PW-233 @skipped
  Scenario: Main menu navigation is present on pages that are listed in IA on desktop device
    Given I am viewing the site on a desktop device
    When I am on "/study-at-vu/courses"
    Then I don't see visible left nav main menu
    And I don't see left nav subsites
    And I see left nav list and left nav collapse text inside of left nav main menu
    And I don't see left nav collapse trigger

  @javascript @PW-233 @skipped
  Scenario: Main menu navigation is present on pages that are listed in subsites on mobile device
    Given I am viewing the site on a mobile device
    When I am on "/vu-sydney/campus-facilities-services"
    Then I don't see left nav subsites
    And I don't see left nav main menu
    And I don't see left nav collapse text and left nav list
    And I see left nav collapse trigger inside of left nav subsites
    When I click a left nav collapse trigger
    And wait 1 second
    Then I see left nav list and left nav collapse trigger inside of left nav subsites
    And I don't see left nav collapse text
    When I click a left nav collapse trigger
    And wait 1 second
    Then I don't see left nav collapse text and left nav list
    And I see left nav collapse trigger inside of left nav subsites

  @javascript @PW-233 @skipped
  Scenario: Main menu navigation is present on pages that are listed in subsites on tablet device
    Given I am viewing the site on a tablet device
    When I am on "/vu-sydney/campus-facilities-services"
    Then I don't see left nav subsites
    And I don't see left nav main menu
    And I see left nav list and left nav collapse text inside of left nav subsites
    And I don't see left nav collapse trigger

  @javascript @PW-233 @skipped
  Scenario: Main menu navigation is present on pages that are listed in subsites on desktop device
    Given I am viewing the site on a desktop device
    When I am on "/vu-sydney/campus-facilities-services"
    Then I don't see left nav subsites
    And I don't see left nav main menu
    And I see left nav list and left nav collapse text inside of left nav subsites
    And I don't see left nav collapse trigger
