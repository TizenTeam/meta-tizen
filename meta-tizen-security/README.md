This layer adds security components and configuration from Tizen to a
standard OE distribution.

It has some dependencies on a suitable BSP; in particular the kernel
must have certain Smack-related patches. For linux-yocto 3.14, the
necessary patches are added by this layer. The necessary kernel
configuration parameters are added to all kernel versions by this
layer.

To enable security, add the layer bblayers.conf and in the following entries
to local.conf:

# Enable Smack support. Eventually this needs to move into a distro conf
# where it needs to be added to DISTROOVERRIDES depending on a distro
# feature.
OVERRIDES .= ":smack"

# Enable systemd.
DISTRO_FEATURES_append = " pam"
DISTRO_FEATURES_append += " systemd"
VIRTUAL-RUNTIME_init_manager = "systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
VIRTUAL-RUNTIME_initscripts = ""
# CORE_IMAGE_EXTRA_INSTALL += "systemd-analyze"

# Need Smack support in file utilities.
CORE_IMAGE_EXTRA_INSTALL += "coreutils"

# Having Smack utilities is useful.
CORE_IMAGE_EXTRA_INSTALL += "smack-userspace"
