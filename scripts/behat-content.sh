#!/usr/bin/env bash
#
# Run specified Behat content type feature with URLs from relevant file.
#
# Run from within VUBox.

# Root Behat tests directory.
BEHAT_TESTS_DIRECTORY=${BEHAT_TESTS_DIRECTORY:-tests/behat}
# Directory containing content type node lists.
BEHAT_CONTENT_NODES_DIRECTORY=${BEHAT_CONTENT_NODES_DIRECTORY:-tests/behat/features/fixtures/nodes}
# Directory containing content type test reports.
BEHAT_CONTENT_REPORTS_DIRECTORY=${BEHAT_CONTENT_REPORTS_DIRECTORY:-tests/behat/features/reports}

# Path in VM to app directory.
APP_DIR=${APP_DIR:-/var/beetbox}

################################################################################
#################### DO NOT CHANGE ANYTHING BELOW THIS LINE ####################
################################################################################

#
# Show help message.
#
show_help() {
  echo
  echo "Behat content type runner"
  echo
  cecho green "./behat-content.sh CONTENT_TYPE"
}

#
# Main entry point.
#
main() {
  # Ensure that script is run from within VUBox.
  if [ ! -d $APP_DIR ]; then
    secho error "Script needs to be run from within VUBox."
    exit 1
  fi

  # Ensure Behat tests directory exists.
  if [ ! -d "$APP_DIR/$BEHAT_TESTS_DIRECTORY" ]; then
    secho error "Behat tests directory '$APP_DIR/$BEHAT_TESTS_DIRECTORY' doesn't exist."
    exit 1
  fi
  cd $APP_DIR/$BEHAT_TESTS_DIRECTORY

  for i in "$@"
  do
    case $i in
      --help|help)
        show_help
        return
        ;;
      *)
        # Ensure that content type feature is present.
        if [ ! -f "$APP_DIR/$BEHAT_TESTS_DIRECTORY/features/content_type.$i.feature" ]; then
          secho error "Behat feature for content type '$i' missing; $APP_DIR/$BEHAT_TESTS_DIRECTORY/features/content_type.$i.feature"
          exit 1
        fi
        BEHAT_CONTENT_FEATURE="$APP_DIR/$BEHAT_TESTS_DIRECTORY/features/content_type.$i.feature"

        # Ensure that content type nodes list is present.
        if [ ! -f "$APP_DIR/$BEHAT_CONTENT_NODES_DIRECTORY/content_type.$i.txt" ]; then
          secho error "Nodes file for content type '$i' missing; $APP_DIR/$BEHAT_CONTENT_NODES_DIRECTORY/content_type.$i.txt"
          exit 1
        fi
        BEHAT_CONTENT_NODES_FILE="$APP_DIR/$BEHAT_CONTENT_NODES_DIRECTORY/content_type.$i.txt"

        # Report file.
        TIMESTAMP=`date +%Y-%m-%d.%H-%M-%S`;
        BEHAT_CONTENT_REPORT_DIRECTORY="$APP_DIR/$BEHAT_CONTENT_REPORTS_DIRECTORY/$i.$TIMESTAMP"
        BEHAT_COTNENT_REPORT_DIRECTORY_RELATIVE="$BEHAT_CONTENT_REPORTS_DIRECTORY/$i.$TIMESTAMP"
        BEHAT_CONTENT_REPORT_FILE="$BEHAT_CONTENT_REPORT_DIRECTORY/results.txt"
    esac
  done

  # Prepare report file.
  mkdir -p $BEHAT_CONTENT_REPORT_DIRECTORY
  touch $BEHAT_CONTENT_REPORT_FILE

  # Iterate over nodes list.
  while read URL; do
    # Append URL to report.
    secho status $URL

    # Run Behat for current URL.
    secho status $URL >> $BEHAT_CONTENT_REPORT_FILE
    BEHAT_SCREENSHOT_DIR=${BEHAT_CONTENT_REPORT_DIRECTORY} BEHAT_CONTENT_URL=${URL} behat ${BEHAT_CONTENT_FEATURE} --format=progress 2>&1 | tee -a $BEHAT_CONTENT_REPORT_FILE

    # Append some formatting to report.
    echo >> $BEHAT_CONTENT_REPORT_FILE
    echo >> $BEHAT_CONTENT_REPORT_FILE
  done < $BEHAT_CONTENT_NODES_FILE

  echo
  echo
  secho status "Report directory: $BEHAT_COTNENT_REPORT_DIRECTORY_RELATIVE"
}

#
# Status echo.
#
secho(){
  local type=$1
  local message=$2
  local quiet=$3

  if [ "$quiet" == 1 ] ; then
    return;
  fi

  case "$type" in
    status) cecho blue "==> $message";;
    error) cecho red "==> $message";;
    *) echo $message
  esac
}

#
# Colored echo.
#
cecho() {
  local prefix="\033["
  local input_color=$1
  local message="$2"

  local color=""
  case "$input_color" in
    black  | bk) color="${prefix}0;30m";;
    red    |  r) color="${prefix}1;31m";;
    green  |  g) color="${prefix}1;32m";;
    yellow |  y) color="${prefix}1;33m";;
    blue   |  b) color="${prefix}1;34m";;
    purple |  p) color="${prefix}1;35m";;
    cyan   |  c) color="${prefix}1;36m";;
    gray   | gr) color="${prefix}0;37m";;
    *) message="$1"
  esac

  # Format message with color codes, but only if in terminal and a correct color
  # was provided.
  [ -t 1 ] && [ -n "$color" ] && message="${color}${message}${prefix}0m"

  echo -e "$message"
}

main "$@"
