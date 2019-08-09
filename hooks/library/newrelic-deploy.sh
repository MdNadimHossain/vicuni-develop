#!/bin/sh
#
# This sample a Cloud Hook script to update New Relic whenever there is a new code deployment

site=$1         # The site name. This is the same as the Acquia Cloud username for the site.
targetenv=$2    # The environment to which code was just deployed.
sourcebranch=$3 # The code branch or tag being deployed.
deployedtag=$4  # The code branch or tag being deployed.
repourl=$5      # The URL of your code repository.
repotype=$6     # The version control system your site is using; "git" or "svn".
settings_file="$HOME/newrelic_settings"

# Load the New Relic APPID and APPKEY variables.
if [ -e "$settings_file" ]; then
  . "$settings_file"
  curl -s -H "x-api-key:$NEWRELIC_APIKEY" -d "deployment[application_id]=$NEWRELIC_APPID" -d "deployment[host]=localhost" -d "deployment[description]=$deployedtag deployed to $site:$targetenv" -d "deployment[revision]=$deployedtag" -d "deployment[changelog]=$deployedtag deployed to $site:$targetenv" -d "deployment[user]=$NEWRELIC_USER"  https://api.newrelic.com/deployments.xml
fi
