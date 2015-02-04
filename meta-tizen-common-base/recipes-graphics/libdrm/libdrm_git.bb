require libdrm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libdrm;tag=d772cc515a24fe015db183e91e85d74dba4f1549;nobranch=1"

BBCLASSEXTEND += " native "

