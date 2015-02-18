require libmm-player.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-player;tag=706c804cbf21c497af38732e96dd05b52d70a1c2;nobranch=1"

BBCLASSEXTEND += " native "

