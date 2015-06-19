require capi-base-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/common;tag=1fac8bc8e298f0805c0531b49019d051e7ed2934;nobranch=1"

BBCLASSEXTEND += " native "

