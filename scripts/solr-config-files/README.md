# Acquia Solr config files

The files in this folder are for versioning purposes only.  They are deployed by Acquia to the relevant environments.

## To upload to Acquia

Read and follow the instructions regarding Acquia Search customisations in the documentation at https://docs.acquia.com/acquia-search/config and https://docs.acquia.com/articles/how-test-custom-solr-schema-file-locally.  Once the configuration is deployed, if there's any errors it might take time to revert those changes.

As per the referenced documentation, following best practice we recommend not altering any of the Solr xml files (e.g. schema.xml). Instead, it is recommended to add custom functionality and configuration into new schema_extra_fields.xml and/or solrconfig_extra.xml files. These files are then included from the schema.xml and solrconfig.xml files (similar to a PHP require/include statement).

Using this recommended structure, the original schema/solrconfig files can be kept intact and required functionality is just added via the _extra* files. Can you please review your changes with a view to split out custom config/functionality where possible to new schema_extra_fields.xml or solrconfig_extra.xml files.

log in and create a support ticket.  Attach the files.

Confirm the following in the ticket:
- Please confirm that you've already tested the custom configuration on a separate Solr instance (running under Solr v.3.5) and have ensured that it works.
- Please provide the individual Search Core IDs where the changes are to be applied.  These details can be found in settings.php.

In some cases, you will need to reindex your site. If applicable, you should use the same procedures as those you followed with your prior testing of these files before submitting them to Acquia.

## Acquia reference docs
[Custom Solr configuration](https://docs.acquia.com/acquia-search/config)
[How to test a custom Solr schema file locally](https://docs.acquia.com/articles/how-test-custom-solr-schema-file-locally)

Note that deploying any custom configuration into your Acquia Search Solr instance might adversely impact your site's search service.

Also note that Acquia has a policy limiting the frequency at which we will deploy changes into Acquia-hosted Solr instances. For details see: https://docs.acquia.com/acquia-search/config.

## Previous related support requests
https://insight.acquia.com/support/tickets/308210
