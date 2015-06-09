NOISO = "1"
NOHDD = "1"

SYSLINUX_ROOT = "root=PARTUUID=${DISK_SIGNATURE}-02"
APPEND_prepend = " rootwait"
SYSLINUX_PROMPT ?= "0"
SYSLINUX_TIMEOUT ?= "10"
SYSLINUX_LABELS = "boot"
LABELS_append = " ${SYSLINUX_LABELS} "

# need to define the dependency and the ROOTFS for directdisk
do_bootdirectdisk[depends] += "${PN}:do_rootfs"
ROOTFS ?= "${DEPLOY_DIR_IMAGE}/${IMAGE_BASENAME}-${MACHINE}.ext3"

inherit boot-directdisk

IMAGE_TYPEDEP_bootdirect = "ext3"
IMAGE_TYPES_MASKED += "bootdirect"

python build_efi_cfg() {
    import sys

    workdir = d.getVar('WORKDIR', True)
    if not workdir:
        bb.error("WORKDIR not defined, unable to package")
        return

    gfxserial = d.getVar('GRUB_GFXSERIAL', True) or ""

    cfile = d.getVar('GRUBCFG', True)
    if not cfile:
        raise bb.build.FuncFailed('Unable to read GRUBCFG')

    try:
         cfgfile = file(cfile, 'w')
    except OSError:
        raise bb.build.funcFailed('Unable to open %s' % (cfile))

    cfgfile.write('# Automatically created by OE\n')

    opts = d.getVar('GRUB_OPTS', True)
    if opts:
        for opt in opts.split(';'):
            cfgfile.write('%s\n' % opt)

    cfgfile.write('default=boot\n')

    timeout = d.getVar('GRUB_TIMEOUT', True)
    if timeout:
        cfgfile.write('timeout=%s\n' % timeout)
    else:
        cfgfile.write('timeout=50\n')

    if gfxserial == "1":
        btypes = [ [ " graphics console", "" ],
            [ " serial console", d.getVar('GRUB_SERIAL', True) or "" ] ]
    else:
        btypes = [ [ "", "" ] ]

    localdata = d.createCopy()

    overrides = localdata.getVar('OVERRIDES', True)
    if not overrides:
        raise bb.build.FuncFailed('OVERRIDES not defined')

    disksignature = localdata.getVar('DISK_SIGNATURE', True)
    if not disksignature:
        raise bb.build.FuncFailed('DISK_SIGNATURE not defined')

    for btype in btypes:
        localdata.setVar('OVERRIDES', 'boot:' + overrides)
        bb.data.update_data(localdata)

        cfgfile.write('\nmenuentry boot\'%s\'{\n' % (btype[0]))
        cfgfile.write('root=(hd0,2)\n')
        cfgfile.write('linux /boot/bzImage')

        append = localdata.getVar('APPEND', True)

        if append:
            cfgfile.write('%s' % (append))
        cfgfile.write(' %s' % btype[1])
        cfgfile.write('\n')

        cfgfile.write(' %s' % btype[1])
        cfgfile.write('\n}\n')

    cfgfile.close()
}
