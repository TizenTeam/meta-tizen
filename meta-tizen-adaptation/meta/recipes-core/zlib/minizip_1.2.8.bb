SUMMARY = "Zlib Compression Library"
DESCRIPTION = "Zlib is a general-purpose, patent-free, lossless data compression \
library which is used by many different programs."
HOMEPAGE = "http://zlib.net/"
SECTION = "libs"
LICENSE = "Zlib"
LIC_FILES_CHKSUM = "file://zip.h;beginline=4;endline=23;md5=21a9142d31897f1dc0cd6318eaa76af3"


SRC_URI = "http://www.zlib.net/zlib-${PV}.tar.xz "

SRC_URI[md5sum] = "28f1205d8dd2001f26fec1e8c2cebe37"
SRC_URI[sha256sum] = "831df043236df8e9a7667b9e3bb37e1fcb1220a0f163b6de2626774b9590d057"
FILESEXTRAPATHS_prepend := "${THISDIR}/zlib-${PV}:"
RDEPENDS_${PN} += "zlib"
DEPENDS_${PN} += "zlib"
S = "${WORKDIR}/zlib-${PV}/contrib/minizip"
inherit autotools

