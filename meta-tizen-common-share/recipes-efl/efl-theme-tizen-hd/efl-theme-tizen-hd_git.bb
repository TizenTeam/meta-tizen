require efl-theme-tizen-hd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/efl-theme-tizen;tag=12d2caceedbfd0344e6d919e3e08faeea2e5a179;nobranch=1"

BBCLASSEXTEND += " native "

