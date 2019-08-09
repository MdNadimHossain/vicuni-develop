<?php
/**
 * @file
 * vu_rp.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function vu_rp_default_rules_configuration() {
  $items = array();
  $items['rules_vu_rp_researcher_profile_unpublished'] = entity_import('rules_config', '{ "rules_vu_rp_researcher_profile_unpublished" : {
      "LABEL" : "Researcher Profile: RP Unpublished",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_unpublishing_live_content" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "researcher_profile" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "webcontent@vu.edu.au",
            "subject" : "Profile unpublished for [node:field-rpa-staff-id]",
            "message" : "[node:title] was unpublished on [site:current-date].",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_vu_rp_staff_profile_unpublished'] = entity_import('rules_config', '{ "rules_vu_rp_staff_profile_unpublished" : {
      "LABEL" : "Researcher Profile: SP Unpublished",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_unpublishing_live_content" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "staff_profile" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "webcontent@vu.edu.au",
            "subject" : "Profile unpublished for [node:field-staff-id]",
            "message" : "[node:title] was unpublished on [site:current-date].",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
