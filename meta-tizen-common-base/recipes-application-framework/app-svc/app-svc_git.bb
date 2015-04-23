require app-svc.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-svc;tag=d95dbdd84bb3aa893ea3e5042ce7a4684f85f4e6;nobranch=1"

BBCLASSEXTEND += " native "

