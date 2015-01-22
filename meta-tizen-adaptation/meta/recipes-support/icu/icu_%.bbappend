SECTION = "System/Libraries"
SRPM_IS_LIB = "libicu libicule libicutu libicudata libicui18n libicuio libiculx libicuuc"

# Remove upstream cross-compiling trick when converting.
EXTRA_OECONF_remove_srpm = "--with-cross-build=${STAGING_ICU_DIR_NATIVE}"

# TODO: instead of changing the license (which is incorrect!), either
# get Tizen to accept ICU as license or suppress the rpmlint check.
SPDXLICENSEMAP[ICU] = "BSD-3-Clause"
