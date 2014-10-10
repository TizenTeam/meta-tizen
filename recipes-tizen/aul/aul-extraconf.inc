do_prep_append() {
    sed -i 's!/usr/bin/mkdir -p!/bin/mkdir -p!g' ${S}/packaging/ac.service
    # preload_list.txt and preexec_list.txt are generated from .in files so they are located in the build directory instead of the source one
    sed -i 's@INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/legacy/preload_list.txt DESTINATION /usr/share/aul )@INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/legacy/preload_list.txt DESTINATION /usr/share/aul )@' ${S}/CMakeLists.txt
    sed -i 's@INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/feature/preexec_list.txt DESTINATION /usr/share/aul )@INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/feature/preexec_list.txt DESTINATION /usr/share/aul )@' ${S}/CMakeLists.txt
}

SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"
aul_files += "${prefix}/share/aul/mida_db.sql"

RDEPENDS_${PN}_remove_class-native = "systemd-native"
RDEPENDS_${PN}_remove_class-native = "eglibc-native"

DEPENDS_remove_class-native = "dlog-native"

EXTRA_OECMAKE+="-DCMAKE_AR:PATH=ar"