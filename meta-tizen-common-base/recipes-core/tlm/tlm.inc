DESCRIPTION = "Login manager for Tizen"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "LGPL-2.1+"
PV = "1.0.3"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by tlm-config-ivi-vtc1010
PROVIDES += "tlm-config-ivi-vtc1010"
# the PROVIDES rules is ignore "tlm-config  "
PROVIDES += "tlm-config"
RPROVIDES_tlm-config-ivi-vtc1010 += "tlm-config"


#PROVIDES by tlm-config-ivi-singleseat
PROVIDES += "tlm-config-ivi-singleseat"
# the PROVIDES rules is ignore "tlm-config  "
PROVIDES += "tlm-config"
RPROVIDES_tlm-config-ivi-singleseat += "tlm-config"


#PROVIDES by tlm-config-ivi-multiseat
PROVIDES += "tlm-config-ivi-multiseat"
# the PROVIDES rules is ignore "tlm-config  "
PROVIDES += "tlm-config"
RPROVIDES_tlm-config-ivi-multiseat += "tlm-config"


#PROVIDES by tlm-config-ivi-singleseat-modello
PROVIDES += "tlm-config-ivi-singleseat-modello"
# the PROVIDES rules is ignore "tlm-config  "
PROVIDES += "tlm-config"
RPROVIDES_tlm-config-ivi-singleseat-modello += "tlm-config"


#PROVIDES by tlm-dev
PROVIDES += "tlm-dev"


#PROVIDES by tlm-doc
PROVIDES += "tlm-doc"


#PROVIDES by tlm-config-ivi-singleseat-ico
PROVIDES += "tlm-config-ivi-singleseat-ico"
# the PROVIDES rules is ignore "tlm-config  "
PROVIDES += "tlm-config"
RPROVIDES_tlm-config-ivi-singleseat-ico += "tlm-config"


#PROVIDES by tlm


RDEPENDS = ""
#RDEPENDS of tlm-config-ivi-vtc1010 (${PN}-config-ivi-vtc1010)
RDEPENDS_${PN}-config-ivi-vtc1010 += "weekeyboard"
RDEPENDS_${PN}-config-ivi-vtc1010 += "tlm"

#RDEPENDS of tlm-config-ivi-singleseat (${PN}-config-ivi-singleseat)
RDEPENDS_${PN}-config-ivi-singleseat += "weekeyboard"
RDEPENDS_${PN}-config-ivi-singleseat += "tlm"

#RDEPENDS of tlm-config-ivi-multiseat (${PN}-config-ivi-multiseat)
RDEPENDS_${PN}-config-ivi-multiseat += "weekeyboard"
RDEPENDS_${PN}-config-ivi-multiseat += "tlm"

#RDEPENDS of tlm-config-ivi-singleseat-modello (${PN}-config-ivi-singleseat-modello)
RDEPENDS_${PN}-config-ivi-singleseat-modello += "weekeyboard"
RDEPENDS_${PN}-config-ivi-singleseat-modello += "Modello-Installer-xwalk"
RDEPENDS_${PN}-config-ivi-singleseat-modello += "tlm"

#RDEPENDS of tlm-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "tlm"

#RDEPENDS of tlm-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "tlm"

#RDEPENDS of tlm-config-ivi-singleseat-ico (${PN}-config-ivi-singleseat-ico)
RDEPENDS_${PN}-config-ivi-singleseat-ico += "tlm"
RDEPENDS_${PN}-config-ivi-singleseat-ico += "ico-uxf-homescreen"

#RDEPENDS of tlm (${PN})
RDEPENDS_${PN} += "libsystemd"
RDEPENDS_${PN} += "glibc"
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "gumd"


