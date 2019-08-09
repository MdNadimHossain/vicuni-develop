@p0
Feature: Navigation on course pages

  As a prospective student
  I want the ability to navigate around the "Study at VU" section from a course page
  In order to find out more about studying at VU

  Background:
    Given I define components:
      | secondary nav        | #block-panels-mini-vu-block-primary-menu                              |
      | first link active    | .main-menu > li.level-2:nth-child(1).active-trail > a                 |
      | four links           | .main-menu > li.level-2:nth-child(4) > a                              |
      | international switch | #block-vu-core-course-international-switcher a[href*="international"] |

  @javascript @PW-537
  Scenario: Secondary nav links appear correctly on large on "/courses" page.
    Given I am viewing the site on a large device
    When I visit "/courses"
    Then I see first link active inside of secondary nav
    And I see four links inside of secondary nav

  @javascript @PW-537
  Scenario: Secondary nav links appear correctly on large on course pages.
    Given I am viewing the site on a large device
    When I am viewing a page of courses content type where:
      | condition type    | field               | value     |
      | propertyCondition | status              | 1         |
      | fieldCondition    | field_international | 1         |
      | fieldCondition    | field_domestic      | 1         |
      | fieldCondition    | field_unit_lev      | undergrad |
    And I save screenshot
    Then I see first link active inside of secondary nav
    And I see four links inside of secondary nav

  @javascript @PW-537 @PW-3776
  Scenario: Secondary nav links appear correctly on large on international course pages.
    Given I am viewing the site on a large device
    When I am viewing a page of courses content type where:
      | condition type    | field               | value     |
      | propertyCondition | status              | 1         |
      | fieldCondition    | field_international | 1         |
      | fieldCondition    | field_domestic      | 1         |
      | fieldCondition    | field_unit_lev      | undergrad |
    And I see international switch below title box
    Then I see first link active inside of secondary nav
    And I see four links inside of secondary nav

  @api @PW-888 @PW-3010
  Scenario: Course link on Online, Open TAFE courses should link to online application page.
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code                    | 1337CERTIII |
      | course_intake_status           | OFFERED     |
      | is_admissions_centre_available | Y           |
      | intake_enabled                 | 1           |
      | admissions_category            | VE-DOM      |
      | sector_code                    | VET         |
    And there is a course intake where:
      | course_code                    | 1337APP   |
      | course_intake_status           | OFFERED   |
      | is_admissions_centre_available | Y         |
      | intake_enabled                 | 1         |
      | admissions_category            | APP-TRAIN |
      | sector_code                    | VET       |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Certificate III  |
      | field_unit_lev   | tafe             |
      | field_unit_code  | 1337CERTIII      |
      | title            | Cert III in 1337 |
    Then I should see the link "Apply direct to VU" linking to "https://gotovu.custhelp.com/app/tafe/launch_application?c_code=1337CERTIII"
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Certificate III                 |
      | field_unit_lev   | tafe                            |
      | field_unit_code  | 1337APP                         |
      | title            | Cert III Apprenticeship in 1337 |
    Then I should see the link "Apply direct to VU" linking to "https://gotovu.custhelp.com/app/tafe/launch_application?c_code=1337APP"

  @PW-2697 @api
  Scenario: Open direct and VTAC
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code              | BACHBOTH  |
      | course_intake_status     | OFFERED   |
      | intake_enabled           | 1         |
      | admissions_category      | HE-UNDGRD |
      | sector_code              | HE        |
      | application_entry_method | VTAC      |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Bachelor Degree  |
      | field_unit_lev   | undergrad        |
      | field_unit_code  | BACHBOTH         |
      | title            | Bachelor of BOTH |
    Then I should see the text "applications are due"
    And I should see the link "Apply via VTAC" linking to "http://www.vtac.edu.au/"
    And I should see the text "You should apply direct to VU if you are"
    And I should see the text "Direct applications are due on"
    And I should see the link "Apply direct to VU" linking to "https://gotovu.custhelp.com/app/launch_application?c_code=BACHBOTH"

  @PW-2697 @api @PW-3010
  Scenario: Open VTAC course with future direct offering
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code              | BACHVTAC              |
      | course_intake_status     | OFFERED               |
      | intake_enabled           | 1                     |
      | admissions_category      | HE-UNDGRD             |
      | sector_code              | HE                    |
      | application_entry_method | VTAC                  |
      | admissions_start_date    | [relative_dt:+1 week] |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Bachelor Degree  |
      | field_unit_lev   | undergrad        |
      | field_unit_code  | BACHVTAC         |
      | title            | Bachelor of VTAC |
    Then I should see the text "You should apply through VTAC if you"
    And I should see the link "Apply via VTAC" linking to "http://www.vtac.edu.au/"
    And I should not see the text "You can apply directly to VU if you"
    And I should see the text "Direct applications open"
    And I should not see the link "Apply direct to VU"

  @PW-2697 @api @PW-3010
  Scenario: Open direct course with future VTAC offering
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code              | BACHDIRE  |
      | course_intake_status     | OFFERED   |
      | intake_enabled           | 1         |
      | admissions_category      | HE-UNDGRD |
      | sector_code              | HE        |
      | application_entry_method | DIRECT    |
    And there is a course intake where:
      | course_code              | BACHDIRE              |
      | course_intake_status     | OFFERED               |
      | intake_enabled           | 1                     |
      | admissions_category      | HE-UNDGRD             |
      | sector_code              | HE                    |
      | application_entry_method | VTAC                  |
      | vtac_open_date           | [relative_dt:+1 week] |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Bachelor Degree    |
      | field_unit_lev   | undergrad          |
      | field_unit_code  | BACHDIRE           |
      | title            | Bachelor of Direct |
    Then I should see the text "VTAC applications open"
    And I should not see the link "Apply via VTAC"
    And I should not see the text "You can apply directly to VU if you"
    And I should see the text "Direct applications are due on"
    And I should see the link "Apply direct to VU" linking to "https://gotovu.custhelp.com/app/launch_application?c_code=BACHDIRE"

  @PW-2697 @api
  Scenario: Closed direct and VTAC
    Given I am logged in as a user with the administrator role
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Bachelor Degree  |
      | field_unit_lev   | undergrad        |
      | field_unit_code  | BACHNONE         |
      | title            | Bachelor of NONE |
    Then I should see the text "Applications for this course are not being taken at this time."
