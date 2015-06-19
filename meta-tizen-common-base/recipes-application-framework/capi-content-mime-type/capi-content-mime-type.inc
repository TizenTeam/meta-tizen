DESCRIPTION = "A MIME type library in Tizen C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/IPC"
LICENSE = "Apache-2.0"
PV = "0.0.2"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by capi-content-mime-type


#PROVIDES by capi-content-mime-type
PROVIDES += "capi-content-mime-type"


RDEPENDS = ""
#RDEPENDS of capi-content-mime-type-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "capi-content-mime-type"


DEPENDS = ""
#DEPENDS of capi-content-mime-type
inherit tizen_cmake
DEPENDS += "dlog"
inherit pkgconfig
DEPENDS += "glib-2.0"
DEPENDS += "capi-base-common"
DEPENDS += "xdgmime"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-content-mime-type.manifest .
 
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

pkg_postinst_capi-content-mime-type() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_capi-content-mime-type() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " capi-content-mime-type "
PACKAGES += " capi-content-mime-type-dev "

capi-content-mime-type_files = ""
capi-content-mime-type_files += "${prefix}/lib/*.so*"
MANIFESTFILES_${PN} = "capi-content-mime-type.manifest"

capi-content-mime-type-dev_files = ""
capi-content-mime-type-dev_files += "${prefix}/include/content/*.h"
capi-content-mime-type-dev_files += "${prefix}/lib/lib*.so"
capi-content-mime-type-dev_files += "${prefix}/lib/pkgconfig/*.pc"
MANIFESTFILES_${PN}-dev = "capi-content-mime-type.manifest"

FILES_${PN} = "${capi-content-mime-type_files}"
FILES_${PN}-dev = "${capi-content-mime-type-dev_files}"

PKG_capi-content-mime-type= "capi-content-mime-type"
PKG_capi-content-mime-type-dev= "capi-content-mime-type-dev"

require capi-content-mime-type-extraconf.inc

