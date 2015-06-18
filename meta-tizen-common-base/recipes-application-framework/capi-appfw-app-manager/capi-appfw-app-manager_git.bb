require capi-appfw-app-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/app-manager;tag=a1345f6ec04f49a7a8a5e3bdc244db8c4d3d51f5;nobranch=1"

BBCLASSEXTEND += " native "

