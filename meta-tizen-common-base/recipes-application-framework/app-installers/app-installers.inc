DESCRIPTION = "Application Information Installer"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Package Management"
LICENSE = "Apache-2.0"
PV = "1.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest package

BBCLASSEXTEND = ""
PROVIDES = ""


PROVIDES += " wgt-backend xpk-backend "

RDEPENDS = ""
RDEPENDS_wgt-backend += "${PN} tizen-platform-config"
RDEPENDS_xpk-backend += "${PN} tizen-platform-config"




DEPENDS = ""
inherit tizen_cmake
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "boost pkgmgr  pkgmgr-info pkgmgr-installer"
DEPENDS += "security-manager openssl libxml2 zlib minizip lzip xmlsec1 vconf "


do_configure() {
 cd ${S}
 cp ./packaging/wgt-backend.manifest .
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 CFLAGS="$CFLAGS -fpic"
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
         ${EXTRA_OECMAKE} . -DWRT_LAUNCHER=/usr/bin/xwalk-launcher \
           -DBUILD_PKGTYPE=rpm
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 CFLAGS="$CFLAGS -fpic"
 
 oe_runmake
  
}

do_install_prepend() {
    cd ${S}
}

do_install_append() {
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    mkdir -p $D${prefix}/share/icons/default/small
    mkdir -p $D${prefix}/share/packages
    mkdir -p $D/etc/package-manager/backendlib
    mkdir -p $D/etc/package-manager/backend
    ln -sf ${prefix}/bin/wgt-backend $D/etc/package-manager/backend/wgt
    ln -sf ${prefix}/bin/xgt-backend $D/etc/package-manager/backend/xpk
    ln -sf ${prefix}/bin/tpk-backend $D/etc/package-manager/backend/tpk

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    if [ $1 == 0 ]; then
        rm -f $D${prefix}/dbspace/.app_info.db*
    fi

}

PACKAGES += "wgt-backend"
PACKAGES += "xpk-backend"
PACKAGES += "tpk-backend"
PKG_wgt-backend = "wgt-backend"
PKG_xpk-backend = "xpk-backend"
PKG_tpk-backend = "tpk-backend"

app-installer_files = ""
app-installer_files += "${prefix}/lib/libcommon-installer.so.*"
app-installer_files += "${prefix}/lib/libcommon-installer-signature.so.*"
app-installer_files += "${prefix}/lib/libcommon-installer-utils.so.*"
app-installer_files += "${prefix}/lib/libcommon-installer-widget-manifest-parser.so.*"
app-installer_files += "/usr/share/app-installers/signature_schema.xsd"
MANIFESTFILES_wgt-backend = "wgt-backend.manifest"

FILES_${PN} = "${app-installer_files}"
FILES_wgt-backend = "${bindir}/wgt-backend"
FILES_tpk-backend = "${bindir}/tpk-backend"

RDEPENDS_wgt-backend = "app-installers"


