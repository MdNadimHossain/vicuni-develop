<?php

namespace VicUni\Driver\Cores;

/**
 * Class Drupal7.
 *
 * @package VicUni\Driver\Cores
 */
// @codingStandardsIgnoreLine
class Drupal7 extends \Drupal\Driver\Cores\Drupal7 {

  /**
   * Create a drupal session for the user.
   *
   * @param \stdClass $user
   *   The user to login.
   *
   * @return array
   *   The created session.
   */
  public function userLogin(\stdClass $user) {
    // Force Drupal HTTPS compatibility, Drupal invoked from Behat has no
    // web server or protocol awareness.
    $GLOBALS['is_https'] = TRUE;
    drupal_session_started(TRUE);

    // Log in the requested user.
    $GLOBALS['user'] = user_load($user->uid);
    $login_form = [];
    $login_form['uid'] = $user->uid;
    user_login_finalize($login_form);

    // Write the session to the database.
    _drupal_session_write(session_id(), '');

    return [
      'session_name' => session_name(),
      'ssession_name' => sprintf('S%s', session_name()),
      'session_id' => session_id(),
    ];
  }

  /**
   * Remove a drupal session for the user.
   *
   * @param \stdClass $user
   *   The user to logout.
   * @param string $session_id
   *   The session id.
   */
  public function userLogout(\stdClass $user, $session_id) {
    $GLOBALS['is_https'] = TRUE;
    $GLOBALS['user'] = $user;
    _drupal_session_destroy($session_id);
  }

}
