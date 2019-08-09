#!/usr/bin/env bash

ISSUES=${ISSUES:-1}
AWK_BIN=$(which gawk)
[ -z "$AWK_BIN" ] && AWK_BIN=$(which awk)
[ -z "$AWK_BIN" ] && exit 1

PR_BASE=$(scripts/ci/github-pr-exists-for-branch.py|grep 'PR Base:'|cut -d':' -f2)
[ -z "$PR_BASE" ] && PR_BASE="develop"

# Ensure that the remote branch list is up to date.
git fetch --all > /dev/null

# Get JIRA issues associated with this commit. Outputs like @PW-1234,@PW-1235
COMMIT_ISSUE_IDS=$(git log --pretty=%B --first-parent ${PR_BASE}.. |${AWK_BIN} '{
for (i=1; i<=NF; i++) {
  if (match($i, /PW-[0-9]{3,7}/)) {
    print "@"substr($i, RSTART, RLENGTH)
  }
}
}'|sort -t'-' -n -k2 -u|tr '\n' ','|sed 's/,$//g')

# If we want the issue tags (step one) print out parameter.
if [ "$ISSUES" != "0" ]; then
  # No issues found in commit.
  [ -z "$COMMIT_ISSUE_IDS" ] && exit 1
  TAG_FOUND=0
  # Just make a \n separated list to loop through.
  COMMIT_ISSUE_LIST=$(echo -n "$COMMIT_ISSUE_IDS"|tr ',' '\n')
  while read -r LINE; do
    # Skip blank lines.
    if [ "$LINE" == "" ]; then
      continue
    fi
    # If we find at least one match...then we should run tests.
    if [ -n "$(find tests/behat -name '*.feature' -exec grep -E \"${LINE}\" '{}' \;| head -n 1)" ]; then
      TAG_FOUND=1
      break;
    fi
  done <<< "$COMMIT_ISSUE_LIST"
  # If nothing was found, there's no need to run tag based tests.
  if [ "$TAG_FOUND" != "1" ]; then
    exit 1
  fi
  echo -n "--tags=$COMMIT_ISSUE_IDS"
# This is for the feature files, there might be no tests to run.
else
  # Find changed features.
  COMMIT_FEATURES_CHANGED=$(git log --pretty='' --name-only --first-parent ${PR_BASE}.. |grep '.feature$'|sort -u|xargs)
  # Find changes to test framework/bootstrap.
  BOOTSTRAP_CHANGES=$(git log --pretty='' --name-only --first-parent ${PR_BASE}.. |grep -n0 '^tests/behat/features/bootstrap' ; echo $?)
  # Make the issue as tags to exclude because we've already run them explicitly.
  NEGATED_ISSUE_IDS=$(echo -n $COMMIT_ISSUE_IDS|sed 's/@/~@/g')
  NEGATED_ISSUE_PARAM=""
  if [ -n "$NEGATED_ISSUE_IDS" ]; then
    NEGATED_ISSUE_PARAM="--tags=$NEGATED_ISSUE_IDS"
  fi

  # If there was bootstrap changes, run the rest of the tests (negated tags).
  [ "$BOOTSTRAP_CHANGES" == "0" ] && echo -n "$NEGATED_ISSUE_PARAM" && exit 0

  # If the features haven't changed either, then we don't need to run.
  [ -z "$COMMIT_FEATURES_CHANGED" ] && exit 1

  # Run the found feature changes, but don't run the tags we already have tested.
  echo -n "$NEGATED_ISSUE_PARAM -- $COMMIT_FEATURES_CHANGED"
fi
