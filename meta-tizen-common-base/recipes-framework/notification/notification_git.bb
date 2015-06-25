require notification.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/notification;tag=45110c2bc1867e8838fb697a2d451a3b199a081f;nobranch=1"

BBCLASSEXTEND += " native "

