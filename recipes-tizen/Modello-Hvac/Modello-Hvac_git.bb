require Modello-Hvac.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Hvac;tag=867feb1d8942c184fe47a622a62a699ea529068d;nobranch=1"

BBCLASSEXTEND += " native "

