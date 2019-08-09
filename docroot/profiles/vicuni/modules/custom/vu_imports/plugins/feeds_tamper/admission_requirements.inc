<?php

/**
 * @file
 * Feeds Tamper process definitions.
 */

/**
 * The plugin definition.
 */
$plugin = [
  'form'     => 'vu_imports_admission_requirements_form',
  'callback' => 'vu_imports_admission_requirements_callback',
  'name'     => 'Parse admission requirements xml nodes into one html string',
  'multi'    => 'direct',
  'category' => 'VU imports',
];

/**
 * Feeds tamper options form callback.
 */
function vu_imports_admission_requirements_form($importer, $element_key, $settings) {
  $form = [];
  $form['help'] = [
    '#markup' => "
      <p>
      There are no settings for this feed tamper. See vu_imports_admission_requirements_callback() to extend.
      </p>",
  ];
  return $form;
}

/**
 * Callback for array_map().
 */
function _vu_imports_trim_and_remove_na_callback($requirements) {
  return trim(str_replace('N/A', '', $requirements));
}

/**
 * Parses all admission requirements xml nodes into one html string.
 */
function vu_imports_admission_requirements_callback($source, $item_key, $element_key, &$field, $settings) {
  // Parse contents of the admissionrequirements xml nodes into
  // html suitable for easy storage and performant display.
  $requirements = array_filter(
    array_map(
      '_vu_imports_trim_and_remove_na_callback', [
        'TAFE'                    => $source->current_item['admissionrequirementsvet'],
        'Year 12'                 => $source->current_item['admissionrequirementsseniorsecondary'],
        'Mature'                  => $source->current_item['admissionrequirementsmatureage'],
        'Other'                   => $source->current_item['admissionrequirementsother'],
      ]
    )
  );

  // Don't have an empty list.
  if (empty($requirements)) {
    return;
  }

  // Check if all requirements other than 'Other' were empty
  // and stripped by array_filter().
  if (count($requirements) === 1 && isset($requirements['Other'])) {
    // Return the value with no label.
    $field = $requirements['Other'];
    return;
  }

  // If at least one additional requirement is present markup
  // a list of requirements with labels.
  $html = '<ul>';
  foreach ($requirements as $label => $value) {
    if ($value) {
      $html .= '<li>' . $label . ': ' . $value . '</li>';
    }
  }
  $html .= '</ul>';
  $field = $html;
}
