SECTION = "Multimedia/Service"

# Use bluez5 instead of bluez4
DEPENDS_remove = "bluez4"
PACKAGECONFIG[bluez] = "--enable-bluez,--disable-bluez,bluez5"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://0001-dont-require-target-wayland-scanner.patch"
