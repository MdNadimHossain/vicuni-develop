<?php

/**
 * @file
 * This was used when there were two implementations of the course index.
 */

/**
 * Get sensible information from the Course Index.
 */
abstract class AbstractCourseIntakeList {
  protected $intakes = array();
  protected $filterEntryMethod = NULL;
  const FEE_TYPE_FULL = 'HEFULLFEE';
  const FEE_TYPE_CSP = 'GOVTFUND';

  /**
   * Constructor.
   *
   * @param array $intakes
   *        Course index rows from vu_course_index_load_rows.
   * @param string $filter_entry_method
   *        Selected course index entry method.
   */
  public function __construct(array $intakes, $filter_entry_method = NULL) {
    $this->intakes = $intakes;
    $this->filterEntryMethod = $filter_entry_method;
  }

  /**
   * Pass all intakes to a test callback and 'or' the results.
   *
   * @param callable $test
   *        A unary function that receives an intake and should return a bool.
   *
   * @return bool
   *         Results of the callback 'or'ed together.
   */
  protected function test(callable $test) {
    return array_reduce($this->intakes, function ($acc, $del) use ($test) {
      return $acc || $test($del);
    }, FALSE);
  }

  /**
   * Array_filter the intakes.
   *
   * @param callable $test
   *        Unary function to receive an intake and return bool.
   *
   * @return AbstractCourseIntakeList
   *         An instance of the current class built from the filtered intakes.
   */
  protected function filter(callable $test) {
    $class = get_class($this);
    return new $class(array_filter($this->intakes, $test), $this->filterEntryMethod);
  }

  /**
   * Array_reduce the intakes.
   *
   * @param callable $test
   *        A function to receive an accumlator and an intake,
   *        and return something.
   * @param null|mixed $key
   *        If provided, values of the key will be plucked from the intakes
   *        and the resulting array reduced.
   * @param mixed|null $acc
   *        Initial value for the accumulator argument to $test.
   *
   * @return mixed
   *         The result of reduction.
   */
  protected function reduce(callable $test, $key = NULL, $acc = NULL) {
    $input = is_null($key) ? $this->intakes : $this->pluck($key);
    return array_reduce($input, $test, $acc);
  }

  /**
   * Array_map the intakes.
   *
   * @param callable $fn
   *        A unary functio to receive and intake and return it transformed.
   *
   * @return array
   *         The transformed intakes array.
   */
  protected function map(callable $fn) {
    return array_map($fn, $this->intakes);
  }

  /**
   * Build an array of values from one column of the intakes.
   *
   * @param string $key
   *        The column/field to pluck.
   *
   * @return array
   *         The values from the column $key.
   */
  protected function pluck($key) {
    return $this->map(function ($intake) use ($key) {
      return $intake[$key];
    });
  }

}
