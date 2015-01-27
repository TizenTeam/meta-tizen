require avsystem.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/avsystem;tag=817c8dc27cf69702e01bd1e926ccf7fe0a10af21;nobranch=1"

BBCLASSEXTEND += " native "

