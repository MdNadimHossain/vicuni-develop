@p0 @api @cms
Feature: CMS: Node theme switching

  Background:
    And I define components:
      | Intro         | .paragraphs-item-type-section   |
      | Section       | .paragraphs-item-type-section   |
      | Section title | .field-name-field-section-title |

  @PW-1720
  Scenario: CMS users and switch content to Victory theme.
    Given I am logged in as a user with the approver role

    # New content in Victory theme.
    And I create a published 'page_builder' with content:
      | title       | Test Victory theme |
      | field_theme | victory            |
    And I should see "victory" theme

    # New content in VU theme.
    And I create a published 'page_builder' with content:
      | title       | Test VU theme |
      | field_theme | vu            |
    And I should see "vu" theme

    # Set draft to Victory theme. Summary is a required field now.
    And I click "Edit draft"
    And I fill in "field_theme[und]" with "victory"
    And I fill in "body[und][0][summary]" with "V is for victory, that's good enough for me."
    And I fill in "log" with "approver"
    And I press the "Save" button
    And I should see "victory" theme

    # Published still uses VU theme.
    And I click "View published"
    And I should see "vu" theme

    # Published draft sets to Victory theme.
    And I click "Moderate"
    And I fill in "state" with "needs_review"
    And I press the "Apply" button
    And I fill in "state" with "published"
    And I press the "Apply" button
    And I click "View published"
    And I should see "victory" theme

  @PW-1720 @javascript
  Scenario: CMS users Paragraphs experience.
    Given I am viewing the site on a desktop device
    And I am logged in as a user with the approver role

    And I visit "/node/add/page-builder"
    And I should see the link "2017 theme"
    And I click "2017 theme"

    # Ensure Intro paragraph is present, and is draggable.
    And I should see "Section type: Intro"
    And I should see 1 "#edit-field-page-paragraphs .handle" visible elements
    And I should not see the button "#edit-field-page-paragraphs input[value='Remove']"

    # Ensure edit behaviour for Intro paragraph.
    And I click on "input[name='field_page_paragraphs_und_0_edit_button']" element
    And I wait for AJAX to finish
    And I should see "Body"
    And I should see "Supplementary content"
    And I should see 1 ".paragraphs-item-type-page-intro .paragraphs-add-more-submit" element
    And I press "Collapse"
    And I wait for AJAX to finish

    # Ensure Section paragraph can be added and is draggable.
    And I press the "Add another Section" button
    And I wait for AJAX to finish
    And I should see "Section type: Page section"
    And I should see 2 "#edit-field-page-paragraphs .handle" visible elements

    # Ensure Section paragraph behaviour works as expected.
    And I see Section title inside of Section
    And I should see "Main content"
    And I should see "Supplementary content"
    And I should see 1 "#edit-field-page-paragraphs input[value='Remove']" visible elements
    
