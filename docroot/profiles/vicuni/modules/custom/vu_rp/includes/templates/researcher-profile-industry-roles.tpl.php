<?php

/**
 * @file
 * Template file for Industry roles.
 */
?>
<?php if (count($content)): ?>
  <div class="section" id="research-career-industry-roles">
    <h2 class="victory-title__stripe">Key industry, community & government
      roles</h2>
    <div class="container">
      <div class="row first">
        <div class="col-md-10">
          <div id="researcher-career-industry-roles">
            <table class="three-cell">
              <thead>
              <tr>
                <th>Dates</th>
                <th>Role</th>
                <th>Department/Organisation</th>
              </tr>
              </thead>
              <tbody>
              <?php foreach ($content as $role): ?>
                <tr>
                  <td><?php print $role['field_start']; ?>
                    - <?php print $role['field_end']; ?></td>
                  <td>
                    <div><b><?php print $role['field_rp_ir_role']; ?>
                    </div>
                    </b></td>
                  <td><?php print $role['field_rp_ir_organisation']; ?></td>
                </tr>
              <?php endforeach; ?>
              </tbody>
            </table>
          </div>
          <div class="xs-table" id="researcher-career-industry-roles-xs">
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
                  <td><?php print $role['field_start']; ?>
                    - <?php print $role['field_end']; ?></td>
                  <td>
                    <div><b><?php print $role['field_rp_ir_role']; ?>
                    </div>
                    </b><?php print $role['field_rp_ir_organisation']; ?></td>
                </tr>
              <?php endforeach; ?>
              </tbody>
            </table>
          </div>
        </div>
        <div class="col-md-push-1 col-md-1"></div>
      </div>
    </div>
  </div>
<?php endif; ?>
