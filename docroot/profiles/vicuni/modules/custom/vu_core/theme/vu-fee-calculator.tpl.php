<?php

/**
 * @file
 * Template for the Fee Calculator.
 */
?>

<form id="fee-calculator-form">
  <div class="fee-calculator-details">
    <p class="paragraph--lead">Use this fee calculator to get an indicative cost of what your course and unit fees could be.</p>
    <p class="paragraph--lead">The Fee Calculator does not include indicative fees for VU courses and units that have been superseded or in ‘teach out’ mode as they are not available for new intake/admission. Any queries regarding fee information not displaying in the online fee calculator can be lodged via <a href="http://askvu.vu.edu.au">ASKVU</a>.</p>
    <p class="paragraph--lead">Please note that the fee amounts displayed are subject to change.</p>
  </div>

  <div class="fee-form-container">
    <input type="hidden" name="international" id="international-field" value="<?php print $international ? FEE_AUDIENCE_INTERNATIONAL : FEE_AUDIENCE_DOMESTIC; ?>">
    <div class="fee-calculator-residency-tabs" data-toggle="buttons">
      <button class="btn btn-default<?php print !$international ? ' active' : ''; ?>" id="btn-domestic" type="button"><?php print t('Australian residents'); ?></button>
      <button class="btn btn-default<?php print $international ? ' active' : ''; ?>" id="btn-international" type="button"><?php print t('International students'); ?></button>
    </div>

    <div class="fee-calculator-fields">
      <p class="residency-modal-txt"><span class="paragraph--lead">Fee calculator for <span id="residential-modal-residency"><?php print $international ? 'International students' : 'Australian residents'; ?></span></span> <a tabindex="0" role="button" class="js-residency-btn-modal fa fa-question-circle"></a></p>

      <div class="form-group" id="fee-type-field"<?php print $international ? ' style="display: none"' : ''; ?>>
        <label for="fee-type">My fee type is <span class="required">*</span> <a tabindex="0" role="button" class="js-fee-type-btn-modal fa fa-question-circle"></a></label>
        <select id="fee-type" name="fee-type" class="form-control input-lg">
          <?php foreach ($fee_type_select_options as $sector => $optgroup): ?>
            <optgroup label="<?php print $sectors[$sector]; ?>">
              <?php foreach ($optgroup as $option): ?>
                <option value="<?php print $option['tid']; ?>"><?php print $option['name']; ?></option>
              <?php endforeach; ?>
            </optgroup>
          <?php endforeach; ?>
        </select>
      </div>
      <div class="form-group" id="sector-field"<?php print !$international ? ' style="display: none"' : ''; ?>>
        <label>My sector is <span class="required">*</span></label>
        <div>
          <?php foreach ($sectors as $key => $sector): ?>
            <label class="radio-inline">
              <input type="radio" name="sector" value="<?php print $key; ?>"<?php print $key === $default_sector ? ' checked="checked"' : ''; ?>> <?php print $sector; ?>
            </label>
          <?php endforeach; ?>
        </div>
      </div>
      <div class="form-group">
        <label>I want to see fees for <span class="required">*</span></label>
        <div>
          <?php foreach ($fee_years as $fee_year): ?>
            <label class="radio-inline">
              <input type="radio"<?php print $fee_year === $default_fee_year ? ' checked="checked"' : ''; ?> name="fee-year" value="<?php print $fee_year; ?>"> <?php print $fee_year; ?>
            </label>
          <?php endforeach; ?>
        </div>
      </div>
      <div class="form-group" id="cohort-year-field"<?php print !$international ? ' style="display: none"' : ''; ?>>
        <label for="cohort-year">I started (or will start) my course in <span class="required">*</span></label>
        <select id="cohort-year" class="form-control input-lg">
          <?php foreach ($cohort_years as $cohort_year): ?>
            <option value="<?php print $cohort_year['value']; ?>"<?php print $cohort_year['value'] === $default_cohort_year ? ' selected="selected"' : ''; ?>>
              <?php print $cohort_year['label']; ?>
            </option>
          <?php endforeach; ?>
        </select>
      </div>
      <div class="form-group">
        <label for="fee-search-query"><span id="fee-search-query-label-text">I want to search fees <?php print $international ? 'for' : 'by'; ?></span> <span class="required">*</span></label>
        <div class="row">
          <div class="col-sm-3" id="fee-context-field"<?php print $international ? ' style="display: none"' : ''; ?>>
            <select id="fee-context" class="form-control input-lg">
              <option value="course"><?php print t('Course') ?></option>
              <option value="unit"><?php print t('Unit') ?></option>
            </select>
          </div>
          <div class="<?php print $international ? 'col-sm-12' : 'col-sm-9'; ?>" id="fee-search-query-field">
            <div id="fee-search-container">
              <input id="fee-search-query" class="form-control input-lg" placeholder="Enter course code or name" autocomplete="off" aria-controls="fee-search-results" aria-autocomplete="list">
              <div id="fee-search-results" class="list-group" role="listbox"></div>
              <div id="fee-search-results-loading" class="list-group" style="display: none">
                <div class="list-group-item">Loading...</div>
              </div>
              <div id="fee-search-results-no-results" class="list-group" style="display: none">
                <div class="list-group-item">No results found.</div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</form>

