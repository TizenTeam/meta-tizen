require phoned.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/phoned;tag=1ab4f7983e686037e87d28cca6e31a35f019a382;nobranch=1"

BBCLASSEXTEND += " native "

