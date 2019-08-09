#!/usr/bin/env bash
#
# Refresh varnish cache.
#

site="$1"
target_env="$2"

LOCAL_VARIABLES_FILE="$HOME/refresh-environment-acquia.variables.$target_env.sh"

[ ! -f "$LOCAL_VARIABLES_FILE" ] && echo "Local variables file $LOCAL_VARIABLES_FILE does not exist" && exit 1

source /var/www/html/$site.$target_env/scripts/purge-cache-acquia.sh
