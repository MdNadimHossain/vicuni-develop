<?php

namespace VicUni;

use SebastianBergmann\GlobalState\RuntimeException;
use VicUni\Driver\DrupalDriver;
use Behat\Mink\Driver\Selenium2Driver;
use WebDriver\Exception\UnableToSetCookie;

/**
 * Trait FastLoginTrait.
 */
trait FastLoginTrait {

  /**
   * The path to the dummy HTML file for quick serving (No drupal).
   *
   * @var string
   */
  public static $fastLoginHtmlFile = 'VicUni_FastLoginTrait_dummy.html';

  /**
   * The user object that is logged in, or FALSE.
   *
   * @var bool|\stdClass
   */
  protected $loggedInUser = FALSE;

  /**
   * The drupal session name and id.
   *
   * @var array
   */
  protected $drupalSession = [];

  /**
   * Get the domain to use in cookies.
   *
   * @return string
   *   The hostname.
   */
  protected function getCookieDomain() {
    if (empty($this->getMinkParameter('base_url'))) {
      throw new RuntimeException('Parameter "base_url" must be set to retrieve cookie domain.');
    }

    return parse_url($this->getMinkParameter('base_url'), PHP_URL_HOST);
  }

  /**
   * {@inheritdoc}
   *
   * Overwritten method bypasses default checking behaviour (vising pages).
   */
  public function loggedIn() {
    if (!$this->getDriver() instanceof DrupalDriver) {
      return parent::loggedIn();
    }

    return !empty($this->loggedInUser);
  }

  /**
   * {@inheritdoc}
   *
   * Overwritten method adds faster login by using drupal sessions directly.
   */
  public function login(\stdClass $user) {
    // If we're not using our custom driver, use the default login method.
    if (!$this->getDriver() instanceof DrupalDriver) {
      parent::login($user);

      return;
    }

    $drupal_session = $this->getDriver()->userLogin($user);
    // Visit a fast loading page to initialise browser session.
    $this->getSession()->visit($this->getTestHtmlFileUrl());

    // Set user's session cookie.
    $this->sendDrupalSessionCookie($drupal_session);
    // Set drupal's "secure" session cookie (it has an extra "S" on the front).
    $this->sendDrupalSessionCookie(['session_name' => $drupal_session['ssession_name'], 'session_id' => $drupal_session['session_id']]);

    // If we get here the user is now logged in.
    $this->loggedInUser = $user;
    $this->drupalSession = $drupal_session;
    $this->getUserManager()->setCurrentUser($user);
  }

  /**
   * {@inheritdoc}
   *
   * Overwritten method adds faster logout by using drupal sessions directly.
   */
  public function logout() {
    if (!$this->getDriver() instanceof DrupalDriver) {
      parent::logout();

      return;
    }
    if (empty($this->loggedInUser)) {
      throw new RuntimeException('Attempted to log out a user that does not exist.');
    }
    if (empty($this->drupalSession)) {
      throw new RuntimeException('No drupal session started.');
    }
    $this->getDriver()->userLogout($this->loggedInUser, $this->drupalSession['session_id']);
    // SetCookie with no value deletes.
    $this->getSession()->setCookie($this->drupalSession['session_name']);
    // Remove "Secure" session cookie.
    $this->getSession()->setCookie($this->drupalSession['ssession_name']);
    $this->loggedInUser = FALSE;
    $this->drupalSession = [];
  }

  /**
   * Send a drupal php session cookie to the current mink session.
   *
   * @param array $drupal_session
   *   Session info in the form of ['session_name' => '', 'session_id => ''].
   *
   * @throws \WebDriver\Exception\UnableToSetCookie
   */
  public function sendDrupalSessionCookie(array $drupal_session) {
    if ($this->getSession()->getDriver() instanceof Selenium2Driver) {
      // PhantomJS and potentially others are fussy about their cookies.
      $cookie = [
        'name' => $drupal_session['session_name'],
        'value' => urlencode($drupal_session['session_id']),
        // Secure = FALSE works on http and https.
        'secure' => FALSE,
        'httponly' => TRUE,
        'domain' => $this->getCookieDomain(),
      ];
      // Bypass Selenium2Session::setCookie as it mangles the cookie and doesn't
      // allow setting of other parameters (domain, httponly).
      /* @var \WebDriver\Session $wd_session */
      $wd_session = $this->getSession()->getDriver()->getWebDriverSession();
      try {
        $wd_session->setCookie($cookie);
      }
      catch (UnableToSetCookie $e) {
        // This is a workaround for a bug in phantomjs.
        // https://github.com/ariya/phantomjs/blob/2.1/src/cookiejar.cpp#L116
        // The underlying method *always* returns FALSE, which in turn
        // triggers an exception.
        //
        // Here we load all the cookies in our webdriver session, if we
        // find a cookie that matches the one we sent, then it obviously set
        // itself, regardless of the exceptions thrown.
        $stored_cookies = $wd_session->getAllCookies();
        $cookie_set = FALSE;
        foreach ($stored_cookies as $stored_cookie) {
          if (isset($stored_cookie['name']) && $stored_cookie['name'] === $cookie['name']) {
            $cookie_set = TRUE;
          }
        }
        // If we can't find the cookie we tried to set, then there actually was
        // an error setting the cookie and the exception was correct.
        if (!$cookie_set) {
          throw $e;
        }
      }
    }
    else {
      $this->getSession()->setCookie($drupal_session['session_name'], $drupal_session['session_id']);
    }
  }

  /**
   * Get the URL for the empty html file.
   *
   * @return bool|string
   *   The path to the file.
   */
  protected function getTestHtmlFileUrl() {
    if (!$this->getDriver() instanceof DrupalDriver) {
      throw new RuntimeException('Cannot use Fast Login with default driver.');
    }

    return $this->locatePath(sprintf('/%s', self::$fastLoginHtmlFile));
  }

  /**
   * Gets the filesystem path to the empty html file.
   *
   * @return string
   *   The html file path.
   */
  protected function getTestHtmlFilename() {
    if (!$this->getDriver() instanceof DrupalDriver) {
      throw new RuntimeException('Cannot use Fast Login with default driver.');
    }

    return sprintf("%s%s%s", $this->getDriver()->getDrupalRoot(), DIRECTORY_SEPARATOR, self::$fastLoginHtmlFile);
  }

  /**
   * Prepare empty html file before scenario runs.
   *
   * @BeforeScenario
   */
  public function prepareTestHtmlFile() {
    if (!$this->getDriver() instanceof DrupalDriver) {
      return;
    }
    if (!is_writable($this->getDriver()->getDrupalRoot())) {
      throw new RuntimeException('Fast login needs write permission to the drupal root directory.');
    }
    $html = '<html><head><meta name="robots" content="noindex, nofollow"><title>Blank</title></head><body><p>Blank</p></body></html>' . PHP_EOL;
    $file_written = file_put_contents($this->getTestHtmlFilename(), $html);
    if ($file_written === FALSE) {
      throw new RuntimeException('Test HTML write failed.');
    }
  }

  /**
   * Remove empty html file after scenario runs.
   *
   * @AfterScenario
   */
  public function removeTestHtmlFile() {
    if (!$this->getDriver() instanceof DrupalDriver) {
      return;
    }
    if (file_exists($this->getTestHtmlFilename())) {
      unlink($this->getTestHtmlFilename());
    }
  }

}
