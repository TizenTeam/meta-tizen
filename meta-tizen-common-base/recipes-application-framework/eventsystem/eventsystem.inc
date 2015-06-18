DESCRIPTION = "Event system library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/IPC"
LICENSE = "Apache-2.0"
PV = "0.0.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by eventsystem


#PROVIDES by eventsystem
PROVIDES += "eventsystem"


RDEPENDS = ""
#RDEPENDS of eventsystem-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "eventsystem"


DEPENDS = ""
#DEPENDS of eventsystem
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit tizen_cmake
DEPENDS += "dlog"
inherit pkgconfig
DEPENDS += "glib-2.0"
DEPENDS += "ecore"
DEPENDS += "bundle"
DEPENDS += "openssl"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
    cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake \
         ${EXTRA_OECMAKE} .
 oe_runmake
 
 
 
}

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
 mkdir -p ${D}${prefix}/share/license
 
 
}

pkg_postinst_eventsystem() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_eventsystem() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " eventsystem "
PACKAGES += " eventsystem-dev "

eventsystem_files = ""
eventsystem_files += "${prefix}/lib/*.so*"
eventsystem_files += "${prefix}/share/license"
MANIFESTFILES_${PN} = "eventsystem.manifest"

eventsystem-dev_files = ""
eventsystem-dev_files += "${prefix}/include/*.h"
eventsystem-dev_files += "${prefix}/lib/libeventsystem.so"
eventsystem-dev_files += "${prefix}/lib/pkgconfig/*.pc"
MANIFESTFILES_${PN}-dev = "eventsystem.manifest"

FILES_${PN} = "${eventsystem_files}"
FILES_${PN}-dev = "${eventsystem-dev_files}"

PKG_eventsystem= "eventsystem"
PKG_eventsystem-dev= "eventsystem-dev"

require eventsystem-extraconf.inc

