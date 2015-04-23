require weston-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/weston-common;tag=15a44961f3d4285537c4c210176138b4e0368ba1;nobranch=1"

BBCLASSEXTEND += " native "

