require app-installers.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/appfw/app-installers;tag=8fd471e4be4460278b9fa2ae6eb79cf0746c8a7d;nobranch=1"

BBCLASSEXTEND += " native "

