#!/usr/bin/env bash
#
# Refresh environment.
#

site="$1"
target_env="$2"

LOCAL_VARIABLES_FILE="$HOME/refresh-environment-acquia.variables.$target_env.sh"
SCRIPTS_DIR=/var/www/html/$site.$target_env/scripts
HOOKS_DIR=/var/www/html/$site.$target_env/hooks

# Disable some steps.
STEP_LEGACY_DB_IMPORT=0
STEP_COPY_FILES=0
STEP_SEARCH_INDEX=0

[ ! -f "$LOCAL_VARIABLES_FILE" ] && echo "Local variables file $LOCAL_VARIABLES_FILE does not exist" && exit 1

source $SCRIPTS_DIR/refresh-environment-acquia.sh
