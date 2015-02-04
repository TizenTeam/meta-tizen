require capi-base-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/common;tag=9ab27c073081894717fa7f12905cbe3b60dfd9ec;nobranch=1"

BBCLASSEXTEND += " native "

