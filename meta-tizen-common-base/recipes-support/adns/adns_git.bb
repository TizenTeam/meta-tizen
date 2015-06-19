require adns.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/adns;tag=36a2721c3c649175a599f4ca31577c5eeea8e3f6;nobranch=1"

BBCLASSEXTEND += " native "

