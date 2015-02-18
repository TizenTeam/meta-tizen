INSANE_SKIP_${PN} = "dev-so"

DEPENDS += "efl-native"

# Build efl native with the fewest dependency possible
DEPENDS_class-native = ""
DEPENDS_class-native += "zlib-native"
DEPENDS_class-native += "tiff-native"
DEPENDS_class-native += "openssl-native"
DEPENDS_class-native += "curl-native"
DEPENDS_class-native += "fontconfig-native"
DEPENDS_class-native += "freetype-native"
DEPENDS_class-native += "wayland-native"
DEPENDS_class-native += "glib-2.0-native"
DEPENDS_class-native += "lua-native"
DEPENDS_class-native += "libpng-native"
DEPENDS_class-native += "pixman-native"
DEPENDS_class-native += "libcheck-native"
DEPENDS_class-native += "giflib-native"
DEPENDS_class-native += "gnutls-native"
DEPENDS_class-native += "util-linux-native"
DEPENDS_class-native += "vconf-native"
DEPENDS_class-native += "fribidi-native"
DEPENDS_class-native += "dbus-native"

EXTRA_OECONF_append_class-target = " \
    --with-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
    --with-eolian-gen=${STAGING_BINDIR_NATIVE}/eolian_gen \
    --with-eolian-cxx=${STAGING_BINDIR_NATIVE}/eolian_cxx \
    "

# Disable as much options as possible for efl-native
EXTRA_OECONF_class-native = " \
    --disable-fontconfig \
    --disable-audio \
    --with-x11=none \
    --disable-image-loader-bmp \
    --disable-image-loader-eet \
    --disable-image-loader-generic \
    --disable-image-loader-gif \
    --disable-image-loader-ico \
    --disable-image-loader-jp2k \
    --disable-image-loader-pmaps \
    --disable-image-loader-psd \
    --disable-image-loader-tga \
    --disable-image-loader-wbmp \
    --disable-image-loader-webp \
    --disable-image-loader-xpm \
    --disable-systemd \
    --disable-gstreamer \
    --disable-gstreamer1 \
    --disable-physics \
    --enable-i-really-know-what-i-am-doing-and-that-this-will-probably-break-things-and-i-will-fix-them-myself-and-send-patches-aaa \
    --enable-lua-old \
"

do_configure_prepend_class-native() {
	echo export RPM_BUILD_ROOT=${D}
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    rm -rf ${D}
    mkdir -p ${D}

	autotools_do_configure
}

do_install_class-native() {
    echo export RPM_BUILD_ROOT=${D}
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    rm -rf ${D}
    mkdir -p ${D}
	
    # "oe_runmake" fails so we use "make" instead
    make \
        DESTDIR=${D} \
        INSTALL_ROOT=${D} \
        BINDIR=${prefix}/bin \
    install

    rm -f ${D}${infodir}/dir 
    find ${D} -regex ".*\.la$" | xargs rm -f -- 
    find ${D} -regex ".*\.a$" | xargs rm -f --

    # We don't build the examples so don't install them
    # oe_runmake datadir=${D}${prefix}/share install-examples
    rm -rf ${D}${prefix}/lib/ecore/system/upower
}
