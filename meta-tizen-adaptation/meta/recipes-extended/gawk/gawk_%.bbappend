SECTION = "Base/Utilities"

do_install_append_srpm () {
       # In Tizen, we package the "awk" symlink that was removed.
       # Recreate it because we cannot remove the rm command (?!).
       ln -s gawk ${D}${bindir}/awk
}

RPROVIDES_${PN}_append_srpm = " awk"
