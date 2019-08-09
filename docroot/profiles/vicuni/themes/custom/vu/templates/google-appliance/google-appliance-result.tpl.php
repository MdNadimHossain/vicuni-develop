<?php

/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * google-applinace-results.tpl.php. This and the parent template are
 * dependent on one another sharing the markup for results listings.
 *
 * Result items that are files (pdf and whatnot) can be decorated with file
 * icons as we use theme_file_icon in
 * template_preprocess_google_appliance_result(). Copy this template to your
 * theme directory and use code like the following to display an icon for
 * each result if it has an iconable mime type:
 * @code
 *    <?php print (isset($mime['icon'])) ? $mime['icon'] : ''; ?>
 * @endcode
 *
 * Metadata for each result is also available to be themed, but is not part of
 * the default implementation here. Have a look at $variables['meta'] to see
 * what data you have available.
 *
 * @see template_preprocess_google_appliance_result()
 * @see google-appliance-results.tpl.php
 */
?>
<?php if (!empty($title) && !empty($abs_url)): ?>
  <li>
    <h3>
      <a href="<?php print $abs_url; ?>" class="noext <?php print !empty($file_mime) ? $file_mime : ''; ?>">
        <?php if (!empty($file_mime)): ?>
          <span class="mime">[<?php echo $file_mime; ?>]</span> <?php
        endif; ?>
        <?php print $title; ?>
      </a>
    </h3>
    <div class="url"><?php echo $display_url ? $display_url : $abs_url; ?></div>
    <?php if (!empty($snippet)): ?>
      <div class="snippet">
        <?php if (!empty($meta['publication_date'])): ?>
          <span class="pub-date"><?php print format_date(strtotime($meta['publication_date']), 'custom', 'j M Y'); ?> &ndash;</span>
        <?php endif ?>
        <?php print $snippet; ?>
      </div>
    <?php endif ?>
  </li>
<?php endif; ?>
