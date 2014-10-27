DESCRIPTION = "YaGL - OpenGLES acceleration module for emulator"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by emulator-yagl


#PROVIDES by emulator-yagl-dev
PROVIDES += "emulator-yagl-dev"


RDEPENDS = ""
#RDEPENDS of emulator-yagl-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "emulator-yagl"
RDEPENDS_${PN}-dev += "libx11"


DEPENDS = ""
#DEPENDS of emulator-yagl
DEPENDS += "xf86driproto"
inherit tizen_cmake
DEPENDS += "libx11"
inherit pkgconfig
DEPENDS += "udev"
DEPENDS += "wayland"
DEPENDS += "libdrm"
DEPENDS += "libxcb"
DEPENDS += "mesa"
DEPENDS += "libxext"
DEPENDS += "libxfixes"

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
 
 cp ${S}/packaging/emulator-yagl.manifest .
 
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
         ${EXTRA_OECMAKE} -DCMAKE_INSTALL_PREFIX=${D}/usr -DPLATFORM_GBM=1 -DPLATFORM_WAYLAND=1
 make
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 make install
 ln -s libEGL.so.1.0 ${D}/usr/lib/libEGL.so.1.0.0
 ln -s libGLESv2.so.2.0 ${D}/usr/lib/libGLESv2.so.2.0.0
 ln -s libGLESv2.so.2.0.0 ${D}/usr/lib/libGL.so.1.2.0
 
 mkdir -p ${D}/usr/lib/udev/rules.d
 cp packaging/95-tizen-emulator.rules ${D}/usr/lib/udev/rules.d
 
 mkdir -p ${D}/usr/include
 cp -r include/EGL ${D}/usr/include/
 cp -r include/GL ${D}/usr/include/
 cp -r include/GLES ${D}/usr/include/
 cp -r include/GLES2 ${D}/usr/include/
 cp -r include/KHR ${D}/usr/include/
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " emulator-yagl "
PACKAGES += " emulator-yagl-dev "

emulator-yagl_files = ""
emulator-yagl_files += "/usr/lib/udev/rules.d/95-tizen-emulator.rules"
emulator-yagl_files += "/usr/lib/*.so*"
MANIFESTFILES_${PN} = "emulator-yagl.manifest"

emulator-yagl-dev_files = ""
emulator-yagl-dev_files += "/usr/include/EGL"
emulator-yagl-dev_files += "/usr/include/GL"
emulator-yagl-dev_files += "/usr/include/GLES"
emulator-yagl-dev_files += "/usr/include/GLES2"
emulator-yagl-dev_files += "/usr/include/KHR"
MANIFESTFILES_${PN}-dev = "emulator-yagl.manifest"

FILES_${PN} = "${emulator-yagl_files}"
FILES_${PN}-dev = "${emulator-yagl-dev_files}"

PKG_emulator-yagl= "emulator-yagl"
PKG_emulator-yagl-dev= "emulator-yagl-dev"

require emulator-yagl-extraconf.inc

