require elementary.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/elementary;tag=027991c597cf1395d13c075c2caa076fef6bdda5;nobranch=1"

BBCLASSEXTEND += " native "

