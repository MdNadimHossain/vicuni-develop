<?php
/**
 * @file
 * Template for journey planner block in campus pages.
 */
?>
<section class="campus-journey-planner clearfix">
  <?php if ($address): ?>
    <div id="address" class="col-md-3 address">
      <h3>Address</h3>
      <address>
        <?php echo $address; ?>
      </address>
    </div>
  <?php endif ?>

  <div class="col-md-4 by-ptv">
    <h3>Plan your trip</h3>
    <p>
      <a class="noext" target="_blank" title="Public Transport Victoria Journey Planner &raquo;" href="https://www.ptv.vic.gov.au/journey">
        Plan your train, tram or bus trip with the
        <abbr class="notip" title="Public Transport Victoria">PTV</abbr> Journey Planner
      </a>
    </p>
  </div>
  <div class="col-md-5 by-road">
    <h3>Get Google directions</h3>
    <form class="jqm" action="//maps.google.com/maps/" target="_blank">
      <div class="by-road-from">
        <label for="street-address">From</label>
        <input name="saddr" id="street-address" type="text"/>
      </div>
      <div class="by-road-to">
        <label for="select-vu-campus">To</label>
        <select id="select-vu-campus" name="daddr">
          <option value="" disabled="disabled">-- Please select --</option>
          <?php foreach ($journey_planner['campus_addresses'] as $name => $value): ?>
            <?php if (strpos($journey_planner['selected_address'], $value) !== FALSE): ?>
              <option selected="selected" value="<?php echo $value ?>"><?php echo $name ?></option>
            <?php else: ?>
              <option value="<?php echo $value ?>"><?php echo $name ?></option>
            <?php endif ?>
          <?php endforeach ?>
        </select>
      </div>
      <div class="by-road-submit"><input name="en" type="hidden" value="hl">
        <input id="gmaps-submit" type="submit" class="btn" value="Get directions">
      </div>
    </form>
  </div>
</section>
