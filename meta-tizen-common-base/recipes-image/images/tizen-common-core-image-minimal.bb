require recipes-image/images/tizen-core-image-minimal.bb

SUMMARY = "A very basic Wayland image with a terminal"
LICENSE = "MIT"
DESCRIPTION = "A weston image with Tizen common."

IMAGE_CLASSES ?= "core-image distro_features_check"
IMAGE_CLASSES_append_x86 += "image-bootdirect"
IMAGE_CLASSES_append_x86-64 += "image-bootdirect"

inherit ${IMAGE_CLASSES}

IMAGE_FEATURES += "splash package-management ssh-server-dropbear hwcodecs"

REQUIRED_DISTRO_FEATURES = "wayland pam"

CORE_IMAGE_BASE_INSTALL += "weston"
CORE_IMAGE_BASE_INSTALL += "weston-init"
CORE_IMAGE_BASE_INSTALL += "clutter-1.0-examples"
CORE_IMAGE_BASE_INSTALL += "weston-common"
CORE_IMAGE_BASE_INSTALL += "weston-common-tz-launcher"
CORE_IMAGE_BASE_INSTALL += "weston-common-config"
CORE_IMAGE_BASE_INSTALL += "desktop-skin"
CORE_IMAGE_BASE_INSTALL += "packagegroup-tizen-gstreamer"
