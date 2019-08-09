<?php

/**
 * @file
 * Styleguide module integration.
 */

/**
 * Implements hook_styleguide().
 */
function vu_core_styleguide() {
  $items['victory_paragraph'] = [
    'title' => t('Paragraph'),
    'group' => t('Victory'),
    'content' => styleguide_paragraph(1),
  ];

  $items['victory_paragraph_lead'] = [
    'title' => t('Lead paragraph'),
    'group' => t('Victory'),
    'content' => '<p class="paragraph--lead">' . styleguide_lorem(1, 0, 'mixed', TRUE, TRUE, TRUE)[0] . '</p>',
  ];

  // Build nested list items.
  $list_items = styleguide_list(3);
  $list_items[1] = [
    'data' => $list_items[1],
    'children' => styleguide_list(3),
  ];
  $list_items[1]['children'][1] = [
    'data' => $list_items[1]['children'][1],
    'children' => styleguide_list(2),
  ];

  $items['victory_list_unordered'] = [
    'title' => t('Unordered list + sub bullets'),
    'group' => t('Victory'),
    'theme' => 'item_list',
    'variables' => ['items' => $list_items, 'type' => 'ul'],
  ];

  $items['victory_list_ordered'] = [
    'title' => t('Ordered list + sub bullets'),
    'group' => t('Victory'),
    'theme' => 'item_list',
    'variables' => ['items' => $list_items, 'type' => 'ol'],
  ];

  $items['victory_button_primary'] = [
    'title' => t('Button'),
    'group' => t('Victory'),
    'theme' => 'link',
    'variables' => [
      'text' => styleguide_word(2),
      'path' => request_uri(),
      'options' => ['attributes' => ['class' => 'button--primary', 'role' => 'button']],
    ],
  ];

  $items['victory_link_internal'] = [
    'title' => t('Link - Internal'),
    'group' => t('Victory'),
    'theme' => 'link',
    'variables' => [
      'text' => styleguide_word(2),
      'path' => request_uri(),
      'options' => ['attributes' => []],
    ],
  ];

  $items['victory_link_external'] = [
    'title' => t('Link - External'),
    'group' => t('Victory'),
    'theme' => 'link',
    'variables' => [
      'text' => styleguide_word(2),
      'path' => 'http://example.com',
      'options' => ['attributes' => []],
    ],
  ];

  $fid = db_select('file_managed', 'f')
    ->condition('f.type', 'document')
    ->fields('f', ['fid'])
    ->range(0, 1)
    ->orderRandom()
    ->execute()
    ->fetchColumn();
  $items['victory_link_download'] = [
    'title' => t('Link - Download'),
    'group' => t('Victory'),
    'content' => media_wysiwyg_token_to_markup(['[[{"fid":"' . $fid . '","view_mode":"default"}]]']),
  ];

  $items['victory_quote'] = [
    'title' => t('Block Quote'),
    'group' => t('Victory'),
    'content' => '<blockquote><p><em>' . styleguide_paragraph(1) . '</em></p><p><strong>&mdash; ' . styleguide_word(2) . '</strong> ' . styleguide_word(5) . '.</p></blockquote>',
  ];

  $items['victory_code'] = [
    'title' => t('Example (Code)'),
    'group' => t('Victory'),
    'content' => '<code>' . styleguide_paragraph(2) . '</code>',
  ];

  $content = '';
  for ($i = 3; $i <= 5; $i++) {
    $content .= "<h{$i}>h{$i}: " . implode(' ', styleguide_list()) . "</h{$i}>";
  }
  $items['victory_headings'] = [
    'title' => t('H3 - H5'),
    'group' => t('Victory'),
    'content' => $content,
  ];

  $items['victory_small'] = [
    'title' => t('Small text'),
    'group' => t('Victory'),
    'content' => '<small>' . styleguide_lorem(1) . '</small>',
  ];

  $items['victory_strong'] = [
    'title' => t('Strong text'),
    'group' => t('Victory'),
    'content' => '<strong>' . styleguide_lorem(1) . '</strong>',
  ];

  $items['victory_em'] = [
    'title' => t('Em text'),
    'group' => t('Victory'),
    'content' => '<em>' . styleguide_lorem(1) . '</em>',
  ];

  $items['victory_hr'] = [
    'title' => t('HR'),
    'group' => t('Victory'),
    'content' => styleguide_paragraph(1) . '<hr>' . styleguide_paragraph(1),
  ];

  $items['victory_sub'] = [
    'title' => t('Subscript'),
    'group' => t('Victory'),
    'content' => styleguide_word(3, 'ucfirst') . ' <sub>' . styleguide_word(1) . '</sub> ' . styleguide_word(4) . '.',
  ];

  $items['victory_sup'] = [
    'title' => t('Superscript'),
    'group' => t('Victory'),
    'content' => styleguide_word(3, 'ucfirst') . ' <sup>' . styleguide_word(1) . '</sup> ' . styleguide_word(4) . '.',
  ];

  // Course search form.
  $block = block_load('vu_core', 'vu_course_search');
  $render_array = _block_get_renderable_array(_block_render_blocks([$block]));
  $output = render($render_array);
  $items['victory_course_search'] = [
    'title' => t('Course search form'),
    'group' => t('Victory'),
    'content' => $output,
  ];

  // Tables.
  // Basic table with a header.
  $content = '';
  $header = styleguide_header(3);
  $rows = styleguide_rows(3);
  $content .= theme('table', ['header' => $header, 'rows' => $rows]);

  // Table without a header.
  $content .= theme('table', ['rows' => $rows]);

  // Rows with a header column.
  $rows_with_header = [];
  for ($i = 1; $i <= 3; $i++) {
    $rows_with_header[] = [
      [
        'data' => styleguide_word(3, 'ucfirst'),
        'scope' => 'row',
        'header' => TRUE,
      ],
      styleguide_word(3, 'ucfirst'),
      styleguide_word(3, 'ucfirst'),
    ];
  }
  $header[0] = ['data' => styleguide_word(3, 'ucfirst'), 'scope' => 'row'];
  $content .= theme('table', [
    'header' => $header,
    'rows' => $rows_with_header,
  ]);

  $items['victory_table'] = [
    'title' => t('Table'),
    'group' => t('Victory'),
    'content' => $content,
  ];

  $fid = db_select('file_managed', 'f')
    ->condition('f.type', 'video')
    ->fields('f', ['fid'])
    ->range(0, 1)
    ->orderRandom()
    ->execute()
    ->fetchColumn();
  $items['victory_video'] = [
    'title' => t('Video'),
    'group' => t('Victory'),
    'content' => media_wysiwyg_token_to_markup(['[[{"fid":"' . $fid . '","view_mode":"default"}]]']),
  ];

  $fid = db_select('file_managed', 'f')
    ->condition('f.type', 'image')
    ->fields('f', ['fid'])
    ->range(0, 1)
    ->orderRandom()
    ->execute()
    ->fetchColumn();
  $items['victory_image'] = [
    'title' => t('Image'),
    'group' => t('Victory'),
    'content' => media_wysiwyg_token_to_markup(['[[{"fid":"' . $fid . '","view_mode":"default"}]]']),
  ];

  // Supplementary Image.
  $fid = db_select('file_managed', 'f')
    ->condition('f.type', 'image')
    ->fields('f', ['fid'])
    ->range(0, 1)
    ->orderBy('f.filesize', 'DESC')
    ->orderRandom()
    ->execute()
    ->fetchColumn();

  $file = file_load($fid);
  $element = file_view_file($file);

  $picture_mapping = picture_mapping_load('col_4');
  $fallback_image_style = 'col_4';
  $breakpoint_styles = picture_get_mapping_breakpoints($picture_mapping, $fallback_image_style);

  $element['#theme'] = 'picture_formatter';
  $element['#breakpoints'] = $breakpoint_styles;
  $element['#image_style'] = 'col_4';

  $image = t('<div class="field-name-field-image">!image</div>', ['!image' => render($element)]);
  $caption = t('<div class="field-name-field-body">!caption</div>', ['!caption' => styleguide_paragraph(1)]);

  $items['victory_rhs_static_image'] = [
    'title' => t('Supplementary Image'),
    'group' => t('Victory'),
    'content' => '<div class="row"><div class="paragraphs-item-image"><div class="col-sm-4">' . $image . $caption . '</div></div></div>',
  ];

  $accordion_items = [];
  for ($i = 0; $i < 5; $i++) {
    $accordion_items[] = [
      '#theme' => 'bootstrap_accordion',
      '#accordion_id' => $i,
      '#ds_content' => styleguide_paragraph(1),
      '#title' => styleguide_word(3, 'ucfirst'),
    ];
  }
  $items['victory_accordion'] = [
    'title' => t('Accordion'),
    'group' => t('Victory'),
    'content' => render($accordion_items),
  ];

  return $items;
}

/**
 * Implements hook_styleguide_alter().
 */
function vu_core_styleguide_alter(&$items) {
  // Limit items as some trigger JS errors.
  foreach ($items as $name => $item) {
    if (isset($item['group']) && !in_array($item['group'], [t('Comment'), t('Victory')])) {
      unset($items[$name]);
    }
  }
}
