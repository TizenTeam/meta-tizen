require gsignond.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gsignond;tag=634344eb36c33b16a49058aff4e73133ad875745;nobranch=1"

BBCLASSEXTEND += " native "

