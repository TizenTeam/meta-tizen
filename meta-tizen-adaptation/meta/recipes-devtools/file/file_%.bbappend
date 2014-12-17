SECTION = "Base/Utilities"
SRPM_IS_LIB = "libmagic"

# Split out magic.mgc and libmagic because that's what Tizen traditionally did.
PACKAGES =+ "libmagic-data libmagic"
RDEPENDS_file-dev_append = "libmagic (= ${EXTENDPKGV})"

FILES_libmagic-data = "${datadir}/misc/magic.mgc"

FILES_libmagic = "${libdir}/lib*.so.*"
RDEPENDS_libmagic = "libmagic-data (= ${EXTENDPKGV})"
