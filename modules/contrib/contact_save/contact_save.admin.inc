<?php
// $Id: contact_save.admin.inc,v 1.16 2010/10/26 21:27:21 joelstein Exp $

/**
 * Displays contact form submissions.
 */
function contact_save_submissions(&$form_state, $account = NULL) {

  $sql_conditions = '';
  $args = array();

  // If at "user/%user/contact_save", restrict to recipient-specific messages
  if (arg(0) == 'user') {
    $sql_conditions .= " AND cs.recipients LIKE '%%%s%%'";
    $args[] = $account->mail;
  }

  // Get all available categories
  $categories = array(1 => t('<all categories>'), 0 => t('<n/a>'));
  $result = db_query("SELECT DISTINCT(cs.category) FROM {contact_save} cs WHERE cs.category IS NOT NULL $sql_conditions ORDER BY cs.category", $args);
  while ($row = db_fetch_object($result)) {
    $categories[$row->category] = $row->category;
  }

  // Get category from session (but only if it matches an available category)
  $category = (isset($_SESSION['contact_save_category']) and isset($categories[$_SESSION['contact_save_category']])) ? $_SESSION['contact_save_category'] : 1;

  // Category filter (if any categories exist)
  if (count($categories) > 2) {
    $form['options'] = array(
      '#type' => 'fieldset',
      '#prefix' => '<div class="container-inline">',
      '#suffix' => '</div>',
    );
    $form['options']['category_filter'] = array(
      '#type' => 'select',
      '#title' => t('Category'),
      '#options' => $categories,
      '#default_value' => $category,
    );
    $form['options']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Filter'),
    );
  }

  // Build sql query, with header, and tablesort
  $sql = "SELECT cs.id, cs.created, cs.name, cs.uid, cs.subject, cs.cid, cs.category, cs.replied, c.category AS c_category, u.name AS u_name
    FROM {contact_save} cs
    LEFT JOIN {contact} c ON cs.cid = c.cid
    LEFT JOIN {users} u ON cs.uid = u.uid";
  $limit = 20;
  $header = array(
    // @TODO: bulk delete
    // '',
    array('data' => t('Date'), 'field' => 'cs.created', 'sort' => 'desc'),
    array('data' => t('Subject'), 'field' => 'cs.subject'),
    array('data' => t('Name'), 'field' => 'cs.name'),
    array('data' => t('Category'), 'field' => 'cs.category'),
    array('data' => t('Replied'), 'field' => 'cs.replied'),
    array('data' => t('Operations'), 'colspan' => 2),
  );
  $form['#header'] = $header;
  $tablesort = tablesort_sql($header);

  // Apply filter (if necessary)
  if (is_numeric($category)) {
    if ($category == 0) {
      $sql_conditions .= " AND cs.category IS NULL";
    }
  } else {
    $sql_conditions .= " AND cs.category = '%s'";
    $args[] = $category;
  }

  // Merge conditions
  if ($sql_conditions) {
    $sql .= " WHERE 1=1 $sql_conditions";
  }

  // Get query results
  $result = pager_query($sql . $tablesort, $limit, 0, NULL, $args);

  // Save array of submissions in $form for future rendering
  $submissions = array();
  while ($submission = db_fetch_object($result)) {
    // @TODO: bulk delete
    // $submissions[$submission->id] = '';
    $form['created-date'][$submission->id] = array('#value' => _contact_save_format_field('created-date', $submission));
    $form['subject'][$submission->id] = array('#value' => _contact_save_format_field('subject', $submission));
    $form['name'][$submission->id] = array('#value' => _contact_save_format_field('name', $submission));
    $form['category'][$submission->id] = array('#value' => _contact_save_format_field('category', $submission));
    $form['replied-date'][$submission->id] = array('#value' => _contact_save_format_field('replied-date', $submission));
    $form['view'][$submission->id] = array('#value' => l(t('view'), _contact_save_path($submission->id)));
    $form['delete'][$submission->id] = array('#value' => l(t('delete'), _contact_save_path($submission->id . '/delete'), array('query' => array('destination' => _contact_save_path()))));
  }
  $form['submissions'] = array('#type' => 'checkboxes', '#options' => $submissions);
  $form['pager'] = array('#value' => theme('pager', NULL, $limit, 0));
  return $form;
}

/**
 * Submissions theme function.
 */
function theme_contact_save_submissions($form) {
  $output = drupal_render($form['options']);
  if (!empty($form['subject'])) {
    // @TODO: bulk delete
    // $form['#header'][0] = theme('table_select_header_cell');
    foreach (element_children($form['category']) as $key) {
      $rows[] = array(
        // @TODO: bulk delete
        // drupal_render($form['submissions'][$key]),
        drupal_render($form['created-date'][$key]),
        drupal_render($form['subject'][$key]),
        drupal_render($form['name'][$key]),
        drupal_render($form['category'][$key]),
        drupal_render($form['replied-date'][$key]),
        drupal_render($form['view'][$key]),
        drupal_render($form['delete'][$key]),
      );
    }
  } else {
    // @TODO: bulk delete
    // $rows[] = array(array('data' => t('No contact form submissions have been made yet.'), 'colspan' => 8));
    $rows[] = array(array('data' => t('No contact form submissions have been made yet.'), 'colspan' => 7));
  }

  $output .= theme('table', $form['#header'], $rows);
  unset($form['#header']);
  $output .= drupal_render($form['pager']);
  $output .= drupal_render($form);
  return $output;
}

