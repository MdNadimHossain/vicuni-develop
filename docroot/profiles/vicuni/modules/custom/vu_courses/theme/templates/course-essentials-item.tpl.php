<?php

/**
 * @file
 * Course essentials item template.
 */
if (!$value) {
  return;
}
$icon = vu_courses_course_essentials_icon($label);
$icon_class = implode(' ', array_map(function ($icon) {
  return "fa-{$icon}";
}, explode(' ', $icon)));

$col = $variants == 'small' ? 'col-sm-6' : 'col-sm-12';
$class_name = 'course-essentials__item';

?>
<div class="<?php echo $class_name ?> <?php echo $col ?>">

  <div class="<?php echo $class_name ?>__label">
    <span class="fa-stack fa-fw">
      <i class="fa fa-circle fa-stack-2x"></i>
      <i class="fa <?php echo $icon_class ?> fa-stack-1x fa-inverse"></i>
    </span><?php echo filter_xss_admin($label) ?>:

  </div>

  <div class="<?php echo $class_name ?>__value">
    <?php echo filter_xss_admin($value) ?>
  </div>

</div>
