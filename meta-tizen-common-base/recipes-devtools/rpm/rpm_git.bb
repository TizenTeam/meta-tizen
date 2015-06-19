require rpm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpm;tag=505aac517c1319c6b5c122a4e2cf34b6c0089d34;nobranch=1"

BBCLASSEXTEND += " native "

