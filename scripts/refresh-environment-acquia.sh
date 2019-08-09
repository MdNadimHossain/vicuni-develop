#!/usr/bin/env bash
##
# Master script to refresh Acquia environment.
#
# Used as a pipeline to run all required actions to refresh
# Acquia environment.
#

# File with per-environment local variables to include.
LOCAL_VARIABLES_FILE=${LOCAL_VARIABLES_FILE:-}

# An alias of the environment to refresh.
DST_DRUSH_ALIAS=${DST_DRUSH_ALIAS:-}

# Refresh steps.
STEP_COPY_FILES=${STEP_COPY_FILES:-1}
STEP_COPY_DB=${STEP_COPY_DB:-1}
STEP_MAINTENANCE_MODE=${STEP_MAINTENANCE_MODE:-1}
STEP_DB_UPDATES=${STEP_DB_UPDATES:-1}
STEP_RESEARCHER_PROFILE_DEMO=${STEP_RESEARCHER_PROFILE_DEMO:-1}
STEP_SEARCH_INDEX=${STEP_SEARCH_INDEX:-1}
STEP_VARNISH_CACHE_PURGE=${STEP_VARNISH_CACHE_PURGE:-1}

SELF_START_TIME_TOTAL=0

# Find absolute script path.
SELF_DIR=$(dirname -- $0)
SELF_PATH=$(cd -P -- "$SELF_DIR" && pwd -P)/$(basename -- $0)
SCRIPTS_DIR=${SCRIPTS_DIR:-$(dirname $SELF_PATH)}

# Include file with local variables.
[ -f "$LOCAL_VARIABLES_FILE" ] && source $LOCAL_VARIABLES_FILE

[ "$DST_DRUSH_ALIAS" == "" ] && echo "##### ERROR: Destination drush alias is not provided" && exit 1

################################################################################
############################## REFRESH TASKS ###################################
################################################################################

echo "#####"
echo "##### STARTING ENVIRONMENT REFRESH"
echo "##### ALIAS: $DST_DRUSH_ALIAS"
echo "#####"

if [ "$STEP_COPY_FILES" == "1" ]; then
  echo "#####"
  echo "##### COPY FILES STARTED"
  echo "#####"
  source $SCRIPTS_DIR/copy-files-acquia.sh
  echo "#####"
  echo "##### COPY FILES FINISHED"
  echo "#####"
fi

if [ "$STEP_COPY_DB" == "1" ]; then
  echo "#####"
  echo "##### COPY DB STARTED"
  echo "#####"
  source $SCRIPTS_DIR/copy-db-acquia.sh
  echo "#####"
  echo "##### COPY DB FINISHED"
  echo "#####"
fi

if [ "$STEP_MAINTENANCE_MODE" == "1" ]; then
  echo "#####"
  echo "##### ENABLING MAINTENANCE MODE STARTED"
  echo "#####"
  drush $DST_DRUSH_ALIAS vset --format=boolean maintenance_mode 1
  echo "#####"
  echo "##### ENABLING MAINTENANCE MODE FINISHED"
  echo "#####"
fi

echo "#####"
echo "##### CACHE CLEAR STARTED"
echo "#####"
echo flush_all | nc staging-15527.prod.hosting.acquia.com 11211
drush $DST_DRUSH_ALIAS cc all
echo "#####"
echo "##### CACHE CLEAR FINISHED"
echo "#####"

if [ "$STEP_DB_UPDATES" == "1" ]; then
  echo "#####"
  echo "##### DB UPDATES STARTED"
  echo "#####"
  drush $DST_DRUSH_ALIAS updb --yes
  echo "#####"
  echo "##### DB UPDATES FINISHED"
  echo "#####"
fi

if [ "$STEP_SEARCH_INDEX" == "1" ]; then
  echo "#####"
  echo "##### SEARCH INDEX STARTED"
  echo "#####"
  drush $DST_DRUSH_ALIAS search-api-clear
  drush $DST_DRUSH_ALIAS search-api-index
  echo "#####"
  echo "##### SEARCH INDEX FINISHED"
  echo "#####"
fi

if [ "$STEP_MAINTENANCE_MODE" == "1" ]; then
  echo "#####"
  echo "##### DISABLING MAINTENANCE MODE STARTED"
  echo "#####"
  drush $DST_DRUSH_ALIAS vset --format=boolean maintenance_mode 0
  echo "#####"
  echo "##### DISABLING MAINTENANCE MODE FINISHED"
  echo "#####"
fi

if [ "$STEP_VARNISH_CACHE_PURGE" == "1" ]; then
  echo "#####"
  echo "##### VARNISH CACHE PURGE STARTED"
  echo "#####"
  source $SCRIPTS_DIR/purge-cache-acquia.sh
  echo "#####"
  echo "##### VARNISH CACHE PURGE FINISHED"
  echo "#####"
fi

if [ "$STEP_RESEARCHER_PROFILE_DEMO" == "1" ]; then
  echo "#####"
  echo "##### RESEARCHER PROFILE DEMO PROVISIONING STARTED"
  echo "#####"
  drush $DST_DRUSH_ALIAS vu-rp-provision all
  echo "#####"
  echo "##### RESEARCHER PROFILE DEMO PROVISIONING FINISHED"
  echo "#####"
fi

SELF_ELAPSED_TIME=$(($SECONDS - $SELF_START_TIME_TOTAL))
echo "##### GRAND TOTAL BUILD DURATION: $(($SELF_ELAPSED_TIME/60)) min $(($SELF_ELAPSED_TIME%60)) sec"


