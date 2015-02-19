require tizen-extensions-crosswalk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/tizen-extensions-crosswalk;tag=21ea2032c15d8c60e32c53716c536c3ec6572a4b;nobranch=1"

BBCLASSEXTEND += " native "

