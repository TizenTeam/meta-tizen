require alsa-lib.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/alsa-lib;protocol=ssh;tag=344a8da2fb44683c3b10dd8c1b38ebf195b7089c;nobranch=1"

