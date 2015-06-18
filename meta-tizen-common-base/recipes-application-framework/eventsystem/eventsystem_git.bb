require eventsystem.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/libeventsystem;tag=9597aa4c4db9cd48d49d8a3927b2ea1f7b83ac70;nobranch=1"

BBCLASSEXTEND += " native "

