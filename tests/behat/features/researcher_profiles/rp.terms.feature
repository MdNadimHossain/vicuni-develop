@researcher_profile @rp_terms @p1
Feature: Taxonomy used in Researcher Profiles.

  As an site owner, I want to know that only specific users have specific access
  to view and edit terms related to Researcher Profiles.

  @api
  Scenario Outline: Users access to view term page
    Given I am logged in as a user with the "<role>" role

    When I am viewing a "<vocabulary>" term with the name "Test"
    Then I should get a "<view_response>" HTTP response

    When I edit vocabulary "<vocabulary>" term
    Then I should get a "<edit_response>" HTTP response

    Examples:
      | role                        | vocabulary               | view_response | edit_response |
      | anonymous user              | research_institutes      | 403           | 403           |
      | authenticated user          | research_institutes      | 200           | 403           |
      | Emergency Publisher         | research_institutes      | 200           | 403           |
      | Author                      | research_institutes      | 200           | 403           |
      | Advanced Author             | research_institutes      | 200           | 403           |
      | Approver                    | research_institutes      | 200           | 403           |
      | International Author        | research_institutes      | 200           | 403           |
      | TAFE Author                 | research_institutes      | 200           | 403           |
      | Researcher                  | research_institutes      | 200           | 403           |
      | Admin                       | research_institutes      | 200           | 403           |
      | administrator               | research_institutes      | 200           | 200           |
      | Researcher                  | research_institutes      | 200           | 403           |
      | Researcher Profile Admin    | research_institutes      | 200           | 200           |
      | Researcher Profile Tester   | research_institutes      | 200           | 200           |
      | Researcher Profile Approver | research_institutes      | 200           | 200           |

      | anonymous user              | membership_organisations | 403           | 403           |
      | authenticated user          | membership_organisations | 200           | 403           |
      | Emergency Publisher         | membership_organisations | 200           | 403           |
      | Author                      | membership_organisations | 200           | 403           |
      | Advanced Author             | membership_organisations | 200           | 403           |
      | Approver                    | membership_organisations | 200           | 403           |
      | International Author        | membership_organisations | 200           | 403           |
      | TAFE Author                 | membership_organisations | 200           | 403           |
      | Researcher                  | membership_organisations | 200           | 403           |
      | Admin                       | membership_organisations | 200           | 403           |
      | administrator               | membership_organisations | 200           | 200           |
      | Researcher                  | membership_organisations | 200           | 403           |
      | Researcher Profile Admin    | membership_organisations | 200           | 200           |
      | Researcher Profile Tester   | membership_organisations | 200           | 200           |
      | Researcher Profile Approver | membership_organisations | 200           | 200           |

      | anonymous user              | membership_levels        | 403           | 403           |
      | authenticated user          | membership_levels        | 200           | 403           |
      | Emergency Publisher         | membership_levels        | 200           | 403           |
      | Author                      | membership_levels        | 200           | 403           |
      | Advanced Author             | membership_levels        | 200           | 403           |
      | Approver                    | membership_levels        | 200           | 403           |
      | International Author        | membership_levels        | 200           | 403           |
      | TAFE Author                 | membership_levels        | 200           | 403           |
      | Researcher                  | membership_levels        | 200           | 403           |
      | Admin                       | membership_levels        | 200           | 403           |
      | administrator               | membership_levels        | 200           | 200           |
      | Researcher                  | membership_levels        | 200           | 403           |
      | Researcher Profile Admin    | membership_levels        | 200           | 200           |
      | Researcher Profile Tester   | membership_levels        | 200           | 200           |
      | Researcher Profile Approver | membership_levels        | 200           | 200           |
