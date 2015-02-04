require crosswalk-thirdparty.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/crosswalk;tag=e337b1b2d330397537e67b4fc10b61430e9f0fd8;nobranch=1"

BBCLASSEXTEND += " native "