<div class="calculated-fees-button-container">
  <button class="calculated-fees-button calculated-fees-button--disabled" disabled><span>My calculated fees<span class="fee-count">(0)</span></span></button>
</div>

<div class="fee-results-container">
  <div id="fee-results-<?php print FEE_AUDIENCE_DOMESTIC; ?>" class="fee-results<?php print !$international ? ' fee-results--visible' : ''; ?>">
    <?php foreach ($fee_type_select_options as $sector => $optgroup): ?>
      <?php foreach ($optgroup as $option): ?>
        <div id="fee-results-<?php print FEE_AUDIENCE_DOMESTIC; ?>-course-<?php print $option['tid']; ?>" style="display: none">
          <h3><?php print $sectors[$sector]; ?> - Courses <span>(<?php print $option['name']; ?>)</span></h3>
          <?php if ($sector === FEE_SECTOR_HE): ?>
            <div class="table-responsive">
              <table class="table">
                <thead>
                <tr>
                  <th class="width-80"><?php print t('Fee year'); ?></th>
                  <th class="width-120"><?php print t('Course code'); ?></th>
                  <th class="course-title"><?php print t('Course title'); ?></th>
                  <th class="width-120"><?php print t('Credit points'); ?></th>
                  <th class="width-120"><?php print t('EFTSL'); ?></th>
                  <th class="fee-value width-160"><?php print t('Annual fee ($AUD)'); ?></th>
                  <th class="actions"></th>
                </tr>
                </thead>
                <tbody></tbody>
              </table>
            </div>
          <?php elseif ($sector === FEE_SECTOR_VE): ?>
            <div class="table-responsive">
              <table class="table">
                <thead>
                <tr>
                  <th class="width-80"><?php print t('Fee year'); ?></th>
                  <th class="width-120"><?php print t('Course code'); ?></th>
                  <th class="course-title"><?php print t('Course title'); ?></th>
                  <th class="width-120"><?php print t('Contact hours'); ?></th>
                  <th class="width-120"><?php print t('Hourly rate'); ?></th>
                  <th class="fee-value width-160"><?php print t('Tuition fee ($AUD)'); ?></th>
                  <th class="actions"></th>
                </tr>
                </thead>
                <tbody></tbody>
              </table>
            </div>
          <?php endif; ?>
        </div>
      <?php endforeach; ?>
    <?php endforeach; ?>

    <?php foreach ($fee_type_select_options as $sector => $optgroup): ?>
      <?php foreach ($optgroup as $option): ?>
        <div id="fee-results-<?php print FEE_AUDIENCE_DOMESTIC; ?>-unit-<?php print $option['tid']; ?>" style="display: none">
          <h3><?php print $sectors[$sector]; ?> - Units <span>(<?php print $option['name']; ?>)</span></h3>
            <?php if ($sector === FEE_SECTOR_HE): ?>
              <div class="table-responsive">
                <table class="table">
                  <thead>
                  <tr>
                    <th class="width-80"><?php print t('Fee year'); ?></th>
                    <th class="width-120"><?php print t('Unit code'); ?></th>
                    <th class="course-title"><?php print t('Unit title'); ?></th>
                    <th class="width-120"><?php print t('Credit points'); ?></th>
                    <th class="width-120"><?php print t('EFTSL'); ?></th>
                    <th class="fee-value width-160"><?php print t('Fee ($AUD)'); ?></th>
                    <th class="actions"></th>
                  </tr>
                  </thead>
                  <tbody></tbody>
                  <tfoot>
                  <tr>
                    <td colspan="5" class="grand-total-label"><span><?php print t('Total'); ?></span></td>
                    <td class="grand-total">$0.00</td>
                    <td class="actions"></td>
                  </tr>
                  </tfoot>
                </table>
              </div>
            <?php elseif ($sector === FEE_SECTOR_VE): ?>
              <div class="table-responsive">
                <table class="table">
                  <thead>
                  <tr>
                    <th class="width-80"><?php print t('Fee year'); ?></th>
                    <th class="width-120"><?php print t('Unit code'); ?></th>
                    <th class="course-title"><?php print t('Unit title'); ?></th>
                    <th class="width-120"><?php print t('Contact hours'); ?></th>
                    <th class="width-120"><?php print t('Hourly rate'); ?></th>
                    <th class="fee-value width-160"><?php print t('Fee ($AUD)'); ?></th>
                    <th class="actions"></th>
                  </tr>
                  </thead>
                  <tbody></tbody>
                  <tfoot>
                  <tr>
                    <td colspan="5" class="grand-total-label"><span><?php print t('Total'); ?></span></td>
                    <td class="grand-total">$0.00</td>
                    <td class="actions"></td>
                  </tr>
                  </tfoot>
                </table>
              </div>
            <?php endif; ?>
        </div>
      <?php endforeach; ?>
    <?php endforeach; ?>
  </div>

  <div id="fee-results-<?php print FEE_AUDIENCE_INTERNATIONAL; ?>" class="fee-results<?php print $international ? ' fee-results--visible' : ''; ?>">
    <?php foreach ($sectors as $key => $sector): ?>
      <?php if ($key === FEE_SECTOR_HE): ?>
        <?php foreach ($cohort_years as $cohort_year): ?>
          <div id="fee-results-<?php print FEE_AUDIENCE_INTERNATIONAL; ?>-course-<?php print $key; ?>-<?php print $cohort_year['value']; ?>" style="display: none">
            <h3><?php print $sector; ?> - Courses <span>(<?php print $cohort_year['label']; ?>)</span></h3>
            <div class="table-responsive">
              <table class="table">
                <thead>
                <tr>
                  <th class="width-80"><?php print t('Fee year'); ?></th>
                  <th class="width-120"><?php print t('Course code'); ?></th>
                  <th class="course-title"><?php print t('Course title'); ?></th>
                  <th class="width-120"><?php print t('Credit points'); ?></th>
                  <th class="width-120"><?php print t('EFTSL'); ?></th>
                  <th class="fee-value width-160"><?php print t('Tuition fee ($AUD)'); ?></th>
                  <th class="actions"></th>
                </tr>
                </thead>
                <tbody></tbody>
              </table>
            </div>
          </div>
        <?php endforeach; ?>
      <?php elseif ($key === FEE_SECTOR_VE): ?>
        <div id="fee-results-<?php print FEE_AUDIENCE_INTERNATIONAL; ?>-course-<?php print $key; ?>" style="display: none">
          <h3><?php print $sector; ?> - Courses</h3>
          <div class="table-responsive">
            <table class="table">
              <thead>
              <tr>
                <th class="width-80"><?php print t('Fee year'); ?></th>
                <th class="width-120"><?php print t('Course code'); ?></th>
                <th class="course-title"><?php print t('Course title'); ?></th>
                <th class="width-120"><?php print t('Contact hours'); ?></th>
                <th class="fee-value width-160"><?php print t('Tuition fee ($AUD)'); ?></th>
                <th class="actions"></th>
              </tr>
              </thead>
              <tbody></tbody>
            </table>
          </div>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
