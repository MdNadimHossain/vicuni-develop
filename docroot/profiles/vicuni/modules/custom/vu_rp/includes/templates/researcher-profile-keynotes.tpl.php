<?php

/**
 * @file
 * Template file for Keynotes.
 */
?>
<?php if (count($content)): ?>
  <div class="section" id="research-career-keynotes">
    <h2 class="victory-title__stripe">Invited keynote speeches</h2>
    <div class="container">
      <div class="row first">
        <div class="col-md-10">
          <div id="researcher-career-keynotes" class="table-more">
            <table class="two-cell">
              <thead>
              <tr>
                <th class="year">Year</th>
                <th>Title/Description</th>
              </tr>
              </thead>
              <tbody>
              <?php foreach ($content as $keynote): ?>
                <tr>
                  <td><?php print $keynote['field_rp_k_year']; ?></td>
                  <td>
                    <p><?php print $keynote['field_rp_k_title']; ?></p>
                    <p><?php print $keynote['field_rp_k_details']; ?></p>
                  </td>
                </tr>
              <?php endforeach; ?>
              </tbody>
            </table>
            <?php if (count($content) > 3): ?>
              <a href="#" class="show-more-table-cell js-show-more-table-cell  more"><span>Show more invited keynote speeches</span>
                <i class="fa fa-angle-down"></i></a>
            <?php endif; ?>
          </div>
        </div>
        <div class="col-md-push-1 col-md-1"></div>
      </div>
    </div>
  </div>
<?php endif; ?>
