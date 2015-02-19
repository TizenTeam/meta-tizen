require dbus-python.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dbus-python;tag=7d179dbd5cdf6ac6dd37b30e994bbb7b6548da10;nobranch=1"

BBCLASSEXTEND += " native "

