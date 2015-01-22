SECTION = "Security/Crypto Libraries"
SRPM_IS_LIB = "${PN}-openssl ${PN}-xx lib${PN}"

# Split out additional dev packages like Tizen traditionally does.
PACKAGES =+ "gnutls-xx-dev gnutls-openssl-dev"

FILES_gnutls-xx-dev = "\
${libdir}/libgnutlsxx.so \
${includedir}/libgnutls/gnutlsxx.h \
"
RDEPENDS_gnutlsxx-dev = "gnutls-xx"

FILES_gnutls-openssl-dev = "\
${libdir}/libgnutls-openssl.so \
${includedir}/libgnutls/openssl.h \
"
RDEPENDS_gnutls-openssl-dev = "gnutls-openssl"

# Missing in upstream. Checked for during configure:
# checking for __gmpz_cmp in -lgmp... no
# configure: error: 
# ***
# *** gmp was not found.
DEPENDS += "gmp"
