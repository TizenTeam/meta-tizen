require testkit-lite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/tools/testkit-lite;tag=9644c166e065747de5da831d4c22fdd8bb9c8818;nobranch=1"

BBCLASSEXTEND += " native "

