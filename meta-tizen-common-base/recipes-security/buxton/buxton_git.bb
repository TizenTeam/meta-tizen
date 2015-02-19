require buxton.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/buxton;tag=a707d0bd523c07c9c813a6cfa058f842ad335112;nobranch=1"

BBCLASSEXTEND += " native "

