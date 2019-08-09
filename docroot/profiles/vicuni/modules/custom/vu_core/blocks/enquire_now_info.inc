<?php

/**
 * @file
 * Enquire now block.
 */

/**
 * Implements hook_block_DELTA_info().
 */
function vu_core_block_enquire_now_info_info() {
  return [
    'info' => t('Enquire now information'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  ];
}

/**
 * Implements hook_block_DELTA_view().
 */
function vu_core_block_enquire_now_info_view() {
  $node = _vu_core_block_menu_get_course_object(TRUE, FALSE, FALSE);
  if (!$node) {
    return;
  }
  $college = field_get_items('node', $node, 'field_college');
  $course_aqf = field_get_items('node', $node, 'field_course_aqf');
  $unit_lev = field_get_items('node', $node, 'field_unit_lev');
  $is_vicpoly = in_array($college[0]['title'], ['VU Polytechnic', 'Victoria Polytechnic']);
  $is_vu_research = !$is_vicpoly && strtolower($college[0]['title']) == 'vu research';

  $is_pgr = FALSE;
  if ($course_aqf) {
    $is_pgr = (bool) preg_match('/Doctoral|Research/', $course_aqf[0]['safe_value']);
  }
  elseif ($unit_lev) {
    $is_pgr = in_array($unit_lev[0]['value'], ['postgrad', 'postgrad_research']);
  }

  // Is this course open for enrolments?
  $course_code = vu_core_extract_single_field_value($node, 'node', 'field_unit_code');
  $delivery = vu_course_index_get_course_intake_list($course_code);
  $is_open = $delivery->isOpen();

  // Default.
  $class = 'default';
  $title = t('Contact us');
  $items[] = [
    'data' => t('Visit a <a href="!link">student service centre</a>', ['!link' => url('contact-us/vuhq-student-service-centres')]),
    'class' => 'enquire-now-info__link',
  ];
  $items[] = [
    'data' => l(t('1300 VIC UNI (1300 842 864)'), 'tel:1300842864'),
    'class' => 'enquire-now-info__phone',
  ];
  if ($is_open) {
    $items[] = [
      'data' => l(t('Request a call back'), 'http://study.vu.edu.au/requestcallback', ['absolute' => TRUE, 'query' => ['course' => $course_code]]),
      'class' => 'enquire-now-info__phone',
    ];
  }
  $items[] = [
    'data' => l(t('Chat with us online'), 'https://gotovu.custhelp.com/app/home?initchat=true'),
    'class' => 'enquire-now-info__contact',
  ];
  $items[] = [
    'data' => t('Ask questions at <a href="!link">GOTOVU</a>', ['!link' => url('http://www.vu.edu.au/gotovu?r=cst')]),
    'class' => 'enquire-now-info__ask',
  ];

  // Tafe.
  if ($is_vicpoly) {
    $class = 'tafe';
    $title = t('Contact VU Polytechnic');
    $items = [
      [
        'data' => l(t('1300 TAFE VP (1300 823 387)'), 'tel:1300823387'),
        'class' => 'enquire-now-info__phone',
      ],
      [
        'data' => l(t('Find answers or chat online'), 'http://www.vu.edu.au/gotovu?r=cst'),
        'class' => 'enquire-now-info__contact',
      ],
    ];
  }

  // Graduate research.
  elseif (($node->type !== 'unit' && $is_pgr) || ($node->type === 'unit' && $is_vu_research)) {
    $class = 'pgr';
    $title = t('Contact the Office for Researcher Training, Quality & Integrity');
    $items = [
      [
        'data' => l(t('Office for Researcher Training, Quality & Integrity'), '/researchers/research-contacts-support/office-for-researcher-training-quality-integrity'),
        'class' => 'enquire-now-info__link',
      ],
      [
        'data' => l(t('+61 3 9919 4522'), 'tel:+61399194522'),
        'class' => 'enquire-now-info__phone',
      ],
      [
        'data' => l(t('apply.research@vu.edu.au'), 'mailto:apply.research@vu.edu.au'),
        'class' => 'enquire-now-info__contact',
      ],
    ];
  }

  $items = theme('item_list', [
    'title' => $title,
    'type' => 'ul',
    'items' => $items,
    'attributes' => ['class' => 'enquire-now-info'],
  ]);

  return [
    'subject' => NULL,
    'content' => "<div class='enquire-now-info-block enquire-now-info-block__{$class}'>" . $items . '</div>',
  ];
}
