require app-installers.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/appfw/app-installers;tag=959fe7a29ed106aec1a9000810b6212be461ab3d;nobranch=1"

BBCLASSEXTEND += " native "

