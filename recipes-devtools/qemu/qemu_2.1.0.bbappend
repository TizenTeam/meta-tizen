# Switch to pulling from Tizen git. This is qemu 2.0.0 with lots of Tizen patches.
SRC_URI_remove = "http://wiki.qemu-project.org/download/${BP}.tar.bz2 file://Qemu-Arm-versatilepb-Add-memory-size-checking.patch"
SRC_URI_prepend = " git://review.tizen.org/sdk/emulator/qemu;rev=ed403ab0f23052948f5e060e937f7105e4381c43;nobranch=1 "

S = "${WORKDIR}/git"
PV = "2.0.0.tizen"

SRC_URI += "file://0001-configure-fix-vigs-X11-dependency.patch"
FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

# --disable-lzo and --disable-numa do not exist yet in 2.0.0.
PACKAGECONFIG[lzo] = ""
PACKAGECONFIG[numa] = ""

# Enable yagl support (see https://wiki.tizen.org/wiki/Emulator#Tizen:Common_on_qemu-yagl_:_ia32)
EXTRA_OECONF_append = " --enable-sdl --with-sdlabi=1.2 --enable-vigs --enable-yagl"
EXTRA_OECONF_remove = "--disable-sdl"
