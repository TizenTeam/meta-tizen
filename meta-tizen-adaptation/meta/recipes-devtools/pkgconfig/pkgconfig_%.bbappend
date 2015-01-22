SECTION = "Development/Building"

# pkg-config needs a working version of itself to compile.
# Yocto solves that via cross-compiling. In the .spec file
# we rely on some other bootstrapping.
DEPENDS_append_srpm = " pkg-config-bootstrap"

# Must provide this alias for Tizen .spec files.
# We have to avoid triggering the tizensrpm.bbclass rewrite rules for
# "pkgconfig". This adds the desired "Provides: pkgconfig = ..." to
# the .spec file, but then rpmbuild does not add it to the resulting
# .rpm. Perhaps because of "Name: pkgconfig".
#
# Bottom line is that we have to replace all packages depending on
# "pkgconfig" with converted recipes.
#
# RPROVIDES_${PN}_append_srpm = " really-pkgconfig (= ${EXTENDPKGV})"
# SRPM_RENAME += "really-pkgconfig=pkgconfig"
