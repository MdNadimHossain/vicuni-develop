@p0
Feature: Content type: staff profile

  As a website user
  I want to read staff profile pages on any device
  So I can find out about VU staff

  Background:
    Given I define components:
      | page title                        | .page-header                    |
      | staff profile contact information | .group-contact-us               |

  @javascript @api @PW-254
  Scenario: Anonymous user viewing staff profile page on mobile device
    Given I am viewing the site on a mobile device
    When I am on "/contact-us/janine-dixon"
    And I see page title and breadcrumbs inside of title box
    Then I see header over title box
    And I see page title above body
    And I see staff profile photo below body
    And I see staff profile contact information below staff profile photo
    And I see footer below page title, body, staff profile contact information and staff profile photo

  @javascript @api @PW-254
  Scenario: Anonymous user viewing staff profile page on tablet device
    Given I am viewing the site on a tablet device
    When I am on "/contact-us/janine-dixon"
    Then I see header over title box, page title, body, staff profile contact information and staff profile photo
    And I see title box above body
    And I see page title inside of title box
    And I see staff profile photo to right of page title and body
    And I see staff profile contact information to right of page title and body
    And I see staff profile contact information below staff profile photo
    And I see footer below title box, page title, body, staff profile contact information and staff profile photo

  @javascript @api @PW-254
  Scenario: Anonymous user viewing staff profile page on desktop
    Given I am viewing the site on a desktop device
    When I am on "/contact-us/janine-dixon"
    Then I see header over title box, page title, body, staff profile contact information and staff profile photo
    And I see title box above body
    And I see page title inside of title box
    And wait 1 second
    And I see staff profile photo to right of page title and body
    And I see staff profile contact information to right of page title and body
    And I see staff profile contact information below staff profile photo
    And I see footer below title box, page title, body and staff profile contact information and staff profile photo
