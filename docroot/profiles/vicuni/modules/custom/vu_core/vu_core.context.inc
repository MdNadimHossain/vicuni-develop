<?php
/**
 * @file
 * vu_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vu_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'any_question_block_in_contact_us_page';
  $context->description = '';
  $context->tag = 'VicUni::Content_Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact-us' => 'contact-us',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vu_chat_now-vu_contact_us_any_questions' => array(
          'module' => 'vu_chat_now',
          'delta' => 'vu_contact_us_any_questions',
          'region' => 'featured_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Content_Blocks');
  $export['any_question_block_in_contact_us_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'feature_content_placement';
  $context->description = '';
  $context->tag = 'VicUni::Content_Blocks';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~any_question_block_in_contact_us_page' => '~any_question_block_in_contact_us_page',
        '~vu-content-blocks_ask_a_librarian_block_in_library_contacts_page' => '~vu-content-blocks_ask_a_librarian_block_in_library_contacts_page',
        '~vu-content_blocks-featured_content_blacklist' => '~vu-content_blocks-featured_content_blacklist',
        '~vu-content_blocks-convention_centre_contact' => '~vu-content_blocks-convention_centre_contact',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'future-students' => 'future-students',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vumain-featured_content' => array(
          'module' => 'vumain',
          'delta' => 'featured_content',
          'region' => 'featured_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Content_Blocks');
  $export['feature_content_placement'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'my_library_login_form';
  $context->description = 'My library login form.';
  $context->tag = 'VicUni::Content_Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'library/access-borrowing/my-library' => 'library/access-borrowing/my-library',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vumain-vumain_my_library_form' => array(
          'module' => 'vumain',
          'delta' => 'vumain_my_library_form',
          'region' => 'inner_content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('My library login form.');
  t('VicUni::Content_Blocks');
  $export['my_library_login_form'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-content-blocks_ask_a_librarian_block_in_library_contacts_page';
  $context->description = '';
  $context->tag = 'VicUni::Content_Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'library/get-help' => 'library/get-help',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vu_core-vu_library_ask_a_librarian' => array(
          'module' => 'vu_core',
          'delta' => 'vu_library_ask_a_librarian',
          'region' => 'featured_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Content_Blocks');
  $export['vu-content-blocks_ask_a_librarian_block_in_library_contacts_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-content_blocks-convention_centre_contact';
  $context->description = '';
  $context->tag = 'VicUni::Content_Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'convention-centres' => 'convention-centres',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vu_core-vu_convention_centre_contact' => array(
          'module' => 'vu_core',
          'delta' => 'vu_convention_centre_contact',
          'region' => 'featured_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Content_Blocks');
  $export['vu-content_blocks-convention_centre_contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-content_blocks-featured_content_blacklist';
  $context->description = 'A list of Content Types and specific pages that do not require featured content.';
  $context->tag = 'VicUni::Content_Blocks';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'courses' => 'courses',
        'events' => 'events',
        'news' => 'news',
        'staff_profile' => 'staff_profile',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'contact-us' => 'contact-us',
        'courses/how-to-apply/bachelor-degree-courses/vtac-applications' => 'courses/how-to-apply/bachelor-degree-courses/vtac-applications',
        'copyright-notice' => 'copyright-notice',
        'legal' => 'legal',
        'privacy' => 'privacy',
        'sitemap' => 'sitemap',
        'study-at-vu/courses/browse-study-areas/all-courses-a-to-z' => 'study-at-vu/courses/browse-study-areas/all-courses-a-to-z',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A list of Content Types and specific pages that do not require featured content.');
  t('VicUni::Content_Blocks');
  $export['vu-content_blocks-featured_content_blacklist'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-layout-global';
  $context->description = 'Global layout context.';
  $context->tag = 'VicUni::Layout';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'theme' => array(
      'values' => array(
        'vu' => 'vu',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-main-menu-level1' => array(
          'module' => 'menu_block',
          'delta' => 'main-menu-level1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'vumain-vumain_acknowledgement_country' => array(
          'module' => 'vumain',
          'delta' => 'vumain_acknowledgement_country',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'panels_mini-vu_block_upper_footer' => array(
          'module' => 'panels_mini',
          'delta' => 'vu_block_upper_footer',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'panels_mini-vu_block_lower_footer' => array(
          'module' => 'panels_mini',
          'delta' => 'vu_block_lower_footer',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'vu_core-vu_funnelback_search' => array(
          'module' => 'vu_core',
          'delta' => 'vu_funnelback_search',
          'region' => 'shutter',
          'weight' => '-9',
        ),
        'menu_block-main-menu-tools' => array(
          'module' => 'menu_block',
          'delta' => 'main-menu-tools',
          'region' => 'shutter',
          'weight' => '-8',
        ),
        'menu_block-main-menu-level2' => array(
          'module' => 'menu_block',
          'delta' => 'main-menu-level2',
          'region' => 'header_menu',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global layout context.');
  t('VicUni::Layout');
  $export['vu-layout-global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-layout-global-victory';
  $context->description = 'Global layout context (Victory theme)';
  $context->tag = 'VicUni::Layout';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'theme' => array(
      'values' => array(
        'victory' => 'victory',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'workbench-block' => array(
          'module' => 'workbench',
          'delta' => 'block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'panels_mini-vu_block_primary_menu' => array(
          'module' => 'panels_mini',
          'delta' => 'vu_block_primary_menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'vumain-vumain_acknowledgement_country' => array(
          'module' => 'vumain',
          'delta' => 'vumain_acknowledgement_country',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'panels_mini-vu_block_upper_footer' => array(
          'module' => 'panels_mini',
          'delta' => 'vu_block_upper_footer',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'panels_mini-vu_block_lower_footer' => array(
          'module' => 'panels_mini',
          'delta' => 'vu_block_lower_footer',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'menu_block-main-menu-tools' => array(
          'module' => 'menu_block',
          'delta' => 'main-menu-tools',
          'region' => 'shutter',
          'weight' => '-10',
        ),
        'vu_core-vu_funnelback_search' => array(
          'module' => 'vu_core',
          'delta' => 'vu_funnelback_search',
          'region' => 'shutter',
          'weight' => '-8',
        ),
        'ds_extras-title_area_course_information' => array(
          'module' => 'ds_extras',
          'delta' => 'title_area_course_information',
          'region' => 'title_box_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global layout context (Victory theme)');
  t('VicUni::Layout');
  $export['vu-layout-global-victory'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-navigation-campus_pages';
  $context->description = '';
  $context->tag = 'VicUni::Navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'campus' => 'campus',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-main-menu-our-campuses' => array(
          'module' => 'menu_block',
          'delta' => 'main-menu-our-campuses',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Navigation');
  $export['vu-navigation-campus_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-navigation-left_nav_main_menu';
  $context->description = 'Main menu left nav block.';
  $context->tag = 'VicUni::Navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'campus_housing' => 'campus_housing',
        'events' => 'events',
        'news' => 'news',
        'page_builder' => 'page_builder',
        'staff_profile' => 'staff_profile',
        'success_story' => 'success_story',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~research' => '~research',
        '~about-vu' => '~about-vu',
        '~industry' => '~industry',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-main-menu-left-nav' => array(
          'module' => 'menu_block',
          'delta' => 'main-menu-left-nav',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu left nav block.');
  t('VicUni::Navigation');
  $export['vu-navigation-left_nav_main_menu'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-navigation-left_nav_subsites';
  $context->description = 'Subsites menu left nav block.';
  $context->tag = 'VicUni::Navigation';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'campus_housing' => 'campus_housing',
        'events' => 'events',
        'page_builder' => 'page_builder',
        'success_story' => 'success_story',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-menu-subsites-left-nav' => array(
          'module' => 'menu_block',
          'delta' => 'menu-subsites-left-nav',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Subsites menu left nav block.');
  t('VicUni::Navigation');
  $export['vu-navigation-left_nav_subsites'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-navigation-on-page';
  $context->description = '';
  $context->tag = 'VicUni::Navigation';
  $context->conditions = array(
    'theme' => array(
      'values' => array(
        'victory' => 'victory',
      ),
    ),
    'context' => array(
      'values' => array(
        '~vu_courses' => '~vu_courses',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vu_core-vu_on_page_nav' => array(
          'module' => 'vu_core',
          'delta' => 'vu_on_page_nav',
          'region' => 'title_box_feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Navigation');
  $export['vu-navigation-on-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-page-vu_english';
  $context->description = '';
  $context->tag = 'VicUni::Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'vu-english' => 'vu-english',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-vu_english-our_students_block' => array(
          'module' => 'bean',
          'delta' => 'vu_english-our_students_block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Page');
  $export['vu-page-vu_english'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-page-vu_english-our_students';
  $context->description = '';
  $context->tag = 'VicUni::Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'vu-english/about-vu-english/our-students' => 'vu-english/about-vu-english/our-students',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-success_stories-block_4' => array(
          'module' => 'views',
          'delta' => 'success_stories-block_4',
          'region' => 'inner_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Page');
  $export['vu-page-vu_english-our_students'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-success_stories-employers_testimonials';
  $context->description = '';
  $context->tag = 'VicUni::Success_Stories';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'study-at-vu/success-stories/employer-testimonials' => 'study-at-vu/success-stories/employer-testimonials',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-success_stories-block_3' => array(
          'module' => 'views',
          'delta' => 'success_stories-block_3',
          'region' => 'inner_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Success_Stories');
  $export['vu-success_stories-employers_testimonials'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-success_stories-partners_and_projects';
  $context->description = '';
  $context->tag = 'VicUni::Success_Stories';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'study-at-vu/success-stories/partners-projects' => 'study-at-vu/success-stories/partners-projects',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-success_stories-block_2' => array(
          'module' => 'views',
          'delta' => 'success_stories-block_2',
          'region' => 'inner_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Success_Stories');
  $export['vu-success_stories-partners_and_projects'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-success_stories-staff';
  $context->description = '';
  $context->tag = 'VicUni::Success_Stories';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'study-at-vu/success-stories/staff-successes' => 'study-at-vu/success-stories/staff-successes',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-success_stories-block_1' => array(
          'module' => 'views',
          'delta' => 'success_stories-block_1',
          'region' => 'inner_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Success_Stories');
  $export['vu-success_stories-staff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu-success_stories-students_and_alumni';
  $context->description = '';
  $context->tag = 'VicUni::Success_Stories';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'study-at-vu/success-stories/students-alumni' => 'study-at-vu/success-stories/students-alumni',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-success_stories-block' => array(
          'module' => 'views',
          'delta' => 'success_stories-block',
          'region' => 'inner_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Success_Stories');
  $export['vu-success_stories-students_and_alumni'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu_course_search_facets_context';
  $context->description = 'Controls blocks in Course search page.';
  $context->tag = 'Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses/search' => 'courses/search',
      ),
    ),
    'query_string' => array(
      'values' => array(
        '~*vuit=1*' => '~*vuit=1*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-course_search' => array(
          'module' => 'current_search',
          'delta' => 'course_search',
          'region' => 'content',
          'weight' => '-73',
        ),
        'facetapi-JsMibik3AsNhra6N2CxxI0lGTlMkyGqs' => array(
          'module' => 'facetapi',
          'delta' => 'JsMibik3AsNhra6N2CxxI0lGTlMkyGqs',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-IA5mcSIsWs5DMsH4vZeq4jEyw7ZDV1Tc' => array(
          'module' => 'facetapi',
          'delta' => 'IA5mcSIsWs5DMsH4vZeq4jEyw7ZDV1Tc',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-Tbp5BL9nDwdi0rFLwc0lliAFPfk48bxx' => array(
          'module' => 'facetapi',
          'delta' => 'Tbp5BL9nDwdi0rFLwc0lliAFPfk48bxx',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-xJNVNXh0gHtViI7xJQw2jGrDxJkQ2xhg' => array(
          'module' => 'facetapi',
          'delta' => 'xJNVNXh0gHtViI7xJQw2jGrDxJkQ2xhg',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-AWbALQ1bDORjU4RTfNayojdl9guWb0kS' => array(
          'module' => 'facetapi',
          'delta' => 'AWbALQ1bDORjU4RTfNayojdl9guWb0kS',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Controls blocks in Course search page.');
  t('Search');
  $export['vu_course_search_facets_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu_course_search_resident_tabs_context';
  $context->description = 'Controls Resident/Non Resident tabs in Course search page.';
  $context->tag = 'Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'courses/search' => 'courses/search',
      ),
    ),
    'query_param' => array(
      'values' => array(
        'parameters' => 'a:1:{i:0;a:3:{s:4:"name";s:4:"type";s:8:"operator";s:10:"not_equals";s:5:"value";s:4:"Unit";}}',
        'require_all_params' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vu_core-vu_course_search_tabs' => array(
          'module' => 'vu_core',
          'delta' => 'vu_course_search_tabs',
          'region' => 'content',
          'weight' => '-77',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Controls Resident/Non Resident tabs in Course search page.');
  t('Search');
  $export['vu_course_search_resident_tabs_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu_courses';
  $context->description = '';
  $context->tag = 'VicUni::Courses';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'courses' => 'courses',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'courses/international/*' => 'courses/international/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vu_core-course_international_switcher' => array(
          'module' => 'vu_core',
          'delta' => 'course_international_switcher',
          'region' => 'below_header',
          'weight' => '-10',
        ),
        'vu_core-vu_on_page_nav' => array(
          'module' => 'vu_core',
          'delta' => 'vu_on_page_nav',
          'region' => 'below_header',
          'weight' => '-10',
        ),
        'ds_extras-course_essentials' => array(
          'module' => 'ds_extras',
          'delta' => 'course_essentials',
          'region' => 'below_header',
          'weight' => '-9',
        ),
        'vu_core-vu_cbs_hta_apply_cta' => array(
          'module' => 'vu_core',
          'delta' => 'vu_cbs_hta_apply_cta',
          'region' => 'below_header',
          'weight' => '-8',
        ),
        'ds_extras-courses_title_box_feature' => array(
          'module' => 'ds_extras',
          'delta' => 'courses_title_box_feature',
          'region' => 'title_box_feature',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Courses');
  $export['vu_courses'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu_expert_guide_context';
  $context->description = 'Controls blocks in Find media expert page.';
  $context->tag = 'Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about-vu/news-events/find-a-media-expert' => 'about-vu/news-events/find-a-media-expert',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vu_core-vu_core_expert_guide_search_form' => array(
          'module' => 'vu_core',
          'delta' => 'vu_core_expert_guide_search_form',
          'region' => 'inner_content_top',
          'weight' => '-10',
        ),
        'views-expert_guide-block' => array(
          'module' => 'views',
          'delta' => 'expert_guide-block',
          'region' => 'inner_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Controls blocks in Find media expert page.');
  t('Search');
  $export['vu_expert_guide_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vu_unit_unitsets';
  $context->description = '';
  $context->tag = 'VicUni::Courses';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'units/*' => 'units/*',
        'unitsets/*' => 'unitsets/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:node/10887696',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('VicUni::Courses');
  $export['vu_unit_unitsets'] = $context;

  return $export;
}
