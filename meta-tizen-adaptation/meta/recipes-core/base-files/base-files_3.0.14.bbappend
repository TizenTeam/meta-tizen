FILESEXTRAPATHS_prepend := "${THISDIR}/base-files:"

SRC_URI += " \
file://base-files.manifest \
"

# Don't use /var/volatile. Instead create regular directories for things that
# used to be symlinks into it (tmp, log).
volatiles_remove = "log tmp"
dirs1777 += " ${localstatedir}/tmp ${localstatedir}/log"
dirs1777_remove = "${localstatedir}/volatile/tmp"
dirs755_remove = "${localstatedir}/volatile ${localstatedir}/volatile/log"
# This gets symlinked to in the .bb but isn't created?
dirs755 += "/run/lock"

merged_dirs = "/bin /lib /sbin"
dirs755_remove = "/bin /lib /sbin"
do_install_prepend () {
        for d in ${merged_dirs}; do
                ln -sf usr$d ${D}$d
        done
}

# Empty directories must be listed explicitly to be packaged.
# This is relevant for our directories with special permissions (see manifest).
DIRFILES_${PN} += "/etc /var/log /var/tmp /tmp"

# The ${merged_dirs} symlinks to directories get ignored by the
# current walk_files() in OE-core's package_rpm.bbclass. A patch
# is needed to support that.

# We don't use the "/var/volatile" support from OE, so provide
# a modified standard file system permission file without those.
FILESYSTEM_PERMS_TABLES = "files/tizen-fs-perms.txt"
