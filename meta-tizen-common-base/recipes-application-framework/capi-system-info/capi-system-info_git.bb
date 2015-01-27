require capi-system-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/system-info;tag=7c1c890c5fdc4c80d99b6a74d1011bfb144ee5b3;nobranch=1"

BBCLASSEXTEND += " native "

