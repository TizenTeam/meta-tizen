require genivi-audio-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/genivi/genivi-audio-manager;tag=42791f2779fc13c9fd170e5339ab72f0ef389d9a;nobranch=1"

BBCLASSEXTEND += " native "

