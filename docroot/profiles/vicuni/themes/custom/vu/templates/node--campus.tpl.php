<?php

/**
 * @file
 * The default template for the page builder content field.
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="row">
    <div class="col-md-12">
      <section class="introduction">
        <?php print render($content['field_introduction']); ?>
      </section>
      <?php if ($block_journey_planner): ?>
        <section class="journey-planner">
          <?php print $block_journey_planner; ?>
        </section>
      <?php endif; ?>
      <section class="googlemaps">
        <?php if ($gmap_block && $site_map_url): ?>
          <ul class="nav nav-tabs">
            <li class="active">
              <a href="#google-map" data-toggle="tab">Google Map</a></li>
            <li>
              <a href="#campus-map" data-toggle="tab"><?php print $map_title; ?></a>
            </li>
          </ul>
          <div class="tab-content">
            <div class="tab-pane active" id="google-map">
              <?php print $gmap_block; ?>
            </div>
            <div class="tab-pane" id="campus-map">
              <?php print "<img src='" . $site_map_url . "'>"; ?>
            </div>
          </div>
        <?php else: ?>
          <?php if ($gmap_block): ?>
            <div class="tab-pane active" id="google-map">
              <?php print $gmap_block; ?>
            </div>
          <?php endif; ?>
          <?php if ($site_map_url): ?>
            <div class="tab-pane active" id="campus-map">
              <?php print "<img src='" . $site_map_url . "'>"; ?>
            </div>
          <?php endif; ?>
        <?php endif; ?>
      </section>
      <section class="body">
        <?php
        hide($content['field_location']);
        hide($content['field_campus_image']);
        print render($content);
        ?>
      </section>
    </div>
  </div>
</article>
