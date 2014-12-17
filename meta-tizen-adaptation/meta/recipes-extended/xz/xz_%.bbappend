SECTION = "Base/Utilities"
SRPM_IS_LIB = "liblzma"

# Tizen's xz-devel installs development files for
# libzma, so enforce the same here.
RDEPENDS_${PN}-dev_srpm += "liblzma-dev"
