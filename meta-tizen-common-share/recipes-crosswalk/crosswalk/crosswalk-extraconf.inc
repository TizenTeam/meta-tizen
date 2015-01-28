inherit gettext

DEPENDS += "crosswalk-thirdparty"

FILESEXTRAPATHS_prepend := "${THISDIR}/crosswalk:"

# This comes from the chromium recipe:
# http://layers.openembedded.org/layerindex/recipe/4969/
# It allows architecture specific configuration
SRC_URI += "${INCLUDE_GYPI}"
SRC_URI += "${OE_DEFAULTS_GYPI}"

SRC_URI += "file://fix-crosbuild.patch"

INCLUDE_GYPI_i586 = "file://include.gypi"
INCLUDE_GYPI_x86-64 = "file://include.gypi"
INCLUDE_GYPI_arm = "file://include.gypi"
OE_DEFAULTS_GYPI_i586 = "file://oe-defaults.gypi"
OE_DEFAULTS_GYPI_x86-64 = "file://oe-defaults.gypi"
OE_DEFAULTS_GYPI_arm = "file://oe-defaults.gypi"

RDEPENDS_${PN} += "libpulsecommon"

do_compile_prepend() {

    CC_host="gcc"; export CC_host
    CXX_host="g++"; export CXX_host

    LD="${CXX}" export LD
    CC="${CC}" export CC
    CXX="${CXX}" export CXX
    GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -I${WORKDIR}/oe-defaults.gypi -I${WORKDIR}/include.gypi"
    GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Dhost_clang=0 "
}

crosswalk-dbg_files += "/usr/lib/xwalk/.debug"
crosswalk-dbg_files += "/usr/lib/xwalk/.debug/libffmpegsumo.so"
crosswalk-dbg_files += "/usr/lib/xwalk/.debug/xwalk"

FILES_${PN}-dbg += "${crosswalk-dbg_files}"

# Unfortunately building crosswalk-dbg breaks Yocto tools, perhaps
# because the unpacked size is so large that it overflows (theory untested).
# The result is an invalid installed="None" in the channels xml files.
# It should have the number of bytes used after installation. This
# breaks the "smart" command during do_rootfs:
#   File "/data/yocto/build/tizen-distro/ivi/x86_64/tmp-glibc/sysroots/x86_64-linux/usr/lib/python2.7/site-packages/smart/backends/rpm/metadata.py", line 242, in load
#    info["installed_size"] = int(elem.get("installed"))
# As a workaround, disable building that package and creation of the files.
PACKAGES_remove = "${PN}-dbg"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

pkg_postinst_${PN}() {
    #!/bin/sh -e

    mkdir -p $D${prefix}/share/icons/default/small
    mkdir -p $D${prefix}/share/packages
    mkdir -p $D/etc/package-manager/backendlib
    mkdir -p $D/etc/package-manager/backend
    ln -sf ${prefix}/lib/xwalk/libxwalk_backend_lib.so $D/etc/package-manager/backendlib/libxpk.so
    ln -sf ${prefix}/lib/xwalk/libxwalk_backend_lib.so $D/etc/package-manager/backendlib/libwgt.so
    ln -sf ${prefix}/lib/xwalk/xwalk_backend $D/etc/package-manager/backend/xpk
    ln -sf ${prefix}/lib/xwalk/xwalk_backend $D/etc/package-manager/backend/wgt

}
