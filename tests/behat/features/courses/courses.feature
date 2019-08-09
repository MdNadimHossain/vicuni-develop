@p1
Feature: Courses
  Display Course information correctly to users

  @api @125808271 @PW-2501 @PW-2674
  Scenario: Course Dates, Times and intro should be visible on a newly created Short Course page
    Given I am logged in as a user with the administrator role
    And I am viewing a published short course:
      | title              | Test Course & Ampersand    |
      | field_introduction | <p>I'm a course intro!</p> |
    Then I should see the heading "Test Course & Ampersand"
    And I should see the text "Short course dates and times"
    And I should see the text "I'm a course intro!"

  @api @javascript @skipped
  Scenario: Course page includes course_code meta tag
    Given I am logged in as a user with the administrator role
    And I am viewing a course page with the title "Awesome Test Course"
    Then the response should contain "<meta name=\"course_code\" content=\"A12345\" />"
    And the javascript statement "window.c_code === 'A12345';" should return "true"

  @PW-999 @PW-838 @api
  Scenario: URLs should update correctly when an approver updates a course.
    Given I am logged in as a user with the "administrator" role
    And I am viewing a draft revision of a published course:
      | field_course_aqf | Diploma                    |
      | title            | [TEST] Course alias update |
      | field_unit_lev   | tafe                       |
      | field_unit_code  | TEST-CODE                  |
    And I click "Moderate"
    And I click "Delete" in the "New revision created with status Draft" row
    And I press "Delete"

    When I am logged in as a user with the "approver" role
    And I visit "courses/test-code"
    And I should be in the "courses/test-course-alias-update-test-code" path
    And I click "New draft"
    And I fill in "edit-log" with "approver"
    And I press "Save"
    And I click "Moderate"
    And I press "Apply"
    And I press "Apply"
    And I click "View published"
    Then I should be in the "courses/test-course-alias-update-test-code" path

  @PW-1824 @api
  Scenario Outline: Course page shows the correct enquire now details.
    When I am viewing a page of courses content type where:
      | condition type    | field          | value        |
      | propertyCondition | status         | 1            |
      | fieldCondition    | field_unit_lev | <unit_level> |
    Then I should see "<text>" in the ".enquire-now-info-block" element

    Examples:
      | unit_level        | text                        |
      | tafe              | 1300 TAFE VP (1300 823 387) |
      | undergrad         | 1300 VIC UNI (1300 842 864) |
      | postgrad_research | +61 3 9919 4522             |

  @PW-2891 @javascript
  Scenario: Course page has "Find on this page" navigation.
    Given I am viewing a page of courses content type where:
      | condition type    | field          | value |
      | propertyCondition | status         | 1     |
      | fieldCondition    | field_unit_lev | tafe  |
      | fieldCondition    | field_domestic | 1     |
    Then I should see "Find on this page"

  @PW-2891 @javascript
  Scenario: International course page has "Find on this page" navigation.
    Given I am viewing a page of courses content type where:
      | condition type    | field               | value     |
      | propertyCondition | status              | 1         |
      | fieldCondition    | field_unit_lev      | undergrad |
      | fieldCondition    | field_international | 1         |
    Then I should see "Find on this page"

  @PW-2898 @api @PW-3010
  Scenario Outline: Course page shows the request callback block for open undergrad and postgrad coursework courses.
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code | REQUESTCALLBACK |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Bachelor                    |
      | field_unit_lev   | <unit_level>                |
      | field_unit_code  | REQUESTCALLBACK             |
      | title            | Bachelor of REQUESTCALLBACK |
    And I should see "Request a call back" in the ".enquire-now-info-block" element

    Examples:
      | unit_level |
      | undergrad  |
      | postgrad   |

  @PW-2898 @api
  Scenario Outline: Course page does not show the request callback block for closed undergrad and postgrad coursework courses.
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code          | REQUESTCALLBACK |
      | course_intake_status | CANCELLED       |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Certificate III             |
      | field_unit_lev   | <unit_level>                |
      | field_unit_code  | REQUESTCALLBACK             |
      | title            | Cert III in REQUESTCALLBACK |
    And I should not see "Request a call back" in the ".enquire-now-info-block" element

    Examples:
      | unit_level |
      | undergrad  |
      | postgrad   |

  @PW-2898 @api
  Scenario Outline: Course page does not show the request callback block if college is vicpoly or non-award courses.
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code | REQUESTCALLBACK |
    When I am viewing a draft revision of a published course:
      | field_college:0:title | <college>                   |
      | field_course_aqf      | Certificate III             |
      | field_unit_lev        | tafe                        |
      | field_unit_code       | REQUESTCALLBACK             |
      | title                 | Cert III in REQUESTCALLBACK |
    Then I should not see "Request a call back from one of our experienced VUHQ course advisers to get your questions answered"

    Examples:
      | college              |
      | Victoria Polytechnic |
      | VU College           |

  @PW-2898 @api
  Scenario: Course page does not show the request callback block if viewer is international.
    Given I am viewing a page of courses content type where:
      | condition type | field               | value |
      | fieldCondition | field_international | 1     |
    Then I should not see "Request a call back from one of our experienced VUHQ course advisers to get your questions answered"

  @PW-2980 @api
  Scenario Outline: Course page shows the "What's a unit?" block for courses that are not short.
    Given I am logged in as a user with the administrator role
    When I am viewing a page of courses content type where:
      | condition type    | field          | value        |
      | propertyCondition | status         | 1            |
      | fieldCondition    | field_unit_lev | <unit_level> |
    Then I should see "What's a unit?"

    Examples:
      | unit_level |
      | tafe       |
      | undergrad  |
      | postgrad   |

  @PW-2980 @api
  Scenario: Course page does not show the "What's a unit?" block for short courses.
    Given I am logged in as a user with the administrator role
    When I am viewing a page of courses content type where:
      | condition type    | field          | value |
      | propertyCondition | status         | 1     |
      | fieldCondition    | field_unit_lev | short |
    Then I should not see "What's a unit?"

  @PW-2980 @api
  Scenario Outline: Course page shows the "Credits" block for courses that are not short.
    Given I am logged in as a user with the administrator role
    When I am viewing a page of courses content type where:
      | condition type    | field          | value        |
      | propertyCondition | status         | 1            |
      | fieldCondition    | field_unit_lev | <unit_level> |
    And I should see "Each unit is worth a set amount of study credits based on the amount of time you study. Generally, 1 credit is equal to 1 hour of study per week."

    Examples:
      | unit_level |
      | undergrad  |
      | postgrad   |

  @PW-2980 @api
  Scenario Outline: Course page does not show the "Credits" block for short courses.
    Given I am logged in as a user with the administrator role
    When I am viewing a page of courses content type where:
      | condition type    | field          | value        |
      | propertyCondition | status         | 1            |
      | fieldCondition    | field_unit_lev | <unit_level> |
    And I should not see "Each unit is worth a set amount of study credits based on the amount of time you study. Generally, 1 credit is equal to 1 hour of study per week."

    Examples:
      | unit_level |
      | tafe       |
      | short      |

  @PW-3105 @api @PW-3010
  Scenario: Course page shows the international brochure block if viewer is international.
    Given I am logged in as a user with the administrator role
    When I am viewing a page of courses content type where:
      | condition type    | field               | value     |
      | propertyCondition | status              | 1         |
      | fieldCondition    | field_international | 1         |
      | fieldCondition    | field_unit_lev      | undergrad |
    Then I should see "Create a customised brochure in a few simple steps. Your brochure will include country-specific information."

  @PW-3105 @api
  Scenario: Course page does not show the international brochure block if viewer is domestic.
    Given I am logged in as a user with the administrator role
    When I am viewing a page of courses content type where:
      | condition type | field               | value |
      | fieldCondition | field_international | 0     |
    Then I should not see "Create a customised brochure in a few simple steps. Your brochure will include country-specific information."

  @PW-3105 @api
  Scenario Outline: Course page does not show the "Already a VU Student" block.
    Given I am logged in as a user with the administrator role
    When I am viewing a page of courses content type where:
      | condition type | field               | value           |
      | fieldCondition | field_international | <international> |
      | fieldCondition | field_unit_lev      | <unit_level>    |
    Then I should not see "Already a VU Student?"

    Examples:
      | international | unit_level |
      | 0             | tafe       |
      | 1             | tafe       |
      | 0             | short      |
      | 1             | short      |
      | 1             | undergrad  |
      | 0             | postgrad   |
      | 1             | postgrad   |

  @PW-3105 @api
  Scenario: Course page shows the Already a VU Student block.
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code | ALREADYSTUDENT |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Certificate III            |
      | field_unit_lev   | undergrad                  |
      | field_unit_code  | ALREADYSTUDENT             |
      | title            | Cert III in ALREADYSTUDENT |
    Then I should see "Already a VU Student?"

  @PW-3138 @PW-3338 @api
  Scenario Outline: Course page shows the course fees for domestic offered or closed undergrad and postgrad coursework courses.
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code          | COURSE-FEES |
      | course_intake_status | <status>    |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Certificate III         |
      | field_unit_lev   | <unit_level>            |
      | field_unit_code  | COURSE-FEES             |
      | title            | Cert III in COURSE-FEES |
    Then I should see "Fees & scholarships"

    Examples:
      | unit_level | status    |
      | undergrad  | OFFERED   |
      | undergrad  | CANCELLED |
      | postgrad   | OFFERED   |
      | postgrad   | CANCELLED |

  @PW-5346 @api
  Scenario Outline: Course page shows the course fees for domestic offered or closed undergrad and postgrad coursework courses.
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code          | COURSE-FEES |
      | course_intake_status | <status>    |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Certificate III         |
      | field_unit_lev   | <unit_level>            |
      | field_unit_code  | COURSE-FEES             |
      | title            | Cert III in COURSE-FEES |
    Then I should see "Fee Calculator"
    And I should see the link "Calculate my fees" linking to "/study-at-vu/fees-scholarships/fee-calculator"

    Examples:
      | unit_level | status    |
      | undergrad  | OFFERED   |
      | undergrad  | CANCELLED |
      | postgrad   | OFFERED   |
      | postgrad   | CANCELLED |

  @PW-5346 @international @api
  Scenario: Course page shows the international brochure block if viewer is international.
    Given I am logged in as a user with the administrator role
    When I am viewing a page of courses content type where:
      | condition type    | field               | value     |
      | propertyCondition | status              | 1         |
      | fieldCondition    | field_international | 1         |
      | fieldCondition    | field_unit_lev      | undergrad |
    Then I should see "Use the fee calculator to get an indicator of your course and unit fees."

  @PW-3138 @PW-3338 @api
  Scenario Outline: Course page does not show the course fees for domestic postgrad research courses.
    Given I am logged in as a user with the approver role
    And there is a course intake where:
      | course_code          | COURSE-FEES |
      | course_intake_status | <status>    |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Certificate III         |
      | field_unit_lev   | <unit_level>            |
      | field_course_aqf | <aqf>                   |
      | field_unit_code  | COURSE-FEES             |
      | title            | Cert III in COURSE-FEES |
    Then I should not see "Fees and scholarships"

    Examples:
      | unit_level        | status    | aqf                     |
      | postgrad_research | OFFERED   | Doctoral Degree         |
      | postgrad_research | CANCELLED | Doctoral Degree         |
      | short             | OFFERED   | Statement of Attainment |
      | short             | CANCELLED | Statement of Attainment |

  @PW-3138 @PW-3338 @api
  Scenario Outline: Course page does not show the course fees for international courses.
    Given I am logged in as a user with the approver role
    When I am viewing a page of courses content type where:
      | condition type | field               | value        |
      | fieldCondition | field_international | 1            |
      | fieldCondition | field_unit_lev      | <unit_level> |
    Then I should not see "Fees and scholarships"

    Examples:
      | unit_level        |
      | undergrad         |
      | postgrad          |
      | tafe              |
      | postgrad_research |
      | short             |


  @PW-3261 @api
  Scenario: Edit Course page should have Feature Image field.
    Given I am logged in as a user with the "administrator" role
    And I am viewing a draft revision of a published course:
      | field_course_aqf | Diploma              |
      | title            | [TEST] Feature Image |
      | field_unit_lev   | tafe                 |
      | field_unit_code  | TEST-CODE            |
    And I click "Edit draft"
    Then I should see "Feature Image"
