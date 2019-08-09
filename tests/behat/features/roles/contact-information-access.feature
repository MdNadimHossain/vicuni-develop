@p1 @api
Feature: Contact Information Access

  Ensure anonymous users can't access contact information directly.

  @130254753
  Scenario: authenticated users
    Given I am logged in as a user with the administrator role
    And I am viewing an entity of the type "contact_information" with the content content:
      | contact_name        | John Citizen   |
      | field_contact_email | john@vu.edu.au |
      | field_contact_title | IT manager     |
      | field_contact_area  | ITS            |
      | field_contact_phone | 9999999        |
    Then I should see the heading "John Citizen"

  @130254753
  Scenario: anonymous users
    Given I am an anonymous user
    And I am viewing an entity of the type "contact_information" with the content content:
      | contact_name        | John Citizen   |
      | field_contact_email | john@vu.edu.au |
      | field_contact_title | IT manager     |
      | field_contact_area  | ITS            |
      | field_contact_phone | 9999999        |
    Then I should see the heading "Access denied"
