DESCRIPTION = "Alarm library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"
PV = "0.4.178"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep
inherit cmake tizen_cmake

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by alarm-manager


#PROVIDES by libalarm
PROVIDES += "libalarm"


#PROVIDES by alarm-server
PROVIDES += "alarm-server"


#PROVIDES by libalarm-dev
PROVIDES += "libalarm-dev"


RDEPENDS = ""
#RDEPENDS of libalarm (libalarm)
RDEPENDS_libalarm += "alarm-server"

#RDEPENDS of alarm-server (alarm-server)
RDEPENDS_alarm-server += "systemd"

#RDEPENDS of libalarm-dev (libalarm-dev)
RDEPENDS_libalarm-dev += "libalarm"


DEPENDS = ""
#DEPENDS of alarm-manager
DEPENDS += "dlog"
DEPENDS += "app-svc"
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "bundle"
DEPENDS += "aul"
DEPENDS += "dbus-glib"
DEPENDS += "glib-2.0"
DEPENDS += "vconf"
DEPENDS += "libslp-db-util"
#DEPENDS += "sqlite3"
DEPENDS += "pkgmgr-info"
#DEPENDS += "gio-2.0"
#DEPENDS += "gio-unix-2.0"
DEPENDS += "capi-system-device"
#DEPENDS += "python-xml"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
# cp ${S}/packaging/alarm-manager.manifest .
 
 
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

  export CFLAGS="$CFLAGS -DTIZEN_DEBUG_ENABLE"
  export CXXFLAGS="$CXXFLAGS -DTIZEN_DEBUG_ENABLE"
  export FFLAGS="$FFLAGS -DTIZEN_DEBUG_ENABLE"

   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DFULLVER=${PV} \
         -DMAJORVER=0 \
         -D_APPFW_FEATURE_ALARM_MANAGER_MODULE_LOG:BOOL=ON \
         ${EXTRA_OECMAKE} . 

  oe_runmake

  
  
}
EXTRA_OECONF += " --disable-static"

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 install -d ${D}${systemd_unitdir}/system/multi-user.target.wants
 install -m0644 ${S}/packaging/alarm-server.service ${D}${systemd_unitdir}/system
 ln -sf ../alarm-server.service ${D}${systemd_unitdir}/system/multi-user.target.wants/alarm-server.service
 
 mkdir -p ${D}/${sysconfdir}/dbus-1/system.d
 install -m0644  ${S}/alarm-service.conf ${D}${sysconfdir}/dbus-1/system.d/
 
 
}

pkg_postinst_alarm-server() {
    #!/bin/sh -e

    vconftool set -t double db/system/timechange_external 0 -u 200 -g 5000 -s system::vconf_system
    vconftool set -t int memory/system/timechanged 0 -i -u 200 -g 5000 -s system::vconf_system

    chsmack -a System %{TZ_SYS_DB}/.alarmmgr.db
    chsmack -a System %{TZ_SYS_DB}/.alarmmgr.db-journal
    chown system:system /var/log/alarmmgr.log

}

pkg_postinst_libalarm() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_prerm_alarm-server() {
    #!/bin/sh -e

    if [ $1 == 0 ]; then
        systemctl stop alarm-server.service
    fi

}

pkg_postrm_libalarm() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_alarm-server() {
    #!/bin/sh -e

    systemctl daemon-reload
    if [ "$1" == 1 ]; then
        systemctl restart net-config.service
    fi

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libalarm "
PACKAGES += " alarm-server "
PACKAGES += " libalarm-dev "

libalarm_files = ""
libalarm_files += "${prefix}/lib/libalarm.so.*"
MANIFESTFILES_libalarm = "alarm-lib.manifest"

alarm-server_files = ""
alarm-server_files += "${prefix}/bin/alarm-server"
alarm-server_files += "${prefix}/bin/alarmmgr*"
alarm-server_files += "${systemd_unitdir}/system/alarm-server.service"
alarm-server_files += "${systemd_unitdir}/system/multi-user.target.wants/alarm-server.service"
alarm-server_files += "${sysconfdir}/dbus-1/system.d/alarm-service.conf"
alarm-server_files += "${sysconfdir}/dump.d/module.d/alarmmgr_log_dump.sh"
MANIFESTFILES_alarm-server = "alarm-server.manifest"

libalarm-dev_files = ""
libalarm-dev_files += "${prefix}/include/*.h"
libalarm-dev_files += "${prefix}/lib/pkgconfig/*.pc"
libalarm-dev_files += "${prefix}/lib/libalarm.so"
MANIFESTFILES_libalarm-dev = "alarm-lib.manifest"

FILES_libalarm = "${libalarm_files}"
FILES_alarm-server = "${alarm-server_files}"
FILES_libalarm-dev = "${libalarm-dev_files}"

PKG_libalarm= "libalarm"
PKG_alarm-server= "alarm-server"
PKG_libalarm-dev= "libalarm-dev"

require alarm-manager-extraconf.inc

