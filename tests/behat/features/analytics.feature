@p1
Feature: Analytics

  As a business owner I want to ensure that Analytics is loaded on the page.

  Note that the Google Tag manager test will work only if there is no $conf['gtm_id'] value
  specified for the environment where it is been tested.

  @api @PW-483
  Scenario: Google tag manager is loaded when variable is set
    Given I set variable "gtm_id" to value "GTM-TNRVD4"
    And I clear the theme cache
    And I am on the homepage
    Then the response should contain "https://www.googletagmanager.com/ns.html?id=GTM-TNRVD4"

  @api @PW-483
  Scenario: Google tag manager is not loaded when variable is not set
    Given I delete variable "gtm_id"
    When I clear the theme cache
    And I am on the homepage
    Then the response should not contain "https://www.googletagmanager.com/ns.html?id=GTM-TNRVD4"

  @api @PW-2703
  Scenario: Marketo is loaded when variable is 1
    Given I set variable "vu_marketo" to value 1
    And I clear the theme cache
    And I am on the homepage
    Then the response should contain "vu_core.marketo.js"

  @api @PW-2703
  Scenario: Marketo is not loaded when variable is 0
    Given I set variable "vu_marketo" to value 0
    When I clear the theme cache
    And I am on the homepage
    Then the response should not contain "vu_core.marketo.js"
