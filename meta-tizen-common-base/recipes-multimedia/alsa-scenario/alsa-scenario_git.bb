require alsa-scenario.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/alsa-scenario-0.2;tag=d3f70eaddda8052dd3b67f290c3490da3f12fabb;nobranch=1"

BBCLASSEXTEND += " native "

