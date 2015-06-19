require libdrm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libdrm;tag=34cc5f5b999a9caec03dbc82cba4cf97e8a4596d;nobranch=1"

BBCLASSEXTEND += " native "

