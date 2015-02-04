FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# Tizen defconfig
SRC_URI += "${DEFCONFIG}"

# Created with "git format-patch v3.14.19..24e9c9a7dbc184"
# in profile/ivi/kernel-x86-ivi
# and manually filtering out packaging and defconfig changes.
# 0005-i2c-i801-enable-Intel-BayTrail-SMBUS.patch is already
# part of the OE kernel.
#
# Be careful to not include patches already included in the base
# kernel! Otherwise the current linux-yocto base recipe will
# accidentally skip all patches preceeding the redundant,
# see https://bugzilla.yoctoproject.org/show_bug.cgi?id=7282
#
# defconfig files kernel-x86-ivi arch/x86/configs/ivi_x86_defconfig resp.
# arch/x86/configs/ivi_x86_64_defconfig were also copied and modified:
# "CONFIG_64BIT=y" must be set in the x86-64 version and "# CONFIG_64BIT is not set"
# in the i586 one.

SRC_URI += " \
file://0003-Smack-Cgroup-filesystem-access.patch \
file://0007-drm-export-cmdline-and-preferred-mode-functions-from.patch \
file://0008-drm-i915-Pass-explicit-mode-into-mode_from_pipe_conf.patch \
file://0009-drm-i915-allow-re-use-BIOS-connector-config-for-init.patch \
file://0010-drm-i915-split-aligned-height-calculation-out-v2.patch \
file://0011-drm-i915-Shuffle-modeset-reset-handling-around.patch \
file://0012-drm-i915-read-out-hw-state-earlier-v2.patch \
file://0013-drm-i915-re-add-locking-around-hw-state-readout.patch \
file://0014-drm-i915-add-plane_config-fetching-infrastructure-v2.patch \
file://0015-drm-i915-get_plane_config-for-i9xx-v13.patch \
file://0016-drm-i915-get_plane_config-support-for-ILK-v3.patch \
file://0017-drm-i915-Wrap-the-preallocated-BIOS-framebuffer-and-.patch \
file://0018-drm-i915-preserve-SSC-if-previously-set.patch \
file://0019-drm-i915-don-t-bother-enabling-swizzle-bits-on-gen7.patch \
file://0020-drm-i915-use-current-mode-if-the-size-matches-the-pr.patch \
file://0021-drm-i915-remove-early-fb-allocation-dependency-on-CO.patch \
file://0023-drm-i915-Use-the-first-mode-if-there-is-no-preferred.patch \
file://0024-PATCH-drm-i915-vlv-DP_SINK_COUNT-is-not-reliable-for.patch \
file://0034-Export-V4L2-APIs-to-support-early-camera.patch \
file://0035-Add-a-new-v4l2-API-to-enumerate-camera-devs.patch \
file://0036-Share-drm-resources-between-X-and-early-camera.patch \
file://0037-Export-drm-APIs-to-support-early-camera.patch \
file://0038-Create-new-DRM-APIs-for-early-camera.patch \
file://0039-Implements-v2g-bridge-module-for-early-camera.patch \
file://0040-Promote-the-booting-priority-of-scsi-and-ata.patch \
file://0041-move-i915-driver-init-to-late_initcall.patch \
file://0045-NFS-pn533-delete-timer-when-polling-is-complete.patch \
"


# Per architecture defconfig files.
DEFCONFIG_i586 = "file://defconfig"
DEFCONFIG_x86-64 = "file://defconfig"
DEFCONFIG_arm= "file://defconfig"

# Setting the KCONFIG_MODE variable prevents it to being set to
# "--allnoconfig" which disable all kernel options.
KCONFIG_MODE = "--reconfig"

COMPATIBLE_MACHINE_genericx86 = "genericx86"
COMPATIBLE_MACHINE_genericx86-64 = "genericx86-64"