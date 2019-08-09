<?php

/**
 * @file
 * Template for international ebrocure block on course pages.
 */
?>
<h3>Course e-Brochure</h3>
<p><?php print t('Create a customised brochure in a few simple steps. Your brochure will include country-specific information.'); ?></p>
<?php print t('<a href="@url" class="btn btn-secondary" role="button" target="_blank">Create an e-brochure</a>', ['@url' => $ebrochure_url]); ?>
