SECTION = "Graphics & UI Framework/Libraries"
SRPM_IS_LIB = "libcogl libcogl-gles2 libcogl-pango libcogl-path"

# Don't generate an empty cogl-1.0 .rpm because it was replaced
# by libcogl, which provides "cogl-1.0". Also creating cogl-1.0
# would prevent installing cogl-1.0-dev because of the ambiguous
# dependency on "cogl-1.0".
#PACKAGES_remove = "${PN}"

# cogl-1.0 is empty, but does get created when building with a
# converted .spec. When that happens, the dependency on cogl-1.0 is
# ambiguous. Better create libcogl via renaming when converting
# to spec.
PACKAGES_remove_srpm = "libcogl"
SRPM_RENAME += "cogl-1.0=libcogl"


