require capi-network-connection.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/connection;tag=90abeefb65bb87c975754f5307f60f56fcd003c2;nobranch=1"

BBCLASSEXTEND += " native "

