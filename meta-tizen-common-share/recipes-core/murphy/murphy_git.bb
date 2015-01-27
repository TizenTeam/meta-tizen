require murphy.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/murphy;tag=1affbe0bb263de2baeb2d815f8dba54d906d62e0;nobranch=1"

BBCLASSEXTEND += " native "

