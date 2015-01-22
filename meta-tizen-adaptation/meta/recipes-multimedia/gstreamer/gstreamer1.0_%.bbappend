SECTION = "Multimedia/Service"
SRPM_IS_LIB = "${PN}"

EXTRA_OECONF += "--disable-examples --disable-tests"

# Split out library because that's how Tizen traditionally did it.
inherit libpkg