/**
 * Submit function submissions page.
 */
function contact_save_submissions_submit($form, &$form_state) {
  // Save filter in session
  $_SESSION['contact_save_category'] = $form_state['values']['category_filter'];
}

/**
 * View a contact form submissions.
 */
function contact_save_view_submission(&$form_state, $id) {
  drupal_add_css(drupal_get_path('module', 'contact_save') . '/contact_save.css');

  $submission = db_fetch_object(db_query("SELECT cs.*, c.category AS c_category, u.name AS u_name, r.name AS r_name
    FROM {contact_save} cs
    LEFT JOIN {contact} c ON cs.cid = c.cid
    LEFT JOIN {users} u ON cs.uid = u.uid
    LEFT JOIN {users} r ON cs.replier = r.uid
    WHERE cs.id = %d", $id));

  // Show message details.
  $args = array(
    '!name' => _contact_save_format_field('name', $submission),
    '!email' => _contact_save_format_field('email', $submission),
    '!created' => _contact_save_format_field('created', $submission),
    '!category' => _contact_save_format_field('category', $submission),
    '!recipients' => _contact_save_format_field('recipients', $submission),
  );
  $output = '<div class="contact-save-submitted">' . t('Submitted by !name (!email) on !created in the category !category, which should have been received by !recipients.', $args) . '</div>';
  $output .= '<div class="contact-save-message">' . _contact_save_format_field('message', $submission) . '</div>';
  $form['message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message'),
    '#collapsible' => TRUE,
  );
  $form['message']['value'] = array(
    '#value' => $output,
  );

  // Show full message body.
  if (!empty($submission->body)) {
    $form['body'] = array(
      '#type' => 'fieldset',
      '#title' => t('Full message body'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['body']['value'] = array(
      '#value' => '<div class="contact-save-body">' . _contact_save_format_field('body', $submission) . '</div>',
    );
  }

  // Show reply (if already replied).
  if ($submission->reply) {
    $args = array(
      '!replier' => _contact_save_format_field('replier', $submission),
      '!replied' => _contact_save_format_field('replied', $submission),
    );
    $output = '<div class="contact-save-replied">' . t('Submitted by !replier on !replied.', $args) . '</div>';
    $output .= '<div class="contact-save-reply">' . _contact_save_format_field('reply', $submission) . '</div>';
    $form['reply'] = array(
      '#type' => 'fieldset',
      '#title' => t('Reply'),
      '#collapsible' => TRUE,
    );
    $form['reply']['value'] = array(
      '#value' => $output,
    );
  }

  // Show reply form (if no reply exists).
  if (!$submission->reply) {
    $form['reply'] = array(
      '#type' => 'fieldset',
      '#title' => t('Reply to this message'),
      '#collapsible' => TRUE,
    );
    $form['reply']['subject'] = array(
      '#type' => 'textfield',
      '#title' => t('Subject'),
      '#default_value' => 'Re: [' . variable_get('site_name', 'Drupal') . '] ' . $submission->subject,
      '#required' => TRUE,
    );
    $args = array(
      '!name' => $submission->name,
      '!site_name' => variable_get('site_name', 'Drupal'),
    );
    $form['reply']['message'] = array(
      '#type' => 'textarea',
      '#title' => t('Message'),
      '#description' => t('<em>Note</em>: The original message will be included below your response.'),
      '#required' => TRUE,
      '#default_value' => strtr(variable_get('contact_save_reply_template', t("Dear !name,\n\n\n\n-- !site_name team")), $args),
    );
    if (user_access('administer site-wide contact form')) {
      $form['reply']['message']['#description'] = t('This template can be modified on the <a href="@settings">contact settings form</a>.', array('@settings' => url('admin/build/contact/settings')))
        . ' '
        . $form['reply']['message']['#description'];
    }
    $form['reply']['copy'] = array(
      '#type' => 'checkbox',
      '#title' => t('Send yourself a copy.'),
    );
    $form['reply']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
  }

  // Add the delete button.
  $form['submission'] = array(
    '#type' => 'value',
    '#value' => $submission,
  );
  $form['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#submit' => array('contact_save_delete_submit'),
  );

  return $form;
}

/**
 * View page submission callback; sends the reply.
 */
function contact_save_view_submission_submit($form, &$form_state) {
  global $language;
  $values = $form_state['values'];
  $submission = $values['submission'];

  // Send reply
  $to = $submission->email;
  $from = variable_get('site_mail', ini_get('sendmail_from'));
  drupal_mail('contact_save', 'reply', $to, language_default(), $values, $from);
  drupal_set_message(t('Your reply has been sent.'));

  // Send copy
  if ($values['copy']) {
    drupal_mail('contact_save', 'copy', $from, $language, $values, $from);
  }

  // Save the reply
  global $user;
  $submission->reply = $values['message'];
  $submission->replied = time();
  $submission->replier = $user->uid;
  drupal_write_record('contact_save', $submission, array('id'));
}

/**
 * Delete button submit function; redirects to confirmation page.
 */
function contact_save_delete_submit($form, &$form_state) {
  $form_state['redirect'] = _contact_save_path($form_state['values']['submission']->id . '/delete');
}

/**
 * Delete confirmation page.
 */
function contact_save_delete_submission(&$form_state, $id) {
  $submission = db_fetch_object(db_query("SELECT cs.*, u.name AS u_name
    FROM {contact_save} cs
    LEFT JOIN {users} u ON cs.uid = u.uid
    WHERE cs.id = %d", $id));
  $form['submission'] = array(
    '#type' => 'value',
    '#value' => $submission,
  );
  $message = t('Are you sure you want to delete the contact form submission with subject %subject?', array('%subject' => $submission->subject));
  $destination = isset($_GET['destination']) ? $_GET['destination'] : _contact_save_path($submission->id);
  return confirm_form($form, $message, $destination, t('This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * Delete form submission callback.
 */
function contact_save_delete_submission_submit($form, &$form_state) {
  $submission = $form_state['values']['submission'];
  db_query("DELETE FROM {contact_save} WHERE id = %d", $submission->id);
  drupal_set_message(t('Contact form submission with subject %subject has been deleted.', array('%subject' => $submission->subject)));
  $form_state['redirect'] = _contact_save_path();
  return;
}

/**
 * Implementation of hook_mail().
 */
function contact_save_mail($key, &$message, $params) {
  switch ($key) {
    case 'reply':
    case 'copy':
      $message['subject'] = $params['subject'];
      $message['body'][] = $params['message'];
      $message['body'][] = t('Your original message:');
      $message['body'][] = $params['submission']->message;
      break;
  }
}

/**
 * Formats submission fields.
 */
function _contact_save_format_field($field, $submission) {
  switch ($field) {
    case 'created-date':
      return format_date($submission->created, 'custom', 'Y-m-d');
    case 'created':
      return format_date($submission->created, 'custom', 'F j, Y \a\t g:i a');
    case 'name':
      return $submission->u_name ? ((user_access('administer users') or user_access('access user profiles')) ? l($submission->u_name, 'user/' . $submission->uid) : $submission->u_name) : check_plain($submission->name);
    case 'email':
      return l($submission->email, 'mailto:' . $submission->email);
    case 'subject':
      return l($submission->subject, _contact_save_path() . '/' . $submission->id);
    case 'category':
      return $submission->c_category ? (user_access('administer site-wide contact form') ? l($submission->c_category, 'admin/build/contact/edit/' . $submission->cid) : $submission->c_category) : ($submission->category ? check_plain($submission->category) : t('n/a'));
    case 'recipients':
      $links = array();
      foreach (explode(',', $submission->recipients) as $recipient) {
        $recipient = trim($recipient);
        $links[] = l($recipient, 'mailto:' . $recipient);
      }
      if (count($links) > 2) {
        $last = array_pop($links);
        return implode(', ', $links) . t(' and ') . $last;
      }
      return implode(t(' and '), $links);
    case 'message':
      return nl2br(check_plain($submission->message));
    case 'body':
      return nl2br(check_plain($submission->body));
    case 'replied-date':
      return $submission->replied ? format_date($submission->replied, 'custom', 'Y-m-d') : '';
    case 'replied':
      return format_date($submission->replied, 'custom', 'F j, Y \a\t g:i a');
    case 'replier':
      return (user_access('administer users') or user_access('access user profiles')) ? l($submission->r_name, 'user/' . $submission->replier) : check_plain($submission->r_name);
    case 'reply':
      return nl2br(check_plain($submission->reply));
  }
}

/**
 * Returns either admin path (admin/build/contact/submissions),
 * or user path (user/%user/contact_save), based on URL.
 */
function _contact_save_path($extra = '') {
  $path = arg(0) == 'user' ? 'user/' . arg(1) . '/contact_save' : 'admin/build/contact/submissions';
  if ($extra) {
    $path .= "/$extra";
  }
  return $path;
}

/**
 * Redirects user to correct page, depending on their permissions.
 */
function contact_save_redirect($submission_id) {
  if (user_access('administer site-wide contact form')) {
    drupal_goto("admin/build/contact/submissions/$submission_id");
  }
  else {
    global $user;
    drupal_goto("user/$user->uid/contact_save/$submission_id");
  }
}
