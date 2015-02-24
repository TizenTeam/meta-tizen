SRC_URI_class-native += "file://0001-remove-buxtondgeneration.patch"


DEPENDS_class-native = ""
DEPENDS_class-native += "systemd-native "
DEPENDS_class-native += "libcheck-native"
DEPENDS_class-native += "attr-native"
DEPENDS_class-native += "gdbm-native"

RDEPENDS_${PN}_class-native = ""
RDEPENDS_${PN}_class-native += "coreutils"
RDEPENDS_${PN}_class-native += "smack"

do_prep_class-native() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/buxton.manifest .
 
 
}
