<?php

/**
 * @file
 * Opt-in/opt-out form functionality.
 */

/**
 * Opt-in/opt-out form.
 */
function vu_rp_optin_form($form, &$form_state) {
  global $user;

  $email = variable_get('vu_rp_helpdesk_email');

  // Check that current user has staff id set in their user object.
  if (!vu_core_get_staff_id_by_uid($user->uid)) {
    $form['container_warning'] = [
      '#type' => 'container',
      '#attributes' => [
        'class' => ['frame-warning'],
      ],
    ];

    $markup_warning = t('<p>Looks like your account does not have a staff ID associated.</p>');

    if ($email) {
      $markup_warning .= t('<p>Please contact !email for assistance.</p>', [
        '!email' => l($email, 'mailto:' . $email),
      ]);
    }

    $form['container_warning']['markup'] = [
      '#markup' => $markup_warning,
    ];

    return $form;
  }

  $has_new_profile_node = (bool) vu_rp_lookup_researcher_profile_by_uid($user->uid);
  $has_old_profile_node = (bool) vu_core_get_staff_profile_by_uid($user->uid);

  // This form is always presented to the user, because we want to always
  // provide an option to opt-in/opt-out.
  // But it has different action buttons based on whether the node already
  // exists or not.
  $form['optin'] = [
    '#type' => 'radios',
    '#title' => t('Do you wish to:'),
    '#options' => [
      1 => t('Opt-in to have a VU researcher profile'),
      0 => t('Opt-out: I do NOT want a VU researcher profile at this time'),
    ],
    '#required' => TRUE,
    '#default_value' => vu_rp_optin_get_status($user),
  ];

  if ($has_new_profile_node) {
    $form['container_optin_link'] = [
      '#type' => 'container',
      '#attributes' => [
        'class' => ['frame-success'],
      ],
    ];

    $markup_optin = t('<h4>Thanks for opting in</h4>');
    $markup_optin .= t('<p>You can edit your profile using the link in the table above.</p>');
    if ($email) {
      $markup_optin .= t('<p>If you have questions or need assistance contact !email</p>', [
        '!email' => l($email, 'mailto:' . $email),
      ]);
    }
    $form['container_optin_link']['markup_optin_link'] = [
      '#markup' => $markup_optin,
    ];
    $form['container_optin_link']['submit_optin_link'] = [
      '#type' => 'submit',
      '#value' => t('Save your selection'),
      '#name' => 'submit_optin_link',
      '#submit' => ['vu_rp_optin_form_submit_optin_link'],
    ];
  }
  else {
    $form['container_optin_create'] = [
      '#type' => 'container',
      '#attributes' => [
        'class' => ['frame-success'],
      ],
    ];

    $markup_optin = t('<h4>Thanks for opting in</h4>');
    if ($email) {
      $markup_optin .= t('<p>If you have questions or need assistance contact !email</p>', [
        '!email' => l($email, 'mailto:' . $email),
      ]);
    }
    $form['container_optin_create']['markup_optin_create'] = [
      '#markup' => $markup_optin,
    ];
    $form['container_optin_create']['submit_optin_create'] = [
      '#type' => 'submit',
      '#value' => t('Create your researcher profile'),
      '#name' => 'submit_optin_create',
      '#submit' => ['vu_rp_optin_form_submit_optin_create'],
    ];
  }

  $form['container_optout'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['frame-success'],
    ],
  ];

  $markup = t('<h4>We’ve noted your preference to opt-out</h4><p>If you change your mind, you can login and change this setting at any time.</p>');
  if ($has_old_profile_node) {
    $markup .= "<p>We've detected you have an existing older style staff profile on the VU website.</p>";
    $markup .= '<p>As you have chosen to opt-out of having a researcher profile we will:</p>';
    $markup .= theme('item_list', [
      'items' => [
        "Leave the draft of your new researcher profile here in case you change your mind - don't worry it will not be published.",
        'Unpublish your existing staff profile.',
      ],
    ]);
  }
  $form['container_optout']['markup_optout'] = [
    '#markup' => $markup,
  ];
  $form['container_optout']['submit_optout'] = [
    '#type' => 'submit',
    '#value' => t('Save your selection'),
    '#name' => 'submit_optout',
    '#submit' => ['vu_rp_optin_form_submit_optout'],
  ];

  $form['container_optin_link']['#states']['visible'][':input[name="optin"]'] = ['value' => 1];
  $form['container_optin_create']['#states']['visible'][':input[name="optin"]'] = ['value' => 1];
  $form['container_optout']['#states']['visible'][':input[name="optin"]'] = ['value' => 0];

  return $form;
}

/**
 * Opt-in submit handler to create and link new profile.
 */
function vu_rp_optin_form_submit_optin_create($form, &$form_state) {
  global $user;

  $existing_node = vu_rp_lookup_researcher_profile_by_uid($user->uid);

  if (!$existing_node) {
    $staff_id = vu_core_get_staff_id_by_uid($user->uid);
    $created_nid = vu_rp_api_provision_profile($staff_id);

    if (!$created_nid) {
      drupal_set_message(t('Unable to create Research profile'), 'error');

      return;
    }
  }

  drupal_set_message(t('Research profile has been created'));
  vu_rp_optin_form_submit_optin_link($form, $form_state);
}

/**
 * Opt-in submit handler to link new profile.
 */
function vu_rp_optin_form_submit_optin_link($form, &$form_state) {
  global $user;

  try {
    vu_rp_optin_link_account_to_researcher_profile($user);
    drupal_set_message(t('Your selection has been saved'));
  }
  catch (Exception $exception) {
    drupal_set_message(t('Unable to update user profile'), 'error');
  }

  $existing_node = vu_rp_lookup_researcher_profile_by_uid($user->uid);
  $form_state['redirect'] = 'node/' . $existing_node->nid . '/edit';
  unset($_GET['destination']);
}

/**
 * Opt-in/opt-out form submit handler for Opt-out button.
 */
function vu_rp_optin_form_submit_optout($form, &$form_state) {
  global $user;

  try {
    vu_rp_optin_unlink_account_from_researcher_profile($user);
    drupal_set_message(t('Your selection has been saved'));

    $staff_profile_is_unpublished = (bool) vu_rp_optin_unpublish_staff_profile($user, t('Unpublished staff profile due to opt-out'));
    if ($staff_profile_is_unpublished) {
      drupal_set_message(t('Your old staff profile has been unpublished'));
    }

    $researcher_profile_is_unpublished = (bool) vu_rp_optin_unpublish_researcher_profile($user, t('Unpublished researcher profile due to opt-out'));
    if ($researcher_profile_is_unpublished) {
      drupal_set_message(t('Your researcher profile has been unpublished'));
    }
  }
  catch (Exception $exception) {
    watchdog('vu_rp', 'Unable to unlink account for user @uid', ['@uid' => $user->uid]);
  }
}
