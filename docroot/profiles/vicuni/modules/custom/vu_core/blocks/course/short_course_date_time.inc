<?php

/**
 * @file
 * Courses - Short course dates and times.
 */

/**
 * Class VuCoreShortCourseDateTimeCourseBlock.
 */
class VuCoreShortCourseDateTimeCourseBlock extends vuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public static $info = 'Short course dates and times';

  /**
   * {@inheritdoc}
   */
  public function condCallback() {
    return !empty($this->course->field_short_dates_times);
  }

  /**
   * {@inheritdoc}
   */
  public function view() {
    /** @var \view $view */
    $view = views_get_view('short_dates_and_times_revision');
    $view->set_arguments([$this->course->vid]);
    $view->dom_id = md5($view->name . REQUEST_TIME . rand());

    return [
      'subject' => self::$info,
      'content' => $view->render('block_1'),
    ];
  }

}
