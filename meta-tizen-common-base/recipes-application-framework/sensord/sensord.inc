DESCRIPTION = "Sensor daemon"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Sensor Framework"
LICENSE = "Apache-2.0"
PV = "1.0.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libsensord-dev
PROVIDES += "libsensord-dev"


#PROVIDES by sensord-sensord
PROVIDES += "sensord-sensord"


#PROVIDES by sensord


#PROVIDES by libsensord
PROVIDES += "libsensord"
PROVIDES += "sensor"


RDEPENDS = ""
#RDEPENDS of libsensord-dev (lib${PN}-dev)
RDEPENDS_lib${PN}-dev += "sensord"

#RDEPENDS of sensord-sensord (${PN}-${PN})
RDEPENDS_${PN}-${PN} += "sensord"

#RDEPENDS of libsensord (lib${PN})
RDEPENDS_lib${PN} += "sensord"


DEPENDS = ""
#DEPENDS of sensord
DEPENDS += "systemd"
inherit tizen_cmake
DEPENDS += "attr"
DEPENDS += "capi-system-info"
DEPENDS += "libxml2"
inherit pkgconfig
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "vconf"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
}

do_configure() {
 cd ${S}
 cp ${S}/packaging/sensord.manifest .
 cp ${S}/packaging/libsensord.manifest .
 
 cmake . -DCMAKE_INSTALL_PREFIX=${prefix} -DACCEL=ON \
 	-DGYRO=ON -DPROXI=ON -DLIGHT=ON \
 	-DGEO=ON -DPRESSURE=ON -DTEMPERATURE=ON \
 	-DORIENTATION=ON -DGRAVITY=ON \
 	-DLINEAR_ACCEL=ON -DRV=ON \
 	-DTEST_SUITE=OFF \
 	-DLIBDIR=${prefix}/lib -DINCLUDEDIR=${prefix}/include
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
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
         LIBDIR=${prefix}/lib \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
 mkdir -p ${D}/${systemd_unitdir}/system/multi-user.target.wants 
 ln -s ../sensord.service  ${D}/${systemd_unitdir}/system/multi-user.target.wants/sensord.service  
 
 mkdir -p ${D}/${systemd_unitdir}/system/sockets.target.wants 
 ln -s ../sensord.socket  ${D}/${systemd_unitdir}/system/sockets.target.wants/sensord.socket  
 
 
}

pkg_postinst_libsensord() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    systemctl daemon-reload

}

pkg_postrm_libsensord() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    systemctl daemon-reload

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libsensord-dev "
PACKAGES += " sensord "
PACKAGES += " libsensord "

libsensord-dev_files = ""
libsensord-dev_files += "${prefix}/include/sensor/*.h"
libsensord-dev_files += "${prefix}/include/sf_common/*.h"
libsensord-dev_files += "${prefix}/lib/libsensor.so"
libsensord-dev_files += "${prefix}/lib/pkgconfig/sensor.pc"
libsensord-dev_files += "${prefix}/lib/pkgconfig/sf_common.pc"
libsensord-dev_files += "${prefix}/lib/pkgconfig/sensord-server.pc"

sensord_files = ""
sensord_files += "/usr/etc/sensor_plugins.xml"
sensord_files += "/usr/etc/sensors.xml"
sensord_files += "/usr/etc/virtual_sensors.xml"
sensord_files += "${prefix}/bin/sensord"
sensord_files += "${systemd_unitdir}/system/sensord.service"
sensord_files += "${systemd_unitdir}/system/sensord.socket"
sensord_files += "${prefix}/lib/systemd/system/sensord.service"
sensord_files += "${prefix}/lib/systemd/system/sensord.socket"
sensord_files += "${systemd_unitdir}/system/multi-user.target.wants/sensord.service"
sensord_files += "${systemd_unitdir}/system/sockets.target.wants/sensord.socket"
MANIFESTFILES_${PN} = "sensord.manifest"

libsensord_files = ""
libsensord_files += "${prefix}/lib/libsensor.so.*"
libsensord_files += "${prefix}/lib/sensord/*.so*"
libsensord_files += "${prefix}/lib/libsensord-share.so"
libsensord_files += "${prefix}/lib/libsensord-server.so"
MANIFESTFILES_lib${PN} = "libsensord.manifest"

FILES_lib${PN}-dev = "${libsensord-dev_files}"
FILES_${PN} = "${sensord_files}"
FILES_lib${PN} = "${libsensord_files}"

PKG_libsensord-dev= "libsensord-dev"
PKG_sensord= "sensord"
PKG_libsensord= "libsensord"

require sensord-extraconf.inc

