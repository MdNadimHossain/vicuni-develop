<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:str="http://exslt.org/strings"
                exclude-result-prefixes="str">
  <xsl:output method="html"/>
  <xsl:variable name="lowercase" select="'abcdefghijklmnopqrstuvwxyz'"/>
  <xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'"/>

  <xsl:template name="linkify">
    <xsl:param name="text"/>
    <xsl:variable name="link">
      <xsl:choose>
        <xsl:when test="//colleges/college[fullname=$text]">
          <xsl:value-of select="//colleges/college[fullname=$text]/url"/>
        </xsl:when>
        <xsl:when test="//campuses/campus[fullname=$text]">
          <xsl:value-of select="//campuses/campus[fullname=$text]/url"/>
        </xsl:when>
      </xsl:choose>
    </xsl:variable>

    <xsl:choose>
      <xsl:when test="$link != ''">
        <xsl:element name="a">
          <xsl:attribute name="href">
            <xsl:value-of select="$link"/>
          </xsl:attribute>
          <xsl:value-of select="$text"/>
        </xsl:element>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="$text"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="locations[*]">
    <xsl:element name="li">
      <xsl:attribute name="class">course-essentials__item location
      </xsl:attribute>
      <xsl:call-template name="icons">
        <xsl:with-param name="heading">Location:</xsl:with-param>
        <xsl:with-param name="icon">fa-map-marker</xsl:with-param>
      </xsl:call-template>
      <xsl:element name="div">
        <xsl:attribute name="class">course-essentials__item__value
        </xsl:attribute>
        <xsl:apply-templates select="location"/>
      </xsl:element>
    </xsl:element>
  </xsl:template>

  <xsl:template match="location">
    <xsl:call-template name="linkify">
      <xsl:with-param name="text" select="."/>
    </xsl:call-template>
    <xsl:if test="position() != last()">
      <xsl:text>, </xsl:text>
    </xsl:if>
  </xsl:template>

  <xsl:template match="school[text()]">
    <xsl:element name="li">
      <xsl:attribute name="class">course-essentials__item school</xsl:attribute>
      <xsl:call-template name="icons">
        <xsl:with-param name="heading">College:</xsl:with-param>
        <xsl:with-param name="icon">fa-university</xsl:with-param>
      </xsl:call-template>
      <xsl:element name="div">
        <xsl:attribute name="class">course-essentials__item__value
        </xsl:attribute>
        <xsl:call-template name="linkify">
          <xsl:with-param name="text" select="."/>
        </xsl:call-template>
      </xsl:element>
    </xsl:element>
  </xsl:template>

  <xsl:template match="sector[text()]|unitlevel[text()]|unitsetlevel[text()]">
    <xsl:element name="li">
      <xsl:attribute name="class">course-essentials__item study-level
      </xsl:attribute>
      <xsl:call-template name="icons">
        <xsl:with-param name="heading">Study level:</xsl:with-param>
        <xsl:with-param name="icon">fa-line-chart</xsl:with-param>
      </xsl:call-template>
      <xsl:element name="div">
        <xsl:attribute name="class">course-essentials__item__value
        </xsl:attribute>
        <xsl:choose>
          <xsl:when test=".='PG'">
            <xsl:text>Postgraduate</xsl:text>
          </xsl:when>
          <xsl:when test=".='UG'">
            <xsl:text>Undergraduate</xsl:text>
          </xsl:when>
          <xsl:when test=".='TAFE'">
            <xsl:text>Vocational and further education (TAFE)</xsl:text>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="."/>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:element>
    </xsl:element>
  </xsl:template>

  <xsl:template match="course[title/text()]">
    <li>
      <a href="/{url}">
        <xsl:value-of select="title"/>
      </a>
    </li>
  </xsl:template>

  <!-- humanize a string -->
  <xsl:template name="humanize">
    <xsl:param name="string"/>

    <xsl:param name="lowerCased"
               select="translate($string, $uppercase, $lowercase)"/>

    <xsl:param name="upperCased"
               select="translate($string, $lowercase, $uppercase)"/>

    <xsl:choose>
      <xsl:when test="$string = $upperCased">
        <xsl:param name="human">
          <xsl:for-each select="str:tokenize($lowerCased, ' ')">
            <xsl:choose>
              <xsl:when test="position() > 1">
                <xsl:apply-templates select="." mode="humanize"/>
              </xsl:when>
              <xsl:otherwise>
                <xsl:call-template name="titleCase">
                  <xsl:with-param name="string" select="."/>
                </xsl:call-template>
              </xsl:otherwise>
            </xsl:choose>
            <xsl:text> </xsl:text>
          </xsl:for-each>
        </xsl:param>

        <xsl:choose>
          <xsl:when test="substring($human, string-length($human)-2)=' a '">
            <xsl:value-of
              select="substring($human, 0, string-length($human)-2)"/>
            <xsl:text> A</xsl:text>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="normalize-space($human)"/>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="normalize-space($string)"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!-- uppercase humanize words-->
  <xsl:template
    match="*[.='i']|*[.='1a']|*[.='1b']|*[.='2a']|*[.='2b']|*[.='it']|*[.='ohs']|*[.='wan']|*[.='ict']|*[.='afl']|*[.='ip']|*[.='ii']|*[.='iii']|*[.='iv']|*[.='v']|*[.='vi']|*[.='vii']|*[.='viii']|*[.='ix']|*[.='x']|*[.='d.c.']|*[.='sose']|*[.='(aesol)'] "
    mode="humanize">
    <xsl:value-of select="translate(., $lowercase, $uppercase)"/>
  </xsl:template>

  <!-- lowercase humanize words -->
  <xsl:template
    match="*[.='a']|*[.='an']|*[.='the']|*[.='and']|*[.='as']|*[.='at']|*[.='but']|*[.='by']|*[.='for']|*[.='if']|*[.='is']|*[.='in']|*[.='of']|*[.='on']|*[.='or']|*[.='to']|*[.='via']|*[.='with']"
    mode="humanize">
    <xsl:value-of select="."/>
  </xsl:template>

  <!-- title case any remaining humanize words -->
  <xsl:template match="*" mode="humanize">
    <xsl:call-template name="titleCase">
      <xsl:with-param name="string" select="."/>
    </xsl:call-template>
  </xsl:template>

  <!-- uppercases first letter in string -->
  <xsl:template name="titleCase">
    <xsl:param name="string"/>
    <xsl:value-of
      select="translate(substring($string, 1,1), $lowercase, $uppercase)"/>
    <xsl:value-of
      select="translate(substring($string, 2), $uppercase, $lowercase)"/>
  </xsl:template>

  <!-- section heading -->

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

  <xsl:template match="courses[*]">
    <xsl:call-template name="aside-cta-box">
      <xsl:with-param name="modifier">aside-cta-box--secondary</xsl:with-param>
      <xsl:with-param name="content">
        <xsl:call-template name="HeadingWithoutOnThisPage"/>
        <ul class="list--unstyled">
          <xsl:apply-templates match="course"/>
        </ul>
      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>

  <xsl:template match="courses[*]" mode="unitset">
    <xsl:call-template name="aside-cta-box">
      <xsl:with-param name="modifier">aside-cta-box--secondary</xsl:with-param>
      <xsl:with-param name="content">
        <xsl:call-template name="HeadingWithoutOnThisPage">
          <xsl:with-param name="element">
            <xsl:text>unitset-courses</xsl:text>
          </xsl:with-param>
        </xsl:call-template>
        <ul class="list--unstyled">
          <xsl:apply-templates match="course"/>
        </ul>
      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>

  <xsl:template match="unitsets[*]">
    <xsl:call-template name="aside-cta-box">
      <xsl:with-param name="modifier">aside-cta-box--secondary</xsl:with-param>
      <xsl:with-param name="content">
        <xsl:call-template name="HeadingWithoutOnThisPage"/>
        <ul class="list--unstyled">
          <xsl:apply-templates match="unitset"/>
        </ul>
      </xsl:with-param>
    </xsl:call-template>
  </xsl:template>

  <xsl:template match="introduction[text()]">
    <p>
      <xsl:value-of select="." disable-output-escaping="yes"/>
    </p>
  </xsl:template>

  <xsl:template name="aside-cta-head">
    <xsl:param name="label"/>
    <xsl:param name="icon"/>
    <xsl:param name="url"/>

    <xsl:element name="div">
      <xsl:choose>
        <xsl:when test="$url">
          <xsl:attribute name="class">aside-cta-head aside-cta-head--link
          </xsl:attribute>
        </xsl:when>
        <xsl:otherwise>
          <xsl:attribute name="class">aside-cta-head</xsl:attribute>
        </xsl:otherwise>
      </xsl:choose>


      <xsl:element name="span">
        <xsl:attribute name="class">fa-stack aside-cta-head__icon
        </xsl:attribute>
        <xsl:element name="i">
          <xsl:attribute name="class">fa fa-circle fa-stack-2x</xsl:attribute>
          <xsl:comment></xsl:comment>
        </xsl:element>
        <xsl:element name="i">
          <xsl:attribute name="class">fa fa-<xsl:value-of select="$icon"/>
            fa-stack-1x fa-inverse
          </xsl:attribute>
          <xsl:comment></xsl:comment>
        </xsl:element>
      </xsl:element>


      <xsl:element name="h2">
        <xsl:attribute name="class">aside-cta-head__label</xsl:attribute>
        <xsl:attribute name="data-neon-onthispage">false</xsl:attribute>
        <xsl:choose>
          <xsl:when test="$url">
            <xsl:element name="a">
              <xsl:attribute name="href">
                <xsl:value-of select="$url"/>
              </xsl:attribute>
              <xsl:value-of select="$label"/>
            </xsl:element>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="$label"/>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:element>
    </xsl:element>
  </xsl:template>

  <xsl:template name="aside-cta-box">
    <xsl:param name="content"/>
    <xsl:param name="modifier"/>
    <xsl:element name="div">
      <xsl:attribute name="class">
        <xsl:text>aside-cta-box </xsl:text>
        <xsl:value-of select="$modifier"/>
      </xsl:attribute>
      <xsl:copy-of select="$content"/>
    </xsl:element>
  </xsl:template>

  <xsl:template name="icons">
    <xsl:param name="icon"/>
    <xsl:param name="heading"/>
    <xsl:element name="div">
      <xsl:attribute name="class">course-essentials__item__label</xsl:attribute>
      <xsl:element name="span">
        <xsl:attribute name="class">fa-stack fa-fw</xsl:attribute>
        <xsl:element name="i">
          <xsl:attribute name="class">fa fa-circle fa-stack-2x</xsl:attribute>
          <xsl:comment></xsl:comment>
        </xsl:element>
        <xsl:element name="i">
          <xsl:attribute name="class">fa
            <xsl:value-of select="$icon"/> fa-stack-1x fa-inverse
          </xsl:attribute>
          <xsl:comment></xsl:comment>
        </xsl:element>
      </xsl:element>
      <xsl:copy-of select="$heading" disable-output-escaping="yes"/>
    </xsl:element>
  </xsl:template>

</xsl:stylesheet>
