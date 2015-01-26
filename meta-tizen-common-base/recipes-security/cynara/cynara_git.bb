require cynara.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/cynara;tag=b00d7fb59ba12ad6cfb53b5b476dc3c18e09f39d;nobranch=1"

BBCLASSEXTEND += " native "

