require tethering.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/tethering;protocol=ssh;tag=d9c4a9752d0c8be29faa847511f5aac088e13dc3;nobranch=1"

