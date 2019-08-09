@researcher_profile @rp_submit @p0
Feature: Submission of Researcher Profile content type

  Ensure that submitted data is shown on the Researcher profile page.

  We are filling all possible fields to make sure that they all coming through
  to the front-end.

  Note: we use suffixes in values to denote how they were entered:
  - 'M' - manual
  - 'A' - API
  - 'C' - calculated

  Background:
    Given "expertise" terms:
      | name                    |
      | My first awesome skill  |
      | My second awesome skill |
    And "research_institutes" terms:
      | name                        | field_research_institutes_link                | field_research_institutes_abbr | field_research_institutes_is_f |
      | My research institute       | Link - http://my-research-institute.com       | MRI                            | 0                              |
      | Flagship research institute | Link - http://flagship-research-institute.com | MRI                            | 1                              |
    And "membership_organisations" terms:
      | name                         |
      | ACME membership organisation |
    And "membership_levels" terms:
      | name |
      | Jedi |
    And no "researcher_profile" content:
      | title      |
      | JaneM DoeM |

  @api
  Scenario: Tester fills in researcher profile form and submits it
    Given I am logged in as a user with the "Researcher Profile Tester" role
    When I visit "node/add/researcher-profile"
    Then the response status code should be 200

    # PERSONAL DETAILS

    And I fill in "Staff ID" with "e1234567"
    And I fill in "First name" with "JaneA"
    And I fill in "Middle name" with "LucyA"
    And I fill in "Last name" with "DoeA"
    And I fill in "Preferred first name" with "JennyA"
    And I select the radio button "A different name - let me enter my own name"
    And I fill in "field_rp_first_name[und][0][value]" with "JaneM"
    And I fill in "field_rp_last_name[und][0][value]" with "DoeM"
    And I select "Dr" from "2. Your title"
    And I fill in "3. Post nominal letters" with "ABCDEF"
    And I fill in "4. Email address" with "a.jane.doe@example.com"
    And I fill in "5. Phone number" with "0412345678"
    And I fill in "6. Twitter handle" with "@janedoeexample"
    And I fill in "7. Facebook profile link" with "https://facebook.com/janedoeexample"
    And I fill in "8. Linkedin profile link" with "https://linkedin.com/janedoeexample"
    And I fill in "edit-field-rp-conversation-profile-und-0-url" with "https://some-conversation-url.com/janedoeexample"
    And I fill in "10. ORCID identifier" with "0000-0002-1825-0097"
    And I select "My research institute" from "11. Which VU research institute do you belong to?"
    And I select the radio button "Flagship research institute"
    And I fill in "12. What is your primary position at VU?" with "Main researcher A"
    And I select the radio button "Yes - let me enter my own position"
    And I fill in "Your position at VU" with "Chief researcher M"
    And I select the radio button "Yes" with the id "edit-field-rp-use-photo-und-1"
    And I attach the file "example.jpg" to "files[field_rp_photo_und_0]"

    # BIOGRAPHY & EXPERTISE
    And I fill in "edit-field-rp-expertise-und-0-target-id" with "My first awesome skill"
    And I fill in "edit-field-rp-expertise-und-1-target-id" with "My second awesome skill"
    And I fill in "Your biography" with "My interesting biography M"
    And I fill in "edit-field-rp-related-links-und-0-title" with "My first link M"
    And I fill in "edit-field-rp-related-links-und-0-url" with "http://my-related-first-example-link.com"
    And I fill in "edit-field-rp-related-links-und-1-title" with "My second link M"
    And I fill in "edit-field-rp-related-links-und-1-url" with "http://my-related-second-example-link.com"
    And I fill in "3. Provide a short description of you" with "My short biography M"
    And I select the radio button "Yes" with the id "edit-field-rp-available-to-media-und-1"
    And I fill in "edit-field-rp-qualification-und-0-value" with "My first qualification"
    And I fill in "edit-field-rp-qualification-und-1-value" with "My second qualification"

    # PUBLICATIONS
    And I fill in "edit-field-rp-research-repo-link-und-0-url" with "http://list-of-publications.com/"
    And I fill in "Publication count" with "2"
    And I fill in "Publication count per type" with "Book: 25"

    # No content message.
    And I see the text "None of your publications have come through from Elements."

    # Publication paragraph.
    And I press "edit-field-rpa-publications-und-add-more-add-more"
    And element "#edit-field-rpa-publications-und-0-paragraph-bundle-title" exists
    And I select "Book" from "edit-field-rpa-publications-und-0-field-rpa-p-type-und"
    And I select "2017" from "edit-field-rpa-publications-und-0-field-rpa-p-year-und-0-value-year"
    And I fill in "Citation" with "A citation from 2017 book C"
    And I fill in "edit-field-rpa-publications-und-0-field-rpa-p-doi-und-0-value" with "10.1002/0470841559.ch1"
    # / Publication paragraph.

    # FUNDING

    # No content message.
    And I see the text "No funding entries have come through from QUEST."

    # Funding paragraph.
    And I press "Add new Funding"
    And element "#edit-field-rpa-funding-und-0-paragraph-bundle-title" exists
    And I fill in "Project title" with "My funding project"
    And I fill in "Source" with "My funding source"
    And I fill in "Investigators" with "My funding investigators"
    And I fill in "Funding amount" with "6000"
    And I select "2014" from "edit-field-rpa-funding-und-0-field-rp-fund-period-duration-und-0-value-year"
    And I select "2017" from "edit-field-rpa-funding-und-0-field-rp-fund-period-duration-und-0-value2-year"
    # / Funding paragraph.

    And I select the radio button "Yes" with the id "edit-field-rp-has-ota-und-1"

    # OTA paragraph.
    And I press "Add new Organisation to acknowledge"
    And element "#edit-field-rp-ota-und-0-paragraph-bundle-title" exists

    And I fill in "Organisation name" with "My OTA"
    And I fill in "edit-field-rp-ota-und-0-field-rp-ota-link-und-0-url" with "http://my-ota.com"
    And I fill in "Description of support provided" with "My support received from My OTA"
    # / OTA paragraph.

    # SUPERVISING & TEACHING

    # No content message.
    And I see the text "No supervision information has come through from QUEST."

    And I select the radio button "Yes" with the id "edit-field-rp-sup-is-available-und-1"

    # Current researcher supervision paragraphs.
    And I press "Add new Current supervision"
    And element "#edit-field-rpa-sup-current-und-0-paragraph-bundle-title" exists
    And I select "Associate supervisor" from "edit-field-rpa-sup-current-und-0-field-rp-sup-role-und"
    And I select "PhD" from "edit-field-rpa-sup-current-und-0-field-rp-sup-study-level-und"
    And I fill in "edit-field-rpa-sup-current-und-0-field-rp-sup-students-und-0-value" with "24"
    # / Current researcher supervision paragraphs.

    # Completed researcher supervision paragraphs.
    And I press "Add new Completed supervision"
    And element "#edit-field-rpa-sup-completed-und-0-paragraph-bundle-title" exists
    And I select "Principal supervisor" from "edit-field-rpa-sup-completed-und-0-field-rp-sup-role-und"
    And I select "Masters by Research" from "edit-field-rpa-sup-completed-und-0-field-rp-sup-study-level-und"
    And I fill in "edit-field-rpa-sup-completed-und-0-field-rp-sup-students-und-0-value" with "42"
    # / Completed researcher supervision paragraphs.

    And I fill in "4. If you have supervised research students at other organisations please provide some details of your experience" with "Additional details about supervision of students"
    And I fill in "edit-field-rp-teaching-experience-und-0-value" with "My special teaching activities"

    # CAREER

    And I select the radio button "Yes" with the id "edit-field-rp-has-academic-roles-und-1"

    # Researcher academic role paragraphs.
    And I press "Add new Academic roles"
    And element "#edit-field-rp-academic-roles-und-0-paragraph-bundle-title" exists

    And I fill in "Role/position held" with "Important Academic Position"
    And I fill in "edit-field-rp-academic-roles-und-0-field-rp-ar-organisation-und-0-value" with "My academic organisation"
    And I select "2" from "edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-month"
    And I select "2015" from "edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value-year"
    And I select "11" from "edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-month"
    And I select "2015" from "edit-field-rp-academic-roles-und-0-field-rp-ar-period-und-0-value2-year"
    # / Researcher academic role paragraphs.

    And I select the radio button "Yes" with the id "edit-field-rp-has-key-industry-und-1"

    # Researcher industry role paragraphs.
    And I press "Add new Industry roles"
    And element "#edit-field-rp-industry-roles-und-0-paragraph-bundle-title" exists

    And I fill in "edit-field-rp-industry-roles-und-0-field-rp-ir-role-und-0-value" with "My industry role"
    And I fill in "edit-field-rp-industry-roles-und-0-field-rp-ir-organisation-und-0-value" with "My industry organisation"
    And I select "7" from "edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-month"
    And I select "2016" from "edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value-year"
    And I select "9" from "edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-month"
    And I select "2017" from "edit-field-rp-industry-roles-und-0-field-rp-ir-period-und-0-value2-year"
    # / Researcher industry role paragraphs.

    And I select the radio button "Yes" with the id "edit-field-rp-has-awards-und-1"

    # Awards paragraphs.
    And I press "Add new Award"
    And element "#edit-field-rp-awards-und-0-paragraph-bundle-title" exists

    And I see the text "Year"
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year" exists
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year.required" exists
    And element "select#edit-field-rp-awards-und-0-field-rp-a-year-und-0-value-year[disabled]" does not exist

    And I fill in "Award name" with "My award from MyOMA"
    And I fill in "Organisation making award" with "MyOMA"
    And I fill in "edit-field-rp-awards-und-0-field-rp-a-organisation-link-und-0-url" with "http://my-oma.com"
    # / Awards paragraphs.

    And I select the radio button "Yes" with the id "edit-field-rp-has-keynote-invitations-und-1"

    # Keynote paragraphs.
    And I press "Add new Keynote"
    And element "#edit-field-rp-keynotes-und-0-paragraph-bundle-title" exists

    And I select "2014" from "edit-field-rp-keynotes-und-0-field-rp-k-year-und-0-value-year"
    And I fill in "Title of your keynote speech" with "My interesting keynote"
    And I fill in "Further details including the inviting organisation or conference and location" with "Other details about the keynote in 2014"
    # / Keynote paragraphs.

    And I select the radio button "Yes" with the id "edit-field-rp-has-memberships-und-1"

    # Membership paragraphs.
    And I press "Add new Membership"
    And element "#edit-field-rp-memberships-und-0-paragraph-bundle-title" exists

    And I fill in "edit-field-rp-memberships-und-0-field-rp-m-organisation-und-0-target-id" with "ACME membership organisation"
    And I fill in "Your role/membership level" with "Jedi"
    # / Membership paragraphs.

    And I select the radio button "Yes" with the id "edit-field-rp-has-media-appearances-und-1"

    # Media appearance paragraphs.
    And I press "Add new Media appearance"
    And element "#edit-field-rp-media-und-0-paragraph-bundle-title" exists

    And I select "11" from "edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-day"
    And I select "3" from "edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-month"
    And I select "2013" from "edit-field-rp-media-und-0-field-rp-ma-date-und-0-value-year"

    And I fill in "edit-field-rp-media-und-0-field-rp-ma-title-und-0-value" with "MyMAP"
    And I fill in "edit-field-rp-media-und-0-field-rp-ma-summary-und-0-value" with "MyMAP details"
    And I fill in "edit-field-rp-media-und-0-field-rp-ma-link-und-0-url" with "http://my-map.com"
    # / Media appearance paragraphs.

    And I fill in "edit-log" with "Researcher Profile Tester"

    And I press the "Save" button

    Then I should be in the "research/janem-doem" path
    And the response status code should be 200

    # PERSONAL DETAILS

    And I should see the text "Dr JaneM DoeM ABCDEF" in the "title box" region
    And I should see the text "Chief researcher M" in the "title box" region
    And I should see the text "VU researcher at: My research institute" in the "title box" region
    And I should see the link "My research institute" in the "title box" region
    And I should see the link "http://my-research-institute.com" in the "title box" region
    And I should see the link "a.jane.doe@example.com" in the "title box" region
    And I should see the link "mailto:a.jane.doe@example.com" in the "title box" region
    And I should see an "img.js-researcher-photo" element

    And I should see the text "Key details" in the "content" region
    And I should see the text "Areas of expertise" in the "content" region
    And I should see the text "My first awesome skill" in the "content" region
    And I should see the text "My second awesome skill" in the "content" region
    And I should see the text "Available to supervise research students" in the "content" region
    And I should see the text "Available for media queries" in the "content" region
    And I should see the link "a.jane.doe@example.com" in the "content" region
    And I should see the link "mailto:a.jane.doe@example.com" in the "content" region
    And I should see the link "+61 412 345 678" in the "content" region
    And I should see the link "tel:0412345678" in the "content" region
    And I should see the link "http://twitter.com/@janedoeexample" in the "content" region
    And I should see the link "Facebook profile" in the "content" region
    And I should see the link "https://facebook.com/janedoeexample" in the "content" region
    And I should see the link "LinkedIn profile" in the "content" region
    And I should see the link "https://linkedin.com/janedoeexample" in the "content" region
    And I should see the link "The Conversation profile" in the "content" region
    And I should see the link "https://some-conversation-url.com/janedoeexample" in the "content" region
    And I should see the link "View ORCID profile" in the "content" region
    And I should see the link "https://orcid.org/0000-0002-1825-0097" in the "content" region

    And I should see the text "About JaneM DoeM" in the "content" region
    And I should see the text "My interesting biography M" in the "content" region
    And I should see the text "Related links" in the "content" region
    And I should see the link "My research institute" in the "content" region

    And I should see the text "Qualifications" in the "content" region
    And I should see the text "My first qualification" in the "content" region
    And I should see the text "My second qualification" in the "content" region

    # PUBLICATIONS
    And I should see the text "Key publications" in the "content" region
    And I should see the text "JaneM has over 2 publications, with a selection listed here." in the "content" region
    And I should see the text "A more comprehensive list of JaneM's publications is available in the VU Research Repository." in the "content" region
    And I should see the link "JaneM's publications is available in the VU Research Repository." in the "content" region
    And I should see the link "http://list-of-publications.com/" in the "content" region
    And I should see the link "Go to JaneM's publications in the VU Research Repository" in the "content" region

    And I should see the link "Book" in the "content" region
    And I should see the text "A citation from 2017 book C" in the "2017" row
    And I should see the text "doi: 10.1002/0470841559.ch1" in the "2017" row
    And I should see the link "https://doi.org/10.1002/0470841559.ch1" in the "content" region

    # FUNDING
    And I should see the text "Research funding for the past 5 years" in the "content" region
    And I should see the text "My funding project" in the "$6,000" row
    And I should see the text "From: My funding source" in the "$6,000" row
    And I should see the text "Investigators: My funding investigators" in the "$6,000" row
    And I should see the text "For period: 2014-2017" in the "$6,000" row

    And I should see the text "Collaborate with us, find out more" in the "content" region
    And I should see the link "Collaborate & commercial research" in the "content" region
    And I should see the link "Research & development innovation" in the "content" region
    And I should see the link "Research focus areas & expertise" in the "content" region
    And I should see the link "Research contacts" in the "content" region

    And I should see the text "Acknowledgements" in the "content" region
    And I should see the link "My OTA" in the "content" region
    And I should see the link "http://my-ota.com" in the "content" region
    And I should see the text "My support received from My OTA" in the "content" region

    # SUPERVISION

    And I should see the text "Supervision of research students at VU" in the "content" region
    And I should see the text "Available to supervise research students" in the "content" region
    And I should see the text "Available for media queries" in the "content" region

    And I should see the text "Currently supervised research students at VU" in the "content" region
    And I should see the text "24" in the "Associate supervisor" row
    And I should see the text "PhD" in the "Associate supervisor" row

    And I should see the text "Completed supervision of research students at VU" in the "content" region
    And I should see the text "42" in the "Principal supervisor" row
    And I should see the text "Masters by Research" in the "Principal supervisor" row

    And I should see the text "Become a graduate researcher" in the "content" region
    And I should see the link "How to apply for a research degree" in the "content" region
    And I should see the link "Our support for graduate researchers" in the "content" region
    And I should see the link "Research student fees" in the "content" region
    And I should see the link "Graduate researcher scholarships" in the "content" region

    And I should see the text "Other supervision of research students" in the "content" region
    And I should see the text "Additional details about supervision of students" in the "content" region

    And I should see the text "Teaching activities & experience" in the "content" region
    And I should see the text "My special teaching activities" in the "content" region

    # CAREER
    And I should see the text "Key academic roles" in the "content" region
    And I should see the text "Feb 2015 - Nov 2015" in the "content" region
    And I should see the text "Important Academic Position" in the "content" region
    And I should see the text "My academic organisation" in the "content" region

    And I should see the text "Key industry, community & government roles" in the "content" region
    And I should see the text "Jul 2016 - Sep 2017" in the "content" region
    And I should see the text "My industry role" in the "content" region
    And I should see the text "My industry organisation" in the "content" region

    And I should see the text "Awards" in the "content" region
    And I should see the text "2019" in the "content" region
    And I should see the text "My award from MyOMA - MyOMA" in the "content" region

    And I should see the text "Invited keynote speeches" in the "content" region
    And I should see the text "2014" in the "content" region
    And I should see the text "My interesting keynote" in the "content" region
    And I should see the text "Other details about the keynote in 2014" in the "content" region

    And I should see the text "Professional memberships" in the "content" region
    And I should see the text "Jedi, ACME membership organisation" in the "content" region

    And I should see the text "Media appearances" in the "content" region
    And I should see the text "11th March 2013" in the "content" region
    And I should see the link "MyMAP" in the "content" region
    And I should see the link "http://my-map.com" in the "content" region
    And I should see the text "MyMAP details" in the "content" region

    # Now, visit edit page and make sure that API tables are rendering entered data.
    When I click "Edit draft"
    Then I should see an ".node-researcher_profile-form" element

    # PUBLICATIONS
    And I should not see the text "None of your publications have come through from Elements."

    And I see the text "Publications from Elements"
    And I should see the text "Book" in the "admin theme content" region
    And I should see the text "2017" in the "A citation from 2017 book C" row
    And I should see the text "2017" in the "10.1002/0470841559.ch1" row
    And I should see the link "https://doi.org/10.1002/0470841559.ch1" in the "admin theme content" region

    # FUNDING
    And I should not see the text "No funding entries have come through from QUEST."

    And I should see the text "Research funding for the past 5 years" in the "admin theme content" region
    And I should see the text "My funding project" in the "admin theme content" region
    And I should see the text "From: My funding source" in the "admin theme content" region
    And I should see the text "Investigators: My funding investigators" in the "admin theme content" region
    And I should see the text "For period: 2014-2017" in the "admin theme content" region
    And I should see the text "$6,000" in the "admin theme content" region

    # SUPERVISION
    And I should not see the text "No supervision information has come through from QUEST."
    And I should see the text "Currently supervised research students at VU" in the "admin theme content" region
    And I should see the text "Associate supervisor" in the "admin theme content" region
    And I should see the text "24" in the "admin theme content" region
    And I should see the text "PhD" in the "admin theme content" region

    And I should see the text "Completed supervision of research students at VU" in the "admin theme content" region
    And I should see the text "Principal supervisor" in the "admin theme content" region
    And I should see the text "42" in the "admin theme content" region
    And I should see the text "Masters by Research" in the "admin theme content" region
