DEPENDS += "wayland-native"
DEPENDS += "weston-ivi-shell"

INSANE_SKIP_${PN}-dev = "staticdev"

B="${S}"

do_configure_prepend() {
    sed -i "s@\${LIBS} \${WESTON_LIBDIR}/weston/ivi-shell.so@\${LIBS} ${PKG_CONFIG_SYSROOT_DIR}\${WESTON_LIBDIR}/weston/ivi-shell.so@g" ${S}/weston-ivi-shell/CMakeLists.txt 
}

do_install_append() {
    # Remove source files
    rm -rf ${D}/usr/src
}

FILES_${PN}-dbg += "${prefix}/bin/.debug"
FILES_${PN}-dbg += "${prefix}/lib/weston/.debug"
FILES_${PN}-dbg += "${prefix}/src/debug/.debug"
FILES_${PN}-dbg += "${prefix}/lib/.debug"
