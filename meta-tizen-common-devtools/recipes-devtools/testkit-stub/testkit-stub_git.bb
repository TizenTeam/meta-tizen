require testkit-stub.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/tools/testkit-stub;tag=31df96cf78e393098fbe1f71f55682382df06d31;nobranch=1"

BBCLASSEXTEND += " native "

