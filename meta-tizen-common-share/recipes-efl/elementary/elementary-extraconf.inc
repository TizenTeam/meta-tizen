SRC_URI += "file://0001-Fix-pathinEOLIAN_FLAGSforyoctobuild.patch \
			file://0001-add-wayland-clientlibinlinkstep.patch"


do_install_prepend () {
    for i in `find ${B}/ -name "*.pc" -type f` ; do \
        sed -i -e 's:-L${STAGING_LIBDIR}:-L\$\{libdir\}:g' -e 's:-I${STAGING_LIBDIR}:-I\$\{libdir\}:g' -e 's:-I${STAGING_INCDIR}:-I\$\{includedir\}:g' $i
    done
}

do_install_append () {
    rm -fr ${D}${prefix}/lib/elementary/examples

}

do_compile_class-native() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  touch ./ABOUT-NLS
  autotools_do_configure
  
  make ${PARALLEL_MAKE}
  
}


DEPENDS_class-native = "efl-native"
DEPENDS_append_class-target = " elementary-native "
EXTRA_OECONF_class-native = " --disable-static --disable-ecore-wayland --disable-ecore-x --disable-build-examples \
							--with-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
					--with-eet-eet=${STAGING_BINDIR_NATIVE}/eet \
					--with-elementary-codegen=${STAGING_BINDIR_NATIVE}/elementary_codegen \
					--with-eolian-gen=${STAGING_BINDIR_NATIVE}/eolian_gen \
					--with-eolian-cxx=${STAGING_BINDIR_NATIVE}/eolian_cxx \
					--with-sysroot-native=${STAGING_DIR_NATIVE} \
					"

FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/prefs/v-1.12.2/.debug"
FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/datetime_input_ctxpopup/v-1.12.2/.debug"
FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/test_entry/v-1.12.2/.debug"
FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/access_output/v-1.12.2/.debug"
FILES_${PN}-dbg += "${prefix}/lib/elementary/modules/test_map/v-1.12.2/.debug"
FILES_${PN}-dbg += "${prefix}/lib/edje/modules/elm/v-1.12/.debug"
