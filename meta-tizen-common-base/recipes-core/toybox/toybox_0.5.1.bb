SUMMARY = "Toybox combines common utilities together into a single executable."
HOMEPAGE = "http://www.landley.net/toybox/"

SRC_URI = "git://review.tizen.org/platform/upstream/toybox;branch=tizen"
SRCREV = "${AUTOREV}"

LICENSE = "BSD-0-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=f0b8b3dd6431bcaa245da0a08bd0d511"

BBCLASSEXTEND = "native"
PROVIDES += ""

S = "${WORKDIR}/git"
PROVIDES += "toybox-coreutils"
PROVIDES += "toybox-cpio"
PROVIDES += "toybox-binutils"
PROVIDES += "toybox-diffutils"
PROVIDES += "toybox-findutils"
PROVIDES += "toybox-dosfstools"
PROVIDES += "toybox-grep"
PROVIDES += "toybox-tar"
PROVIDES += "toybox-sed"
PROVIDES += "toybox-patch"
PROVIDES += "toybox-xz"
PROVIDES += "toybox-other"

RDEPENDS_toybox-coreutils += "toybox"
RDEPENDS_toybox-cpio += "toybox"
RDEPENDS_toybox-binutils += "toybox"
RDEPENDS_toybox-diffutils += "toybox"
RDEPENDS_toybox-findutils += "toybox"
RDEPENDS_toybox-dosfstools += "toybox"
RDEPENDS_toybox-grep += "toybox"
RDEPENDS_toybox-tar += "toybox"
RDEPENDS_toybox-sed += "toybox"
RDEPENDS_toybox-patch += "toybox"
RDEPENDS_toybox-xz += "toybox"
RDEPENDS_toybox-other += "toybox"

do_configure() {
    cp packaging/config ./.config
}


