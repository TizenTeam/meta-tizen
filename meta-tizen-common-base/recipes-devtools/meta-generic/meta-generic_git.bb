require meta-generic.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/meta-generic;tag=99e8e2ef92394c2a39a4904ee3bbf9b9a0f63a5d;nobranch=1"

BBCLASSEXTEND += " native "

