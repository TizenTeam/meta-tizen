require aul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/aul-1;tag=27c15aa6ef71fd37dd8cf5a3d10c8e29c82fcc34;nobranch=1"

BBCLASSEXTEND += " native "

