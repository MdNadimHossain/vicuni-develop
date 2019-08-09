# Behat content reports

The Behat content reports systems provides tests with the ability to run a
content type behat feature against a list of URLs, resulting in a text file
report listing the results of the feature per each URL.



## Setup

Two things are required for the behat content reports runner:

1. A list of URLs for the specified content type in the following file
   path/name and format:
   
   `tests/behat/features/fixtures/nodes/content_type.CONTENT_TYPE.txt`

   ```
   /URL
   /URL
   ```
   
   Note: `CONTENT_TYPE` must be the machine name of the content type, e.g.,
         `success_story`.

2. An Behat feature for the specific content type in the following file
   path/name containing the `When I visit a page of CONTENT TYPE content type`
   phrase:
   
  `tests/behat/features/content_type.CONTENT_TYPE.feature`



## Running

To run the Behat content reports runner you must have a provisioned development
environment.

Assuming that requirement has been met, run the following command from the root
of the project (e.g., ~/Sites/vicuni):

`vagrant ssh -c "/var/beetbox/scripts/behat-content.sh CONTENT_TYPE"`

Note: `CONTENT_TYPE` must be the machine name of the content type, e.g.,
      `success_story`.



## Results

At the conclusion of the runner, a report directory will be output to the
screen. This directory is the directory where the report and screenshots exists.
