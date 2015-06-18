require app-core.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-core;tag=6dbe9f1f4b97fe9f6c9bd5b89e08852aa8f9fdec;nobranch=1"

BBCLASSEXTEND += " native "

