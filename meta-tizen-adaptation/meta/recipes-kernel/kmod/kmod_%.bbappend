SECTION = "Base/Libraries"
SRPM_IS_LIB = "lib${PN}"

# Split out certain binaries into kmod-compat, as Tizen traditionally does it.
PACKAGES =+ "kmod-compat"

SUMMARY_kmod-compat = "Compat symlinks for kernel module utilities"
DESCRIPTION_kmod-compat = "kod is a set of tools to handle common tasks with Linux kernel modules \
like                inmsert, remove, list, check properties, resolve \
dependencies and aliases. \
\
This package contains traditional name symlinks (lsmod, etc.). \
"
FILES_kmod-compat = "\
${bindir}/lsmod \
${sbindir}/depmod \
${sbindir}/insmod \
${sbindir}/lsmod \
${sbindir}/modinfo \
${sbindir}/modprobe \
${sbindir}/rmmod \
"
RDEPENDS_kmod-compat = "${PN}"
