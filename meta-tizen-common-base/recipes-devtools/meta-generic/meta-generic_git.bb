require meta-generic.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/meta-generic;tag=e6bf7789847b774bb7ebd176a0ad6d467bbb3e0a;nobranch=1"

BBCLASSEXTEND += " native "

