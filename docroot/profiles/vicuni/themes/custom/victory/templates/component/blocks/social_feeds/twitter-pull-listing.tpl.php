<?php

/**
 * @file
 * Theme template for a list of tweets.
 *
 * Available variables in the theme include:
 *
 * 1) An array of $tweets, where each tweet object has:
 *   $tweet->id
 *   $tweet->username
 *   $tweet->userphoto
 *   $tweet->text
 *   $tweet->timestamp
 *   $tweet->time_ago
 *
 * 2) $twitkey string containing initial keyword.
 *
 * 3) $title
 */
?>
<?php if ($lazy_load): ?>
  <?php print $lazy_load; ?>
<?php else: ?>
  <div class="tweets-pulled-listing-wrapper">

    <?php if (!empty($title)): ?>
      <h2><?php print $title; ?></h2>
    <?php endif; ?>

    <?php if (is_array($tweets)): ?>
      <?php $tweet_count = count($tweets); ?>

      <div class="tweets-pulled-listing">
        <?php foreach ($tweets as $tweet_key => $tweet): ?>
          <?php if (!empty($tweet->screenname)): ?>
            <div class="tweet">
              <div class="tweet-author-wrapper clearfix">
                <div class="tweet-author-info clearfix">
                  <a href="<?php echo '//twitter.com/' . $tweet->screenname; ?>" class="noext">
                    <div class="tweet-authorphoto">
                      <img src="<?php echo $tweet->userphoto; ?>" alt="<?php echo $tweet->username; ?>"/>
                    </div>
                    <div class="tweet-author"><?php print $tweet->username; ?></div>
                    <div class="tweet-screenname"><?php print '@' . $tweet->screenname; ?></div>
                    <span class="tweet-icon fa fa-twitter"></span>
                  </a>
                </div>
              </div>
              <div class="tweet-text"><?php print _vu_twitter_pull_add_links($tweet->text); ?></div>
              <div class="tweet-footer">
                <div class="tweet-time"><?php print l($tweet->time_ago, '//twitter.com/' . $tweet->screenname . '/status/' . $tweet->id, ['attributes' => ['class' => ['noext']]]); ?></div>
                <div class="tweet-actions">
                  <?php print l('<span class="element-invisible">Reply</span>', "//twitter.com/intent/tweet?in_reply_to=$tweet->id", [
                    'html' => TRUE,
                    'attributes' => ['class' => 'twitter-reply noext fa fa-reply'],
                  ]); ?>
                  <?php print l('<span class="element-invisible">Retweet</span>', "//twitter.com/intent/retweet?tweet_id=$tweet->id", [
                    'html' => TRUE,
                    'attributes' => ['class' => 'twitter-retweet noext fa fa-retweet'],
                  ]); ?>
                  <?php print l('<span class="element-invisible">Favorite</span>', "//twitter.com/intent/favorite?tweet_id=$tweet->id", [
                    'html' => TRUE,
                    'attributes' => ['class' => 'twitter-favorite noext fa fa-star'],
                  ]); ?>
                </div>
              </div>
            </div>
          <?php endif; ?>
        <?php endforeach; ?>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
