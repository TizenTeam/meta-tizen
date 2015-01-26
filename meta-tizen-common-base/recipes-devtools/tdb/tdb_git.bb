require tdb.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tdb;tag=135e077bda78148ce8602200559ea81a5792d808;nobranch=1"

BBCLASSEXTEND += " native "

