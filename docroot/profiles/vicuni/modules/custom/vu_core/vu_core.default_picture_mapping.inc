<?php
/**
 * @file
 * vu_core.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function vu_core_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Background image';
  $picture_mapping->machine_name = 'background_image';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'custom.victory.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'background_image',
      ),
    ),
    'custom.victory.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'background_image_breakpoints_theme_victory_sm_1x',
      ),
    ),
    'custom.victory.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'background_image_breakpoints_theme_victory_md_1x',
      ),
    ),
    'custom.victory.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'background_image_breakpoints_theme_victory_lg_1x',
      ),
    ),
    'custom.victory.xl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'background_image_breakpoints_victory_custom_xl_1x',
      ),
    ),
    'custom.user.xxl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'background_image_breakpoints_theme_victory_xxl_1x',
      ),
    ),
    'custom.user.xxxl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'background_image_breakpoints_theme_victory_xxxl_1x',
      ),
    ),
  );
  $export['background_image'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Bootstrap 1 col';
  $picture_mapping->machine_name = 'bootstrap_1_col';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'breakpoints.theme.victory.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full_width_at_small_breakpoint',
      ),
    ),
    'breakpoints.theme.victory.sm' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.victory.md' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.victory.lg' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.victory.xl' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['bootstrap_1_col'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Bootstrap Column 12';
  $picture_mapping->machine_name = 'col_12';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'breakpoints.theme.victory.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_12',
      ),
    ),
    'breakpoints.theme.victory.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_12_breakpoints_theme_victory_sm_1x',
      ),
    ),
    'breakpoints.theme.victory.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_12_breakpoints_theme_victory_xl_1x',
      ),
    ),
    'breakpoints.theme.victory.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_12_breakpoints_theme_victory_xl_1x',
      ),
    ),
    'breakpoints.theme.victory.xl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_12_breakpoints_theme_victory_xl_1x',
      ),
    ),
  );
  $export['col_12'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'col 1 thumbnail';
  $picture_mapping->machine_name = 'col_3_thumbnail';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'breakpoints.theme.victory.xs' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.victory.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_3_thumbnail_breakpoints_theme_victory_sm_1x',
      ),
    ),
    'breakpoints.theme.victory.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_3_thumbnail_breakpoints_theme_victory_md_1x',
      ),
    ),
    'breakpoints.theme.victory.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_3_thumbnail_breakpoints_theme_victory_lg_1x',
      ),
    ),
    'breakpoints.theme.victory.xl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_3_thumbnail_breakpoints_theme_victory_xl_1x',
      ),
    ),
  );
  $export['col_3_thumbnail'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Bootstrap Column 4';
  $picture_mapping->machine_name = 'col_4';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'breakpoints.theme.victory.xs' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.victory.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_4_breakpoints_theme_victory_sm_1x',
      ),
    ),
    'breakpoints.theme.victory.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_4_breakpoints_theme_victory_md_1x',
      ),
    ),
    'breakpoints.theme.victory.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_4_breakpoints_theme_victory_lg_1x',
      ),
    ),
    'breakpoints.theme.victory.xl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'col_4_breakpoints_theme_victory_lg_1x',
      ),
    ),
  );
  $export['col_4'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Course banner image picture mapping';
  $picture_mapping->machine_name = 'course_banner_image_picture_mapping';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'breakpoints.theme.victory.xs' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.victory.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'course_banner_breakpoints_theme_victory_sm_1x',
      ),
    ),
    'breakpoints.theme.victory.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'course_banner_breakpoints_theme_victory_md_1x',
      ),
    ),
    'breakpoints.theme.victory.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'course_banner_breakpoints_theme_victory_lg_1x',
      ),
    ),
    'breakpoints.theme.victory.xl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'course_banner_breakpoints_theme_victory_lg_1x',
      ),
    ),
  );
  $export['course_banner_image_picture_mapping'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Large Logo';
  $picture_mapping->machine_name = 'large_logo';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'custom.victory.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_logo__350w',
      ),
    ),
    'custom.victory.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_logo__350w',
      ),
    ),
    'custom.victory.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_logo__350w',
      ),
    ),
    'custom.victory.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_logo__350w',
      ),
    ),
    'custom.victory.xl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_logo__350w',
      ),
    ),
    'custom.user.xxl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_logo__350w',
      ),
    ),
    'custom.user.xxxl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_logo__350w',
      ),
    ),
  );
  $export['large_logo'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Small Logo';
  $picture_mapping->machine_name = 'small_logo';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'custom.victory.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small_logo__150w',
      ),
    ),
    'custom.victory.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small_logo__150w',
      ),
    ),
    'custom.victory.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small_logo__150w',
      ),
    ),
    'custom.victory.lg' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.victory.xl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small_logo__150w',
      ),
    ),
    'custom.user.xxl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small_logo__150w',
      ),
    ),
    'custom.user.xxxl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'small_logo__150w',
      ),
    ),
  );
  $export['small_logo'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Success Story';
  $picture_mapping->machine_name = 'success_story';
  $picture_mapping->breakpoint_group = 'victory';
  $picture_mapping->mapping = array(
    'custom.victory.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'success_story',
      ),
    ),
    'custom.victory.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'success_story',
      ),
    ),
    'custom.victory.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'success_story_md',
      ),
    ),
    'custom.victory.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'success_story_md',
      ),
    ),
    'custom.victory.xl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'success_story_md',
      ),
    ),
    'custom.user.xxl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'success_story_md',
      ),
    ),
    'custom.user.xxxl' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'success_story_md',
      ),
    ),
  );
  $export['success_story'] = $picture_mapping;

  return $export;
}
