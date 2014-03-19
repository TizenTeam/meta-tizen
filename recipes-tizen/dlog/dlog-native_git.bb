require dlog.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/dlog;protocol=ssh;tag=7125136fabfd0b9f1a508ee49ca45b851b3ce9be;nobranch=1"

