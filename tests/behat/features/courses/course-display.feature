@p0
Feature: Course essentials block
  As a prospective student
  I should be able to view the content in the course essentials block

  Background:
    Given I define components:
      | on this page             | #block-vu-core-vu-on-page-nav                                  |
      | course essentials        | #block-ds-extras-course-essentials                             |
      | he other locations block | #block-vu-core-vu-cbs-he-other-locations                       |
      | international course link | .international-switcher-content .course-link .non-residents a |

  @javascript
  Scenario Outline: Anonymous users should see course essential block on courses pages
    Given I am viewing the site on a large device
    When I am on "<path>"
    Then I see header above title box
    And wait 1 second
    # make sure elements are on the page
    Then I should see "VU course code:" in the "#block-ds-extras-title-area-course-information" element
    Then I should see "<course_code>" in the ".field-name-field-unit-code" element
    And I should see "Offered by:" in the "#block-ds-extras-title-area-course-information" element
    # make sure college has content
    And the element ".field-name-field-college .field-item" is not empty
    And I see visible course essentials
    Then I should see "Duration:" in the "#block-ds-extras-course-essentials" element

    Examples:
      | path                                                                   | course_code |
      | courses/diploma-of-building-and-construction-building-cpc50210         | cpc50210    |
      | courses/diploma-of-business-enterprise-vdbe                            | vdbe        |
      | courses/bachelor-of-arts-abab                                          | abab        |
      | courses/graduate-certificate-in-business-administration-btpf           | btpf        |
      | courses/alcohol-and-other-drugs-co-existing-needs-skill-set-chcss00092 | chcss00092  |
      | courses/doctor-of-business-administration-bppb                         | bppb        |

  @javascript @PW-4831
  Scenario: Vicpoly on this page nav has right color
  Given I am on "courses/diploma-of-building-and-construction-building-cpc50210"
  And element ".field-name-field-college .field-item a" exists
  And I see visible on this page
  Then element ".victoria-polytechnic #block-vu-core-vu-on-page-nav.switch-on" exists
  When I am on "courses/bachelor-of-arts-abab"
  And I see visible on this page
  Then element ".victoria-polytechnic #block-vu-core-vu-on-page-nav.switch-on" does not exist

  @javascript @api @PW-5037
  Scenario: Users should see the Materials Fee block on international courses pages
    Given I am viewing the site on a large device
    And I am logged in as a user with the approver role
    When I create a published courses with content:
      | title                         | [TEST] Test international course |
      | field_unit_code               | TEST2018                         |
      | field_domestic                | Yes                              |
      | field_international           | Yes                              |
      | field_unit_lev                | undergrad                        |
      | field_materials_fee           | Hammers are required             |
    Then I should not see the text "Materials fee"

    When I click on international course link
    And wait 1 second
    Then I see the text "Materials fee"
    And I see the text "Hammers are required"

  @javascript @api @PW-5113
  Scenario: Users should see Supplementary Date Info on the courses page
    Given I am viewing the site on a large device
    And I am logged in as a user with the approver role
    When I create a published courses with content:
      | title                         | [TEST] Test course      |
      | field_unit_code               | BMPF                    |
      | field_domestic                | Yes                     |
      | field_unit_lev                | undergrad               |
      | field_supplementary_date_info | Supplementary date info |
    Then element ".supplementary-date-info" exists
    And I see the text "Supplementary date info"

  @javascript @PW-5058
  Scenario Outline: Anonymous users should see FYM block for Bachelor or Embedded Honours courses
    Given I am viewing the site on a large device
    When I am on "<path>"
    Then I should see "Achieve more with the VU Block Model" in the "#course-structure" element

    Examples:
      | path                                                 |
      | courses/bachelor-of-arts-abab                        |
      | courses/bachelor-of-laws-honours-graduate-entry-lhge |

  @javascript @PW-5058
  Scenario Outline: Anonymous users should not see FYM block for Associate Degree or Stand Alone Honours courses
    Given I am viewing the site on a large device
    When I am on "<path>"
    Then I should not see "Achieve more with the VU Block Model" in the "#course-structure" element

    Examples:
      | path                                                                 |
      | courses/associate-degree-in-hospitality-and-hotel-management-vahh    |
      | courses/bachelor-of-psychological-studies-honours-ahpa               |
      | courses/bachelor-of-science-honours-biomedical-sciences-shbm         |
      | courses/bachelor-of-science-honours-nutrition-and-food-sciences-shnf |


  @javascript @api @PW-5033
  Scenario: Users should see Other locations block on HE courses pages
    Given I am viewing the site on a large screen
    And I am logged in as a user with the approver role
    And I create a published courses with content:
      | title                         | [TEST] Test course  |
      | field_domestic                | Yes                 |
      | field_location_other_editable | Whitten Oval        |
      | field_unit_lev                | undergrad           |
    Then I see visible he other locations block
    And I see the text "Other locations"
