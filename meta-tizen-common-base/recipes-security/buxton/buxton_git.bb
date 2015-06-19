require buxton.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/buxton;tag=96f20fdd5d21145f40b260665dbeabe4285b1f8c;nobranch=1"

BBCLASSEXTEND += " native "

