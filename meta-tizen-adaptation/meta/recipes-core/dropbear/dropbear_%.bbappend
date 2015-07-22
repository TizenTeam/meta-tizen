SECTION = "Security/Network"

#PAM_SRC_URI = ""
PAM_PLUGINS = "libpam-runtime"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
PAM_SRC_URI += "file://dropbear"

