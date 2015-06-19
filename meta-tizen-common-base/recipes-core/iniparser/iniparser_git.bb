require iniparser.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/iniparser;tag=152457b294a8dd97d40bc4c98da73f1b18e20c49;nobranch=1"

BBCLASSEXTEND += " native "

