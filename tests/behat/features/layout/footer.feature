@p1 @test
Feature: Footer

  Ensure that anonymous users can view the footer so that the contact info is
  visible and it is possible to navigate to other areas of the site.

  Background:
    Given I define components:
      | acknowledgement             | #block-vumain-vumain-acknowledgement-country                     |
      | upper footer                | #block-panels-mini-vu-block-upper-footer                         |
      | lower footer                | #block-panels-mini-vu-block-lower-footer                         |
      | acknowledgement flag        | #block-vumain-vumain-acknowledgement-country .footer-aoc-flag    |
      | acknowledgement title       | #block-vumain-vumain-acknowledgement-country .footer-aoc-title   |
      | acknowledgement message     | #block-vumain-vumain-acknowledgement-country .footer-aoc-message |
      | footer appstore             | .footer-appstore                                                 |
      | footer chat                 | .footer-chat                                                     |
      | footer connect              | .footer-connect                                                  |
      | footer call us              | .footer-call-us                                                  |
      | footer visit us             | .footer-visit-us                                                 |
      | footer menu                 | .menu-footer                                                     |
      | future students footer menu | .future-students-footer-menu                                     |
      | staff footer menu           | .staff-footer-menu                                               |
      | tools footer menu           | .tools-footer-menu                                               |
      | copyright                   | .copyright                                                       |
      | twitter icon                | .social-media-links .fa-twitter                                  |
      | facebook icon               | .social-media-links .fa-facebook-official                        |
      | youtube icon                | .social-media-links .fa-youtube                                  |
      | instagram icon              | .social-media-links .fa-instagram                                |
      | linkedin icon               | .social-media-links .fa-linkedin-square                          |
      | snapchat icon               | .social-media-links .fa-snapchat-ghost                           |

  @api @javascript @PW-255
  Scenario: Anonymous user viewing page footer at the extra_small breakpoint device
    Given I am viewing the site on a extra_small screen
    When I go to the homepage
    And wait 1 second
    And I see acknowledgement, upper footer and lower footer inside of footer
    And I see acknowledgement above upper footer and lower footer
    And I see acknowledgement flag, acknowledgement title and acknowledgement message inside of acknowledgement
    And I see acknowledgement flag above acknowledgement title and acknowledgement message
    And I see acknowledgement title above acknowledgement message
    And I see upper footer above lower footer
    And I see future students footer menu, staff footer menu and tools footer menu inside of upper footer
    And I see future students footer menu above staff footer menu and tools footer menu
    And I see staff footer menu to left of tools footer menu
    And I see footer call us, footer visit us, footer chat, footer appstore, footer connect, footer menu and copyright inside of lower footer
    And I see footer call us, footer visit us, footer chat, footer appstore and footer connect above footer menu and copyright
    And I see footer menu above copyright
    And I see footer call us above footer visit us
    And I see footer call us, footer visit us above footer chat, footer appstore and footer connect
    And I see footer chat above footer appstore and footer connect
    And I see footer appstore above footer connect
    And I see twitter icon, facebook icon, youtube icon, instagram icon, linkedin icon and snapchat icon inside of footer

  @api @javascript @PW-255 @PW-3010
  Scenario: Anonymous user viewing page footer at the small breakpoint device
    Given I am viewing the site on a small screen
    When I go to the homepage
    And wait 1 second
    And I see acknowledgement inside of footer
    And I see acknowledgement above upper footer and lower footer
    And I see acknowledgement flag, acknowledgement title and acknowledgement message inside of acknowledgement
    And I see acknowledgement title above acknowledgement message
    And I see upper footer above lower footer
    And I see future students footer menu, staff footer menu and tools footer menu inside of upper footer
    And I see future students footer menu to left of staff footer menu and tools footer menu
    And I see staff footer menu to left of tools footer menu
    And I see footer call us, footer visit us, footer chat, footer appstore, footer connect, footer menu and copyright inside of lower footer
    And I see footer call us, footer visit us, footer chat, footer appstore and footer connect above footer menu and copyright
    And I see footer menu above copyright
    And I see footer call us above footer visit us
    And I see footer call us, footer visit us to left of footer chat, footer appstore and footer connect
    And I see footer chat to left of footer appstore and footer connect
    And I see footer appstore to left of footer connect
    And I see twitter icon, facebook icon, youtube icon, instagram icon, linkedin icon and snapchat icon inside of lower footer

  @api @javascript @PW-255 @skipped
  Scenario: Anonymous user viewing page footer at the medium breakpoint device
    Given I am viewing the site on a medium screen
    When I go to the homepage
    And wait 1 second
    And I see acknowledgement, upper footer and lower footer inside of footer
    And I see acknowledgement above upper footer and lower footer
    And I see acknowledgement flag, acknowledgement title and acknowledgement message inside of acknowledgement
    And I see acknowledgement title above acknowledgement message
    And I see upper footer above lower footer
    And I see future students footer menu, staff footer menu and tools footer menu inside of upper footer
    And I see future students footer menu to left of staff footer menu and tools footer menu
    And I see staff footer menu to left of tools footer menu
    And I see footer call us, footer visit us, footer chat, footer appstore, footer connect, footer menu and copyright inside of lower footer
    And I see footer call us, footer visit us, footer chat, footer appstore and footer connect above footer menu and copyright
    And I see footer menu above copyright
    And I see footer call us above footer visit us
    And I see footer call us, footer visit us to left of footer chat, footer appstore and footer connect
    And I see footer chat to left of footer appstore and footer connect
    And I see footer appstore to left of footer connect
    And I see twitter icon, facebook icon, youtube icon, instagram icon, linkedin icon and snapchat icon inside of lower footer
