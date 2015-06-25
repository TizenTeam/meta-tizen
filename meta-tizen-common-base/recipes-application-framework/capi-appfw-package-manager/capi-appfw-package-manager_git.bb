require capi-appfw-package-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/package-manager;tag=84b87f5457f2449660a1017a98468bbfa3fd6092;nobranch=1"

BBCLASSEXTEND += " native "

