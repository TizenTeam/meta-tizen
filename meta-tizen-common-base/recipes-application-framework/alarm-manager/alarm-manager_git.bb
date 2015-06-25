require alarm-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/alarm-manager;tag=2f323b533a991df3eb9f53b3852db06984115c81;nobranch=1"

BBCLASSEXTEND += " native "

