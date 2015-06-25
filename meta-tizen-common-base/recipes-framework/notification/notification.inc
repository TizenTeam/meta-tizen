DESCRIPTION = "Notification Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"
PV = "0.2.34"
PR = "1"

SRC_URI = ""
SRC_URI += "file://notification_DB_init.sh"

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by notification-service-dev
PROVIDES += "notification-service-dev"


#PROVIDES by notification


#PROVIDES by notification-dev
PROVIDES += "notification-dev"


RDEPENDS = ""
#RDEPENDS of notification-service-dev (${PN}-service-dev)
RDEPENDS_${PN}-service-dev += "notification"

#RDEPENDS of notification (${PN})
RDEPENDS_${PN} += "sqlite3"
RDEPENDS_${PN} += "glibc"
RDEPENDS_${PN} += "libtzplatform-config"

#RDEPENDS of notification-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "notification"


DEPENDS = ""
#DEPENDS of notification
inherit tizen_cmake
DEPENDS += "dbus-glib"
DEPENDS += "eina"
DEPENDS += "dbus"
DEPENDS += "app-svc"
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "bundle"
DEPENDS += "aul"
DEPENDS += "ail"
DEPENDS += "dlog"
DEPENDS += "ecore"
DEPENDS += "sqlite3"
DEPENDS += "libcom-core"
DEPENDS += "capi-appfw-application"
DEPENDS += "capi-appfw-package-manager"
DEPENDS += "edbus"
DEPENDS += "elementary"
DEPENDS += "vconf"
DEPENDS += "libslp-db-util"

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
 
 export CFLAGS="$CFLAGS -DTIZEN_ENGINEER_MODE"
 export CXXFLAGS="$CXXFLAGS -DTIZEN_ENGINEER_MODE"
 export FFLAGS="$FFLAGS -DTIZEN_ENGINEER_MODE"
 
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
         -DHAVE_WAYLAND=On \
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
 
 mkdir -p ${D}/usr/share/license
 cp -f LICENSE ${D}/usr/share/license/notification
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    $D${prefix}/share/notification/notification_DB_init.sh

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " notification "
PACKAGES += " notification-dev "

notification_files = ""
notification_files += "${prefix}/lib/libnotification.so*"
notification_files += "${prefix}/share/notification/notification_DB_init.sh"
notification_files += "/usr/share/license/notification"
MANIFESTFILES_${PN} = "notification.manifest"

notification-dev_files = ""
notification-dev_files += "${prefix}/include/notification/notification.h"
notification-dev_files += "${prefix}/include/notification/notification_internal.h"
notification-dev_files += "${prefix}/include/notification/notification_error.h"
notification-dev_files += "${prefix}/include/notification/notification_type.h"
notification-dev_files += "${prefix}/include/notification/notification_list.h"
notification-dev_files += "${prefix}/include/notification/notification_ongoing_flag.h"
notification-dev_files += "${prefix}/include/notification/notification_text_domain.h"
notification-dev_files += "${prefix}/include/notification/notification_status.h"
notification-dev_files += "${prefix}/include/notification/notification_status_internal.h"
notification-dev_files += "${prefix}/include/notification/notification_setting.h"
notification-dev_files += "${prefix}/include/notification/notification_setting_internal.h"
notification-dev_files += "${prefix}/include/notification/notification_ipc.h"
notification-dev_files += "${prefix}/include/notification/notification_noti.h"
notification-dev_files += "${prefix}/includenotification/notification_setting_service.h"
notification-dev_files += "${prefix}/lib/pkgconfig/notification.pc"

PKG_notification= "notification"
PKG_notification-dev= "notification-dev"

require notification-extraconf.inc

