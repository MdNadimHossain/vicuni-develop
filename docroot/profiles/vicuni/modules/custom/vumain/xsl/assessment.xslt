<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"/>
  <xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'"/>
  <xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'"/>

  <xsl:template match="/">
    <xsl:apply-templates select="assessment" mode="assessment"/>
  </xsl:template>


  <!-- uppercases first letter in string -->
  <xsl:template name="titleCase">
    <xsl:param name="string"/>
    <xsl:value-of
      select="translate(substring($string, 1,1), $lowercase, $uppercase)"/>
    <xsl:value-of
      select="translate(substring($string, 2), $uppercase, $lowercase)"/>
  </xsl:template>

  <!-- Use this to translate node names to headings -->
  <xsl:template name="NameMapping">
    <xsl:param name="element" select="name()"/>
    <xsl:choose>
      <xsl:when test="$element = 'requiredreading'">Required reading</xsl:when>
      <xsl:when test="$element = 'pre-requisites'">Prerequisites</xsl:when>
      <xsl:when test="$element = 'courses'">Courses this unit belongs to
      </xsl:when>
      <xsl:when test="$element = 'unitsets'">Specialisations this unit belongs
        to
      </xsl:when>
      <xsl:when test="$element = 'structure'">Unitset Structure</xsl:when>
      <xsl:when test="$element = 'unitset-courses'">Courses this unitset belongs
        to
      </xsl:when>
      <xsl:otherwise>
        <xsl:call-template name="titleCase">
          <xsl:with-param name="string" select="$element"/>
        </xsl:call-template>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  <xsl:template name="backToTop">
    <div class="back-to-top">
      <a href="#page">Back to top</a>
    </div>
  </xsl:template>
  <xsl:template name="Heading">
    <xsl:param name="element" select="name()"/>
    <h2>
      <xsl:call-template name="NameMapping">
        <xsl:with-param name="element" select="name()"/>
      </xsl:call-template>
    </h2>
  </xsl:template>


  <xsl:template name="HeadingWithoutOnThisPage">
    <xsl:param name="element" select="name()"/>
    <h3 data-neon-onthispage="false">
      <xsl:call-template name="NameMapping">
        <xsl:with-param name="element" select="$element"/>
      </xsl:call-template>
    </h3>
  </xsl:template>

  <xsl:template match="assessment[*]" mode="assessment">
    <div id="assessment">
      <xsl:call-template name="Heading"/>
      <xsl:apply-templates mode="assessment" select="headertext"/>
      <xsl:apply-templates mode="assessment" select="items"/>
      <xsl:apply-templates mode="assessment" select="footertext"/>
    </div>
    <xsl:call-template name="backToTop"/>
  </xsl:template>

  <xsl:template
    mode="assessment"
    match="headertext[text()]|footertext[text()]">
    <p>
      <xsl:value-of
        disable-output-escaping="yes"
        select="."/>
    </p>
  </xsl:template>

  <xsl:template mode="assessment" match="items">
    <xsl:if test="*">
      <table>
        <thead>
          <tr>
            <th>Assessment type</th>
            <th>Description</th>
            <th>Grade</th>
          </tr>
        </thead>
        <tbody>
          <xsl:apply-templates mode="assessment" select="item"/>
        </tbody>
      </table>
    </xsl:if>
  </xsl:template>

  <xsl:template mode="assessment" match="item">
    <tr>
      <td>
        <xsl:value-of disable-output-escaping="yes" select="type"/>
      </td>
      <td>
        <xsl:value-of disable-output-escaping="yes" select="description"/>
      </td>
      <td>
        <xsl:value-of disable-output-escaping="yes" select="grade"/>
      </td>
    </tr>
  </xsl:template>

  <xsl:template mode="assessment" match="*"/>


</xsl:stylesheet>
