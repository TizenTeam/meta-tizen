require recipes-image/images/tizen-core-image-minimal.bb

# meta-common is not used in Tizen IVI 3.0. It is also not clear which
# purpose it would serve when building with Yocto (it contains package
# groups for mic, which is not used yet). Remove it.
CORE_IMAGE_BASE_INSTALL_remove = "meta-common"

# Obsolete, at least in Tizen IVI 3.0.
CORE_IMAGE_BASE_INSTALL_remove = "user-session-units"

SUMMARY = "Tizen IVI core image"

LICENSE = "MIT"

DESCRIPTION = "A Tizen IVI image based on Tizen common ."

# weston-init is from OE-core and not used in Tizen IVI.
CORE_IMAGE_BASE_INSTALL_remove = "weston-init"

# Weston config files are provided by tlm-config-* in recent Tizen IVI.
# weston-ivi-config is not used at all anymore.
WESTONINI = ""

CORE_IMAGE_EXTRA_INSTALL += "automotive-message-broker"
CORE_IMAGE_EXTRA_INSTALL += "efl-theme-tizen-hd"
CORE_IMAGE_EXTRA_INSTALL += "festival"
CORE_IMAGE_EXTRA_INSTALL += "genivi-audio-manager"

CORE_IMAGE_EXTRA_INSTALL += "lemolo"
CORE_IMAGE_EXTRA_INSTALL += "libwebsockets"
CORE_IMAGE_EXTRA_INSTALL += "murphy"
CORE_IMAGE_EXTRA_INSTALL += "node-startup-controller"
CORE_IMAGE_EXTRA_INSTALL += "pulseaudio-module-murphy-ivi"
CORE_IMAGE_EXTRA_INSTALL += "${WESTONINI}"

# TMP Remove rygel
# BTY-36
#CORE_IMAGE_EXTRA_INSTALL += "rygel"


CORE_IMAGE_EXTRA_INSTALL += "sphinxbase"
CORE_IMAGE_EXTRA_INSTALL += "udev-rules-ivi"
CORE_IMAGE_EXTRA_INSTALL += "genivi-shell"
CORE_IMAGE_EXTRA_INSTALL += "weston-ivi-shell"

# Time zone
CORE_IMAGE_EXTRA_INSTALL += "tzdata"

# gstreamer
CORE_IMAGE_BASE_INSTALL += "packagegroup-tizen-gstreamer"