# @TODO - Fix these steps.
#    And I should not see the text "You must apply via VTAC if you are"
#    And I should not see the text "VTAC applications due"
#    And I should not see the link "Apply via VTAC"
#    And I should not see the text "You can apply directly to VU if you"
#    And I should not see the text "Direct applications due"
#    And I should not see the link "Apply direct to VU"

  @PW-2697 @api
  Scenario: Open direct only
    Given I am logged in as a user with the administrator role
    And there is a course intake where:
      | course_code              | BACHDINV  |
      | course_intake_status     | OFFERED   |
      | intake_enabled           | 1         |
      | admissions_category      | HE-UNDGRD |
      | sector_code              | HE        |
      | application_entry_method | DIRECT    |
      | is_vtac_course           | N         |
    When I am viewing a draft revision of a published course:
      | field_course_aqf | Bachelor Degree         |
      | field_unit_lev   | undergrad               |
      | field_unit_code  | BACHDINV                |
      | title            | Bachelor of DIRECT ONLY |
    And I save screenshot
    Then I should see the text "Direct applications are due on"
    And I should see the link "Apply direct to VU" linking to "https://gotovu.custhelp.com/app/launch_application?c_code=BACHDINV"
# @TODO - Fix these steps.
#    And I should not see the text "You must apply via VTAC if you are"
#    And I should not see the link "Apply via VTAC"
#    And I should not see the text "You can apply directly to VU if you"
