@p1 @feeds @api @javascript
Feature: Feeds import: Units
  Ensure feeds imports the units correctly

  @PW-1152 @PW-1184
  Scenario: Prerequisites
    Given I am logged in as a user with the "administrator" role

    # Import the units xml.
    Then I am at "import/units"
    And I attach the file "feeds/unit-mapping.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    # Ensure prerequisites are displayed.
    Then I am at "units/UNITIMPORTTEST"
    And I should see "Prerequisites"
    And I should see "Prerequisite 1 & a thing"
    And I should see "Prerequisite 2 - another thing"

