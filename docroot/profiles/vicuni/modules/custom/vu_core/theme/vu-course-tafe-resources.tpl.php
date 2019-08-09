<?php

/**
 * @file
 * Template for TAFE resources sidebar block on course pages.
 */
?>
<div class="tafe-resources-box--tafe">
  <div class="tafe-resources-box__header">
    <h3 class="title">
      <?php echo t('TAFE resources'); ?>
    </h3>
    <!--?xml version="1.0" encoding="utf-8"?-->
    <!-- Generator: Adobe Illustrator 16.0.0, SVG Export Plug-In . SVG Version: 6.00 Build 0)  -->
    <svg enable-background="new 0 0 35.92 35.919" height="35.919px" id="Layer_1" version="1.1" viewbox="0 0 35.92 35.919" width="35.92px" x="0px" xml:space="preserve" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" y="0px">
      <g>
        <polygon points="17.672,35.918 17.672,26.328 0.064,18.311"></polygon>
        <polygon points="18.312,0 18.312,25.623 35.92,17.606"></polygon>
        <polygon points="17.607,0 0,17.606 17.607,25.623"></polygon>
        <polygon points="18.312,26.328 18.312,35.919 35.92,18.312"></polygon>
      </g>
    </svg>
  </div>
  <div class="tafe-resources-box__content">
    <ul>
      <?php if ($free_tafe_value): ?>
        <li class="free-tafe">
          <a class="noext" href="https://www.vupolytechnic.edu.au/free-tafe" title="Free Tafe 2019">
            Free TAFE 2019
          </a><br>
          <span class="free-tafe-text">No tuition fees for eligible students.</span>
        </li>
      <?php endif; ?>
      <li class="fee-subsidies">
        <a class="noext" href="https://www.vupolytechnic.edu.au/eligibility-government-subsidised-place">
          Fee subsidies
        </a>
      </li>
      <?php if (!empty($tafe_info_session_url)): ?>
        <li class="info-sessions">
          <a class="noext" href="<?php echo $tafe_info_session_url; ?>" title="course information sessions">
            Course information sessions
          </a>
        </li>
      <?php endif; ?>
    </ul>
  </div>
</div>
