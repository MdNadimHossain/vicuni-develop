<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$total_row = count($rows);
$i = 1;
?>
<div class="unit-course-list">
  <?php print $title; ?>&nbsp;
  (<?php
  foreach ($rows as $id => $row) {
    print l($view->result[$id]->node_title, 'node/' . $view->result[$id]->nid);
    if ($i < $total_row) {
      print ', ';
    }
    $i++;
  }
  ?>)
</div>
