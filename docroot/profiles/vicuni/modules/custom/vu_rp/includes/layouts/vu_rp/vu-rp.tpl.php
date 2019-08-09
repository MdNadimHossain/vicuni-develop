<?php

/**
 * @file
 * Research Profile page template.
 */
?>
<article id="node-<?php print $node->nid; ?>" class="content researcher-profile researcher-profiles clear-block node<?php print !$status ? ' node-unpublished' : ''; ?>">
  <div id="overview" class="researcher-overview researcher-content-section js-researcher-content-section">
    <?php if ($overview_key_details) : ?>
      <div class="section researcher-overview-key-details" id="overview-key-details">
        <h2 class="victory-title__stripe">Key details</h2>
        <div class="container">
          <div class="row first">
            <div class="col-md-7 clear-content js-researcher-photo-target">
              <?php print $overview_key_details; ?>
            </div>
            <div class="col-md-push-1 col-md-4">
              <?php print $overview_right; ?>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($overview_about) : ?>
      <div class="section research-overview-about-details" id="overview-about-details">
        <h2 class="victory-title__stripe">About <?php print $node->title ?></h2>
        <div class="container">
          <div class="row first">
            <div class="col-md-7 clear-content">
              <?php print $overview_about; ?>
            </div>
            <div class="col-md-push-1 col-md-4">
              <?php print $overview_middle_right; ?>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($overview_qualifications) : ?>
      <div class="section researcher-overview-qualifications" id="overview-qualifications">
        <h2 class="victory-title__stripe">Qualifications</h2>
        <div class="container">
          <div class="row first">
            <div class="col-md-7 clear-content">
              <?php print $overview_qualifications; ?>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>
  </div>

  <?php if ($publications) : ?>
    <div id="publications" class="researcher-content-section js-researcher-content-section">
      <div class="section" id="key-publications">
        <h2 class="victory-title__stripe">Key publications</h2>
        <div class="container">
          <div class="row first">
            <div class="col-md-10 clear-content js-accordion-wrapper">
              <?php print $publications; ?>
            </div>
            <div class="col-md-push-1 col-md-1">
            </div>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <div id="research-funding" class="researcher-content-section js-researcher-content-section">
    <div class="section" id="research-funding-5-years">
      <h2 class="victory-title__stripe">Research funding for the past 5
        years</h2>
      <div class="container">
        <div class="row first">
          <div class="col-md-7 clear-content js-accordion-wrapper js-accordion-state-open-md">
            <?php if ($funding) : ?>
              <div class="section">
                <p>Please note:</p>
                <ul>
                  <li>Funding is ordered by the year the project commenced and may continue over several years.</li>
                  <li>Funding amounts for contact research are not disclosed to maintain commercial confidentiality.</li>
                  <li>The order of investigators is not indicative of the role they played in the research project.</li>
                </ul>
              </div>
              <?php print $funding; ?>
            <?php else: ?>
              Funding details for this researcher are currently unavailable.
            <?php endif; ?>
          </div>
          <div class="col-md-push-1 col-md-4">
            <?php print $funding_right; ?>
          </div>
        </div>
      </div>
    </div>

    <?php if ($funding_bottom): ?>
      <div class="section" id="research-funding-other">
        <h2 class="victory-title__stripe">Acknowledgements</h2>
        <div class="container">
          <div class="row first">
            <div class="col-md-7 clear-content">
              <?php print $funding_bottom; ?>
            </div>
            <div class="col-md-push-1 col-md-4">
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>
  </div>

  <div id="supervising" class="researcher-supervising researcher-content-section js-researcher-content-section">
    <div class="section" id="research-supervsing">
      <h2 class="victory-title__stripe">Supervision of research students at
        VU</h2>
      <div class="container">
        <div class="row first">
          <div class="col-md-7">
            <?php print $supervising_left; ?>
            <?php if (empty($supervising_left)): ?>
              <div class="researcher-details-unavailable">Details of this
                researcher’s supervision roles at VU are currently unavailable.
              </div>
            <?php endif; ?>
          </div>
          <div class="col-md-push-1 col-md-4">
            <?php print $supervising_right; ?>
          </div>
        </div>
      </div>
    </div>
    <?php if ($supervising_middle): ?>
      <div class="section" id="research-supervsing-other">
        <h2 class="victory-title__stripe">Other supervision of research students</h2>
        <div class="container">
          <div class="row first">
            <div class="col-md-8">
              <?php print $supervising_middle; ?>
            </div>
            <div class="col-md-4">
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>
    <?php if ($supervising_bottom): ?>
      <div class="section" id="research-teaching">
        <h2 class="victory-title__stripe">Teaching activities & experience</h2>
        <div class="container">
          <div class="row first">
            <div class="col-md-8">
              <?php print $supervising_bottom; ?>
            </div>
            <div class="col-md-4">
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>
  </div>

  <div id="career" class="researcher-career researcher-content-section js-researcher-content-section">
    <?php if ($career) : ?>
      <?php print $career; ?>
    <?php else : ?>
      <div class="section" id="research-career-awards">
        <h2 class="victory-title__stripe">Careers</h2>
        <div class="container">
          <div class="row first">
            <div class="col-md-10">
              <div class="researcher-details-unavailable">
                Details of this Researcher's career are currently unavailable.
              </div>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>
  </div>
</article>
