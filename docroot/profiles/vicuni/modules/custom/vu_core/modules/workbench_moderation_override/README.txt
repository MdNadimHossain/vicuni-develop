Workbench Moderation Override
=============================

This Drupal 7 module overrides the Workbench Moderation behaviour where, upon accessing the Create / Edit Node page, the
"moderation notes" is automatically population with the editor's name. Instead, we are returning an empty field, which
forces the content team to put in a proper moderation note.

The JIRA ticket is https://vu-pmo.atlassian.net/browse/PW-580.