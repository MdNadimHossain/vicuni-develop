#!/usr/bin/env python
try:
  import urllib.request as urllib2
except ImportError:
  import urllib2
import json
import base64
import os
import sys

full_build_branch_prefixes=['master', 'develop', 'release']

EXIT_PR_NOT_FOUND=0
EXIT_PR_FOUND=1

# Set in circle env vars
if not os.environ.get('GITHUB_OAUTH_PR_TOKEN'):
  print('No OAUTH token found...exiting without error.')
  sys.exit(EXIT_PR_NOT_FOUND)

# Set by CircleCI
if not os.environ.get('CIRCLE_BRANCH'):
  print('No CIRCLE_BRANCH...exiting without error.')
  sys.exit(EXIT_PR_NOT_FOUND)

# Set by CircleCI
if not os.environ.get('CIRCLE_BUILD_URL'):
  print('No CIRCLE_BUILD_URL...exiting without error.')
  sys.exit(EXIT_PR_NOT_FOUND)

# Set in circle env vars
if not os.environ.get('CIRCLE_CI_REBUILD_TOKEN'):
  print('No CIRCLE_CI_REBUILD_TOKEN...exiting without error.')
  sys.exit(EXIT_PR_NOT_FOUND)

# Find PRs for branch
url = 'https://api.github.com/repos/vu-web-services/vicuni/pulls'
# OATH token requires private repo access.
headers = {'Accept': 'application/vnd.github.v3+json', 'Authorization': 'token {0}'.format(os.environ.get('GITHUB_OAUTH_PR_TOKEN'))}
req = urllib2.Request(url, headers=headers)
try:
  response = urllib2.urlopen(req)
  pr_string = response.read()
  pull_requests = json.loads(pr_string)
  # Loop through all open PRs
  for pull_request in pull_requests:
    # Does the branch match the one we're currently on?
    if pull_request['head']['label'] == '{0}:{1}'.format('vu-web-services', os.environ.get('CIRCLE_BRANCH')):
      print('PR Base:origin/{0}'.format(pull_request['base']['ref']))
      # Are we trying to do a PR into one of the 'important' branches?
      if any(pull_request['base']['ref'].startswith(s) for s in full_build_branch_prefixes):
        print('Pull request found for branch.')
        sys.exit(EXIT_PR_FOUND)
      # Also notify if the PR is against a protected branch.
      protection_headers = {'Accept': 'application/vnd.github.loki-preview+json', 'Authorization': 'token {0}'.format(os.environ.get('GITHUB_OAUTH_PR_TOKEN'))}
      protection_url = 'https://api.github.com/repos/vu-web-services/vicuni/branches/{0}'.format(pull_request['base']['ref'])
      protection_req = urllib2.Request(protection_url, headers=protection_headers)
      try:
        protection_response = urllib2.urlopen(protection_req)
        protection_string = protection_response.read()
        protection = json.loads(protection_string)
        if protection.get('protected', False):
          print("Pull request found against protected branch.".format(pull_request['base']['ref']))
          sys.exit(EXIT_PR_FOUND)
      except urllib2.URLError as e:
        print('Error fetching branch protection. Requested: {0}.'.format(url))
        sys.exit(EXIT_PR_FOUND)
except urllib2.URLError as e:
  print('Error fetching pull request: {0}. Exiting without error.'.format(url))
  sys.exit(EXIT_PR_NOT_FOUND)
print('No matching PR found. Exiting without error.')
sys.exit(EXIT_PR_NOT_FOUND)
