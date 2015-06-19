require ofono.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ofono;tag=eb05dee71b8731fac0170669c8904fca126ce831;nobranch=1"

BBCLASSEXTEND += " native "

