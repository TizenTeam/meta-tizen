require pkgmgr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/slp-pkgmgr;tag=cc62763ac7ffa287b0e5b22de3d2e678f3545504;nobranch=1"

BBCLASSEXTEND += " native "

