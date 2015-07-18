SUMMARY = "Tizen dev tools packagegroups"
LICENSE = "MIT"
DESCRIPTION = "Tizen dev tools packages."
PR = "1"

inherit packagegroup

PACKAGES += "${PN}-tools"

# dev tools fonts packages
RDEPENDS_${PN}-tools = " \
                         attr \
                         acl \
                         util-linux-agetty \
                         strace \
                         gdb \
                         lsof \
                         screen \
                         ldd \
                         libcap \
                         sudo \
                         connman-client \
                         git \
                         python-json \
                         dlogutil \
                       "
