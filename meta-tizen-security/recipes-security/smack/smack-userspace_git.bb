DESCRIPTION = "Selection of tools for developers working with Smack"
HOMEPAGE = "https://github.com/smack-team/smack"
SECTION = "Security/Access Control"
LICENSE = "LGPL-2.1"
PV = "1.0.5"

# Alias needed to satisfy dependencies in other recipes.
# This recipe itself cannot be named "smack" because that
# would conflict with the "smack" override.
PROVIDES = "smack"
RPROVIDES_${PN} += "smack"

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"
SRC_URI += "git://review.tizen.org/platform/upstream/smack;tag=66a110344be79ff2968ff6817ec72f569d852c17;nobranch=1"
S = "${WORKDIR}/git"

inherit autotools

BBCLASSEXTEND_append = "nativesdk"

# do_configure_prepend() {
#  sed -i 's@systemd_new=no@systemd_new=yes@' ${S}/configure.ac
#  sed -i '/PKG_CHECK_MODULES(/,/)/{s/b/r/p;d}' ${S}/configure.ac
# }
