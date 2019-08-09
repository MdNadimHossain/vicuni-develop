<?php

/**
 * @file
 * Fieldable panels panes module integration.
 */

/**
 * Implements hook_vu_core_form_FORM_alter().
 */
function fieldable_panels_panes_vu_core_form_fieldable_panels_panes_entity_edit_form_alter(&$form, $form_state) {
  fieldable_panels_panes_vu_core_form_fieldable_panels_panes_fieldable_panels_pane_content_type_edit_form_alter($form, $form_state);
}

/**
 * Implements hook_vu_core_form_FORM_alter().
 */
function fieldable_panels_panes_vu_core_form_fieldable_panels_panes_fieldable_panels_pane_content_type_edit_form_alter(&$form, $form_state) {
  if (!user_access('administer fieldable panels panes')) {
    $form['link']['#access'] = FALSE;

    // Remove URL redirects.
    if (isset($form['field_fieldable_pane_paragraph'][LANGUAGE_NONE][0]['field_block_entity_ref'][LANGUAGE_NONE]['entities'])) {
      $entities =& $form['field_fieldable_pane_paragraph'][LANGUAGE_NONE][0]['field_block_entity_ref'][LANGUAGE_NONE]['entities'];
      foreach ($entities as &$entity) {
        if (isset($entity['form']['redirect'])) {
          unset($entity['form']['redirect']);
        }
      }
    }
  }
}
