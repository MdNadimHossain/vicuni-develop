<?php

/**
 * @file
 * Template file for Completed supervision.
 */
?>
<?php if (count($content)): ?>
  <div id="researcher-supervising-past-students">
    <h3>Completed supervision of research students at VU</h3>
    <table>
      <thead>
      <tr>
        <th>No. of students</th>
        <th>Study level</th>
        <th>Role</th>
      </tr>
      </thead>
      <tbody>
      <?php foreach ($content as $supervision): ?>
        <tr>
          <td><?php print $supervision['student_count'] ?></td>
          <td><?php print $supervision['level'] ?></td>
          <td><?php print $supervision['role'] ?></td>
        </tr>
      <?php endforeach; ?>
      </tbody>
    </table>
  </div>
  <div class="table-last" id="researcher-supervising-past-students-xs">
    <h3>Completed supervision of research students at VU</h3>
    <table>
      <thead>
      <tr>
        <th>Students & level</th>
        <th>Role</th>
      </tr>
      </thead>
      <tbody>
      <?php foreach ($content as $supervision): ?>
        <tr>
          <td><?php print $supervision['level'] ?>
            (<?php print $supervision['student_count'] ?>)
          </td>
          <td><?php print $supervision['role'] ?></td>
        </tr>
      <?php endforeach; ?>
      </tbody>
    </table>
  </div>
<?php endif; ?>
