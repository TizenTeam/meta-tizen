SECTION = "Security/Access Control"
SRPM_IS_LIB = "lib${PN}"

# Fixed upstream in master > 1.7:
# Disable autoheader by setting EXTRA_AUTORECONF to --exclude=autoheader instead
# of setting AUTOHEADER to true.
EXTRA_AUTORECONF_append = " --exclude=autoheader"
export AUTOHEADER = ""
