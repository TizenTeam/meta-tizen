require capi-content-media-content.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/media-content;tag=f268e8edcfab07ca50837cd6b2f8c95e51956130;nobranch=1"

BBCLASSEXTEND += " native "

