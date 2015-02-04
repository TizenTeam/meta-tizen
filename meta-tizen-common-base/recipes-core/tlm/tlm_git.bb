require tlm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/tlm;tag=8eb7b86257158f15bc29cd6f89487e72d2d0b67c;nobranch=1"

BBCLASSEXTEND += " native "