DEPENDS = ""
#DEPENDS of tlm
DEPENDS += "libpam"
DEPENDS += "gumd"
inherit pkgconfig
DEPENDS += "glib-2.0"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n tlm-1.0.3
 cp ${S}/packaging/tlm.manifest .
 
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  
  autotools_do_configure
  oe_runmake ${PARALLEL_MAKE}
  
  
  
  
}
EXTRA_OECONF += " --enable-gum "

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 rm -f ${D}${sysconfdir}/tlm.conf
 install -m 755 -d ${D}${systemd_unitdir}/system
 install -m 644 data/tlm.service ${D}${systemd_unitdir}/system
 install -m 755 -d ${D}${sysconfdir}/pam.d
 install -m 644 data/tlm-login ${D}${sysconfdir}/pam.d/
 install -m 644 data/tlm-default-login ${D}${sysconfdir}/pam.d/
 install -m 644 data/tlm-system-login ${D}${sysconfdir}/pam.d/
 install -m 755 -d ${D}${sysconfdir}/session.d
 install -m 755 -d ${D}${sysconfdir}/xdg/weston
 install -m 644 data/tizen-ivi/etc/tlm*.conf ${D}${sysconfdir}
 install -m 755 data/tizen-ivi/etc/session.d/* ${D}${sysconfdir}/session.d/
 install -m 644 data/tizen-ivi/etc/xdg/weston/*.ini ${D}${sysconfdir}/xdg/weston/
 install -m 755 -d ${D}${sysconfdir}/udev/rules.d
 install -m 644 data/tizen-ivi/10-multiseat-vtc1010.rules ${D}${sysconfdir}/udev/rules.d/
 install -m 755 -d ${D}${sysconfdir}/profile.d
 install -m 644 data/tizen-ivi/etc/profile.d/* ${D}${sysconfdir}/profile.d/
 
 
 
}

pkg_postinst_${PN}-config-ivi-singleseat-modello() {
    #!/bin/sh -e

    if [ ! -e $D/etc/tlm.conf ] || [ -h $D/etc/tlm.conf ]; then
    	ln -s -f tlm-singleseat-modello.conf $D/etc/tlm.conf
    fi

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig

}

pkg_postinst_${PN}-config-ivi-multiseat() {
    #!/bin/sh -e

    if [ ! -e $D/etc/tlm.conf ] || [ -h $D/etc/tlm.conf ]; then
    	ln -s -f tlm-multiseat.conf $D/etc/tlm.conf
    fi

}

pkg_postinst_${PN}-config-ivi-singleseat-ico() {
    #!/bin/sh -e

    if [ ! -e $D/etc/tlm.conf ] || [ -h $D/etc/tlm.conf ]; then
    	ln -s -f tlm-singleseat-ico.conf $D/etc/tlm.conf
    fi

}

pkg_postinst_${PN}-config-ivi-singleseat() {
    #!/bin/sh -e

    if [ ! -e $D/etc/tlm.conf ] || [ -h $D/etc/tlm.conf ]; then
    	ln -s -f tlm-singleseat.conf $D/etc/tlm.conf
    fi

}

pkg_postinst_${PN}-config-ivi-vtc1010() {
    #!/bin/sh -e

    if [ ! -e $D/etc/tlm.conf ] || [ -h $D/etc/tlm.conf ]; then
    	ln -s -f tlm-vtc1010.conf $D/etc/tlm.conf
    fi

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ -h $D/etc/tlm.conf ] && [ $1 == 0 ]; then
    	rm -f $D/etc/tlm.conf
    fi

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ -h $D/etc/tlm.conf ] && [ $1 == 0 ]; then
    	rm -f $D/etc/tlm.conf
    fi

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ -h $D/etc/tlm.conf ] && [ $1 == 0 ]; then
    	rm -f $D/etc/tlm.conf
    fi

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ -h $D/etc/tlm.conf ] && [ $1 == 0 ]; then
    	rm -f $D/etc/tlm.conf
    fi

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ -h $D/etc/tlm.conf ] && [ $1 == 0 ]; then
    	rm -f $D/etc/tlm.conf
    fi

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " tlm-config-ivi-vtc1010 "
PACKAGES += " tlm-config-ivi-singleseat "
PACKAGES += " tlm-config-ivi-multiseat "
PACKAGES += " tlm-config-ivi-singleseat-modello "
PACKAGES += " tlm-dev "
PACKAGES += " tlm-config-ivi-singleseat-ico "
PACKAGES += " tlm "

# With Yocto, we cannot package the same file in different packages.
# Need to create a common config package...
PACKAGES += "${PN}-config-ivi-common"
FILES_tlm-config-ivi-common = " \
${sysconfdir}/session.d/user-session \
${sysconfdir}/session.d/genivi-session-singleseat \
${sysconfdir}/profile.d/weston-env-ivi.sh \
${sysconfdir}/xdg/weston/weston-user.ini \
${sysconfdir}/xdg/weston/weston-genivi.ini \
"

tlm-config-ivi-vtc1010_files = ""
tlm-config-ivi-vtc1010_files += "${sysconfdir}/tlm-vtc1010.conf"
tlm-config-ivi-vtc1010_files += "${sysconfdir}/session.d/genivi-session-vtc1010"
tlm-config-ivi-vtc1010_files += "${sysconfdir}/xdg/weston/weston-genivi-vtc1010.ini"
tlm-config-ivi-vtc1010_files += "${sysconfdir}/udev/rules.d/*"
MANIFESTFILES_${PN}-config-ivi-vtc1010 = "tlm.manifest"
RDEPENDS_${PN}-config-ivi-vtc1010 += "${PN}-config-ivi-common"

tlm-config-ivi-singleseat_files = ""
tlm-config-ivi-singleseat_files += "${sysconfdir}/tlm-singleseat.conf"
tlm-config-ivi-singleseat_files += "${sysconfdir}/session.d/genivi-session-singleseat"
MANIFESTFILES_${PN}-config-ivi-singleseat = "tlm.manifest"
RDEPENDS_${PN}-config-ivi-singleseat += "${PN}-config-ivi-common"

tlm-config-ivi-multiseat_files = ""
tlm-config-ivi-multiseat_files += "${sysconfdir}/tlm-multiseat.conf"
tlm-config-ivi-multiseat_files += "${sysconfdir}/session.d/genivi-session-multiseat"
MANIFESTFILES_${PN}-config-ivi-multiseat = "tlm.manifest"
RDEPENDS_${PN}-config-ivi-multiseat += "${PN}-config-ivi-common"

tlm-config-ivi-singleseat-modello_files = ""
tlm-config-ivi-singleseat-modello_files += "${sysconfdir}/tlm-singleseat-modello.conf"
tlm-config-ivi-singleseat-modello_files += "${sysconfdir}/session.d/genivi-session-modello"
tlm-config-ivi-singleseat-modello_files += "${sysconfdir}/session.d/user-session-modello"
tlm-config-ivi-singleseat-modello_files += "${sysconfdir}/xdg/weston/weston-genivi-modello.ini"
tlm-config-ivi-singleseat-modello_files += "${sysconfdir}/xdg/weston/weston-user-modello.ini"
MANIFESTFILES_${PN}-config-ivi-singleseat-modello = "tlm.manifest"
RDEPENDS_${PN}-config-ivi-singleseat-modello += "${PN}-config-ivi-common"

tlm-dev_files = ""
tlm-dev_files += "${prefix}/include/tlm/*.h"
tlm-dev_files += "${prefix}/lib/libtlm*.so"
tlm-dev_files += "${prefix}/lib/pkgconfig/tlm.pc"

tlm-doc_files = ""
tlm-doc_files += "${prefix}/share/gtk-doc/html/tlm/*"

tlm-config-ivi-singleseat-ico_files = ""
tlm-config-ivi-singleseat-ico_files += "${sysconfdir}/tlm-singleseat-ico.conf"
tlm-config-ivi-singleseat-ico_files += "${sysconfdir}/session.d/user-session-ico"
MANIFESTFILES_${PN}-config-ivi-singleseat-ico = "tlm.manifest"
RDEPENDS_${PN}-config-ivi-singleseat-ico += "${PN}-config-ivi-common"

tlm_files = ""
tlm_files += "AUTHORS NEWS README"
tlm_files += "${prefix}/bin/tlm"
tlm_files += "${prefix}/bin/tlm-sessiond"
tlm_files += "${prefix}/bin/tlm-client"
tlm_files += "${prefix}/bin/tlm-launcher"
tlm_files += "${prefix}/lib/libtlm*.so.*"
tlm_files += "${prefix}/lib/tlm/plugins/*.so*"
tlm_files += "${systemd_unitdir}/system/tlm.service"
tlm_files += "${sysconfdir}/pam.d/tlm-login"
tlm_files += "${sysconfdir}/pam.d/tlm-default-login"
tlm_files += "${sysconfdir}/pam.d/tlm-system-login"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/pam.d/tlm-login"
CONFFILES_${PN} += "${sysconfdir}/pam.d/tlm-default-login"
CONFFILES_${PN} += "${sysconfdir}/pam.d/tlm-system-login"
MANIFESTFILES_${PN} = "tlm.manifest"

FILES_${PN}-config-ivi-vtc1010 = "${tlm-config-ivi-vtc1010_files}"
FILES_${PN}-config-ivi-singleseat = "${tlm-config-ivi-singleseat_files}"
FILES_${PN}-config-ivi-multiseat = "${tlm-config-ivi-multiseat_files}"
FILES_${PN}-config-ivi-singleseat-modello = "${tlm-config-ivi-singleseat-modello_files}"
FILES_${PN}-dev = "${tlm-dev_files}"
FILES_${PN}-doc = "${tlm-doc_files}"
FILES_${PN}-config-ivi-singleseat-ico = "${tlm-config-ivi-singleseat-ico_files}"
FILES_${PN} = "${tlm_files}"

PKG_tlm-config-ivi-vtc1010= "tlm-config-ivi-vtc1010"
PKG_tlm-config-ivi-singleseat= "tlm-config-ivi-singleseat"
PKG_tlm-config-ivi-multiseat= "tlm-config-ivi-multiseat"
PKG_tlm-config-ivi-singleseat-modello= "tlm-config-ivi-singleseat-modello"
PKG_tlm-dev= "tlm-dev"
PKG_tlm-doc= "tlm-doc"
PKG_tlm-config-ivi-singleseat-ico= "tlm-config-ivi-singleseat-ico"
PKG_tlm= "tlm"

require tlm-extraconf.inc

