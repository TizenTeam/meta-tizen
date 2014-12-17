SECTION = "Development/Tools/Building"

# gnu-conf installs new config.guess files as part of reconfiguring.
# This is useful when adding new architectures often. In Tizen, it
# leads to a dependency on a new project (gnu-config), so don't use it
# (yet).
SRC_URI_remove_srpm = "file://autoreconf-gnuconfigize.patch"
RDEPENDS_${PN}_remove_srpm = "gnu-config"
