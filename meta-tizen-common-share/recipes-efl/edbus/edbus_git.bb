require edbus.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/edbus;tag=f988bbb48d8894e47d9166ebb966e51fd2f32942;nobranch=1"

BBCLASSEXTEND += " native "

