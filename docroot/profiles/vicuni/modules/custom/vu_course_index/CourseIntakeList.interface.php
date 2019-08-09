<?php

/**
 * @file
 * Interface for course intake list class.
 */

/**
 * Interface for course intake list class.
 */
interface CourseIntakeListInterface {

  /**
   * Is the course currently open?
   *
   * Optionally filtered by application method.
   *
   * @param string|NULL $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course currently open?
   */
  public function isOpen($entry_method = NULL);

  /**
   * Is the course currently closed?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course currently closed?
   */
  public function isClosed($entry_method = NULL);

  /**
   * Does the course have a VTAC entry method?
   *
   * @return bool
   *         Does the course have a VTAC entry method?
   */
  public function isVtac();

  /**
   * Does the course have a direct entry method?
   *
   * @return bool
   *         Does the course have a direct entry method?
   */
  public function isDirect();

  /**
   * Is this a VE/TAFE course?
   *
   * @return bool
   *         Is this a VE/TAFE course?
   */
  public function isTafe();

  /**
   * Is this an undergraduate course?
   *
   * @return bool
   *         Is this an undergraduate course?
   */
  public function isUndergraduate();

  /**
   * Is this a postgraduate course?
   *
   * @return bool
   *         Is this a postgraduate course?
   */
  public function isPostgraduate();

  /**
   * Course level.
   *
   * @return string
   *         Undergraduate, Postgraduate, TAFE or empty string.
   */
  public function level();

  /**
   * Is this a Higher Ed (undergraduate or postgraduate) course?
   *
   * @return bool
   *         Is this a Higher Ed (undergraduate or postgraduate) course?
   */
  public function isHigherEd();

  /**
   * Does the course have an ongoing intake?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Does the course have an ongoing intake?
   */
  public function isOngoing($entry_method = NULL);

  /**
   * The furthest course closing date as a string.
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return string
   *         The furthest course closing date.
   */
  public function closingDate($entry_method = NULL);

  /**
   * Does the course have online application?
   *
   * @return bool
   *         Does the course have online application?
   */
  public function hasOnlineApplication();

  /**
   * Is the course offered part time?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course offered part time?
   */
  public function isPartTime($entry_method = NULL);

  /**
   * Is the course offered full time?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course offered full time?
   */
  public function isFullTime($entry_method = NULL);

  /**
   * Is the course fee type CSP?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course fee type CSP?
   */
  public function isFeeTypeCsp($entry_method = NULL);

  /**
   * Is the course fee type full fee?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course fee type full fee?
   */
  public function isFeeTypeFullFee($entry_method = NULL);

  /**
   * Get the fee type for this course.
   *
   * @return string
   *         Fee type.
   */
  public function getFeeType();

  /**
   * Is the course fee type both CSP and full fee?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course fee type both CSP and full fee?
   */
  public function isFeeTypeBothCspAndFullFee($entry_method = NULL);

  /**
   * Is the course only offered full time?
   *
   * Optionally filtered by application method.
   *
   * @param string $entry_method
   *        VTAC, Direct or Extern.
   *
   * @return bool
   *         Is the course only offered full time?
   */
  public function isOnlyFullTime($entry_method = NULL);

  /**
   * Information for the 'Course essentials' section of a course page.
   *
   * @param bool $open
   *        If true, only use info from open rows.
   *
   * @return array
   *         Information for the 'Course essentials' section of a course page.
   *         This is an array with two keys:
   *         - common: contains a hash of all values that are the same for rows.
   *         - rows: contains an array of hashes of distinct values.
   */
  public function courseEssentialsInfo($open = TRUE);

  /**
   * List of unique locations from this intake list.
   *
   * @param bool $open
   *        If true only use info from open rows.
   *
   * @return array
   *         Unique locations.
   */
  public function locations($open = TRUE);

}
