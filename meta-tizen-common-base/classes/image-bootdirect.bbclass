
#NOISO = "1"

SYSLINUX_ROOT ?= "root=/dev/sda2"
SYSLINUX_PROMPT ?= "0"
SYSLINUX_TIMEOUT ?= "10"
SYSLINUX_LABELS = "boot"
LABELS_append = " ${SYSLINUX_LABELS} "

# need to define the dependency and the ROOTFS for directdisk
do_bootdirectdisk[depends] += "${PN}:do_rootfs"
ROOTFS ?= "${DEPLOY_DIR_IMAGE}/${IMAGE_BASENAME}-${MACHINE}.ext3"

# creating VMDK relies on having a live hddimg so ensure we
# inherit it here.
#inherit image-live
inherit boot-directdisk

IMAGE_TYPEDEP_bootdirect = "ext3"
IMAGE_TYPES_MASKED += "bootdirect"


python do_bootdirectimg() {
        # bb.build.exec_func('create_vmdk_image', d)
        return 0
}

addtask do_bootdirectimg after do_bootdirectdisk before do_build

##do_vmdkimg[depends] += "qemu-native:do_populate_sysroot" 

