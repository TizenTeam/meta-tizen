SECTION = "Multimedia/Libraries"

# Split out libs as done in Tizen traditionally.
PACKAGES =+ "liborc"
RDEPENDS_orc-dev_append = " liborc"
# Would be nice to remove orc, but _remove doesn't work like
# that (can only remove full words).
# RDEPENDS_orc-dev_remove = "${PN} (= ${EXTENDPKGV})"

FILES_liborc = "\
${libdir}/*.so.* \
"
