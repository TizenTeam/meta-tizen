require audio-session-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/audio-session-manager;tag=cba5a315ca8abb87ec935048647feaa129f5c277;nobranch=1"

BBCLASSEXTEND += " native "

