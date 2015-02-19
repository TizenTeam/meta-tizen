require libmedia-thumbnail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmedia-thumbnail;tag=23d402a209ebef8a4203ced3bdcdfee2f89924eb;nobranch=1"

BBCLASSEXTEND += " native "

