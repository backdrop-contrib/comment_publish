<?php
/**
 * @file
 * Page callbacks for the single-comment publish/unpublish action links.
 */

/**
 * Page callback: Publishes a single comment via a tokenized link.
 *
 * @param object $comment
 *   A fully loaded comment object.
 *
 * @return int
 *   MENU_ACCESS_DENIED if the token is missing or invalid. Otherwise
 *   redirects back to the originating page.
 *
 * @see comment_publish_unpublish_page()
 * @see comment_publish_set_status()
 */
function comment_publish_publish_page($comment) {
  return comment_publish_set_status($comment, COMMENT_PUBLISHED, 'publish');
}

/**
 * Page callback: Unpublishes a single comment via a tokenized link.
 *
 * @param object $comment
 *   A fully loaded comment object.
 *
 * @return int
 *   MENU_ACCESS_DENIED if the token is missing or invalid. Otherwise
 *   redirects back to the originating page.
 *
 * @see comment_publish_publish_page()
 * @see comment_publish_set_status()
 */
function comment_publish_unpublish_page($comment) {
  $status = COMMENT_NOT_PUBLISHED;
  return comment_publish_set_status($comment, $status, 'unpublish');
}

/**
 * Sets a comment's published status and redirects back to the listing.
 *
 * Mirrors the token pattern used by core's comment_approve().
 *
 * @param object $comment
 *   A fully loaded comment object.
 * @param int $status
 *   Either COMMENT_PUBLISHED or COMMENT_NOT_PUBLISHED.
 * @param string $action
 *   The action name used in the token and path, "publish" or "unpublish".
 *
 * @return int
 *   MENU_ACCESS_DENIED if the token is missing or invalid.
 *
 * @see comment_approve()
 */
function comment_publish_set_status($comment, $status, $action) {
  $path = "comment/$comment->cid/$action";
  if (!isset($_GET['token']) || !backdrop_valid_token($_GET['token'], $path)) {
    return MENU_ACCESS_DENIED;
  }

  $comment->status = $status;
  comment_save($comment);

  if ($status == COMMENT_PUBLISHED) {
    $message = t('Comment published.');
  }
  else {
    $message = t('Comment unpublished.');
  }
  backdrop_set_message($message);

  $destination = backdrop_get_destination();
  backdrop_goto($destination['destination']);
}
