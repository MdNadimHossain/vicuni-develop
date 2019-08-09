#!/usr/bin/env bash
###
# Environment setup
###
FULL_SUITE_CACHE_FILE="./full_suite_$CIRCLE_SHA1"
if [ -f "$FULL_SUITE_CACHE_FILE" ]; then
    read FULL_SUITE < "$FULL_SUITE_CACHE_FILE"
    exit $FULL_SUITE
fi
export GIT_COMMIT_MESSAGE=$(git log -1 --pretty=%B)
python scripts/ci/github-pr-base-check.py
FULL_SUITE=$?
echo $FULL_SUITE > "$FULL_SUITE_CACHE_FILE"
exit $FULL_SUITE
