require capi-system-device.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/device;tag=206b50511648ad6affda9a638d2199b9903a48eb;nobranch=1"

BBCLASSEXTEND += " native "

