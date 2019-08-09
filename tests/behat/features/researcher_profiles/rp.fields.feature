@researcher_profile @rp-fields @p1
Feature: Fields on Researcher Profile content type

  Ensure that user roles have appropriate access to fields on Researcher Profile
  content type.

  Background:
    Given "research_institutes" terms:
      | name                  | field_research_institutes_link          | field_research_institutes_abbr | field_research_institutes_is_f |
      | My research institute | Link - http://my-research-institute.com | MRI                            | 1                              |

  @api
  Scenario: Researcher Profile Tester visits Researcher Profile edit page
    Given I am logged in as a user with the "Researcher Profile Tester" role
    When I visit "node/add/researcher-profile"
    Then the response status code should be 200

    # PERSONAL DETAILS

    And I see field "Staff ID"
    And element "input#edit-field-rpa-staff-id-und-0-value" exists
    And element "input#edit-field-rpa-staff-id-und-0-value.required" exists
    And element "input#edit-field-rpa-staff-id-und-0-value[disabled]" does not exist

    And I see field "First name"
    And element "input#edit-field-rpa-first-name-und-0-value" exists
    And element "input#edit-field-rpa-first-name-und-0-value.required" exists
    And element "input#edit-field-rpa-first-name-und-0-value[disabled]" does not exist

    And I see field "Middle name"
    And element "input#edit-field-rpa-middle-name-und-0-value" exists
    And element "input#edit-field-rpa-middle-name-und-0-value.required" exists
    And element "input#edit-field-rpa-middle-name-und-0-value[disabled]" does not exist

    And I see field "Last name"
    And element "input#edit-field-rpa-last-name-und-0-value" exists
    And element "input#edit-field-rpa-last-name-und-0-value.required" exists
    And element "input#edit-field-rpa-last-name-und-0-value[disabled]" does not exist

    And I see field "Preferred first name"
    And element "input#edit-field-rpa-preferred-name-und-0-value" exists
    And element "input#edit-field-rpa-preferred-name-und-0-value.required" does not exist
    And element "input#edit-field-rpa-preferred-name-und-0-value[disabled]" does not exist

    And I see the text "Do you wish to use"
    And element "input#edit-field-rp-name-variation-und-0" exists
    And element "input#edit-field-rp-name-variation-und-1" exists
    And element ".field-name-field-rp-name-variation label .form-required" exists
    And element "input#edit-field-rp-name-variation-und-0[disabled]" does not exist
    And element "input#edit-field-rp-name-variation-und-1[disabled]" does not exist

    And I see field "First name"
    And element "input#edit-field-rp-first-name-und-0-value" exists
    And element "input#edit-field-rp-first-name-und-0-value.required" exists
    And element "input#edit-field-rp-first-name-und-0-value[disabled]" does not exist

    And I see field "Last name"
    And element "input#edit-field-rp-last-name-und-0-value" exists
    And element "input#edit-field-rp-last-name-und-0-value.required" exists
    And element "input#edit-field-rp-last-name-und-0-value[disabled]" does not exist

    And I see field "2. Your title"
    And element "select#edit-field-rp-title-und" exists

    And I see field "3. Post nominal letters"
    And element "input#edit-field-rp-post-nominal-und-0-value" exists
    And element "input#edit-field-rp-post-nominal-und-0-value.required" does not exist
    And element "input#edit-field-rp-post-nominal-und-0-value[disabled]" does not exist

    And I see field "4. Email address"
    And element "input#edit-field-rpa-email-und-0-email" exists
    And element "input#edit-field-rpa-email-und-0-email.required" exists
    And element "input#edit-field-rpa-email-und-0-email[disabled]" does not exist

    And I see field "5. Phone number"
    And element "input#edit-field-rp-phone-und-0-value" exists
    And element "input#edit-field-rp-phone-und-0-value.required" does not exist
    And element "input#edit-field-rp-phone-und-0-value[disabled]" does not exist

    And I see field "6. Twitter handle"
    And element "input#edit-field-rp-twitter-und-0-value" exists
    And element "input#edit-field-rp-twitter-und-0-value.required" does not exist
    And element "input#edit-field-rp-twitter-und-0-value[disabled]" does not exist

    And I see field "7. Facebook profile link"
    And element "input#edit-field-rp-facebook-und-0-value" exists
    And element "input#edit-field-rp-facebook-und-0-value.required" does not exist
    And element "input#edit-field-rp-facebook-und-0-value[disabled]" does not exist

    And I see field "8. Linkedin profile link"
    And element "input#edit-field-rp-linkedin-und-0-value" exists
    And element "input#edit-field-rp-linkedin-und-0-value.required" does not exist
    And element "input#edit-field-rp-linkedin-und-0-value[disabled]" does not exist

    And I see the text "9. The Conversation profile link"
    And element "input#edit-field-rp-conversation-profile-und-0-url" exists
    And element "input#edit-field-rp-conversation-profile-und-0-url.required" does not exist
    And element "input#edit-field-rp-conversation-profile-und-0-url[disabled]" does not exist

    And I see field "10. ORCID identifier"
    And element "input#edit-field-rpa-orcid-id-und-0-value" exists
    And element "input#edit-field-rpa-orcid-id-und-0-value.required" does not exist
    And element "input#edit-field-rpa-orcid-id-und-0-value[disabled]" does not exist

    And I see field "11. Which VU research institute do you belong to?"
    And element "select#edit-field-rp-institute-primary-und" exists
    And element "select#edit-field-rp-institute-primary-und.required" exists
    And element "select#edit-field-rp-institute-primary-und[disabled]" does not exist

    And I see the text "Which VU research institute does your research best align to"
    And element ".field-name-field-rp-institute-best-align .form-required" exists
    And element "input[name='field_rp_institute_best_align[und]']" exists

    And I see field "12. What is your primary position at VU?"
    And element "input#edit-field-rpa-job-title-und-0-value" exists
    And element "input#edit-field-rpa-job-title-und-0-value.required" exists
    And element "input#edit-field-rpa-job-title-und-0-value[disabled]" does not exist

    And I see the text "Do you wish to provide a more descriptive or accurate position?"
    And element "input#edit-field-rp-job-title-variation-und-0" exists
    And element "input#edit-field-rp-job-title-variation-und-1" exists
    And element ".field-name-field-rp-job-title-variation label .form-required" exists
    And element "input#edit-field-rp-job-title-variation-und-0[disabled]" does not exist
    And element "input#edit-field-rp-job-title-variation-und-1[disabled]" does not exist

    And I see field "Your position at VU"
    And element "input#edit-field-rp-job-title-und-0-value" exists
    And element "input#edit-field-rp-job-title-und-0-value.required" exists
    And element "input#edit-field-rp-job-title-und-0-value[disabled]" does not exist

    And I see the text "13. Do you wish to include a photo on the VU website?"
    And element "input#edit-field-rp-use-photo-und-0" exists
    And element "input#edit-field-rp-use-photo-und-1" exists
    And element ".field-name-field-rp-use-photo label .form-required" exists
    And element "input#edit-field-rp-use-photo-und-0[disabled]" does not exist
    And element "input#edit-field-rp-use-photo-und-1[disabled]" does not exist

    And I see the text "Before you upload the image file make sure the:"
    And element "input#edit-field-rp-photo-und-0-upload" exists
    And element "input#edit-field-rp-photo-und-0-upload-button" exists
    And element ".field-name-field-rp-photo label .form-required" exists
    And element "input#edit-field-rp-photo-und-0-upload[disabled]" does not exist
    And element "input#edit-field-rp-photo-und-0-upload-button[disabled]" does not exist

    # BIOGRAPHY & EXPERTISE
    And I see the text "Areas of expertise"
    And element "input#edit-field-rp-expertise-und-0-target-id" exists
    And element "input#edit-field-rp-expertise-und-0-target-id.required" exists
    And element "input#edit-field-rp-expertise-und-0-target-id[disabled]" does not exist
    And element "input#edit-field-rp-expertise-und-1-target-id" exists
    And element "input#edit-field-rp-expertise-und-1-target-id.required" does not exist
    And element "input#edit-field-rp-expertise-und-1-target-id[disabled]" does not exist
    And element "input#edit-field-rp-expertise-und-2-target-id" exists
    And element "input#edit-field-rp-expertise-und-2-target-id.required" does not exist
    And element "input#edit-field-rp-expertise-und-2-target-id[disabled]" does not exist
    And element "input#edit-field-rp-expertise-und-3-target-id" exists
    And element "input#edit-field-rp-expertise-und-3-target-id.required" does not exist
    And element "input#edit-field-rp-expertise-und-3-target-id[disabled]" does not exist
    And element "input#edit-field-rp-expertise-und-4-target-id" exists
    And element "input#edit-field-rp-expertise-und-4-target-id.required" does not exist
    And element "input#edit-field-rp-expertise-und-4-target-id[disabled]" does not exist

    And I see field "Your biography"
    And element "textarea#edit-field-rp-biography-und-0-value" exists
    And element "textarea#edit-field-rp-biography-und-0-value.required" exists
    And element "textarea#edit-field-rp-biography-und-0-value[disabled]" does not exist

    And I see the text "Related links"
    And element "input#edit-field-rp-related-links-und-0-title" exists
    And element "input#edit-field-rp-related-links-und-1-title" exists
    And element "input#edit-field-rp-related-links-und-2-title" exists
    And element "input#edit-field-rp-related-links-und-3-title" exists
    And element "input#edit-field-rp-related-links-und-0-url" exists
    And element "input#edit-field-rp-related-links-und-1-url" exists
    And element "input#edit-field-rp-related-links-und-2-url" exists
    And element "input#edit-field-rp-related-links-und-3-url" exists
    And element "input#edit-field-rp-related-links-und-0-url.required" does not exist
    And element "input#edit-field-rp-related-links-und-1-url.required" does not exist
    And element "input#edit-field-rp-related-links-und-2-url.required" does not exist
    And element "input#edit-field-rp-related-links-und-3-url.required" does not exist
    And element "input#edit-field-rp-related-links-und-0-url[disabled]" does not exist
    And element "input#edit-field-rp-related-links-und-1-url[disabled]" does not exist
    And element "input#edit-field-rp-related-links-und-2-url[disabled]" does not exist
    And element "input#edit-field-rp-related-links-und-3-url[disabled]" does not exist

    And I see field "3. Provide a short description of you"
    And element "textarea#edit-field-rp-shorter-biography-und-0-value" exists
    And element "textarea#edit-field-rp-shorter-biography-und-0-value.required" exists
    And element "textarea#edit-field-rp-shorter-biography-und-0-value[disabled]" does not exist

    And I see the text "4. Are you available for media queries?"
    And element "input#edit-field-rp-available-to-media-und-0" exists
    And element "input#edit-field-rp-available-to-media-und-1" exists
    And element ".field-name-field-rp-available-to-media label .form-required" exists
    And element "input#edit-field-rp-available-to-media-und-0[disabled]" does not exist
    And element "input#edit-field-rp-available-to-media-und-1[disabled]" does not exist

    And I see the text "5. Enter a least one qualification, up to a maximum of five."
    And element "input#edit-field-rp-qualification-und-0-value" exists
    And element "input#edit-field-rp-qualification-und-1-value" exists
    And element "input#edit-field-rp-qualification-und-2-value" exists
    And element "input#edit-field-rp-qualification-und-3-value" exists
    And element "input#edit-field-rp-qualification-und-4-value" exists
    And element "input#edit-field-rp-qualification-und-0-value.required" exists
    And element "input#edit-field-rp-qualification-und-1-value.required" does not exist
    And element "input#edit-field-rp-qualification-und-2-value.required" does not exist
    And element "input#edit-field-rp-qualification-und-3-value.required" does not exist
    And element "input#edit-field-rp-qualification-und-4-value.required" does not exist
    And element "input#edit-field-rp-qualification-und-0-value[disabled]" does not exist
    And element "input#edit-field-rp-qualification-und-1-value[disabled]" does not exist
    And element "input#edit-field-rp-qualification-und-2-value[disabled]" does not exist
    And element "input#edit-field-rp-qualification-und-3-value[disabled]" does not exist
    And element "input#edit-field-rp-qualification-und-4-value[disabled]" does not exist

    # PUBLICATIONS

    And I see field "URL"
    And element "input#edit-field-rp-research-repo-link-und-0-url" exists
    And element "input#edit-field-rp-research-repo-link-und-0-url.required" does not exist
    And element "input#edit-field-rp-research-repo-link-und-0-url[disabled]" does not exist

    And I see field "Publication count"
    And element "input#edit-field-rpc-publication-count-und-0-value" exists
    And element "input#edit-field-rpc-publication-count-und-0-value.required" exists
    And element "input#edit-field-rpc-publication-count-und-0-value[disabled]" does not exist

    And I see field "Publication count per type"
    And element "textarea#edit-field-rpc-publication-type-count-und-0-value" exists
    And element "textarea#edit-field-rpc-publication-type-count-und-0-value.required" exists
    And element "textarea#edit-field-rpc-publication-type-count-und-0-value[disabled]" does not exist

    # Publication paragraph.
    And I see the text "Publications"
    And element "#edit-field-rpa-publications-und-0-paragraph-bundle-title" does not exist

    And I press "Add new publication"
    And element "#edit-field-rpa-publications-und-0-paragraph-bundle-title" exists

    And I see field "Type"
    And element "select#edit-field-rpa-publications-und-0-field-rpa-p-type-und" exists
    And element "select#edit-field-rpa-publications-und-0-field-rpa-p-type-und.required" exists
    And element "select#edit-field-rpa-publications-und-0-field-rpa-p-type-und[disabled]" does not exist

    And I see field "Year"
    And element "select#edit-field-rpa-publications-und-0-field-rpa-p-year-und-0-value-year" exists
    And element "select#edit-field-rpa-publications-und-0-field-rpa-p-year-und-0-value-year.required" exists
    And element "select#edit-field-rpa-publications-und-0-field-rpa-p-year-und-0-value-year[disabled]" does not exist

    And I see field "Citation"
    And element "textarea#edit-field-rpa-publications-und-0-field-rpc-p-citation-und-0-value" exists
    And element "textarea#edit-field-rpa-publications-und-0-field-rpc-p-citation-und-0-value.required" does not exist
    And element "textarea#edit-field-rpa-publications-und-0-field-rpc-p-citation-und-0-value[disabled]" does not exist

    And I see the text "DOI"
    And element "input#edit-field-rpa-publications-und-0-field-rpa-p-doi-und-0-value" exists
    And element "input#edit-field-rpa-publications-und-0-field-rpa-p-doi-und-0-value.required" does not exist
    And element "input#edit-field-rpa-publications-und-0-field-rpa-p-doi-und-0-value[disabled]" does not exist
    # / Publication paragraph.

    And I see the text "None of your publications have come through from Elements"

    # FUNDING

    # Funding paragraph.
    And I see the text "Funding"
    And element "#edit-field-rpa-funding-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Funding"
    And element "#edit-field-rpa-funding-und-0-paragraph-bundle-title" exists

    And I see the text "Project title"
    And element "input#edit-field-rpa-funding-und-0-field-rp-project-title-und-0-value" exists
    And element "input#edit-field-rpa-funding-und-0-field-rp-project-title-und-0-value.required" exists
    And element "input#edit-field-rpa-funding-und-0-field-rp-project-title-und-0-value[disabled]" does not exist

    And I see field "Source"

    And I see the text "Funding amount"
    And element "input#edit-field-rpa-funding-und-0-field-rp-fund-amount-und-0-value" exists
    And element "input#edit-field-rpa-funding-und-0-field-rp-fund-amount-und-0-value.required" exists
    And element "input#edit-field-rpa-funding-und-0-field-rp-fund-amount-und-0-value[disabled]" does not exist

    And I see the text "Duration"
    And element "select#edit-field-rpa-funding-und-0-field-rp-fund-period-duration-und-0-value-year" exists
    And element "select#edit-field-rpa-funding-und-0-field-rp-fund-period-duration-und-0-value2-year" exists
    And element "select#edit-field-rpa-funding-und-0-field-rp-fund-period-duration-und-0-value-year.required" exists
    And element "select#edit-field-rpa-funding-und-0-field-rp-fund-period-duration-und-0-value2-year.required" exists
    And element "select#edit-field-rpa-funding-und-0-field-rp-fund-period-duration-und-0-value-year[disabled]" does not exist
    And element "select#edit-field-rpa-funding-und-0-field-rp-fund-period-duration-und-0-value2-year[disabled]" does not exist
    # / Funding paragraph.

    And I see the text "1. Do you have any organisations to acknowledge?"
    And element "input#edit-field-rp-has-ota-und-0" exists
    And element "input#edit-field-rp-has-ota-und-1" exists
    And element ".field-name-field-rp-has-ota label .form-required" exists
    And element "input#edit-field-rp-has-ota-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-ota-und-1[disabled]" does not exist

    # OTA paragraph.
    And I see the text "Organisation to acknowledge"
    And element "#edit-field-rp-ota-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Organisation to acknowledge"
    And element "#edit-field-rp-ota-und-0-paragraph-bundle-title" exists

    And I see field "Organisation name"
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-name-und-0-value" exists
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-name-und-0-value.required" exists
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-name-und-0-value[disabled]" does not exist

    And I see the text "Link to organisation"
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-link-und-0-url" exists
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-link-und-0-url.required" does not exist
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-link-und-0-url[disabled]" does not exist

    And I see field "Description of support provided"
    And element "textarea#edit-field-rp-ota-und-0-field-rp-ota-description-und-0-value" exists
    And element "textarea#edit-field-rp-ota-und-0-field-rp-ota-description-und-0-value.required" does not exist
    And element "textarea#edit-field-rp-ota-und-0-field-rp-ota-description-und-0-value[disabled]" does not exist
    # / OTA paragraph.

    # SUPERVISING & TEACHING

    And I see the text "1. Are you available to supervise research students at VU?"
    And element "input#edit-field-rp-sup-is-available-und-0" exists
    And element "input#edit-field-rp-sup-is-available-und-1" exists
    And element ".field-name-field-rp-sup-is-available label .form-required" exists
    And element "input#edit-field-rp-sup-is-available-und-0[disabled]" does not exist
    And element "input#edit-field-rp-sup-is-available-und-1[disabled]" does not exist

    # Current researcher supervision paragraphs.
    And I see the text "Current supervision"
    And element "#edit-field-rpa-sup-current-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Current supervision"
    And element "#edit-field-rpa-sup-current-und-0-paragraph-bundle-title" exists

    And I see field "Your role"
    And element "select#edit-field-rpa-sup-current-und-0-field-rp-sup-role-und" exists
    And element "select#edit-field-rpa-sup-current-und-0-field-rp-sup-role-und.required" exists
    And element "select#edit-field-rpa-sup-current-und-0-field-rp-sup-role-und[disabled]" does not exist

    And I see field "Study level"
    And element "select#edit-field-rpa-sup-current-und-0-field-rp-sup-study-level-und" exists
    And element "select#edit-field-rpa-sup-current-und-0-field-rp-sup-study-level-und.required" exists
    And element "select#edit-field-rpa-sup-current-und-0-field-rp-sup-study-level-und[disabled]" does not exist

    And I see the text "Number of students"
    And element "input#edit-field-rpa-sup-current-und-0-field-rp-sup-students-und-0-value" exists
    And element "input#edit-field-rpa-sup-current-und-0-field-rp-sup-students-und-0-value.required" exists
    And element "input#edit-field-rpa-sup-current-und-0-field-rp-sup-students-und-0-value[disabled]" does not exist
    # / Current researcher supervision paragraphs.

    # Completed researcher supervision paragraphs.
    And I see the text "Completed supervision"
    And element "#edit-field-rpa-sup-completed-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Completed supervision"
    And element "#edit-field-rpa-sup-completed-und-0-paragraph-bundle-title" exists

    And I see field "Your role"
    And element "select#edit-field-rpa-sup-completed-und-0-field-rp-sup-role-und" exists
    And element "select#edit-field-rpa-sup-completed-und-0-field-rp-sup-role-und.required" exists
    And element "select#edit-field-rpa-sup-completed-und-0-field-rp-sup-role-und[disabled]" does not exist

    And I see field "Study level"
    And element "select#edit-field-rpa-sup-completed-und-0-field-rp-sup-study-level-und" exists
    And element "select#edit-field-rpa-sup-completed-und-0-field-rp-sup-study-level-und.required" exists
    And element "select#edit-field-rpa-sup-completed-und-0-field-rp-sup-study-level-und[disabled]" does not exist

    And I see the text "Number of students"
    And element "input#edit-field-rpa-sup-completed-und-0-field-rp-sup-students-und-0-value" exists
    And element "input#edit-field-rpa-sup-completed-und-0-field-rp-sup-students-und-0-value.required" exists
    And element "input#edit-field-rpa-sup-completed-und-0-field-rp-sup-students-und-0-value[disabled]" does not exist
    # / Completed researcher supervision paragraphs.

    And I see field "4. If you have supervised research students at other organisations please provide some details of your experience"
    And element "textarea#edit-field-rp-sup-other-und-0-value" exists
    And element "textarea#edit-field-rp-sup-other-und-0-value.required" does not exist
    And element "textarea#edit-field-rp-sup-other-und-0-value[disabled]" does not exist

    And I see the text "5. Describe your teaching activities and experience"
    And element "textarea#edit-field-rp-teaching-experience-und-0-value" exists
    And element "textarea#edit-field-rp-teaching-experience-und-0-value.required" does not exist
    And element "textarea#edit-field-rp-teaching-experience-und-0-value[disabled]" does not exist

    # CAREER

    And I see the text "1. Provide at least one key academic role?"
    And element "input#edit-field-rp-has-academic-roles-und-0" exists
    And element "input#edit-field-rp-has-academic-roles-und-1" exists
    And element ".field-name-field-rp-has-academic-roles label .form-required" exists
    And element "input#edit-field-rp-has-academic-roles-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-academic-roles-und-1[disabled]" does not exist

    # Researcher academic role paragraphs.
    And I see the text "Academic roles"
    And element "#edit-field-rp-academic-roles-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Academic roles"
    And element "#edit-field-rp-academic-roles-und-0-paragraph-bundle-title" exists

    And I see field "Role/position held"
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-role-und-0-value" exists
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-role-und-0-value.required" exists
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-role-und-0-value[disabled]" does not exist

    And I see field "Organisation"
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-organisation-und-0-value" exists
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-organisation-und-0-value.required" exists
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-organisation-und-0-value[disabled]" does not exist

    And I see the text "Period"
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-month" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-year" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-month.required" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-year.required" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-month[disabled]" does not exist
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-year[disabled]" does not exist
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-month" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-year" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-month.required" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-year.required" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-month[disabled]" does not exist
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-year[disabled]" does not exist
    # / Researcher academic role paragraphs.

    And I see the text "2. Do you have any key industry, community or government roles to add?"
    And element "input#edit-field-rp-has-key-industry-und-0" exists
    And element "input#edit-field-rp-has-key-industry-und-1" exists
    And element ".field-name-field-rp-has-key-industry label .form-required" exists
    And element "input#edit-field-rp-has-key-industry-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-key-industry-und-1[disabled]" does not exist

    # Researcher industry role paragraphs.
    And I see the text "Industry roles"
    And element "#edit-field-rp-industry-roles-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Industry roles"
    And element "#edit-field-rp-industry-roles-und-0-paragraph-bundle-title" exists

    And I see field "Role/position held"
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-role-und-0-value" exists
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-role-und-0-value.required" exists
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-role-und-0-value[disabled]" does not exist

    And I see field "Organisation"
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-organisation-und-0-value" exists
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-organisation-und-0-value.required" exists
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-organisation-und-0-value[disabled]" does not exist

    And I see the text "Period"
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-month" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-year" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-month.required" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-year.required" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-month[disabled]" does not exist
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-year[disabled]" does not exist
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-month" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-year" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-month.required" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-year.required" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-month[disabled]" does not exist
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-year[disabled]" does not exist
    # / Researcher industry role paragraphs.

    And I see the text "3. Do you have any awards to add?"
    And element "input#edit-field-rp-has-awards-und-0" exists
    And element "input#edit-field-rp-has-awards-und-1" exists
    And element ".field-name-field-rp-has-awards label .form-required" exists
    And element "input#edit-field-rp-has-awards-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-awards-und-1[disabled]" does not exist

    # Awards paragraphs.
    And I see the text "Awards"
    And element "#edit-field-rp-awards-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Award"
    And element "#edit-field-rp-awards-und-0-paragraph-bundle-title" exists

    And I see the text "Year"
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year" exists
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year.required" exists
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year[disabled]" does not exist

    And I see field "Award name"
    And element "input#edit-field-rp-awards-und-0-field-rp-a-award-name-und-0-value" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-award-name-und-0-value.required" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-award-name-und-0-value[disabled]" does not exist

    And I see field "Organisation making award"
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-und-0-value" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-und-0-value.required" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-und-0-value[disabled]" does not exist

    And I see the text "Link to organisation"
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-link-und-0-url" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-link-und-0-url.required" does not exist
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-link-und-0-url[disabled]" does not exist
    # / Awards paragraphs.

    And I see the text "4. Do you have any invited keynote speeches to add?"
    And element "input#edit-field-rp-has-keynote-invitations-und-0" exists
    And element "input#edit-field-rp-has-keynote-invitations-und-1" exists
    And element ".field-name-field-rp-has-keynote-invitations label .form-required" exists
    And element "input#edit-field-rp-has-keynote-invitations-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-keynote-invitations-und-1[disabled]" does not exist

    # Keynote paragraphs.
    And I see the text "Keynote speaker invitations"
    And element "#edit-field-rp-keynotes-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Keynote"
    And element "#edit-field-rp-keynotes-und-0-paragraph-bundle-title" exists

    And I see the text "Year"
    And element "select#edit-field-rp-keynotes-und-0-field-rp-k-year-und-0-value-year" exists
    And element "select#edit-field-rp-keynotes-und-0-field-rp-k-year-und-0-value-year.required" exists
    And element "select#edit-field-rp-keynotes-und-0-field-rp-k-year-und-0-value-year[disabled]" does not exist

    And I see field "Title of your keynote speech"
    And element "input#edit-field-rp-keynotes-und-0-field-rp-k-title-und-0-value" exists
    And element "input#edit-field-rp-keynotes-und-0-field-rp-k-title-und-0-value.required" exists
    And element "input#edit-field-rp-keynotes-und-0-field-rp-k-title-und-0-value[disabled]" does not exist

    And I see field "Further details including the inviting organisation or conference and location"
    And element "textarea#edit-field-rp-keynotes-und-0-field-rp-k-details-und-0-value" exists
    And element "textarea#edit-field-rp-keynotes-und-0-field-rp-k-details-und-0-value.required" exists
    And element "textarea#edit-field-rp-keynotes-und-0-field-rp-k-details-und-0-value[disabled]" does not exist
    # / Keynote paragraphs.

    And I see the text "5. Do you have any professional memberships to add?"
    And element "input#edit-field-rp-has-memberships-und-0" exists
    And element "input#edit-field-rp-has-memberships-und-1" exists
    And element ".field-name-field-rp-has-memberships label .form-required" exists
    And element "input#edit-field-rp-has-memberships-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-memberships-und-1[disabled]" does not exist

    # Membership paragraphs.
    And I see the text "Professional memberships"
    And element "#edit-field-rp-memberships-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Membership"
    And element "#edit-field-rp-memberships-und-0-paragraph-bundle-title" exists

    And I see the text "Organisation name"
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-organisation-und-0-target-id" exists
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-organisation-und-0-target-id.required" exists
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-organisation-und-0-target-id[disabled]" does not exist

    And I see the text "Your role/membership level"
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-role-und-0-target-id" exists
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-role-und-0-target-id.required" exists
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-role-und-0-target-id[disabled]" does not exist
    # / Membership paragraphs.

    And I see the text "6. Do you have any media appearances to add?"
    And element "input#edit-field-rp-has-media-appearances-und-0" exists
    And element "input#edit-field-rp-has-media-appearances-und-1" exists
    And element ".field-name-field-rp-has-media-appearances label .form-required" exists
    And element "input#edit-field-rp-has-media-appearances-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-media-appearances-und-1[disabled]" does not exist

    # Media appearance paragraphs.
    And I see the text "Media appearance"
    And element "#edit-field-rp-media-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Media appearance"
    And element "#edit-field-rp-media-und-0-paragraph-bundle-title" exists

    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-day" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-month" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-year" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-day.required" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-month.required" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-year.required" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-day[disabled]" does not exist
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-month[disabled]" does not exist
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-year[disabled]" does not exist

    And I see field "Title"
    And element "input#edit-field-rp-media-und-0-field-rp-ma-title-und-0-value" exists
    And element "input#edit-field-rp-media-und-0-field-rp-ma-title-und-0-value.required" exists
    And element "input#edit-field-rp-media-und-0-field-rp-ma-title-und-0-value[disabled]" does not exist

    And I see field "Summary details including the media outlet"
    And element "textarea#edit-field-rp-media-und-0-field-rp-ma-summary-und-0-value" exists
    And element "textarea#edit-field-rp-media-und-0-field-rp-ma-summary-und-0-value.required" exists
    And element "textarea#edit-field-rp-media-und-0-field-rp-ma-summary-und-0-value[disabled]" does not exist

    And I see the text "Link to media appearance"
    And element "input#edit-field-rp-media-und-0-field-rp-ma-link-und-0-url" exists
    And element "input#edit-field-rp-media-und-0-field-rp-ma-link-und-0-url.required" does not exist
    And element "input#edit-field-rp-media-und-0-field-rp-ma-link-und-0-url[disabled]" does not exist
    # / Media appearance paragraphs.

    # REVISION INFORMATION

    And element ".vertical-tabs-panes .node-form-revision-information" does not exist

    And I see field "Revision log message"
    And element "textarea#edit-log" exists
    And element "textarea#edit-log.required" exists
    And element "textarea#edit-log[disabled]" does not exist

    And I see field "Moderation state"
    And element "select#edit-workbench-moderation-state-new" exists
    And element "select#edit-workbench-moderation-state-new.required" does not exist
    And element "select#edit-workbench-moderation-state-new[disabled]" does not exist

  @api @skipped
  Scenario: Tester visits Researcher Profile edit page
    Given I am logged in as a user with the "Researcher Profile Tester" role
    When I visit "node/add/researcher-profile"
    Then the response status code should be 200

    # PERSONAL DETAILS

    And I see field "Staff ID"
    And element "input#edit-field-rpa-staff-id-und-0-value" exists
    And element "input#edit-field-rpa-staff-id-und-0-value.required" exists
    And element "input#edit-field-rpa-staff-id-und-0-value[disabled]" exists

    And I see field "First name"
    And element "input#edit-field-rpa-first-name-und-0-value" exists
    And element "input#edit-field-rpa-first-name-und-0-value.required" exists
    And element "input#edit-field-rpa-first-name-und-0-value[disabled]" exists

    And I see field "Middle name"
    And element "input#edit-field-rpa-middle-name-und-0-value" exists
    And element "input#edit-field-rpa-middle-name-und-0-value.required" exists
    And element "input#edit-field-rpa-middle-name-und-0-value[disabled]" exists

    And I see field "Last name"
    And element "input#edit-field-rpa-last-name-und-0-value" exists
    And element "input#edit-field-rpa-last-name-und-0-value.required" exists
    And element "input#edit-field-rpa-last-name-und-0-value[disabled]" exists

    And I see field "Preferred first name"
    And element "input#edit-field-rpa-preferred-name-und-0-value" exists
    And element "input#edit-field-rpa-preferred-name-und-0-value.required" does not exist
    And element "input#edit-field-rpa-preferred-name-und-0-value[disabled]" exists

    And I see the text "Do you wish to use"
    And element "input#edit-field-rp-name-variation-und-0" exists
    And element "input#edit-field-rp-name-variation-und-1" exists
    And element ".field-name-field-rp-name-variation label .form-required" exists
    And element "input#edit-field-rp-name-variation-und-0[disabled]" does not exist
    And element "input#edit-field-rp-name-variation-und-1[disabled]" does not exist

    And I see field "First name"
    And element "input#edit-field-rp-first-name-und-0-value" exists
    And element "input#edit-field-rp-first-name-und-0-value.required" exists
    And element "input#edit-field-rp-first-name-und-0-value[disabled]" does not exist

    And I see field "Last name"
    And element "input#edit-field-rp-last-name-und-0-value" exists
    And element "input#edit-field-rp-last-name-und-0-value.required" exists
    And element "input#edit-field-rp-last-name-und-0-value[disabled]" does not exist

    And I see field "2. Your title"
    And element "select#edit-field-rp-title-und" exists

    And I see field "3. Post nominal letters"
    And element "input#edit-field-rp-post-nominal-und-0-value" exists
    And element "input#edit-field-rp-post-nominal-und-0-value.required" does not exist
    And element "input#edit-field-rp-post-nominal-und-0-value[disabled]" does not exist

    And I see field "4. Email address"
    And element "input#edit-field-rpa-email-und-0-email" exists
    And element "input#edit-field-rpa-email-und-0-email.required" exists
    And element "input#edit-field-rpa-email-und-0-email[disabled]" exists

    And I see field "5. Phone number"
    And element "input#edit-field-rp-phone-und-0-value" exists
    And element "input#edit-field-rp-phone-und-0-value.required" does not exist
    And element "input#edit-field-rp-phone-und-0-value[disabled]" does not exist

    And I see field "6. Twitter handle"
    And element "input#edit-field-rp-twitter-und-0-value" exists
    And element "input#edit-field-rp-twitter-und-0-value.required" does not exist
    And element "input#edit-field-rp-twitter-und-0-value[disabled]" does not exist

    And I see field "7. Facebook profile link"
    And element "input#edit-field-rp-facebook-und-0-value" exists
    And element "input#edit-field-rp-facebook-und-0-value.required" does not exist
    And element "input#edit-field-rp-facebook-und-0-value[disabled]" does not exist

    And I see field "8. Linkedin profile link"
    And element "input#edit-field-rp-linkedin-und-0-value" exists
    And element "input#edit-field-rp-linkedin-und-0-value.required" does not exist
    And element "input#edit-field-rp-linkedin-und-0-value[disabled]" does not exist

    And I see the text "9. The Conversation profile link"
    And element "input#edit-field-rp-conversation-profile-und-0-url" exists
    And element "input#edit-field-rp-conversation-profile-und-0-url.required" does not exist
    And element "input#edit-field-rp-conversation-profile-und-0-url[disabled]" does not exist

    And I see field "10. ORCID identifier"
    And element "input#edit-field-rpa-orcid-id-und-0-value" exists
    And element "input#edit-field-rpa-orcid-id-und-0-value.required" does not exist
    And element "input#edit-field-rpa-orcid-id-und-0-value[disabled]" exists

    And I see field "11. Which VU research institute do you belong to?"
    And element "select#edit-field-rp-institute-primary-und" exists
    And element "select#edit-field-rp-institute-primary-und.required" exists
    And element "select#edit-field-rp-institute-primary-und[disabled]" does not exist

    And I see the text "Which VU research institute does your research best align to"
    And element ".field-name-field-rp-institute-best-align .form-required" exists
    And element "input[name='field_rp_institute_best_align[und]']" exists

    And I see field "12. What is your primary position at VU?"
    And element "input#edit-field-rpa-job-title-und-0-value" exists
    And element "input#edit-field-rpa-job-title-und-0-value.required" exists
    And element "input#edit-field-rpa-job-title-und-0-value[disabled]" exists

    And I see the text "Do you wish to provide a more descriptive or accurate position?"
    And element "input#edit-field-rp-job-title-variation-und-0" exists
    And element "input#edit-field-rp-job-title-variation-und-1" exists
    And element ".field-name-field-rp-job-title-variation label .form-required" exists
    And element "input#edit-field-rp-job-title-variation-und-0[disabled]" does not exist
    And element "input#edit-field-rp-job-title-variation-und-1[disabled]" does not exist

    And I see field "Your position at VU"
    And element "input#edit-field-rp-job-title-und-0-value" exists
    And element "input#edit-field-rp-job-title-und-0-value.required" exists
    And element "input#edit-field-rp-job-title-und-0-value[disabled]" does not exist

    And I see the text "13. Do you wish to include a photo on the VU website?"
    And element "input#edit-field-rp-use-photo-und-0" exists
    And element "input#edit-field-rp-use-photo-und-1" exists
    And element ".field-name-field-rp-use-photo label .form-required" exists
    And element "input#edit-field-rp-use-photo-und-0[disabled]" does not exist
    And element "input#edit-field-rp-use-photo-und-1[disabled]" does not exist

    And I see the text "Before you upload the image file make sure the:"
    And element "input#edit-field-rp-photo-und-0-upload" exists
    And element "input#edit-field-rp-photo-und-0-upload-button" exists
    And element ".field-name-field-rp-photo label .form-required" exists
    And element "input#edit-field-rp-photo-und-0-upload[disabled]" does not exist
    And element "input#edit-field-rp-photo-und-0-upload-button[disabled]" does not exist

    # BIOGRAPHY & EXPERTISE
    And I see the text "Areas of expertise"
    And element "input#edit-field-rp-expertise-und-0-target-id" exists
    And element "input#edit-field-rp-expertise-und-0-target-id.required" exists
    And element "input#edit-field-rp-expertise-und-0-target-id[disabled]" does not exist
    And element "input#edit-field-rp-expertise-und-1-target-id" exists
    And element "input#edit-field-rp-expertise-und-1-target-id.required" does not exist
    And element "input#edit-field-rp-expertise-und-1-target-id[disabled]" does not exist
    And element "input#edit-field-rp-expertise-und-2-target-id" exists
    And element "input#edit-field-rp-expertise-und-2-target-id.required" does not exist
    And element "input#edit-field-rp-expertise-und-2-target-id[disabled]" does not exist
    And element "input#edit-field-rp-expertise-und-3-target-id" exists
    And element "input#edit-field-rp-expertise-und-3-target-id.required" does not exist
    And element "input#edit-field-rp-expertise-und-3-target-id[disabled]" does not exist
    And element "input#edit-field-rp-expertise-und-4-target-id" exists
    And element "input#edit-field-rp-expertise-und-4-target-id.required" does not exist
    And element "input#edit-field-rp-expertise-und-4-target-id[disabled]" does not exist

    And I see field "Your biography"
    And element "textarea#edit-field-rp-biography-und-0-value" exists
    And element "textarea#edit-field-rp-biography-und-0-value.required" exists
    And element "textarea#edit-field-rp-biography-und-0-value[disabled]" does not exist

    And I see the text "Related links"
    And element "input#edit-field-rp-related-links-und-0-title" exists
    And element "input#edit-field-rp-related-links-und-1-title" exists
    And element "input#edit-field-rp-related-links-und-2-title" exists
    And element "input#edit-field-rp-related-links-und-3-title" exists
    And element "input#edit-field-rp-related-links-und-0-url" exists
    And element "input#edit-field-rp-related-links-und-1-url" exists
    And element "input#edit-field-rp-related-links-und-2-url" exists
    And element "input#edit-field-rp-related-links-und-3-url" exists
    And element "input#edit-field-rp-related-links-und-0-url.required" does not exist
    And element "input#edit-field-rp-related-links-und-1-url.required" does not exist
    And element "input#edit-field-rp-related-links-und-2-url.required" does not exist
    And element "input#edit-field-rp-related-links-und-3-url.required" does not exist
    And element "input#edit-field-rp-related-links-und-0-url[disabled]" does not exist
    And element "input#edit-field-rp-related-links-und-1-url[disabled]" does not exist
    And element "input#edit-field-rp-related-links-und-2-url[disabled]" does not exist
    And element "input#edit-field-rp-related-links-und-3-url[disabled]" does not exist

    And I see field "3. Provide a short description of you"
    And element "textarea#edit-field-rp-shorter-biography-und-0-value" exists
    And element "textarea#edit-field-rp-shorter-biography-und-0-value.required" exists
    And element "textarea#edit-field-rp-shorter-biography-und-0-value[disabled]" does not exist

    And I see the text "4. Are you available for media queries?"
    And element "input#edit-field-rp-available-to-media-und-0" exists
    And element "input#edit-field-rp-available-to-media-und-1" exists
    And element ".field-name-field-rp-available-to-media label .form-required" exists
    And element "input#edit-field-rp-available-to-media-und-0[disabled]" does not exist
    And element "input#edit-field-rp-available-to-media-und-1[disabled]" does not exist

    And I see the text "5. Enter a least one qualification, up to a maximum of five."
    And element "input#edit-field-rp-qualification-und-0-value" exists
    And element "input#edit-field-rp-qualification-und-1-value" exists
    And element "input#edit-field-rp-qualification-und-2-value" exists
    And element "input#edit-field-rp-qualification-und-3-value" exists
    And element "input#edit-field-rp-qualification-und-4-value" exists
    And element "input#edit-field-rp-qualification-und-0-value.required" exists
    And element "input#edit-field-rp-qualification-und-1-value.required" does not exist
    And element "input#edit-field-rp-qualification-und-2-value.required" does not exist
    And element "input#edit-field-rp-qualification-und-3-value.required" does not exist
    And element "input#edit-field-rp-qualification-und-4-value.required" does not exist
    And element "input#edit-field-rp-qualification-und-0-value[disabled]" does not exist
    And element "input#edit-field-rp-qualification-und-1-value[disabled]" does not exist
    And element "input#edit-field-rp-qualification-und-2-value[disabled]" does not exist
    And element "input#edit-field-rp-qualification-und-3-value[disabled]" does not exist
    And element "input#edit-field-rp-qualification-und-4-value[disabled]" does not exist

    # PUBLICATIONS

    And I see field "URL"
    And element "input#edit-field-rp-research-repo-link-und-0-url" exists
    And element "input#edit-field-rp-research-repo-link-und-0-url.required" does not exist
    And element "input#edit-field-rp-research-repo-link-und-0-url[disabled]" does not exist

    And I don't see field "Publication count"
    And element "input#edit-field-rpc-publication-count-und-0-value" does not exist

    # Publication paragraph.
    And I see the text "Publications"
    And element "#edit-field-rpa-publications-und-0-paragraph-bundle-title" does not exist
    And element "#edit-field-rpa-publications-und-add-more input[disabled]" does not exist
    # / Publication paragraph.

    And I see the text "None of your publications have come through from Elements"

    # FUNDING

    # Funding paragraph.
    And I see the text "Funding"
    And element "#edit-field-rpa-funding-und-0-paragraph-bundle-title" does not exist
    And element "#edit-field-rpa-funding-und-add-more input[disabled]" does not exist
    # / Funding paragraph.

    And I see the text "1. Do you have any organisations to acknowledge?"
    And element "input#edit-field-rp-has-ota-und-0" exists
    And element "input#edit-field-rp-has-ota-und-1" exists
    And element ".field-name-field-rp-has-ota label .form-required" exists
    And element "input#edit-field-rp-has-ota-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-ota-und-1[disabled]" does not exist

    # OTA paragraph.
    And I see the text "Organisation to acknowledge"
    And element "#edit-field-rp-ota-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Organisation to acknowledge"
    And element "#edit-field-rp-ota-und-0-paragraph-bundle-title" exists

    And I see field "Organisation name"
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-name-und-0-value" exists
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-name-und-0-value.required" exists
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-name-und-0-value[disabled]" does not exist

    And I see the text "Link to organisation"
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-link-und-0-url" exists
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-link-und-0-url.required" does not exist
    And element "input#edit-field-rp-ota-und-0-field-rp-ota-link-und-0-url[disabled]" does not exist

    And I see field "Description of support provided"
    And element "textarea#edit-field-rp-ota-und-0-field-rp-ota-description-und-0-value" exists
    And element "textarea#edit-field-rp-ota-und-0-field-rp-ota-description-und-0-value.required" does not exist
    And element "textarea#edit-field-rp-ota-und-0-field-rp-ota-description-und-0-value[disabled]" does not exist
    # / OTA paragraph.

    # SUPERVISING & TEACHING

    And I see the text "1. Are you available to supervise research students at VU?"
    And element "input#edit-field-rp-sup-is-available-und-0" exists
    And element "input#edit-field-rp-sup-is-available-und-1" exists
    And element ".field-name-field-rp-sup-is-available label .form-required" exists
    And element "input#edit-field-rp-sup-is-available-und-0[disabled]" does not exist
    And element "input#edit-field-rp-sup-is-available-und-1[disabled]" does not exist

    # Current researcher supervision paragraph.
    And element "#edit-field-rpa-sup-current-und-0-paragraph-bundle-title" does not exist
    And element "#edit-field-rpa-sup-current-und-add-more input[disabled]" does not exist
    # / Current supervision paragraph.

    # Completed researcher supervision paragraph.
    And element "#edit-field-rpa-sup-completed-und-0-paragraph-bundle-title" does not exist
    And element "#edit-field-rpa-sup-completed-und-add-more input[disabled]" does not exist
    # / Completed supervision paragraph.

    And I see field "4. If you have supervised research students at other organisations please provide some details of your experience"
    And element "textarea#edit-field-rp-sup-other-und-0-value" exists
    And element "textarea#edit-field-rp-sup-other-und-0-value.required" does not exist
    And element "textarea#edit-field-rp-sup-other-und-0-value[disabled]" does not exist

    And I see the text "5. Describe your teaching activities and experience"
    And element "textarea#edit-field-rp-teaching-experience-und-0-value" exists
    And element "textarea#edit-field-rp-teaching-experience-und-0-value.required" does not exist
    And element "textarea#edit-field-rp-teaching-experience-und-0-value[disabled]" does not exist

    # CAREER

    And I see the text "1. Provide at least one key academic role?"
    And element "input#edit-field-rp-has-academic-roles-und-0" exists
    And element "input#edit-field-rp-has-academic-roles-und-1" exists
    And element ".field-name-field-rp-has-academic-roles label .form-required" exists
    And element "input#edit-field-rp-has-academic-roles-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-academic-roles-und-1[disabled]" does not exist

    # Researcher academic role paragraphs.
    And I see the text "Academic roles"
    And element "#edit-field-rp-academic-roles-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Academic roles"
    And element "#edit-field-rp-academic-roles-und-0-paragraph-bundle-title" exists

    And I see field "Role/position held"
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-role-und-0-value" exists
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-role-und-0-value.required" exists
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-role-und-0-value[disabled]" does not exist

    And I see field "Organisation"
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-organisation-und-0-value" exists
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-organisation-und-0-value.required" exists
    And element "input#edit-field-rp-academic-roles-und-0-field-rp-ar-organisation-und-0-value[disabled]" does not exist

    And I see the text "Period"
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-month" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-year" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-month.required" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-year.required" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-month[disabled]" does not exist
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-year[disabled]" does not exist
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-month" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-year" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-month.required" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-year.required" exists
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-month[disabled]" does not exist
    And element "select#edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-year[disabled]" does not exist
    # / Researcher academic role paragraphs.

    And I see the text "2. Do you have any key industry, community or government roles to add?"
    And element "input#edit-field-rp-has-key-industry-und-0" exists
    And element "input#edit-field-rp-has-key-industry-und-1" exists
    And element ".field-name-field-rp-has-key-industry label .form-required" exists
    And element "input#edit-field-rp-has-key-industry-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-key-industry-und-1[disabled]" does not exist

    # Researcher industry role paragraphs.
    And I see the text "Industry roles"
    And element "#edit-field-rp-industry-roles-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Industry roles"
    And element "#edit-field-rp-industry-roles-und-0-paragraph-bundle-title" exists

    And I see field "Role/position held"
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-role-und-0-value" exists
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-role-und-0-value.required" exists
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-role-und-0-value[disabled]" does not exist

    And I see field "Organisation"
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-organisation-und-0-value" exists
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-organisation-und-0-value.required" exists
    And element "input#edit-field-rp-industry-roles-und-0-field-rp-ir-organisation-und-0-value[disabled]" does not exist

    And I see the text "Period"
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-month" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-year" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-month.required" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-year.required" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-month[disabled]" does not exist
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-year[disabled]" does not exist
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-month" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-year" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-month.required" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-year.required" exists
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-month[disabled]" does not exist
    And element "select#edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-year[disabled]" does not exist
    # / Researcher industry role paragraphs.

    And I see the text "3. Do you have any awards to add?"
    And element "input#edit-field-rp-has-awards-und-0" exists
    And element "input#edit-field-rp-has-awards-und-1" exists
    And element ".field-name-field-rp-has-awards label .form-required" exists
    And element "input#edit-field-rp-has-awards-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-awards-und-1[disabled]" does not exist

    # Awards paragraphs.
    And I see the text "Awards"
    And element "#edit-field-rp-awards-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Award"
    And element "#edit-field-rp-awards-und-0-paragraph-bundle-title" exists

    And I see the text "Year"
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year" exists
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year.required" exists
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year[disabled]" does not exist

    And I see field "Award name"
    And element "input#edit-field-rp-awards-und-0-field-rp-a-award-name-und-0-value" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-award-name-und-0-value.required" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-award-name-und-0-value[disabled]" does not exist

    And I see field "Organisation making award"
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-und-0-value" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-und-0-value.required" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-und-0-value[disabled]" does not exist

    And I see the text "Link to organisation"
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-link-und-0-url" exists
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-link-und-0-url.required" does not exist
    And element "input#edit-field-rp-awards-und-0-field-rp-a-organisation-link-und-0-url[disabled]" does not exist
    # / Awards paragraphs.

    And I see the text "4. Do you have any invited keynote speeches to add?"
    And element "input#edit-field-rp-has-keynote-invitations-und-0" exists
    And element "input#edit-field-rp-has-keynote-invitations-und-1" exists
    And element ".field-name-field-rp-has-keynote-invitations label .form-required" exists
    And element "input#edit-field-rp-has-keynote-invitations-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-keynote-invitations-und-1[disabled]" does not exist

    # Keynote paragraphs.
    And I see the text "Keynote speaker invitations"
    And element "#edit-field-rp-keynotes-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Keynote"
    And element "#edit-field-rp-keynotes-und-0-paragraph-bundle-title" exists

    And I see the text "Year"
    And element "select#edit-field-rp-keynotes-und-0-field-rp-k-year-und-0-value-year" exists
    And element "select#edit-field-rp-keynotes-und-0-field-rp-k-year-und-0-value-year.required" exists
    And element "select#edit-field-rp-keynotes-und-0-field-rp-k-year-und-0-value-year[disabled]" does not exist

    And I see field "Title of your keynote speech"
    And element "input#edit-field-rp-keynotes-und-0-field-rp-k-title-und-0-value" exists
    And element "input#edit-field-rp-keynotes-und-0-field-rp-k-title-und-0-value.required" exists
    And element "input#edit-field-rp-keynotes-und-0-field-rp-k-title-und-0-value[disabled]" does not exist

    And I see field "Further details including the inviting organisation or conference and location"
    And element "textarea#edit-field-rp-keynotes-und-0-field-rp-k-details-und-0-value" exists
    And element "textarea#edit-field-rp-keynotes-und-0-field-rp-k-details-und-0-value.required" exists
    And element "textarea#edit-field-rp-keynotes-und-0-field-rp-k-details-und-0-value[disabled]" does not exist
    # / Keynote paragraphs.

    And I see the text "5. Do you have any professional memberships to add?"
    And element "input#edit-field-rp-has-memberships-und-0" exists
    And element "input#edit-field-rp-has-memberships-und-1" exists
    And element ".field-name-field-rp-has-memberships label .form-required" exists
    And element "input#edit-field-rp-has-memberships-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-memberships-und-1[disabled]" does not exist

    # Membership paragraphs.
    And I see the text "Professional memberships"
    And element "#edit-field-rp-memberships-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Membership"
    And element "#edit-field-rp-memberships-und-0-paragraph-bundle-title" exists

    And I see the text "Organisation name"
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-organisation-und-0-target-id" exists
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-organisation-und-0-target-id.required" exists
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-organisation-und-0-target-id[disabled]" does not exist

    And I see the text "Your role/membership level"
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-role-und-0-target-id" exists
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-role-und-0-target-id.required" exists
    And element "input#edit-field-rp-memberships-und-0-field-rp-m-role-und-0-target-id[disabled]" does not exist
    # / Membership paragraphs.

    And I see the text "6. Do you have any media appearances to add?"
    And element "input#edit-field-rp-has-media-appearances-und-0" exists
    And element "input#edit-field-rp-has-media-appearances-und-1" exists
    And element ".field-name-field-rp-has-media-appearances label .form-required" exists
    And element "input#edit-field-rp-has-media-appearances-und-0[disabled]" does not exist
    And element "input#edit-field-rp-has-media-appearances-und-1[disabled]" does not exist

    # Media appearance paragraphs.
    And I see the text "Media appearance"
    And element "#edit-field-rp-media-und-0-paragraph-bundle-title" does not exist

    And I press "Add new Media appearance"
    And element "#edit-field-rp-media-und-0-paragraph-bundle-title" exists

    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-day" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-month" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-year" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-day.required" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-month.required" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-year.required" exists
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-day[disabled]" does not exist
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-month[disabled]" does not exist
    And element "select#edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-year[disabled]" does not exist

    And I see field "Title"
    And element "input#edit-field-rp-media-und-0-field-rp-ma-title-und-0-value" exists
    And element "input#edit-field-rp-media-und-0-field-rp-ma-title-und-0-value.required" exists
    And element "input#edit-field-rp-media-und-0-field-rp-ma-title-und-0-value[disabled]" does not exist

    And I see field "Summary details including the media outlet"
    And element "textarea#edit-field-rp-media-und-0-field-rp-ma-summary-und-0-value" exists
    And element "textarea#edit-field-rp-media-und-0-field-rp-ma-summary-und-0-value.required" exists
    And element "textarea#edit-field-rp-media-und-0-field-rp-ma-summary-und-0-value[disabled]" does not exist

    And I see the text "Link to media appearance"
    And element "input#edit-field-rp-media-und-0-field-rp-ma-link-und-0-url" exists
    And element "input#edit-field-rp-media-und-0-field-rp-ma-link-und-0-url.required" does not exist
    And element "input#edit-field-rp-media-und-0-field-rp-ma-link-und-0-url[disabled]" does not exist
    # / Media appearance paragraphs.

    # REVISION INFORMATION

    And element ".vertical-tabs-panes .node-form-revision-information" does not exist

    And I see field "Revision log message"
    And element "textarea#edit-log" exists
    And element "textarea#edit-log.required" exists
    And element "textarea#edit-log[disabled]" does not exist

    And I see field "Moderation state"
    And element "select#edit-workbench-moderation-state-new" exists
    And element "select#edit-workbench-moderation-state-new.required" does not exist
    And element "select#edit-workbench-moderation-state-new[disabled]" does not exist

    # Preview button
    And I see the button "Preview"

    # Prepopulated fields
    And the "edit-field-rp-job-title-variation-und-0" checkbox should be checked
    And the "edit-field-rp-use-photo-und-0" checkbox should be checked
    And the "edit-field-rp-name-variation-und-0" checkbox should be checked
    And the "edit-field-rp-available-to-media-und-0" checkbox should be checked
    And the "edit-field-rp-has-ota-und-0" checkbox should be checked
    And the "edit-field-rp-has-memberships-und-0" checkbox should be checked
    And the "edit-field-rp-has-keynote-invitations-und-0" checkbox should be checked
    And the "edit-field-rp-has-awards-und-0" checkbox should be checked
    And the "edit-field-rp-has-key-industry-und-0" checkbox should be checked
    And the "edit-field-rp-has-academic-roles-und-0" checkbox should be checked
    And the "edit-field-rp-sup-is-available-und-0" checkbox should be checked
    And the "edit-field-rp-has-media-appearances-und-0" checkbox should be checked
