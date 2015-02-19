require msg-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/messaging/msg-service;tag=04ede6288a10bd733cc73a3162a4cd998020c8d5;nobranch=1"

BBCLASSEXTEND += " native "

