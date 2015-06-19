require libdevice-node.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libdevice-node;tag=17791aab5269f6392b85694b116c7f7638fd5d62;nobranch=1"

BBCLASSEXTEND += " native "

