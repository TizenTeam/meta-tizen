require weston.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/weston;tag=2ddf1b5a53caccaab6357fd0fce60b09b60b1cc7;nobranch=1"

BBCLASSEXTEND += " native "

