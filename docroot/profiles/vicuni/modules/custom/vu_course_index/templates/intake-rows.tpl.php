<?php
/**
 * @file
 * Generate VTAC table.
 */

$headers = array_keys(current($rows));
switch (count($headers)) {
  case 0:
    return;

  case 1:
    $heading = current($headers);
    $conj = ($heading === 'Fee type') ? '<p><b>OR</b>' : ', ';
    $content = implode($conj, array_filter(array_map('current', ($rows))));
    break;

  default:
    $heading = implode(', ', $headers);
    $last_comma = strrpos($heading, ',');
    if ($last_comma !== FALSE) {
      $heading = substr($heading, 0, $last_comma) . ' and' . substr($heading, $last_comma + 1);
    }
    $content = theme('table', array(
      'header' => $headers,
      'rows' => $rows,
      'attributes' => array('class' => array('course-essentials__item__table')),
    ));
}
echo theme('course-essentials-item', array(
  'label' => $heading,
  'value' => $content,
));
