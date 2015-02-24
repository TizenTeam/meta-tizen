DESCRIPTION = "Deviced"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Framework/system"
LICENSE = "Apache-2.0"
PV = "1.0.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest cmake

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libdevman-dev
PROVIDES += "libdevman-dev"


#PROVIDES by libhaptic
PROVIDES += "libhaptic"


#PROVIDES by libdeviced
PROVIDES += "libdeviced"


#PROVIDES by sysman-dev
PROVIDES += "sysman-dev"


#PROVIDES by deviced-deviced
PROVIDES += "deviced-deviced"


#PROVIDES by libslp-pm-dev
PROVIDES += "libslp-pm-dev"


#PROVIDES by libhaptic-plugin-dev
PROVIDES += "libhaptic-plugin-dev"


#PROVIDES by libslp-pm
PROVIDES += "libslp-pm"


#PROVIDES by libdeviced-dev
PROVIDES += "libdeviced-dev"


#PROVIDES by sysman-internal-dev
PROVIDES += "sysman-internal-dev"


#PROVIDES by libhaptic-dev
PROVIDES += "libhaptic-dev"


#PROVIDES by libdevman-haptic-dev
PROVIDES += "libdevman-haptic-dev"


#PROVIDES by deviced


#PROVIDES by sysman
PROVIDES += "sysman"


#PROVIDES by libdevman
PROVIDES += "libdevman"


RDEPENDS = ""
#RDEPENDS of libdevman-dev (libdevman-dev)
RDEPENDS_libdevman-dev += "libdevman"

#RDEPENDS of libdeviced (lib${PN})
RDEPENDS_lib${PN} += "deviced"

#RDEPENDS of sysman-dev (sysman-dev)
RDEPENDS_sysman-dev += "sysman"

#RDEPENDS of libslp-pm-dev (libslp-pm-dev)
RDEPENDS_libslp-pm-dev += "libslp-pm"

#RDEPENDS of libhaptic-plugin-dev (libhaptic-plugin-dev)
RDEPENDS_libhaptic-plugin-dev += "libhaptic"

#RDEPENDS of libslp-pm (libslp-pm)
RDEPENDS_libslp-pm += "libdeviced"

#RDEPENDS of libdeviced-dev (lib${PN}-dev)
RDEPENDS_lib${PN}-dev += "libdeviced"

#RDEPENDS of sysman-internal-dev (sysman-internal-dev)
RDEPENDS_sysman-internal-dev += "sysman"

#RDEPENDS of libhaptic-dev (libhaptic-dev)
RDEPENDS_libhaptic-dev += "libhaptic"

#RDEPENDS of deviced (${PN})
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "vconf"

#RDEPENDS of libdevman-haptic-dev (libdevman-haptic-dev)
RDEPENDS_libdevman-haptic-dev += "libdevman-dev"

#RDEPENDS of sysman (sysman)
RDEPENDS_sysman += "libdeviced"

#RDEPENDS of libdevman (libdevman)
RDEPENDS_libdevman += "libdeviced"


DEPENDS = ""
#DEPENDS of deviced
DEPENDS += "smack"
DEPENDS += "edbus"
inherit tizen_cmake
DEPENDS += "attr"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "notification"
DEPENDS += "tizen-platform-config"
DEPENDS += "syspopup"
inherit pkgconfig
DEPENDS += "libtapi"
DEPENDS += "libdevice-node"
DEPENDS += "systemd"
DEPENDS += "dlog"
DEPENDS += "ecore"
DEPENDS += "sensord"
DEPENDS += "vconf"
DEPENDS += "dbus-glib"
DEPENDS += "capi-base-common"
DEPENDS += "openssl"
DEPENDS += "smack"
DEPENDS += "libprivilege-control"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
}


