require media-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/media-server;tag=0bef7d493c64addf95f15b5d99e669f8c1f0ee83;nobranch=1"

BBCLASSEXTEND += " native "

