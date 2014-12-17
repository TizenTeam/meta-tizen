SECTION = "Security/Crypto Libraries"

# Split out libnettle and libhogweed because that's how Tizen traditionally did it.
PACKAGES =+ "libnettle libhogweed"
RDEPENDS_nettle-dev_append = " libnettle (= ${EXTENDPKGV}) libhogweed (= ${EXTENDPKGV})"
# nettle-dev dependency on nettle is obsolete, but cannot be removed via _remove and does
# not hurt anyway.

SUMMARY_libnettle = "A low level cryptographic library"
DESCRIPTION_libnettle = "The libnettle library itself."
FILES_libnettle = "${libdir}/libnettle*.so.*"

SUMMARY_libhogweed = "A low level cryptographic library"
DESCRIPTION_libhogweed = "The libhogweed library itself."
FILES_libhogweed = "${libdir}/libhogweed*.so.*"

SRPM_IS_LIB = "libnettle libhogweed"

