@p1 @sitemap @PW-471
Feature: XML Sitemap

  Ensure that the XML Sitemap exists.

  Scenario: XML Sitemap is accessible
    Given the XML sitemap has been created
    And I am an anonymous user
    When I visit "sitemap.xml"
    Then the response status code should be 200
