SECTION = "Graphics & UI Framework/Libraries"
SRPM_IS_LIB = "${PN}"

# Patch depends on Poky libtool behavior, breaks compilation without it.
SRC_URI_remove_srpm = "\
file://hardcoded_libtool.patch \
"
