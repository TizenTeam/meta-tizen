RDEPENDS_${PN} += "xkeyboard-config"
RRECOMMENDS_${PN} = "liberation-fonts"

RDEPENDS_${PN}_remove = "weston-startup"

SRC_URI += "file://make-lcms-explicitly-configurable.patch"
SRC_URI += "file://make-libwebp-explicitly-configurable.patch"

do_configure_prepend() {
    sed -i 's/PKG_CHECK_MODULES(WAYLAND_SCANNER, wayland-scanner)//' configure.ac
}

# Disable unusable "useradd weston-launch" from .spec file.
# Creating the user was moved to meta-tizen-ivi/recipes-image/config-tizen-profiles/config-tizen-ivi.bb.
pkg_preinst_${PN}() {
}

do_install_append() {
    # Done in the .spec file via permissions in the file list.
    chmod u+s ${D}${bindir}/weston-launch

    # Not done in Tizen, but perhaps it should be? Don't do it here either for now.
    # When we do it, we also need to move the GROUPADD_PARAM from  config-tizen-ivi.bb
    # into this recipe here.
    # chgrp weston-launcher ${D}${bindir}/weston-launch
}

export libexecdir="${prefix}/libexec"

FILES_${PN} += "${prefix}/lib/weston/cms-static.so"

FILES_${PN} += "${prefix}/bin/weston-scaler"
FILES_${PN} += "${prefix}/bin/weston-stacking"
FILES_${PN} += "${prefix}/bin/weston-multi-resource"
