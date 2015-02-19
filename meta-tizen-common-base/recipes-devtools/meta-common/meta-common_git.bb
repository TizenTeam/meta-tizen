require meta-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=afcdce5e3f0dbd5a9b4b632b906e478b39f5b707;nobranch=1"

BBCLASSEXTEND += " native "

