<?php
/**
 * @file
 * vu_core.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function vu_core_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'courses_atar_he';
  $mini->category = '';
  $mini->admin_title = 'Courses: ATAR HE';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'bootstrap_7_4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a2437ea6-5896-4d01-9406-6a4a7cd70f0c';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'courses_atar_he';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9df5dd2b-639d-4ef4-ae4d-4f9f0dcc9477';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_atar_he_intro';
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
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9df5dd2b-639d-4ef4-ae4d-4f9f0dcc9477';
  $display->content['new-9df5dd2b-639d-4ef4-ae4d-4f9f0dcc9477'] = $pane;
  $display->panels['left'][0] = 'new-9df5dd2b-639d-4ef4-ae4d-4f9f0dcc9477';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['courses_atar_he'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'courses_atar_se';
  $mini->category = '';
  $mini->admin_title = 'Courses: ATAR SE';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'raw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1342ba8d-746e-4165-bde3-82a231bdcc44';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'courses_atar_se';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1f9cb86d-342f-444f-9de3-5a512b5ee1d7';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_atar_se_intro';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-6',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1f9cb86d-342f-444f-9de3-5a512b5ee1d7';
  $display->content['new-1f9cb86d-342f-444f-9de3-5a512b5ee1d7'] = $pane;
  $display->panels['middle'][0] = 'new-1f9cb86d-342f-444f-9de3-5a512b5ee1d7';
  $pane = new stdClass();
  $pane->pid = 'new-b12e04be-4345-4d63-8004-c553bf6c6701';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_atar_indicator';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-6',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b12e04be-4345-4d63-8004-c553bf6c6701';
  $display->content['new-b12e04be-4345-4d63-8004-c553bf6c6701'] = $pane;
  $display->panels['middle'][1] = 'new-b12e04be-4345-4d63-8004-c553bf6c6701';
  $pane = new stdClass();
  $pane->pid = 'new-b3fe154c-a1d0-4212-907a-8f99c0e23855';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_atar_requirements_se';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b3fe154c-a1d0-4212-907a-8f99c0e23855';
  $display->content['new-b3fe154c-a1d0-4212-907a-8f99c0e23855'] = $pane;
  $display->panels['middle'][2] = 'new-b3fe154c-a1d0-4212-907a-8f99c0e23855';
  $pane = new stdClass();
  $pane->pid = 'new-2b7c552f-5c50-40b7-8451-84ca018d8232';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_atar_adjustment';
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
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2b7c552f-5c50-40b7-8451-84ca018d8232';
  $display->content['new-2b7c552f-5c50-40b7-8451-84ca018d8232'] = $pane;
  $display->panels['middle'][3] = 'new-2b7c552f-5c50-40b7-8451-84ca018d8232';
  $pane = new stdClass();
  $pane->pid = 'new-eb976703-5efa-43b5-984d-61f9d090259a';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_atar_profile';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'eb976703-5efa-43b5-984d-61f9d090259a';
  $display->content['new-eb976703-5efa-43b5-984d-61f9d090259a'] = $pane;
  $display->panels['middle'][4] = 'new-eb976703-5efa-43b5-984d-61f9d090259a';
  $pane = new stdClass();
  $pane->pid = 'new-91103564-e3df-40c4-b3dd-44284dc50122';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_special_ad_pro_se';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '91103564-e3df-40c4-b3dd-44284dc50122';
  $display->content['new-91103564-e3df-40c4-b3dd-44284dc50122'] = $pane;
  $display->panels['middle'][5] = 'new-91103564-e3df-40c4-b3dd-44284dc50122';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1f9cb86d-342f-444f-9de3-5a512b5ee1d7';
  $mini->display = $display;
  $export['courses_atar_se'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'courses_atar_vet';
  $mini->category = '';
  $mini->admin_title = 'Courses: ATAR VET';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'bootstrap_7_4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1a10f3fd-e95c-4f7e-a255-8678ce9ec77c';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'courses_atar_vet';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1403d713-5fc1-40a3-80ed-77dfb7c7ae19';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_atar_vet_intro';
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
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1403d713-5fc1-40a3-80ed-77dfb7c7ae19';
  $display->content['new-1403d713-5fc1-40a3-80ed-77dfb7c7ae19'] = $pane;
  $display->panels['left'][0] = 'new-1403d713-5fc1-40a3-80ed-77dfb7c7ae19';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['courses_atar_vet'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'courses_atar_work_life';
  $mini->category = '';
  $mini->admin_title = 'Courses: ATAR Work Life';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'bootstrap_7_4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b406753e-fc3a-4f65-8aec-035119d9aa8f';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'courses_atar_work_life';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7e56e5e8-fd57-461b-b3cf-47637b1906f4';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_atar_work_life_intro';
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
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7e56e5e8-fd57-461b-b3cf-47637b1906f4';
  $display->content['new-7e56e5e8-fd57-461b-b3cf-47637b1906f4'] = $pane;
  $display->panels['left'][0] = 'new-7e56e5e8-fd57-461b-b3cf-47637b1906f4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7e56e5e8-fd57-461b-b3cf-47637b1906f4';
  $mini->display = $display;
  $export['courses_atar_work_life'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'hero_title_box';
  $mini->category = 'VicUni';
  $mini->admin_title = 'Homepage - Hero title box';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'raw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
    'style' => 'naked',
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5a8f53cb-da7c-4430-8ae5-af2bca8b31c4';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'hero_title_box';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2136c6f6-415e-43cf-8dd4-6ca8f4ce149d';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-blocks_hero_title_box-block';
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
    'style' => 'naked',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2136c6f6-415e-43cf-8dd4-6ca8f4ce149d';
  $display->content['new-2136c6f6-415e-43cf-8dd4-6ca8f4ce149d'] = $pane;
  $display->panels['middle'][0] = 'new-2136c6f6-415e-43cf-8dd4-6ca8f4ce149d';
  $pane = new stdClass();
  $pane->pid = 'new-a0ee5562-5754-4430-b5f5-738e82d89d1c';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_course_search';
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
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a0ee5562-5754-4430-b5f5-738e82d89d1c';
  $display->content['new-a0ee5562-5754-4430-b5f5-738e82d89d1c'] = $pane;
  $display->panels['middle'][1] = 'new-a0ee5562-5754-4430-b5f5-738e82d89d1c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['hero_title_box'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'vu_block_lower_footer';
  $mini->category = 'VicUni';
  $mini->admin_title = 'Lower footer';
  $mini->admin_description = 'Lower footer';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'bootstrap_stacked_3_3_3_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'middle_1' => NULL,
      'middle_2' => NULL,
      'middle_3' => NULL,
      'middle_4' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '39443e75-582f-4e4f-8338-0bf5ad7595b4';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'vu_block_lower_footer';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0bf5592c-dc1b-470f-9d7a-7fdfcc908a23';
  $pane->panel = 'bottom';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-footer';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0bf5592c-dc1b-470f-9d7a-7fdfcc908a23';
  $display->content['new-0bf5592c-dc1b-470f-9d7a-7fdfcc908a23'] = $pane;
  $display->panels['bottom'][0] = 'new-0bf5592c-dc1b-470f-9d7a-7fdfcc908a23';
  $pane = new stdClass();
  $pane->pid = 'new-83168b22-0b23-472b-8afd-4a4d58b9f36f';
  $pane->panel = 'bottom';
  $pane->type = 'block';
  $pane->subtype = 'vumain-vumain_copyright';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'copyright',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '83168b22-0b23-472b-8afd-4a4d58b9f36f';
  $display->content['new-83168b22-0b23-472b-8afd-4a4d58b9f36f'] = $pane;
  $display->panels['bottom'][1] = 'new-83168b22-0b23-472b-8afd-4a4d58b9f36f';
  $pane = new stdClass();
  $pane->pid = 'new-6f53b424-318a-402e-a1cc-614400a019d8';
  $pane->panel = 'middle_1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '0',
          'paths' => 'vu-sydney
vu-sydney/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Call us',
    'title' => '<i class="fa fa-phone"></i>Call us',
    'body' => '<a href="tel:1300VICUNI" class="noext">1300 VIC UNI</a>',
    'format' => 'full_html',
    'substitute' => TRUE,
    'title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'footer-call-us',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6f53b424-318a-402e-a1cc-614400a019d8';
  $display->content['new-6f53b424-318a-402e-a1cc-614400a019d8'] = $pane;
  $display->panels['middle_1'][0] = 'new-6f53b424-318a-402e-a1cc-614400a019d8';
  $pane = new stdClass();
  $pane->pid = 'new-095e67c9-1d7c-4cfc-874b-745c45a36566';
  $pane->panel = 'middle_1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '0',
          'paths' => 'vu-sydney
vu-sydney/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Visit us',
    'title' => '<i class="fa fa-map-marker"></i>Visit us',
    'body' => '<a href="/contact-us/student-service-centres">Find a VUHQ Student Centre</a>',
    'format' => 'full_html',
    'substitute' => TRUE,
    'title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'footer-visit-us',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '095e67c9-1d7c-4cfc-874b-745c45a36566';
  $display->content['new-095e67c9-1d7c-4cfc-874b-745c45a36566'] = $pane;
  $display->panels['middle_1'][1] = 'new-095e67c9-1d7c-4cfc-874b-745c45a36566';
  $pane = new stdClass();
  $pane->pid = 'new-f9a19a98-c08d-4159-be53-56bf4b375a8c';
  $pane->panel = 'middle_1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'vu-sydney
vu-sydney/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Call us sydney',
    'title' => '<i class="fa fa-phone"></i>Call us',
    'title_heading' => 'h3',
    'body' => '<p><a class="noext" href="tel:+61282653222">+61 2 8265 3222</a></p>
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
  $pane->uuid = 'f9a19a98-c08d-4159-be53-56bf4b375a8c';
  $display->content['new-f9a19a98-c08d-4159-be53-56bf4b375a8c'] = $pane;
  $display->panels['middle_1'][2] = 'new-f9a19a98-c08d-4159-be53-56bf4b375a8c';
  $pane = new stdClass();
  $pane->pid = 'new-92700d66-6d4c-435b-8649-ef9ca77c9818';
  $pane->panel = 'middle_2';
  $pane->type = 'block';
  $pane->subtype = 'vu_chat_now-vu_chat_footer';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '0',
          'paths' => 'vu-sydney
vu-sydney/*',
        ),
        'context' => 'empty',
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'footer-chat',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '92700d66-6d4c-435b-8649-ef9ca77c9818';
  $display->content['new-92700d66-6d4c-435b-8649-ef9ca77c9818'] = $pane;
  $display->panels['middle_2'][0] = 'new-92700d66-6d4c-435b-8649-ef9ca77c9818';
  $pane = new stdClass();
  $pane->pid = 'new-728e9876-d24e-46fa-acde-9ee325185b2d';
  $pane->panel = 'middle_2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'vu-sydney
vu-sydney/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Visit us sydney',
    'title' => '<i class="fa fa-map-marker"></i>Visit us',
    'title_heading' => 'h3',
    'body' => '<p><a href="/vu-sydney/contact-vu-sydney">Level 1, 160-166 Sussex Street Sydney NSW 2000</a></p>
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '728e9876-d24e-46fa-acde-9ee325185b2d';
  $display->content['new-728e9876-d24e-46fa-acde-9ee325185b2d'] = $pane;
  $display->panels['middle_2'][1] = 'new-728e9876-d24e-46fa-acde-9ee325185b2d';
  $pane = new stdClass();
  $pane->pid = 'new-026426a8-ec53-4872-b1df-6e6d0662f41a';
  $pane->panel = 'middle_3';
  $pane->type = 'block';
  $pane->subtype = 'vumain-vumain_campus_app';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '0',
          'paths' => 'vu-sydney
vu-sydney/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Victoria University student app',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'footer-appstore',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '026426a8-ec53-4872-b1df-6e6d0662f41a';
  $display->content['new-026426a8-ec53-4872-b1df-6e6d0662f41a'] = $pane;
  $display->panels['middle_3'][0] = 'new-026426a8-ec53-4872-b1df-6e6d0662f41a';
  $pane = new stdClass();
  $pane->pid = 'new-a53c9370-14d2-4087-b0d9-41bb34d42bb0';
  $pane->panel = 'middle_3';
  $pane->type = 'block';
  $pane->subtype = 'vu_chat_now-vu_chat_footer';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'vu-sydney
vu-sydney/*',
        ),
        'context' => 'empty',
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
  $pane->uuid = 'a53c9370-14d2-4087-b0d9-41bb34d42bb0';
  $display->content['new-a53c9370-14d2-4087-b0d9-41bb34d42bb0'] = $pane;
  $display->panels['middle_3'][1] = 'new-a53c9370-14d2-4087-b0d9-41bb34d42bb0';
  $pane = new stdClass();
  $pane->pid = 'new-2f35855e-28c1-4630-90e5-6a01a42d6e9d';
  $pane->panel = 'middle_4';
  $pane->type = 'block';
  $pane->subtype = 'vumain-vumain_social_media_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Connect',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'footer-connect',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2f35855e-28c1-4630-90e5-6a01a42d6e9d';
  $display->content['new-2f35855e-28c1-4630-90e5-6a01a42d6e9d'] = $pane;
  $display->panels['middle_4'][0] = 'new-2f35855e-28c1-4630-90e5-6a01a42d6e9d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0bf5592c-dc1b-470f-9d7a-7fdfcc908a23';
  $mini->display = $display;
  $export['vu_block_lower_footer'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'vu_block_primary_menu';
  $mini->category = 'VicUni';
  $mini->admin_title = 'Primary menu';
  $mini->admin_description = 'Primary menu';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'victory_navigation';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'middle_1' => NULL,
      'middle_2' => NULL,
      'middle_3' => NULL,
      'middle_4' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
      'primary' => NULL,
      'secondary' => NULL,
      'shutters' => NULL,
      'shutter' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dcbfc1bb-bb45-4b18-ab49-30c17a4d05c0';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'vu_block_primary_menu';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-15dd542d-6052-46a3-a404-b118e0ad9271';
  $pane->panel = 'primary';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-main-menu-level1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array(
    'method' => '0',
    'settings' => array(),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '15dd542d-6052-46a3-a404-b118e0ad9271';
  $display->content['new-15dd542d-6052-46a3-a404-b118e0ad9271'] = $pane;
  $display->panels['primary'][0] = 'new-15dd542d-6052-46a3-a404-b118e0ad9271';
  $pane = new stdClass();
  $pane->pid = 'new-2ff39077-f685-437c-94f7-7544eb6ce0ac';
  $pane->panel = 'secondary';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-main-menu-level2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array(
    'method' => '0',
    'settings' => array(),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2ff39077-f685-437c-94f7-7544eb6ce0ac';
  $display->content['new-2ff39077-f685-437c-94f7-7544eb6ce0ac'] = $pane;
  $display->panels['secondary'][0] = 'new-2ff39077-f685-437c-94f7-7544eb6ce0ac';
  $pane = new stdClass();
  $pane->pid = 'new-e9b14237-bb4d-42bc-90db-9e390061e8ed';
  $pane->panel = 'secondary';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-menu-subsites-level2';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e9b14237-bb4d-42bc-90db-9e390061e8ed';
  $display->content['new-e9b14237-bb4d-42bc-90db-9e390061e8ed'] = $pane;
  $display->panels['secondary'][1] = 'new-e9b14237-bb4d-42bc-90db-9e390061e8ed';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['vu_block_primary_menu'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'vu_block_upper_footer';
  $mini->category = 'VicUni';
  $mini->admin_title = 'Upper footer';
  $mini->admin_description = 'Upper footer';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'bootstrap_stacked_6_3_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'middle_1' => NULL,
      'middle_2' => NULL,
      'middle_3' => NULL,
      'middle_4' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '39443e75-582f-4e4f-8338-0bf5ad7595b4';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'vu_block_upper_footer';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2f61df64-3b67-48db-bf29-ce01bf9af4a9';
  $pane->panel = 'middle_1';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-footer-useful-links-col1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Future students',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'future-students-footer-menu',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2f61df64-3b67-48db-bf29-ce01bf9af4a9';
  $display->content['new-2f61df64-3b67-48db-bf29-ce01bf9af4a9'] = $pane;
  $display->panels['middle_1'][0] = 'new-2f61df64-3b67-48db-bf29-ce01bf9af4a9';
  $pane = new stdClass();
  $pane->pid = 'new-05c6aabd-6bbd-4b3d-bd2c-8ada5daa8884';
  $pane->panel = 'middle_2';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-footer-useful-links-col2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Staff & students',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-xs-6 staff-footer-menu',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '05c6aabd-6bbd-4b3d-bd2c-8ada5daa8884';
  $display->content['new-05c6aabd-6bbd-4b3d-bd2c-8ada5daa8884'] = $pane;
  $display->panels['middle_2'][0] = 'new-05c6aabd-6bbd-4b3d-bd2c-8ada5daa8884';
  $pane = new stdClass();
  $pane->pid = 'new-db84f29f-6849-4459-ad85-f0ec13a7cab8';
  $pane->panel = 'middle_3';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-footer-main-menu-tools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'tools-footer-menu',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'db84f29f-6849-4459-ad85-f0ec13a7cab8';
  $display->content['new-db84f29f-6849-4459-ad85-f0ec13a7cab8'] = $pane;
  $display->panels['middle_3'][0] = 'new-db84f29f-6849-4459-ad85-f0ec13a7cab8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['vu_block_upper_footer'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'vu_courses_hta';
  $mini->category = 'VicUni';
  $mini->admin_title = 'Courses: How to Apply';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'bootstrap_12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c8a6ff5b-7447-494c-81ec-491e8c153226';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'vu_courses_hta';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e8b9d5fa-cfc7-454c-9fca-7219b1e9715b';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_mid_year';
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
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e8b9d5fa-cfc7-454c-9fca-7219b1e9715b';
  $display->content['new-e8b9d5fa-cfc7-454c-9fca-7219b1e9715b'] = $pane;
  $display->panels['middle'][0] = 'new-e8b9d5fa-cfc7-454c-9fca-7219b1e9715b';
  $pane = new stdClass();
  $pane->pid = 'new-33c3ee50-8897-45cb-b0b0-7008569c1a5e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_tafe_lit_num_ass';
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
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '33c3ee50-8897-45cb-b0b0-7008569c1a5e';
  $display->content['new-33c3ee50-8897-45cb-b0b0-7008569c1a5e'] = $pane;
  $display->panels['middle'][1] = 'new-33c3ee50-8897-45cb-b0b0-7008569c1a5e';
  $pane = new stdClass();
  $pane->pid = 'new-c2fcaf21-f269-4615-8792-c1d7ae99655e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_special_admission';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c2fcaf21-f269-4615-8792-c1d7ae99655e';
  $display->content['new-c2fcaf21-f269-4615-8792-c1d7ae99655e'] = $pane;
  $display->panels['middle'][2] = 'new-c2fcaf21-f269-4615-8792-c1d7ae99655e';
  $pane = new stdClass();
  $pane->pid = 'new-71a02a2a-3c0d-4161-87db-879ba4f13b7e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_closed';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '71a02a2a-3c0d-4161-87db-879ba4f13b7e';
  $display->content['new-71a02a2a-3c0d-4161-87db-879ba4f13b7e'] = $pane;
  $display->panels['middle'][3] = 'new-71a02a2a-3c0d-4161-87db-879ba4f13b7e';
  $pane = new stdClass();
  $pane->pid = 'new-dc924ae4-e841-4a0d-aab8-e3543b4d9589';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_open_heading';
  $pane->shown = FALSE;
  $pane->access = array();
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'dc924ae4-e841-4a0d-aab8-e3543b4d9589';
  $display->content['new-dc924ae4-e841-4a0d-aab8-e3543b4d9589'] = $pane;
  $display->panels['middle'][4] = 'new-dc924ae4-e841-4a0d-aab8-e3543b4d9589';
  $pane = new stdClass();
  $pane->pid = 'new-eeae8f24-d9d6-44d8-b469-8193e66b7911';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_vtac_open';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'eeae8f24-d9d6-44d8-b469-8193e66b7911';
  $display->content['new-eeae8f24-d9d6-44d8-b469-8193e66b7911'] = $pane;
  $display->panels['middle'][5] = 'new-eeae8f24-d9d6-44d8-b469-8193e66b7911';
  $pane = new stdClass();
  $pane->pid = 'new-d8638212-dfa1-4446-bca5-1fdd7fa8e917';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_direct_open';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'd8638212-dfa1-4446-bca5-1fdd7fa8e917';
  $display->content['new-d8638212-dfa1-4446-bca5-1fdd7fa8e917'] = $pane;
  $display->panels['middle'][6] = 'new-d8638212-dfa1-4446-bca5-1fdd7fa8e917';
  $pane = new stdClass();
  $pane->pid = 'new-8dca0def-9d2e-4420-bb8a-d68219c3ea61';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_direct_closed';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '8dca0def-9d2e-4420-bb8a-d68219c3ea61';
  $display->content['new-8dca0def-9d2e-4420-bb8a-d68219c3ea61'] = $pane;
  $display->panels['middle'][7] = 'new-8dca0def-9d2e-4420-bb8a-d68219c3ea61';
  $pane = new stdClass();
  $pane->pid = 'new-5bc38ee4-9e81-4710-adda-4c2afc715de4';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_open_apprenticeship';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '5bc38ee4-9e81-4710-adda-4c2afc715de4';
  $display->content['new-5bc38ee4-9e81-4710-adda-4c2afc715de4'] = $pane;
  $display->panels['middle'][8] = 'new-5bc38ee4-9e81-4710-adda-4c2afc715de4';
  $pane = new stdClass();
  $pane->pid = 'new-ad04fb73-b896-402a-977d-fa9f89915768';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_intntl_summary';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'ad04fb73-b896-402a-977d-fa9f89915768';
  $display->content['new-ad04fb73-b896-402a-977d-fa9f89915768'] = $pane;
  $display->panels['middle'][9] = 'new-ad04fb73-b896-402a-977d-fa9f89915768';
  $pane = new stdClass();
  $pane->pid = 'new-1ee7140e-ef66-444b-95fd-22bb9802ddb0';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_intntl_contacts';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '1ee7140e-ef66-444b-95fd-22bb9802ddb0';
  $display->content['new-1ee7140e-ef66-444b-95fd-22bb9802ddb0'] = $pane;
  $display->panels['middle'][10] = 'new-1ee7140e-ef66-444b-95fd-22bb9802ddb0';
  $pane = new stdClass();
  $pane->pid = 'new-84783962-a4bb-4d9d-9bfb-e87430bcbe4b';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_short_course_summary';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '84783962-a4bb-4d9d-9bfb-e87430bcbe4b';
  $display->content['new-84783962-a4bb-4d9d-9bfb-e87430bcbe4b'] = $pane;
  $display->panels['middle'][11] = 'new-84783962-a4bb-4d9d-9bfb-e87430bcbe4b';
  $pane = new stdClass();
  $pane->pid = 'new-9bebfe7c-f50d-46f9-a4b1-19e0e038db37';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_vu_online';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '9bebfe7c-f50d-46f9-a4b1-19e0e038db37';
  $display->content['new-9bebfe7c-f50d-46f9-a4b1-19e0e038db37'] = $pane;
  $display->panels['middle'][12] = 'new-9bebfe7c-f50d-46f9-a4b1-19e0e038db37';
  $pane = new stdClass();
  $pane->pid = 'new-51e1abbf-1d8a-4197-a320-9d3007e6b3ed';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_rsrch_course_summary';
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
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '51e1abbf-1d8a-4197-a320-9d3007e6b3ed';
  $display->content['new-51e1abbf-1d8a-4197-a320-9d3007e6b3ed'] = $pane;
  $display->panels['middle'][13] = 'new-51e1abbf-1d8a-4197-a320-9d3007e6b3ed';
  $pane = new stdClass();
  $pane->pid = 'new-facab3f9-3f7e-4fb0-b289-309bb44ba901';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_admissions_centre';
  $pane->shown = FALSE;
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = 'facab3f9-3f7e-4fb0-b289-309bb44ba901';
  $display->content['new-facab3f9-3f7e-4fb0-b289-309bb44ba901'] = $pane;
  $display->panels['middle'][14] = 'new-facab3f9-3f7e-4fb0-b289-309bb44ba901';
  $pane = new stdClass();
  $pane->pid = 'new-038bb894-4312-471f-bbad-7f7640a5d71f';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_hta_after_you_apply';
  $pane->shown = FALSE;
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = '038bb894-4312-471f-bbad-7f7640a5d71f';
  $display->content['new-038bb894-4312-471f-bbad-7f7640a5d71f'] = $pane;
  $display->panels['middle'][15] = 'new-038bb894-4312-471f-bbad-7f7640a5d71f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['vu_courses_hta'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'vu_courses_related';
  $mini->category = 'VicUni';
  $mini->admin_title = 'Courses: Related courses';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b911addc-0ae6-40cf-96ad-2440b3fb1691';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'vu_courses_related';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a8cac494-7476-4856-9ef7-1d260b355338';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-vu_courses_related-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a8cac494-7476-4856-9ef7-1d260b355338';
  $display->content['new-a8cac494-7476-4856-9ef7-1d260b355338'] = $pane;
  $display->panels['middle'][0] = 'new-a8cac494-7476-4856-9ef7-1d260b355338';
  $pane = new stdClass();
  $pane->pid = 'new-c37a59bc-a7b3-47ca-bad8-6024da0c0397';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'vu_core-vu_cbs_course_postgrad_more_text';
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
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c37a59bc-a7b3-47ca-bad8-6024da0c0397';
  $display->content['new-c37a59bc-a7b3-47ca-bad8-6024da0c0397'] = $pane;
  $display->panels['middle'][1] = 'new-c37a59bc-a7b3-47ca-bad8-6024da0c0397';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['vu_courses_related'] = $mini;

  return $export;
}
