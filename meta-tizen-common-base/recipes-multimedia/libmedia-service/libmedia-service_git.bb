require libmedia-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmedia-service;tag=2b894760e968d23992f6c46efced432bbe781fa8;nobranch=1"

BBCLASSEXTEND += " native "

