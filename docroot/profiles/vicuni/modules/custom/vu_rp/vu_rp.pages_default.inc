<?php
/**
 * @file
 * vu_rp.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function vu_rp_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'myworkbench__panel_context_d9a962f8-61b0-4872-a5c3-d4c5c228ef28';
  $handler->task = 'myworkbench';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 101;
  $handler->conf = array(
    'title' => 'Researcher Admin',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'use researcher profile workbench',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        3 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 26,
              1 => 21,
              2 => 11,
              3 => 16,
              4 => 36,
              5 => 41,
              6 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a1621dc2-3cf3-498b-8251-bee3772f62e2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'myworkbench__panel_context_d9a962f8-61b0-4872-a5c3-d4c5c228ef28';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ef971469-63ff-49bb-9fef-f87033dd23c0';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-7ec5a063cef0581f7787935d2b06e420';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 46,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ef971469-63ff-49bb-9fef-f87033dd23c0';
  $display->content['new-ef971469-63ff-49bb-9fef-f87033dd23c0'] = $pane;
  $display->panels['middle'][0] = 'new-ef971469-63ff-49bb-9fef-f87033dd23c0';
  $pane = new stdClass();
  $pane->pid = 'new-24e825e1-98d2-4469-b568-e566a5317814';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_rp-researcher_profile_optin';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 46,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '24e825e1-98d2-4469-b568-e566a5317814';
  $display->content['new-24e825e1-98d2-4469-b568-e566a5317814'] = $pane;
  $display->panels['middle'][1] = 'new-24e825e1-98d2-4469-b568-e566a5317814';
  $pane = new stdClass();
  $pane->pid = 'new-95a81dbf-be66-4bfb-a6dd-ba47830ad1d8';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 51,
            1 => 56,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Page title',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h2>Administration of Researcher Profiles</h2>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '95a81dbf-be66-4bfb-a6dd-ba47830ad1d8';
  $display->content['new-95a81dbf-be66-4bfb-a6dd-ba47830ad1d8'] = $pane;
  $display->panels['middle'][2] = 'new-95a81dbf-be66-4bfb-a6dd-ba47830ad1d8';
  $pane = new stdClass();
  $pane->pid = 'new-823fa93b-b7c9-4335-ba3a-aa0bf7b9376d';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-rp_researchers_list-block_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 51,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '823fa93b-b7c9-4335-ba3a-aa0bf7b9376d';
  $display->content['new-823fa93b-b7c9-4335-ba3a-aa0bf7b9376d'] = $pane;
  $display->panels['middle'][3] = 'new-823fa93b-b7c9-4335-ba3a-aa0bf7b9376d';
  $pane = new stdClass();
  $pane->pid = 'new-c1380dbb-f889-47c7-b982-b30015d49ddb';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-0562c53c041547e9d20f8a01f07d7eea';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 51,
            1 => 56,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'c1380dbb-f889-47c7-b982-b30015d49ddb';
  $display->content['new-c1380dbb-f889-47c7-b982-b30015d49ddb'] = $pane;
  $display->panels['middle'][4] = 'new-c1380dbb-f889-47c7-b982-b30015d49ddb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['myworkbench__panel_context_d9a962f8-61b0-4872-a5c3-d4c5c228ef28'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function vu_rp_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'researcher_profile_workbench_tab';
  $page->task = 'page';
  $page->admin_title = 'Researcher Profile: Workbench tab';
  $page->admin_description = 'Researcher workbench in a tab';
  $page->path = 'admin/workbench/researcher-content';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 51,
            1 => 56,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 26,
            1 => 21,
            2 => 11,
            3 => 16,
            4 => 36,
            5 => 41,
            6 => 3,
            7 => 31,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Research Profile',
    'name' => 'navigation',
    'weight' => '100',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => TRUE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_researcher_profile_workbench_tab__panel';
  $handler->task = 'page';
  $handler->subtask = 'researcher_profile_workbench_tab';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 51,
              1 => 56,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 26,
              1 => 21,
              2 => 11,
              3 => 16,
              4 => 36,
              5 => 41,
              6 => 3,
              7 => 31,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b0d3aa59-0901-4637-aa6e-a78c01d53428';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_researcher_profile_workbench_tab__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3be45a6d-b255-4548-9777-7d4ed0b67bd3';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 51,
            1 => 56,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Page title',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h2>Administration of Researcher Profiles</h2>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3be45a6d-b255-4548-9777-7d4ed0b67bd3';
  $display->content['new-3be45a6d-b255-4548-9777-7d4ed0b67bd3'] = $pane;
  $display->panels['middle'][0] = 'new-3be45a6d-b255-4548-9777-7d4ed0b67bd3';
  $pane = new stdClass();
  $pane->pid = 'new-c752852e-9ba7-42ad-a0ad-f7b4ac805314';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-rp_researchers_list-block_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 51,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c752852e-9ba7-42ad-a0ad-f7b4ac805314';
  $display->content['new-c752852e-9ba7-42ad-a0ad-f7b4ac805314'] = $pane;
  $display->panels['middle'][1] = 'new-c752852e-9ba7-42ad-a0ad-f7b4ac805314';
  $pane = new stdClass();
  $pane->pid = 'new-8b83e643-3f3c-4ea4-9102-b6dae0026e99';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-0562c53c041547e9d20f8a01f07d7eea';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '8b83e643-3f3c-4ea4-9102-b6dae0026e99';
  $display->content['new-8b83e643-3f3c-4ea4-9102-b6dae0026e99'] = $pane;
  $display->panels['middle'][2] = 'new-8b83e643-3f3c-4ea4-9102-b6dae0026e99';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['researcher_profile_workbench_tab'] = $page;

  return $pages;

}
