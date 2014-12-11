SECTION = "Multimedia/Image Library"

# Patch depends on Poky libtool behavior, breaks compilation without it.
SRC_URI_remove_srpm = "\
file://hardcoded_libtool.patch \
"
