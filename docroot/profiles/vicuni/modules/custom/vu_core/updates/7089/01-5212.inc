<?php

/**
 * @file
 * PW-5212 - Add a new Free TAFE 2019 bean.
 */

$beans['free-tafe-2019'] = [
  'type' => 'promo',
  'label' => 'Free TAFE 2019',
  'fields' => [
    'title_field' => [
      LANGUAGE_NONE => [['value' => 'Free TAFE 2019']],
      'en' => [['value' => 'Free TAFE 2019']],
    ],
    'field_promo_text' => [
      LANGUAGE_NONE => [
        [
          'value' => 'Get work ready with VU Polytechnic\'s award-winning blended learning and don\'t pay tuition under the government\'s \'Free TAFE\' initiative. Free TAFE is an affordable training opportunity for courses leading to priority occupations.',
        ],
      ],
    ],
    'field_promo_link' => [
      LANGUAGE_NONE => [
        [
          'url' => 'https://www.vupolytechnic.edu.au/free-tafe',
          'title' => 'Find a Free TAFE course',
        ],
        [
          'url' => 'https://www.vupolytechnic.edu.au/',
          'title' => 'Browse all TAFE courses',
        ],
      ],
    ],
    'field_promo_brand' => [LANGUAGE_NONE => [['value' => 'vicpoly']]],
  ],
];

// Create Beans.
foreach ($beans as $delta => $item) {
  $bean = bean_create(['type' => $item['type']]);
  $bean->label = $item['label'];
  if (isset($item['title'])) {
    $bean->title = $item['title'];
  }
  $bean->delta = $delta;
  foreach ($item['fields'] as $name => $value) {
    $bean->{$name} = $value;
  }
  $bean->save();
  $beans[$delta] = $bean->bid;
}
