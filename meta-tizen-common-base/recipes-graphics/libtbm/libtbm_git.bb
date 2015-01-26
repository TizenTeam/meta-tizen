require libtbm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libtbm;tag=d3bbb67a496eabe1d1b9d76cf66cc3f9d35af2bb;nobranch=1"

BBCLASSEXTEND += " native "

