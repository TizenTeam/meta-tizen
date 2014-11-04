DESCRIPTION = "Tizen emulator kernel"
SECTION = "kernel"
LICENSE = "GPLv2"

# Derived from poky/meta-skeleton/recipes-kernel/linux/linux-yocto-custom.bb

inherit kernel
require recipes-kernel/linux/linux-yocto.inc

SRC_URI = "git://review.tizen.org/sdk/emulator/emulator-kernel;nocheckout=1;name=machine;branch=tizen"

LINUX_VERSION ?= "3.10"
LINUX_VERSION_EXTENSION ?= "-tizen"

SRCREV_machine="38ecc4894a55b225cca19f88f47a7397e7b39c2f"

do_configure_prepend() {
    # Exactly the same kernel config as in Tizen.
    cp "${S}/arch/x86/configs/i386_tizen_emul_defconfig" "${B}/.config"

    # We build out-of-tree and therefore must copy the Tizen ramfs into
    # the build directory where it is expected by the Tizen kernel config.
    rm -rf "${B}/ramfs"
    cp -a "${S}"/ramfs "${B}"

    # Use normal runqemu with root = /dev/sda, instead of kvm accelerated virtio with root = /dev/vda.
    perl -pi -e 's;nod /dev/vda 0600 0 0 b 254 0;nod /dev/sda 0600 0 0 b 8 0;' "${B}/ramfs/initramfs"
    perl -pi -e 's;/dev/vda;/dev/sda;' "${B}/ramfs/init"

    # systemd is /usr/sbin/init on Tizen. We don't have a symlink for it when
    # building with Yocto.
    perl -pi -e 's; /sbin/init; /usr/sbin/init;' "${B}/ramfs/init"

    # TODO: ramfs/init is so simplistic, why do we use it at all?

    # sed -e 's/CONFIG_BLK_DEV_INITRD=.*/# CONFIG_BLK_DEV_INITRD unset by linux-emulator .bb/' "${S}/arch/x86/configs/i386_tizen_emul_defconfig" >"${B}/.config"
}

PR = "r1"
PV = "${LINUX_VERSION}+git${SRCPV}"

COMPATIBLE_MACHINE = "qemux86"
SRC_URI += "file://defconfig"

COMPATIBLE_MACHINE = "qemux86"
