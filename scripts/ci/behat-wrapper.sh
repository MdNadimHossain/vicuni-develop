#!/usr/bin/env bash
if ./scripts/ci/should-run-full-suite.sh ; then
  BEHAT_PROFILE=ci
  if [ "$CIRCLE_NODE_TOTAL" -gt "1" ] ; then
    BEHAT_PROFILE="cip$CIRCLE_NODE_INDEX"
  fi
  [ "$TESTS_BEHAT" != "" ] && composer test-behat -- -p $BEHAT_PROFILE || composer test-behat -- -p $BEHAT_PROFILE --rerun
else
  RUN_TAG_BASED_TESTS=1
  RUN_FEATURE_BASED_TESTS=1

  # This just runs the tests on different containers if available.
  if [ "$CIRCLE_NODE_TOTAL" -gt "1" ] ; then
    if [ "$CIRCLE_NODE_INDEX" -gt "0" ] ; then
      RUN_TAG_BASED_TESTS=0
      RUN_FEATURE_BASED_TESTS=1
    else
      RUN_TAG_BASED_TESTS=1
      RUN_FEATURE_BASED_TESTS=0
    fi
  fi

  if [ "$RUN_TAG_BASED_TESTS" -gt "1" ] ; then
    # Run once for tags/issue numbers [PW-XXX].
    ISSUE_TAGS=$(ISSUES=1 ./scripts/ci/generate-test-params.sh)
    if [ $? -eq 0 ]; then
      [ "$TESTS_BEHAT" != "" ] && composer test-behat -- -p ci $ISSUE_TAGS || composer test-behat -- -p ci $ISSUE_TAGS --rerun
    fi
  fi
  if [ "$RUN_FEATURE_BASED_TESTS" -gt "1" ] ; then
    # Run once for changed features, excluding above tags.
    FEATURE_PARAMS=$(ISSUES=0 ./scripts/ci/generate-test-params.sh)
    if [ $? -eq 0 ]; then
      [ "$TESTS_BEHAT" != "" ] && composer test-behat -- -p ci $FEATURE_PARAMS || composer test-behat -- -p ci $FEATURE_PARAMS --rerun
    fi
  fi
fi
