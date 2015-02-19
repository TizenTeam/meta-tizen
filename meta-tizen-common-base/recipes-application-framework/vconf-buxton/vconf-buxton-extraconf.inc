RDEPENDS_${PN}_remove_class-native = "glibc-native"
RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_vconf-buxton_remove_class-native = "systemd-native"

DEPENDS_class-native += "systemd-native"
DEPENDS_class-native += "vconf-internal-keys-native"
DEPENDS_class-native += "buxton-native"

