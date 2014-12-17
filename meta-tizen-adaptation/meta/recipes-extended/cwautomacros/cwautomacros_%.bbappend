SECTION = "Development/Building"

do_install_append_srpm () {
    # Fix bug in cwautomacros makefile: CWAUTOMACROSPREFIX must include
    # the build root to get files created there, but the generated files
    # must not contain the build root prefix.
    sed -i -e 's;${D}${prefix};${prefix};g' `find ${D} -type f`
}
