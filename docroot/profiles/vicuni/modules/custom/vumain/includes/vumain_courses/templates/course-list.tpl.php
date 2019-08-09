<?php

/**
 * @file
 */
?>
<ul class="nav nav-tabs">
  <?php $i = 0;
  foreach (array_keys($lists) as $title): ?>
    <li<?php if (0 == $i++): ?> class="active"<?php endif ?>>
      <a href="#<?php echo $title ?>" data-toggle="tab">
        Courses for <strong><?php echo $title ?></strong>
      </a>
    </li>
  <?php endforeach ?>
</ul>

<div class="tab-content"><?php $i = 0;
  foreach ($lists as $title => $list): ?>
  <div class="tab-pane<?php if (0 == $i++): ?> active<?php endif ?>" id="<?php echo $title ?>">

    <ul class="nav nav-group-az nav-pills">
      <?php
      $letters = array_keys($list);

      // Split A-Z into chunks.
      $az = array_chunk(range('A', 'Z'), 4);

      // But combine last chunk of U-X, Y-Z.
      $az[count($az) - 2] = array_merge($az[count($az) - 2], array_pop($az));

      // Link to fragment in page.
      foreach ($az as $i => $group) :
        $anchor = $group[0];
        $j = 0;
        do {
          $anchor = $group[$j];
          $j++;
        } while (!in_array($anchor, $letters) && $j < count($group));
        $link_class = '';

        foreach ($group as $letter) {
          $link_class .= 'letter-' . strtolower($letter) . ' ';
        }
        ?>
        <li class="group-<?php echo ($i + 1); ?><?php echo $i == 0 ? ' active' : ''; ?>">
          <a data-toggle="group" class='<?php echo $link_class; ?>' href='#<?php echo $title ?>-course-starts-with-<?php echo strtolower($anchor); ?>'><?php echo ($group[0] . ' - ' . $group[count($group) - 1]); ?></a>
        </li>
      <?php endforeach; ?>
    </ul>
    <div class="course-list-wrapper">
      <?php foreach ($list as $letter => $rows): ?>
      <section class="course-list-group course-list-group-<?php echo strtolower($letter); ?>" id="course-list-group-<?php echo strtolower($letter); ?>">
        <h2 data-mobile-backtotop="true" data-neon-onthispage="false" id="<?php echo $title ?>-course-starts-with-<?php echo strtolower($letter); ?>"><?php echo $letter ?></h2>
        <ul>
          <?php foreach ($rows as $row): ?>
            <li>
              <a href="/<?php echo $row->url; ?>"><?php echo $row->highlighted_title ?></a>
              <?php
              if (!empty($row->firstoffered_year)) : ?>
                <span class='firstoffered firstoffered-<?php echo $row->firstoffered_year; ?>'>Entry in <?php echo $row->firstoffered_year; ?></span>
                <?php
              endif; ?>
            </li>
          <?php endforeach ?>
        </ul>
        </section><?php endforeach ?>
    </div>
    </div><?php endforeach ?>
</div>
