require pulseaudio.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pulseaudio;tag=9120bf9099551ec194fe34c059140379c22de166;nobranch=1"

BBCLASSEXTEND += " native "

