SUMMARY = "Library to handle input devices in Wayland compositors"
HOMEPAGE = "http://www.freedesktop.org/wiki/Software/libinput/"
SECTION = "libs"

PRIORITY = "10"

S = "${WORKDIR}/git"

SRC_URI = "git://review.tizen.org/platform/upstream/libinput;tag=a5414e9de9adf340d061a25bbb27a9df47fd228b;nobranch=1"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=673e626420c7f859fbe2be3a9c13632d"

DEPENDS = "libevdev udev mtdev"

inherit manifest autotools pkgconfig

FILES_${PN} += "/usr/lib/udev/libinput-device-group"
FILES_${PN}-dbg += "/usr/lib/udev/.debug/libinput-device-group"