do_configure() {

   cd ${S}
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
 	     -DTZ_SYS_ETC=${sysconfdir} \
 	     -DCMAKE_INSTALL_PREFIX=${prefix} \
 	     -DARCH=emulator \
 	     -DTIZEN_DISPLAY:BOOL=ON \
         ${EXTRA_OECMAKE} . 
 	#eol
 
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 cp ${S}/packaging/deviced.manifest .
 cp ${S}/packaging/libdeviced.manifest .
 cp ${S}/packaging/sysman.manifest .
 cp ${S}/packaging/libslp-pm.manifest .
 cp ${S}/packaging/haptic.manifest .
 cp ${S}/packaging/devman.manifest .
 oe_runmake ${PARALLEL_MAKE}
 
 
 
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
 
 
 mkdir -p ${D}/${systemd_unitdir}/system/multi-user.target.wants 
 ln -s ../deviced.service  ${D}/${systemd_unitdir}/system/multi-user.target.wants/deviced.service  
 
 mkdir -p ${D}/${systemd_unitdir}/system/sockets.target.wants 
 ln -s ../deviced.socket  ${D}/${systemd_unitdir}/system/sockets.target.wants/deviced.socket  
 
 mkdir -p ${D}/${systemd_unitdir}/system/graphical.target.wants 
 ln -s ../zbooting-done.service  ${D}/${systemd_unitdir}/system/graphical.target.wants/zbooting-done.service  
 
 mkdir -p ${D}/${systemd_unitdir}/system/graphical.target.wants 
 ln -s ../devicectl-stop@.service  ${D}/${systemd_unitdir}/system/graphical.target.wants/devicectl-stop@.service  
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    #memory type vconf key init
    users_gid=$(getent group users | cut -f3 -d':')
    vconftool set -t int memory/sysman/usbhost_status -1 -i
    vconftool set -t int memory/sysman/mmc -1 -i
    vconftool set -t int memory/sysman/earjack_key 0 -i
    vconftool set -t int memory/sysman/added_usb_storage 0 -i
    vconftool set -t int memory/sysman/removed_usb_storage 0 -i
    vconftool set -t int memory/sysman/charger_status -1 -i
    vconftool set -t int memory/sysman/charge_now -1 -i
    vconftool set -t int memory/sysman/battery_status_low -1 -i
    vconftool set -t int memory/sysman/battery_capacity -1 -i
    vconftool set -t int memory/sysman/usb_status -1 -i
    vconftool set -t int memory/sysman/earjack -1 -i
    vconftool set -t int memory/sysman/low_memory 1 -i
    vconftool set -t int memory/sysman/sliding_keyboard -1 -i
    vconftool set -t int memory/sysman/mmc_mount -1 -i
    vconftool set -t int memory/sysman/mmc_unmount -1 -i
    vconftool set -t int memory/sysman/mmc_format -1 -i
    vconftool set -t int memory/sysman/mmc_format_progress 0 -i
    vconftool set -t int memory/sysman/mmc_err_status 0 -i
    vconftool set -t int memory/sysman/power_off 0 -g "$users_gid" -i -f
    vconftool set -t int memory/sysman/battery_level_status -1 -i
    vconftool set -t string memory/private/sysman/added_storage_uevent "" -i
    vconftool set -t string memory/private/sysman/removed_storage_uevent "" -g "$users_gid" -i
    vconftool set -t int memory/sysman/hdmi 0 -i
    vconftool set -t int memory/sysman/stime_changed 0 -i
    #db type vconf key init
    vconftool set -t int db/sysman/mmc_dev_changed 0 -i
    vconftool set -t int memory/pm/state 0 -i -g "$users_gid"
    vconftool set -t int memory/pm/battery_timetofull -1 -i
    vconftool set -t int memory/pm/battery_timetoempty -1 -i
    vconftool set -t int memory/pm/sip_status 0 -i -g "$users_gid"
    vconftool set -t int memory/pm/custom_brightness_status 0 -i -g "$users_gid"
    vconftool set -t bool memory/pm/brt_changed_lpm 0 -i
    vconftool set -t int memory/pm/current_brt 60 -i -g "$users_gid"
    systemctl daemon-reload
    if [ "$1" == "1" ]; then
        systemctl restart deviced.service
    	systemctl restart zbooting-done.service
    fi

}

pkg_postinst_libslp-pm() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libhaptic() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_sysman() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libdevman() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libdeviced() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_prerm_${PN}() {
    #!/bin/sh -e

    if [ "$1" == "0" ]; then
        systemctl stop deviced.service
    	systemctl stop zbooting-done.service
    fi

}

