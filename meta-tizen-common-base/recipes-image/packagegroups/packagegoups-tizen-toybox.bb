SUMMARY = "Tizen toybox packagegroups"
LICENSE = "BSD"
DESCRIPTION = "Tizen toybox packages."

inherit packagegroup

PACKAGES = "\
            packagegroup-tizen-toybox\
            "

# dev tools fonts packages
RDEPENDS_packagegroup-tizen-toybox = " \
                                        toybox-coreutils \
                                        toybox-findutils \
                                        toybox-cpio \
                                        toybox-binutils \
                                        toybox-diffutils \
                                        toybox-dosfstools \
                                        toybox-grep \
                                        toybox-tar \
                                        toybox-sed \
                                        toybox-patch \
                                        toybox-other \
                                        "
