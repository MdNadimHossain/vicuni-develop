<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:include href="common.xsl"/>
  <xsl:output method="html"/>

  <!-- ============================= -->
  <!-- Unit -->
  <!-- ============================= -->

  <xsl:template match="pre-requisites|co-requisites">
    <xsl:for-each select="./*">
      <xsl:if test=". != ''">
        <p>
          <xsl:value-of select="."/>
        </p>
      </xsl:if>
    </xsl:for-each>
  </xsl:template>

  <xsl:template match="learningoutcomes">
    <xsl:value-of select="."/>
  </xsl:template>

  <xsl:template match="assessment">
    <xsl:value-of select="headertext"/>
    <xsl:choose>
      <xsl:when test="items/item">
        <table class="table table-striped">
          <thead>
            <th>Assessment type</th>
            <th>Description</th>
            <th>Grade</th>
          </thead>
          <tbody>
            <xsl:for-each select="items/item">
              <tr>
                <td>
                  <xsl:value-of select="type"/>
                </td>
                <td>
                  <xsl:value-of select="description"/>
                </td>
                <td>
                  <xsl:value-of select="grade"/>
                </td>
              </tr>
            </xsl:for-each>
          </tbody>
        </table>
      </xsl:when>
    </xsl:choose>
    <xsl:value-of select="footertext"/>
  </xsl:template>

  <xsl:template match="requiredreading[*/*]">
    <div>
      <xsl:value-of disable-output-escaping="yes" select="headertext"/>
      <xsl:apply-templates mode="readings" select="text" />
      <xsl:value-of disable-output-escaping="yes" select="footertext"/>
    </div>
  </xsl:template>

  <xsl:template mode="readings" match="text">
    <p>
      <xsl:value-of disable-output-escaping="yes" select="title"/>
      <xsl:text> </xsl:text>
      <xsl:value-of disable-output-escaping="yes" select="edition"/><br />
      <xsl:value-of disable-output-escaping="yes" select="author-year"/><br />
      <xsl:value-of disable-output-escaping="yes" select="place-publisher"/>
    </p>
  </xsl:template>

  <!-- ============================= -->
  <!-- Unit Sets -->
  <!-- ============================= -->
  <xsl:template match="structure">
    <xsl:element name="div">
      <xsl:attribute name="class">structure</xsl:attribute>
      <xsl:apply-templates select="section"/>
    </xsl:element>
  </xsl:template>

  <xsl:template match="section">
    <xsl:apply-templates select="sectiontitle"/>
    <xsl:apply-templates select="sectionheader"/>
    <ul>
      <xsl:apply-templates select="line"/>
    </ul>
    <xsl:apply-templates select="sectionfooter"/>
    <xsl:apply-templates select="sectionfootnote"/>
  </xsl:template>

  <xsl:template match="sectiontitle[text()]">
    <h3>
      <xsl:value-of select="."/>
    </h3>
  </xsl:template>

  <xsl:template match="sectionheader[text()]">
    <p>
      <xsl:call-template name="nl2br">
        <xsl:with-param name="string" select="."/>
      </xsl:call-template>
    </p>
  </xsl:template>

  <xsl:template match="line[linetext/text()]">
    <li>
      <xsl:value-of select="." disable-output-escaping="yes"/>
    </li>
  </xsl:template>

  <xsl:template match="line[unitid]">
    <xsl:variable name="url" select="concat('/units/', normalize-space(unitcode[text()]))"/>
    <li class="unit-title">
      <a href="{$url}">
        <xsl:call-template name="humanize">
          <xsl:with-param name="string" select="unittitle"/>
        </xsl:call-template>
      </a>
    </li>
  </xsl:template>

  <xsl:template match="sectionfooter[text()]|sectionfootnote[text()]">
    <p>
      <xsl:value-of select="."/>
    </p>
  </xsl:template>

  <!-- http://www.getsymphony.com/download/xslt-utilities/view/26522/ -->
  <xsl:template name="nl2br">
    <xsl:param name="string"/>
    <xsl:value-of
      select="normalize-space(substring-before($string,'&#10;'))"
      disable-output-escaping="yes"/>
    <xsl:choose>
      <xsl:when test="contains($string,'&#10;')">
        <br/>
        <xsl:call-template name="nl2br">
          <xsl:with-param name="string"
                          select="substring-after($string,'&#10;')"/>
        </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="$string" disable-output-escaping="yes"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!-- This must be last. It will gobble any bad matches -->
  <xsl:template match="*"/>

</xsl:stylesheet>
