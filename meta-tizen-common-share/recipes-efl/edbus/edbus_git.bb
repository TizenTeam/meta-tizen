require edbus.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/edbus;tag=434ea19660951c48ccfa8540f36443c58d6523ea;nobranch=1"

BBCLASSEXTEND += " native "

