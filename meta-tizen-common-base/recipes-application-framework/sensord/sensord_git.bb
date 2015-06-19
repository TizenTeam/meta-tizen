require sensord.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/sensord;tag=9e537f46b7a6efee960bd17d4a06e19c738bec60;nobranch=1"

BBCLASSEXTEND += " native "

