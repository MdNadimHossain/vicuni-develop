<?php

/**
 * @file
 * HTML email notification template.
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns="http://www.w3.org/1999/xhtml"
      style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
<head>
  <meta name="viewport" content="width=device-width"/>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <title>CAMS Course import</title>
</head>
<body bgcolor="#f6f6f6"
      style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; -webkit-font-smoothing: antialiased; -webkit-text-size-adjust: none; width: 100% !important; height: 100%; margin: 0; padding: 0;">

<!-- body -->
<table class="body-wrap" bgcolor="#f6f6f6"
       style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; width: 100%; margin: 0; padding: 20px;">
  <tr
    style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
    <td
      style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;"></td>
    <td class="container" bgcolor="#FFFFFF"
        style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; display: block !important; max-width: 600px !important; clear: both !important; margin: 0 auto; padding: 20px; border: 1px solid #f0f0f0;">

      <!-- content -->
      <div class="content"
           style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; max-width: 600px; display: block; margin: 0 auto; padding: 0;">
        <table
          style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; width: 100%; margin: 0; padding: 0;">
          <tr
            style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
            <td
              style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
              <h1
                style="font-family: 'Helvetica Neue', Helvetica, Arial, 'Lucida Grande', sans-serif; font-size: 36px; line-height: 1.2; color: #000; font-weight: 200; margin: 40px 0 10px; padding: 0;">
                CAMS Course Import <?php echo date('d/m/Y'); ?></h1>

              <p
                style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;">
                Following is a list of the updates that happened with the latest
                course import.</p>
              <table
                style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; width: 100%; margin: 0; padding: 0;">
                <tr
                  style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
                  <td class="padding"
                      style="background-color: #DEE8C9; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 10px;">
                    <h2
                      style="font-family: 'Helvetica Neue', Helvetica, Arial, 'Lucida Grande', sans-serif; font-size: 28px; line-height: 1.2; color: #000; font-weight: 200; margin: 40px 0 10px; padding: 0;">
                      Created</h2>
                  </td>
                </tr>
                <?php foreach ($courses['CREATED'] as $course): ?>
                  <tr
                    style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
                    <td class="padding"
                        style="background-color: #EFF3E4; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 10px;">
                      <p
                        style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;">
                        <a href="https://www.vu.edu.au/node/<?php echo $course['nid']; ?>"><?php echo $course['title'];
                          echo $course['international'] === 'Y' ? ' (international)' : ''; ?></a>
                      </p>
                    </td>
                  </tr>
                <?php endforeach; ?>
              </table>
              <table
                style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; width: 100%; margin: 0; padding: 0;">
                <tr
                  style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
                  <td class="padding"
                      style="background-color: #C3E3ED; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 10px;">
                    <h2
                      style="font-family: 'Helvetica Neue', Helvetica, Arial, 'Lucida Grande', sans-serif; font-size: 28px; line-height: 1.2; color: #000; font-weight: 200; margin: 40px 0 10px; padding: 0;">
                      Reoffered</h2>
                  </td>
                </tr>
                <?php foreach ($courses['REOFFERED'] as $course): ?>
                  <tr
                    style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
                    <td class="padding"
                        style="background-color: #E2F1F6; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 10px;">
                      <p
                        style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;">
                        <a href="https://www.vu.edu.au/node/<?php echo $course['nid']; ?>"><?php echo $course['title'];
                          echo $course['international'] === 'Y' ? ' (international)' : ''; ?></a>
                      </p>
                    </td>
                  </tr>
                <?php endforeach; ?>
              </table>
              <table
                style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; width: 100%; margin: 0; padding: 0;">
                <tr
                  style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
                  <td class="padding"
                      style="background-color: #ECC5C4; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 10px;">
                    <h2
                      style="font-family: 'Helvetica Neue', Helvetica, Arial, 'Lucida Grande', sans-serif; font-size: 28px; line-height: 1.2; color: #000; font-weight: 200; margin: 40px 0 10px; padding: 0;">
                      Unpublished</h2>
                  </td>
                </tr>
                <?php foreach ($courses['UNPUBLISHED'] as $course): ?>
                  <tr
                    style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
                    <td class="padding"
                        style="background-color: #F5E3E2; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 10px;">
                      <p
                        style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;">
                        <a href="https://www.vu.edu.au/node/<?php echo $course['nid']; ?>"><?php echo $course['title'];
                          echo $course['international'] === 'Y' ? ' (international)' : ''; ?></a>
                      </p>
                      <?php if (($c = count($course['references']))): ?>

                        <p style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;">
                          Linked from:
                          <?php if ($c > 1) {
                            echo "<ul>";
                          } ?>
                          <?php foreach ($course['references'] as $nid => $title): ?>
                            <?php if ($c > 1) {
                              echo "<li style=\"font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;\">";
                            } ?>
                            <a href="https://www.vu.edu.au/node/<?php echo $nid; ?>"><?php echo $title; ?></a><?php if ($c > 1) {
                              echo "</li>";
                           } ?>
                          <?php endforeach; ?>
                          <?php if ($c > 1) {
                            echo "</ul>";
                          } ?>
                        </p>

                      <?php else: ?>
                        <p style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0; font-style: italic;">No links found.</p>
                      <?php endif; ?>

                    </td>
                  </tr>
                <?php endforeach; ?>
              </table>
              <table
                style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; width: 100%; margin: 0; padding: 0;">
                <tr
                  style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
                  <td class="padding"
                      style="background-color: #FDDCC1; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 10px;">
                    <h2
                      style="font-family: 'Helvetica Neue', Helvetica, Arial, 'Lucida Grande', sans-serif; font-size: 28px; line-height: 1.2; color: #000; font-weight: 200; margin: 40px 0 10px; padding: 0;">
                      Updated</h2>
                  </td>
                </tr>
                <?php foreach ($courses['UPDATED'] as $course): ?>
                  <tr
                    style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;">
                    <td class="padding"
                        style="background-color: #FEEEE1; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 10px;">
                      <p
                        style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;">
                        <a href="https://www.vu.edu.au/node/<?php echo $course['nid']; ?>"><?php echo $course['title'];
                          echo $course['international'] === 'Y' ? ' (international)' : ''; ?></a>
                      </p>
                      <?php if (($c = count($course['fields']))): ?>

                        <p style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;">
                          Updated:
                          <?php if ($c > 1) {
                            echo "<ul>";
                          } ?>
                          <?php foreach ($course['fields'] as $updated): ?>
                            <?php if ($c > 1) {
                              echo "<li style=\"font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;\">";
                            } ?><?php echo $updated; ?><?php if ($c > 1) {
                              echo "</li>";
                            } ?>
                          <?php endforeach; ?>
                          <?php if ($c > 1) {
                            echo "</ul>";
                          } ?>
                        </p>

                      <?php else: ?>
                        <p style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0; font-style: italic;">No links found.</p>
                      <?php endif; ?>
                    </td>
                  </tr>
                <?php endforeach; ?>
              </table>

              <p
                style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; line-height: 1.6; font-weight: normal; margin: 0 0 10px; padding: 0;">
                Thanks, have a lovely day.</p>

            </td>
          </tr>
        </table>
      </div>
      <!-- /content -->

    </td>
    <td
      style="font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 100%; line-height: 1.6; margin: 0; padding: 0;"></td>
  </tr>
</table>
<!-- /body -->
</body>
</html>
