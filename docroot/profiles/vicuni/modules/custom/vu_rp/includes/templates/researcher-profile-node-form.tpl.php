<?php

/**
 * @file
 * Template file for Researcher profile node form.
 */
?>
<div class="field-group-htabs-wrapper group-researcher-profile field-group-htabs">
  <div class="horizontal-tabs clearfix">
    <ul class="horizontal-tabs-list">
      <li class="horizontal-tab-button horizontal-tab-button-0 first" tabindex="0">
        <a href="#"><strong>Personal details</strong>
          <span class="form-required" title="This field is required.">*</span><span class="summary"></span></a>
      </li>
      <li class="horizontal-tab-button horizontal-tab-button-1" tabindex="1">
        <a href="#"><strong>Biography & expertise</strong>
          <span class="form-required" title="This field is required.">*</span><span class="summary"></span></a>
      </li>
      <li class="horizontal-tab-button horizontal-tab-button-2" tabindex="2">
        <a href="#"><strong>Publications</strong>
          <span class="form-required" title="This field is required.">*</span><span class="summary"></span></a>
      </li>
      <li class="horizontal-tab-button horizontal-tab-button-3" tabindex="3">
        <a href="#"><strong>Funding</strong>
          <span class="form-required" title="This field is required.">*</span><span class="summary"></span></a>
      </li>
      <li class="horizontal-tab-button horizontal-tab-button-4" tabindex="4">
        <a href="#"><strong>Supervising & teaching</strong>
          <span class="form-required" title="This field is required.">*</span><span class="summary"></span></a>
      </li>
      <li class="horizontal-tab-button horizontal-tab-button-5" tabindex="5">
        <a href="#"><strong>Career</strong>
          <span class="form-required" title="This field is required.">*</span><span class="summary"></span></a>
      </li>
    </ul>
    <div class="horizontal-tabs-panes horizontal-tabs-processed">
      <fieldset class="required-fields form-wrapper horizontal-tabs-pane fieldgroup-effects-processed">
        <div class="block-form">
          <div class="name-section section">
            <div class="col-1">
              <div class="field-markup">
                <h1>Your name</h1>
                <p>
                  <label for="edit-field-rp-name-variation-und">1. Your name (required)</label>
                </p>
                <p>The VU system has your name as:</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_staff_id']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_first_name']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_middle_name']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_last_name']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_preferred_name']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Name incorrect in the system?</h1>
                <p>Please contact People & Culture to change your name recorded in their system.</p>
              </div>
            </div>
          </div>
          <div class="important-name-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_name_variation']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_first_name']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_last_name']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Your name is important</h1>
                <p>Your name will be user as the title of your profile page as well as the address e.g. vu.edu.au/research/find-researcher/john-smith.</p>
                <p>Search engines will use and display this so use the name people are most likely to know you by.</p>
                <p>If you are known by multiple names you may wish to create alternative URLs for people to access your profile. Discuss this with the Web Content team when when your profile is being reviewed.</p>
              </div>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_title']); ?>
          <div class="post-nominal-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_post_nominal']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-expanded">
                <h1><span>Show</span> post nominal guidance</h1>
                <div>
                  <p>For more understanding of common Australian post nominal letters visit
                    <a href="https://en.wikipedia.org/wiki/List_of_post-nominal_letters_(Australia)">https://en.wikipedia.org/wiki/List_of_post-nominal_letters_(Australia)</a>.
                  </p>
                </div>
              </div>
            </div>
          </div>
          <div class="field-markup">
            <h1>Contact details</h1>
          </div>
          <div class="email-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_email']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Email address incorrect?</h1>
                <p>Please contact ITS Help Desk to fix any problems with your email address.</p>
              </div>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_phone']); ?>
          <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_phone']); ?>
          <div class="twitter-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_twitter']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-expanded">
                <h1><span>Show</span> Twitter guidance</h1>
                <div>
                  <p>To find your Twitter username, sign in to Twitter and check your profile. The Twitter handle is your username with an @ symbol immediately before it.</p>
                </div>
              </div>
            </div>
          </div>
          <div class="facebook-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_facebook']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-expanded">
                <h1><span>Show</span> Facebook guidance</h1>
                <div>
                  <p>To find your Facebook link, sign in to Facebook then go to your profile. The link in your browser’s address bar is the one you want to copy here.</p>
                </div>
              </div>
            </div>
          </div>
          <div class="linkedin-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_linkedin']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-expanded">
                <h1><span>Show</span> LinkedIn guidance</h1>
                <div>
                  <p>To find your LinkedIn profile link, sign into LinkedIn then go to your profile. The link in your browser’s address bar is the one you want to copy here.</p>
                </div>
              </div>
            </div>
          </div>
          <div class="conversation-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_conversation_profile']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-expanded">
                <h1><span>Show</span> The Conversation guidance</h1>
                <div>
                  <p>To find your profile on The Conversation, sign in to The Conversation website then go to your profile. There are a number of tabs showing below your image so make sure the ‘Profile’ tab is selected. The link in your browser’s address bar is the one you want to copy here.</p>
                </div>
              </div>
            </div>
          </div>
          <div class="orcid-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_orcid_id']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Not your ORCID identifier?</h1>
                <p>If an ORCID identifier is showing that is not yours, please correct it here and also contact P&C to correct it in their system.</p>
              </div>
            </div>
          </div>
          <div class="field-markup">
            <h1>VU role</h1>
          </div>
          <div class="vu-role section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_institute_primary']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_institute_best_align']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-expanded">
                <h1><span>Show</span> research institute guidance</h1>
                <div>
                  <p>If you are not formally associated with any of the research institutes shown, select ‘None of these’. You will be asked to nominate which institute your research best aligns with.</p>
                </div>
              </div>
            </div>
          </div>
          <div class="job-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rpa_job_title']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_job_title_variation']); ?>
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_job_title']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Does your Position need to be more descriptive?</h1>
                <p>If the position in the VU system is identical to the Title you have already entered, it will not provide any additional value for users so consider providing some additional description.</p>
                <p>e.g. A title of 'Professor' with a position of 'Professor' is less informative than a descriptive position such as 'Professor of Psychology'</p>
              </div>
            </div>
          </div>
          <div class="field-markup">
            <h1>Your photo</h1>
          </div>
          <div class="photo-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_use_photo']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Photos are encouraged, but not required</h1>
                <p>We know people searching for profiles like to see an image of the person they are looking for and also understand if you don't wish to include one.</p>
              </div>
            </div>
          </div>
          <div class="load-photo-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_personal_details']['field_rp_photo']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-expanded">
                <h1>Tips for taking your photo</h1>
                <div>
                  <ul>
                    <li>You don't need a professional photo shoot - a colleague or family member can take your photo.</li>
                    <li>The photo orientation should be landscape.</li>
                    <li>Position yourself in the center third.</li>
                    <li>Decide whether you want a plain background or one that shows you in your work environment, e.g. in lad setting, speaking in front of a group, etc.</li>
                    <li>Aim to look friendly and authoritative.</li>
                  </ul>
                </div>
              </div>
            </div>
          </div>
        </div>
      </fieldset>
      <fieldset class="required-fields form-wrapper horizontal-tabs-pane fieldgroup-effects-processed">
        <div class="block-form">
          <div class="field-markup">
            <h1>Areas of expertise</h1>
          </div>
          <div class="expertise-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>You can choose up to 5 areas of expertise to display. These will also be used in searches to help match your profile to entered search criteria.</p>
                <p>Start typing to see areas of expertise with similar wording. If your expertise appears select it from the list, otherwise continue typing and it will be added.</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_biography_expertise']['field_rp_expertise']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Why is there a maximum of 5 areas of expertise?</h1>
                <div>
                  <p>The more specific your areas of expertise are, the harder it can be for site visitors to know the specific terms to use to find you. Limiting the number of areas of expertise may result in more generalised terms being used, which may assist site visitors to find you more easily.</p>
                </div>
              </div>
            </div>
          </div>
          <div class="field-markup">
            <h1>Your biography</h1>
          </div>
          <div class="biography-section section">
            <div class="col">
              <div class="field-markup">
                <p>
                  <strong>1. Provide a brief description of yourself (required)</strong>
                </p>
                <ul>
                  <li>Write in the third person. e.g. 'Gina has an internationally recognised research track record in..'</li>
                  <li>Ideally focus on your key achievements and current research interests</li>
                  <li>Try not to repeat information that is presented elsewhere, e.g. a list of your academic qualifications is provided in its own section</li>
                  <li>The formatting bar can be used to style text</li>
                </ul>
              </div>
              <?php print render($form['group_research_profile']['group_rp_biography_expertise']['field_rp_biography']); ?>
            </div>
          </div>
          <div class="field-markup">
            <h1>Related links (supporting your biography)</h1>
          </div>
          <div class="related-links-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>Up to 4 links can be displayed with your biography. The first will be to your VU research institute (previously selected) and you can include 3 more e.g. to the College, labs or groups you work with. Note: any external groups you wish to acknowledge should be added in the Funding tab.</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_biography_expertise']['field_rp_related_links']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Guidance notes</h1>
                <div>
                  <p>Find the page you wish to link to and copy the address into the Link address / URL e.g. https://www.vu.edu.au/center-of-policy-studies-cops.</p>
                  <p>The Link label is the human readable name of the page. This should match the main heading on the page so you can copy and paste that. e.g. Centre of Policy Studies (CoPS)</p>
                </div>
              </div>
            </div>
          </div>
          <div class="short-description-section section">
            <div class="col-1">
              <div class="field-markup">
                <h1>Search related details</h1>
                <p><strong>Short description</strong></p>
                <p>When you appear in search results, a short description of you is provided and your areas of expertise listed.</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_biography_expertise']['field_rp_shorter_biography']); ?>
            </div>
          </div>
          <div class="media-queries-section section">
            <div class="col-1">
              <div class="field-markup">
                <h1>Are you available for media queries?</h1>
                <p>If you are comfortable to receive media queries please indicate this so the search facilities on the VU website can help members of the media find you more easily.</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_biography_expertise']['field_rp_available_to_media']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Guidance notes</h1>
                <div>
                  <p>The VU media team (media@vu.edu.au) can help you prepare for media appearances.</p>
                  <p>Please note that responding 'No' does not guarantee the media will not contact you, as your profile will still be publicly available on the site.</p>
                </div>
              </div>
            </div>
          </div>
          <div class="field-markup">
            <h1>Qualifications</h1>
          </div>
          <div class="qualification-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>
                  <strong>5. Enter a least one qualification, up to a maximum of five.</strong>
                </p>
                <p>Use the format:
                  <i>Abbreviated qualification, University, Country, Year</i><br/>
                  e.g. <i>BSc (Hons), RMIT University, Australia, 2000</i></p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_biography_expertise']['field_rp_qualification']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Displaying your qualifications</h1>
                <div>
                  <p>Start with your highest qualification first.</p>
                  <p>If you're not sure of the abbreviated version of your qualification, enter the complete qualification.</p>
                  <p>Avoid abbreviating University names e.g. RMIT should be RMIT University.</p>
                </div>
              </div>
            </div>
          </div>
        </div>
      </fieldset>
      <fieldset class="required-fields form-wrapper horizontal-tabs-pane fieldgroup-effects-processed">
        <div class="block-form">
          <div class="field-markup">
            <h1>Publications on VU Research Repository</h1>
          </div>
          <div class="col-1">
            <div class="field-markup">
              <p>You can provide details up to 10 publications as part of your research profile. People viewing your profile will also be offered a link to the VU Research Repository (required)</p>
            </div>
          </div>
          <div class="publications-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_publications']['field_rp_research_repo_link']); ?>
              <?php print render($form['group_research_profile']['group_rp_publications']['field_rpc_publication_count']); ?>
              <?php print render($form['group_research_profile']['group_rp_publications']['field_rpc_publication_type_count']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-expanded">
                <h1><span>Show</span> VURR guidance</h1>
                <div>
                  <p>To find the link to your full list of publications on the VU Research Repository go to the repository at
                    <a href="http://vuir.vu.edu.au/">http://vuir.vu.edu.au/</a>.
                  </p>
                  <p>Select the Browse by Author link and use the A-Z listing to locate your page. When found copy the URL here. It should look similar to: http://vuir.vu.edu.au/view/people/Dawkins=3APeter=3A=3A.html.</p>
                </div>
              </div>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_publications']['field_rpa_publications']); ?>
          <?php print render($form['field_rp_publications_info']); ?>
        </div>
      </fieldset>
      <fieldset class="required-fields form-wrapper horizontal-tabs-pane fieldgroup-effects-processed">
        <div class="block-form">
          <div class="col-1">
            <div class="field-markup">
              <h1>Research funding for the past 5 years</h1>
            </div>
          </div>
          <div class="funding-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>The following funding information has come through from QUEST. Please confirm it is correct then continue the next section.</p>
                <p>If you have any questions regarding this information contact
                  <a>researcher.profiles@vu.edu.au</a>.</p>
              </div>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Note that projects are not shown when they are marked confidential in QUEST. Also the funding amount will not be disclosed when:</h1>
                <ul>
                  <li>the funded amount is less than $5,000</li>
                  <li>the project type is either contract or tender</li>
                </ul>
              </div>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_funding']['field_rpa_funding']); ?>
          <?php print render($form['field_rp_fundings_info']); ?>
          <div class="field-markup">
            <h1>Organisations to acknowledge</h1>
          </div>
          <div class="acknowledge-section section">
            <div class="col-1">
              <div class="field-markup">
                This section will be shown below the research funding section and allows you to acknowledge organisations that:
                <ul>
                  <li>have provided funding that is not associated with a specific project.</li>
                  <li>provide you with non-monetary support such as equipment and facilities.</li>
                  <li>wish to keep project specific details confidential (while happy to be acknowledged).</li>
                </ul>
              </div>
              <?php print render($form['group_research_profile']['group_rp_funding']['field_rp_has_ota']); ?>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_funding']['field_rp_ota']); ?>
        </div>
      </fieldset>


      <fieldset class="required-fields form-wrapper horizontal-tabs-pane fieldgroup-effects-processed">
        <div class="block-form">
          <div class="field-markup">
            <h1>Supervising of research students at VU</h1>
          </div>
          <div class="available-supervising-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_supervising_teaching']['field_rp_sup_is_available']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Responsibilities of available supervisors</h1>
                <p>Indicating you are available to supervise research students means you accept the responsibility of answering potential student queries in a timely and professional manner.</p>
              </div>
            </div>
          </div>
          <div class="supervising-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_supervising_teaching']['field_rpa_sup_current']); ?>
              <?php print render($form['group_research_profile']['group_rp_supervising_teaching']['field_rpa_sup_completed']); ?>
              <?php print render($form['field_rp_sup_info']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>New to supervision?</h1>
                <p>If you don't have any supervision experience you can use the 'Teaching activities &amp; experience' section to highlight your skill.</p>
              </div>
            </div>
          </div>
          <div class="field-markup">
            <h1>Other supervision of research students</h1>
          </div>
          <div class="other-supervising-section section">
            <div class="col-1">
              <?php print render($form['group_research_profile']['group_rp_supervising_teaching']['field_rp_sup_other']); ?>
            </div>
          </div>
          <div class="field-markup">
            <h1>Teaching activities & experience</h1>
          </div>
          <div class="teaching-experience-section section">
            <div class="field-markup">
              <p>
                <strong>5. Describe your teaching activities and experience (optional)</strong>
              </p>
              <p>Guidance notes</p>
              <ul>
                <li>Focus on your VU experience/commitments first. If you are new to VU refer to prior teaching or supervision experience at other institutions.</li>
                <li>White in the third person. e.g. 'Gina is Unit Coordinator of the following VU units...'</li>
                <li>If referring to a VU unit or course code, please include the unit/course title with it.</li>
                <li>The formatting bar can be used to create lists, style text or include hyperlinks</li>
              </ul>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_supervising_teaching']['field_rp_teaching_experience']); ?>
        </div>
      </fieldset>

      <fieldset class="required-fields form-wrapper horizontal-tabs-pane fieldgroup-effects-processed">
        <div class="block-form">
          <div class="field-markup">
            <h1>Key academic roles</h1>
          </div>
          <div class="key-academic-roles-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>Highlight significant roles you've had at VU and other academic institutions (rather than providing a detailed CV).</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_career']['field_rp_has_academic_roles']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Which roles to include?</h1>
                <p>Ideally choose between 1 and 10 of your most recent or most significant roles.</p>
                <p>They will be displayed in order of most to least recent, regardless of the order you enter them.</p>
              </div>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_career']['field_rp_academic_roles']); ?>
          <div class="field-markup">
            <h1>Key industry, community and government roles</h1>
          </div>
          <div class="industry-role-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>Highlight significant non-academic roles you currently hold or have had in the past.</p>
                <p>This can include boards, advisory committees, peak bodies, commercial organisations.</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_career']['field_rp_has_key_industry']); ?>
            </div>
            <div class="col-2">
              <div class="field-markup-no-expanded">
                <h1>Which roles to include?</h1>
                <p>Ideally choose between 1 and 10 of your most recent or most significant roles.</p>
                <p>They will be displayed in order of most to least recent, regardless of the order you enter them.</p>
              </div>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_career']['field_rp_industry_roles']); ?>
          <div class="field-markup">
            <h1>Awards</h1>
          </div>
          <div class="awards-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>Include academic awards or any relating to your research expertise.</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_career']['field_rp_has_awards']); ?>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_career']['field_rp_awards']); ?>
          <div class="field-markup">
            <h1>Invited keynote speeches</h1>
          </div>
          <div class="keynotes-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>Include only keynote speeches for national and international level conferences.</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_career']['field_rp_has_keynote_invitations']); ?>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_career']['field_rp_keynotes']); ?>
          <div class="field-markup">
            <h1>Professional memberships</h1>
          </div>
          <div class="membership-section">
            <div class="col-1">
              <div class="field-markup">
                <p>In addition to the organisation name, we encourage you to include your level of membership or role. If you have a significant role, e.g. chair, secretary, treasurer consider including that in your list of key industry, community and government roles.</p>
              </div>
              <?php print render($form['group_research_profile']['group_rp_career']['field_rp_has_memberships']); ?>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_career']['field_rp_memberships']); ?>
          <div class="field-markup">
            <h1>Media appearances</h1>
          </div>
          <div class="media-section section">
            <div class="col-1">
              <div class="field-markup">
                <p>In addition to traditional media, consider online media e.g. The Conversation.</p>
                
              </div>
              <?php print render($form['group_research_profile']['group_rp_career']['field_rp_has_media_appearances']); ?>
            </div>
          </div>
          <?php print render($form['group_research_profile']['group_rp_career']['field_rp_media']); ?>
        </div>
      </fieldset>
    </div>
  </div>
</div>
<div><?php print render($form['revision_information']); ?></div>
<div><?php print render($form['additional_settings']); ?></div>
<div><?php print render($form['actions']); ?></div>
<div class="hidden-element"><?php print drupal_render_children($form); ?></div>
