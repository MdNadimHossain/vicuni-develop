<?php

/**
 * @file
 * VU QR Code.
 */
?>
<?php if (!empty($qr_code)): ?>
  <div class="qr-code-container">
    <?php print $qr_code; ?>
    <div class="qr-code-info">Scan this QR code using your mobile phone camera to view this content on the Victoria University website.</div>
 </div>
<?php endif; ?>
