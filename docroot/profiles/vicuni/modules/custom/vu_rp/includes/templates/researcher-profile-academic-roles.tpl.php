<?php

/**
 * @file
 * Template file for Researcher key details.
 */
?>
<?php if (count($content)): ?>
  <div class="section research-career-academic-roles" id="research-career-academic-roles">
    <h2 class="victory-title__stripe">Key academic roles</h2>
    <div class="container">
      <div class="row first">
        <div class="col-md-10">
          <div class="table-more" id="researcher-career-academic-roles">
            <table class="three-cell">
              <thead>
              <tr>
                <th>Dates</th>
                <th>Role</th>
                <th>Department / Organisation</th>
              </tr>
              </thead>
              <tbody>
              <?php foreach ($content as $role): ?>
                <tr>
                  <td><?php print $role['field_start']; ?>
                    - <?php print $role['field_end']; ?></td>
                  <td>
                    <div><b><?php print $role['field_rp_ar_role']; ?></b>
                    </div>
                  </td>
                  <td><?php print $role['field_rp_ar_organisation']; ?></td>
                </tr>
              <?php endforeach; ?>
              </tbody>
            </table>
            <?php if (count($content) > 3): ?>
              <a href="#" class="show-more-table-cell js-show-more-table-cell  more"><span>Show more academic roles</span>
                <i class="fa fa-angle-down"></i></a>
            <?php endif; ?>
          </div>
          <div class="table-more xs-table" id="researcher-career-academic-roles-xs">
            <table>
              <thead>
              <tr>
                <th>Dates</th>
                <th>Role & Department/Organisation</th>
              </tr>
              </thead>
              <tbody>
              <?php foreach ($content as $role): ?>
                <tr>
                  <td><?php print $role['field_start']; ?> -
                    <div><?php print $role['field_end']; ?></div>
                  </td>
                  <td>
                    <div><b><?php print $role['field_rp_ar_role']; ?></b>
                    </div><?php print $role['field_rp_ar_organisation']; ?></td>
                </tr>
              <?php endforeach; ?>
              </tbody>
            </table>
            <?php if (count($content) > 3): ?>
              <a href="#" class="show-more-table-cell js-show-more-table-cell  more"><span>Show more academic roles</span>
                <i class="fa fa-angle-down"></i></a>
            <?php endif; ?>
          </div>
        </div>
        <div class="col-md-push-1 col-md-1"></div>
      </div>
    </div>
  </div>
<?php endif; ?>
