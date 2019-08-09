@p0
Feature: Content type: Courses

  Ensure that user roles have appropriate access to fields on Courses content type.

  @api
  Scenario Outline: User has access to course edit page
    Given I am logged in as a user with the "<role>" role
    When I go to "courses/doctor-of-business-administration-bppb"
    And I save screenshot
    Then I should see "New draft"
    When I click "New draft"
    Then I should get a 200 HTTP response

    # Fields user should see
    # Above tab fields
    And I should see "Feature image"

    # Dont see fields
    And element "#edit-title[disabled]" exists
    And element "#edit-field-domestic-und" does not exist
    And I don't see field "Sort title"
    And I don't see field "Course Code"
    And element "#edit-field-cut-off-date-und-0-value-datepicker-popup-0" does not exist
    And element "#edit-field-first-off-date-und-0-value-datepicker-popup-0" does not exist
    And I don't see field "Course Level"
    And I don't see field "Course ID"
    And I don't see field "Course Version"
    And element "#edit-field-college-und-0-title" does not exist
    And element "#edit-field-college-und-0-url" does not exist
    And element "#edit-field-locations-und-0-value" does not exist
    And element "#edit-field-location-other" does not exist
    And element "#edit-field-location-other-editable" exists
    And I don't see field "Duration"
    And I don't see field "Full Time"
    And I don't see field "Part Time"
    And element "#edit-field-international-und" exists
    And element "#edit-field-imp-inter-campus-und-0-target-id" does not exist
    And element "#edit-field-course-preceded-by-und-0-target-id" does not exist
    And element "#edit-field-course-followed-by-und-0-target-id" does not exist
    And element "#edit-field-imp-delivery-mode-und-0-value" does not exist
    And element "#edit-field-cricos-code-und-0-value" does not exist
    And I don't see field "AQF"

    # Overview tab
    And I should see "Overview"
    And I see field "Course search description"
    And I should see "DESCRIPTION (EDITABLE)"
    And I should see "Supplementary description information"
    And element "input#edit-field-short-dates-times-und-actions-ief-add" exists
    And element "input#edit-field-related-courses-und-0-target-id" exists
    And I should see "Introduction"
    # Dont see fields
    And element "#edit-field-imp-desc-und-0-value[disabled]" exists
    And I don't see field "Introduction (legacy)"

    # Careers tab
    And I should see "Careers"
    And I see field "Pathways information"
    And I see field "Career opportunities title (custom)"
    And I should see "CAREER OPPORTUNITIES"
    And I should see "Supplementary career information"
    And element "input#edit-field-related-success-stories-und-0-target-id" exists
    # Dont see fields

    # How to apply tab
    And I should see "How to apply"
    And I should see "Course Start Date"
    And I see field "How to apply title"
    And I should see "Supplementary application information"
    And I should see "International semester intake"
    And I should see "Supplementary Date Info"
    And I should see "Supplementary information domestic"
    And I should see "Supplementary information international"

    # Fees and scholarship tab
    And I should see "Fees and scholarship"
    And I see field "Additional costs"
    And I see field "Short courses domestic fees (AUD$)"
    And I should see "Fees And Scholarships Right"
    And I should see "International fees"
    And I should see "Materials fee"

    # Admissions & pathways tab
    And I should see "Admissions & pathways"
    And I see field "Atar Minimum Entry"
    And I see field "Atar Profile Data"
    # Dont see fields
    And I don't see field "Admission requirements"
    And I don't see field "English language requirements"
    And I don't see field "Atar Indicator"
    And I don't see field "Additional Information"
    And I don't see field "Additional requirements"
    And I don't see field "Admission Requirements SE"
    And I don't see field "Admission Requirements HE"
    And I don't see field "Admission Requirements VET"
    And I don't see field "Admission Requirements Work Life"
    And I don't see field "Entry Requirements PG"
    And I don't see field "Entry Requirements IN"
    And I don't see field "Entry Requirements VE"
    And element "input#edit-field-he-study-und-0-first" does not exist
    And element "input#edit-field-he-study-und-0-second" does not exist
    And element "input#edit-field-ve-study-und-0-first" does not exist
    And element "input#edit-field-ve-study-und-0-second" does not exist
    And element "input#edit-field-se-atar-only-und-0-first" does not exist
    And element "input#edit-field-se-atar-only-und-0-second" does not exist
    And element "input#edit-field-se-atar-plus-und-0-first" does not exist
    And element "input#edit-field-se-atar-plus-und-0-second" does not exist
    And element "input#edit-field-se-na-und-0-first" does not exist
    And element "input#edit-field-se-na-und-0-second" does not exist
    And element "input#edit-field-work-life-und-0-first" does not exist
    And element "input#edit-field-work-life-und-0-second" does not exist
    And element "input#edit-field-international-study-und-0-first" does not exist
    And element "input#edit-field-international-study-und-0-second" does not exist
    And element "input#edit-field-total-study-und-0-first" does not exist
    And element "input#edit-field-total-study-und-0-second" does not exist

    # Structure tab - dont see
    And element "#edit-field-course-units-und-actions-bundle" does not exist
    And I don't see field "Imported objectives"
    And I don't see field "Completion rules"
    And I don't see field "Structure"
    And I don't see field "Prerequisite units"

    # After tab
    And element "input#edit-field-study-topic-area-und-0-target-id" exists
    # Dont see fields
    And element "input#edit-field-course-offered-und" does not exist
    And element "input#edit-field-postgrad-research-und" does not exist
    And element "input#edit-field-course-midyear-intake-und" does not exist
    And element "input#edit-field-handbook-include-und" does not exist
    And element "input#edit-field-continuing-student-und" does not exist
    And element "#edit-field-multiple-audience-group-und-0-value" does not exist
    And element "#edit-field-ve-cohorts-und-0-value" does not exist

    Examples:
      | role                        |
      | Advanced Author             |
      | Approver                    |

  @api
  Scenario Outline: User does not have access to course edit page
  Given I am logged in as a user with the "<role>" role
    When I go to "courses/doctor-of-business-administration-bppb"
    Then I should not see "New draft"

    Examples:
      | role                        |
      | authenticated user          |
      | Emergency Publisher         |
      | Author                      |
      | International Author        |
      | TAFE Author                 |
      | Admin                       |
      | Researcher                  |
      | Researcher Profile Admin    |
      | Researcher Profile Approver |
      | Researcher Profile Tester   |

  @api @PW-5063
  Scenario Outline: User does not have access to course edit page
  Given I am logged in as a user with the "<role>" role
    When I go to "<path>"
    Then I should get a 200 HTTP response

    And element "#edit-body-und-0-value" exists

  Examples:
      | role                        | path                      |
      | Approver                    | node/add/campus           |
      | Approver                    | node/add/events           |
      | Approver                    | node/add/news             |
      | Approver                    | node/add/page-builder     |
      | Approver                    | node/add/staff-profile    |
      | Approver                    | node/add/webform          |
      | Approver                    | node/add/success-story    |
      | Approver                    | node/add/study-topic-area |
      | Advanced Author             | node/add/events           |
      | Advanced Author             | node/add/news             |
      | Advanced Author             | node/add/success-story    |
      | Advanced Author             | node/add/webform          |
      | Advanced Author             | node/add/staff-profile    |

  @api @PW-5063
  Scenario: User does not have access to course edit page
  Given I am logged in as a user with the "Approver" role
    When I go to "node/add/campus"
    Then I should get a 200 HTTP response

    And element "#edit-field-introduction-und-0-value" exists

  @api @PW-5064
  Scenario: User can see content on page
  Given I am logged in as a user with the "Approver" role
    When I go to "courses/doctor-of-business-administration-bppb"
    Then I should get a 200 HTTP response

    And element ".field-name-field-body" exists
