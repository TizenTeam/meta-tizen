require smartcard-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/smartcard-service;protocol=ssh;tag=2b952f512092b75bcc3a75eb0660fb14efabe46c;nobranch=1"

