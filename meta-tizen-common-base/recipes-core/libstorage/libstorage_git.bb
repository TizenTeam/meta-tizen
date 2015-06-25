DESCRIPTION = "Library to get storage information"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"
PV = "0.1.0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI = ""
SRC_URI += "git://review.tizen.org/platform/core/system/libstorage;tag=ff98211fd608bfc88edbb805eaf3d8e362108ade;nobranch=1"

S = "${WORKDIR}/git"

inherit cmake tizen_cmake

BBCLASSEXTEND = ""
PROVIDES = ""

RDEPENDS = ""
#RDEPENDS of libstorage (${PN})
RDEPENDS_${PN} += "libtzplatform-config"

DEPENDS = ""
#DEPENDS of libstorage
inherit pkgconfig
DEPENDS += "dlog"
DEPENDS += "capi-base-common"
DEPENDS += "vconf"
DEPENDS += "glib-2.0"

EXTRA_OECMAKE_append += " -DLIB_INSTALL_DIR:PATH=${prefix}/lib"

PACKAGES = "${PN} ${PN}-dev ${PN}-dbg"
