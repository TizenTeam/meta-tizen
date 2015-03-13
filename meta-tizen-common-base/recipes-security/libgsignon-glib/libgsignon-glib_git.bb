require libgsignon-glib.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libgsignon-glib;tag=2d2df0c1b8d8f814b1342187538fb24a276fa1e8;nobranch=1"

BBCLASSEXTEND += " native "

