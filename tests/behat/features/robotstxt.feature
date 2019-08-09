@p1
Feature: Robots.txt

  Ensure that Robots.txt is accessible and have expected content

  Scenario: robots.txt is accessible and has content
    Given I am an anonymous user
    When I visit "robots.txt"
    Then the response should contain "Disallow: /*/search/"
    And the response should not contain "Disallow: /search/"
