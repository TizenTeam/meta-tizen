# Base this image on rpi-hwup-image
include recipes-core/images/rpi-hwup-image.bb	

IMAGE_EXTRA_INSTALL += "nodejs"
IMAGE_EXTRA_INSTALL += "nodejs-npm"
IMAGE_EXTRA_INSTALL += "nginx"
IMAGE_EXTRA_INSTALL += "wpa-supplicant"
IMAGE_EXTRA_INSTALL += "openssh openssh-sftp-server"
IMAGE_EXTRA_INSTALL += "systemd-serialgetty util-linux-agetty procps"
IMAGE_EXTRA_INSTALL += "userland"

# Set root password to "root"
ROOTFS_POSTPROCESS_COMMAND += "set_root_passwd;"
set_root_passwd() {
    sed 's%^root:[^:]*:%root:wYNffsf6sozwE:%' \
        < ${IMAGE_ROOTFS}/etc/shadow \
        > ${IMAGE_ROOTFS}/etc/shadow.new;
    mv ${IMAGE_ROOTFS}/etc/shadow.new ${IMAGE_ROOTFS}/etc/shadow ;
}

def get_kernelversion_file(p):
    fn = p + '/kernel-abiversion'

    try:
        with open(fn, 'r') as f:
            return f.readlines()[0].strip()
    except IOError:
        return None

STAGING_KERNEL_BUILDDIR = "${TMPDIR}/work-shared/${MACHINE}/kernel-build-artifacts"
