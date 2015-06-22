require capi-media-tool.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/mediatool;tag=156e83e58007ee3221aaab7c6b099dce5d49ade9;nobranch=1"

BBCLASSEXTEND += " native "

