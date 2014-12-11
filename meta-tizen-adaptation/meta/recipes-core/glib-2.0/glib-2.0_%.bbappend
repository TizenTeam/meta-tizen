SECTION = "System/Libraries"

# Patch depends on Poky libtool behavior, breaks compilation without it.
SRC_URI_remove_srpm = "\
file://configure-libtool.patch \
"
