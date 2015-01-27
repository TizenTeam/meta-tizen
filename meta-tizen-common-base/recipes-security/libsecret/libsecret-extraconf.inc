# Even with libxslt and docbook-xsl-stylesheets installed
# there were still problems locating the manpages/docbook.xsl file:
# /data/yocto/build/tizen-distro/ivi/x86_64/tmp-glibc/sysroots/x86_64-linux/usr/bin/xsltproc --nonet --stringparam man.output.quietly 1 --stringparam funcsynopsis.style ansi --stringparam man.th.extra1.suppress 1 --stringparam man.authors.section.enabled 0 --stringparam man.copyright.section.enabled 0 http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl docs/man/secret-tool.xml
# I/O error : Attempt to load network entity http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl
# warning: failed to load external entity "http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl"
# cannot parse http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl
#
# Just disable this feature entirely, we don't need to generate documentation.
EXTRA_OECONF += "--disable-manpages --disable-gtk-doc-html"