do_install() {
	oe_runmake PREFIX=./ install
    # Install manually instead of using 'make install'
    install -d ${D}${bindir}
    install -d ${D}${sbindir}
    install -m 0755 ${B}/bin/* ${D}/${bindir}
    install -m 0755 ${B}/usr/bin/* ${D}/${bindir}
    install -m 0755 ${B}/usr/sbin/* ${D}/${sbindir}
}

pkg_postinst_toybox-coreutils() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-cpio() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-binutils() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-diffutils() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-findutils() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-dosfstools() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-grep() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-tar() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-sed() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-patch() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-xz() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_toybox-other() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN} ${PN}-coreutils ${PN}-cpio ${PN}-binutils ${PN}-diffutils ${PN}-dosfstools ${PN}-findutils ${PN}-grep ${PN}-tar ${PN}-sed ${PN}-patch ${PN}-xz ${PN}-other"

toybox_files = ""
toybox_files += "${prefix}/bin/toybox"
toybox_files += "${prefix}/bin/toysh"

toybox-coreutils_files = ""
toybox-coreutils_files += "${prefix}/bin/basename"
toybox-coreutils_files += "${prefix}/bin/cat"
toybox-coreutils_files += "${prefix}/bin/chgrp"
toybox-coreutils_files += "${prefix}/bin/chmod"
toybox-coreutils_files += "${prefix}/bin/chown"
toybox-coreutils_files += "${prefix}/bin/cksum"
toybox-coreutils_files += "${prefix}/bin/comm"
toybox-coreutils_files += "${prefix}/bin/cp"
toybox-coreutils_files += "${prefix}/bin/cut"
toybox-coreutils_files += "${prefix}/bin/date"
toybox-coreutils_files += "${prefix}/bin/dd"
toybox-coreutils_files += "${prefix}/bin/dirname"
toybox-coreutils_files += "${prefix}/bin/du"
toybox-coreutils_files += "${prefix}/bin/echo"
toybox-coreutils_files += "${prefix}/bin/env"
toybox-coreutils_files += "${prefix}/bin/expand"
toybox-coreutils_files += "${prefix}/bin/expr"
toybox-coreutils_files += "${prefix}/bin/factor"
toybox-coreutils_files += "${prefix}/bin/false"
toybox-coreutils_files += "${prefix}/bin/fold"
toybox-coreutils_files += "${prefix}/bin/groups"
toybox-coreutils_files += "${prefix}/bin/head"
toybox-coreutils_files += "${prefix}/bin/id"
toybox-coreutils_files += "${prefix}/bin/install"
toybox-coreutils_files += "${prefix}/bin/kill"
toybox-coreutils_files += "${prefix}/bin/link"
toybox-coreutils_files += "${prefix}/bin/ln"
toybox-coreutils_files += "${prefix}/bin/logname"
toybox-coreutils_files += "${prefix}/bin/ls"
toybox-coreutils_files += "${prefix}/bin/md5sum"
toybox-coreutils_files += "${prefix}/bin/mkdir"
toybox-coreutils_files += "${prefix}/bin/mkfifo"
toybox-coreutils_files += "${prefix}/bin/mknod"
toybox-coreutils_files += "${prefix}/bin/mktemp"
toybox-coreutils_files += "${prefix}/bin/mv"
toybox-coreutils_files += "${prefix}/bin/nice"
toybox-coreutils_files += "${prefix}/bin/nl"
toybox-coreutils_files += "${prefix}/bin/nohup"
toybox-coreutils_files += "${prefix}/bin/od"
toybox-coreutils_files += "${prefix}/bin/paste"
toybox-coreutils_files += "${prefix}/bin/printenv"
toybox-coreutils_files += "${prefix}/bin/printf"
toybox-coreutils_files += "${prefix}/bin/pwd"
toybox-coreutils_files += "${prefix}/bin/readlink"
toybox-coreutils_files += "${prefix}/bin/realpath"
toybox-coreutils_files += "${prefix}/bin/rm"
toybox-coreutils_files += "${prefix}/bin/rmdir"
toybox-coreutils_files += "${prefix}/bin/seq"
toybox-coreutils_files += "${prefix}/bin/sha1sum"
toybox-coreutils_files += "${prefix}/bin/sleep"
toybox-coreutils_files += "${prefix}/bin/sort"
toybox-coreutils_files += "${prefix}/bin/split"
toybox-coreutils_files += "${prefix}/bin/stat"
toybox-coreutils_files += "${prefix}/bin/sync"
toybox-coreutils_files += "${prefix}/bin/tac"
toybox-coreutils_files += "${prefix}/bin/tail"
toybox-coreutils_files += "${prefix}/bin/tee"
toybox-coreutils_files += "${prefix}/bin/test"
toybox-coreutils_files += "${prefix}/bin/timeout"
toybox-coreutils_files += "${prefix}/bin/touch"
toybox-coreutils_files += "${prefix}/bin/tr"
toybox-coreutils_files += "${prefix}/bin/true"
toybox-coreutils_files += "${prefix}/bin/truncate"
toybox-coreutils_files += "${prefix}/bin/tty"
toybox-coreutils_files += "${prefix}/bin/uname"
toybox-coreutils_files += "${prefix}/bin/uniq"
toybox-coreutils_files += "${prefix}/bin/unlink"
toybox-coreutils_files += "${prefix}/bin/wc"
toybox-coreutils_files += "${prefix}/bin/who"
toybox-coreutils_files += "${prefix}/bin/whoami"
toybox-coreutils_files += "${prefix}/bin/yes"
toybox-coreutils_files += "${prefix}/sbin/chroot"
toybox-coreutils_files += "${prefix}/sbin/df"

toybox-cpio_files = ""
toybox-cpio_files += "${prefix}/bin/cpio"

toybox-binutils_files = ""
toybox-binutils_files += "${prefix}/bin/strings"

toybox-diffutils_files = ""
toybox-diffutils_files += "${prefix}/bin/cmp"
toybox-diffutils_files += "${prefix}/bin/diff"

toybox-findutils_files = ""
toybox-findutils_files += "${prefix}/bin/find"
toybox-findutils_files += "${prefix}/bin/xargs"

toybox-dosfstools_files = ""
toybox-dosfstools_files += "${prefix}/bin/fsck"

toybox-grep_files = ""
toybox-grep_files += "${prefix}/bin/egrep"
toybox-grep_files += "${prefix}/bin/grep"
toybox-grep_files += "${prefix}/bin/fgrep"

toybox-tar_files = ""
toybox-tar_files += "${prefix}/bin/tar"

toybox-sed_files = ""
toybox-sed_files += "${prefix}/bin/sed"

toybox-patch_files = ""
toybox-patch_files += "${prefix}/bin/patch"

toybox-xz_files = ""
toybox-xz_files += "${prefix}/bin/xzcat"

toybox-other_files = ""
toybox-other_files += "${prefix}/bin/bzcat"
toybox-other_files += "${prefix}/bin/compress"
toybox-other_files += "${prefix}/bin/dos2unix"
toybox-other_files += "${prefix}/bin/help"
toybox-other_files += "${prefix}/bin/sh"
toybox-other_files += "${prefix}/bin/unix2dos"
toybox-other_files += "${prefix}/bin/zcat"

FILES_${PN} = "${toybox_files}"
FILES_${PN}-coreutils = "${toybox-coreutils_files}"
FILES_${PN}-cpio = "${toybox-cpio_files}"
FILES_${PN}-binutils = "${toybox-binutils_files}"
FILES_${PN}-diffutils = "${toybox-diffutils_files}"
FILES_${PN}-findutils = "${toybox-findutils_files}"
FILES_${PN}-dosfstools = "${toybox-dosfstools_files}"
FILES_${PN}-grep = "${toybox-grep_files}"
FILES_${PN}-tar = "${toybox-tar_files}"
FILES_${PN}-sed = "${toybox-sed_files}"
FILES_${PN}-patch = "${toybox-patch_files}"
FILES_${PN}-xz = "${toybox-xz_files}"
FILES_${PN}-other = "${toybox-other_files}"

PKG_${PN} = "toybox"
PKG_${PN}-coreutils = "toybox-coreutils"
PKG_${PN}-cpio = "toybox-cpio"
PKG_${PN}-binutils = "toybox-binutils"
PKG_${PN}-diffutils = "toybox-diffutils"
PKG_${PN}-findutils = "toybox-findutils"
PKG_${PN}-dosfstools = "toybox-dosfstools"
PKG_${PN}-grep = "toybox-grep"
PKG_${PN}-tar = "toybox-tar"
PKG_${PN}-sed = "toybox-sed"
PKG_${PN}-patch = "toybox-patch"
PKG_${PN}-xz = "toybox-xz"
PKG_${PN}-other = "toybox-other"
