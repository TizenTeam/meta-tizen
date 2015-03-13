require libdrm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libdrm;tag=4a9274d5eff61a9632fa59b360f0aee7643405e6;nobranch=1"

BBCLASSEXTEND += " native "

