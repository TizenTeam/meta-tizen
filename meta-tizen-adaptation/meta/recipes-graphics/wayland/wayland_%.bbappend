SECTION = "Graphics & UI Framework/Wayland Window System"
SRPM_IS_LIB = "libwayland"

# Disabling building of the scanner is a cross-compile trick.
# Enabling it for native compilation adds a dependency on expat.
EXTRA_OECONF_remove_srpm = "--disable-scanner"
DEPENDS_append_srpm = " expat"

# Split out libs as done in Tizen traditionally.
PKG_LIBS = "libwayland-client libwayland-cursor libwayland-server"
inherit libpkg
