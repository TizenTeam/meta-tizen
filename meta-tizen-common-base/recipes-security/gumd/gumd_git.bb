require gumd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gumd;tag=4d3229b2c21bc68049e6160dba44f82dfde71abe;nobranch=1"

BBCLASSEXTEND += " native "

