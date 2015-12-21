PACKAGECONFIG ??= "${@bb.utils.contains('SOC_FAMILY', 'rpi', '', 'egl', d)}"
PACKAGECONFIG += "${@bb.utils.contains('SOC_FAMILY', 'rpi', '', 'cairo-glesv2', d)}"

RDEPENDS_${PN} += "xkeyboard-config"
RRECOMMENDS_${PN} = "liberation-fonts"

RDEPENDS_${PN}_remove = "weston-startup"

SRC_URI += "file://make-lcms-explicitly-configurable.patch"
SRC_URI += "file://make-libwebp-explicitly-configurable.patch"

EXTRA_OECONF += "   \
                    --disable-vaapi-recorder \
                    --enable-weston-launch \
                    --enable-sys-uid \
                    --enable-fbdev-compositor \
                    --disable-headless-compositor \
                    --enable-setuid-install \
                    --enable-demo-clients-install \
                    --disable-lcms \
                    --disable-webp \
                    "

EXTRA_OECONF += "   --disable-rdp-compositor "
                    
EXTRA_OECONF += "   --disable-dbus"

EXTRA_OECONF += " --disable-static \
  --enable-clients \
  --disable-libunwind \
  --disable-rpi-compositor \
  --disable-setuid-install \
  --enable-simple-clients \
  --disable-x11-compositor \
  --disable-xwayland \
  --disable-xwayland-test \
  "

# The current experimental vc4 drivers for RPI2 don't like the glesv2 backend
#	so, only enable it for archs where this is known to work

EXTRA_OECONF += "${@bb.utils.contains('PACKAGECONFIG', 'cairo-glesv2', ' --with-cairo=glesv2', '', d)}"


# Weston with EGL support
EXTRA_OECONF += "${@bb.utils.contains('PACKAGECONFIG', 'egl', ' --enable-egl --enable-simple-egl-clients --enable-drm-compositor --enable-wayland-compositor', '--disable-egl', d)}"


do_configure_prepend() {
    sed -i 's/PKG_CHECK_MODULES(WAYLAND_SCANNER, wayland-scanner)//' configure.ac
}

pkg_preinst_${PN}() {
}

export libexecdir="${prefix}/libexec"

FILES_${PN} += "${prefix}/lib/weston/cms-static.so"

FILES_${PN} += "${prefix}/bin/weston-scaler"
FILES_${PN} += "${prefix}/bin/weston-stacking"
FILES_${PN} += "${prefix}/bin/weston-multi-resource"
