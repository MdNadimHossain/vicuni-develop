<?php

/**
 * @file
 * Audience selector.
 */
?>
<div class="atar-audience-indicator">
  <h3>
    <i class="fa fa-info-circle"></i>
    Need help?
  </h3>
  <h4>Selection criteria assistance</h4>
  <p>
    Let us know which qualifications you have studied and we will help you find
    the admission information that most applies to you.
  </p>
  <p>
    Which of the following qualifications have you studied, or are currently studying?
  </p>
  <div data-audience="1" class="hidden audience-indicator-advice">
    <p>
      Based on your selection<span data-audience="2" class="hidden audience-indicator-selection">/s</span><span data-audience="1" class="hidden selection-text"></span>, you will need to view information for <strong>applicants with recent secondary education (within the last 2 years)</strong>.
    </p>
    <p>
      If you have completed secondary education more than 2 year ago (prior to 2017) you will need to view information for applicants with work/life experience.
    </p>
  </div>
  <div data-audience="2" class="hidden audience-indicator-advice">
    <p>
      Based on your selection<span data-audience="2" class="hidden audience-indicator-selection">/s</span><span data-audience="2" class="hidden selection-text"></span>, you will need to view information for <strong>applicants with Vocational Education and Training (VET/TAFE) study</strong>.
    </p>
  </div>
  <div data-audience="3" class="hidden audience-indicator-advice">
    <p>
      Based on your selection<span data-audience="2" class="hidden audience-indicator-selection">/s</span><span data-audience="3" class="hidden selection-text"></span>, you will need to view information for <strong>applicants with higher education study</strong>.
    </p>
  </div>
  <div class="qualification-dropdown">
    <select class="selectpicker" multiple title="Select your qualifications" data-width="auto" id="audience-indicator" data-header="Select one or more qualifications you have studied in.">
      <option value="1">Secondary school / VCE</option>
      <option value="1">International Baccalaureate (IB)</option>
      <option value="1">Bridging course (foundation studies)</option>
      <option value="2">Certificate IV (TAFE)</option>
      <option value="2">Diploma/Advanced Diploma (TAFE)</option>
      <option value="3">Bachelor degree</option>
      <option value="3">Postgraduate studies</option>
    </select>
  </div>
  <p></p>
  <p>
    Still not sure? <a href="#goto-enquire-now" data-smoothscroll>Make an enquiry</a> and one of our advisors can assist.
  </p>
</div>
