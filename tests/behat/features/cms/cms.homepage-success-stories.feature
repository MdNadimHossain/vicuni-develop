@p0 @api @javascript @cms @PW-979 @skipped
Feature: CMS: Homepage success stories

  Scenario: Approver can edit homepage success stories.
    Given I am viewing the site on a desktop device
    And I am logged in as a user with the approver role
    Then I am at "/admin/structure/fieldable-panels-panes/view/16/edit"

    # Fieldable panels pane remove button.
    And I should see 3 ".paragraphs-item-type-node-ref-paragraph .form-actions input[value='Remove']" visible element

    # IEF Edit/Remove buttons.
    And I should see 3 ".paragraphs-item-type-node-ref-paragraph td .ief-entity-operations input[value='Edit']" visible element
    And I should see 3 ".paragraphs-item-type-node-ref-paragraph td .ief-entity-operations input[value='Remove']" visible element

    # Only three paragraph items are allowed.
    And I should see 0 ".form-item-field-fieldable-pane-paragraph-add-more-type" visible element
