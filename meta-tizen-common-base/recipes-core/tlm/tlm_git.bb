require tlm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/tlm;tag=7263310cce0fe67af21c63eeecfa776778da8b08;nobranch=1"

BBCLASSEXTEND += " native "

