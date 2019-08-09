#!/usr/bin/env python
try:
  import urllib.request as urllib2
except ImportError:
  import urllib2
import json
import os
import sys

EXIT_FULL_BUILD=0
EXIT_LIMITED_BUILD=1

# These branches require a full build
full_build_branch_prefixes=['master', 'develop', 'release']

# Set in circle env vars
if not os.environ.get('GITHUB_OAUTH_PR_TOKEN'):
  print('No OAUTH token found...defaulting to run full build.')
  sys.exit(EXIT_FULL_BUILD)

# Set by CircleCI
if os.environ.get('CIRCLE_BRANCH') is not None and any(os.environ.get('CIRCLE_BRANCH').startswith(s) for s in full_build_branch_prefixes):
  print('Full build required for master, develop and release branches.')
  sys.exit(EXIT_FULL_BUILD)

# Set in should-run-full-suite.sh script
if os.environ.get('GIT_COMMIT_MESSAGE') is not None and "full-build" in os.environ.get('GIT_COMMIT_MESSAGE').lower():
  print('full-build keyword specified in commit message')
  sys.exit(EXIT_FULL_BUILD)

# Set by CircleCI
if os.environ.get('CI_PULL_REQUESTS') is None or not os.environ.get('CI_PULL_REQUESTS'):
  sys.exit(EXIT_LIMITED_BUILD)

# CI_PULL_REQUESTS is a list of github URLs seperated by commas.
for linked_pull_request in os.environ.get('CI_PULL_REQUESTS').split(','):
  # Last part of the URL is the PR ID github.com/.../pull/[ID].
  pr_id = linked_pull_request.rpartition('/')[2]
  url = 'https://api.github.com/repos/vu-web-services/vicuni/pulls/' + pr_id
  # OATH token requires private repo access.
  headers = {'Accept': 'application/vnd.github.v3+json', 'Authorization': 'token {0}'.format(os.environ.get('GITHUB_OAUTH_PR_TOKEN'))}
  req = urllib2.Request(url, headers=headers)
  try:
    response = urllib2.urlopen(req)
    pr_string = response.read()
    pr = json.loads(pr_string)
    # We want to run tests for any PR against develop, master or a release branch.
    if any(pr['base']['ref'].startswith(s) for s in full_build_branch_prefixes):
      print("Tests need to be built, branch is against: {0}".format(pr['base']['ref']))
      sys.exit(EXIT_FULL_BUILD)

    # Also run full build if it's a protected branch.
    headers = {'Accept': 'application/vnd.github.loki-preview+json', 'Authorization': 'token {0}'.format(os.environ.get('GITHUB_OAUTH_PR_TOKEN'))}
    url = 'https://api.github.com/repos/vu-web-services/vicuni/branches/{0}'.format(pr['base']['ref'])
    req = urllib2.Request(url, headers=headers)
    try:
      response = urllib2.urlopen(req)
      protection_string = response.read()
      protection = json.loads(protection_string)
      if protection.get('protected', False):
        print("Tests need to be built, branch {0} is protected.".format(pr['base']['ref']))
        sys.exit(EXIT_FULL_BUILD)
    except urllib2.URLError as e:
      print('Error fetching branch protection. Requested: {0}. Running full suite.'.format(url))
      sys.exit(EXIT_FULL_BUILD)

  except urllib2.URLError as e:
    print('Error fetching pull request: {0}. Running full suite.'.format(url))
    sys.exit(EXIT_FULL_BUILD)
# If we get here, no need to run full build
sys.exit(EXIT_LIMITED_BUILD)
