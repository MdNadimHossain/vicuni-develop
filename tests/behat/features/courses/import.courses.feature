@p0 @feeds @api @javascript
Feature: Feeds import: Courses
  Ensure feeds imports the courses correctly

  @PW-532 @127432907 @PW-471
  Scenario: Workflow
    Given I am logged in as a user with the "administrator" role

    # Ensure the four results are at their expected beginning states.
    Then the courses node where field_unit_code is "TEST-WORKFLOW-NEW" should have 0 results.
    Then the courses node where field_unit_code is "TEST-WORKFLOW-EXISTS-1" should be unpublished.
    And the courses node where field_unit_code is "TEST-WORKFLOW-EXISTS-2" should be published.
    And the courses node where field_unit_code is "TEST-WORKFLOW-EXISTS-3" should be published.

    # Import the courses workflow xml.
    Then I am at "import/courses"
    And I attach the file "feeds/courses-workflow.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    Then I should see "Created 1 content."
    And I should see "Updated 3 nodes."

    # Ensure the four results are as expected.
    Then the courses node where field_unit_code is "TEST-WORKFLOW-NEW" should have 1 result.
    And the courses node where field_unit_code is "TEST-WORKFLOW-NEW" should be unpublished.
    And the courses node where field_unit_code is "TEST-WORKFLOW-EXISTS-1" should be unpublished.
    And the courses node where field_unit_code is "TEST-WORKFLOW-EXISTS-2" should be unpublished.
    And the courses node where field_unit_code is "TEST-WORKFLOW-EXISTS-3" should be published.

  @129807761 @133715675
  Scenario: Flags
    Given I am logged in as a user with the "administrator" role

  # Ensure the three results are at their expected beginning states.
    Then the courses node where field_unit_code is "TEST-FLAGS-1" should be unpublished.
    And the courses node where field_unit_code is "TEST-FLAGS-2" should be published.
    And the courses node where field_unit_code is "TEST-FLAGS-3" should have 0 results.

  # Import the courses workflow flags xml.
    Then I am at "import/courses"
    And I attach the file "feeds/courses-workflow-flags.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    Then I should see "Created 1 content."
    And I should see "Updated 2 nodes."

  # Verify that TEST-FLAGS-2 has been unpublished.
    Then I am at "courses/test-flags-2-test-flags-2"
    Then I should see "Revision state: Draft"
    And the courses node where field_unit_code is "TEST-FLAGS-2" should be unpublished.

  @natest @133715675 @130171817
  Scenario: Non-Award
    Given I am logged in as a user with the "administrator" role

    # Ensure that TEST-FLAGS-NA is at its expected beginning state.
    Then the courses node where field_unit_code is "TEST-FLAGS-NA" should be published.

    # Import the courses workflow flags non-award xml.
    Then I am at "import/courses"
    And I attach the file "feeds/courses-workflow-flags-na.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    And I should see "Updated 1 content."

    # Ensure that TEST-FLAGS-NA is still published.
    Then the courses node where field_unit_code is "TEST-FLAGS-NA" should be published.

    # Verify that TEST-FLAGS-NA has been updated.
    Then I am at "courses/test-flags-na-test-flags-na"
    Then I should see "Changed Location"

  @mappingTest @PW-532 @127432907
  Scenario Outline: Mapping
    Given I am logged in as a user with the "administrator" role

    # Import the courses base xml.
    Then I am at "import/courses"
    And I attach the file "feeds/courses-mapping-<File>.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    Then I should see "Created 1 content."

    # Import the courses international xml.
    Then I am at "import/courses"
    And I attach the file "feeds/courses-mapping-international.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    Then I should see "Updated 1 content."

    # Ensure base mapping was successful.
    Then the courses node where field_unit_code is "TEST-MAPPING-<Code>" should have 1 result.
    And the courses node where field_unit_code is "TEST-MAPPING-<Code>" should have the following data:
      | field                      | value                                 |
      | field_unit_code            | TEST-MAPPING-<Code>                   |
      | title                      | <Code> mapping test                   |
      | field_course_sort_title    | <Sort title> mapping test             |
      | field_imp_desc             | <p>Introduction</p>                   |
      | field_imp_object           | <p>Course learning outcomes</p>       |
      | field_locations            | Location                              |
      | field_location_other       | Location other                        |
      | field_college:0:title      | VU College                            |
      | field_college:0:url        | about-vu/academic-colleges/vu-college |
      | field_cricos_code          | Cricos Code                           |
      | field_unit_lev             | <Course level>                        |
      | field_duration             | Course duration                       |
      | field_imp_career           | <p>Career outcomes</p>                |
      | field_completion_rules     | <p>Course completion rules</p>        |
      | field_imp_delivery_mode    | Delivery mode                         |
      | field_course_aqf           | <AQF>                                 |
      | field_study_mode           | Full Time                             |
      | field_course_units:0:title | TEST-MAPPING-UNIT                     |
      | field_course_units:0:type  | unit                                  |
      | field_course_units:1:title | TEST-MAPPING-UNITSET                  |
      | field_course_units:1:type  | unit_set                              |

    And the courses node where field_unit_code is "TEST-MAPPING-<Code>" should have the following value in field_imp_structure:
    """
    <structure>
                <section>
                    <line>
                        <unitid>TEST-MAPPING-UNIT</unitid>
                        <isUnitSet>N</isUnitSet>
                    </line>
                    <line>
                        <unitid>TEST-MAPPING-UNITSET</unitid>
                        <isUnitSet>Y</isUnitSet>
                    </line>
                </section>
            </structure>
    """

    And the courses node where field_unit_code is "TEST-MAPPING-<Code>" should have the following value in field_imp_admission_requirements:
    """
    <ul><li>TAFE: Admission requirements VET</li><li>Year 12: Admission requirements senior secondary</li><li>Mature: Admission requirements mature age</li><li>Other: Admission requirements other</li></ul>
    """

    # Ensure international mapping was successful.
    Then the courses node where field_unit_code is "TEST-MAPPING-<Code>" should have 1 result.
    And the courses node where field_unit_code is "TEST-MAPPING-<Code>" should have the following data:
      | field                          | value                   |
      | field_additional_costs         | <p>Additional costs</p> |
      | field_imp_inter_campus:0:title | Test campus             |
      | field_international            | 1                       |

    And the courses node where field_unit_code is "TEST-MAPPING-<Code>" should have the following value in field_int_sem_int:
    """
    <semesterintakes>
                <semesterintake year="2016">1,2</semesterintake>
            </semesterintakes>
    """

    And the courses node where field_unit_code is "TEST-MAPPING-<Code>" should have the following value in field_international_fees:
    """
    <fees>
                <fee year="2016">1</fee>
                <additionalcosts><p>Additional costs</p></additionalcosts>
            </fees>
    """


    Examples:
      | File | Code | Sort title | Course level | AQF             |
      | he   | HE   | he         | undergrad    | Bachelor Degree |
      | na   | NA   | na         | short        |                 |
      | vet  | VET  | vet        | tafe         | Diploma         |

  @VET_Title @PW-532
  Scenario: VET courses should have course code in the title
    Given I am logged in as a user with the "administrator" role

    # Import the courses base xml.
    Then I am at "import/courses"
    And I attach the file "feeds/courses-mapping-vet.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    Then I should see "Created 1 content."

    And the courses node where field_unit_code is "TEST-MAPPING-VET" should have the following data:
      | field | value            |
      | title | VET mapping test |

  @HE_Title @PW-532
  Scenario: HE courses should not have the course code in the title
    Given I am logged in as a user with the "administrator" role

    # Import the courses base xml.
    Then I am at "import/courses"
    And I attach the file "feeds/courses-mapping-he.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    Then I should see "Created 1 content."

    And the courses node where field_unit_code is "TEST-MAPPING-HE" should have the following data:
      | field | value           |
      | title | HE mapping test |

  @NA_Title @PW-532
  Scenario: Non-award courses should not have the course code in the title
    Given I am logged in as a user with the "administrator" role

    # Import the courses base xml.
    Then I am at "import/courses"
    And I attach the file "feeds/courses-mapping-na.xml" to "files[feeds]"
    And I press the "Import" button
    Then I wait for the batch job to finish
    Then I should see "Created 1 content."

    And the courses node where field_unit_code is "TEST-MAPPING-NA" should have the following data:
      | field | value           |
      | title | NA mapping test |
