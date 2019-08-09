@p0
Feature: Content type: Page Builder

  As a prospective student
  I want the ability to view menu links on this page section
  So that I can see the menus on this page section block

  Background:
    Given I define components:
      | child page navigation | .field-name-field-page-paragraphs .menu-block-main-menu-child-page-nav |
      | intro text            | .field-name-field-page-paragraphs .field-name-field-body               |

  @javascript @PW-1099 @api
  Scenario: create page builder type
    Given I am viewing a page_builder content:
      | title                              | Test Title                                                           |
      | body:value                         | <h2>Link test</h2> <h2 data-neon-onthispage="false">Link test 2</h2> |
      | body:format                        | full_html                                                            |
      | status                             | 1                                                                    |
      | author                             | role_administrator_1                                                 |
      | revision_timestamp                 | 1                                                                    |
      | workbench_moderation_state_current | published                                                            |
      | workbench_moderation_state_new     | published                                                            |
      | language                           | und                                                                  |
    Then I should see 1 ".field-name-field-on-this-page .field-items .field-item" visible elements

  @PW-1864 @api @javascript @skipped
  Scenario: Page builder child page navigation
    Given I am viewing the site on a large screen

    And I am logged in as a user with the approver role

    # Level 0 Page
    And I create a published 'page_builder' with content:
      | title       | [TEST] Level 0 Page |
      | field_theme | victory             |
    # Attach page intro paragraph.
    And field_page_paragraphs in "[TEST] Level 0 Page" node of type page_builder has page_intro paragraph:
      | field_body:value | Testing Intro paragraph |

    # Level 1 - Child Pages
    And I create a published 'page_builder' with content:
      | title        | [TEST] Level 1 Child Page 1  |
      | body:value   | Child Page body text         |
      | body:summary | Level 1 Child Page 1 summary |
      | field_theme  | victory                      |
      # Attach page intro paragraph.
    And field_page_paragraphs in "[TEST] Level 1 Child Page 1" node of type page_builder has page_intro paragraph:
      | field_body:value | Testing Intro paragraph |

    And I create a published 'page_builder' with content:
      | title        | [TEST] Level 1 Child Page 2  |
      | body:value   | Child Page body text         |
      | body:summary | Level 1 Child Page 2 summary |
      | field_theme  | victory                      |
      # Attach page intro paragraph.
    And field_page_paragraphs in "[TEST] Level 1 Child Page 2" node of type page_builder has page_intro paragraph:
      | field_body:value | Testing Intro paragraph |

    # Level 2 - Child Pages
    And I create a published 'page_builder' with content:
      | title        | [TEST] Level 2 Child Page 1  |
      | body:value   | Child Page body text         |
      | body:summary | Level 2 Child Page 1 summary |
      | field_theme  | victory                      |
      # Attach page intro paragraph.
    And field_page_paragraphs in "[TEST] Level 2 Child Page 1" node of type page_builder has page_intro paragraph:
      | field_body:value | Testing Intro paragraph |

    And I create a published 'page_builder' with content:
      | title        | [TEST] Level 2 Child Page 2  |
      | body:value   | Child Page body text         |
      | body:summary | Level 2 Child Page 2 summary |
      | field_theme  | victory                      |
      # Attach page intro paragraph.
    And field_page_paragraphs in "[TEST] Level 2 Child Page 2" node of type page_builder has page_intro paragraph:
      | field_body:value | Testing Intro paragraph |

    And I create a published 'page_builder' with content:
      | title        | [TEST] Level 2 Child Page 3  |
      | body:value   | Child Page body text         |
      | body:summary | Level 2 Child Page 3 summary |
      | field_theme  | victory                      |
      # Attach page intro paragraph.
    And field_page_paragraphs in "[TEST] Level 2 Child Page 3" node of type page_builder has page_intro paragraph:
      | field_body:value | Testing Intro paragraph |

    # LEVEL 0 AND LEVEL 1
    And I create the following menu structure:
      | title                       | parent_menu_item    | menu      |
      | [TEST] Level 0 Page         |                     | main-menu |
      | [TEST] Level 1 Child Page 1 | [TEST] Level 0 Page | main-menu |
      | [TEST] Level 1 Child Page 2 | [TEST] Level 0 Page | main-menu |

    # LEVEL 2
    And I create the following menu structure:
      | title                       | parent_menu_item            | menu      |
      | [TEST] Level 2 Child Page 1 | [TEST] Level 1 Child Page 1 | main-menu |
      | [TEST] Level 2 Child Page 2 | [TEST] Level 1 Child Page 1 | main-menu |
      | [TEST] Level 2 Child Page 3 | [TEST] Level 1 Child Page 2 | main-menu |

    # Parent page - Level 0 (it could be any level).
    Then I visit "test-level-0-page"
    And I should see "[TEST] Level 0 Page" in the ".page-header" element
    And I should see the text "Testing Intro paragraph"
    And I see intro text above child page navigation

    # Two child pages should be shown.
    And I should see the text "[TEST] Level 1 Child Page 1"
    And I should see the text "Level 1 Child Page 1 summary"

    And I should see the text "[TEST] Level 1 Child Page 2"
    And I should see the text "Level 1 Child Page 2 summary"

    # Ensure we are at the top of the page and header is not covering content.
    And I see visible header

    # Test second Level pages.
    And I click "[TEST] Level 1 Child Page 1"

    And wait 2 seconds
    And I should see the text "[TEST] Level 2 Child Page 1"
    And I should see the text "Level 2 Child Page 1 summary"

    And I should see the text "[TEST] Level 2 Child Page 2"
    And I should see the text "Level 2 Child Page 2 summary"

    Then I move backward one page
    And I see visible header

    # The menu shouldn't appear if there is only one child page.
    And I click "[TEST] Level 1 Child Page 2"
    And wait 2 seconds
    And I don't see child page navigation

    # The menu shouldn't appear if there is no child page.
    And I visit "test-level-2-child-page-3"
    And I don't see child page navigation

    # Link summary should be hidden on mobile.
    And I am viewing the site on a extra_small screen
    And I visit "test-level-0-page"
    And I should not see the text "Level 1 Child Page 1 summary"
    And I should not see the text "Level 1 Child Page 2 summary"

  @PW-2121 @api
  Scenario: Page builder - Paragraphs permissions
    Given I am logged in as a user with the approver role

    # Create test page builder page.
    And I create a published 'page_builder' with content:
      | title       | [TEST] Page builder |
      | field_theme | victory             |
    # Attach page intro paragraph.
    And field_page_paragraphs in "[TEST] Page builder" node of type page_builder has page_intro paragraph:
      | field_body:value | Testing Intro paragraph |

    # Ensure that Approvers are able to edit paragraphs.
    And I click "Edit draft"
    Then the response status code should be 200
    And I should not see the text "You are not allowed to edit or remove this Section item."

    # Ensure that Authors are able to edit paragraphs.
    And I am logged in as a user with the author role
    Then I visit "test-page-builder"
    And I click "Edit draft"
    Then the response status code should be 200
    And I should not see the text "You are not allowed to edit or remove this Section item."

  @PW-2548 @api
  Scenario: Page Builder - If a page has never been published allow the Approver to delete it.
    Given I am logged in as a user with the approver role
    And I enable the test email system

    # Edit a new page builder content type, update and save.
    And I should be able to edit a "page_builder" content
    And I fill in the following:
      | edit-body-und-0-summary | test 2 |
    And I fill in the following:
      | edit-log | test 2 |
    And I press the "Save" button

    # Check the revision state and then edit to check if the approver can still delete.
    Then I should see "Revision State: Draft"
    And I click "Edit draft"
    Then I should see the button "Delete"
    Then I fill in the following:
      | edit-body-und-0-summary | test 3 |
    And I fill in the following:
      | edit-log | test 3 |
    And I press the "Save" button

    # Check the revision state again, and change the state to needs review.
    Then I should see "Revision State: Draft"
    Then I press the "Apply" button
    And I should see "Revision State: Needs Review"

    # Edit and check if the content can still be deleted. Change the content and save again.
    Then I click "Edit draft"
    And I should see the button "Delete"
    Then I fill in the following:
      | edit-body-und-0-summary | test 4 |
    And I fill in the following:
      | edit-log | test 4 |
    Then I press the "Save" button

    # Change the state to published and check again that the content can no longer be deleted.
    Then I press the "Apply" button
    And I should see "Revision State: Needs Review"
    Then I press the "Apply" button
    And I should see "Revision State: Published"
    Then I click "New draft"
    And I should not see the "Delete" button

    # Unpublish the content and check to make sure the content can still not be deleted.
    Then I click "View published"
    Then I should see "Revision state: Published"
    Then I click "Unpublish this revision"
    Then I press the "Unpublish" button
    Then I click "Edit draft"
    And I should not see the "Delete" button
