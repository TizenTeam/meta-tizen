require contacts-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/pim/contacts-service;tag=fdb9d594c9a1df21fe55f25e18f8d61876dfc7bc;nobranch=1"

BBCLASSEXTEND += " native "

