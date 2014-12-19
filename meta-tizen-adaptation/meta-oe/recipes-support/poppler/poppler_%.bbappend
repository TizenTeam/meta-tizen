SECTION = "System/Libraries"

# Upstream bug: poppler autotools uses iconv.m4.
DEPENDS += "virtual/libintl"

# Create separate lib packages. The base .bb already does that
# for lib${PN} and lib${PN}-glib, but not lib${PN}-cpp (which
# we want in Tizen), and it gets the -dev dependencies wrong.
# libpkg fixes that for us. It also sets SRPM_IS_LIB.
PKG_LIBS = "lib${PN}-cpp lib${PN}-glib lib${PN}"
inherit libpkg
