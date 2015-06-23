SRC_URI += "file://Add_extralib.diff"
SRC_URI += "file://0001-pkgmgr-do-not-set-an-absolute-path-to-msgfmt.patch"
SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"

do_compile_prepend_class-native() {
 sed -i "s@"/usr/bin/pkginfo@"${STAGING_BINDIR_NATIVE}/pkginfo@g" ${S}/tool/pkg_initdb.c
}

do_install_append() {
 rm -fr "${D}${prefix}/bin/pkgcmd.real"
 rm -fr "${D}${prefix}/bin/pkgcmd.wrapper"
}

RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "dlog-native"

RDEPENDS_${PN}-client += "pkgmgr-server"

EXTRA_OECMAKE+="-DCMAKE_AR:PATH=ar"
