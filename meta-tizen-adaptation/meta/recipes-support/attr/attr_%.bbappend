SECTION = "Base/File Systems"

# To be fixed upstream in master > 1.7:
# Disable autoheader by setting EXTRA_AUTORECONF to --exclude=autoheader instead
# of setting AUTOHEADER to true.
EXTRA_AUTORECONF_append = " --exclude=autoheader"
export AUTOHEADER = ""
