require efl-theme-tizen-hd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/efl-theme-tizen;tag=9db03fec5e9f1e4ad7e3ad8c93f7c6ac45af6e2d;nobranch=1"

BBCLASSEXTEND += " native "

