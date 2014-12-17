SECTION = "System/Libraries"
SRPM_IS_LIB = "libexpat"

# Split out library because that's how Tizen traditionally did it.
PACKAGES =+ "libexpat"
RDEPENDS_expat-dev_append = "libexpat (= ${EXTENDPKGV})"
# Can't remove the main expat dependency from expat-dev because _remove
# cannot handle more than single words.

SUMMARY_libexpat = "XML Parser library"
DESCRIPTION_libexpat = "This package contains the libexpat library."
FILES_libexpat = "${libdir}/*.so.*"
