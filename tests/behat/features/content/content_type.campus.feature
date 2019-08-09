@p0
Feature: Content type: Campus

  As a prospective student
  I want the ability to view campus pages on any device
  So that I can get more information about VU campuses

  Background:
  Given I define components:
    | body                | .node                                          |
    | campus introduction | .field-name-field-body                         |
    | campus map          | .map-component                                 |
    | page title          | .page-header                                   |
    | campus list         | #visit-our-other-campuses                      |

  @javascript @133229969
  Scenario: Anonymous user viewing event page on a mobile device
    Given I am viewing the site on a mobile device
    When I am on "/campuses/footscray-park"
    Then I see header over title box, campus list, page title, campus introduction, campus map
    And I see title box above campus list, campus introduction, campus map
    And I don't see sticky header
    And I don't see featured content small
    And I see campus introduction above campus list
    And I don't see campus video
    And I see page title above campus introduction, campus map
    And I see campus introduction above campus map
    And I see campus map above campus list
    And I see footer below title box, campus list, page title, campus introduction, campus map

  @javascript @133229969
  Scenario: Anonymous user viewing Campus page on a tablet device
    Given I am viewing the site on a tablet device
    When I am on "/campuses/footscray-park"
    Then I see header over title box, campus list, page title, campus introduction, campus map
    And I see title box above campus list, campus introduction, campus map
    And I don't see sticky header
    And I don't see featured content small
    And I see campus introduction above campus list
    And I don't see campus video
    And I see page title above campus introduction, campus map
    And I see campus introduction above campus map
    And I see campus map above campus list
    And I see footer below title box, campus list, page title, campus introduction, campus map
    

  @javascript @133229969
  Scenario: Anonymous user viewing Campus page on a desktop device
    Given I am viewing the site on a desktop device
    When I am on "/campuses/footscray-park"
    Then I see header over title box, campus list, page title, campus introduction, campus map
    And I see title box above campus list, campus introduction, campus map
    And I see page title inside of title box
    And I don't see sticky header
    And I don't see featured content small
    And I see campus introduction above campus list
    And I don't see campus video
    And I see page title above campus introduction, campus map
    And I see campus introduction above campus map
    And I see campus map above campus list
    And I see footer below title box, campus list, page title, campus introduction, campus map
