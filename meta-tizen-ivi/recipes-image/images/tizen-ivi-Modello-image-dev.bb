require recipes-image/images/tizen-ivi-Modello-image.bb

DESCRIPTION = "A Tizen ivi image base on Tizen ivi with Modello and \
               is suitable for debugging the image."

IMAGE_FEATURES += "tools-debug debug-tweaks ssh-server-openssh"
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-dev-tools"
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-tests-connectivity"