pkg_postrm_libhaptic() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    systemctl daemon-reload

}

pkg_postrm_libslp-pm() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libdeviced() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libdevman() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_sysman() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libdevman-dev "
PACKAGES += " libhaptic "
PACKAGES += " sysman-dev "
PACKAGES += " libslp-pm-dev "
PACKAGES += " deviced "
PACKAGES += " libdevman "
PACKAGES += " libslp-pm "
PACKAGES += " libdeviced-dev "
PACKAGES += " sysman-internal-dev "
PACKAGES += " libhaptic-dev "
PACKAGES += " libhaptic-plugin-dev "
PACKAGES += " libdevman-haptic-dev "
PACKAGES += " libdeviced "
PACKAGES += " sysman "

libdevman-dev_files = ""
libdevman-dev_files += "${prefix}/include/devman/devman.h"
libdevman-dev_files += "${prefix}/include/devman/devman_image.h"
libdevman-dev_files += "${prefix}/include/devman/devman_managed.h"
libdevman-dev_files += "${prefix}/include/devman/devman_haptic.h"
libdevman-dev_files += "${prefix}/include/devman/SLP_devman_PG.h"
libdevman-dev_files += "${prefix}/lib/pkgconfig/devman.pc"
libdevman-dev_files += "${prefix}/lib/libdevman.so"

libhaptic_files = ""
libhaptic_files += "${prefix}/lib/libhaptic.so.*"
MANIFESTFILES_libhaptic = "haptic.manifest"

sysman-dev_files = ""
sysman-dev_files += "${prefix}/include/sysman/sysman.h"
sysman-dev_files += "${prefix}/include/sysman/sysman_managed.h"
sysman-dev_files += "${prefix}/include/sysman/SLP_sysman_PG.h"
sysman-dev_files += "${prefix}/lib/pkgconfig/sysman.pc"
sysman-dev_files += "${prefix}/lib/libsysman.so"

libslp-pm-dev_files = ""
libslp-pm-dev_files += "${prefix}/include/pmapi/pmapi.h"
libslp-pm-dev_files += "${prefix}/include/pmapi/pmapi_managed.h"
libslp-pm-dev_files += "${prefix}/include/pmapi/SLP_pm_PG.h"
libslp-pm-dev_files += "${prefix}/lib/pkgconfig/pmapi.pc"
libslp-pm-dev_files += "${prefix}/lib/libpmapi.so"

deviced_files = ""
deviced_files += "${sysconfdir}/dbus-1/system.d/deviced.conf"
deviced_files += "${prefix}/bin/deviced-pre.sh"
deviced_files += "${prefix}/bin/deviced"
deviced_files += "${prefix}/bin/devicectl"
deviced_files += "${prefix}/bin/movi_format.sh"
deviced_files += "${systemd_unitdir}/system/multi-user.target.wants/deviced.service"
deviced_files += "${systemd_unitdir}/system/sockets.target.wants/deviced.socket"
deviced_files += "${systemd_unitdir}/system/graphical.target.wants/zbooting-done.service"
deviced_files += "${systemd_unitdir}/system/graphical.target.wants/devicectl-stop@.service"
deviced_files += "${systemd_unitdir}/system/deviced.service"
deviced_files += "${systemd_unitdir}/system/deviced.socket"
deviced_files += "${systemd_unitdir}/system/deviced-pre.service"
deviced_files += "${systemd_unitdir}/system/zbooting-done.service"
deviced_files += "${systemd_unitdir}/system/devicectl-start@.service"
deviced_files += "${systemd_unitdir}/system/devicectl-stop@.service"

deviced_files += "${prefix}/lib/systemd/system/deviced-pre.service"
deviced_files += "${prefix}/lib/systemd/system/zbooting-done.service"
deviced_files += "${prefix}/lib/systemd/system/devicectl-stop@.service"
deviced_files += "${prefix}/lib/systemd/system/devicectl-start@.service"
deviced_files += "${prefix}/lib/systemd/system/deviced.socket"
deviced_files += "${prefix}/lib/systemd/system/deviced.service"

CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/dbus-1/system.d/deviced.conf"
MANIFESTFILES_${PN} = "deviced.manifest"

libdevman_files = ""
libdevman_files += "${prefix}/bin/display_wd"
libdevman_files += "${prefix}/lib/libdevman.so.*"
MANIFESTFILES_libdevman = "devman.manifest"

libslp-pm_files = ""
libslp-pm_files += "${prefix}/lib/libpmapi.so.*"
MANIFESTFILES_libslp-pm = "libslp-pm.manifest"

libdeviced-dev_files = ""
libdeviced-dev_files += "${prefix}/include/deviced/*.h"
libdeviced-dev_files += "${prefix}/lib/libdeviced.so"
libdeviced-dev_files += "${prefix}/lib/pkgconfig/deviced.pc"

sysman-internal-dev_files = ""
sysman-internal-dev_files += "${prefix}/include/sysman/sysman-internal.h"

libhaptic-dev_files = ""
libhaptic-dev_files += "${prefix}/include/haptic/haptic.h"
libhaptic-dev_files += "${prefix}/lib/libhaptic.so"
libhaptic-dev_files += "${prefix}/lib/pkgconfig/haptic.pc"

libhaptic-plugin-dev_files = ""
libhaptic-plugin-dev_files += "${prefix}/include/haptic/haptic_module.h"
libhaptic-plugin-dev_files += "${prefix}/include/haptic/haptic_plugin_intf.h"
libhaptic-plugin-dev_files += "${prefix}/include/haptic/SLP_haptic_PG.h"
libhaptic-plugin-dev_files += "${prefix}/lib/pkgconfig/haptic-plugin.pc"

libdevman-haptic-dev_files = ""
libdevman-haptic-dev_files += "${prefix}/include/devman/devman_haptic_ext.h"
libdevman-haptic-dev_files += "${prefix}/include/devman/devman_haptic_ext_core.h"
libdevman-haptic-dev_files += "${prefix}/lib/pkgconfig/devman_haptic.pc"

libdeviced_files = ""
libdeviced_files += "${prefix}/lib/libdeviced.so.*"
MANIFESTFILES_lib${PN} = "deviced.manifest"

sysman_files = ""
sysman_files += "${prefix}/lib/libsysman.so.*"
MANIFESTFILES_sysman = "sysman.manifest"

FILES_libdevman-dev = "${libdevman-dev_files}"
FILES_libhaptic = "${libhaptic_files}"
FILES_sysman-dev = "${sysman-dev_files}"
FILES_libslp-pm-dev = "${libslp-pm-dev_files}"
FILES_${PN} = "${deviced_files}"
FILES_libdevman = "${libdevman_files}"
FILES_libslp-pm = "${libslp-pm_files}"
FILES_lib${PN}-dev = "${libdeviced-dev_files}"
FILES_sysman-internal-dev = "${sysman-internal-dev_files}"
FILES_libhaptic-dev = "${libhaptic-dev_files}"
FILES_libhaptic-plugin-dev = "${libhaptic-plugin-dev_files}"
FILES_libdevman-haptic-dev = "${libdevman-haptic-dev_files}"
FILES_lib${PN} = "${libdeviced_files}"
FILES_sysman = "${sysman_files}"

PKG_libdevman-dev= "libdevman-dev"
PKG_libhaptic= "libhaptic"
PKG_sysman-dev= "sysman-dev"
PKG_libslp-pm-dev= "libslp-pm-dev"
PKG_deviced= "deviced"
PKG_libdevman= "libdevman"
PKG_libslp-pm= "libslp-pm"
PKG_libdeviced-dev= "libdeviced-dev"
PKG_sysman-internal-dev= "sysman-internal-dev"
PKG_libhaptic-dev= "libhaptic-dev"
PKG_libhaptic-plugin-dev= "libhaptic-plugin-dev"
PKG_libdevman-haptic-dev= "libdevman-haptic-dev"
PKG_libdeviced= "libdeviced"
PKG_sysman= "sysman"

require deviced-extraconf.inc

