SRC_URI += "file://0001-Add-env-value-SYSROOT-for-root-fs-prefix.patch"


RDEPENDS_${PN}_remove_class-native = "toybox-coreutils-native"
RDEPENDS_${PN}_class-native += "coreutils"

do_configure_append_class-native() {
 sed -i "s@\"/etc/tizen-platform.conf\"@\"${sysconfdir}/tizen-platform.conf\"@g" ${S}/src/init.c
 sed -i "s@\"/etc/tizen-platform.conf\"@\"${sysconfdir}/tizen-platform.conf\"@g" ${S}/src/toolbox.c
}


