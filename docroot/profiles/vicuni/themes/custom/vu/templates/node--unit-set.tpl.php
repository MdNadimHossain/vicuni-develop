<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup templates
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="row">
    <div class="col-md-7">
      <div class="unitsets-content-wrapper">

        <div class="field-name-field-on-this-page-on-fly field field-name-field-on-this-page field-type-link-field field-label-above">
          <div class="field-label"><?php print t('On this page'); ?>:</div>
          <div class="field-items"></div>
        </div>

        <?php print render($content['body']); ?>
        <h2><?php print t('Unitset details'); ?></h2>
        <div class="unitsets-details">
          <?php
          // This code merges in imported locations that aren't able to be
          // stored in the entityreference type field. This can't live in the
          // precprocess hook becuase it merges pre and post process field
          // items.
          // Deal with case that only special locations exist for this node.
          if (!isset($content['field_locations']) && !empty($special_locations)) {
            $content['field_locations'] = $field_locations_base_render_array;
          }
          // Merge preprocessed special locations into the regular locations
          // entityreference field display.
          if (!empty($special_locations)) {
            $content['field_locations']['#items'] = array_merge($content['field_locations']['#items'], $special_locations);
            $content['field_locations'] = array_merge($content['field_locations'], $special_locations);
          }
          ?>
          <div class="unitsets-detail-item">
            <div class="course-essentials__item__label">
              <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-map-marker fa-stack-1x fa-inverse"></i></span><?php print t('Location:'); ?>
            </div>
            <div class="course-essentials__item__value">
              <?php print render($content['field_locations']); ?>
            </div>
          </div>

          <?php if (!empty($unit_level)): ?>
            <div class="unitsets-detail-item">
              <div class="course-essentials__item__label">
                <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-line-chart fa-stack-1x fa-inverse"></i></span><?php print t('Study level:'); ?>
              </div>
              <div class="course-essentials__item__value">
                <?php print $unit_level; ?>
              </div>
            </div>
          <?php endif; ?>

          <div class="unitsets-detail-item">
            <div class="course-essentials__item__label">
              <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-files-o fa-stack-1x fa-inverse"></i></span><?php print t('Unitset type:'); ?>
            </div>
            <div class="course-essentials__item__value">
              <?php print render($content['field_unit_s_type']); ?>
            </div>
          </div>
          <div class="unitsets-detail-item">
            <div class="course-essentials__item__label">
              <span class="fa-stack fa-fw"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-tag fa-stack-1x fa-inverse"></i></span><?php print t('Unitset code:'); ?>
            </div>
            <div class="course-essentials__item__value">
              <?php print render($content['field_unit_code']); ?>
            </div>
          </div>
        </div>

        <h2 id="goto-unitset-structure"><?php print t('Unitset Structure'); ?></h2>
        <div class="unitsets-structure">
          <?php print render($content['field_structure']); ?>
        </div>
        <?php
        // Hide comments, tags, and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_tags']);
        hide($content['field_college']);
        // Don't print original special locations field output.
        hide($content['field_locations_special']);
        hide($content['field_unit_lev']);
        hide($content['field_course_units']);
        print render($content);
        ?>
      </div>

      <div id="where-to-next">
        <h2 id="goto-where-to-next"><?php print t('Where to next?'); ?></h2>
        <p><?php print t('If you are interested in this unit as part of a course, refer to our <a href="/courses/applying/how-to-apply">how to apply page</a> to find out more about our application process.'); ?></p>
        <p><?php print t('If you are a current VU student, you may be able to enrol in this unitset as an elective.'); ?></p>
        <ul>
          <li><?php print t('Contact your course coordinator to see if you are able to take the elective unit set.'); ?></li>
        </ul>
        <h3><?php print t('You can also contact us directly:'); ?></h3>
        <ul>
          <li><?php print t('Ring us on <strong>+61 3 9919 6100</strong>'); ?></li>
          <li><?php print t('Find answers and ask questions at <a href="/gotovu?r=cst">GOTOVU</a>'); ?></li>
        </ul>
        <p>
          <small><?php print t('VU takes care to ensure the accuracy of this unit information, but reserves the right to change or withdraw courses offered at any time. Please check that unit information is current with the <a href="/contact-us">Student Contact Centre</a>.'); ?></small>
        </p>
      </div>
    </div>
    <div class="col-md-5 unitsets-rightside">
      <div class="aside-cta-head">
        <span class="fa-stack">
          <i class="fa fa-circle fa-stack-2x"></i>
          <i class="fa fa-pencil fa-stack-1x fa-inverse"></i>
        </span>
        <h2><a href="#where-to-next"><?php print t('How to apply'); ?></a></h2>
      </div>
      <div class="aside-cta-box">
        <h3><?php print t('Already a VU student?'); ?></h3>
        <p><?php print t('You may be able to enrol in this unitset as an elective.'); ?></p>
        <p><?php print t('Contact your course coordinator to see if you are able to take the elective unitset.'); ?></p>
      </div>
      <div class="aside-cta-box">
        <p>
          <a href="#where-to-next"><strong><?php print t('More on applying for this unitset'); ?></strong></a>
        </p>
      </div>
      <?php print $courses_this_unit_belongs_to; ?>
    </div>
  </div>
</article>
