@p0
Feature: Content type: Event

  As a prospective student
  I want the ability to view event pages on any device
  So that I can keep abreast of the latest updates from VU

  @PW-1012 @api @VUTestModule
  Scenario: Pinning events
    Given events content with fields:
      | title                              | [TEST-EVENT] Today and tomorrow - not pinned      |
      | field_date:value                   | [relative:yesterday 5pm], [relative:tomorrow 8am] |
      | field_date:value2                  | [relative:+1 hour], [relative:tomorrow 9am]       |
      | status                             | 1                                                 |
      | workbench_moderation_state_current | published                                         |
      | promoted                           | 1                                                 |
      | language                           | und                                               |
    And events content with fields:
      | title                              | [TEST-EVENT] Next week - pinned |
      | field_date:value                   | [relative:+1 week 9am]          |
      | field_date:value2                  | [relative:+1 week 10am]         |
      | status                             | 1                               |
      | workbench_moderation_state_current | published                       |
      | sticky                             | 1                               |
      | promoted                           | 1                               |
    And events content with fields:
      | title                              | [TEST-EVENT] Later today  - not pinned |
      | field_date:value                   | [relative:+1 hour]                     |
      | field_date:value2                  | [relative:tomorrow 9am]                |
      | status                             | 1                                      |
      | workbench_moderation_state_current | published                              |
      | promoted                           | 1                                      |
    And events content with fields:
      | title                              | [TEST-EVENT] Even later today |
      | field_date:value                   | [relative:+2 hours]           |
      | field_date:value2                  | [relative:tomorrow 9am]       |
      | status                             | 1                             |
      | workbench_moderation_state_current | published                     |
      | promoted                           | 1                             |
    And the cache has been cleared
    When I go to the homepage
    Then the selector ".view-display-id-promoted_events_list .field-name-title" should contain only the following items in order:
      | [TEST-EVENT] Next week - pinned              |
      | [TEST-EVENT] Later today - not pinned        |
      | [TEST-EVENT] Even later today                |
      | [TEST-EVENT] Today and tomorrow - not pinned |

  @PW-1402 @api @VUTestModule @skipped
  Scenario: Event dates
    Given an entity of type inline_entities with fields:
      | type  | location                |
      | title | [TEST-EVENT] Location 1 |
    And an entity of type inline_entities with fields:
      | type  | location                |
      | title | [TEST-EVENT] Location 2 |

    And events content with fields:
      | title                              | [TEST-EVENT] Multiple, not started                           |
      | field_date:value                   | [relative:Jan 1 + 1 year 9am], [relative:Jan 2 + 1 year 9am] |
      | field_date:value2                  | [relative:Jan 1 + 1 year 5pm], [relative:Jan 2 + 1 year 5pm] |
      | field_event_campus                 | City Flinders                                                |
      | status                             | 1                                                            |
      | workbench_moderation_state_current | published                                                    |
      | promoted                           | 1                                                            |
      | language                           | und                                                          |
    And events content with fields:
      | title                              | [TEST-EVENT] Multiple, started                          |
      | field_date:value                   | [relative:yesterday 9am], [relative:Jan 2 + 1 year 9am] |
      | field_date:value2                  | [relative:yesterday 5pm], [relative:Jan 2 + 1 year 5pm] |
      | field_event_campus                 | Off campus                                              |
      | field_location                     | [TEST-EVENT] Location 1                                 |
      | status                             | 1                                                       |
      | workbench_moderation_state_current | published                                               |
      | sticky                             | 1                                                       |
      | promoted                           | 1                                                       |
    And events content with fields:
      | title                              | [TEST-EVENT] Multiple, finished                 |
      | field_date:value                   | [relative:-2 days 9am], [relative:-1 days 9am]  |
      | field_date:value2                  | [relative:-2 days 5pm], [relative:tomorrow 5pm] |
      | status                             | 1                                               |
      | workbench_moderation_state_current | published                                       |
      | promoted                           | 1                                               |
    And events content with fields:
      | title                              | [TEST-EVENT] Single, multi day                   |
      | field_date:value                   | [relative:Jan 3 + 1 year 9am]                    |
      | field_date:value2                  | [relative:Jan 4 + 1 year 5pm]                    |
      | field_event_campus                 | Off campus                                       |
      | field_location                     | [TEST-EVENT] Location 1, [TEST-EVENT] Location 2 |
      | status                             | 1                                                |
      | workbench_moderation_state_current | published                                        |
      | promoted                           | 1                                                |
    And events content with fields:
      | title                              | [TEST-EVENT] Single, one day                     |
      | field_date:value                   | [relative:Jan 4 + 1 year 9am]                    |
      | field_date:value2                  | [relative:Jan 4 + 1 year 5pm]                    |
      | field_event_campus                 | Footscray Park                                   |
      | field_location                     | [TEST-EVENT] Location 1, [TEST-EVENT] Location 2 |
      | status                             | 1                                                |
      | workbench_moderation_state_current | published                                        |
      | promoted                           | 1                                                |
    And the cache has been cleared

    When I go to the homepage
    # Test the right wording for the event date.
    Then the selector ".view-display-id-promoted_events_list .field-name-field-date .field-item" should contain only the following items in order:
      | Multiple, next 2 Jan     |
      | Multiple, starting 1 Jan |
      | 3 Jan - 4 Jan (2 days)   |
      | 4 Jan                    |

    # Test the right wording for the event location.
    And the selector ".view-display-id-promoted_events_list .field-name-field-event-campus .field-items" should contain only the following items in order:
      | [TEST-EVENT] Location 1 |
      | City Flinders           |
      | Multiple                |
      | Footscray Park          |

  @javascript @PW-254
  Scenario: Anonymous user viewing event page on a mobile device
    Given I am viewing the site on a mobile device
    When I visit a page of events content type with filled fields field_cust_when, field_event_campus, field_contact_info, field_related_in_link
    Then I see header above page title, body, event information, contact information and related links
    And I see legacy title box above body
    And I don't see sticky header
    And I see page title above body
    And I see event information below body
    And I see contact information below event information
    And I see related links below contact information
    And I see footer below body, event information, contact information, related links

  # These tests are skipped because of issues with the grid.
  # After the tests were skipped the header had changed
  # and they've basically been rendered useless anyway.
  # Don't waste any more time on this, advocate for 
  # the new theme.
  @javascript @skipped @PW-254
  Scenario: Anonymous user viewing event page on a tablet device
    Given I am viewing the site on a tablet device
    When I visit a page of events content type with filled fields field_cust_when, field_event_campus, field_contact_info, field_related_in_link
    Then I see header over legacy title box, page title, body, event information, contact information and related links
    And I see legacy title box above body
    And I don't see sticky header
    And I see page title above body
    And I see event information below body
    And I see contact information below event information
    And I see related links below contact information
    And I see footer below legacy title box, page title, body, event information, contact information, related links

  @javascript @skipped @PW-254
  Scenario: Anonymous user viewing event page on a desktop device
    Given I am viewing the site on a tablet device
    When I visit a page of events content type with filled fields field_cust_when, field_event_campus, field_contact_info, field_related_in_link
    Then I see legacy title box above  above legacy title box
    And I see event information to right of body
    And I see contact information and related links to right of body and event information

  @PW-4478 @javascript @api
  Scenario Outline: Publishing options are not present for author and advanced author
    Given I am logged in as a "<role>"
    And I visit a page of News & Media content type
    And I click "New draft"
    Then I should not see "Publishing options"

    Examples:
      | role            |
      | Author          |
      | Advanced author |

  @PW-4478 @javascript @api
  Scenario: Promote to front page and Sticky at top of lists are present for approver
    Given I am logged in as an "Approver"
    And I visit a page of News & Media content type
    And I click "New draft"
    And I click "Publishing options"
    Then I should see "Promoted to front page"
    And I should see "Sticky at top of lists"

  @PW-5979 @javascript @api
  Scenario: Anonymous user viewing news page on desktop
    Given I am viewing the site on a desktop device
    When I visit a page of events content type with filled fields field_event_cost
    Then I should see "View map"