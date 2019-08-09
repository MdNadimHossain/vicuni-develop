#!/usr/bin/env bash

# Read from cached result if available.
BOOTSTRAP_CACHE_FILE="./bootstrap_$CIRCLE_SHA1"
if [ -f "$BOOTSTRAP_CACHE_FILE" ]; then
    read SHOULD_BOOTSTRAP < "$BOOTSTRAP_CACHE_FILE"
    exit $SHOULD_BOOTSTRAP
fi

# Default to error/false.
SHOULD_BOOTSTRAP=1

# If full suite is required, bootstrap.
scripts/ci/should-run-full-suite.sh > /dev/null && echo "Build level: Full" && SHOULD_BOOTSTRAP=0

if [ "0" != "$SHOULD_BOOTSTRAP" ]; then
  # See if there are any tests that match the issue number.
 ISSUES=1 scripts/ci/generate-test-params.sh > /dev/null && echo "Build level: Limited" && SHOULD_BOOTSTRAP=0
fi

if [ "0" != "$SHOULD_BOOTSTRAP" ]; then
  # See if the test bootstrap or any .feature file has changed.
  ISSUES=0 scripts/ci/generate-test-params.sh > /dev/null && echo "Build level: Limited" && SHOULD_BOOTSTRAP=0
fi

if [ "0" != "$SHOULD_BOOTSTRAP" ]; then
  # No bootstrap required for cs checking.
  echo "Build level: Coding standards only (no build)."
fi
# Save result to the cache file.
echo $SHOULD_BOOTSTRAP > "$BOOTSTRAP_CACHE_FILE"
exit $SHOULD_BOOTSTRAP
