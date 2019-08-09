@p1
Feature: On this page navigation

  As a user I want to see an all section on this page in the navigation.

  @javascript @PW-2090 @api @skipped
  Scenario: Test On this page navigation responsiveness.
    Given I am viewing the site on a large screen
    And I am logged in as a user with the approver role
    And I create a published 'page_builder' with content:
      | title       | [TEST] On this page |
      | field_theme | victory             |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has page_intro paragraph:
      | field_body:value | Intro paragraph |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 1: 2 lines on MD o o o o o o o o o o o o o o o o o o o o o |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 2: 2 lines on SM o o o o o o o o o o o o o o |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 3 |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 4 |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 5 |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 6 |

    # Ensure all section links are present.
    Then I visit "test-on-this-page"
    And the selector "#block-vu-core-vu-on-page-nav__content ul:first-child li" should contain only the following items in order:
      | Section 1: 2 lines on MD o o o o o o o o o o o o o o o o o o o o o |
      | Section 2: 2 lines on SM o o o o o o o o o o o o o o               |
      | Section 3                                                          |
      | Section 4                                                          |
      | Section 5                                                          |
      | Section 6                                                          |

    # Add another section, then ensure we've overflowed into the 'More' menu.
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 7 |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 8 |
    And field_page_paragraphs in "[TEST] On this page" node of type page_builder has section paragraph:
      | field_section_title:value | Section 9 |
    And I visit "test-on-this-page"
    And the selector "#block-vu-core-vu-on-page-nav__content ul:first-child li" should contain only the following items in order:
      | Section 1: 2 lines on MD o o o o o o o o o o o o o o o o o o o o o |
      | Section 2: 2 lines on SM o o o o o o o o o o o o o o               |
      | Section 3                                                          |
      | Section 4                                                          |
      | Section 5                                                          |
      | Section 6                                                          |
      | More                                                               |
    And I click "More"
    And wait 1 second
    And the selector "#block-vu-core-vu-on-page-nav__more li" should contain all of the following items in order:
      | Section 7 |
      | Section 8 |
      | Section 9 |

    Then I am viewing the site on a medium screen
    Then I visit "test-on-this-page"
    And the selector "#block-vu-core-vu-on-page-nav__content ul:first-child li" should contain only the following items in order:
      | Section 1: 2 lines on MD o o o o o o o o o o o o o o o o o o o o o |
      | Section 2: 2 lines on SM o o o o o o o o o o o o o o               |
      | Section 3                                                          |
      | Section 4                                                          |
      | Section 5                                                          |
      | More                                                               |
    And I click "More"
    And wait 1 second
    And the selector "#block-vu-core-vu-on-page-nav__more li" should contain all of the following items in order:
      | Section 6 |
      | Section 7 |
      | Section 8 |
      | Section 9 |

    Then I am viewing the site on a small screen
    Then I visit "test-on-this-page"
    And the selector "#block-vu-core-vu-on-page-nav__content ul:first-child li" should contain only the following items in order:
      | Section 1: 2 lines on MD o o o o o o o o o o o o o o o o o o o o o |
      | Section 2: 2 lines on SM o o o o o o o o o o o o o o               |
      | Section 3                                                          |
      | Section 4                                                          |
      | Section 5                                                          |
      | More                                                               |
    And I click "More"
    And wait 1 second
    And the selector "#block-vu-core-vu-on-page-nav__more li" should contain all of the following items in order:
      | Section 6 |
      | Section 7 |
      | Section 8 |
      | Section 9 |
