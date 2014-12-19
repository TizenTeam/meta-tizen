SECTION = "Base/Libraries"
SRPM_IS_LIB = "${PN}-date-time ${PN}-filesystem ${PN}-graph ${PN}-iostreams ${PN}-program-options ${PN}-regex ${PN}-serialization ${PN}-signals ${PN}-system ${PN}-test ${PN}-thread"

do_compile_prepend() {
       # Remove x bit from unpacked data files, because they would end up getting
       # installed that way, which just does not make sense for data files.
       find ${S} -type f ! \( -name \*.sh -o -name \*.py -o -name \*.pl \) -exec chmod -x {} +
}
