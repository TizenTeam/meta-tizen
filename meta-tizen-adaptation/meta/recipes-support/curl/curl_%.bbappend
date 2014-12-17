SECTION = "Base/Utilities"
SRPM_IS_LIB = "lib${PN}"

# Traditionally enabled in Tizen, needed for binary compatibility.
EXTRA_OECONF_append = " --enable-versioned-symbols"
