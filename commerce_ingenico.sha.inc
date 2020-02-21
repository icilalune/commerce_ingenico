<?php

/**
 * @file
 * SHA security hash specific functionality
 */

/**
 * Validate the feedback with the SHA signature.
 */
function commerce_ingenico_feedback_valid_sha($feedback, $payment_method) {
  // Get the right sha algorithm.
  $api = commerce_ingenico_api_object('', $payment_method);
  $sha_composer = $api->preparePhraseToHash('sha_out');
  $feedback_sha = $feedback['SHASIGN'];
  unset($feedback['SHASIGN']);
  $sha_out = $sha_composer->compose($feedback);
  return strtoupper($sha_out) === $feedback_sha;
}
