SECTION = "Base/File Systems"

# To be fixed upstream in master > 1.7:
# Disable autoheader by setting EXTRA_AUTORECONF to --exclude=autoheader instead
# of setting AUTOHEADER to true.
EXTRA_AUTORECONF_append = " --exclude=autoheader"
export AUTOHEADER = ""

# Not enabled in Tizen.
EXTRA_OECONF_append = " --disable-gettext"
EXTRA_OECONF_remove = "--enable-gettext"
DEPENDS_remove = "virtual/libintl virtual/gettext gettext-native"
SRPM_IS_LIB = "lib${PN}"
