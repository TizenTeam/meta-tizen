require capi-network-bluetooth.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/bluetooth;tag=63f146253b13e8033383f162dc3f3cbc87d22f04;nobranch=1"

BBCLASSEXTEND += " native "

