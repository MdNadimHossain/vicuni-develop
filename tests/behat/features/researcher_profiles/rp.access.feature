@researcher_profile @rp_access @p0
Feature: Access to Researcher Profile content type

  Ensure that Researcher Profile content access permissions are set correctly
  for designated roles.

  Background:
    Given no researcher_profiles content:
      | title                                 |
      | [TEST] Published Researcher Profile   |
      | [TEST] Unpublished Researcher Profile |
    And researcher_profile content:
      | title                                 | workbench_moderation_state_new | revision_timestamp |
      | [TEST] Published Researcher Profile   | published                      | 1                  |
      | [TEST] Unpublished Researcher Profile | draft                          | 1                  |

  @api
  Scenario Outline: Users have access to create Researcher Profile content
    Given I am logged in as a user with the "<role>" role
    When I go to "node/add/researcher-profile"
    Then I should get a "<code_create>" HTTP response

    When I visit researcher_profile "[TEST] Published Researcher Profile"
    Then I should get a "<code_view_published>" HTTP response

    When I visit researcher_profile "[TEST] Unpublished Researcher Profile"
    Then I should get a "<code_view_unpublished>" HTTP response

    When I edit researcher_profile "[TEST] Published Researcher Profile"
    Then I should get a "<code_edit_published>" HTTP response

    When I edit researcher_profile "[TEST] Unpublished Researcher Profile"
    Then I should get a "<code_edit_unpublished>" HTTP response

    Examples:
      | role                        | code_create | code_view_published | code_view_unpublished | code_edit_published | code_edit_unpublished |
      | anonymous user              | 403         | 200                 | 403                   | 403                 | 403                   |
      # @note: 'authenticated user' has 'View content revisions' permissions, giving access to this content type unpublished revisions.
      | authenticated user          | 403         | 200                 | 200                   | 403                 | 403                   |
      | Emergency Publisher         | 403         | 200                 | 200                   | 403                 | 403                   |
      | Author                      | 403         | 200                 | 200                   | 403                 | 403                   |
      | Advanced Author             | 403         | 200                 | 200                   | 403                 | 403                   |
      | Approver                    | 403         | 200                 | 200                   | 403                 | 403                   |
      | International Author        | 403         | 200                 | 200                   | 403                 | 403                   |
      | TAFE Author                 | 403         | 200                 | 200                   | 403                 | 403                   |
      | Admin                       | 403         | 200                 | 200                   | 403                 | 403                   |
      | administrator               | 200         | 200                 | 200                   | 200                 | 200                   |
      # @todo: Fix edit permissions for published and unpublished.
      | Researcher                  | 403         | 200                 | 200                   | 403                 | 403                   |
      | Researcher Profile Admin    | 403         | 200                 | 200                   | 200                 | 200                   |
      | Researcher Profile Approver | 403         | 200                 | 200                   | 200                 | 200                   |
      | Researcher Profile Tester   | 200         | 200                 | 200                   | 200                 | 200                   |

  @api
  Scenario Outline: Users have access to admin parts of a site
    Given I am logged in as a user with the "<role>" role

    When I go to "admin/workbench"
    Then I should get a "<code_workbench>" HTTP response

    When I go to "node/add/researcher-profile"
    Then I should get a "<code_create>" HTTP response

    When I go to "admin/structure/taxonomy"
    Then I should get a "<code_taxonomy>" HTTP response

    When I go to "admin/structure/taxonomy/research_institutes"
    Then I should get a "<code_taxonomy_research_institutes>" HTTP response

    When I go to "admin/structure/taxonomy/research_institutes/add"
    Then I should get a "<code_taxonomy_research_institutes_create>" HTTP response

    Examples:
      | role                        | code_workbench | code_create | code_taxonomy | code_taxonomy_research_institutes | code_taxonomy_research_institutes_create |
      | Researcher                  | 200            | 403         | 403           | 403                               | 403                                      |
      | Researcher Profile Admin    | 200            | 403         | 200           | 200                               | 200                                      |
      | Researcher Profile Tester   | 200            | 200         | 200           | 200                               | 200                                      |
      | Researcher Profile Approver | 200            | 403         | 200           | 200                               | 200                                      |
