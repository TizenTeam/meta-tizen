require gpg2.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gpg2;tag=94fab32e997ce870c424af01aa702c93743a0e2e;nobranch=1"

BBCLASSEXTEND += " native "

