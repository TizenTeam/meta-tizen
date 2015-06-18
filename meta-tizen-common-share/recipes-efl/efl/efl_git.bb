require efl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/efl;tag=989cee0d565c4a55578dc64539ce9c89d3fea0d4;nobranch=1"

BBCLASSEXTEND += " native "

