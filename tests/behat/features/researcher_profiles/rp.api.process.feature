@researcher_profile @rp_api_process @p0
Feature: Researcher Profile API end-to-end processing

  End-to-end test to check all parts of end-to-end processing of API data.

  @api @VURpAPIServer
  Scenario: Assert that test API server works as expected with testing system.
    Given no "researcher_profile" content:
      | title                            |
      | Testprefferedname1 Testlastname1 |
      | Testprefferedname2 Testlastname2 |
      | Testprefferedname3 Testlastname3 |

    And variable "vu_rp_api_provider" has value "local"
    And research profile api provider "list" endpoint "url" value is set to "vu-rest/test-researcher/profiles"
    And research profile api provider "account" endpoint "url" value is set to "vu-rest/test-researcher/profile/{account}"
    And researcher profile api response "test-researcher/profiles" exists
    And researcher profile api response "test-researcher/profile/E8888001" exists
    And researcher profile api response "test-researcher/profile/E8888002" exists
    And researcher profile api response "test-researcher/profile/E8888003" exists
    When I add staff id "E8888001" to researcher profile list
    When I add staff id "E8888002" to researcher profile list

    And I reset research profile api queues
    And research profile api "account" queue has 0 items
    And research profile api "node" queue has 0 items

    Given I am logged in as a user with the "administrator" role

    When I visit "admin/config/system/cron/execute/vu_rp_api_fetch_list"
    Then research profile api "account" queue has 2 items
    And research profile api "node" queue has 0 items

    When I visit "admin/config/system/cron/execute/vu_rp_api_fetch_accounts"
    Then research profile api "account" queue has 0 items
    And research profile api "node" queue has 2 items

    When I visit "admin/config/system/cron/execute/vu_rp_api_process_nodes"
    Then research profile api "account" queue has 0 items
    Then research profile api "node" queue has 0 items

    # Now, assert that data was correctly processed and is shown on the page.
    And I visit "research/testprefferedname1-testlastname1"
    Then the response status code should be 200

    # HEADER.
    And I should see "Testprefferedname1 Testlastname1" in the ".page-header" element
    And I should see "Professor" in the ".page-header-title-sub1" element
    And I should see "testfirstname1.testlastname1@vu.edu.au" in the ".page-header-title-sub3" element

    # PUBLICATIONS.
    And I should see "McLaren, J. (130101). Melbourne: City of Words. Australia Scholarly Publishing Pty Ltd." in the "#publications-researcher-profile-book" element
    And I should not see "10.1080/14443058.2012.673501" in the "#publications-researcher-profile-book" element

    And I should see "McLaren, J. (100101). In Search of the Celtic Sunrise (pp. 37-46). Wakefield Press." in the "#publications-researcher-profile-book-chapter" element
    And I should see "McLaren, J. (090101). Kingdom of Neptune: seas, bays, estuaries and the danger of reading skua poetry (it may be embed in your skull) (pp. 161-171). Wakefield Press." in the "#publications-researcher-profile-book-chapter" element
    And I should see "McLaren, J. (090101). 'This is Serious': From the Backblocks to the City (pp. 48-59). University Of Queensland Press." in the "#publications-researcher-profile-book-chapter" element
    And I should see "McLaren, J. (050101). Elements of Hope: Politics in the Later Novels of F. Sionil Jos (pp. 133-142). Marshell Cavendish Academic." in the "#publications-researcher-profile-book-chapter" element
    And I should not see "10.1080/14443058.2012.673501" in the "#publications-researcher-profile-book-chapter" element

    And I should see "McLaren, J. (160101). Westminster abroad : fictions of power and authority in contemporary democracies (pp. 1-13). University of Stirling:" in the "#publications-researcher-profile-conference-paper" element
    And I should not see "10.1080/14443058.2012.673501" in the "#publications-researcher-profile-conference-paper" element

    And I should see "McLaren, J. (120601). Radical nationalism and socialist realism in Alan Marshall's autobiographical writing. Journal of Australian Studies, 36(2), (229-244)." in the "#publications-researcher-profile-journal-article" element
    And I should see "10.1080/14443058.2012.673501" in the "#publications-researcher-profile-journal-article" element
    And I should see "McLaren, J. (080101). Stephen Murray-Smith: his legacy. The La Trobe Journal,(82), (19-26)." in the "#publications-researcher-profile-journal-article" element
    And I should see "McLaren, J. (070101). A Haunted Land. Australian Studies, 20(1&2), (139-153)." in the "#publications-researcher-profile-journal-article" element
    And I should see "McLaren, J. (040101). Alan Marshall: Trapped in his Own Image. Life Writing, I(2), (85-99)." in the "#publications-researcher-profile-journal-article" element

    # FUNDING.
    And I should see "Grant 4" in the "#publications-researcher-fundings-2017" element
    And I should see "From: Grant 4 fund source" in the "#publications-researcher-fundings-2017" element
    And I should see "For period: 2017-2019" in the "#publications-researcher-fundings-2017" element
    And I should see "$20,000" in the "#publications-researcher-fundings-2017" element

    And I should see "Grant 3" in the "#publications-researcher-fundings-2016" element
    And I should see "For period: 2016-2017" in the "#publications-researcher-fundings-2016" element
    And I should see "Grant 3 fund source" in the "#publications-researcher-fundings-2016" element
    And I should see "$49,999" in the "#publications-researcher-fundings-2016" element

    And I should see "Grant 2" in the "#publications-researcher-fundings-2014" element
    And I should see "For period: 2014-2017" in the "#publications-researcher-fundings-2014" element
    And I should see "Grant 2 fund source" in the "#publications-researcher-fundings-2014" element
    And I should see "Not disclosed" in the "#publications-researcher-fundings-2014" element

    # SUPERVISION.
    And I should see "Currently supervised research students at VU" in the "#researcher-supervising-current-students" element
    And I should see "9" in the "#researcher-supervising-current-students" element

    And I should see "Completed supervision of research students at VU" in the "#researcher-supervising-past-students" element
    And I should see "5" in the "#researcher-supervising-past-students" element

    When I go to "research/testprefferedname2-testlastname2"
    Then the response status code should be 200

    When I go to "research/testprefferedname3-testlastname3"
    Then the response status code should be 404
