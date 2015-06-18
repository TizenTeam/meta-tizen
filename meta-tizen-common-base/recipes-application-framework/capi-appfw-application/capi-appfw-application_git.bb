require capi-appfw-application.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/application;tag=ba3841dce24c90e1795436997fa408696ed21311;nobranch=1"

BBCLASSEXTEND += " native "

