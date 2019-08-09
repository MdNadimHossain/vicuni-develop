#!/usr/bin/env bash
##
# Deploy code in Acquia.
# @see https://cloudapi.acquia.com/#POST__sites__site_envs__env_code_deploy-instance_route

DEPLOY_API_USER_NAME=${DEPLOY_API_USER_NAME:-}
DEPLOY_API_USER_PASS=${DEPLOY_API_USER_PASS:-}
DEPLOY_API_CODE_SITE=${DEPLOY_API_CODE_SITE:-}
DEPLOY_API_CODE_ENV=${DEPLOY_API_CODE_ENV:-}
# Full branch name or 'tags/tagname'.
DEPLOY_API_CODE_PATH=${DEPLOY_API_CODE_PATH:-}

# Number of status retrieval retries. If this limit reached and task has not
# yet finished, the task is considered failed.
DEPLOYMENT_STATUS_RETRIES=10
# Interval in seconds to check task status.
DEPLOYMENT_STATUS_INTERVAL=5
################################################################################
#################### DO NOT CHANGE ANYTHING BELOW THIS LINE ####################
################################################################################
SELF_START_TIME=0
TIMESTAMP=$(date '+%Y-%m-%d %H:%M:%S')

# Find absolute script path.
SELF_DIR=$(dirname -- $0)
SELF_PATH=$(cd -P -- "$SELF_DIR" && pwd -P)/$(basename -- $0)

# Find absolute project root.
PROJECT_PATH=$(dirname $(dirname $(dirname $SELF_PATH)))

# Set DB dump file, dirname and compressed file name.
DB_DUMP=${DB_DUMP:-$PROJECT_PATH/.data/db.sql}
DB_DUMP_DIR=$(dirname $DB_DUMP)
DB_DUMP_COMPRESSED=$DB_DUMP.gz

which curl > /dev/null ||  {
  echo "==> curl is not available in this session" && exit 1
}

if [ "$DEPLOY_API_USER_NAME" == "" ] || [ "$DEPLOY_API_USER_PASS" == "" ] || [ "$DEPLOY_API_CODE_SITE" == "" ]  || [ "$DEPLOY_API_CODE_ENV" == "" ]  || [ "$DEPLOY_API_CODE_PATH" == "" ] ; then
  echo "==> Missing required parameter(s)" && exit 1
fi

# Function to extract value from JSON object passed via STDIN.
extract_json_value() {
  local key=$1
  php -r '$data=json_decode(file_get_contents("php://stdin"), TRUE); print $data["'$key'"];'
}

echo "==> Checking currently deployed branch in environment $DEPLOY_API_CODE_ENV"
ENV_STATUS_JSON=$(curl --progress-bar -s -u $DEPLOY_API_USER_NAME:$DEPLOY_API_USER_PASS https://cloudapi.acquia.com/v1/sites/$DEPLOY_API_CODE_SITE/envs/$DEPLOY_API_CODE_ENV.json)
CURRENT_BRANCH=$(echo $ENV_STATUS_JSON | extract_json_value "vcs_path")
[ "$CURRENT_BRANCH" == "$DEPLOY_API_CODE_PATH" ] && echo "==> Skipping code deployment as branch $CURRENT_BRANCH already deployed" && exit 0

echo "==> Deploying code $DEPLOY_API_CODE_PATH to environment $DEPLOY_API_CODE_ENV"
TASK_STATUS_JSON=$(curl --progress-bar -s -u $DEPLOY_API_USER_NAME:$DEPLOY_API_USER_PASS -X POST https://cloudapi.acquia.com/v1/sites/$DEPLOY_API_CODE_SITE/envs/$DEPLOY_API_CODE_ENV/code-deploy.json?path=$DEPLOY_API_CODE_PATH)
DEPLOYMENT_TASK_ID=$(echo $TASK_STATUS_JSON | extract_json_value "id")

echo -n "==> Checking code deployment status: "
TASK_COMPLETED=0
for i in `seq 1 $DEPLOYMENT_STATUS_RETRIES`;
do
  echo -n "."
  sleep $DEPLOYMENT_STATUS_INTERVAL
  TASK_STATUS_JSON=$(curl --progress-bar -s -u $DEPLOY_API_USER_NAME:$DEPLOY_API_USER_PASS https://cloudapi.acquia.com/v1/sites/$DEPLOY_API_CODE_SITE/tasks/$DEPLOYMENT_TASK_ID.json)
  TASK_STATE=$(echo $TASK_STATUS_JSON | extract_json_value "state")
  [ "$TASK_STATE" == "done" ] && TASK_COMPLETED=1 && break
done
echo

if [ $TASK_COMPLETED == 0 ] ; then
 echo "==> Unable to deploy code $DEPLOY_API_CODE_PATH into environment $DEPLOY_API_CODE_ENV"
 exit 1
fi

echo "==> Checking currently deployed branch in environment $DEPLOY_API_CODE_ENV"
ENV_STATUS_JSON=$(curl --progress-bar -s -u $DEPLOY_API_USER_NAME:$DEPLOY_API_USER_PASS https://cloudapi.acquia.com/v1/sites/$DEPLOY_API_CODE_SITE/envs/$DEPLOY_API_CODE_ENV.json)
CURRENT_BRANCH=$(echo $ENV_STATUS_JSON | extract_json_value "vcs_path")
[ "$CURRENT_BRANCH" != "$DEPLOY_API_CODE_PATH" ] && echo "==> Unable to deploy code $DEPLOY_API_CODE_PATH into environment $DEPLOY_API_CODE_ENV" && exit 1

echo "==> Successfully deployed code $DEPLOY_API_CODE_PATH into environment $DEPLOY_API_CODE_ENV"

SELF_ELAPSED_TIME=$(($SECONDS - $SELF_START_TIME))
echo "==> Build duration: $(($SELF_ELAPSED_TIME/60)) min $(($SELF_ELAPSED_TIME%60)) sec"
