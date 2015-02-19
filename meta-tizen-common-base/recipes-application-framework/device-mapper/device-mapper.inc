DESCRIPTION = "Device mapper utility"
HOMEPAGE = "http://sources.redhat.com/dm"
SECTION = "Base/Device Management"
LICENSE = "GPL-2.0"
PV = "1.02.77"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libdevmapper
PROVIDES += "libdevmapper"


#PROVIDES by device-mapper


#PROVIDES by device-mapper-dev
PROVIDES += "device-mapper-dev"


RDEPENDS = ""
#RDEPENDS of device-mapper (${PN})
RDEPENDS_${PN} += "libdevmapper"

#RDEPENDS of device-mapper-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libdevmapper"
RDEPENDS_${PN}-dev += "device-mapper"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n LVM2.2.02.98
 
 
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
  make device-mapper
  
  
  
}
EXTRA_OECONF += " --with-user= --with-group= --with-device-uid=0 --with-device-gid=6 --with-device-mode=0660 --enable-pkgconfig"

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 make install_device-mapper DESTDIR=${D} usrlibdir=${D}/usr/lib
 sed -i 's/ (.*)//g' ${D}${prefix}/lib/pkgconfig/*.pc
 
 
 
}

pkg_postinst_libdevmapper() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libdevmapper() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libdevmapper "
PACKAGES += " device-mapper "
PACKAGES += " device-mapper-dev "

libdevmapper_files = ""
libdevmapper_files += "/${prefix}/lib/libdevmapper.so.*"

device-mapper_files = ""
device-mapper_files += "/sbin/dmsetup"
device-mapper_files += "${mandir}/man8/dmsetup.8.gz"

device-mapper-dev_files = ""
device-mapper-dev_files += "/${prefix}/lib/libdevmapper.so"
device-mapper-dev_files += "${prefix}/include/libdevmapper.h"
device-mapper-dev_files += "${prefix}/lib/pkgconfig/*.pc"

FILES_libdevmapper = "${libdevmapper_files}"
FILES_${PN} = "${device-mapper_files}"
FILES_${PN}-dev = "${device-mapper-dev_files}"

PKG_libdevmapper= "libdevmapper"
PKG_device-mapper= "device-mapper"
PKG_device-mapper-dev= "device-mapper-dev"

require device-mapper-extraconf.inc

