@testapi
Feature: Check that variable assertions work

  As a developer, I want to know that variable step definitions work
  as expected.

  @api
  Scenario: Setting and asserting variables.
    Given I set variable "random_test_var1" to value "my value"
    Then variable "random_test_var1" has value "my value"
    And I delete variable "random_test_var1"

  @api
  Scenario: Preserving original variables.
    Given I set variable "random_test_var2" to value "my value"
    Then variable "random_test_var2" has value "my value"
    And I store original variable "random_test_var2"

    When I set variable "random_test_var2" to value "my value2"
    Then variable "random_test_var2" has value "my value2"
    And variable "test_behat_random_test_var2" has value "my value"

    When I restore original variables
    Then variable "random_test_var2" has value "my value"
    And variable "test_behat_random_test_var2" does not have a value

    And I delete variable "random_test_var1"

  @api
  Scenario: Setting and asserting multiline variables.
    Given I set variable "random_test_var3" to value:
    """
    Line1
    Line2
    Line3
    """
    Then variable "random_test_var3" has value:
    """
    Line1
    Line2
    Line3
    """
    And I delete variable "random_test_var3"

  @api
  Scenario: Automated cleanup of set variable. Part 1.
    Given I set variable "random_test_var4" to value "my value"
    Then variable "random_test_var4" has value "my value"

  @api
  Scenario: Automated cleanup of set variable. Part 2.
    Given variable "random_test_var4" does not have a value
