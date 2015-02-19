require systemd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/systemd;tag=1c6d7a3b259467df3c02c1fb0bb4c57d70192d15;nobranch=1"

BBCLASSEXTEND += " native "

