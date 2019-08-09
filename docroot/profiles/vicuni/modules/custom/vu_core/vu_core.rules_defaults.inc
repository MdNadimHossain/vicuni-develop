<?php
/**
 * @file
 * vu_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function vu_core_default_rules_configuration() {
  $items = array();
  $items['rules_content_needs_review'] = entity_import('rules_config', '{ "rules_content_needs_review" : {
      "LABEL" : "Content needs review",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "new-state" ], "value" : "needs_review" } },
        { "NOT data_is" : { "data" : [ "previous-state" ], "value" : "needs_review" } },
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "16" : "16" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "webcontent@vu.edu.au",
            "subject" : "For review: [node:title]",
            "message" : "[site:current-user:name] has submitted \\u003Ca href=\\u0022[site:url]node\\/[node:nid]\\/revisions\\/[node:vid]\\/view\\u0022\\u003E[node:title]\\u003C\\/a\\u003E for review\\r\\n\\r\\n[node:log]\\r\\n\\r\\n\\u003Ca href=\\u0022[site:url]admin\\/workbench\\/needs-review\\u0022\\u003ESee a list of all pending revisions\\u003C\\/a\\u003E",
            "from" : "[site:current-user:mail]",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : {
            "message" : "Page has been sent to webcontent@vu.edu.au for review.",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_email_linked_pages'] = entity_import('rules_config', '{ "rules_email_linked_pages" : {
      "LABEL" : "Email Unpublished Course Linked Pages",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "link_management", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "NOT data_is" : { "data" : [ "new-state" ], "value" : "published" } },
        { "data_is" : { "data" : [ "previous-state" ], "value" : "published" } },
        { "NOT data_is" : { "data" : [ "node:status" ], "value" : "1" } }
      ],
      "DO" : [ { "email_linked_pages" : { "node" : [ "node" ] } } ]
    }
  }');
  $items['rules_publish_courses'] = entity_import('rules_config', '{ "rules_publish_courses" : {
      "LABEL" : "Publish Courses",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : {
        "node_presave--courses" : { "bundle" : "courses" },
        "workbench_moderation_transition_presave" : []
      },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "OR" : [
            { "data_is" : { "data" : [ "node:field-handbook-include" ], "value" : "0" } },
            { "data_is" : { "data" : [ "node:field-course-offered" ], "value" : "0" } },
            { "NOT data_is" : { "data" : [ "node:field-continuing-student" ], "value" : "0" } }
          ]
        }
      ],
      "DO" : [
        { "node_unpublish" : { "node" : [ "node" ] } },
        { "workbench_moderation_set_state" : {
            "node" : [ "node" ],
            "moderation_state" : "draft",
            "force_transition" : "1"
          }
        },
        { "drupal_message" : {
            "message" : "Updates to the \\u003Cb\\u003E[node:title]\\u003C\\/b\\u003E could not be published as the course is not currently active. The latest information received from CAMS indicates:\\u003Cbr\\u003E\\r\\n- Course Offered = [node:field-course-offered]\\u003Cbr\\u003E\\r\\n- Handbook Include = [node:field-handbook-include]\\u003Cbr\\u003E\\r\\n- Continuing Student (teach-out) = [node:field-continuing-student]\\u003Cbr\\u003E\\r\\nIf this needs to be addressed in CAMS, contact the course coordinator. In an emergency, contact a site administrator to override the current settings.",
            "type" : "warning"
          }
        }
      ]
    }
  }');
  $items['rules_redirect_user_to_workbench_after_login'] = entity_import('rules_config', '{ "rules_redirect_user_to_workbench_after_login" : {
      "LABEL" : "Redirect user to workbench after login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "login", "user", "workbench" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : [
        { "redirect" : { "url" : "admin\\/workbench", "force" : "0", "destination" : "1" } }
      ]
    }
  }');
  return $items;
}
