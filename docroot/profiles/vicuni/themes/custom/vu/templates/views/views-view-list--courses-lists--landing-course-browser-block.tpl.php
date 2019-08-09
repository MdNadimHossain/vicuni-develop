<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 *
 * @ingroup views_templates
 */

$count = 1;
$totalrows = count($rows);

// Generate custom links for TAFE + English courses.
$tafe_local_link = l(t('TAFE'), '/courses/search', [
  'query' => [
    'iam' => 'resident',
    'type' => 'Course',
    'level' => [NULL => 'Vocational or Further Education'],
  ],
]);
$tafe_int_link = l(t('Technical and Further Education (TAFE)'), '/courses/search', [
  'query' => [
    'iam' => 'non-resident',
    'type' => 'Course',
    'level' => [NULL => 'Vocational or Further Education'],
  ],
]);
$eng_courses_link = l(t('English language courses'), '/vu-english/english-language-courses');

$current_path = drupal_get_path_alias();

// Assign custom links to appropriate topic page.
if ($current_path == 'future-students') {
  $rows[$totalrows] = $tafe_local_link;
}
if ($current_path == VUMAIN_URLS_INTERNATIONAL_STUDENTS) {
  $rows[$totalrows] = $tafe_int_link;
  $rows[$totalrows + 1] = $eng_courses_link;
}

$totalrows = count($rows);
$half = ceil($totalrows / 2);
?>

<?php print $wrapper_prefix; ?>

<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php print $list_type_prefix; ?>
<?php foreach ($rows as $id => $row): ?>
  <li class="<?php print isset($classes_array[$id]) ? $classes_array[$id] : ''; ?>"><?php print $row; ?></li>
  <?php if ($count == $half) {
    print $list_type_suffix;
    print $list_type_prefix;
  }
  $count++;
  ?>
<?php endforeach; ?>
<?php print $list_type_suffix; ?>

<?php print $wrapper_suffix; ?>
