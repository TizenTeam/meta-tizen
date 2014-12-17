SECTION = "Application Framework/Database"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://Fix_JOURNALMODE_PERSIST.patch"

# Missing in upstream .bb.
RDEPENDS_lib${PN}-dev_append = "lib${PN} (= ${EXTENDPKGV})"
