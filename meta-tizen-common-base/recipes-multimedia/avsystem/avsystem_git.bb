require avsystem.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/avsystem;tag=6c769f64f84c1bfaa8a05d9ca9288cd13b8cb700;nobranch=1"

BBCLASSEXTEND += " native "

