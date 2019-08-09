@p0
Feature: Homepage

  Background:
    Given I define components:
      | primary navigation                  | #page-header .primary                                                                                           |
      | choose vu pane                      | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5                                                                 |
      | choose vu pane column 1             | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5 .pane-content .featured-entity__column:nth-child(1) .entity     |
      | choose vu pane column 1 arrow       | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5 .pane-content .featured-entity__column:nth-child(1) .link-arrow |
      | choose vu pane column 2             | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5 .pane-content .featured-entity__column:nth-child(2) .entity     |
      | choose vu pane column 2 arrow       | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5 .pane-content .featured-entity__column:nth-child(2) .link-arrow |
      | choose vu pane column 3             | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5 .pane-content .featured-entity__column:nth-child(3) .entity     |
      | choose vu pane column 3 arrow       | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5 .pane-content .featured-entity__column:nth-child(3) .link-arrow |
      | choose vu pane columns              | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5 .pane-content                                                   |
      | choose vu pane title                | .pane-uuid-9d167593-6b7b-4558-81ff-c968125e61e5 .pane-title                                                     |
      | whats happening pane                | .pane-uuid-4bb0c050-23ef-402c-94ac-4a2309076ad9                                                                 |
      | events                              | .pane-uuid-4bb0c050-23ef-402c-94ac-4a2309076ad9 .pane-content .featured-entity__column:nth-child(2)             |
      | social feeds block                  | #block-vumain-vumain-social-feeds                                                                               |
      | success story pane                  | .pane-uuid-886714cf-9590-428c-aef0-0813212bda0e                                                                 |
      | success story pane columns          | .pane-uuid-886714cf-9590-428c-aef0-0813212bda0e .pane-content                                                   |
      | success story pane column 1         | .pane-uuid-886714cf-9590-428c-aef0-0813212bda0e .pane-content .featured-entity__column:nth-child(1) .entity     |
      | success story pane column 2         | .pane-uuid-886714cf-9590-428c-aef0-0813212bda0e .pane-content .featured-entity__column:nth-child(2) .entity     |
      | success story pane column 3         | .pane-uuid-886714cf-9590-428c-aef0-0813212bda0e .pane-content .featured-entity__column:nth-child(3) .entity     |
      | success story pane show more button | .pane-uuid-886714cf-9590-428c-aef0-0813212bda0e .pane-content .collapse-toggle                                  |
      | success story pane title            | .pane-uuid-886714cf-9590-428c-aef0-0813212bda0e .pane-title                                                     |

  @api @javascript @PW-808 @PW-811 @PW-1665 @PW-3010
  Scenario: Anonymous user viewing homepage at the extra_small breakpoint
    Given I am viewing the site on a extra_small screen
    And I am on the homepage

    # Use screenshots to capture the page state to make sure that the page was rendered correctly (useful for debug).
    Then I see header over content
    And I save screenshot
    And I see footer below content
    And I save screenshot
    And I see content above footer

    When I see visible footer
    And wait 1 second
    Then I don't see sticky header
    And I save screenshot

    # Choose VU.
    And I see visible choose vu pane
    And I see choose vu pane column 1 above choose vu pane column 2
    And I see choose vu pane title above choose vu pane columns
    And I click on choose vu pane column 1 arrow
    And wait 1 second
    Then I am not on the homepage
    Then I move backward one page

    # What's happening at VU
    And I see visible whats happening pane
    # Events Labels are visible
    And I see visible events
    Then I should see "Location" in the ".view-events-listing .field-name-field-location-tag .location-tag-text" element
    Then I should see "Date" in the ".view-events-listing .field-name-field-date .field-label" element

    # Social feeds.
    And I see visible social feeds block

    # Success story panes.
    And I see visible success story pane
    And I see success story pane column 1 above success story pane column 2
    And I should see 2 ".pane-uuid-886714cf-9590-428c-aef0-0813212bda0e .pane-content .featured-entity__column" visible elements
    And I see success story pane title above success story pane columns

    And I see visible success story pane show more button
    And I see the text "Show more success stories"
    And I click on success story pane show more button
    Then I should see 3 ".pane-uuid-886714cf-9590-428c-aef0-0813212bda0e .pane-content .featured-entity__column" visible elements
    And I don't see success story pane show more button

    And I click on success story pane column 1
    And wait 1 seconds
    Then I am not on the homepage
    Then I move backward one page

  @api @javascript @PW-808 @PW-811 @PW-1665
  Scenario: Anonymous user viewing homepage at the small breakpoint
    Given I am viewing the site on a small screen
    And I am on the homepage

    # Use screenshots to capture the page state to make sure that the page was rendered correctly (useful for debug).
    Then I see header over content
    And I save screenshot
    And I see content above footer

    When I see visible footer
    And wait 1 second
    Then I don't see sticky header
    And I save screenshot

    # Choose VU.
    And I see visible choose vu pane
    And I see choose vu pane column 1 to the left of choose vu pane column 2
    And I see choose vu pane column 2 to the left of choose vu pane column 3
    And I see choose vu pane title above choose vu pane columns
    And I click on choose vu pane column 2 arrow
    And wait 1 second
    Then I am not on the homepage
    Then I move backward one page

    # What's happening at VU
    And I see visible whats happening pane
    # Events Labels are not visible
    Then I should not see "Location" in the ".view-events-listing .field-name-field-location-tag .location-tag-text" element
    Then I should not see "Date" in the ".view-events-listing .field-name-field-date .field-label" element

    # Social feeds.
    And I see visible social feeds block

    # Success story panes.
    And I see visible success story pane
    And I see success story pane column 1 to the left of success story pane column 2
    And I see success story pane column 2 to the left of success story pane column 3
    And I see success story pane title above success story pane columns
    And I don't see success story pane show more button

    And I click on success story pane column 1
    And wait 1 seconds
    Then I am not on the homepage
    Then I move backward one page

  @api @javascript @PW-808 @PW-811 @PW-1665 @PW-3010 @skipped
  Scenario Outline: Anonymous user viewing homepage at the breakpoints medium and above

    Given I am viewing the site on a "<screen_size>" screen
    And I am on the homepage

    # Use screenshots to capture the page state to make sure that the page was rendered correctly (useful for debug).
    Then I see logo below primary navigation
    And I save screenshot
    And I see content below header
    And I save screenshot
    And I see footer below content
    And I save screenshot
    And I see content above footer
    And I save screenshot

    When I see visible footer
    And wait 1 second
    Then I see visible sticky header
    And I save screenshot

    # Choose VU.
    And I see visible choose vu pane
    And I see choose vu pane column 1 to the left of choose vu pane column 2
    And I see choose vu pane column 2 to the left of choose vu pane column 3
    And I see choose vu pane title above choose vu pane columns
    And I click on choose vu pane column 3 arrow
    And wait 1 second
    Then I am not on the homepage
    Then I move backward one page

    # What's happening at VU
    And I see visible whats happening pane
    # Events Labels are visible
    Then I should see "Location" in the ".view-events-listing .field-name-field-location-tag .location-tag-text" element
    Then I should see "Date" in the ".view-events-listing .field-name-field-date .field-label" element

    # Social feeds.
    And I see visible social feeds block

    # Success story panes.
    And I see visible success story pane
    And I see success story pane column 1 to the left of success story pane column 2
    And I see success story pane column 2 to the left of success story pane column 3
    And I see success story pane title above success story pane columns
    And I don't see success story pane show more button

    And I click on success story pane column 1
    And wait 1 seconds
    Then I am not on the homepage
    Then I move backward one page

    Examples:
      | screen_size |
      | medium      |
      | large       |
      | extra_large |
