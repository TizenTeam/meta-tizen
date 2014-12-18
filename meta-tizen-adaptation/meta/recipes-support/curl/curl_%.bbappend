SECTION = "Base/Utilities"
SRPM_IS_LIB = "lib${PN}"

# Traditionally enabled in Tizen, needed for binary compatibility.
EXTRA_OECONF_append = " --enable-versioned-symbols"

# use openssl instead of gnutls by default
PACKAGECONFIG ??= "${@bb.utils.contains("DISTRO_FEATURES", "ipv6", "ipv6", "", d)} ssl zlib"
