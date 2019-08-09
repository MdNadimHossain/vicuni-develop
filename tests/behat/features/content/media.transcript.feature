@p0 @transcript
Feature: Content type: Transcript

  Ensure that the Transcript content type behaves as expected.

  Background:
    Given I define components:
      | page title             | #page-header                       |
      | media video transcript | .field-name-field-video-transcript |
      | media video            | .media-youtube-video               |

  @javascript @api @PW-254
  Scenario: Anonymous user viewing video transcript page on mobile
    Given I am viewing the site on a mobile device
    When I am on "/transcript/st-albans-campus-tour-transcript"
    Then I see header above title box
    And I see page title above media video and media video transcript
    And I see media video above media video transcript
    And I see footer below title box

  @javascript @api @PW-254
  Scenario: Anonymous user viewing video transcript page on tablet
    Given I am viewing the site on a tablet device
    When I am on "/transcript/st-albans-campus-tour-transcript"
    Then I see page title above media video and media video transcript
    And I see media video above media video transcript
    And I see footer below page title, media video and media video transcript

  @javascript @api @PW-254 @PW-554
  Scenario: Anonymous user viewing video transcript page on desktop
    Given I am viewing the site on a large device
    When I am on "/transcript/st-albans-campus-tour-transcript"
    Then I see header above title box
    And I see page title above media video and media video transcript
    And I see media video above media video transcript
    And I see footer below page title, media video and media video transcript
