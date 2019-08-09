<?php

/**
 * @file
 * Course page nationally recognised training block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_course_nationally_recognised_info() {
  return [
    'info' => t('Course nationally recognised'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_course_nationally_recognised_view() {
  $node = _vu_core_block_menu_get_course_object();
  if (!$node) {
    return;
  }

  $is_tafe = $node->field_unit_lev[$node->language][0]['value'] == 'tafe';
  // This is based on the fact that at time of writing all TAFE courses that do
  // not have 'Victorian' in their title are Nationally Registered.
  $victorian = (FALSE !== strpos(strtolower($node->title), 'victorian'));

  $markup = '';

  if ($is_tafe && !$victorian) {
    $title = t('Nationally recognised training');
    $text = t('This course is nationally recognised training.');
    $markup = <<<END
    <div id="course-nrt" class="career-highlights">
      <div class="career-highlight">
        <h3>$title</h3>
        <img src="/profiles/vicuni/themes/custom/vu/images/nrt-logo.jpg"/>
        <p>$text</p>
      </div>
    </div>
END;

  }
  return [
    'subject' => NULL,
    'content' => $markup,
  ];
}
