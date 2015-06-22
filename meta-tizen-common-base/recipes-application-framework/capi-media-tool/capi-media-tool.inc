DESCRIPTION = "A Core API media tool library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/IPC"
LICENSE = "Apache-2.0"
PV = "0.1.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by capi-media-tool


#PROVIDES by capi-media-tool
PROVIDES += "capi-media-tool"


#RDEPENDS of capi-media-tool (${PN})
RDEPENDS_${PN} += "libprivilege-control"

#RDEPENDS of capi-media-tool-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "capi-media-tool"


DEPENDS = ""
#DEPENDS of capi-media-tool
inherit tizen_cmake
DEPENDS += "dlog"
inherit pkgconfig
DEPENDS += "glib-2.0"
DEPENDS += "capi-base-common"
DEPENDS += "elementary"
DEPENDS += "app-core-efl"
DEPENDS += "libtbm"

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
 
  MAJORVER=`echo ${PV} | awk 'BEGIN {FS="."}{print $1}'`
  
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
         ${EXTRA_OECMAKE} \
         -DFULLVER=${PV} -DMAJORVER=${MAJORVER} .
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
 
 
}

pkg_postinst_capi-media-tool() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_capi-media-tool() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " capi-media-tool "
PACKAGES += " capi-media-tool-dev "

capi-media-tool_files = ""
capi-media-tool_files += "${prefix}/lib/*.so*"
MANIFESTFILES_${PN} = "capi-media-tool.manifest"

capi-media-tool-dev_files = ""
capi-media-tool-dev_files += "${prefix}/include/media/*.h"
capi-media-tool-dev_files += "${prefix}/lib/lib*.so"
capi-media-tool-dev_files += "${prefix}/lib/pkgconfig/*.pc"
MANIFESTFILES_${PN}-dev = "capi-media-tool.manifest"

FILES_${PN} = "${capi-media-tool_files}"
FILES_${PN}-dev = "${capi-media-tool_files}"

PKG_capi-media-tool= "capi-media-tool"
PKG_capi-media-tool-dev= "capi-media-tool-dev"

require capi-media-tool-extraconf.inc

