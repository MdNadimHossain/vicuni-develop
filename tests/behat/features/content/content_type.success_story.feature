@p0
Feature: Content type: Success Story

  As a prospective student
  I want to read Success Story on any device
  In order to find out about the VU offer

  Background:
    Given I define components:
      | body                | .node                                          |
      | body content column | .main-content-wrapper .field-name-body .column |

  @javascript @PW-254
  Scenario: Anonymous user viewing success story page on mobile device
    Given I am viewing the site on a mobile device
    When I visit a page of Success Story content type
    Then I see header over page title, body and content feature image
    And I see legacy title box above page title and body
    And I see page title above body
    And I don't see sticky header
    And I see content feature image inside of body
    And I see content feature image below body content column
    And I see footer below page title, body and content feature image

  @javascript @PW-254
  Scenario: Anonymous user viewing success story page on tablet device
    Given I am viewing the site on a tablet device
    When I visit a page of Success Story content type
    Then I see header over legacy title box, page title, body and content feature image
    And I see legacy title box above page title and body
    And I see page title above body
    And I don't see sticky header
    And I see content feature image to right of body content column
    And I see footer below page title, body and content feature image

  @javascript @PW-254
  Scenario: Anonymous user viewing success story page on desktop
    Given I am viewing the site on a desktop device
    When I visit a page of Success Story content type
    Then I see header above legacy title box, page title, body and content feature image
    And I see legacy title box above page title and body
    And wait 1 second
    And I see sticky header over body
    And I see content feature image inside of body
    And I see content feature image to right of body content column
    And I see footer below page title, body and content feature image

  @api @PW-1675
  Scenario: Feature tile text and Courses Studied fields should not appear in full content view mode.
    Given I am logged in as a user with the "administrator" role
    And I create a published success_story with content:
      | title                              | Test success story |
      | field_featured_tile_text           | Featured Tile Text |
      | field_course_studied               | Courses studied    |
      | field_success_categories           | Student            |
      | status                             | 1                  |
      | workbench_moderation_state_current | published          |
      | language                           | und                |
    Then I should not see "Featured Tile Text" in the ".node-success-story" element
    And I should not see "Courses studied" in the ".node-success-story" element

  @PW-5298 @api @javascript
  Scenario: Success story new theme
    Given I am viewing the site on a large screen

    And I am logged in as a user with the approver role
    And I create a published 'success_story' with content:
      | title                              | Test success story |
      | field_theme                        | victory            |
      | field_person_name                  | Test name          |
      | field_excerpt                      | Test quote         |
      | field_course_studied               | Courses studied    |
      | body                               | test description   |
      | field_featured_tile_text           | Featured Tile Text |
      | field_success_categories           | Student            |
      | status                             | 1                  |
      | workbench_moderation_state_current | published          |
      | language                           | und                |

    And I should see "Test success story" in the ".page-header" element
    And I should see "Test quote" in the ".success-story-excerpt" element
    And I should see "Test name" in the ".success-story-name" element
    And I should see "Courses studied" in the ".success-story-courses" element
    And I should see "test description" in the ".field-name-body" element
