<?php
/**
 * @file
 * Contains My library login form markup.
 */
?>
<h2>Log in to My Library</h2>
<p>Log in to <em>My Library</em> to manage your holds, loans and renewals.</p>
<form accept-charset="UTF-8" action="https://library.vu.edu.au/patroninfo~S0/" class="webform-client-form" id="my-library-login-form" method="post">
  <div class="form-fields">
    <div class="webform-component webform-component-textfield">
      <div class="form-item form-item-id-number"><label for="edit-submitted-code">ID Number:</label> <input class="form-text" id="edit-submitted-code" maxlength="15" name="code" size="60" type="text" value="" />
        <p><em>VU ID Number (without the e or s). If non VU, use barcode</em></p>
      </div>
    </div>
    <div class="webform-component webform-component-password" id="webform-component-pin">
      <div class="form-item form-item-key-in-your-pin" id="edit-submitted-pin-wrapper"><label for="edit-submitted-pin">Key in your PIN:</label> <input class="form-text" id="edit-submitted-pin" maxlength="40" name="pin" size="60" type="password" />
        <p><a href="https://library.vu.edu.au/pinreset~S0">Forgot your PIN?</a></p>
      </div>
    </div>
    <div class="form-actions form-wrapper" id="edit-actions"><input class="form-submit button-primary btn btn-primary" id="my-library-login-form-submit" name="op" type="submit" value="Login" /></div>
  </div>
</form>
