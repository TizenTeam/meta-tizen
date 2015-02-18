require libhangul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libhangul;tag=f9100c34a349b90a6641d0a834a42931d2db707b;nobranch=1"

BBCLASSEXTEND += " native "

