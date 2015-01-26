require crosswalk-thirdparty.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/crosswalk;tag=2dfc3b03cd7a92a43676409b763e76e4f615f0da;nobranch=1"

BBCLASSEXTEND += " native "

