<?php

/**
 * @file
 * Display Suite module integration.
 */

/**
 * Implements hook_ds_layout_info().
 */
function vu_core_ds_layout_info() {
  $path = drupal_get_path('module', 'vu_core');

  $layouts['bootstrap_9_3_stacked'] = [
    'label' => t('VU: Bootstrap 9/3 stacked'),
    'path' => $path . '/layouts/bootstrap_9_3_stacked',
    'regions' => [
      'top' => t('Top'),
      'left' => t('Left'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ],
  ];

  $layouts['vu_page_section_single_column'] = [
    'label' => t('VU: Page section single column'),
    'path' => $path . '/layouts/vu_page_section_single_column',
    'regions' => [
      'top' => t('Top'),
      'middle' => t('Middle'),
      'bottom' => t('Bottom'),
    ],
  ];

  $layouts['bootstrap_accordion'] = [
    'label' => t('VU: Bootstrap accordion'),
    'path' => $path . '/layouts/bootstrap_accordion',
    'regions' => [
      'title' => t('Title'),
      'ds_content' => t('Content'),
    ],
  ];

  $layouts['hero_banner'] = [
    'label' => t('VU: Hero banner'),
    'path' => $path . '/layouts/hero_banner',
    'regions' => [
      'ds_content' => t('Content'),
      'ds_image' => t('Image'),
    ],
  ];

  $layouts['vu_course'] = [
    'label' => t('VU: Course'),
    'path' => $path . '/layouts/vu_course',
    'regions' => [
      'introduction' => t('Introduction'),
      'overview_right' => t('Overview right'),
      'overview_right_lower_middle' => t('Overview Right Lower Middle'),
      'tafe_resources_block' => t('TAFE resources'),
      'ds_content' => t('Content'),
      'careers' => t('Careers'),
      'careers_right' => t('Careers right'),
      'first_year_model_info' => t('First year model info'),
      'fees_scholarships' => t('Fees and scholarships'),
      'admission_pathways' => t('Admission and pathways'),
      'pathways_credits' => t('Pathways and Credits'),
      'how_to_apply' => t('How to apply (raw)'),
      'bottom' => t('Bottom'),
      'admission_pathways_right' => t('Admission and Pathways RHS'),
      'fees_scholarships_right' => t('Fees and scholarships Right'),
    ],
  ];

  $layouts['vu_unit'] = [
    'label' => t('VU: Unit'),
    'path' => $path . '/layouts/vu_unit',
    'regions' => [
      'ds_content' => t('Overview'),
      'overview_rhs' => t('Overview - RHS'),
      'details' => t('Details'),
      'learning' => t('Learning Outcomes'),
      'assessment' => t('Assessment'),
      'reading' => t('Required reading'),
    ],
  ];

  $layouts['vu_unitsets'] = [
    'label' => t('VU: Unitsets'),
    'path' => $path . '/layouts/vu_unitsets',
    'regions' => [
      'ds_content' => t('Overview'),
      'overview_rhs' => t('Overview - RHS'),
      'details' => t('Details'),
      'structure' => t('Unitset structure'),
    ],
  ];

  $layouts['vu_promo'] = [
    'label' => t('VU: Promo'),
    'path' => $path . '/layouts/vu_promo',
    'regions' => [
      'ds_content' => t('Content'),
    ],
  ];

  $layouts['vu_staff_profile'] = [
    'label' => t('VU: Staff Profile'),
    'path' => $path . '/layouts/vu_staff_profile',
    'regions' => [
      'left' => t('Left'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ],
  ];

  return $layouts;
}
