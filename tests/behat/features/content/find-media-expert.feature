@p0
Feature: Find media expert

  Ensure "Find a media expert" page exists and is accessible.

  @130737393
  Scenario: Find a media expert page exists
    Given I am an anonymous user
    When I visit "/about-vu/news-events/find-a-media-expert"
    Then the page title should be "Find a media expert | Victoria University | Melbourne Australia"

  @130737393
  Scenario Outline: "Find a media expert" form sends query to "Find a media expert" page
    Given I am an anonymous user
    When I am on "<path>"
    And I click "Find a media expert"
    Then the page title should be "Find a media expert | Victoria University | Melbourne Australia"
    And I should be in the "about-vu/news-events/find-a-media-expert" path

    Examples:
      | path                                     |
      | contact-us                               |
      | about-vu/news-events/find-a-media-expert |
