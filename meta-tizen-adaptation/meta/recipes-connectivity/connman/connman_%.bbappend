SECTION = "Network & Connectivity/Connection Management"

# Build without ppp, not in Tizen.
DEPENDS_remove = "ppp"

# Build without the wpa-supplicant build dependency,
# it was not used in Tizen so far and seems to be optional.
# Tizen does not even provide a wpa-supplicant-devel.
DEPENDS_remove = "wpa-supplicant"

# Build without Bluez. Not used in Tizen.
DEPENDS_remove = "bluez4 bluez5"
RDEPENDS_remove = "bluez4 bluez5"

# The Tizen patches add a build dependency on readline.
DEPENDS_append = " readline"
