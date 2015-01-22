SECTION = "System/Libraries"
SRPM_IS_LIB = "libexpat"

# Split out library because that's how Tizen traditionally did it.
inherit libpkg

# Do not generate separate expat-bin, in Tizen the binaries are in the
# main package which would be empty otherwise.
PACKAGES_remove = "${PN}-bin"
