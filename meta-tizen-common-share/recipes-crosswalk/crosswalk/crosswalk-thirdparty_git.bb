require crosswalk-thirdparty.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/crosswalk;tag=4b0df18728c2254b370c0c10f9a826b84b48e112;nobranch=1"

BBCLASSEXTEND += " native "

