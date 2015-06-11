SYSLINUX_ROOT_task-bootdirectdisk = "root=PARTUUID=${DISK_SIGNATURE}-02"
APPEND_prepend_task-bootdirectdisk = " rootwait"
SYSLINUX_PROMPT ?= "0"
SYSLINUX_TIMEOUT ?= "10"
SYSLINUX_LABELS_task-bootdirectdisk = "boot"
#LABELS_task-bootdirectdisk = " ${SYSLINUX_LABELS} "

SYSLINUXCFG_task-bootdirectdisk = "syslinux_direcdisk.cfg"
GRUBCFG_task-bootdirectdisk = "grub_direcdisk.cfg"

INITRD_task-bootdirectdisk = ""

# need to define the dependency and the ROOTFS for directdisk
do_bootdirectdisk[depends] += "${PN}:do_rootfs"
ROOTFS ?= "${DEPLOY_DIR_IMAGE}/${IMAGE_BASENAME}-${MACHINE}.ext3"

inherit boot-directdisk

IMAGE_TYPEDEP_bootdirect = "ext3"
IMAGE_TYPES_MASKED += "bootdirect"
