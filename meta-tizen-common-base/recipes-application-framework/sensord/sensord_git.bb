require sensord.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/sensord;tag=33a40709f3c14b366204925f0bddd2b87c73bb70;nobranch=1"

BBCLASSEXTEND += " native "

