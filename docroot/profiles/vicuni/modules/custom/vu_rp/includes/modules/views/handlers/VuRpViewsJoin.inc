<?php

/**
 * @file
 * Code for VuRpViewsJoin.
 */

/**
 * Views join.
 *
 * @ingroup views_field_handlers
 */
class VuRpViewsJoin extends views_join {

  /**
   * Build the SQL for the join this object represents.
   *
   * When possible, try to use table alias instead of table names.
   *
   * @param SelectQueryInterface $select_query
   *   An Implements SelectQueryInterface.
   * @param string $table
   *   The base table to join.
   * @param views_plugin_query $view_query
   *   The source query, Implements views_plugin_query.
   */
  // @codingStandardsIgnoreStart
  public function build_join($select_query, $table, $view_query) {
    // @codingStandardsIgnoreEnd
    if (empty($this->definition['table formula'])) {
      $right_table = $this->table;
    }
    else {
      $right_table = $this->definition['table formula'];
    }

    if ($this->left_table) {
      $left = $view_query->get_table_info($this->left_table);
      $left_field = "$left[alias].$this->left_field";
    }
    else {
      // This can be used if left_field is a formula or something.
      // It should be used only *very* rarely.
      $left_field = $this->left_field;
    }

    $condition = "$left_field = $table[alias].$this->field";
    $arguments = [];

    // Tack on the extra.
    if (isset($this->extra)) {
      // If extra has been provided as string instead of an array, convert it
      // to an array.
      if (!is_array($this->extra)) {
        $this->extra = [$this->extra];
      }

      $extras = [];
      foreach ($this->extra as $info) {
        if (is_array($info)) {
          // Figure out the table name. Remember, only use aliases provided
          // if at all possible.
          $join_table = '';
          if (!array_key_exists('table', $info)) {
            $join_table = $table['alias'] . '.';
          }
          elseif (isset($info['table'])) {
            // If we're aware of a table alias for this table, use the table
            // alias instead of the table name.
            if (isset($left) && $left['table'] == $info['table']) {
              $join_table = $left['alias'] . '.';
            }
            else {
              $join_table = $info['table'] . '.';
            }
          }

          // Convert a single-valued array of values to the single-value case,
          // and transform from IN() notation to = notation.
          if (is_array($info['value']) && count($info['value']) == 1) {
            if (empty($info['operator'])) {
              $operator = '=';
            }
            else {
              $operator = $info['operator'] == 'NOT IN' ? '!=' : '=';
            }
            $info['value'] = array_shift($info['value']);
          }

          if (is_array($info['value'])) {
            // With an array of values, we need multiple placeholders and the
            // 'IN' operator is implicit.
            foreach ($info['value'] as $value) {
              $placeholder_i = $view_query->placeholder('views_join_condition_');
              $arguments[$placeholder_i] = $value;
            }

            $operator = !empty($info['operator']) ? $info['operator'] : 'IN';
            $placeholder = '( ' . implode(', ', array_keys($arguments)) . ' )';
          }
          else {
            // With a single value, the '=' operator is implicit.
            $operator = !empty($info['operator']) ? $info['operator'] : '=';
            $placeholder = $view_query->placeholder('views_join_condition_');
            $arguments[$placeholder] = $info['value'];
          }
          $extras[] = "$join_table$info[field] $operator $placeholder";
        }
        elseif (is_string($info)) {
          $extras[] = $info;
        }
      }

      if ($extras) {
        if (count($extras) == 1) {
          $condition .= ' OR ' . array_shift($extras);
        }
        else {
          $condition .= ' OR (' . implode(' ' . $this->extra_type . ' ', $extras) . ')';
        }
      }
    }

    $select_query->addJoin($this->type, $right_table, $table['alias'], $condition, $arguments);
  }

}
