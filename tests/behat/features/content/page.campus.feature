@p0
Feature: Page: Campuses

  As a prospective student
  I want the ability to view Campuses page on any device
  So that I can get more information about VU campuses

  Background:
    Given I define components:
      | content region         | .region-content                        |

  @javascript @PW-420
  Scenario: Anonymous user viewing Campuses page on a mobile device
    Given I am viewing the site on a mobile device
    When I am on "/campuses"
    Then I see header over title box
    And I don't see sticky header
    And I see title box above content region

  @javascript @PW-420
  Scenario: Anonymous user viewing Campuses page on a tablet device
    Given I am viewing the site on a tablet device
    When I am on "/campuses"
    Then I see header over title box
    And I don't see sticky header
    And I don't see featured content
    And I see title box above content region

  @javascript @PW-420 @PW-211
  Scenario: Anonymous user viewing Campuses page on a desktop device
    Given I am viewing the site on a desktop device
    When I am on "/campuses"
    Then I see header above title box
    And wait 1 second
    And I see title box above content region
