require neardal.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/neardal;tag=87d6296b5b2fbd340a0ab5af1fe235a34ac835d1;nobranch=1"

BBCLASSEXTEND += " native "

