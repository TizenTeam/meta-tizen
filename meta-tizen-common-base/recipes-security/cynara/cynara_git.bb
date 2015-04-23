require cynara.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/cynara;tag=229ec1e1e8c5940c62f734e4b8a0b9c49eb8f9f2;nobranch=1"

BBCLASSEXTEND += " native "

