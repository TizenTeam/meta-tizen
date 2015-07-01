require gumd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gumd;tag=e42fc079e00fd9ce62ebfabf1d8b25669ea354ec;nobranch=1"

BBCLASSEXTEND += " native "

