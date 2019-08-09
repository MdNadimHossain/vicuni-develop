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
        <?php print render($content['field_page_introduction']); ?>
      </section>
      <?php if (!empty($domestic_href_switch) && !empty($international_href_switch)): ?>
        <section class="audience-tabs">
          <ul class="nav nav-tabs">
            <li <?php echo $international ? '' : 'class="active"'; ?>>
              <a class="search-navigation" href="<?php echo $domestic_href_switch; ?>">Information for
                <strong>Australian residents</strong></a>
            </li>
            <li <?php echo $international ? 'class="active"' : ''; ?>>
              <a class="search-navigation" href="<?php echo $international_href_switch; ?>">Information for
                <strong>International students</strong></a>
            </li>
          </ul>
        </section>
      <?php endif; ?>
      <?php if (isset($subpages)): ?>
        <section class="in-this-section">
          <h2>In '<?php echo $title ?>':</h2>
          <?php echo $subpages; ?>
        </section>
      <?php endif ?>
      <section class="on-this-page">
        <?php print render($content['field_on_this_page']); ?>
      </section>
      <section class="inner-content-top">
        <?php print render($inner_content_top); ?>
      </section>
      <section class="body">
        <?php print render($content['body']); ?>
        <?php print render($content); ?>
      </section>
      <section class="inner-content-bottom">
        <?php print render($inner_content_bottom); ?>
      </section>
    </div>
  </div>
</article>
