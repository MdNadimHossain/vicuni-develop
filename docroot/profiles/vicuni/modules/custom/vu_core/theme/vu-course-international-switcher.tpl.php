<?php

/**
 * @file
 * Template file for 'International Switcher' block.
 */
?>
<div class="container">
  <div class="international-switcher-container">
    <div class="international-switcher-content">
      <div class="course-link">
        <?php if ($international_has_dom): ?>
          <?php if ($is_vu_sydney): ?>
            <div class="residents sydney-course non-active">
              <div class="international-switcher-icon"><div class="australia"></div></div>
              <?php print t('<a href="@href">Australian residents</a>', ['@href' => "/courses/${code}?uc"]) ?>
            </div>
            <div class="non-residents sydney-course active">
              <div class="international-switcher-icon"><i class="fa fa-globe" aria-hidden="true"></i></div>
              <div class="sydney-link">
                <span class="link-1"><?php print t('<a href="@href">International students (Melbourne)</a>', ['@href' => "/courses/international/${code}"]); ?></span>
                <span class="link-2"><?php print t('<a href="@href">VU Sydney information</a>', ['@href' => "/vu-sydney/courses-at-vu-sydney"]); ?></span>
              </div>
            </div>
            <a href="#OPEN-MODAL" tabindex="0" role="button" class="sydney-course js-aud-btn-modal fa fa-question-circle"></a>
          <?php else : ?>
            <div class="residents non-active">
              <div class="international-switcher-icon"><div class="australia"></div></div>
              <?php print t('<a href="@href">Australian residents</a>', ['@href' => "/courses/${code}?uc"]) ?>
            </div>
            <div class="non-residents active">
              <div class="international-switcher-icon"><i class="fa fa-globe" aria-hidden="true"></i></div>
              <?php print t('<a href="@href">International students</a>', ['@href' => "/courses/international/${code}"]); ?>
            </div>
            <a href="#OPEN-MODAL" tabindex="0" role="button" class="js-aud-btn-modal fa fa-question-circle"></a>
          <?php endif; ?>
        <?php elseif ($international_only): ?>
          <div class="one-version-only">
            <div class="international-switcher-icon"><i class="fa fa-globe" aria-hidden="true"></i></div>
            <div class="inner-text-1">
              <?php print t('Information on this page is for <span class="audience-name">international students'); ?>
              <a href="#OPEN-MODAL" tabindex="0" role="button" class="js-aud-btn-modal fa fa-question-circle"></a>
              <?php print t('</span>'); ?>
              <div class="inner-text-2"><?php print t('Course not available to Australian residents'); ?></div>
            </div>
          </div>
        <?php elseif ($domestic_has_int): ?>
          <div class="residents active">
            <div class="international-switcher-icon"><div class="australia-active"></div></div>
            <?php print t('<a href="@href">Australian residents</a>', ['@href' => "/courses/${code}?uc"]) ?>
          </div>
          <div class="non-residents non-active">
            <div class="international-switcher-icon"><i class="fa fa-globe" aria-hidden="true"></i></div>
            <?php print t('<a href="@href">International students</a>', ['@href' => "/courses/international/${code}"]); ?>
          </div>
          <a href="#OPEN-MODAL" tabindex="0" role="button" class="js-aud-btn-modal fa fa-question-circle"></a>
        <?php elseif ($domestic_only): ?>
          <div class="one-version-only">
            <div class="international-switcher-icon"><div class="australia"></div></div>
            <div class="inner-text-1">
              <?php print t('Information on this page is for <span class="audience-name">Australian residents'); ?>
              <a href="#OPEN-MODAL" tabindex="0" role="button" class="js-aud-btn-modal fa fa-question-circle"></a>
              <?php print t('</span>'); ?>
              <div class="inner-text-2"><?php print t('Course not available to international students'); ?></div>
            </div>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
<div class="modal fade" id="audience-switcher-modal" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close" ></button>
        <?php if ($domestic_only) : ?>
          <h3><?php print t('This course is only available to Australian residents') ?></h3>
          <?php print theme('vu_course_switcher_domestic_info') ?>
          <?php print theme('vu_course_switcher_international_info') ?>
        <?php elseif ($international_only) : ?>
          <h3><?php print t('This course is only available to international students') ?></h3>
          <?php print theme('vu_course_switcher_international_info') ?>
          <?php print theme('vu_course_switcher_domestic_info') ?>
        <?php else : ?>
          <h3><?php print t('Which course details are right for you?') ?></h3>
          <?php print theme('vu_course_switcher_domestic_info') ?>
          <?php print theme('vu_course_switcher_international_info') ?>
          <h3><?php print t('Show course details for:') ?></h3>
          <div class="switcher-buttons">
            <?php if (!$is_international_url) : ?>
              <button data-dismiss="modal" id="res-btn-modal" class="btn btn-primary" role="link">
                <div class="international-switcher-icon"><div class="australia-active"></div></div>
                <div class=button-text>Australian residents</div>
              </button>
            <?php else : ?>
              <a href="/courses/<?php print $code ?>" id="res-btn-modal" class="btn btn-primary">
                <div class="international-switcher-icon"><div class="australia-active"></div></div>
                <div class=button-text>Australian residents</div>
              </a>
            <?php endif; ?>
            <?php if ($is_international_url) : ?>
              <button data-dismiss="modal" id="res-btn-modal" class="btn btn-primary" role="link">
                <div class="international-switcher-icon"><i class="fa fa-globe" aria-hidden="true"></i></div>
                <div class=button-text>International students</div>
              </button>
            <?php else : ?>
              <a href="/courses/international/<?php print $code ?>" id="res-btn-modal" class="btn btn-primary">
                <div class="international-switcher-icon"><i class="fa fa-globe" aria-hidden="true"></i></div>
                <div class=button-text>International students</div>
              </a>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <div class="bottom-text">You can also switch course details by clicking these buttons on the page.</div>
        <div class="dismiss-modal">
          <button tabindex="0" class="close-text" data-dismiss="modal">Close</button>
        </div>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->
