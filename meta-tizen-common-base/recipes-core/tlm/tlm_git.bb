require tlm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/tlm;tag=e341ea06e6b673d034258456e68966e7dfe2beb5;nobranch=1"

BBCLASSEXTEND += " native "

