require libmedia-thumbnail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmedia-thumbnail;tag=92ca49f87e36c9ab477f1af7aabf4c3815763dae;nobranch=1"

BBCLASSEXTEND += " native "

