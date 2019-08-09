# Enquire Now

This module integrates enquiry forms on course pages with RightNow.
The integration depends on a specific configuration of [Boomi][1] middleware.

The workflow is as follows:

1. Form is rendered into course page
2. User submits form
3. Results are queued in Drupal database
4. Boomi periodically requests an update from Drupal at /boomi
5. Queued form submissions are sent in response as XML
6. Sent form submissions are removed from the queue

## Boomi
**Boomi** expects XML input in the following format:

    <form-submissions>

      <form-submission>
        <first-name>$first_name</first-name>
        <last-name>$last_name</last-name>
        <email>$email_address</email>
        <phone>$phone</phone>
        <course>$course_code</course>
        <school>$school_name</school>
        <comment>$question</comment>
      </form-submission>

      <form-submission>
        ...
      </form-submission>

    </form-submissions>

[1]: http://www.boomi.com/