require capi-system-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/system-info;tag=1604ff2532e44cd556a88b3a3fc8ee8e48f7da54;nobranch=1"

BBCLASSEXTEND += " native "

