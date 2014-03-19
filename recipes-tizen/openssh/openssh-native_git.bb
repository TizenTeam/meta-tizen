require openssh.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/openssh;protocol=ssh;tag=8bbfa512de0be6e13bbf062de76302b9ebedbb87;nobranch=1"

