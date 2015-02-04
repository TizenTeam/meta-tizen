DESCRIPTION = "Multimedia Framework LOG Lib"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/LOG"
LICENSE = "Apache-2.0"
PV = "0.1.9"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libmm-log


#PROVIDES by libmm-log-dev
PROVIDES += "libmm-log-dev"


RDEPENDS = ""

DEPENDS = ""
#DEPENDS of libmm-log
inherit pkgconfig
DEPENDS += "dlog"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libmm-log-0.1.9
 ./autogen.sh
 
 
 
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
  
  export CFLAGS+=" -DUSE_DLOG"
  
  
  
  autotools_do_configure
  make ${PARALLEL_MAKE}
  
  
  
}
EXTRA_OECONF += " --disable-static --prefix=${prefix} --enable-dlog"

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
 cp LICENSE.APLv2 ${D}${prefix}/share/license/libmm-log
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libmm-log-dev "

libmm-log-dev_files = ""
libmm-log-dev_files += "${prefix}/share/license/libmm-log"
libmm-log-dev_files += "${prefix}/include/mm_log/mm_log.h"
libmm-log-dev_files += "${prefix}/lib/pkgconfig/mm-log.pc"

FILES_${PN}-dev = "${libmm-log-dev_files}"

PKG_libmm-log-dev= "libmm-log-dev"

require libmm-log-extraconf.inc

