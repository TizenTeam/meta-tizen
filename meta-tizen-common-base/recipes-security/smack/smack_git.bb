require smack.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/smack;tag=0bd2831dae7500fcfc080519ded5ae2bf6752226;nobranch=1"

BBCLASSEXTEND += " native "

