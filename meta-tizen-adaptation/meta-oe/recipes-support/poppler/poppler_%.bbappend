SECTION = "System/Libraries"
SRPM_IS_LIB = "lib${PN} lib${PN}-glib lib${PN}-cpp"

# Upstream bug: poppler autotools uses iconv.m4.
DEPENDS += "virtual/libintl"
