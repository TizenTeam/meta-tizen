require deviced.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/deviced;tag=c83bdb9c20ca96fccd7badb409f1a2ec306d5f86;nobranch=1"

BBCLASSEXTEND += " native "

