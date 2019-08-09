@p1
Feature: User roles

  Ensure that defined roles allow the correct level of access.

  @api @130806431 @PW-412
  Scenario Outline: Users can edit certain content types:
    Given I am logged in as a "<role>"
    Then I can edit a "<content type>"

    Examples:
      | role            | content type  |
      | Approver        | courses       |
      | Approver        | success story |
      | Approver        | staff profile |
      | Approver        | page builder  |
      | Approver        | news          |
      | Approver        | events        |
      | Approver        | webform       |
      | Advanced author | courses       |
      | Advanced author | success story |
      | Advanced author | staff profile |
      | Advanced author | page builder  |
      | Advanced author | news          |
      | Advanced author | events        |
      | Advanced author | webform       |
      | Author          | staff profile |
      | Author          | page builder  |
      | Author          | news          |
      | Author          | events        |

  @api @130806431 @PW-412
  Scenario Outline: Users can create certain content types
    Given I am logged in as a "<role>"
    Then I can create a "<content type>"

    Examples:
      | role            | content type  |
      | Approver        | success story |
      | Approver        | staff profile |
      | Approver        | page builder  |
      | Approver        | news          |
      | Approver        | events        |
      | Approver        | webform       |
      | Advanced author | success story |
      | Advanced author | staff profile |
      | Advanced author | news          |
      | Advanced author | events        |
      | Advanced author | webform       |
      | Author          | staff profile |
      | Author          | news          |
      | Author          | events        |
      | Webform Author  | webform       |

  @api @130806431 @PW-412
  Scenario Outline: Users can not edit certain content types
    Given I am logged in as a "<role>"
    Then I can not edit a "<content type>"

    Examples:
      | role                | content type  |
      | Approver            | unit          |
      | Approver            | unit set      |
      | Emergency publisher | courses       |
      | Emergency publisher | unit          |
      | Emergency publisher | unit set      |
      | Emergency publisher | success story |
      | Emergency publisher | staff profile |
      | Emergency publisher | page builder  |
      | Emergency publisher | news          |
      | Emergency publisher | events        |
      | Emergency publisher | webform       |
      | Author              | courses       |
      | Author              | unit          |
      | Author              | unit set      |
      | Author              | success story |
      | Author              | webform       |
      | Advanced author     | courses       |
      | Advanced author     | unit          |
      | Advanced author     | unit set      |
      | Webform Author      | page builder  |
  @api @130806431 @PW-412
  Scenario Outline: Users can not create certain content types
    Given I am logged in as a "<role>"
    Then I can not create a "<content type>"

    Examples:
      | role                | content type  |
      | Approver            | courses       |
      | Approver            | unit          |
      | Approver            | unit set      |
      | Emergency publisher | courses       |
      | Emergency publisher | unit          |
      | Emergency publisher | unit set      |
      | Emergency publisher | success story |
      | Emergency publisher | staff profile |
      | Emergency publisher | page builder  |
      | Emergency publisher | news          |
      | Emergency publisher | events        |
      | Emergency publisher | webform       |
      | Author              | courses       |
      | Author              | unit          |
      | Author              | unit set      |
      | Author              | success story |
      | Author              | page builder  |
      | Author              | webform       |
      | Advanced author     | courses       |
      | Advanced author     | unit          |
      | Advanced author     | unit set      |
      | Advanced author     | page builder  |
      | Webform Author      | page builder  |

  @api @moderation @130889883 @133148653 @PW-2307
  Scenario Outline: Users can moderate content

    Given a role "<role>" does have the permission: "<permission>"

    Examples:
      | role                | permission                                      |
      | Approver            | moderate content from draft to needs_review     |
      | Approver            | moderate content from needs_review to draft     |
      | Approver            | moderate content from needs_review to published |
      | Approver            | create any hero_title_box bean                  |
      | Approver            | edit any hero_title_box bean                    |
      | Approver            | delete any hero_title_box bean                  |
      | Approver            | create any hero_banner bean                     |
      | Approver            | edit any hero_banner bean                       |
      | Approver            | delete any hero_banner bean                     |
      | Emergency publisher | moderate content from draft to needs_review     |
      | Emergency publisher | moderate content from needs_review to draft     |
      | Emergency publisher | moderate content from needs_review to published |
      | Author              | moderate content from draft to needs_review     |
      | Author              | moderate content from needs_review to draft     |
      | Advanced author     | moderate content from draft to needs_review     |
      | Advanced author     | moderate content from needs_review to draft     |
      | Webform Author      | moderate content from draft to needs_review     |

  @api @moderation @130889883 @133148653 @PW-2307
  Scenario Outline: Users cannot moderate content
    Given a role "<role>" "doesn't" have the permission: "<permission>"

    Examples:
      | role                 | permission                                      |
      | Author               | moderate content from needs_review to published |
      | Author               | create any hero_title_box bean                  |
      | Author               | edit any hero_title_box bean                    |
      | Author               | delete any hero_title_box bean                  |
      | Author               | create any hero_banner bean                     |
      | Author               | edit any hero_banner bean                       |
      | Author               | delete any hero_banner bean                     |
      | Advanced author      | moderate content from needs_review to published |
      | Advanced author      | create any hero_title_box bean                  |
      | Advanced author      | edit any hero_title_box bean                    |
      | Advanced author      | delete any hero_title_box bean                  |
      | Advanced author      | create any hero_banner bean                     |
      | Advanced author      | edit any hero_banner bean                       |
      | Advanced author      | delete any hero_banner bean                     |
      | International Author | moderate content from needs_review to published |
      | International Author | create any hero_title_box bean                  |
      | International Author | edit any hero_title_box bean                    |
      | International Author | delete any hero_title_box bean                  |
      | International Author | create any hero_banner bean                     |
      | International Author | edit any hero_banner bean                       |
      | International Author | delete any hero_banner bean                     |
      | authenticated user   | create any hero_title_box bean                  |
      | authenticated user   | edit any hero_title_box bean                    |
      | authenticated user   | delete any hero_title_box bean                  |
      | authenticated user   | create any hero_banner bean                     |
      | authenticated user   | edit any hero_banner bean                       |
      | authenticated user   | delete any hero_banner bean                     |
      | Webform Author       | edit any hero_title_box bean                    |

  @api @inputFormats @130889883 @133148653
  Scenario Outline: User roles can use an input format
    Given a role "<role>" can use the input format: "<format>"

    Examples:
      | role                 | format        |
      | Author               | filtered_html |
      | Advanced author      | filtered_html |
      | Approver             | filtered_html |
      | Emergency publisher  | filtered_html |
      | International Author | filtered_html |
      | International Author | full_html     |
      | Webform Author       | filtered_html |

  @api @inputFormats @130889883 @133148653
  Scenario Outline: User roles cannot use the input format
    Given a role "<role>" cannot use the input format: "<format>"

    Examples:
      | role                | format    |
      | Author              | full_html |
      | Advanced author     | full_html |
      | Approver            | full_html |
      | Emergency publisher | full_html |
      | Webform Author      | full_html |

  @api @inputFormats @130889883 @133148653
  Scenario Outline: All user roles can use Migrated content input format
    Given a role "<role>" can use the input format: "<format>"

    Examples:
      | role                 | format           |
      | Author               | migrated_content |
      | Advanced author      | migrated_content |
      | Approver             | migrated_content |
      | Emergency publisher  | migrated_content |
      | International Author | migrated_content |
      | Webform Author       | migrated_content |

  @api @inputFormats @130889883 @133148653
  Scenario Outline: All user roles cannot use PHP input format
    Given a role "<role>" cannot use the input format: "<format>"

    Examples:
      | role                 | format   |
      | Author               | php_code |
      | Advanced author      | php_code |
      | Approver             | php_code |
      | Emergency publisher  | php_code |
      | International Author | php_code |
      | Webform Author       | php_code |

  @api @webforms @133148653 @PW-412
  Scenario: Approvers can view the submissions of their own webform.
    Given I am logged in as a user with the "Approver" role
    And I create a published webform with content:
      | title | Test webform |
    Then I can see a link "Results" within the element "ul.tabs--primary"
    And I save screenshot

  @api @webforms @PW-412
  Scenario: Advanced Authors can view the submissions of their own webform.
    Given I am logged in as a user with the "Advanced Author" role
    And I create a published webform with content:
      | title | Test webform |
    Then I can see a link "Results" within the element "ul.tabs--primary"
    And I save screenshot

  @api @webforms @PW-4278
  Scenario: Webform authors can view the submissions of their own webform.
    Given I am logged in as a user with the "Webform Author" role
    And I create a published webform with content:
      | title | Test webform |
    Then I can see a link "Results" within the element "ul.tabs--primary"
    And I save screenshot

  @api @webforms @PW-412
  Scenario: Approvers can view the submissions of any webform.
    Given I am logged in as a user with the "Advanced Author" role
    And I create a published webform with content:
      | title | Test webform |
    And I am logged in as a user with the "Approver" role
    When I am viewing a page of "webform" content type where:
      | condition type    | field | value        |
      | propertyCondition | title | Test webform |
    Then I can see a link "Results" within the element "ul.tabs--primary"

  @api @webforms @PW-412
  Scenario: Advanced Authors can not view the submissions of webforms not created by them.
    Given I am logged in as a user with the "Approver" role
    And I create a published webform with content:
      | title | Test webform |
    And I am logged in as a user with the "Advanced Author" role
    When I am viewing a page of "webform" content type where:
      | condition type    | field | value        |
      | propertyCondition | title | Test webform |
    Then I can not see a link "Results" within the element "ul.tabs--primary"

  @api @webforms @PW-4278
  Scenario: Webform authors can not view the submissions of webforms not created by them.
    Given I am logged in as a user with the "Approver" role
    And I create a published webform with content:
      | title | Test webform |
    And I am logged in as a user with the "Webform Author" role
    When I am viewing a page of "webform" content type where:
      | condition type    | field | value        |
      | propertyCondition | title | Test webform |
    Then I can not see a link "Results" within the element "ul.tabs--primary"

  @api @webforms @PW-412
  Scenario: Authors can be given access to view the submissions.
    Given users:
      | name      | mail             | roles  |
      | Joe User  | joe@example.com  | Author |
      | Jane User | jane@example.com | Author |

    # Create the webform as an approver and give Joe access
    # to view the submissions.
    And I am logged in as a user with the "Approver" role
    And I create a published webform with content:
      | title                     | Test webform |
      | field_results_user_access | Joe User     |

    # Joe should be able to view the webform submissions.
    And I am logged in as "Joe User"
    When I am viewing a page of "webform" content type where:
      | condition type    | field | value        |
      | propertyCondition | title | Test webform |
    Then I can see a link "Results" within the element "ul.tabs--primary"

    # Jane should not be able to view the webform submissions.
    When I am logged in as "Jane User"
    When I am viewing a page of "webform" content type where:
      | condition type    | field | value        |
      | propertyCondition | title | Test webform |
    Then I can not see a link "Results" within the element "ul.tabs--primary"

  @api @darksite @PW-955 @skipped
  Scenario Outline: Users cannot administer Darksite.
    Given I am logged in as a user with the "<role>" role
    When I visit "user"
    Then I can not see a link "Darksite" within the element "ul#admin-menu-menu"

    When I visit "admin/darksite"
    Then I should see the heading "Access denied"

    Examples:
      | role            |
      | Author          |
      | Advanced Author |
      | Approver        |

  @api @darksite @PW-955
  Scenario: Only emergency publisher can administer Darksite.
    Given I am logged in as a user with the "Emergency Publisher" role
    When I visit "user"
    Then I can see a link "Darksite" within the element "ul#admin-menu-menu"

    When I visit "admin/darksite"
    Then I should see the heading "Darksite"

  @api @user @PW-515
  Scenario: Approvers should be able to select a parent from the subsite menu.
    Given I am logged in as a user with the "Approver" role
    And I am at "node/add/page-builder"
    Then I should see "Subsites" in the "select.menu-parent-select" element

  @api @tafe_users
  Scenario: Only users with "TAFE Author" role can manage TAFE course information sessions links
    Given users:
      | name      | mail             | roles                        |
      | Jane User | jane@example.com | Advanced Author              |
      | Joe User  | joe@example.com  | Advanced Author, TAFE Author |

    # Users with TAFE Author role should be able manage TAFE info sessions.
    And I am logged in as "Joe User"
    When I go to "/admin/workbench/create"
    And I click "Manage TAFE course information session links" I see page title "TAFE information session link"

    # Users without TAFE Author role should NOT be able to see the link.
    And I am logged in as "Jane User"
    When I go to "/admin/workbench/create"
    And I can not see a link "Manage TAFE course information session links" within the element "div#content"

  @api @PW-1107
  Scenario: Authenticated user can log out
    Given I am logged in as a user with the "authenticated user" role
    When I go to "/study-at-vu"
    Then I should see the link "Log out"
    And I should not see the link "Help"
    And I should not see the link "Index"