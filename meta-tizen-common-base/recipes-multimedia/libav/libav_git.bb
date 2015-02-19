require libav.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libav;tag=8622a963e6b008a81167b3c71a43a55f75824acb;nobranch=1"

BBCLASSEXTEND += " native "

