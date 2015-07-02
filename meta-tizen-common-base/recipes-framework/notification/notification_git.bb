require notification.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/notification;tag=f59b9dc191613956ec0bd4c3245be79aaee34a1f;nobranch=1"

BBCLASSEXTEND += " native "

