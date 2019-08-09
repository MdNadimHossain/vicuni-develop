@p0 @courses @failingtest
Feature: Content type: Courses

  As a prospective student
  I want the ability to view Courses pages on any device
  So that I can get more information about VU courses

  Background:
    Given I define components:
      | vicpoly logo           | .title-box__logo--top>a>svg            |
      | header region          | .region-below-header                   |
      | on this page           | #block-vu-core-vu-on-page-nav          |
      | course essentials      | #block-ds-extras-course-essentials     |
      | course description     | #overview                           |
      | pathways               | #pathways                              |
      | credit                 | #credit-for-skills-past-study          |
      | course structure       | #course-structure                      |
      | enquire now            | #enquire-now                           |
      | course disclaimer      | .course-disclaimer                     |
      | international switcher | .international-switcher-container      |
      | how to apply           | #apply-now                             |

  @javascript @PW-486 @PW-3010 @PW-3776
  Scenario: Anonymous user viewing Courses VicPoly page on a mobile device
    Given I am viewing the site on a extra_small device
    When I am on "courses/diploma-of-accounting-fns50217"
    Then I see header over title box
    And I don't see sticky header
    And I see breadcrumbs and vicpoly logo inside of title box

    And I see course essentials inside of header region
    And I see on this page below title box
    And I see course essentials above course description

    And I see course structure, enquire now and course disclaimer below header region
    And I see enquire now and course disclaimer below course structure
    And I see enquire now and course disclaimer below course structure
    And I see course disclaimer below enquire now
    And I should see the text "Admission requirements"
    And I don't see pathways

  @javascript @PW-486
  Scenario: Anonymous user viewing Courses VicPoly page on a tablet device
    Given I am viewing the site on a small device
    When I am on "courses/diploma-of-accounting-fns50217"
    Then I see header over title box
    And I don't see sticky header
    And I see breadcrumbs and vicpoly logo inside of title box

    And I see course description and how to apply below header region
    And I see on this page below title box
    And I see course essentials above course description
    And I see on this page, course essentials and course description above how to apply
    And I see enquire now and course disclaimer below course structure
    And I see enquire now and course disclaimer below course structure
    And I see course disclaimer below enquire now
    And I should see the text "Admission requirements"
    And I don't see pathways

  @javascript @PW-486 @PW-3330
  Scenario: Anonymous user viewing Courses VicPoly page on a desktop device
    Given I am viewing the site on a large device
    When I am on "courses/diploma-of-accounting-fns50217"
    Then I see header above title box
    And wait 1 second
    And I see sticky header over course description
    And I see breadcrumbs and vicpoly logo inside of title box
    And I see vicpoly logo to the right of international switcher

    And I see on this page below title box
    And I see course essentials above course description

    And I see enquire now and course disclaimer below course structure
    And I see course disclaimer below enquire now
    And I should see the text "Admission requirements"
    And I don't see pathways

  @javascript @PW-3026
  Scenario: Anonymous user viewing Courses page on a mobile device
    Given I am viewing the site on a extra_small device
    When I am on "/courses/bachelor-of-business-bbns"
    Then wait 1 second
    And I see pathways below header region
    And I should see the text "Admission"
    And I should not see the text "Short course dates and times"

  @javascript @PW-3026
  Scenario: Anonymous user viewing Courses page on a tablet device
    Given I am viewing the site on a small device
    When I am on "/courses/bachelor-of-business-bbns"
    Then wait 1 second
    And I see pathways below header region
    And I should see the text "Admission"
    And I should not see the text "Short course dates and times"

  @javascript @PW-3026
  Scenario: Anonymous user viewing Courses page on a desktop device
    Given I am viewing the site on a large device
    When I am on "/courses/bachelor-of-business-bbns"
    Then wait 1 second
    And I see pathways below header region
    And I should see the text "Admission"
    And I should not see the text "Short course dates and times"

  @PW-869
  Scenario: Anonymous user viewing Courses page on a desktop device
    Given I am on "/courses/bachelor-of-business-bbns"
    And I should see the link "Department of Home Affairs" linking to "https://immi.homeaffairs.gov.au/visas/getting-a-visa/visa-listing/student-500"
    And I should not see the text "liveinaustralia"
    And I should not see the text "Department of Immigration and Border Protection (DIBP)"