</div>

<div class="fee-disclaimers-container" style="display: none">
  <div class="fee-disclaimers-list">
    <?php foreach ($disclaimers as $disclaimer): ?>
    <div class="fee-disclaimer-item" data-disclaimer-id="<?php print $disclaimer['tid']; ?>" style="display: none">
      <?php print $disclaimer['description']; ?>
    </div>
    <?php endforeach; ?>
  </div>
</div>

<div class="modal fade" id="residency-info-modal" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close" ></button>
        <h3><?php print t('Which fee calculator should I use?') ?></h3>
        <?php print theme('vu_course_switcher_domestic_info') ?>
        <?php print theme('vu_course_switcher_international_info') ?>
        <div class="dismiss-modal">
          <button tabindex="0" class="close-text" data-dismiss="modal">Close</button>
        </div>
      </div>
    </div>
  </div>
</div>

<div class="modal fade" id="fee-type-info-modal" tabindex="-1" role="dialog">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-body">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close" ></button>
        <h3><?php print t('What is my fee type?') ?></h3>
        <p>Your fee type will depend on your eligibility and type of place being offered.</p>
        <p>Subsidised fee rates are provided to eligible students in a Commonwealth supported or government subsidised place, this means that your fees are jointly paid by you and the Australian Government.</p>
        <p>Reduced fee rates are provided to VET government subsidised places with an eligible Concession.</p>
        <p>Full-fee rates means that there is no contribution from the Australian Government and the total tuition cost is paid by you.</p>
        <div class="dismiss-modal">
          <button tabindex="0" class="close-text" data-dismiss="modal">Close</button>
        </div>
      </div>
    </div>
  </div>
</div>
