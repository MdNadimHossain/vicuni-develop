@p1 @researcher_profile
Feature: Breadcrumb

  As a user I want to see an accurate breadcrumb that follows the right navigation structure.

  @api
  Scenario Outline: VU Home shows up in 2017 theme page builder.
    Given I am on "<path>"
    And I can see a link "VU Home" within the element "ol.breadcrumb"

    Examples:
      | path                                          |
      | industry                                      |
      | industry/explore-our-partnerships             |
      | research                                      |
      | research/excellence-in-research-for-australia |
