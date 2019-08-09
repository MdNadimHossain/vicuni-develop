<?php

/**
 * @file
 * Template file for Awards.
 */
?>
<?php if (count($content)): ?>
  <div class="section" id="research-career-awards">
    <h2 class="victory-title__stripe">Awards</h2>
    <div class="container">
      <div class="row first">
        <div class="col-md-10">
          <div id="researcher-career-awards" class="table-more">
            <table class="two-cell">
              <thead>
              <tr>
                <th class="year">Year</th>
                <th>Award</th>
              </tr>
              </thead>
              <tbody>
              <?php foreach ($content as $award): ?>
                <tr>
                  <td><?php print $award['field_rp_a_year']; ?></td>
                  <td>
                    <p><?php print $award['field_rp_a_award_name']; ?>
                      - <?php print $award['field_rp_a_organisation']; ?></p>
                  </td>
                </tr>
              <?php endforeach; ?>
              </tbody>
            </table>
            <?php if (count($content) > 3): ?>
              <a href="#" class="show-more-table-cell js-show-more-table-cell  more"><span>Show more awards</span>
                <i class="fa fa-angle-down"></i></a>
            <?php endif; ?>
          </div>
        </div>
        <div class="col-md-push-1 col-md-1"></div>
      </div>
    </div>
  </div>
<?php endif; ?>
