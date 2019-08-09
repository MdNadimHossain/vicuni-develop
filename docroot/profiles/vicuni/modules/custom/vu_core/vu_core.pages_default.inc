<?php
/**
 * @file
 * vu_core.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function vu_core_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'homepage';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_homepage__panel';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'page-title-hidden',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(),
  );
  $display = new panels_display();
  $display->layout = 'raw';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(),
        'class' => 'asdfasdf',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Home';
  $display->uuid = '9021c4e3-342e-4033-837d-0b6ef0ebb2fb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_homepage__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3d01e693-75a5-4ae5-b471-597c4b0afa13';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'hero_title_box';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => 'hero-title-box',
    'css_class' => 'hero-title-box js-parallax-container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3d01e693-75a5-4ae5-b471-597c4b0afa13';
  $display->content['new-3d01e693-75a5-4ae5-b471-597c4b0afa13'] = $pane;
  $display->panels['middle'][0] = 'new-3d01e693-75a5-4ae5-b471-597c4b0afa13';
  $pane = new stdClass();
  $pane->pid = 'new-e2b260e9-3028-43b6-8158-37b9289397b4';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-526c0145b016a941d871e12405aa0e65';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '%title',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'victory-12-col',
  );
  $pane->css = array(
    'css_id' => 'views_view__courses_lists__course_browser_block',
    'css_class' => 'victory_link_list',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e2b260e9-3028-43b6-8158-37b9289397b4';
  $display->content['new-e2b260e9-3028-43b6-8158-37b9289397b4'] = $pane;
  $display->panels['middle'][1] = 'new-e2b260e9-3028-43b6-8158-37b9289397b4';
  $pane = new stdClass();
  $pane->pid = 'new-09d323cd-ed7f-4236-abea-f845c39cc990';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-free-tafe-2019';
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
    'style' => 'victory-12-col',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '09d323cd-ed7f-4236-abea-f845c39cc990';
  $display->content['new-09d323cd-ed7f-4236-abea-f845c39cc990'] = $pane;
  $display->panels['middle'][2] = 'new-09d323cd-ed7f-4236-abea-f845c39cc990';
  $pane = new stdClass();
  $pane->pid = 'new-75899902-50b5-4db2-8b34-16b7c9a10bee';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-top-20-sport-hero-banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'js-parallax-container',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '75899902-50b5-4db2-8b34-16b7c9a10bee';
  $display->content['new-75899902-50b5-4db2-8b34-16b7c9a10bee'] = $pane;
  $display->panels['middle'][3] = 'new-75899902-50b5-4db2-8b34-16b7c9a10bee';
  $pane = new stdClass();
  $pane->pid = 'new-9abea88e-a06e-41fa-88c4-93b65a6dbfdf';
  $pane->panel = 'middle';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:9d167593-6b7b-4558-81ff-c968125e61e5';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'victory-12-col',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'background--wild_sand',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9abea88e-a06e-41fa-88c4-93b65a6dbfdf';
  $display->content['new-9abea88e-a06e-41fa-88c4-93b65a6dbfdf'] = $pane;
  $display->panels['middle'][4] = 'new-9abea88e-a06e-41fa-88c4-93b65a6dbfdf';
  $pane = new stdClass();
  $pane->pid = 'new-f9eddfd1-4f56-4d3d-b2dd-555bd3172d3e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-first-year-model-hero-banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'js-parallax-container',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f9eddfd1-4f56-4d3d-b2dd-555bd3172d3e';
  $display->content['new-f9eddfd1-4f56-4d3d-b2dd-555bd3172d3e'] = $pane;
  $display->panels['middle'][5] = 'new-f9eddfd1-4f56-4d3d-b2dd-555bd3172d3e';
  $pane = new stdClass();
  $pane->pid = 'new-9e87c3e2-0e9f-491d-ba78-5dd7762e3a19';
  $pane->panel = 'middle';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:4bb0c050-23ef-402c-94ac-4a2309076ad9';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'victory-12-col',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'background--wild_sand',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '9e87c3e2-0e9f-491d-ba78-5dd7762e3a19';
  $display->content['new-9e87c3e2-0e9f-491d-ba78-5dd7762e3a19'] = $pane;
  $display->panels['middle'][6] = 'new-9e87c3e2-0e9f-491d-ba78-5dd7762e3a19';
  $pane = new stdClass();
  $pane->pid = 'new-3a6c59e2-cb2f-42f6-ba1d-3ff887d92546';
  $pane->panel = 'middle';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'uuid:886714cf-9590-428c-aef0-0813212bda0e';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'collapsable_content',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'victory-12-col',
  );
  $pane->css = array(
    'css_id' => 'panel-pane--success-story',
    'css_class' => 'background--wild_sand',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '3a6c59e2-cb2f-42f6-ba1d-3ff887d92546';
  $display->content['new-3a6c59e2-cb2f-42f6-ba1d-3ff887d92546'] = $pane;
  $display->panels['middle'][7] = 'new-3a6c59e2-cb2f-42f6-ba1d-3ff887d92546';
  $pane = new stdClass();
  $pane->pid = 'new-ae96906d-a39f-4ec8-ac9e-8dbf646b0fe0';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vumain-vumain_social_feeds';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Connect with VU',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'victory-12-col',
  );
  $pane->css = array(
    'css_id' => 'block-vumain-vumain-social-feeds',
    'css_class' => 'background--wild_sand',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'ae96906d-a39f-4ec8-ac9e-8dbf646b0fe0';
  $display->content['new-ae96906d-a39f-4ec8-ac9e-8dbf646b0fe0'] = $pane;
  $display->panels['middle'][8] = 'new-ae96906d-a39f-4ec8-ac9e-8dbf646b0fe0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  return $pages;

}
