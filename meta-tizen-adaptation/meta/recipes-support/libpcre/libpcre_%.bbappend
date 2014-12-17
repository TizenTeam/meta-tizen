SECTION = "System/Libraries"
SRPM_IS_LIB = "libpcreposix libpcrecpp libpcre"

# Not cross-compiling after conversion...
SRC_URI_remove_srpm = "file://pcre-cross.patch"

# Need to be more precise to pass Tizen rpmlint checks.
SPDXLICENSEMAP[BSD] = "BSD-3-Clause"
