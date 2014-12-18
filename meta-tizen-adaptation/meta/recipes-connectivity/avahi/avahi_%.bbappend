SECTION = "System/Network"
SRPM_IS_LIB = "lib${PN}-client lib${PN}-common lib${PN}-core lib${PN}-glib lib${PN}-gobject"

# Keep the extra packages, but make the main one pull them in to
# satisfy Tizen expectations. The resulting circular dependency is only possible in .spec.
RDEPENDS_${PN}_append_srpm = "${PN}-autopid ${PN}-daemon ${PN}-dnsconfd ${PN}-utils"

# Similarly, create a dummy lib package depending on the others.
PACKAGES += "${PN}-libs"
RDEPENDS_${PN}-libs = "lib${PN}-client lib${PN}-common lib${PN}-core lib${PN}-glib lib${PN}-gobject lib${PN}-ui"
