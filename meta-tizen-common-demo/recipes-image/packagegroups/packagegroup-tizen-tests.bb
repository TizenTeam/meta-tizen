SUMMARY = "Tizen tests packagegroups"
LICENSE = "MIT"
DESCRIPTION = "Tizen tests packages."
PR = "1"

inherit packagegroup

PACKAGES += "${PN}-connectivity"

# Connectivity test packages
RDEPENDS_${PN}-connectivity = " \
                                bluez5-testtools \
                                neard-tests \
                                connman-tests \
                              "
