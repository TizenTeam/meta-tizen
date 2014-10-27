require emulator-yagl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/adaptation/emulator/emulator-yagl;tag=1de389884a211e241f3aa9b5bd0188cb91f5c0e1;nobranch=1"

BBCLASSEXTEND += " native "

