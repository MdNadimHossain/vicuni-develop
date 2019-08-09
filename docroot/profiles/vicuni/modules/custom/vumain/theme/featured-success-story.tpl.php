<?php
/**
 * @file
 * Contains featured success story template.
 */
?>
<?php if (isset($image) && isset($testimony) && isset($node_link) && isset($person_name)): ?>
  <section class="featured-success-story">
    <?php print $image ?>
    <div class="testimonial-box">
      <blockquote>
        <div>
          <?php print $testimony; ?>
        </div>
        <cite><a href="/<?php print $node_link; ?>"><?php print $person_name; ?></a></cite>
      </blockquote>
    </div>
  </section>
<?php endif;
