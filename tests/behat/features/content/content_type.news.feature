@p0
Feature: News content type

  As a prospective student
  I want the ability to read news articles on any device
  So that I can keep abreast of the latest updates from VU

  @javascript @PW-254
  Scenario: Anonymous user viewing news page on mobile device
    Given I am viewing the site on a mobile device
    When I visit a page of News & Media content type with filled fields field_article_date, field_contact_info, field_related_in_link
    Then I see header over page title, body, contact information and related links
    And I see legacy title box above body and article date
    And I don't see sticky header
    And I see page title above body and article date
    And I see article date above body
    And I see contact information below body
    And I see related links below contact information
    And I see footer below page title, body, contact information and related links

  @javascript @PW-254
  Scenario: Anonymous user viewing news page on tablet device
    Given I am viewing the site on a tablet device
    When I visit a page of News & Media content type with filled fields field_article_date, field_contact_info, field_related_in_link
    Then I see header over legacy title box, page title, body, contact information and related links
    And I see legacy title box above body and article date
    And I don't see sticky header
    And I see page title above body and article date
    And I see article date above body
    And I see contact information and related links to the right of body
    And I see related links below contact information
    And I see footer below legacy title box, page title, body, contact information and related links

  @javascript @PW-254
  Scenario: Anonymous user viewing news page on desktop
    Given I am viewing the site on a desktop device
    When I visit a page of News & Media content type with filled fields field_article_date, field_contact_info, field_related_in_link
    Then I see header above legacy title box, page title, body, contact information and related links
    And I see legacy title box above body and article date
    And wait 1 second
    And I see sticky header over body
    And I see page title above body and article date
    And I see article date above body
    And I see contact information and related links to the right of body
    And I see related links below contact information
    And I see footer below legacy title box, page title, body, contact information and related links

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