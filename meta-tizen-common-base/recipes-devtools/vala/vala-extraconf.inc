inherit pkgconfig

EXTRA_OECONF = " --with-pic --disable-vapigen"

SRC_URI += " file://0001-git-version-gen-don-t-append-dirty-if-we-re-not-in-g.patch"

RDEPENDS_${PN}_remove_class-native = "update-alternatives-native"

DEPENDS_append_class-target = " vala-native"

# When checking out from git, we don't get the guarantee that
# time stamps were preserved as in the pristine tar archive.
# Therefore it is random whether .c files get re-regenerated
# from .vala files, and it randomly failed on vala-native
# unless a suitable valac was installed on the host.
#
# Fix-time-stamp.patch might have been meant to address that
# (unsure, it came without comments), but it did not apply and
# no longer (?) worked after adapting to the more recent release.
# Let's try something else...

# When building the native vala, we do not have valac yet.
# All we can do in this case is assume that the .c files
# are recent and touch the stamp files.
touch_stamps() {
    find ${S} -name '*.stamp' -print0 | xargs -0 touch
}
do_unpack_append_class-native() {
    bb.build.exec_func('touch_stamps', d)
}

# When build the target vala, we have the native valac
# and therefore can re-generate source files.
remove_stamps() {
    find ${S} -name '*.vala' -print0 | xargs -0 touch
}
do_unpack_append_class-target() {
    bb.build.exec_func('remove_stamps', d)
}

do_install_append() {
 rm -rf ${D}${prefix}/share/devhelp
}

vala_files += "${prefix}/bin/vala"
vala_files += "${prefix}/bin/valac"
vala_files += "${prefix}/bin/vala-gen-introspect"
vala_files += "${prefix}/bin/vapicheck"
vala_files += "${prefix}/bin/vapigen"
vala_files += "${mandir}/man1/valac.1*"
vala_files += "${mandir}/man1/vala-gen-introspect.1*"
vala_files += "${mandir}/man1/vapigen.1*"

FILES_${PN}-dbg += "${prefix}/lib/vala-0.26/.debug"
vala_files += "${prefix}/share/pkgconfig/vapigen.pc"
