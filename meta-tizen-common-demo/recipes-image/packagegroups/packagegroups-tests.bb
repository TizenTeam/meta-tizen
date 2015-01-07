SUMMARY = "Tizen tests packagegroups"
LICENSE = "MIT"
DESCRIPTION = "Tizen tests packages."

inherit packagegroup

PACKAGES = " \
            packagegroup-tizen-tests-connectivity \
            "

# gstreamer packages
RDEPENDS_packagegroup-tizen-tests-connectivity = " \
                                                    bluez5-testtools \
                                                    neard-tests \
                                                    connman-tests \
                                                    "
